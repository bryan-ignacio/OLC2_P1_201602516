#ifndef BITWISE_H
#define BITWISE_H

#include "ast/AbstractExpresion.h"
#include "context/result.h"
#include "context/context.h"
#include "ast/nodos/expresiones/expresiones.h"

/* BITWISE AND (&) */
Result bitwiseAndIntInt(Result, Result);
Result bitwiseAndCharChar(Result, Result);
Result bitwiseAndCharInt(Result, Result);
Result bitwiseAndIntChar(Result, Result);

extern Operacion tablaOperacionesBitwiseAnd[TIPO_COUNT][TIPO_COUNT];

/* BITWISE OR (|) */
Result bitwiseOrIntInt(Result, Result);
Result bitwiseOrCharChar(Result, Result);
Result bitwiseOrCharInt(Result, Result);
Result bitwiseOrIntChar(Result, Result);

extern Operacion tablaOperacionesBitwiseOr[TIPO_COUNT][TIPO_COUNT];

/* BITWISE XOR (^) */
Result bitwiseXorIntInt(Result, Result);
Result bitwiseXorCharChar(Result, Result);
Result bitwiseXorCharInt(Result, Result);
Result bitwiseXorIntChar(Result, Result);

extern Operacion tablaOperacionesBitwiseXor[TIPO_COUNT][TIPO_COUNT];

/* BITWISE NOT (~) */
Result bitwiseNotInt(Result, Result);
Result bitwiseNotChar(Result, Result);

extern Operacion tablaOperacionesBitwiseNot[TIPO_COUNT][TIPO_COUNT];

/* BITWISE LEFT SHIFT (<<) */
Result bitwiseLeftShiftIntInt(Result, Result);
Result bitwiseLeftShiftCharChar(Result, Result);
Result bitwiseLeftShiftCharInt(Result, Result);
Result bitwiseLeftShiftIntChar(Result, Result);

extern Operacion tablaOperacionesBitwiseLeftShift[TIPO_COUNT][TIPO_COUNT];

/* BITWISE RIGHT SHIFT (>>) */
Result bitwiseRightShiftIntInt(Result, Result);
Result bitwiseRightShiftCharChar(Result, Result);
Result bitwiseRightShiftCharInt(Result, Result);
Result bitwiseRightShiftIntChar(Result, Result);

extern Operacion tablaOperacionesBitwiseRightShift[TIPO_COUNT][TIPO_COUNT];

#endif