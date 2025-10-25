#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast/AbstractExpresion.h"

extern int yyparse(void);
extern FILE *yyin;
// Definir símbolos globales que el parser/bison espera (sustituyen al main)
AbstractExpresion *ast_root = NULL;
Context *contextoActualReporte = NULL;

#include "context/context.h"
#include "backend/arm64_generator.h"

// In order to populate the symbol table used by the ARM64 generator we
// interpret only the AST nodes that register symbols (variable/constant
// declarations and function declarations). This avoids executing runtime
// code such as prints or function bodies while allowing the emitter to
// lookup types/initializers for globals and variables.
#include "ast/nodos/instrucciones/instruccion/declaracion.h"
#include "ast/nodos/instrucciones/instruccion/funcion.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s [--gui-sim] <input.usl>\n", argv[0]);
        fprintf(stderr, "  --gui-sim   : simulate GUI invocation (pass NULL Context to generator)\n");
        return 1;
    }

    int gui_sim = 0;
    const char *fname = NULL;
    if (argc >= 3 && strcmp(argv[1], "--gui-sim") == 0)
    {
        gui_sim = 1;
        fname = argv[2];
    }
    else
    {
        fname = argv[1];
    }
    FILE *f = fopen(fname, "r");
    if (!f)
    {
        perror("fopen");
        return 1;
    }

    // Read file text
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *src = malloc(sz + 1);
    if (!src)
    {
        fclose(f);
        fprintf(stderr, "Out of memory\n");
        return 1;
    }
    fread(src, 1, sz, f);
    src[sz] = '\0';
    fclose(f);

    // Feed parser
    yyin = fopen(fname, "r");
    if (!yyin)
    {
        perror("fopen yyin");
        free(src);
        return 1;
    }

    int pr = yyparse();
    fclose(yyin);
    if (pr != 0)
    {
        fprintf(stderr, "Parse error\n");
        free(src);
        return 1;
    }

    if (!ast_root)
    {
        fprintf(stderr, "No AST produced\n");
        free(src);
        return 1;
    }

    const char *outpath = "salida_arm64.s";
    int ok = 0;

    if (gui_sim)
    {
        // Simulate GUI: do NOT populate a Context here and pass NULL so generator
        // creates its own temporary Context (this replicates GUI behavior).
        ok = generate_arm64_from_ast_with_source(ast_root, NULL, outpath, src);
        if (ok)
            printf("Generated %s (gui-sim)\n", outpath);
        else
            printf("Generation failed (gui-sim)\n");
    }
    else
    {
        Context *ctx = nuevoContext(NULL);
        ctx->archivo = fopen("salida.txt", "w");
        if (!ctx->archivo)
        {
            perror("fopen salida.txt");
            free(src);
            return 1;
        }

        // Populate symbol table by interpreting only declaration/const/function nodes.
        // We do a simple DFS and call the node interpreter when it's one of the
        // registration-type nodes. This will register variables, constants and
        // function signatures (including main) without executing function bodies
        // or print statements.
        {
            AbstractExpresion **stack = NULL;
            size_t stack_cap = 0, stack_sz = 0;
            stack_cap = 128;
            stack = malloc(stack_cap * sizeof(AbstractExpresion *));
            if (stack)
            {
                stack[stack_sz++] = ast_root;
                while (stack_sz > 0)
                {
                    AbstractExpresion *n = stack[--stack_sz];
                    if (!n)
                        continue;

                    // If this node registers symbols, call its interpreter to populate the context
                    if (n->interpret == interpretDeclaracionVariable || n->interpret == interpretDeclaracionConstante || n->interpret == interpretFuncionExpresion)
                    {
                        // call interpreter (safe: these interpreters register symbols; function interpreter does not execute body)
                        n->interpret(n, ctx);
                        continue; // no need to descend into children for these nodes
                    }

                    // otherwise push children for traversal
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

        // For safety, set contextoActualReporte if used elsewhere (symbol lookup uses provided context pointer only).
        ok = generate_arm64_from_ast_with_source(ast_root, ctx, outpath, src);
        if (ok)
            printf("Generated %s\n", outpath);
        else
            printf("Generation failed\n");

        fclose(ctx->archivo);
    }
    free(src);
    return 0;
}
