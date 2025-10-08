#ifndef FLOAT_PARSE_H
#define FLOAT_PARSE_H

#include "ast/AbstractExpresion.h"

// Estructura para la expresión Double.parseDouble()
typedef struct
{
    AbstractExpresion base;
} DoubleParseDoubleExpresion;

// Estructura para la expresión Float.parseFloat()
typedef struct
{
    AbstractExpresion base;
} FloatParseFloatExpresion;

// Función para interpretar Double.parseDouble()
Result interpretDoubleParseDoubleExpresion(AbstractExpresion *self, Context *context);

// Función para interpretar Float.parseFloat()
Result interpretFloatParseFloatExpresion(AbstractExpresion *self, Context *context);

// Constructor para Double.parseDouble()
AbstractExpresion *nuevoDoubleParseDoubleExpresion(AbstractExpresion *expresion, int linea, int columna);

// Constructor para Float.parseFloat()
AbstractExpresion *nuevoFloatParseFloatExpresion(AbstractExpresion *expresion, int linea, int columna);

#endif // FLOAT_PARSE_H