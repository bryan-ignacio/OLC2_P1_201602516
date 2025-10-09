#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "context/error_report.h"
#include "arraysIndexOf.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constructor para Arrays.indexOf()
AbstractExpresion *nuevoArraysIndexOfExpresion(AbstractExpresion *argumentos, int linea, int columna)
{
    ArraysIndexOfExpresion *nuevo = (ArraysIndexOfExpresion *)malloc(sizeof(ArraysIndexOfExpresion));
    if (!nuevo)
        return NULL;

    nuevo->super.interpret = interpretarArraysIndexOf;
    nuevo->super.linea = linea;
    nuevo->super.columna = columna;
    nuevo->argumentos = argumentos;

    return (AbstractExpresion *)nuevo;
}

// Función de interpretación
Result interpretarArraysIndexOf(AbstractExpresion *expresion, Context *contexto)
{
    ArraysIndexOfExpresion *arraysIndexOf = (ArraysIndexOfExpresion *)expresion;

    // Obtener la lista de argumentos
    AbstractExpresion *lista = arraysIndexOf->argumentos;
    if (!lista->hijos || lista->numHijos != 2)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Arrays.indexOf() requiere exactamente 2 argumentos (array, elemento)");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        return nuevoValorResultado(malloc(sizeof(int)), INT);
    }

    // El primer argumento es el array
    Result resultArray = lista->hijos[0]->interpret(lista->hijos[0], contexto);
    if (resultArray.tipo == NULO)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Error al interpretar array en Arrays.indexOf()");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        int *valorError = malloc(sizeof(int));
        *valorError = -1;
        return nuevoValorResultado(valorError, INT);
    }

    if (resultArray.tipo != ARRAY)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "El primer argumento debe ser un array en Arrays.indexOf()");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        int *valorError = malloc(sizeof(int));
        *valorError = -1;
        return nuevoValorResultado(valorError, INT);
    }

    // El segundo argumento es el elemento a buscar
    Result resultElemento = lista->hijos[1]->interpret(lista->hijos[1], contexto);
    if (resultElemento.tipo == NULO)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Error al interpretar elemento en Arrays.indexOf()");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        int *valorError = malloc(sizeof(int));
        *valorError = -1;
        return nuevoValorResultado(valorError, INT);
    }

    // Obtener la estructura del array
    ArrayStruct *arrayStruct = (ArrayStruct *)resultArray.valor;

    // Verificar que el tipo del elemento coincida con el tipo del array
    if (arrayStruct->tipoElemento != resultElemento.tipo)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "El tipo del elemento a buscar no coincide con el tipo del array en Arrays.indexOf()");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        int *valorError = malloc(sizeof(int));
        *valorError = -1;
        return nuevoValorResultado(valorError, INT);
    }

    // Buscar el índice del elemento en el array
    int indice = buscarIndiceEnArray(arrayStruct, resultElemento.valor, resultElemento.tipo);

    // Crear el resultado
    int *valorResultado = malloc(sizeof(int));
    *valorResultado = indice;

    return nuevoValorResultado(valorResultado, INT);
}

// Función para buscar el índice de un elemento en un array
int buscarIndiceEnArray(ArrayStruct *arrayStruct, void *elemento, TipoDato tipoElemento)
{
    if (!arrayStruct || !elemento)
        return -1;

    for (int i = 0; i < arrayStruct->tamaño; i++)
    {
        void *elementoArray = arrayStruct->elementos[i];
        if (!elementoArray)
            continue;

        bool encontrado = false;

        switch (tipoElemento)
        {
        case INT:
        {
            int *valorBuscado = (int *)elemento;
            int *valorArray = (int *)elementoArray;
            encontrado = (*valorBuscado == *valorArray);
            break;
        }
        case FLOAT:
        {
            float *valorBuscado = (float *)elemento;
            float *valorArray = (float *)elementoArray;
            encontrado = (*valorBuscado == *valorArray);
            break;
        }
        case DOUBLE:
        {
            double *valorBuscado = (double *)elemento;
            double *valorArray = (double *)elementoArray;
            encontrado = (*valorBuscado == *valorArray);
            break;
        }
        case BOOLEAN:
        {
            bool *valorBuscado = (bool *)elemento;
            bool *valorArray = (bool *)elementoArray;
            encontrado = (*valorBuscado == *valorArray);
            break;
        }
        case CHAR:
        {
            char *valorBuscado = (char *)elemento;
            char *valorArray = (char *)elementoArray;
            encontrado = (*valorBuscado == *valorArray);
            break;
        }
        case STRING:
        {
            char *valorBuscado = (char *)elemento;
            char *valorArray = (char *)elementoArray;
            encontrado = (strcmp(valorBuscado, valorArray) == 0);
            break;
        }
        default:
            // Tipos no soportados
            return -1;
        }

        if (encontrado)
        {
            return i; // Retornar el índice de la primera ocurrencia
        }
    }

    return -1; // No encontrado
}