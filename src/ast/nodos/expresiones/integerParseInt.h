#ifndef INTEGER_PARSE_INT_H
#define INTEGER_PARSE_INT_H

#include "ast/AbstractExpresion.h"

// Estructura para la expresión Integer.parseInt()
typedef struct
{
    AbstractExpresion base;
} IntegerParseIntExpresion;

// Función para interpretar Integer.parseInt()
Result interpretIntegerParseIntExpresion(AbstractExpresion *self, Context *context);

// Constructor para Integer.parseInt()
AbstractExpresion *nuevoIntegerParseIntExpresion(AbstractExpresion *expresion, int linea, int columna);

#endif // INTEGER_PARSE_INT_H