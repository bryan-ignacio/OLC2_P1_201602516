#ifndef ARRAYS_INDEXOF_H
#define ARRAYS_INDEXOF_H

#include "../../../context/definiciones.h"
#include "../../../context/context.h"
#include "../../../context/result.h"
#include "../../AbstractExpresion.h"

// Estructura para Arrays.indexOf()
typedef struct ArraysIndexOfExpresion
{
    AbstractExpresion super;
    AbstractExpresion *argumentos; // Lista completa: array + elemento a buscar
} ArraysIndexOfExpresion;

// Constructor para Arrays.indexOf()
AbstractExpresion *nuevoArraysIndexOfExpresion(AbstractExpresion *argumentos, int linea, int columna);

// Función de interpretación
Result interpretarArraysIndexOf(AbstractExpresion *expresion, Context *contexto);

// Función para buscar el índice de un elemento en un array
int buscarIndiceEnArray(ArrayStruct *arrayStruct, void *elemento, TipoDato tipoElemento);

#endif // ARRAYS_INDEXOF_H