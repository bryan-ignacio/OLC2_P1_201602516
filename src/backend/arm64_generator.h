// Generador ARM64 - interfaz mínima y segura
#ifndef ARM64_GENERATOR_H
#define ARM64_GENERATOR_H

#include "../ast/AbstractExpresion.h"
#include "../context/context.h"
#include <stdio.h>
#include <stdbool.h>

// Estructura opaca para el emisor
typedef struct Arm64Emitter Arm64Emitter;

// Genera código ARM64 a partir del AST y el contexto. Devuelve true si tuvo éxito.
// Nueva versión: acepta opcionalmente el texto fuente original (source_text).
// Si `source_text` es NULL, el generador intentará funcionar solo con el AST/contexto.
bool generate_arm64_from_ast(AbstractExpresion *ast, Context *contexto, const char *output_path);
bool generate_arm64_from_ast_with_source(AbstractExpresion *ast, Context *contexto, const char *output_path, const char *source_text);

// Creación / destrucción del emisor (opcionales si se usan directamente)
Arm64Emitter *arm64_emitter_create(FILE *out);
void arm64_emitter_destroy(Arm64Emitter *emitter);

// Emitir comentarios en formato ARM64
// Comentario de línea: comenzará con '#' y terminará con nueva línea.
void arm64_emit_line_comment(Arm64Emitter *emitter, const char *fmt, ...);

// Comentario multilínea: envolverá el texto entre /*  */
void arm64_emit_block_comment(Arm64Emitter *emitter, const char *text);

// Alias histórico: emite un comentario de línea (prefijo '#')
void arm64_emit_comment(Arm64Emitter *emitter, const char *fmt, ...);

#endif // ARM64_GENERATOR_H
