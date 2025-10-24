#include "arm64_generator.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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

// Emisión de cabecera mínima para un archivo ARM64 compatible con GNU assembler
static void emit_arm64_header(Arm64Emitter *e)
{
    if (!e || !e->out)
        return;
    fprintf(e->out, "// Archivo generado por el generador ARM64 (esqueleto)\n");
    fprintf(e->out, ".text\n");
    fprintf(e->out, ".global main\n\n");
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

    // Minimal code generation placeholder
    arm64_emit_comment(emitter, "Sección de código (placeholder):");
    (void)ast; // por ahora no generamos instrucciones reales
    fprintf(emitter->out, "\nmain:\n");
    fprintf(emitter->out, "    mov x0, #0\n");
    fprintf(emitter->out, "    ret\n");

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
