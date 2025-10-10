#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "context/error_report.h"
#include "arrayAdd.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Constructor para array.add()
AbstractExpresion *nuevoArrayAddExpresion(AbstractExpresion *arrayExpresion, AbstractExpresion *elementoExpresion, int linea, int columna)
{
    ArrayAddExpresion *nuevo = (ArrayAddExpresion *)malloc(sizeof(ArrayAddExpresion));
    if (!nuevo)
        return NULL;

    buildAbstractExpresion(&nuevo->super, interpretarArrayAdd);
    nuevo->super.linea = linea;
    nuevo->super.columna = columna;
    nuevo->arrayExpresion = arrayExpresion;
    nuevo->elementoExpresion = elementoExpresion;

    return (AbstractExpresion *)nuevo;
}

// Función de interpretación
Result interpretarArrayAdd(AbstractExpresion *expresion, Context *contexto)
{
    ArrayAddExpresion *arrayAdd = (ArrayAddExpresion *)expresion;

    // Evaluar la expresión que debe resultar en un array
    Result resultArray = arrayAdd->arrayExpresion->interpret(arrayAdd->arrayExpresion, contexto);

    if (resultArray.tipo == NULO)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Error al evaluar la expresión del array para array.add()");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        return nuevoValorResultadoVacio();
    }

    // Verificar que el resultado sea un array
    if (resultArray.tipo != ARRAY)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "El método .add() solo puede aplicarse a arrays");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        return nuevoValorResultadoVacio();
    }

    // Obtener la estructura del array
    ArrayStruct *arrayStruct = (ArrayStruct *)resultArray.valor;
    if (!arrayStruct)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Array inválido para array.add()");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        return nuevoValorResultadoVacio();
    }

    // Evaluar el elemento a agregar
    Result resultElemento = arrayAdd->elementoExpresion->interpret(arrayAdd->elementoExpresion, contexto);
    if (resultElemento.tipo == NULO)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Error al evaluar el elemento para array.add()");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        return nuevoValorResultadoVacio();
    }

    // Verificar que el tipo del elemento coincida con el tipo del array
    if (arrayStruct->tipoElemento != resultElemento.tipo)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Tipo incompatible: esperado %s, recibido %s en array.add()",
                 labelTipoDato[arrayStruct->tipoElemento], labelTipoDato[resultElemento.tipo]);
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        return nuevoValorResultadoVacio();
    }

    // Crear el nuevo array con el elemento agregado
    ArrayStruct *nuevoArray = crearArrayConElementoAgregado(arrayStruct, resultElemento.valor, resultElemento.tipo);
    if (!nuevoArray)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Error de memoria al crear nuevo array en array.add()");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        return nuevoValorResultadoVacio();
    }

    return nuevoValorResultado(nuevoArray, ARRAY);
}

// Función auxiliar para crear una copia del array con el nuevo elemento
ArrayStruct *crearArrayConElementoAgregado(ArrayStruct *arrayOriginal, void *nuevoElemento, TipoDato tipoElemento)
{
    if (!arrayOriginal || !nuevoElemento)
        return NULL;

    // Crear un nuevo array con un tamaño incrementado en 1
    ArrayStruct *nuevoArray = malloc(sizeof(ArrayStruct));
    if (!nuevoArray)
        return NULL;

    nuevoArray->tipoElemento = arrayOriginal->tipoElemento;
    nuevoArray->tamaño = arrayOriginal->tamaño + 1;
    nuevoArray->elementos = malloc(sizeof(void *) * nuevoArray->tamaño);
    if (!nuevoArray->elementos)
    {
        free(nuevoArray);
        return NULL;
    }

    // Copiar todos los elementos existentes
    for (int i = 0; i < arrayOriginal->tamaño; i++)
    {
        if (arrayOriginal->elementos[i])
        {
            // Crear una copia del elemento según su tipo
            switch (tipoElemento)
            {
            case INT:
            {
                int *copia = malloc(sizeof(int));
                *copia = *((int *)arrayOriginal->elementos[i]);
                nuevoArray->elementos[i] = copia;
                break;
            }
            case FLOAT:
            {
                float *copia = malloc(sizeof(float));
                *copia = *((float *)arrayOriginal->elementos[i]);
                nuevoArray->elementos[i] = copia;
                break;
            }
            case DOUBLE:
            {
                double *copia = malloc(sizeof(double));
                *copia = *((double *)arrayOriginal->elementos[i]);
                nuevoArray->elementos[i] = copia;
                break;
            }
            case BOOLEAN:
            {
                bool *copia = malloc(sizeof(bool));
                *copia = *((bool *)arrayOriginal->elementos[i]);
                nuevoArray->elementos[i] = copia;
                break;
            }
            case CHAR:
            {
                char *copia = malloc(sizeof(char));
                *copia = *((char *)arrayOriginal->elementos[i]);
                nuevoArray->elementos[i] = copia;
                break;
            }
            case STRING:
            {
                char *copia = strdup((char *)arrayOriginal->elementos[i]);
                nuevoArray->elementos[i] = copia;
                break;
            }
            default:
                // Para tipos no soportados, solo asignar NULL
                nuevoArray->elementos[i] = NULL;
                break;
            }
        }
        else
        {
            nuevoArray->elementos[i] = NULL;
        }
    }

    // Agregar el nuevo elemento al final
    switch (tipoElemento)
    {
    case INT:
    {
        int *copia = malloc(sizeof(int));
        *copia = *((int *)nuevoElemento);
        nuevoArray->elementos[arrayOriginal->tamaño] = copia;
        break;
    }
    case FLOAT:
    {
        float *copia = malloc(sizeof(float));
        *copia = *((float *)nuevoElemento);
        nuevoArray->elementos[arrayOriginal->tamaño] = copia;
        break;
    }
    case DOUBLE:
    {
        double *copia = malloc(sizeof(double));
        *copia = *((double *)nuevoElemento);
        nuevoArray->elementos[arrayOriginal->tamaño] = copia;
        break;
    }
    case BOOLEAN:
    {
        bool *copia = malloc(sizeof(bool));
        *copia = *((bool *)nuevoElemento);
        nuevoArray->elementos[arrayOriginal->tamaño] = copia;
        break;
    }
    case CHAR:
    {
        char *copia = malloc(sizeof(char));
        *copia = *((char *)nuevoElemento);
        nuevoArray->elementos[arrayOriginal->tamaño] = copia;
        break;
    }
    case STRING:
    {
        char *copia = strdup((char *)nuevoElemento);
        nuevoArray->elementos[arrayOriginal->tamaño] = copia;
        break;
    }
    default:
        // Para tipos no soportados, asignar NULL
        nuevoArray->elementos[arrayOriginal->tamaño] = NULL;
        break;
    }

    return nuevoArray;
}