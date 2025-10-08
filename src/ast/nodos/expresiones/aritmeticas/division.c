#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "aritmeticas.h"
#include "ast/nodos/expresiones/expresiones.h"
#include "casting.h"

#include <stdlib.h>
#include <stdio.h>

// Función auxiliar para verificar división por cero
int esCero(Result operando)
{
    switch (operando.tipo)
    {
    case CHAR:
        return *((char *)operando.valor) == 0;
    case INT:
        return *((int *)operando.valor) == 0;
    case FLOAT:
        return *((float *)operando.valor) == 0.0f;
    case DOUBLE:
        return *((double *)operando.valor) == 0.0;
    default:
        return 0;
    }
}

Result dividirIntInt(Result izquierda, Result derecha)
{
    // Verificar división por cero
    if (esCero(derecha))
    {
        printf("Error: División por cero detectada\n");
        return nuevoValorResultadoVacio();
    }

    // División entera: mantener resultado como int (división entera)
    int *res = malloc(sizeof(int));
    *res = *((int *)izquierda.valor) / *((int *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result dividirFloatFloat(Result izquierda, Result derecha)
{
    // Verificar división por cero
    if (esCero(derecha))
    {
        printf("Error: División por cero detectada\n");
        return nuevoValorResultadoVacio();
    }

    float *res = malloc(sizeof(float));
    *res = *((float *)izquierda.valor) / *((float *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result dividirIntFloat(Result izquierda, Result derecha)
{
    // Verificar división por cero
    if (esCero(derecha))
    {
        printf("Error: División por cero detectada\n");
        return nuevoValorResultadoVacio();
    }

    float *res = malloc(sizeof(float));
    *res = (float)*((int *)izquierda.valor) / *((float *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result dividirFloatInt(Result izquierda, Result derecha)
{
    // Verificar división por cero
    if (esCero(derecha))
    {
        printf("Error: División por cero detectada\n");
        return nuevoValorResultadoVacio();
    }

    float *res = malloc(sizeof(float));
    *res = *((float *)izquierda.valor) / (float)*((int *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

// ========== OPERACIONES CON CHAR ==========
Result dividirCharChar(Result izquierda, Result derecha)
{
    // Verificar división por cero
    if (esCero(derecha))
    {
        printf("Error: División por cero detectada\n");
        return nuevoValorResultadoVacio();
    }

    // char / char promociona a float
    float *res = malloc(sizeof(float));
    *res = (float)*((char *)izquierda.valor) / (float)*((char *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result dividirCharInt(Result izquierda, Result derecha)
{
    // Verificar división por cero
    if (esCero(derecha))
    {
        printf("Error: División por cero detectada\n");
        return nuevoValorResultadoVacio();
    }

    float *res = malloc(sizeof(float));
    *res = (float)*((char *)izquierda.valor) / (float)*((int *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result dividirIntChar(Result izquierda, Result derecha)
{
    // Verificar división por cero
    if (esCero(derecha))
    {
        printf("Error: División por cero detectada\n");
        return nuevoValorResultadoVacio();
    }

    float *res = malloc(sizeof(float));
    *res = (float)*((int *)izquierda.valor) / (float)*((char *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result dividirCharFloat(Result izquierda, Result derecha)
{
    // Verificar división por cero
    if (esCero(derecha))
    {
        printf("Error: División por cero detectada\n");
        return nuevoValorResultadoVacio();
    }

    float *res = malloc(sizeof(float));
    *res = (float)*((char *)izquierda.valor) / *((float *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result dividirFloatChar(Result izquierda, Result derecha)
{
    // Verificar división por cero
    if (esCero(derecha))
    {
        printf("Error: División por cero detectada\n");
        return nuevoValorResultadoVacio();
    }

    float *res = malloc(sizeof(float));
    *res = *((float *)izquierda.valor) / (float)*((char *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result dividirCharDouble(Result izquierda, Result derecha)
{
    // Verificar división por cero
    if (esCero(derecha))
    {
        printf("Error: División por cero detectada\n");
        return nuevoValorResultadoVacio();
    }

    double *res = malloc(sizeof(double));
    *res = (double)*((char *)izquierda.valor) / *((double *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Result dividirDoubleChar(Result izquierda, Result derecha)
{
    // Verificar división por cero
    if (esCero(derecha))
    {
        printf("Error: División por cero detectada\n");
        return nuevoValorResultadoVacio();
    }

    double *res = malloc(sizeof(double));
    *res = *((double *)izquierda.valor) / (double)*((char *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

// ========== OPERACIONES CON DOUBLE ==========
Result dividirDoubleDouble(Result izquierda, Result derecha)
{
    // Verificar división por cero
    if (esCero(derecha))
    {
        printf("Error: División por cero detectada\n");
        return nuevoValorResultadoVacio();
    }

    double *res = malloc(sizeof(double));
    *res = *((double *)izquierda.valor) / *((double *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Result dividirIntDouble(Result izquierda, Result derecha)
{
    // Verificar división por cero
    if (esCero(derecha))
    {
        printf("Error: División por cero detectada\n");
        return nuevoValorResultadoVacio();
    }

    double *res = malloc(sizeof(double));
    *res = (double)*((int *)izquierda.valor) / *((double *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Result dividirDoubleInt(Result izquierda, Result derecha)
{
    // Verificar división por cero
    if (esCero(derecha))
    {
        printf("Error: División por cero detectada\n");
        return nuevoValorResultadoVacio();
    }

    double *res = malloc(sizeof(double));
    *res = *((double *)izquierda.valor) / (double)*((int *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Result dividirFloatDouble(Result izquierda, Result derecha)
{
    // Verificar división por cero
    if (esCero(derecha))
    {
        printf("Error: División por cero detectada\n");
        return nuevoValorResultadoVacio();
    }

    double *res = malloc(sizeof(double));
    *res = (double)*((float *)izquierda.valor) / *((double *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Result dividirDoubleFloat(Result izquierda, Result derecha)
{
    // Verificar división por cero
    if (esCero(derecha))
    {
        printf("Error: División por cero detectada\n");
        return nuevoValorResultadoVacio();
    }

    double *res = malloc(sizeof(double));
    *res = *((double *)izquierda.valor) / (double)*((float *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Operacion tablaOperacionesDivision[TIPO_COUNT][TIPO_COUNT] = {
    // char operations
    [CHAR][CHAR] = dividirCharChar,
    [CHAR][INT] = dividirCharInt,
    [CHAR][FLOAT] = dividirCharFloat,
    [CHAR][DOUBLE] = dividirCharDouble,

    // int operations
    [INT][CHAR] = dividirIntChar,
    [INT][INT] = dividirIntInt,
    [INT][FLOAT] = dividirIntFloat,
    [INT][DOUBLE] = dividirIntDouble,

    // float operations
    [FLOAT][CHAR] = dividirFloatChar,
    [FLOAT][INT] = dividirFloatInt,
    [FLOAT][FLOAT] = dividirFloatFloat,
    [FLOAT][DOUBLE] = dividirFloatDouble,

    // double operations
    [DOUBLE][CHAR] = dividirDoubleChar,
    [DOUBLE][INT] = dividirDoubleInt,
    [DOUBLE][FLOAT] = dividirDoubleFloat,
    [DOUBLE][DOUBLE] = dividirDoubleDouble,
};

// builders.h
AbstractExpresion *nuevoDivisionExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    ExpresionLenguaje *divisionExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    divisionExpresion->tablaOperaciones = &tablaOperacionesDivision;
    return (AbstractExpresion *)divisionExpresion;
}