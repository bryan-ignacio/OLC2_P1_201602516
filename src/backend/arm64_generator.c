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
#include "ast/nodos/instrucciones/instruccion/print.h"
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
    // Contexto para buscar símbolos globales durante la generación
    Context *context;

    // Lista simple de variables globales detectadas durante la generación.
    // Usamos esto para emitir una sección .data al final.
    char **global_names;
    TipoDato *global_types;
    size_t global_count;
    size_t global_cap;
    char **global_inits; // optional initialization directive per global (owned)
    // Pool de constantes (float/double) embebidas en .data
    char **const_labels;
    double *const_values;  // almacenamos el valor como double (para float usamos la parte baja)
    TipoDato *const_types; // FLOAT o DOUBLE
    size_t const_count;
    size_t const_cap;
    // Pool de literales string
    char **str_labels;
    char **str_values;
    size_t str_count;
    size_t str_cap;
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
    e->context = NULL;
    e->global_names = NULL;
    e->global_types = NULL;
    e->global_count = 0;
    e->global_cap = 0;
    e->global_inits = NULL;
    e->const_labels = NULL;
    e->const_values = NULL;
    e->const_types = NULL;
    e->const_count = 0;
    e->const_cap = 0;
    e->str_labels = NULL;
    e->str_values = NULL;
    e->str_count = 0;
    e->str_cap = 0;
    return e;
}

void arm64_emitter_destroy(Arm64Emitter *emitter)
{
    if (!emitter)
        return;
    // Liberar memoria de la lista de globals
    if (emitter->global_names)
    {
        for (size_t i = 0; i < emitter->global_count; ++i)
        {
            free(emitter->global_names[i]);
        }
        free(emitter->global_names);
    }
    if (emitter->global_types)
        free(emitter->global_types);
    if (emitter->global_inits)
    {
        for (size_t i = 0; i < emitter->global_count; ++i)
            free(emitter->global_inits[i]);
        free(emitter->global_inits);
    }
    // liberar constantes
    if (emitter->const_labels)
    {
        for (size_t i = 0; i < emitter->const_count; ++i)
            free(emitter->const_labels[i]);
        free(emitter->const_labels);
    }
    if (emitter->const_values)
        free(emitter->const_values);
    if (emitter->const_types)
        free(emitter->const_types);
    // liberar literales string
    if (emitter->str_labels)
    {
        for (size_t i = 0; i < emitter->str_count; ++i)
            free(emitter->str_labels[i]);
        free(emitter->str_labels);
    }
    if (emitter->str_values)
    {
        for (size_t i = 0; i < emitter->str_count; ++i)
            free(emitter->str_values[i]);
        free(emitter->str_values);
    }

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

// Registrar una variable global detectada para más tarde emitir en .data
static void arm64_register_global(Arm64Emitter *e, const char *name, TipoDato tipo)
{
    if (!e || !name)
        return;
    // comprobar si ya existe
    for (size_t i = 0; i < e->global_count; ++i)
    {
        if (strcmp(e->global_names[i], name) == 0)
            return;
    }
    // crecer si es necesario
    if (e->global_count + 1 > e->global_cap)
    {
        size_t newcap = e->global_cap ? e->global_cap * 2 : 8;
        char **tmpn = realloc(e->global_names, newcap * sizeof(char *));
        TipoDato *tmpt = realloc(e->global_types, newcap * sizeof(TipoDato));
        if (!tmpn || !tmpt)
        {
            // si falla, no registrar
            if (tmpn)
                free(tmpn);
            if (tmpt)
                free(tmpt);
            return;
        }
        e->global_names = tmpn;
        e->global_types = tmpt;
        e->global_cap = newcap;
    }
    e->global_names[e->global_count] = strdup(name);
    e->global_types[e->global_count] = tipo;
    e->global_count++;
}

// Registrar una variable global con inicializador. Si ya existe la variable,
// actualiza su inicializador.
static void arm64_register_global_init(Arm64Emitter *e, const char *name, TipoDato tipo, const char *init_directive)
{
    if (!e || !name)
        return;
    // comprobar si ya existe
    for (size_t i = 0; i < e->global_count; ++i)
    {
        if (strcmp(e->global_names[i], name) == 0)
        {
            // actualizar tipo y init si es necesario
            e->global_types[i] = tipo;
            if (init_directive)
            {
                if (e->global_inits[i])
                    free(e->global_inits[i]);
                e->global_inits[i] = strdup(init_directive);
            }
            return;
        }
    }

    // crecer si es necesario
    if (e->global_count + 1 > e->global_cap)
    {
        size_t newcap = e->global_cap ? e->global_cap * 2 : 8;
        char **tmpn = realloc(e->global_names, newcap * sizeof(char *));
        TipoDato *tmpt = realloc(e->global_types, newcap * sizeof(TipoDato));
        char **tmpi = realloc(e->global_inits, newcap * sizeof(char *));
        if (!tmpn || !tmpt || !tmpi)
        {
            if (tmpn)
                free(tmpn);
            if (tmpt)
                free(tmpt);
            if (tmpi)
                free(tmpi);
            return;
        }
        e->global_names = tmpn;
        e->global_types = tmpt;
        e->global_inits = tmpi;
        // initialize new slots
        for (size_t k = e->global_cap; k < newcap; ++k)
            e->global_inits[k] = NULL;
        e->global_cap = newcap;
    }

    e->global_names[e->global_count] = strdup(name);
    e->global_types[e->global_count] = tipo;
    e->global_inits[e->global_count] = init_directive ? strdup(init_directive) : NULL;
    e->global_count++;
}

// Registrar una constante float/double en el pool y devolver la etiqueta asignada (caller must not free)
static const char *arm64_register_constant(Arm64Emitter *e, TipoDato tipo, double value)
{
    if (!e)
        return NULL;
    // crear etiqueta única
    char label[64];
    snprintf(label, sizeof(label), "LC_%d", ++e->label_counter);

    // reservar espacio en arrays
    if (e->const_count + 1 > e->const_cap)
    {
        size_t newcap = e->const_cap ? e->const_cap * 2 : 8;
        char **tmpl = realloc(e->const_labels, newcap * sizeof(char *));
        double *tmpv = realloc(e->const_values, newcap * sizeof(double));
        TipoDato *tmpt = realloc(e->const_types, newcap * sizeof(TipoDato));
        if (!tmpl || !tmpv || !tmpt)
        {
            if (tmpl)
                free(tmpl);
            if (tmpv)
                free(tmpv);
            if (tmpt)
                free(tmpt);
            return NULL;
        }
        e->const_labels = tmpl;
        e->const_values = tmpv;
        e->const_types = tmpt;
        e->const_cap = newcap;
    }

    e->const_labels[e->const_count] = strdup(label);
    e->const_values[e->const_count] = value;
    e->const_types[e->const_count] = tipo;
    e->const_count++;
    return e->const_labels[e->const_count - 1];
}

// Registrar una cadena literal y devolver su etiqueta (caller must not free)
static const char *arm64_register_string(Arm64Emitter *e, const char *value)
{
    if (!e || !value)
        return NULL;
    char label[64];
    snprintf(label, sizeof(label), "LS_%d", ++e->label_counter);

    if (e->str_count + 1 > e->str_cap)
    {
        size_t newcap = e->str_cap ? e->str_cap * 2 : 8;
        char **tmpl = realloc(e->str_labels, newcap * sizeof(char *));
        char **tmpv = realloc(e->str_values, newcap * sizeof(char *));
        if (!tmpl || !tmpv)
        {
            if (tmpl)
                free(tmpl);
            if (tmpv)
                free(tmpv);
            return NULL;
        }
        e->str_labels = tmpl;
        e->str_values = tmpv;
        e->str_cap = newcap;
    }

    e->str_labels[e->str_count] = strdup(label);
    e->str_values[e->str_count] = strdup(value);
    e->str_count++;
    return e->str_labels[e->str_count - 1];
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

// Escapar una cadena para imprimir en .asciz (escapa \ " \n \t). Devuelve strdup() que caller debe liberar.
static char *escape_for_asciz(const char *src)
{
    if (!src)
        return NULL;
    size_t len = strlen(src);
    size_t cap = len * 2 + 1;
    char *out = malloc(cap);
    if (!out)
        return NULL;
    size_t oi = 0;
    for (size_t i = 0; i < len; ++i)
    {
        char c = src[i];
        if (c == '\\' || c == '"')
        {
            if (oi + 2 >= cap)
            {
                cap *= 2;
                char *tmp = realloc(out, cap);
                if (!tmp)
                {
                    free(out);
                    return NULL;
                }
                out = tmp;
            }
            out[oi++] = '\\';
            out[oi++] = c;
        }
        else if (c == '\n')
        {
            if (oi + 2 >= cap)
            {
                cap *= 2;
                char *tmp = realloc(out, cap);
                if (!tmp)
                {
                    free(out);
                    return NULL;
                }
                out = tmp;
            }
            out[oi++] = '\\';
            out[oi++] = 'n';
        }
        else if (c == '\t')
        {
            if (oi + 2 >= cap)
            {
                cap *= 2;
                char *tmp = realloc(out, cap);
                if (!tmp)
                {
                    free(out);
                    return NULL;
                }
                out = tmp;
            }
            out[oi++] = '\\';
            out[oi++] = 't';
        }
        else
        {
            out[oi++] = c;
        }
    }
    out[oi] = '\0';
    return out;
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

void arm64_emit_and_reg_reg(Arm64Emitter *emitter, const char *dst_reg, const char *lhs_reg, const char *rhs_reg)
{
    if (!emitter || !emitter->out || !dst_reg || !lhs_reg || !rhs_reg)
        return;
    fprintf(emitter->out, "    and %s, %s, %s\n", dst_reg, lhs_reg, rhs_reg);
}

void arm64_emit_orr_reg_reg(Arm64Emitter *emitter, const char *dst_reg, const char *lhs_reg, const char *rhs_reg)
{
    if (!emitter || !emitter->out || !dst_reg || !lhs_reg || !rhs_reg)
        return;
    fprintf(emitter->out, "    orr %s, %s, %s\n", dst_reg, lhs_reg, rhs_reg);
}

void arm64_emit_eor_reg_reg(Arm64Emitter *emitter, const char *dst_reg, const char *lhs_reg, const char *rhs_reg)
{
    if (!emitter || !emitter->out || !dst_reg || !lhs_reg || !rhs_reg)
        return;
    fprintf(emitter->out, "    eor %s, %s, %s\n", dst_reg, lhs_reg, rhs_reg);
}

void arm64_emit_lslv_reg_reg(Arm64Emitter *emitter, const char *dst_reg, const char *lhs_reg, const char *rhs_reg)
{
    if (!emitter || !emitter->out || !dst_reg || !lhs_reg || !rhs_reg)
        return;
    fprintf(emitter->out, "    lslv %s, %s, %s\n", dst_reg, lhs_reg, rhs_reg);
}

void arm64_emit_asrv_reg_reg(Arm64Emitter *emitter, const char *dst_reg, const char *lhs_reg, const char *rhs_reg)
{
    if (!emitter || !emitter->out || !dst_reg || !lhs_reg || !rhs_reg)
        return;
    fprintf(emitter->out, "    asrv %s, %s, %s\n", dst_reg, lhs_reg, rhs_reg);
}

// Floating point arithmetic helpers
void arm64_emit_fadd_s(Arm64Emitter *emitter, const char *dst, const char *lhs, const char *rhs)
{
    if (!emitter || !emitter->out || !dst || !lhs || !rhs)
        return;
    fprintf(emitter->out, "    fadd %s, %s, %s\n", dst, lhs, rhs);
}
void arm64_emit_fsub_s(Arm64Emitter *emitter, const char *dst, const char *lhs, const char *rhs)
{
    if (!emitter || !emitter->out || !dst || !lhs || !rhs)
        return;
    fprintf(emitter->out, "    fsub %s, %s, %s\n", dst, lhs, rhs);
}
void arm64_emit_fmul_s(Arm64Emitter *emitter, const char *dst, const char *lhs, const char *rhs)
{
    if (!emitter || !emitter->out || !dst || !lhs || !rhs)
        return;
    fprintf(emitter->out, "    fmul %s, %s, %s\n", dst, lhs, rhs);
}
void arm64_emit_fdiv_s(Arm64Emitter *emitter, const char *dst, const char *lhs, const char *rhs)
{
    if (!emitter || !emitter->out || !dst || !lhs || !rhs)
        return;
    fprintf(emitter->out, "    fdiv %s, %s, %s\n", dst, lhs, rhs);
}

void arm64_emit_fadd_d(Arm64Emitter *emitter, const char *dst, const char *lhs, const char *rhs)
{
    if (!emitter || !emitter->out || !dst || !lhs || !rhs)
        return;
    fprintf(emitter->out, "    fadd %s, %s, %s\n", dst, lhs, rhs);
}
void arm64_emit_fsub_d(Arm64Emitter *emitter, const char *dst, const char *lhs, const char *rhs)
{
    if (!emitter || !emitter->out || !dst || !lhs || !rhs)
        return;
    fprintf(emitter->out, "    fsub %s, %s, %s\n", dst, lhs, rhs);
}
void arm64_emit_fmul_d(Arm64Emitter *emitter, const char *dst, const char *lhs, const char *rhs)
{
    if (!emitter || !emitter->out || !dst || !lhs || !rhs)
        return;
    fprintf(emitter->out, "    fmul %s, %s, %s\n", dst, lhs, rhs);
}
void arm64_emit_fdiv_d(Arm64Emitter *emitter, const char *dst, const char *lhs, const char *rhs)
{
    if (!emitter || !emitter->out || !dst || !lhs || !rhs)
        return;
    fprintf(emitter->out, "    fdiv %s, %s, %s\n", dst, lhs, rhs);
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
        if (p->valor)
        {
            if (p->tipo == INT)
            {
                long v = atol(p->valor);
                arm64_emit_comment(e, "cargar literal %ld en %s", v, target_reg);
                arm64_emit_mov_imm(e, target_reg, v);
            }
            else if (p->tipo == BOOLEAN)
            {
                int val = 0;
                if (strcasecmp(p->valor, "true") == 0 || strcmp(p->valor, "1") == 0)
                    val = 1;
                arm64_emit_comment(e, "cargar literal boolean %s(%d) en %s", p->valor, val, target_reg);
                arm64_emit_mov_imm(e, target_reg, val);
            }
            else if (p->tipo == CHAR)
            {
                int ch = 0;
                size_t len = strlen(p->valor);
                if (len == 1)
                {
                    ch = (unsigned char)p->valor[0];
                }
                else if (len >= 3 && p->valor[0] == '\'' && p->valor[len - 1] == '\'')
                {
                    ch = (unsigned char)p->valor[1];
                }
                else
                {
                    // intentar interpretar como número
                    ch = atoi(p->valor);
                }
                arm64_emit_comment(e, "cargar literal char %s(%d) en %s", p->valor, ch, target_reg);
                arm64_emit_mov_imm(e, target_reg, ch);
            }
            else if (p->tipo == STRING)
            {
                const char *lbl = arm64_register_string(e, p->valor);
                if (lbl)
                {
                    arm64_emit_comment(e, "cargar literal string %s en %s via %s", p->valor, target_reg, lbl);
                    arm64_emit_adr_label(e, target_reg, lbl);
                }
                else
                {
                    arm64_emit_comment(e, "no se pudo registrar literal string %s", p->valor);
                }
            }
            else if (p->tipo == FLOAT)
            {
                double v = atof(p->valor);
                const char *lbl = arm64_register_constant(e, FLOAT, v);
                if (lbl)
                {
                    arm64_emit_comment(e, "cargar literal float %f en %s via %s", v, target_reg, lbl);
                    // esperar que target_reg sea sN
                    arm64_emit_ldr_s_from_label(e, target_reg, lbl);
                }
                else
                {
                    arm64_emit_comment(e, "no se pudo registrar constante float %s", p->valor);
                }
            }
            else if (p->tipo == DOUBLE)
            {
                double v = atof(p->valor);
                const char *lbl = arm64_register_constant(e, DOUBLE, v);
                if (lbl)
                {
                    arm64_emit_comment(e, "cargar literal double %f en %s via %s", v, target_reg, lbl);
                    arm64_emit_ldr_d_from_label(e, target_reg, lbl);
                }
                else
                {
                    arm64_emit_comment(e, "no se pudo registrar constante double %s", p->valor);
                }
            }
            else
            {
                arm64_emit_comment(e, "primitivo no soportado para codegen: tipo=%d", p->tipo);
            }
        }
        else
        {
            arm64_emit_comment(e, "primitivo sin valor para codegen");
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
            // evaluar inicializador en el registro adecuado según el tipo
            const char *target = "x0";
            if (dv->tipo == FLOAT)
                target = "s0";
            else if (dv->tipo == DOUBLE)
                target = "d0";
            emit_expression(e, stmt->hijos[0], target);
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
            // Buscar variable local primero para decidir el registro destino
            LocalVar *lv = find_local(locals, local_count, av->nombre);
            if (lv)
            {
                const char *t = "x0";
                if (lv->tipo == FLOAT)
                    t = "s0";
                else if (lv->tipo == DOUBLE)
                    t = "d0";
                emit_expression(e, stmt->hijos[0], t);
                emit_store_to_local(e, t, lv);
            }
            else
            {
                // Intentar asignar a variable global (buscar en contexto)
                Symbol *sym = NULL;
                if (e && e->context)
                    sym = buscarTablaSimbolos(e->context, av->nombre);

                if (sym)
                {
                    // registrar global para emisión de .data
                    arm64_register_global(e, av->nombre, sym->tipo);

                    // elegir registro según tipo
                    if (sym->tipo == FLOAT)
                    {
                        emit_expression(e, stmt->hijos[0], "s0");
                    }
                    else if (sym->tipo == DOUBLE)
                    {
                        emit_expression(e, stmt->hijos[0], "d0");
                    }
                    else
                    {
                        emit_expression(e, stmt->hijos[0], "x0");
                    }

                    // emitir ADR + store
                    char label[256];
                    snprintf(label, sizeof(label), "g_%s", av->nombre);
                    arm64_emit_comment(e, "Asignacion a variable global %s (tipo=%d)", av->nombre, sym->tipo);
                    arm64_emit_adr_label(e, "x12", label);
                    switch (sym->tipo)
                    {
                    case FLOAT:
                        arm64_emit_str_s(e, "s0", "x12");
                        break;
                    case DOUBLE:
                        arm64_emit_str_d(e, "d0", "x12");
                        break;
                    default:
                        arm64_emit_str_reg(e, "x0", "x12");
                        break;
                    }
                }
                else
                {
                    arm64_emit_comment(e, "Asignacion a symbol global o no encontrada: %s (no implementado)", av->nombre);
                }
            }
        }
        return;
    }

    // Asignación compuesta (+=, -=, etc.)
    if (stmt->interpret == interpretAsignacionCompuesta)
    {
        AsignacionCompuesta *ac = (AsignacionCompuesta *)stmt;
        arm64_emit_comment(e, "asignacion compuesta a %s operador=%d", ac->nombre, ac->tipoOperador);

        if (stmt->numHijos == 0 || !stmt->hijos[0])
        {
            arm64_emit_comment(e, "Asignacion compuesta sin valor para %s", ac->nombre);
            return;
        }

        // intentar local
        LocalVar *lv = find_local(locals, local_count, ac->nombre);
        if (lv)
        {
            // escoger registros según tipo
            const char *r_lhs = "x0";
            const char *r_rhs = "x1";
            if (lv->tipo == FLOAT)
            {
                r_lhs = "s0";
                r_rhs = "s1";
                // cargar lhs
                emit_load_from_local(e, r_lhs, lv);
                // evaluar rhs
                emit_expression(e, stmt->hijos[0], r_rhs);
                // aplicar operador
                switch (ac->tipoOperador)
                {
                case ASIG_SUMA:
                    arm64_emit_fadd_s(e, r_lhs, r_lhs, r_rhs);
                    break;
                case ASIG_RESTA:
                    arm64_emit_fsub_s(e, r_lhs, r_lhs, r_rhs);
                    break;
                case ASIG_MULT:
                    arm64_emit_fmul_s(e, r_lhs, r_lhs, r_rhs);
                    break;
                case ASIG_DIV:
                    arm64_emit_fdiv_s(e, r_lhs, r_lhs, r_rhs);
                    break;
                default:
                    arm64_emit_comment(e, "Operador compuesto no soportado para float en codegen: %d", ac->tipoOperador);
                    return;
                }
                // almacenar
                emit_store_to_local(e, r_lhs, lv);
            }
            else if (lv->tipo == DOUBLE)
            {
                r_lhs = "d0";
                r_rhs = "d1";
                emit_load_from_local(e, r_lhs, lv);
                emit_expression(e, stmt->hijos[0], r_rhs);
                switch (ac->tipoOperador)
                {
                case ASIG_SUMA:
                    arm64_emit_fadd_d(e, r_lhs, r_lhs, r_rhs);
                    break;
                case ASIG_RESTA:
                    arm64_emit_fsub_d(e, r_lhs, r_lhs, r_rhs);
                    break;
                case ASIG_MULT:
                    arm64_emit_fmul_d(e, r_lhs, r_lhs, r_rhs);
                    break;
                case ASIG_DIV:
                    arm64_emit_fdiv_d(e, r_lhs, r_lhs, r_rhs);
                    break;
                default:
                    arm64_emit_comment(e, "Operador compuesto no soportado para double en codegen: %d", ac->tipoOperador);
                    return;
                }
                emit_store_to_local(e, r_lhs, lv);
            }
            else
            {
                // enteros
                // cargar lhs en x0
                emit_load_from_local(e, "x0", lv);
                // evaluar rhs en x1
                emit_expression(e, stmt->hijos[0], "x1");
                switch (ac->tipoOperador)
                {
                case ASIG_SUMA:
                    arm64_emit_add_reg_reg(e, "x0", "x0", "x1");
                    break;
                case ASIG_RESTA:
                    arm64_emit_sub_reg_reg(e, "x0", "x0", "x1");
                    break;
                case ASIG_MULT:
                    arm64_emit_mul_reg_reg(e, "x0", "x0", "x1");
                    break;
                case ASIG_DIV:
                    arm64_emit_sdiv_reg_reg(e, "x0", "x0", "x1");
                    break;
                case ASIG_MOD:
                    // x2 = x0 / x1; x3 = x2 * x1; x0 = x0 - x3
                    arm64_emit_sdiv_reg_reg(e, "x2", "x0", "x1");
                    arm64_emit_mul_reg_reg(e, "x3", "x2", "x1");
                    arm64_emit_sub_reg_reg(e, "x0", "x0", "x3");
                    break;
                case ASIG_AND:
                    arm64_emit_and_reg_reg(e, "x0", "x0", "x1");
                    break;
                case ASIG_OR:
                    arm64_emit_orr_reg_reg(e, "x0", "x0", "x1");
                    break;
                case ASIG_XOR:
                    arm64_emit_eor_reg_reg(e, "x0", "x0", "x1");
                    break;
                case ASIG_LSHIFT:
                    arm64_emit_lslv_reg_reg(e, "x0", "x0", "x1");
                    break;
                case ASIG_RSHIFT:
                    arm64_emit_asrv_reg_reg(e, "x0", "x0", "x1");
                    break;
                default:
                    arm64_emit_comment(e, "Operador compuesto no implementado en codegen: %d", ac->tipoOperador);
                    return;
                }
                // almacenar
                emit_store_to_local(e, "x0", lv);
            }
        }
        else
        {
            // intentar global
            Symbol *sym = NULL;
            if (e && e->context)
                sym = buscarTablaSimbolos(e->context, ac->nombre);
            if (!sym)
            {
                arm64_emit_comment(e, "Asignacion compuesta a symbol global no encontrada: %s", ac->nombre);
                return;
            }
            arm64_register_global(e, ac->nombre, sym->tipo);
            char label[256];
            snprintf(label, sizeof(label), "g_%s", ac->nombre);

            if (sym->tipo == FLOAT)
            {
                // cargar lhs
                arm64_emit_ldr_s_from_label(e, "s0", label);
                // evaluar rhs
                emit_expression(e, stmt->hijos[0], "s1");
                // aplicar
                switch (ac->tipoOperador)
                {
                case ASIG_SUMA:
                    arm64_emit_fadd_s(e, "s0", "s0", "s1");
                    break;
                case ASIG_RESTA:
                    arm64_emit_fsub_s(e, "s0", "s0", "s1");
                    break;
                case ASIG_MULT:
                    arm64_emit_fmul_s(e, "s0", "s0", "s1");
                    break;
                case ASIG_DIV:
                    arm64_emit_fdiv_s(e, "s0", "s0", "s1");
                    break;
                default:
                    arm64_emit_comment(e, "Operador compuesto no soportado para float en global: %d", ac->tipoOperador);
                    return;
                }
                arm64_emit_adr_label(e, "x12", label);
                arm64_emit_str_s(e, "s0", "x12");
            }
            else if (sym->tipo == DOUBLE)
            {
                arm64_emit_ldr_d_from_label(e, "d0", label);
                emit_expression(e, stmt->hijos[0], "d1");
                switch (ac->tipoOperador)
                {
                case ASIG_SUMA:
                    arm64_emit_fadd_d(e, "d0", "d0", "d1");
                    break;
                case ASIG_RESTA:
                    arm64_emit_fsub_d(e, "d0", "d0", "d1");
                    break;
                case ASIG_MULT:
                    arm64_emit_fmul_d(e, "d0", "d0", "d1");
                    break;
                case ASIG_DIV:
                    arm64_emit_fdiv_d(e, "d0", "d0", "d1");
                    break;
                default:
                    arm64_emit_comment(e, "Operador compuesto no soportado para double en global: %d", ac->tipoOperador);
                    return;
                }
                arm64_emit_adr_label(e, "x12", label);
                arm64_emit_str_d(e, "d0", "x12");
            }
            else
            {
                // ints: ldr x0, [adr]
                arm64_emit_adr_label(e, "x12", label);
                arm64_emit_ldr_reg(e, "x0", "x12");
                emit_expression(e, stmt->hijos[0], "x1");
                switch (ac->tipoOperador)
                {
                case ASIG_SUMA:
                    arm64_emit_add_reg_reg(e, "x0", "x0", "x1");
                    break;
                case ASIG_RESTA:
                    arm64_emit_sub_reg_reg(e, "x0", "x0", "x1");
                    break;
                case ASIG_MULT:
                    arm64_emit_mul_reg_reg(e, "x0", "x0", "x1");
                    break;
                case ASIG_DIV:
                    arm64_emit_sdiv_reg_reg(e, "x0", "x0", "x1");
                    break;
                case ASIG_MOD:
                    arm64_emit_sdiv_reg_reg(e, "x2", "x0", "x1");
                    arm64_emit_mul_reg_reg(e, "x3", "x2", "x1");
                    arm64_emit_sub_reg_reg(e, "x0", "x0", "x3");
                    break;
                case ASIG_AND:
                    arm64_emit_and_reg_reg(e, "x0", "x0", "x1");
                    break;
                case ASIG_OR:
                    arm64_emit_orr_reg_reg(e, "x0", "x0", "x1");
                    break;
                case ASIG_XOR:
                    arm64_emit_eor_reg_reg(e, "x0", "x0", "x1");
                    break;
                case ASIG_LSHIFT:
                    arm64_emit_lslv_reg_reg(e, "x0", "x0", "x1");
                    break;
                case ASIG_RSHIFT:
                    arm64_emit_asrv_reg_reg(e, "x0", "x0", "x1");
                    break;
                default:
                    arm64_emit_comment(e, "Operador compuesto no implementado en global: %d", ac->tipoOperador);
                    return;
                }
                arm64_emit_adr_label(e, "x12", label);
                arm64_emit_str_reg(e, "x0", "x12");
            }
        }
        return;
    }

    // Expression statements: evaluate expression and ignore result
    // (ej. llamada a función) - delegar a emit_expression
    // Support for System.out.println / print expressions
    if (stmt->interpret == interpretPrintExpresion)
    {
        PrintExpresion *p = (PrintExpresion *)stmt;
        if (p->base.numHijos == 0)
        {
            // nothing to print, just newline
            const char *nl = arm64_register_string(e, "\n");
            if (nl)
            {
                arm64_emit_adr_label(e, "x0", nl);
                arm64_emit_bl(e, "puts");
            }
            else
            {
                arm64_emit_mov_imm(e, "x0", '\n');
                arm64_emit_bl(e, "putchar");
            }
            return;
        }

        AbstractExpresion *lista = p->base.hijos[0];
        // register common format strings
        const char *fmt_d = arm64_register_string(e, "%d");
        const char *fmt_g = arm64_register_string(e, "%g");
        const char *fmt_gd = arm64_register_string(e, "%.15g");
        const char *fmt_c = arm64_register_string(e, "%c");
        const char *fmt_s = arm64_register_string(e, "%s");

        // Helper to print a single expression without newline
        for (size_t i = 0; i < lista->numHijos; ++i)
        {
            AbstractExpresion *expr = lista->hijos[i];
            TipoDato t = -1;
            // try to infer type from node or context
            if (expr->interpret == interpretPrimitivoExpresion)
            {
                PrimitivoExpresion *pp = (PrimitivoExpresion *)expr;
                t = pp->tipo;
            }
            else if (expr->interpret == interpretIdentificadorExpresion)
            {
                IdentificadorExpresion *id = (IdentificadorExpresion *)expr;
                if (e && e->context)
                {
                    Symbol *s = buscarTablaSimbolos(e->context, id->nombre);
                    if (s)
                        t = s->tipo;
                }
            }

            switch (t)
            {
            case STRING:
            {
                // evaluate into x0 and call puts (handles newline)
                emit_expression(e, expr, "x0");
                // if pointer may be NULL, handle by substituting "null"
                char lab_null[64];
                snprintf(lab_null, sizeof(lab_null), "L_print_null_%d", ++e->label_counter);
                // cmp x0, #0 ; beq lab_null ; bl puts ; b L_print_end
                arm64_emit_cmp_reg_reg(e, "x0", "xzr");
                arm64_emit_beq(e, lab_null);
                arm64_emit_bl(e, "puts");
                char lab_end[64];
                snprintf(lab_end, sizeof(lab_end), "L_print_end_%d", ++e->label_counter);
                arm64_emit_b(e, lab_end);
                arm64_emit_code_label(e, lab_null);
                {
                    const char *lbl_null = arm64_register_string(e, "null");
                    arm64_emit_adr_label(e, "x0", lbl_null);
                    arm64_emit_bl(e, "puts");
                }
                arm64_emit_code_label(e, lab_end);
                break;
            }
            case INT:
            case CHAR:
            case BOOLEAN:
            default:
            {
                // treat as integer-like by default
                emit_expression(e, expr, "x1");
                // load format into x0
                arm64_emit_adr_label(e, "x0", fmt_d);
                arm64_emit_bl(e, "printf");
                break;
            }
            case FLOAT:
            {
                // evaluate float into s0, convert to double in d0, call printf with %.g
                emit_expression(e, expr, "s0");
                // convert
                fprintf(e->out, "    fcvt d0, s0\n");
                arm64_emit_adr_label(e, "x0", fmt_g);
                arm64_emit_bl(e, "printf");
                break;
            }
            case DOUBLE:
            {
                emit_expression(e, expr, "d0");
                arm64_emit_adr_label(e, "x0", fmt_gd);
                arm64_emit_bl(e, "printf");
                break;
            }
                        }
        }

        // after printing all parts, output newline via putchar
        arm64_emit_mov_imm(e, "x0", '\n');
        arm64_emit_bl(e, "putchar");
        return;
    }

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

    // Emitir sección de datos para variables globales detectadas
    // Primero emitir constantes literales (FLOAT/DOUBLE) si las hay
    // Emitir literales string (asciz) primero si existen
    if (e->str_count > 0)
    {
        fprintf(e->out, "\n.data\n");
        for (size_t i = 0; i < e->str_count; ++i)
        {
            const char *lbl = e->str_labels[i];
            const char *val = e->str_values[i];
            char *esc = escape_for_asciz(val);
            if (!esc)
                esc = strdup(val ? val : "");
            fprintf(e->out, "%s:\n    .asciz \"%s\"\n", lbl, esc);
            free(esc);
        }
    }

    if (e->const_count > 0)
    {
        // Si las constantes float/double existen, asegurarnos de haber declarado .data
        if (e->str_count == 0)
            fprintf(e->out, "\n.data\n");
        for (size_t i = 0; i < e->const_count; ++i)
        {
            const char *lbl = e->const_labels[i];
            TipoDato tipo = e->const_types[i];
            double val = e->const_values[i];
            if (tipo == FLOAT)
            {
                // emitir 32-bit float
                fprintf(e->out, "%s:\n    .float %f\n", lbl, (float)val);
            }
            else
            {
                fprintf(e->out, "%s:\n    .double %f\n", lbl, val);
            }
        }
    }

    if (e->global_count > 0)
    {
        if (e->const_count == 0)
            fprintf(e->out, "\n.data\n");
        for (size_t i = 0; i < e->global_count; ++i)
        {
            const char *name = e->global_names[i];
            TipoDato tipo = e->global_types[i];
            // Nombre de etiqueta simple
            fprintf(e->out, "g_%s:\n", name);
            if (e->global_inits && e->global_inits[i])
            {
                // Emisión literal tal como fue construida por el registrador
                fprintf(e->out, "%s\n", e->global_inits[i]);
            }
            else
            {
                switch (tipo)
                {
                case INT:
                case BOOLEAN:
                case CHAR:
                case STRING:
                case ARRAY:
                case MATRIX:
                    // reservar 8 bytes por simplicidad
                    fprintf(e->out, "    .quad 0\n");
                    break;
                case FLOAT:
                    fprintf(e->out, "    .float 0.0\n");
                    break;
                case DOUBLE:
                    fprintf(e->out, "    .double 0.0\n");
                    break;
                default:
                    fprintf(e->out, "    .quad 0\n");
                    break;
                }
            }
        }
    }
}

// Función principal expuesta: por ahora genera un archivo con estructura básica
// New implementation: optionally accept source text to extract comments. If source_text is
// NULL, the function behaves similarly to the old behavior but without comment emission.
bool generate_arm64_from_ast_with_source(AbstractExpresion *ast, Context *contexto, const char *output_path, const char *source_text)
{
    (void)contexto; // por ahora no usamos el contexto más allá de reportes

    // Debug: abrir log para ayudar a diagnosticar crashes desde la GUI
    FILE *dbg = fopen("arm64_debug.log", "a");
    if (dbg)
    {
        fprintf(dbg, "generate_arm64_from_ast_with_source start\n");
        if (ast)
            fprintf(dbg, "AST root present, numHijos=%zu\n", ast->numHijos);
        else
            fprintf(dbg, "AST root is NULL\n");
        if (contexto)
            fprintf(dbg, "Context present\n");
        else
            fprintf(dbg, "Context is NULL\n");
        if (output_path)
            fprintf(dbg, "output_path=%s\n", output_path);
        if (source_text)
            fprintf(dbg, "source_text length=%zu\n", strlen(source_text));
        fflush(dbg);
    }

    if (!output_path)
        return false;

    FILE *out = fopen(output_path, "w");
    if (!out)
        return false;

    Arm64Emitter *emitter = arm64_emitter_create(out);
    if (!emitter)
    {
        fclose(out);
        if (dbg)
        {
            fprintf(dbg, "Failed to create emitter\n");
            fclose(dbg);
        }
        return false;
    }
    // Guardar el contexto en el emisor para que las rutinas puedan buscar símbolos
    emitter->context = contexto;
    if (dbg)
    {
        fprintf(dbg, "Emitter created, label_counter=%d\n", emitter->label_counter);
        fflush(dbg);
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
    if (dbg)
    {
        fprintf(dbg, "After parsing comments\n");
        fflush(dbg);
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
                // Emitir constantes globales si aparecen en el AST de nivel superior
                if (n->interpret == interpretDeclaracionConstante)
                {
                    DeclaracionConstante *dc = (DeclaracionConstante *)n;
                    // si tiene inicializador y es un primitivo simple, crear init directive
                    if (dc->base.numHijos > 0 && dc->base.hijos[0] && dc->base.hijos[0]->interpret == interpretPrimitivoExpresion)
                    {
                        PrimitivoExpresion *p = (PrimitivoExpresion *)dc->base.hijos[0];
                        char initbuf[256];
                        initbuf[0] = '\0';
                        if (p->tipo == STRING && p->valor)
                        {
                            const char *slabel = arm64_register_string(emitter, p->valor);
                            if (slabel)
                                snprintf(initbuf, sizeof(initbuf), "    .quad %s", slabel);
                        }
                        else if ((p->tipo == INT || p->tipo == CHAR || p->tipo == BOOLEAN) && p->valor)
                        {
                            long v = atol(p->valor);
                            snprintf(initbuf, sizeof(initbuf), "    .quad %ld", v);
                        }
                        else if (p->tipo == FLOAT && p->valor)
                        {
                            double v = atof(p->valor);
                            snprintf(initbuf, sizeof(initbuf), "    .float %f", (float)v);
                        }
                        else if (p->tipo == DOUBLE && p->valor)
                        {
                            double v = atof(p->valor);
                            snprintf(initbuf, sizeof(initbuf), "    .double %f", v);
                        }
                        else
                        {
                            // no se pudo formar inicializador
                        }
                        if (initbuf[0] != '\0')
                        {
                            arm64_register_global_init(emitter, dc->nombre, dc->tipo, initbuf);
                        }
                        else
                        {
                            // registrar sin init
                            arm64_register_global(emitter, dc->nombre, dc->tipo);
                        }
                    }
                    else
                    {
                        arm64_register_global(emitter, dc->nombre, dc->tipo);
                    }
                    continue;
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

    if (dbg)
    {
        fprintf(dbg, "About to emit footer\n");
        fflush(dbg);
    }

    emit_arm64_footer(emitter);

    if (dbg)
    {
        fprintf(dbg, "Footer emitted\n");
        fflush(dbg);
    }

    arm64_emitter_destroy(emitter);
    fclose(out);

    if (dbg)
    {
        fprintf(dbg, "generate_arm64_from_ast_with_source end\n");
        fclose(dbg);
    }
    return true;
}

// Backward-compatible wrapper
bool generate_arm64_from_ast(AbstractExpresion *ast, Context *contexto, const char *output_path)
{
    return generate_arm64_from_ast_with_source(ast, contexto, output_path, NULL);
}
