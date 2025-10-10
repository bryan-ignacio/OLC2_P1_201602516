#ifndef ARRAY_ADD_H
#define ARRAY_ADD_H

#include "../../../context/definiciones.h"
#include "../../../context/context.h"
#include "../../../context/result.h"
#include "../../AbstractExpresion.h"

// Estructura para array.add()
typedef struct ArrayAddExpresion
{
    AbstractExpresion super;
    AbstractExpresion *arrayExpresion;    // Expresión que debe resultar en un array
    AbstractExpresion *elementoExpresion; // Elemento a agregar al final del array
} ArrayAddExpresion;

// Constructor para array.add()
AbstractExpresion *nuevoArrayAddExpresion(AbstractExpresion *arrayExpresion, AbstractExpresion *elementoExpresion, int linea, int columna);

// Función de interpretación
Result interpretarArrayAdd(AbstractExpresion *expresion, Context *contexto);

// Función auxiliar para crear una copia del array con el nuevo elemento
ArrayStruct *crearArrayConElementoAgregado(ArrayStruct *arrayOriginal, void *nuevoElemento, TipoDato tipoElemento);

#endif // ARRAY_ADD_H