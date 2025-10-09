#ifndef ARRAY_LENGTH_H
#define ARRAY_LENGTH_H

#include "../../../context/definiciones.h"
#include "../../../context/context.h"
#include "../../../context/result.h"
#include "../../AbstractExpresion.h"

// Estructura para acceso a propiedad .length de arrays
typedef struct ArrayLengthExpresion
{
    AbstractExpresion super;
    AbstractExpresion *arrayExpresion; // Expresión que debe resultar en un array
} ArrayLengthExpresion;

// Constructor para acceso a .length
AbstractExpresion *nuevoArrayLengthExpresion(AbstractExpresion *arrayExpresion, int linea, int columna);

// Función de interpretación
Result interpretarArrayLength(AbstractExpresion *expresion, Context *contexto);

#endif // ARRAY_LENGTH_H