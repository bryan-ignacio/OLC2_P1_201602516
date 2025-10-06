#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "aritmeticas.h"
#include "ast/nodos/expresiones/expresiones.h"
#include "casting.h"

#include <stdlib.h>
#include <stdio.h>

Result restaIntInt(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((int *)izquierda.valor) - *((int *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result restaFloatFloat(Result izquierda, Result derecha)
{
    float *res = malloc(sizeof(float));
    *res = *((float *)izquierda.valor) - *((float *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result restaIntFloat(Result izquierda, Result derecha)
{
    float *res = malloc(sizeof(float));
    *res = *((int *)izquierda.valor) - *((float *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result restaFloatInt(Result izquierda, Result derecha)
{
    float *res = malloc(sizeof(float));
    *res = *((float *)izquierda.valor) - *((int *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

// ========== OPERACIONES CON CHAR ==========
Result restaCharChar(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((char *)izquierda.valor) - *((char *)derecha.valor);
    return nuevoValorResultado(res, INT); // char - char promociona a int
}

Result restaCharInt(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((char *)izquierda.valor) - *((int *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result restaIntChar(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((int *)izquierda.valor) - *((char *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result restaCharFloat(Result izquierda, Result derecha)
{
    float *res = malloc(sizeof(float));
    *res = *((char *)izquierda.valor) - *((float *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result restaFloatChar(Result izquierda, Result derecha)
{
    float *res = malloc(sizeof(float));
    *res = *((float *)izquierda.valor) - *((char *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result restaCharDouble(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((char *)izquierda.valor) - *((double *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Result restaDoubleChar(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((double *)izquierda.valor) - *((char *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

// ========== OPERACIONES CON DOUBLE ==========
Result restaDoubleDouble(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((double *)izquierda.valor) - *((double *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Result restaIntDouble(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((int *)izquierda.valor) - *((double *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Result restaDoubleInt(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((double *)izquierda.valor) - *((int *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Result restaFloatDouble(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((float *)izquierda.valor) - *((double *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Result restaDoubleFloat(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((double *)izquierda.valor) - *((float *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Operacion tablaOperacionesResta[TIPO_COUNT][TIPO_COUNT] = {
    // char operations
    [CHAR][CHAR] = restaCharChar,
    [CHAR][INT] = restaCharInt,
    [CHAR][FLOAT] = restaCharFloat,
    [CHAR][DOUBLE] = restaCharDouble,

    // int operations
    [INT][CHAR] = restaIntChar,
    [INT][INT] = restaIntInt,
    [INT][FLOAT] = restaIntFloat,
    [INT][DOUBLE] = restaIntDouble,

    // float operations
    [FLOAT][CHAR] = restaFloatChar,
    [FLOAT][INT] = restaFloatInt,
    [FLOAT][FLOAT] = restaFloatFloat,
    [FLOAT][DOUBLE] = restaFloatDouble,

    // double operations
    [DOUBLE][CHAR] = restaDoubleChar,
    [DOUBLE][INT] = restaDoubleInt,
    [DOUBLE][FLOAT] = restaDoubleFloat,
    [DOUBLE][DOUBLE] = restaDoubleDouble,
};

// builders.h
AbstractExpresion *nuevoRestaExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    ExpresionLenguaje *restaExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    restaExpresion->tablaOperaciones = &tablaOperacionesResta;
    return (AbstractExpresion *)restaExpresion;
}
