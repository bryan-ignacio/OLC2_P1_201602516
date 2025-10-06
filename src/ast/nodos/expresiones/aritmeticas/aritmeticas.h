#ifndef ARITMETICAS_H
#define ARITMETICAS_H

#include "ast/AbstractExpresion.h"
#include "context/result.h"
#include "context/context.h"
#include "ast/nodos/expresiones/expresiones.h"
#include "casting.h"

/* SUMA */
Result sumarIntInt(Result, Result);
Result sumarFloatFloat(Result, Result);
Result sumarIntFloat(Result, Result);
Result sumarFloatInt(Result, Result);

// Operaciones con CHAR
Result sumarCharChar(Result, Result);
Result sumarCharInt(Result, Result);
Result sumarIntChar(Result, Result);
Result sumarCharFloat(Result, Result);
Result sumarFloatChar(Result, Result);
Result sumarCharDouble(Result, Result);
Result sumarDoubleChar(Result, Result);

// Operaciones con DOUBLE
Result sumarDoubleDouble(Result, Result);
Result sumarIntDouble(Result, Result);
Result sumarDoubleInt(Result, Result);
Result sumarFloatDouble(Result, Result);
Result sumarDoubleFloat(Result, Result);

extern Operacion tablaOperacionesSuma[TIPO_COUNT][TIPO_COUNT];

/* RESTA */
Result restaIntInt(Result, Result);
Result restaFloatFloat(Result, Result);
Result restaIntFloat(Result, Result);
Result restaFloatInt(Result, Result);

// Operaciones con CHAR
Result restaCharChar(Result, Result);
Result restaCharInt(Result, Result);
Result restaIntChar(Result, Result);
Result restaCharFloat(Result, Result);
Result restaFloatChar(Result, Result);
Result restaCharDouble(Result, Result);
Result restaDoubleChar(Result, Result);

// Operaciones con DOUBLE
Result restaDoubleDouble(Result, Result);
Result restaIntDouble(Result, Result);
Result restaDoubleInt(Result, Result);
Result restaFloatDouble(Result, Result);
Result restaDoubleFloat(Result, Result);

extern Operacion tablaOperacionesResta[TIPO_COUNT][TIPO_COUNT];

/* MULTIPLICACION */
Result multiplicarIntInt(Result, Result);
Result multiplicarFloatFloat(Result, Result);
Result multiplicarIntFloat(Result, Result);
Result multiplicarFloatInt(Result, Result);

// Operaciones con CHAR
Result multiplicarCharChar(Result, Result);
Result multiplicarCharInt(Result, Result);
Result multiplicarIntChar(Result, Result);
Result multiplicarCharFloat(Result, Result);
Result multiplicarFloatChar(Result, Result);
Result multiplicarCharDouble(Result, Result);
Result multiplicarDoubleChar(Result, Result);

// Operaciones con DOUBLE
Result multiplicarDoubleDouble(Result, Result);
Result multiplicarIntDouble(Result, Result);
Result multiplicarDoubleInt(Result, Result);
Result multiplicarFloatDouble(Result, Result);
Result multiplicarDoubleFloat(Result, Result);

extern Operacion tablaOperacionesMultiplicacion[TIPO_COUNT][TIPO_COUNT];

/* DIVISION */
Result dividirIntInt(Result, Result);
Result dividirFloatFloat(Result, Result);
Result dividirIntFloat(Result, Result);
Result dividirFloatInt(Result, Result);

// Operaciones con CHAR
Result dividirCharChar(Result, Result);
Result dividirCharInt(Result, Result);
Result dividirIntChar(Result, Result);
Result dividirCharFloat(Result, Result);
Result dividirFloatChar(Result, Result);
Result dividirCharDouble(Result, Result);
Result dividirDoubleChar(Result, Result);

// Operaciones con DOUBLE
Result dividirDoubleDouble(Result, Result);
Result dividirIntDouble(Result, Result);
Result dividirDoubleInt(Result, Result);
Result dividirFloatDouble(Result, Result);
Result dividirDoubleFloat(Result, Result);

extern Operacion tablaOperacionesDivision[TIPO_COUNT][TIPO_COUNT];

/* MODULO */
Result moduloIntInt(Result, Result);
Result moduloFloatFloat(Result, Result);
Result moduloIntFloat(Result, Result);
Result moduloFloatInt(Result, Result);

// Operaciones con CHAR
Result moduloCharChar(Result, Result);
Result moduloCharInt(Result, Result);
Result moduloIntChar(Result, Result);
Result moduloCharFloat(Result, Result);
Result moduloFloatChar(Result, Result);
Result moduloCharDouble(Result, Result);
Result moduloDoubleChar(Result, Result);

// Operaciones con DOUBLE
Result moduloDoubleDouble(Result, Result);
Result moduloIntDouble(Result, Result);
Result moduloDoubleInt(Result, Result);
Result moduloFloatDouble(Result, Result);
Result moduloDoubleFloat(Result, Result);

extern Operacion tablaOperacionesModulo[TIPO_COUNT][TIPO_COUNT];

/* UNARIO */
Result negarAritmeticoInt(Result, Result);
Result negarAritmeticoFloat(Result, Result);

extern Operacion tablaOperacionesUnario[TIPO_COUNT][TIPO_COUNT];

#endif