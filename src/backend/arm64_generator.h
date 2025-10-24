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

// Helpers para emitir instrucciones que usan registros
// Emite: mov <reg>, #<imm>
void arm64_emit_mov_imm(Arm64Emitter *emitter, const char *reg, long imm);

// Emite: adr <reg>, <label>
void arm64_emit_adr_label(Arm64Emitter *emitter, const char *reg, const char *label);

// Define una etiqueta con un string en el segmento de texto (p.ej. para pruebas de ADR)
// Emite:
// <label>:
//    .asciz "text"
void arm64_emit_label_string(Arm64Emitter *emitter, const char *label, const char *text);

// Helpers para registros de coma flotante
// Cargar un float (single) desde una etiqueta: genera ADR para un registro entero temporal
// y luego LDR hacia el registro de coma flotante: ldr s<reg>, [<temp>]
void arm64_emit_ldr_s_from_label(Arm64Emitter *emitter, const char *sreg, const char *label);

// Cargar un double (double) desde una etiqueta
void arm64_emit_ldr_d_from_label(Arm64Emitter *emitter, const char *dreg, const char *label);

// Memoria: cargas/almacenamientos generales
// Almacena el registro entero src_reg en la dirección apuntada por addr_reg: str <src_reg>, [<addr_reg>]
void arm64_emit_str_reg(Arm64Emitter *emitter, const char *src_reg, const char *addr_reg);

// Carga un registro entero desde la dirección apuntada por addr_reg: ldr <dst_reg>, [<addr_reg>]
void arm64_emit_ldr_reg(Arm64Emitter *emitter, const char *dst_reg, const char *addr_reg);

// Versiones para coma flotante (single / double)
void arm64_emit_str_s(Arm64Emitter *emitter, const char *sreg, const char *addr_reg);
void arm64_emit_ldr_s(Arm64Emitter *emitter, const char *sreg, const char *addr_reg);
void arm64_emit_str_d(Arm64Emitter *emitter, const char *dreg, const char *addr_reg);
void arm64_emit_ldr_d(Arm64Emitter *emitter, const char *dreg, const char *addr_reg);

// Etiquetas y control de flujo
// Define una etiqueta de código: emitirá "<label>:" en el flujo de instrucciones
void arm64_emit_code_label(Arm64Emitter *emitter, const char *label);

// Saltos: b <label>
void arm64_emit_b(Arm64Emitter *emitter, const char *label);

// Branch with link: bl <label> (guarda la dirección de retorno en x30)
void arm64_emit_bl(Arm64Emitter *emitter, const char *label);

// Branch to register: br <reg>
void arm64_emit_br(Arm64Emitter *emitter, const char *reg);

// Saltos condicionales: bne <label>, beq <label>, etc.
void arm64_emit_bne(Arm64Emitter *emitter, const char *label);
void arm64_emit_beq(Arm64Emitter *emitter, const char *label);

// Condicionales adicionales (lt, gt, le, ge)
void arm64_emit_blt(Arm64Emitter *emitter, const char *label);
void arm64_emit_bgt(Arm64Emitter *emitter, const char *label);
void arm64_emit_ble(Arm64Emitter *emitter, const char *label);
void arm64_emit_bge(Arm64Emitter *emitter, const char *label);

// Emite un salto condicional genérico con la condición textual (p.ej. "eq","ne","lt")
void arm64_emit_b_cond(Arm64Emitter *emitter, const char *cond, const char *label);

// Comparación (cmp xN, xM) y add inmediato (add xN, xN, #imm)
void arm64_emit_cmp_reg_reg(Arm64Emitter *emitter, const char *reg1, const char *reg2);
void arm64_emit_add_imm(Arm64Emitter *emitter, const char *dst_reg, const char *src_reg, long imm);

// Operadores aritméticos (enteros)
void arm64_emit_add_reg_reg(Arm64Emitter *emitter, const char *dst_reg, const char *lhs_reg, const char *rhs_reg);
void arm64_emit_sub_reg_reg(Arm64Emitter *emitter, const char *dst_reg, const char *lhs_reg, const char *rhs_reg);
void arm64_emit_mul_reg_reg(Arm64Emitter *emitter, const char *dst_reg, const char *lhs_reg, const char *rhs_reg);
// División con signo / sin signo
void arm64_emit_sdiv_reg_reg(Arm64Emitter *emitter, const char *dst_reg, const char *lhs_reg, const char *rhs_reg);
void arm64_emit_udiv_reg_reg(Arm64Emitter *emitter, const char *dst_reg, const char *lhs_reg, const char *rhs_reg);

// Incremento / decremento (inmediato 1)
void arm64_emit_incr(Arm64Emitter *emitter, const char *reg);
void arm64_emit_decr(Arm64Emitter *emitter, const char *reg);

#endif // ARM64_GENERATOR_H
