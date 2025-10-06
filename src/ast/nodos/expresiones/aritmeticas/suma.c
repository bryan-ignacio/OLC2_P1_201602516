#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "aritmeticas.h"
#include "ast/nodos/expresiones/expresiones.h"
#include "casting.h"

#include <stdlib.h>
#include <stdio.h>

Result sumarIntInt(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((int *)izquierda.valor) + *((int *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result sumarFloatFloat(Result izquierda, Result derecha)
{
    float *res = malloc(sizeof(float));
    *res = *((float *)izquierda.valor) + *((float *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result sumarIntFloat(Result izquierda, Result derecha)
{
    float *res = malloc(sizeof(float));
    *res = *((int *)izquierda.valor) + *((float *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result sumarFloatInt(Result izquierda, Result derecha)
{
    float *res = malloc(sizeof(float));
    *res = *((float *)izquierda.valor) + *((int *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

// ========== OPERACIONES CON CHAR ==========
Result sumarCharChar(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((char *)izquierda.valor) + *((char *)derecha.valor);
    return nuevoValorResultado(res, INT); // char + char promociona a int
}

Result sumarCharInt(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((char *)izquierda.valor) + *((int *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result sumarIntChar(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((int *)izquierda.valor) + *((char *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result sumarCharFloat(Result izquierda, Result derecha)
{
    float *res = malloc(sizeof(float));
    *res = *((char *)izquierda.valor) + *((float *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result sumarFloatChar(Result izquierda, Result derecha)
{
    float *res = malloc(sizeof(float));
    *res = *((float *)izquierda.valor) + *((char *)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result sumarCharDouble(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((char *)izquierda.valor) + *((double *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Result sumarDoubleChar(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((double *)izquierda.valor) + *((char *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

// ========== OPERACIONES CON DOUBLE ==========
Result sumarDoubleDouble(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((double *)izquierda.valor) + *((double *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Result sumarIntDouble(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((int *)izquierda.valor) + *((double *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Result sumarDoubleInt(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((double *)izquierda.valor) + *((int *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Result sumarFloatDouble(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((float *)izquierda.valor) + *((double *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Result sumarDoubleFloat(Result izquierda, Result derecha)
{
    double *res = malloc(sizeof(double));
    *res = *((double *)izquierda.valor) + *((float *)derecha.valor);
    return nuevoValorResultado(res, DOUBLE);
}

Operacion tablaOperacionesSuma[TIPO_COUNT][TIPO_COUNT] = {
    // char operations
    [CHAR][CHAR] = sumarCharChar,
    [CHAR][INT] = sumarCharInt,
    [CHAR][FLOAT] = sumarCharFloat,
    [CHAR][DOUBLE] = sumarCharDouble,

    // int operations
    [INT][CHAR] = sumarIntChar,
    [INT][INT] = sumarIntInt,
    [INT][FLOAT] = sumarIntFloat,
    [INT][DOUBLE] = sumarIntDouble,

    // float operations
    [FLOAT][CHAR] = sumarFloatChar,
    [FLOAT][INT] = sumarFloatInt,
    [FLOAT][FLOAT] = sumarFloatFloat,
    [FLOAT][DOUBLE] = sumarFloatDouble,

    // double operations
    [DOUBLE][CHAR] = sumarDoubleChar,
    [DOUBLE][INT] = sumarDoubleInt,
    [DOUBLE][FLOAT] = sumarDoubleFloat,
    [DOUBLE][DOUBLE] = sumarDoubleDouble,
};

// builders.h
AbstractExpresion *nuevoSumaExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    ExpresionLenguaje *sumaExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    sumaExpresion->tablaOperaciones = &tablaOperacionesSuma;
    return (AbstractExpresion *)sumaExpresion;
}
