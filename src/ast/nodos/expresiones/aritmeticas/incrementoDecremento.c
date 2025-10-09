#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "context/error_report.h"
#include "incrementoDecremento.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constructor para pre-incremento (++variable)
AbstractExpresion *nuevoPreIncrementoExpresion(char *identificador, int linea, int columna)
{
    IncrementoDecrementoExpresion *nuevo = (IncrementoDecrementoExpresion *)malloc(sizeof(IncrementoDecrementoExpresion));
    if (!nuevo)
        return NULL;

    nuevo->super.interpret = interpretarIncrementoDecremento;
    nuevo->super.linea = linea;
    nuevo->super.columna = columna;
    nuevo->identificador = strdup(identificador);
    nuevo->tipo = OP_PRE_INCREMENT;

    return (AbstractExpresion *)nuevo;
}

// Constructor para post-incremento (variable++)
AbstractExpresion *nuevoPostIncrementoExpresion(char *identificador, int linea, int columna)
{
    IncrementoDecrementoExpresion *nuevo = (IncrementoDecrementoExpresion *)malloc(sizeof(IncrementoDecrementoExpresion));
    if (!nuevo)
        return NULL;

    nuevo->super.interpret = interpretarIncrementoDecremento;
    nuevo->super.linea = linea;
    nuevo->super.columna = columna;
    nuevo->identificador = strdup(identificador);
    nuevo->tipo = OP_POST_INCREMENT;

    return (AbstractExpresion *)nuevo;
}

// Constructor para pre-decremento (--variable)
AbstractExpresion *nuevoPreDecrementoExpresion(char *identificador, int linea, int columna)
{
    IncrementoDecrementoExpresion *nuevo = (IncrementoDecrementoExpresion *)malloc(sizeof(IncrementoDecrementoExpresion));
    if (!nuevo)
        return NULL;

    nuevo->super.interpret = interpretarIncrementoDecremento;
    nuevo->super.linea = linea;
    nuevo->super.columna = columna;
    nuevo->identificador = strdup(identificador);
    nuevo->tipo = OP_PRE_DECREMENT;

    return (AbstractExpresion *)nuevo;
}

// Constructor para post-decremento (variable--)
AbstractExpresion *nuevoPostDecrementoExpresion(char *identificador, int linea, int columna)
{
    IncrementoDecrementoExpresion *nuevo = (IncrementoDecrementoExpresion *)malloc(sizeof(IncrementoDecrementoExpresion));
    if (!nuevo)
        return NULL;

    nuevo->super.interpret = interpretarIncrementoDecremento;
    nuevo->super.linea = linea;
    nuevo->super.columna = columna;
    nuevo->identificador = strdup(identificador);
    nuevo->tipo = OP_POST_DECREMENT;

    return (AbstractExpresion *)nuevo;
}

// Función de interpretación
Result interpretarIncrementoDecremento(AbstractExpresion *expresion, Context *contexto)
{
    IncrementoDecrementoExpresion *incDec = (IncrementoDecrementoExpresion *)expresion;

    // Buscar la variable en el contexto
    Symbol *simbolo = buscarTablaSimbolos(contexto, incDec->identificador);
    if (!simbolo)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "El identificador no existe %s", incDec->identificador);
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        return nuevoValorResultadoVacio();
    }

    // Verificar que sea una variable (no constante)
    if (simbolo->esConstante)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "No se puede modificar la constante '%s'", incDec->identificador);
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        return nuevoValorResultadoVacio();
    }

    // Verificar que sea un tipo numérico
    if (simbolo->tipo != INT && simbolo->tipo != FLOAT && simbolo->tipo != DOUBLE)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "El incremento/decremento solo se puede aplicar a tipos numéricos");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        return nuevoValorResultadoVacio();
    }

    // Obtener el valor actual y hacer una copia para post-operaciones
    void *valorAnteriorCopia = NULL;

    switch (simbolo->tipo)
    {
    case INT:
        valorAnteriorCopia = malloc(sizeof(int));
        *(int *)valorAnteriorCopia = *(int *)simbolo->valor;
        break;
    case FLOAT:
        valorAnteriorCopia = malloc(sizeof(float));
        *(float *)valorAnteriorCopia = *(float *)simbolo->valor;
        break;
    case DOUBLE:
        valorAnteriorCopia = malloc(sizeof(double));
        *(double *)valorAnteriorCopia = *(double *)simbolo->valor;
        break;
    default:
        break;
    }

    // Realizar la operación según el tipo
    void *nuevoValor = NULL;

    switch (simbolo->tipo)
    {
    case INT:
    {
        int *valorInt = (int *)simbolo->valor;
        nuevoValor = malloc(sizeof(int));

        switch (incDec->tipo)
        {
        case OP_PRE_INCREMENT:
        case OP_POST_INCREMENT:
            *(int *)nuevoValor = (*valorInt) + 1;
            break;
        case OP_PRE_DECREMENT:
        case OP_POST_DECREMENT:
            *(int *)nuevoValor = (*valorInt) - 1;
            break;
        }
        break;
    }
    case FLOAT:
    {
        float *valorFloat = (float *)simbolo->valor;
        nuevoValor = malloc(sizeof(float));

        switch (incDec->tipo)
        {
        case OP_PRE_INCREMENT:
        case OP_POST_INCREMENT:
            *(float *)nuevoValor = (*valorFloat) + 1.0f;
            break;
        case OP_PRE_DECREMENT:
        case OP_POST_DECREMENT:
            *(float *)nuevoValor = (*valorFloat) - 1.0f;
            break;
        }
        break;
    }
    case DOUBLE:
    {
        double *valorDouble = (double *)simbolo->valor;
        nuevoValor = malloc(sizeof(double));

        switch (incDec->tipo)
        {
        case OP_PRE_INCREMENT:
        case OP_POST_INCREMENT:
            *(double *)nuevoValor = (*valorDouble) + 1.0;
            break;
        case OP_PRE_DECREMENT:
        case OP_POST_DECREMENT:
            *(double *)nuevoValor = (*valorDouble) - 1.0;
            break;
        }
        break;
    }
    default:
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Tipo no soportado para incremento/decremento");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        return nuevoValorResultadoVacio();
    }
    }

    // Actualizar el valor en el contexto
    free(simbolo->valor);
    simbolo->valor = nuevoValor;

    // Retornar el valor según el tipo de operación
    switch (incDec->tipo)
    {
    case OP_PRE_INCREMENT:
    case OP_PRE_DECREMENT:
        // Pre-incremento/decremento: retorna el nuevo valor
        if (valorAnteriorCopia)
            free(valorAnteriorCopia);
        return nuevoValorResultado(simbolo->valor, simbolo->tipo);

    case OP_POST_INCREMENT:
    case OP_POST_DECREMENT:
        // Post-incremento/decremento: retorna el valor anterior
        return nuevoValorResultado(valorAnteriorCopia, simbolo->tipo);

    default:
        if (valorAnteriorCopia)
            free(valorAnteriorCopia);
        return nuevoValorResultadoVacio();
    }
}