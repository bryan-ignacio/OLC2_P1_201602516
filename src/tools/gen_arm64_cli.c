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

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <input.usl>\n", argv[0]);
        return 1;
    }

    const char *fname = argv[1];
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

    Context *ctx = nuevoContext(NULL);
    ctx->archivo = fopen("salida.txt", "w");
    if (!ctx->archivo)
    {
        perror("fopen salida.txt");
        free(src);
        return 1;
    }

    // Interpret to fill symbols (but avoid executing heavy code). Some interpreters may assume runtime.
    // We'll skip full interpretation and just generate directly from AST using context for symbols if present.

    // For safety, set contextoActualReporte if used elsewhere (symbol lookup uses provided context pointer only).

    const char *outpath = "salida_arm64.s";
    int ok = generate_arm64_from_ast_with_source(ast_root, ctx, outpath, src);
    if (ok)
        printf("Generated %s\n", outpath);
    else
        printf("Generation failed\n");

    fclose(ctx->archivo);
    free(src);
    return 0;
}
