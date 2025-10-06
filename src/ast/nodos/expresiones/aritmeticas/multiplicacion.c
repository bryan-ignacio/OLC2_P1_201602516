#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "aritmeticas.h"
#include "ast/nodos/expresiones/expresiones.h"
#include "casting.h"

#include <stdlib.h>
#include <stdio.h>

Result multiplicarIntInt(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((int *)izquierda.valor) * *((int *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result multiplicarFloatFloat(Result izquierda, Result derecha)
{
    float *res = malloc(sizeof(float));
    *res = *((float *)izquierda.valor) * *((float *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result multiplicarIntFloat(Result izquierda, Result derecha)
{
    float *res = malloc(sizeof(float));
    *res = *((int *)izquierda.valor) * *((float *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result multiplicarFloatInt(Result izquierda, Result derecha)
{
    float *res = malloc(sizeof(float));
    *res = *((float *)izquierda.valor) * *((int *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

// ========== OPERACIONES CON CHAR ==========
Result multiplicarCharChar(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((char *)izquierda.valor) * *((char *)derecha.valor);
    return nuevoValorResultado(res, INT); // char * char promociona a int
}

Result multiplicarCharInt(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((char *)izquierda.valor) * *((int *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result multiplicarIntChar(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((int *)izquierda.valor) * *((char *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result multiplicarCharFloat(Result izquierda, Result derecha)
{
    float *res = malloc(sizeof(float));
    *res = *((char *)izquierda.valor) * *((float *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result multiplicarFloatChar(Result izquierda, Result derecha)
{
    float *res = malloc(sizeof(float));
    *res = *((float *)izquierda.valor) * *((char *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result multiplicarCharDouble(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((char *)izquierda.valor) * *((double *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Result multiplicarDoubleChar(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((double *)izquierda.valor) * *((char *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

// ========== OPERACIONES CON DOUBLE ==========
Result multiplicarDoubleDouble(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((double *)izquierda.valor) * *((double *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Result multiplicarIntDouble(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((int *)izquierda.valor) * *((double *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Result multiplicarDoubleInt(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((double *)izquierda.valor) * *((int *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Result multiplicarFloatDouble(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((float *)izquierda.valor) * *((double *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Result multiplicarDoubleFloat(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((double *)izquierda.valor) * *((float *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Operacion tablaOperacionesMultiplicacion[TIPO_COUNT][TIPO_COUNT] = {
    // char operations
    [CHAR][CHAR] = multiplicarCharChar,
    [CHAR][INT] = multiplicarCharInt,
    [CHAR][FLOAT] = multiplicarCharFloat,
    [CHAR][DOUBLE] = multiplicarCharDouble,

    // int operations
    [INT][CHAR] = multiplicarIntChar,
    [INT][INT] = multiplicarIntInt,
    [INT][FLOAT] = multiplicarIntFloat,
    [INT][DOUBLE] = multiplicarIntDouble,

    // float operations
    [FLOAT][CHAR] = multiplicarFloatChar,
    [FLOAT][INT] = multiplicarFloatInt,
    [FLOAT][FLOAT] = multiplicarFloatFloat,
    [FLOAT][DOUBLE] = multiplicarFloatDouble,

    // double operations
    [DOUBLE][CHAR] = multiplicarDoubleChar,
    [DOUBLE][INT] = multiplicarDoubleInt,
    [DOUBLE][FLOAT] = multiplicarDoubleFloat,
    [DOUBLE][DOUBLE] = multiplicarDoubleDouble,
};

// builders.h
AbstractExpresion *nuevoMultiplicacionExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    ExpresionLenguaje *multiplicacionExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    multiplicacionExpresion->tablaOperaciones = &tablaOperacionesMultiplicacion;
    return (AbstractExpresion *)multiplicacionExpresion;
}