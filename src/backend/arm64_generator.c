#include "arm64_generator.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Para identificar tipos de expresiones y primitivos
#include "ast/nodos/expresiones/expresiones.h"
#include "context/result.h"
// Necesario para manejar declaraciones, identificadores y funciones en codegen
#include "ast/nodos/instrucciones/instruccion/declaracion.h"
#include "ast/nodos/instrucciones/instruccion/funcion.h"
#include "ast/nodos/expresiones/terminales/identificadores.h"
#include "ast/nodos/expresiones/terminales/primitivos.h"

// Declaraciones externas de las tablas de operaciones (definidas en los módulos aritméticos)
extern Operacion tablaOperacionesSuma[TIPO_COUNT][TIPO_COUNT];
extern Operacion tablaOperacionesResta[TIPO_COUNT][TIPO_COUNT];
extern Operacion tablaOperacionesMultiplicacion[TIPO_COUNT][TIPO_COUNT];
extern Operacion tablaOperacionesDivision[TIPO_COUNT][TIPO_COUNT];

// Debido a que el header de primitivos comparte un include-guard no ideal,
// declaramos localmente la estructura mínima necesaria para inspeccionar
// primitivos en el codegen.
typedef struct
{
    AbstractExpresion base;
    TipoDato tipo;
    char *valor;
} PrimitivoExpresion;

// Prototipo de la función de interpretación de primitivos (existente en otro módulo)
extern Result interpretPrimitivoExpresion(AbstractExpresion *, Context *);

// Emitor recursivo de expresiones (soporta enteros y +-*/ de forma elemental)
// Forward declaration; implementation inserted later (after LocalVar definition)
static void emit_expression(Arm64Emitter *e, AbstractExpresion *node, const char *target_reg);

// Simple comment extraction and emission utility.
// We support two styles: line comments starting with '//' and block comments '/* ... */'.
typedef enum
{
    COMMENT_LINE,
    COMMENT_BLOCK
} CommentType;

typedef struct
{
    CommentType type;
    char *text; // owned
    int line;   // 1-based line number where comment starts
} Comment;

static void free_comments(Comment *list, size_t n)
{
    if (!list)
        return;
    for (size_t i = 0; i < n; ++i)
        free(list[i].text);
    free(list);
}

// Parse comments from a source string. Allocates an array in *out_list and sets *out_count.
// Caller must free with free_comments.
static bool parse_comments_from_source(const char *src, Comment **out_list, size_t *out_count)
{
    if (!src || !out_list || !out_count)
        return false;
    *out_list = NULL;
    *out_count = 0;

    size_t cap = 0;
    Comment *arr = NULL;

    const char *p = src;
    int line = 1;
    while (*p)
    {
        if (*p == '\n')
        {
            ++line;
            ++p;
            continue;
        }

        // Line comment: // ... to end of line
        if (p[0] == '/' && p[1] == '/')
        {
            const char *start = p + 2;
            const char *q = start;
            while (*q && *q != '\n')
                ++q;
            size_t len = q - start;
            char *txt = malloc(len + 1);
            if (!txt)
            {
                free_comments(arr, *out_count);
                return false;
            }
            memcpy(txt, start, len);
            txt[len] = '\0';

            if (*out_count + 1 > cap)
            {
                cap = cap ? cap * 2 : 8;
                Comment *tmp = realloc(arr, cap * sizeof(Comment));
                if (!tmp)
                {
                    free(txt);
                    free_comments(arr, *out_count);
                    return false;
                }
                arr = tmp;
            }
            arr[*out_count].type = COMMENT_LINE;
            arr[*out_count].text = txt;
            arr[*out_count].line = line;
            (*out_count)++;

            p = q; // at \n or \0
            continue;
        }

        // Block comment: /* ... */
        if (p[0] == '/' && p[1] == '*')
        {
            const char *start = p + 2;
            const char *q = start;
            while (*q && !(q[0] == '*' && q[1] == '/'))
            {
                if (*q == '\n')
                    ++line;
                ++q;
            }
            size_t len = (q > start) ? (q - start) : 0;
            char *txt = malloc(len + 1);
            if (!txt)
            {
                free_comments(arr, *out_count);
                return false;
            }
            if (len)
                memcpy(txt, start, len);
            txt[len] = '\0';

            if (*out_count + 1 > cap)
            {
                cap = cap ? cap * 2 : 8;
                Comment *tmp = realloc(arr, cap * sizeof(Comment));
                if (!tmp)
                {
                    free(txt);
                    free_comments(arr, *out_count);
                    return false;
                }
                arr = tmp;
            }
            arr[*out_count].type = COMMENT_BLOCK;
            arr[*out_count].text = txt;
            arr[*out_count].line = line;
            (*out_count)++;

            if (*q == '\0')
            {
                p = q;
            }
            else
            {
                p = q + 2;
            } // skip '*/'
            continue;
        }

        // Otherwise advance; count lines
        if (*p == '\n')
            ++line;
        ++p;
    }

    *out_list = arr;
    return true;
}

// Collect AST nodes with their starting line. Returns an array of pointers and count.
// Caller must free the returned array (but not the nodes themselves).
typedef struct
{
    AbstractExpresion *node;
    int line;
} NodeEntry;

static bool collect_ast_nodes(AbstractExpresion *root, NodeEntry **out_nodes, size_t *out_count)
{
    if (!out_nodes || !out_count)
        return false;
    *out_nodes = NULL;
    *out_count = 0;

    size_t cap = 0;
    NodeEntry *arr = NULL;

    // Simple stack-based DFS to avoid recursion depth issues
    AbstractExpresion **stack = NULL;
    size_t stack_cap = 0, stack_sz = 0;

    // push root
    if (root)
    {
        stack_cap = 64;
        stack = malloc(stack_cap * sizeof(AbstractExpresion *));
        if (!stack)
            return false;
        stack[stack_sz++] = root;
    }

    while (stack_sz > 0)
    {
        AbstractExpresion *n = stack[--stack_sz];
        if (!n)
            continue;

        // record node if it has a sensible line (>0)
        if (n->linea > 0)
        {
            if (*out_count + 1 > cap)
            {
                cap = cap ? cap * 2 : 128;
                NodeEntry *tmp = realloc(arr, cap * sizeof(NodeEntry));
                if (!tmp)
                {
                    free(arr);
                    free(stack);
                    return false;
                }
                arr = tmp;
            }
            arr[*out_count].node = n;
            arr[*out_count].line = n->linea;
            (*out_count)++;
        }

        // push children
        if (n->hijos && n->numHijos > 0)
        {
            for (size_t i = 0; i < n->numHijos; ++i)
            {
                if (stack_sz + 1 > stack_cap)
                {
                    size_t newcap = stack_cap * 2;
                    AbstractExpresion **tmp = realloc(stack, newcap * sizeof(AbstractExpresion *));
                    if (!tmp)
                    {
                        free(arr);
                        free(stack);
                        return false;
                    }
                    stack = tmp;
                    stack_cap = newcap;
                }
                stack[stack_sz++] = n->hijos[i];
            }
        }
    }

    free(stack);
    *out_nodes = arr;
    return true;
}

// Helper: sort NodeEntry array by line ascending (simple qsort)
static int nodeentry_cmp(const void *a, const void *b)
{
    const NodeEntry *na = a;
    const NodeEntry *nb = b;
    return (na->line - nb->line);
}

// Assign each comment to the nearest AST node by absolute line distance.
// Returns an array of lists: for each node index (0..n-1) a dynamic array of Comment indices.
// For simplicity we build an array of vectors implemented with malloc/realloc.
static int **assign_comments_to_nodes(Comment *comments, size_t ccount, NodeEntry *nodes, size_t ncount, size_t **out_per_node_counts)
{
    if (!out_per_node_counts)
        return NULL;
    *out_per_node_counts = NULL;
    if (ccount == 0 || ncount == 0)
        return NULL;

    // allocate arrays
    int **lists = calloc(ncount, sizeof(int *));
    size_t *counts = calloc(ncount, sizeof(size_t));
    size_t *caps = calloc(ncount, sizeof(size_t));
    if (!lists || !counts || !caps)
    {
        free(lists);
        free(counts);
        free(caps);
        return NULL;
    }

    for (size_t ci = 0; ci < ccount; ++ci)
    {
        int best_idx = -1;
        int best_dist = INT_MAX;
        for (size_t ni = 0; ni < ncount; ++ni)
        {
            int dist = abs(comments[ci].line - nodes[ni].line);
            if (dist < best_dist)
            {
                best_dist = dist;
                best_idx = (int)ni;
                if (dist == 0)
                    break;
            }
        }

        if (best_idx >= 0)
        {
            if (counts[best_idx] + 1 > caps[best_idx])
            {
                caps[best_idx] = caps[best_idx] ? caps[best_idx] * 2 : 4;
                int *tmp = realloc(lists[best_idx], caps[best_idx] * sizeof(int));
                if (!tmp)
                { /* cleanup */
                    for (size_t k = 0; k < ncount; ++k)
                        free(lists[k]);
                    free(lists);
                    free(counts);
                    free(caps);
                    return NULL;
                }
                lists[best_idx] = tmp;
            }
            lists[best_idx][counts[best_idx]++] = (int)ci;
        }
    }

    *out_per_node_counts = counts;
    free(caps);
    return lists;
}

struct Arm64Emitter
{
    FILE *out;
    int label_counter;
};

Arm64Emitter *arm64_emitter_create(FILE *out)
{
    if (!out)
        return NULL;
    Arm64Emitter *e = malloc(sizeof(Arm64Emitter));
    if (!e)
        return NULL;
    e->out = out;
    e->label_counter = 0;
    return e;
}

void arm64_emitter_destroy(Arm64Emitter *emitter)
{
    if (!emitter)
        return;
    // No cerramos el FILE* aquí (quien lo abrió lo cierra)
    free(emitter);
}

void arm64_emit_comment(Arm64Emitter *emitter, const char *fmt, ...)
{
    // Alias to emit a line comment prefixed with '#'
    if (!emitter || !emitter->out || !fmt)
        return;
    va_list ap;
    va_start(ap, fmt);
    fprintf(emitter->out, "# ");
    vfprintf(emitter->out, fmt, ap);
    fprintf(emitter->out, "\n");
    va_end(ap);
}

void arm64_emit_line_comment(Arm64Emitter *emitter, const char *fmt, ...)
{
    if (!emitter || !emitter->out || !fmt)
        return;
    va_list ap;
    va_start(ap, fmt);
    fprintf(emitter->out, "# ");
    vfprintf(emitter->out, fmt, ap);
    fprintf(emitter->out, "\n");
    va_end(ap);
}

void arm64_emit_block_comment(Arm64Emitter *emitter, const char *text)
{
    if (!emitter || !emitter->out || !text)
        return;
    // Simple block comment wrapper. Caller must ensure text does not contain '*/' sequences.
    fprintf(emitter->out, "/* %s */\n", text);
}

// Emitir mov <reg>, #<imm>
void arm64_emit_mov_imm(Arm64Emitter *emitter, const char *reg, long imm)
{
    if (!emitter || !emitter->out || !reg)
        return;
    fprintf(emitter->out, "    mov %s, #%ld\n", reg, imm);
}

// Emitir adr <reg>, <label>
void arm64_emit_adr_label(Arm64Emitter *emitter, const char *reg, const char *label)
{
    if (!emitter || !emitter->out || !reg || !label)
        return;
    fprintf(emitter->out, "    adr %s, %s\n", reg, label);
}

// Define una etiqueta y una cadena asociada (ej: para probar ADR)
void arm64_emit_label_string(Arm64Emitter *emitter, const char *label, const char *text)
{
    if (!emitter || !emitter->out || !label || !text)
        return;
    fprintf(emitter->out, "\n%s:\n", label);
    // .asciz en el segmento text es aceptado por GNU as para datos embebidos
    fprintf(emitter->out, "    .asciz \"%s\"\n", text);
}

// Helpers para cargar valores de coma flotante desde una etiqueta.
// Usan un registro temporal entero (x12) para almacenar la dirección via ADR,
// luego cargan desde memoria al registro de coma flotante (s/d).
// Nota: esto es una estrategia simple para ejemplos; en generación real se
// debería usar registers alloc y ADRP+ADD si la etiqueta está lejos.
void arm64_emit_ldr_s_from_label(Arm64Emitter *emitter, const char *sreg, const char *label)
{
    if (!emitter || !emitter->out || !sreg || !label)
        return;
    // usar x12 como registro temporal fijo
    fprintf(emitter->out, "    // cargar float desde etiqueta %s en %s\n", label, sreg);
    fprintf(emitter->out, "    adr x12, %s\n", label);
    fprintf(emitter->out, "    ldr %s, [x12]\n", sreg);
}

void arm64_emit_ldr_d_from_label(Arm64Emitter *emitter, const char *dreg, const char *label)
{
    if (!emitter || !emitter->out || !dreg || !label)
        return;
    fprintf(emitter->out, "    // cargar double desde etiqueta %s en %s\n", label, dreg);
    fprintf(emitter->out, "    adr x12, %s\n", label);
    fprintf(emitter->out, "    ldr %s, [x12]\n", dreg);
}

// Memoria helpers
void arm64_emit_str_reg(Arm64Emitter *emitter, const char *src_reg, const char *addr_reg)
{
    if (!emitter || !emitter->out || !src_reg || !addr_reg)
        return;
    fprintf(emitter->out, "    // store: %s -> [%s]\n", src_reg, addr_reg);
    fprintf(emitter->out, "    str %s, [%s]\n", src_reg, addr_reg);
}

void arm64_emit_ldr_reg(Arm64Emitter *emitter, const char *dst_reg, const char *addr_reg)
{
    if (!emitter || !emitter->out || !dst_reg || !addr_reg)
        return;
    fprintf(emitter->out, "    // load: [%s] -> %s\n", addr_reg, dst_reg);
    fprintf(emitter->out, "    ldr %s, [%s]\n", dst_reg, addr_reg);
}

void arm64_emit_str_s(Arm64Emitter *emitter, const char *sreg, const char *addr_reg)
{
    if (!emitter || !emitter->out || !sreg || !addr_reg)
        return;
    fprintf(emitter->out, "    // store float: %s -> [%s]\n", sreg, addr_reg);
    fprintf(emitter->out, "    str %s, [%s]\n", sreg, addr_reg);
}

void arm64_emit_ldr_s(Arm64Emitter *emitter, const char *sreg, const char *addr_reg)
{
    if (!emitter || !emitter->out || !sreg || !addr_reg)
        return;
    fprintf(emitter->out, "    // load float: [%s] -> %s\n", addr_reg, sreg);
    fprintf(emitter->out, "    ldr %s, [%s]\n", sreg, addr_reg);
}

void arm64_emit_str_d(Arm64Emitter *emitter, const char *dreg, const char *addr_reg)
{
    if (!emitter || !emitter->out || !dreg || !addr_reg)
        return;
    fprintf(emitter->out, "    // store double: %s -> [%s]\n", dreg, addr_reg);
    fprintf(emitter->out, "    str %s, [%s]\n", dreg, addr_reg);
}

void arm64_emit_ldr_d(Arm64Emitter *emitter, const char *dreg, const char *addr_reg)
{
    if (!emitter || !emitter->out || !dreg || !addr_reg)
        return;
    fprintf(emitter->out, "    // load double: [%s] -> %s\n", addr_reg, dreg);
    fprintf(emitter->out, "    ldr %s, [%s]\n", dreg, addr_reg);
}

// Definir una etiqueta de código
void arm64_emit_code_label(Arm64Emitter *emitter, const char *label)
{
    if (!emitter || !emitter->out || !label)
        return;
    fprintf(emitter->out, "\n%s:\n", label);
}

// Saltos
void arm64_emit_b(Arm64Emitter *emitter, const char *label)
{
    if (!emitter || !emitter->out || !label)
        return;
    fprintf(emitter->out, "    b %s\n", label);
}

// Branch with link (call-like): bl <label>
void arm64_emit_bl(Arm64Emitter *emitter, const char *label)
{
    if (!emitter || !emitter->out || !label)
        return;
    fprintf(emitter->out, "    bl %s\n", label);
}

// Branch to register: br <reg>
void arm64_emit_br(Arm64Emitter *emitter, const char *reg)
{
    if (!emitter || !emitter->out || !reg)
        return;
    fprintf(emitter->out, "    br %s\n", reg);
}

void arm64_emit_bne(Arm64Emitter *emitter, const char *label)
{
    if (!emitter || !emitter->out || !label)
        return;
    arm64_emit_b_cond(emitter, "ne", label);
}

void arm64_emit_beq(Arm64Emitter *emitter, const char *label)
{
    if (!emitter || !emitter->out || !label)
        return;
    arm64_emit_b_cond(emitter, "eq", label);
}

void arm64_emit_blt(Arm64Emitter *emitter, const char *label)
{
    arm64_emit_b_cond(emitter, "lt", label);
}

void arm64_emit_bgt(Arm64Emitter *emitter, const char *label)
{
    arm64_emit_b_cond(emitter, "gt", label);
}

void arm64_emit_ble(Arm64Emitter *emitter, const char *label)
{
    arm64_emit_b_cond(emitter, "le", label);
}

void arm64_emit_bge(Arm64Emitter *emitter, const char *label)
{
    arm64_emit_b_cond(emitter, "ge", label);
}

void arm64_emit_b_cond(Arm64Emitter *emitter, const char *cond, const char *label)
{
    if (!emitter || !emitter->out || !cond || !label)
        return;
    // Emitir en la forma 'b.cond label' (ej: b.eq L1) para seguir ejemplos didácticos
    fprintf(emitter->out, "    b.%s %s\n", cond, label);
}

// Comparación y add inmediato
void arm64_emit_cmp_reg_reg(Arm64Emitter *emitter, const char *reg1, const char *reg2)
{
    if (!emitter || !emitter->out || !reg1 || !reg2)
        return;
    fprintf(emitter->out, "    cmp %s, %s\n", reg1, reg2);
}

void arm64_emit_add_imm(Arm64Emitter *emitter, const char *dst_reg, const char *src_reg, long imm)
{
    if (!emitter || !emitter->out || !dst_reg || !src_reg)
        return;
    fprintf(emitter->out, "    add %s, %s, #%ld\n", dst_reg, src_reg, imm);
}

// Operadores aritméticos (enteros)
void arm64_emit_add_reg_reg(Arm64Emitter *emitter, const char *dst_reg, const char *lhs_reg, const char *rhs_reg)
{
    if (!emitter || !emitter->out || !dst_reg || !lhs_reg || !rhs_reg)
        return;
    fprintf(emitter->out, "    add %s, %s, %s\n", dst_reg, lhs_reg, rhs_reg);
}

void arm64_emit_sub_reg_reg(Arm64Emitter *emitter, const char *dst_reg, const char *lhs_reg, const char *rhs_reg)
{
    if (!emitter || !emitter->out || !dst_reg || !lhs_reg || !rhs_reg)
        return;
    fprintf(emitter->out, "    sub %s, %s, %s\n", dst_reg, lhs_reg, rhs_reg);
}

void arm64_emit_mul_reg_reg(Arm64Emitter *emitter, const char *dst_reg, const char *lhs_reg, const char *rhs_reg)
{
    if (!emitter || !emitter->out || !dst_reg || !lhs_reg || !rhs_reg)
        return;
    fprintf(emitter->out, "    mul %s, %s, %s\n", dst_reg, lhs_reg, rhs_reg);
}

void arm64_emit_sdiv_reg_reg(Arm64Emitter *emitter, const char *dst_reg, const char *lhs_reg, const char *rhs_reg)
{
    if (!emitter || !emitter->out || !dst_reg || !lhs_reg || !rhs_reg)
        return;
    fprintf(emitter->out, "    sdiv %s, %s, %s\n", dst_reg, lhs_reg, rhs_reg);
}

void arm64_emit_udiv_reg_reg(Arm64Emitter *emitter, const char *dst_reg, const char *lhs_reg, const char *rhs_reg)
{
    if (!emitter || !emitter->out || !dst_reg || !lhs_reg || !rhs_reg)
        return;
    fprintf(emitter->out, "    udiv %s, %s, %s\n", dst_reg, lhs_reg, rhs_reg);
}

// Incremento / decremento
void arm64_emit_incr(Arm64Emitter *emitter, const char *reg)
{
    if (!emitter || !emitter->out || !reg)
        return;
    fprintf(emitter->out, "    add %s, %s, #1\n", reg, reg);
}

void arm64_emit_decr(Arm64Emitter *emitter, const char *reg)
{
    if (!emitter || !emitter->out || !reg)
        return;
    fprintf(emitter->out, "    sub %s, %s, #1\n", reg, reg);
}

// Emisión de cabecera mínima para un archivo ARM64 compatible con GNU assembler
static void emit_arm64_header(Arm64Emitter *e)
{
    if (!e || !e->out)
        return;
    fprintf(e->out, "// Archivo generado por el generador ARM64 (esqueleto)\n");
    fprintf(e->out, ".text\n");
    fprintf(e->out, ".global main\n\n");
}

// --- Helpers para tamaño de tipos y manejo de variables locales (stack) ---
static size_t size_of_tipo(TipoDato tipo)
{
    switch (tipo)
    {
    case CHAR:
        return sizeof(char);
    case INT:
        return sizeof(int);
    case FLOAT:
        return sizeof(float);
    case DOUBLE:
        return sizeof(double);
    case BOOLEAN:
        return sizeof(bool);
    case STRING:
        return sizeof(char *);
    default:
        return sizeof(void *);
    }
}

// Estructura simple para mapear variables locales a offsets en el frame
typedef struct
{
    char *nombre;
    TipoDato tipo;
    int offset; // offset positivo desde x29 (fp): address = x29 - offset
} LocalVar;

// Alinea 'v' a múltiplos de 'a'
static int align_to(int v, int a)
{
    return ((v + a - 1) / a) * a;
}

// Escanea un subtree (funcion->bloque) y recopila todas las declaraciones de variables
// asignándoles offsets sucesivos. Retorna frame_size calculado (ya alineado a 16).
static int collect_locals_and_offsets(AbstractExpresion *node, LocalVar **out_vars, int *out_count)
{
    if (!node || !out_vars || !out_count)
        return 0;

    LocalVar *vars = NULL;
    int count = 0;
    int cap = 0;
    int offset = 0; // acumulador de tamaño

    // DFS stack
    AbstractExpresion **stack = NULL;
    size_t stack_cap = 0, stack_sz = 0;

    stack_cap = 128;
    stack = malloc(stack_cap * sizeof(AbstractExpresion *));
    if (!stack)
        return 0;

    stack[stack_sz++] = node;

    while (stack_sz > 0)
    {
        AbstractExpresion *n = stack[--stack_sz];
        if (!n)
            continue;

        // Si es una declaración de variable, registrarla
        if (n->interpret == interpretDeclaracionVariable)
        {
            DeclaracionVariable *dv = (DeclaracionVariable *)n;
            size_t sz = size_of_tipo(dv->tipo);
            // alinear cada variable a 8 bytes para simplicidad
            offset = align_to(offset, 8);
            offset += (int)align_to((int)sz, 8);

            if (count + 1 > cap)
            {
                cap = cap ? cap * 2 : 16;
                LocalVar *tmp = realloc(vars, cap * sizeof(LocalVar));
                if (!tmp)
                {
                    free(vars);
                    free(stack);
                    return 0;
                }
                vars = tmp;
            }

            vars[count].nombre = dv->nombre;
            vars[count].tipo = dv->tipo;
            vars[count].offset = offset;
            count++;
        }

        // push children
        if (n->hijos && n->numHijos > 0)
        {
            for (size_t i = 0; i < n->numHijos; ++i)
            {
                if (stack_sz + 1 > stack_cap)
                {
                    size_t newcap = stack_cap * 2;
                    AbstractExpresion **tmp = realloc(stack, newcap * sizeof(AbstractExpresion *));
                    if (!tmp)
                    {
                        free(vars);
                        free(stack);
                        return 0;
                    }
                    stack = tmp;
                    stack_cap = newcap;
                }
                stack[stack_sz++] = n->hijos[i];
            }
        }
    }

    free(stack);

    // 'offset' contiene la suma de tamaños (ya alineados a 8). Alinear frame a 16.
    int frame_size = align_to(offset, 16);

    *out_vars = vars;
    *out_count = count;
    return frame_size;
}

// Helper: buscar variable local por nombre
static LocalVar *find_local(LocalVar *vars, int count, const char *nombre)
{
    if (!vars || !nombre)
        return NULL;
    for (int i = 0; i < count; ++i)
    {
        if (vars[i].nombre && strcmp(vars[i].nombre, nombre) == 0)
            return &vars[i];
    }
    return NULL;
}

// Contexto global temporal usado durante la emisión de una función
static LocalVar *g_current_locals = NULL;
static int g_current_local_count = 0;

// Emitir prologue y epilogue sencillos
static void arm64_emit_function_prologue(Arm64Emitter *emitter, int frame_size)
{
    if (!emitter || !emitter->out)
        return;
    // push fp (x29) and lr (x30)
    fprintf(emitter->out, "    stp x29, x30, [sp, #-16]!\n");
    fprintf(emitter->out, "    mov x29, sp\n");
    if (frame_size > 0)
    {
        fprintf(emitter->out, "    sub sp, sp, #%d\n", frame_size);
    }
}

static void arm64_emit_function_epilogue(Arm64Emitter *emitter, int frame_size)
{
    if (!emitter || !emitter->out)
        return;
    if (frame_size > 0)
    {
        fprintf(emitter->out, "    add sp, sp, #%d\n", frame_size);
    }
    fprintf(emitter->out, "    ldp x29, x30, [sp], #16\n");
    fprintf(emitter->out, "    ret\n");
}

// Emitir código para una asignación o declaración que almacena en una variable local
static void emit_store_to_local(Arm64Emitter *e, const char *src_reg, LocalVar *local)
{
    if (!e || !src_reg || !local)
        return;
    // usar x12 como registro temporal para la dirección
    // dirección = x29 - offset
    fprintf(e->out, "    // almacenar %s en variable local %s (offset=%d)\n", src_reg, local->nombre, local->offset);
    fprintf(e->out, "    sub x12, x29, #%d\n", local->offset);
    // elegir la instrucción según el tipo
    switch (local->tipo)
    {
    case FLOAT:
        fprintf(e->out, "    str %s, [x12]\n", src_reg); // s-reg expected (caller ensures)
        break;
    case DOUBLE:
        fprintf(e->out, "    str %s, [x12]\n", src_reg); // d-reg expected
        break;
    default:
        fprintf(e->out, "    str %s, [x12]\n", src_reg);
        break;
    }
}

// Emitir carga desde variable local al registro destino
static void emit_load_from_local(Arm64Emitter *e, const char *dst_reg, LocalVar *local)
{
    if (!e || !dst_reg || !local)
        return;
    fprintf(e->out, "    // cargar variable local %s (offset=%d) en %s\n", local->nombre, local->offset, dst_reg);
    fprintf(e->out, "    sub x12, x29, #%d\n", local->offset);
    switch (local->tipo)
    {
    case FLOAT:
        fprintf(e->out, "    ldr %s, [x12]\n", dst_reg);
        break;
    case DOUBLE:
        fprintf(e->out, "    ldr %s, [x12]\n", dst_reg);
        break;
    default:
        fprintf(e->out, "    ldr %s, [x12]\n", dst_reg);
        break;
    }
}

// Implementation of emit_expression (moved here so LocalVar is defined)
static void emit_expression(Arm64Emitter *e, AbstractExpresion *node, const char *target_reg)
{
    if (!e || !node || !target_reg)
        return;

    // Caso primitivo (enteros)
    if (node->interpret == interpretPrimitivoExpresion)
    {
        PrimitivoExpresion *p = (PrimitivoExpresion *)node;
        if (p->tipo == INT && p->valor)
        {
            long v = atol(p->valor);
            arm64_emit_comment(e, "cargar literal %ld en %s", v, target_reg);
            arm64_emit_mov_imm(e, target_reg, v);
        }
        else
        {
            arm64_emit_comment(e, "primitivo no soportado para codegen (solo INT): tipo=%d", p->tipo);
        }
        return;
    }

    // Identificador: cargar desde variable local si existe
    if (node->interpret == interpretIdentificadorExpresion)
    {
        IdentificadorExpresion *id = (IdentificadorExpresion *)node;
        if (g_current_locals && g_current_local_count > 0)
        {
            LocalVar *lv = find_local(g_current_locals, g_current_local_count, id->nombre);
            if (lv)
            {
                arm64_emit_comment(e, "cargar identificador %s en %s", id->nombre, target_reg);
                emit_load_from_local(e, target_reg, lv);
                return;
            }
        }
        arm64_emit_comment(e, "identificador %s no encontrado en locals (fallback no implementado)", id->nombre);
        return;
    }

    // Expresiones de lenguaje (operaciones aritméticas usan la misma estructura)
    if (node->interpret == interpretExpresionLenguaje)
    {
        ExpresionLenguaje *ex = (ExpresionLenguaje *)node;

        // Detectar qué tabla de operaciones corresponde (suma/resta/mul/div)
        if (ex->tablaOperaciones == &tablaOperacionesSuma)
        {
            // evaluar lhs -> target_reg, rhs -> x1
            emit_expression(e, node->hijos[0], target_reg);
            emit_expression(e, node->hijos[1], "x1");
            arm64_emit_comment(e, "emitir suma %s = %s + x1", target_reg, target_reg);
            arm64_emit_add_reg_reg(e, target_reg, target_reg, "x1");
            return;
        }
        else if (ex->tablaOperaciones == &tablaOperacionesResta)
        {
            emit_expression(e, node->hijos[0], target_reg);
            emit_expression(e, node->hijos[1], "x1");
            arm64_emit_comment(e, "emitir resta %s = %s - x1", target_reg, target_reg);
            arm64_emit_sub_reg_reg(e, target_reg, target_reg, "x1");
            return;
        }
        else if (ex->tablaOperaciones == &tablaOperacionesMultiplicacion)
        {
            emit_expression(e, node->hijos[0], target_reg);
            emit_expression(e, node->hijos[1], "x1");
            arm64_emit_comment(e, "emitir multiplicación %s = %s * x1", target_reg, target_reg);
            arm64_emit_mul_reg_reg(e, target_reg, target_reg, "x1");
            return;
        }
        else if (ex->tablaOperaciones == &tablaOperacionesDivision)
        {
            emit_expression(e, node->hijos[0], target_reg);
            emit_expression(e, node->hijos[1], "x1");
            arm64_emit_comment(e, "emitir división %s = %s / x1 (signed)", target_reg, target_reg);
            arm64_emit_sdiv_reg_reg(e, target_reg, target_reg, "x1");
            return;
        }

        // Por defecto, intentar evaluar el primer hijo
        if (node->numHijos > 0 && node->hijos[0])
        {
            emit_expression(e, node->hijos[0], target_reg);
        }
        return;
    }

    // Otros nodos: intentar evaluar primer hijo
    if (node->numHijos > 0 && node->hijos[0])
        emit_expression(e, node->hijos[0], target_reg);
}

// Emitir código para una instrucción/expresión dentro de una función
static void emit_statement(Arm64Emitter *e, AbstractExpresion *stmt, LocalVar *locals, int local_count)
{
    if (!e || !stmt)
        return;

    // Declaración de variable: si tiene inicializador, evaluar y almacenar
    if (stmt->interpret == interpretDeclaracionVariable)
    {
        DeclaracionVariable *dv = (DeclaracionVariable *)stmt;
        arm64_emit_comment(e, "declaracion variable %s (tipo=%d)", dv->nombre, dv->tipo);
        if (stmt->numHijos > 0 && stmt->hijos[0])
        {
            // evaluar inicializador en x0 (o s0/d0 según tipo). Para simplicidad usamos x0 for ints
            emit_expression(e, stmt->hijos[0], "x0");
            LocalVar *lv = find_local(locals, local_count, dv->nombre);
            if (lv)
            {
                emit_store_to_local(e, "x0", lv);
            }
            else
            {
                arm64_emit_comment(e, "Advertencia: variable local %s no encontrada en la tabla de offsets", dv->nombre);
            }
        }
        return;
    }

    // Asignación simple: buscar variable y almacenar
    if (stmt->interpret == interpretAsignacionVariable)
    {
        AsignacionVariable *av = (AsignacionVariable *)stmt;
        arm64_emit_comment(e, "asignacion a %s", av->nombre);
        if (stmt->numHijos > 0 && stmt->hijos[0])
        {
            emit_expression(e, stmt->hijos[0], "x0");
            LocalVar *lv = find_local(locals, local_count, av->nombre);
            if (lv)
            {
                emit_store_to_local(e, "x0", lv);
            }
            else
            {
                // por ahora no manejamos globals en stack-mode; emitir comentario
                arm64_emit_comment(e, "Asignacion a symbol global o no encontrada: %s (no implementado)", av->nombre);
            }
        }
        return;
    }

    // Expression statements: evaluate expression and ignore result
    // (ej. llamada a función) - delegar a emit_expression
    emit_expression(e, stmt, "x0");
}

// Emitir una funcion completa: prologue, cuerpo y epilogue
static void emit_function_node(Arm64Emitter *e, FuncionExpresion *fnode)
{
    if (!e || !fnode)
        return;

    // Obtener bloque (suponemos último hijo es el bloque)
    AbstractExpresion *bloque = NULL;
    if (fnode->base.numHijos > 0)
        bloque = fnode->base.hijos[fnode->base.numHijos - 1];

    // Collect locals
    LocalVar *locals = NULL;
    int local_count = 0;
    int frame_size = 0;
    if (bloque)
        frame_size = collect_locals_and_offsets(bloque, &locals, &local_count);

    // Emitir etiqueta de función
    if (fnode->nombre)
        fprintf(e->out, "\n%s:\n", fnode->nombre);
    else
        fprintf(e->out, "\nfunc_%p:\n", (void *)fnode);

    // prologue
    arm64_emit_function_prologue(e, frame_size);
    // establecer contexto de locals para que emit_expression pueda resolver identificadores
    g_current_locals = locals;
    g_current_local_count = local_count;

    // Emitir declaraciones/ instrucciones en orden dentro del bloque (si existe)
    if (bloque && bloque->numHijos > 0)
    {
        for (size_t i = 0; i < bloque->numHijos; ++i)
        {
            AbstractExpresion *stmt = bloque->hijos[i];
            if (!stmt)
                continue;
            emit_statement(e, stmt, locals, local_count);
        }
    }

    // limpiar contexto
    g_current_locals = NULL;
    g_current_local_count = 0;

    // epilogue
    arm64_emit_function_epilogue(e, frame_size);

    free(locals);
}

// Emisión de footer/placeholder
static void emit_arm64_footer(Arm64Emitter *e)
{
    if (!e || !e->out)
        return;
    fprintf(e->out, "\n// Fin del archivo generado (placeholder)\n");
}

// Función principal expuesta: por ahora genera un archivo con estructura básica
// New implementation: optionally accept source text to extract comments. If source_text is
// NULL, the function behaves similarly to the old behavior but without comment emission.
bool generate_arm64_from_ast_with_source(AbstractExpresion *ast, Context *contexto, const char *output_path, const char *source_text)
{
    (void)contexto; // por ahora no usamos el contexto más allá de reportes

    if (!output_path)
        return false;

    FILE *out = fopen(output_path, "w");
    if (!out)
        return false;

    Arm64Emitter *emitter = arm64_emitter_create(out);
    if (!emitter)
    {
        fclose(out);
        return false;
    }

    emit_arm64_header(emitter);

    // If source_text provided, parse comments and emit them in source order.
    if (source_text)
    {
        Comment *list = NULL;
        size_t n = 0;
        if (parse_comments_from_source(source_text, &list, &n) && n > 0)
        {
            // Assign comments to AST nodes and emit near the node when possible.
            arm64_emit_comment(emitter, "Sección de comentarios (extraídos del texto fuente):");

            NodeEntry *nodes = NULL;
            size_t n_nodes = 0;
            if (collect_ast_nodes(ast, &nodes, &n_nodes) && n_nodes > 0)
            {
                // sort nodes by line to have deterministic order
                qsort(nodes, n_nodes, sizeof(NodeEntry), nodeentry_cmp);

                size_t *per_node_counts = NULL;
                int **lists = assign_comments_to_nodes(list, n, nodes, n_nodes, &per_node_counts);

                // Emit: iterate nodes in order, emit assigned comments before the node
                for (size_t ni = 0; ni < n_nodes; ++ni)
                {
                    // emit comments assigned to this node
                    if (per_node_counts && per_node_counts[ni] > 0 && lists && lists[ni])
                    {
                        for (size_t k = 0; k < per_node_counts[ni]; ++k)
                        {
                            int ci = lists[ni][k];
                            if (ci >= 0 && (size_t)ci < n)
                            {
                                if (list[ci].type == COMMENT_LINE)
                                    arm64_emit_line_comment(emitter, "%s", list[ci].text ? list[ci].text : "");
                                else
                                    arm64_emit_block_comment(emitter, list[ci].text ? list[ci].text : "");
                            }
                        }
                    }

                    // Emit a small marker for the node (helpful while codegen is a placeholder)
                    arm64_emit_line_comment(emitter, "-- Nodo AST en linea %d --", nodes[ni].line);
                }

                // cleanup lists
                if (lists)
                {
                    for (size_t i = 0; i < n_nodes; ++i)
                        free(lists[i]);
                    free(lists);
                }
                free(per_node_counts);
            }
            else
            {
                // No AST nodes found; just dump comments in source order
                for (size_t i = 0; i < n; ++i)
                {
                    if (list[i].type == COMMENT_LINE)
                        arm64_emit_line_comment(emitter, "%s", list[i].text ? list[i].text : "");
                    else
                        arm64_emit_block_comment(emitter, list[i].text ? list[i].text : "");
                }
            }
        }
        free_comments(list, n);
    }

    // Recorrer el AST y emitir funciones (con frame/stack para variables locales)
    arm64_emit_comment(emitter, "Sección de código: emitiendo funciones con frame y variables locales");
    if (ast)
    {
        // Simple DFS to find FuncionExpresion nodes
        AbstractExpresion **stack = NULL;
        size_t stack_cap = 0, stack_sz = 0;
        stack_cap = 128;
        stack = malloc(stack_cap * sizeof(AbstractExpresion *));
        if (stack)
        {
            stack[stack_sz++] = ast;
            while (stack_sz > 0)
            {
                AbstractExpresion *n = stack[--stack_sz];
                if (!n)
                    continue;
                if (n->interpret == interpretFuncionExpresion)
                {
                    FuncionExpresion *f = (FuncionExpresion *)n;
                    emit_function_node(emitter, f);
                    continue; // no need to descend into function body here
                }
                if (n->hijos && n->numHijos > 0)
                {
                    for (size_t i = 0; i < n->numHijos; ++i)
                    {
                        if (stack_sz + 1 > stack_cap)
                        {
                            size_t newcap = stack_cap * 2;
                            AbstractExpresion **tmp = realloc(stack, newcap * sizeof(AbstractExpresion *));
                            if (!tmp)
                                break;
                            stack = tmp;
                            stack_cap = newcap;
                        }
                        stack[stack_sz++] = n->hijos[i];
                    }
                }
            }
            free(stack);
        }
    }

    emit_arm64_footer(emitter);

    arm64_emitter_destroy(emitter);
    fclose(out);
    return true;
}

// Backward-compatible wrapper
bool generate_arm64_from_ast(AbstractExpresion *ast, Context *contexto, const char *output_path)
{
    return generate_arm64_from_ast_with_source(ast, contexto, output_path, NULL);
}
