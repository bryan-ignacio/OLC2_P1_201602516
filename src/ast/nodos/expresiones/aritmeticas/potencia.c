#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "aritmeticas.h"
#include "ast/nodos/expresiones/expresiones.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Implementaciones para potencia. Usamos pow para floats/doubles; para ints usamos un cálculo entero.

/* Prototipos de funciones auxiliares que se definiran más abajo pero son usadas en la tabla */
Result potenciaFloatChar(Result izquierda, Result derecha);
Result potenciaDoubleChar(Result izquierda, Result derecha);
Result potenciaCharFloat(Result izquierda, Result derecha);
Result potenciaCharDouble(Result izquierda, Result derecha);

Result potenciaIntInt(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    int base = *((int *)izquierda.valor);
    int exp = *((int *)derecha.valor);
    // Implementación simple: si exp < 0, resultado 0 (entero) -- alternativa sería manejar como double
    if (exp < 0)
    {
        *res = 0;
    }
    else
    {
        int r = 1;
        for (int i = 0; i < exp; i++)
            r *= base;
        *res = r;
    }
    return nuevoValorResultado(res, INT);
}

Result potenciaFloatFloat(Result izquierda, Result derecha)
{
    float *res = malloc(sizeof(float));
    *res = powf(*((float *)izquierda.valor), *((float *)derecha.valor));
    return nuevoValorResultado(res, FLOAT);
}

Result potenciaIntFloat(Result izquierda, Result derecha)
{
    float *res = malloc(sizeof(float));
    *res = powf((float)*((int *)izquierda.valor), *((float *)derecha.valor));
    return nuevoValorResultado(res, FLOAT);
}

Result potenciaFloatInt(Result izquierda, Result derecha)
{
    float *res = malloc(sizeof(float));
    *res = powf(*((float *)izquierda.valor), (float)*((int *)derecha.valor));
    return nuevoValorResultado(res, FLOAT);
}

// CHAR treated as small integers
Result potenciaCharChar(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    int base = *((char *)izquierda.valor);
    int exp = *((char *)derecha.valor);
    if (exp < 0)
    {
        *res = 0;
    }
    else
    {
        int r = 1;
        for (int i = 0; i < exp; i++)
            r *= base;
        *res = r;
    }
    return nuevoValorResultado(res, INT);
}

Result potenciaCharInt(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    int base = *((char *)izquierda.valor);
    int exp = *((int *)derecha.valor);
    if (exp < 0)
    {
        *res = 0;
    }
    else
    {
        int r = 1;
        for (int i = 0; i < exp; i++)
            r *= base;
        *res = r;
    }
    return nuevoValorResultado(res, INT);
}

Result potenciaIntChar(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    int base = *((int *)izquierda.valor);
    int exp = *((char *)derecha.valor);
    if (exp < 0)
    {
        *res = 0;
    }
    else
    {
        int r = 1;
        for (int i = 0; i < exp; i++)
            r *= base;
        *res = r;
    }
    return nuevoValorResultado(res, INT);
}

Result potenciaDoubleDouble(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = pow(*((double *)izquierda.valor), *((double *)derecha.valor));
    return nuevoValorResultado(res, DOUBLE);
}

Result potenciaIntDouble(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = pow((double)*((int *)izquierda.valor), *((double *)derecha.valor));
    return nuevoValorResultado(res, DOUBLE);
}

Result potenciaDoubleInt(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = pow(*((double *)izquierda.valor), (double)*((int *)derecha.valor));
    return nuevoValorResultado(res, DOUBLE);
}

Result potenciaFloatDouble(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = pow((double)*((float *)izquierda.valor), *((double *)derecha.valor));
    return nuevoValorResultado(res, DOUBLE);
}

Result potenciaDoubleFloat(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = pow(*((double *)izquierda.valor), (double)*((float *)derecha.valor));
    return nuevoValorResultado(res, DOUBLE);
}

Operacion tablaOperacionesPotencia[TIPO_COUNT][TIPO_COUNT] = {
    // char operations
    [CHAR][CHAR] = potenciaCharChar,
    [CHAR][INT] = potenciaCharInt,
    [CHAR][FLOAT] = potenciaCharFloat,
    [CHAR][DOUBLE] = potenciaCharDouble,

    // int operations
    [INT][CHAR] = potenciaIntChar,
    [INT][INT] = potenciaIntInt,
    [INT][FLOAT] = potenciaIntFloat,
    [INT][DOUBLE] = potenciaIntDouble,

    // float operations
    [FLOAT][CHAR] = potenciaFloatChar,
    [FLOAT][INT] = potenciaFloatInt,
    [FLOAT][FLOAT] = potenciaFloatFloat,
    [FLOAT][DOUBLE] = potenciaFloatDouble,

    // double operations
    [DOUBLE][CHAR] = potenciaDoubleChar,
    [DOUBLE][INT] = potenciaDoubleInt,
    [DOUBLE][FLOAT] = potenciaDoubleFloat,
    [DOUBLE][DOUBLE] = potenciaDoubleDouble,
};

// Fallback definitions for a couple used above but not declared earlier
Result potenciaFloatChar(Result izquierda, Result derecha)
{
    float *res = malloc(sizeof(float));
    *res = powf(*((float *)izquierda.valor), (float)*((char *)derecha.valor));
    return nuevoValorResultado(res, FLOAT);
}

Result potenciaDoubleChar(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = pow(*((double *)izquierda.valor), (double)*((char *)derecha.valor));
    return nuevoValorResultado(res, DOUBLE);
}

Result potenciaCharFloat(Result izquierda, Result derecha)
{
    float *res = malloc(sizeof(float));
    *res = powf((float)*((char *)izquierda.valor), *((float *)derecha.valor));
    return nuevoValorResultado(res, FLOAT);
}

Result potenciaCharDouble(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = pow((double)*((char *)izquierda.valor), *((double *)derecha.valor));
    return nuevoValorResultado(res, DOUBLE);
}

// Constructor
AbstractExpresion *nuevoPotenciaExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    ExpresionLenguaje *potExp = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    potExp->tablaOperaciones = &tablaOperacionesPotencia;
    return (AbstractExpresion *)potExp;
}
