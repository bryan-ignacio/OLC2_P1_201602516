#ifndef STRING_VALUE_OF_H
#define STRING_VALUE_OF_H

#include "../../../context/definiciones.h"
#include "../../../context/context.h"
#include "../../../context/result.h"
#include "../../AbstractExpresion.h"

// Estructura para String.valueOf()
typedef struct StringValueOfExpresion
{
    AbstractExpresion super;
    AbstractExpresion *expresion;
} StringValueOfExpresion;

// Constructor para String.valueOf()
AbstractExpresion *nuevoStringValueOfExpresion(AbstractExpresion *expresion, int linea, int columna);

// Función de interpretación
Result interpretarStringValueOf(AbstractExpresion *expresion, Context *contexto);

// Función para convertir cualquier valor a string
char *convertirValorAString(Result *valor);

#endif // STRING_VALUE_OF_H