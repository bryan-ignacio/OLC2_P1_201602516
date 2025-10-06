#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "aritmeticas.h"
#include "ast/nodos/expresiones/expresiones.h"
#include "casting.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Función auxiliar para verificar división por cero (reutilizada de división)
int esCeroModulo(Result operando)
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

Result moduloIntInt(Result izquierda, Result derecha)
{
    // Verificar módulo por cero
    if (esCeroModulo(derecha))
    {
        printf("Error: Módulo por cero detectado\n");
        return nuevoValorResultadoVacio();
    }

    // Módulo entero: resultado es int
    int *res = malloc(sizeof(int));
    *res = *((int *)izquierda.valor) % *((int *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result moduloFloatFloat(Result izquierda, Result derecha)
{
    // Verificar módulo por cero
    if (esCeroModulo(derecha))
    {
        printf("Error: Módulo por cero detectado\n");
        return nuevoValorResultadoVacio();
    }

    // Usar fmod para números de punto flotante
    float *res = malloc(sizeof(float));
    *res = fmod(*((float *)izquierda.valor), *((float *)derecha.valor));
    return nuevoValorResultado(res, FLOAT);
}

Result moduloIntFloat(Result izquierda, Result derecha)
{
    // Verificar módulo por cero
    if (esCeroModulo(derecha))
    {
        printf("Error: Módulo por cero detectado\n");
        return nuevoValorResultadoVacio();
    }

    float *res = malloc(sizeof(float));
    *res = fmod((float)*((int *)izquierda.valor), *((float *)derecha.valor));
    return nuevoValorResultado(res, FLOAT);
}

Result moduloFloatInt(Result izquierda, Result derecha)
{
    // Verificar módulo por cero
    if (esCeroModulo(derecha))
    {
        printf("Error: Módulo por cero detectado\n");
        return nuevoValorResultadoVacio();
    }

    float *res = malloc(sizeof(float));
    *res = fmod(*((float *)izquierda.valor), (float)*((int *)derecha.valor));
    return nuevoValorResultado(res, FLOAT);
}

// ========== OPERACIONES CON CHAR ==========
Result moduloCharChar(Result izquierda, Result derecha)
{
    // Verificar módulo por cero
    if (esCeroModulo(derecha))
    {
        printf("Error: Módulo por cero detectado\n");
        return nuevoValorResultadoVacio();
    }

    // char % char promociona a int
    int *res = malloc(sizeof(int));
    *res = *((char *)izquierda.valor) % *((char *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result moduloCharInt(Result izquierda, Result derecha)
{
    // Verificar módulo por cero
    if (esCeroModulo(derecha))
    {
        printf("Error: Módulo por cero detectado\n");
        return nuevoValorResultadoVacio();
    }

    int *res = malloc(sizeof(int));
    *res = *((char *)izquierda.valor) % *((int *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result moduloIntChar(Result izquierda, Result derecha)
{
    // Verificar módulo por cero
    if (esCeroModulo(derecha))
    {
        printf("Error: Módulo por cero detectado\n");
        return nuevoValorResultadoVacio();
    }

    int *res = malloc(sizeof(int));
    *res = *((int *)izquierda.valor) % *((char *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result moduloCharFloat(Result izquierda, Result derecha)
{
    // Verificar módulo por cero
    if (esCeroModulo(derecha))
    {
        printf("Error: Módulo por cero detectado\n");
        return nuevoValorResultadoVacio();
    }

    float *res = malloc(sizeof(float));
    *res = fmod((float)*((char *)izquierda.valor), *((float *)derecha.valor));
    return nuevoValorResultado(res, FLOAT);
}

Result moduloFloatChar(Result izquierda, Result derecha)
{
    // Verificar módulo por cero
    if (esCeroModulo(derecha))
    {
        printf("Error: Módulo por cero detectado\n");
        return nuevoValorResultadoVacio();
    }

    float *res = malloc(sizeof(float));
    *res = fmod(*((float *)izquierda.valor), (float)*((char *)derecha.valor));
    return nuevoValorResultado(res, FLOAT);
}

Result moduloCharDouble(Result izquierda, Result derecha)
{
    // Verificar módulo por cero
    if (esCeroModulo(derecha))
    {
        printf("Error: Módulo por cero detectado\n");
        return nuevoValorResultadoVacio();
    }

    double *res = malloc(sizeof(double));
    *res = fmod((double)*((char *)izquierda.valor), *((double *)derecha.valor));
    return nuevoValorResultado(res, DOUBLE);
}

Result moduloDoubleChar(Result izquierda, Result derecha)
{
    // Verificar módulo por cero
    if (esCeroModulo(derecha))
    {
        printf("Error: Módulo por cero detectado\n");
        return nuevoValorResultadoVacio();
    }

    double *res = malloc(sizeof(double));
    *res = fmod(*((double *)izquierda.valor), (double)*((char *)derecha.valor));
    return nuevoValorResultado(res, DOUBLE);
}

// ========== OPERACIONES CON DOUBLE ==========
Result moduloDoubleDouble(Result izquierda, Result derecha)
{
    // Verificar módulo por cero
    if (esCeroModulo(derecha))
    {
        printf("Error: Módulo por cero detectado\n");
        return nuevoValorResultadoVacio();
    }

    double *res = malloc(sizeof(double));
    *res = fmod(*((double *)izquierda.valor), *((double *)derecha.valor));
    return nuevoValorResultado(res, DOUBLE);
}

Result moduloIntDouble(Result izquierda, Result derecha)
{
    // Verificar módulo por cero
    if (esCeroModulo(derecha))
    {
        printf("Error: Módulo por cero detectado\n");
        return nuevoValorResultadoVacio();
    }

    double *res = malloc(sizeof(double));
    *res = fmod((double)*((int *)izquierda.valor), *((double *)derecha.valor));
    return nuevoValorResultado(res, DOUBLE);
}

Result moduloDoubleInt(Result izquierda, Result derecha)
{
    // Verificar módulo por cero
    if (esCeroModulo(derecha))
    {
        printf("Error: Módulo por cero detectado\n");
        return nuevoValorResultadoVacio();
    }

    double *res = malloc(sizeof(double));
    *res = fmod(*((double *)izquierda.valor), (double)*((int *)derecha.valor));
    return nuevoValorResultado(res, DOUBLE);
}

Result moduloFloatDouble(Result izquierda, Result derecha)
{
    // Verificar módulo por cero
    if (esCeroModulo(derecha))
    {
        printf("Error: Módulo por cero detectado\n");
        return nuevoValorResultadoVacio();
    }

    double *res = malloc(sizeof(double));
    *res = fmod((double)*((float *)izquierda.valor), *((double *)derecha.valor));
    return nuevoValorResultado(res, DOUBLE);
}

Result moduloDoubleFloat(Result izquierda, Result derecha)
{
    // Verificar módulo por cero
    if (esCeroModulo(derecha))
    {
        printf("Error: Módulo por cero detectado\n");
        return nuevoValorResultadoVacio();
    }

    double *res = malloc(sizeof(double));
    *res = fmod(*((double *)izquierda.valor), (double)*((float *)derecha.valor));
    return nuevoValorResultado(res, DOUBLE);
}

Operacion tablaOperacionesModulo[TIPO_COUNT][TIPO_COUNT] = {
    // char operations
    [CHAR][CHAR] = moduloCharChar,
    [CHAR][INT] = moduloCharInt,
    [CHAR][FLOAT] = moduloCharFloat,
    [CHAR][DOUBLE] = moduloCharDouble,

    // int operations
    [INT][CHAR] = moduloIntChar,
    [INT][INT] = moduloIntInt,
    [INT][FLOAT] = moduloIntFloat,
    [INT][DOUBLE] = moduloIntDouble,

    // float operations
    [FLOAT][CHAR] = moduloFloatChar,
    [FLOAT][INT] = moduloFloatInt,
    [FLOAT][FLOAT] = moduloFloatFloat,
    [FLOAT][DOUBLE] = moduloFloatDouble,

    // double operations
    [DOUBLE][CHAR] = moduloDoubleChar,
    [DOUBLE][INT] = moduloDoubleInt,
    [DOUBLE][FLOAT] = moduloDoubleFloat,
    [DOUBLE][DOUBLE] = moduloDoubleDouble,
};

// builders.h
AbstractExpresion *nuevoModuloExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    ExpresionLenguaje *moduloExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    moduloExpresion->tablaOperaciones = &tablaOperacionesModulo;
    return (AbstractExpresion *)moduloExpresion;
}