#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "context/error_report.h"
#include "arrayLength.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constructor para acceso a .length
AbstractExpresion *nuevoArrayLengthExpresion(AbstractExpresion *arrayExpresion, int linea, int columna)
{
    ArrayLengthExpresion *nuevo = (ArrayLengthExpresion *)malloc(sizeof(ArrayLengthExpresion));
    if (!nuevo)
        return NULL;

    nuevo->super.interpret = interpretarArrayLength;
    nuevo->super.linea = linea;
    nuevo->super.columna = columna;
    nuevo->arrayExpresion = arrayExpresion;

    return (AbstractExpresion *)nuevo;
}

// Función de interpretación
Result interpretarArrayLength(AbstractExpresion *expresion, Context *contexto)
{
    ArrayLengthExpresion *arrayLength = (ArrayLengthExpresion *)expresion;

    // Evaluar la expresión que debe resultar en un array
    Result resultArray = arrayLength->arrayExpresion->interpret(arrayLength->arrayExpresion, contexto);

    if (resultArray.tipo == NULO)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Error al evaluar la expresión para acceso a .length");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        int *valorError = malloc(sizeof(int));
        *valorError = 0;
        return nuevoValorResultado(valorError, INT);
    }

    // Verificar que el resultado sea un array
    if (resultArray.tipo != ARRAY)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "La propiedad .length solo puede aplicarse a arrays");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        int *valorError = malloc(sizeof(int));
        *valorError = 0;
        return nuevoValorResultado(valorError, INT);
    }

    // Obtener la estructura del array
    ArrayStruct *arrayStruct = (ArrayStruct *)resultArray.valor;
    if (!arrayStruct)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Array inválido para acceso a .length");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        int *valorError = malloc(sizeof(int));
        *valorError = 0;
        return nuevoValorResultado(valorError, INT);
    }

    // Crear el resultado con el tamaño del array
    int *valorResultado = malloc(sizeof(int));
    if (!valorResultado)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Error de memoria al obtener .length del array");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        int *valorError = malloc(sizeof(int));
        *valorError = 0;
        return nuevoValorResultado(valorError, INT);
    }

    *valorResultado = arrayStruct->tamaño;

    return nuevoValorResultado(valorResultado, INT);
}