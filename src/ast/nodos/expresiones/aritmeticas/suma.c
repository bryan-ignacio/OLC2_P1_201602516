#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "aritmeticas.h"
#include "ast/nodos/expresiones/expresiones.h"
#include "casting.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <wchar.h>

// Función auxiliar para convertir un valor a string
char *convertirAString(Result valor)
{
    char *resultado;

    switch (valor.tipo)
    {
    case STRING:
        if (valor.valor == NULL)
        {
            resultado = malloc(5);
            strcpy(resultado, "null");
        }
        else
        {
            resultado = malloc(strlen((char *)valor.valor) + 1);
            strcpy(resultado, (char *)valor.valor);
        }
        break;

    case INT:
        resultado = malloc(20); // Suficiente para un int
        snprintf(resultado, 20, "%d", *(int *)valor.valor);
        break;

    case FLOAT:
        resultado = malloc(30); // Suficiente para un float
        snprintf(resultado, 30, "%g", *(float *)valor.valor);
        break;

    case DOUBLE:
        resultado = malloc(40); // Suficiente para un double
        snprintf(resultado, 40, "%.15g", *(double *)valor.valor);
        break;

    case BOOLEAN:
        resultado = malloc(6);
        strcpy(resultado, *(bool *)valor.valor ? "true" : "false");
        break;

    case CHAR:
        resultado = malloc(10);
        if (*(wchar_t *)valor.valor == L'\0')
        {
            strcpy(resultado, "\\0");
        }
        else
        {
            snprintf(resultado, 10, "%lc", *(wchar_t *)valor.valor);
        }
        break;

    case NULO:
        resultado = malloc(5);
        strcpy(resultado, "null");
        break;

    default:
        resultado = malloc(20);
        strcpy(resultado, "undefined");
        break;
    }

    return resultado;
}

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

// ========== OPERACIONES DE CONCATENACIÓN DE STRINGS ==========
Result concatenarStringString(Result izquierda, Result derecha)
{
    char *str1 = convertirAString(izquierda);
    char *str2 = convertirAString(derecha);

    char *resultado = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(resultado, str1);
    strcat(resultado, str2);

    free(str1);
    free(str2);

    return nuevoValorResultado(resultado, STRING);
}

Result concatenarStringInt(Result izquierda, Result derecha)
{
    char *str1 = convertirAString(izquierda);
    char *str2 = convertirAString(derecha);

    char *resultado = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(resultado, str1);
    strcat(resultado, str2);

    free(str1);
    free(str2);

    return nuevoValorResultado(resultado, STRING);
}

Result concatenarIntString(Result izquierda, Result derecha)
{
    char *str1 = convertirAString(izquierda);
    char *str2 = convertirAString(derecha);

    char *resultado = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(resultado, str1);
    strcat(resultado, str2);

    free(str1);
    free(str2);

    return nuevoValorResultado(resultado, STRING);
}

Result concatenarStringFloat(Result izquierda, Result derecha)
{
    char *str1 = convertirAString(izquierda);
    char *str2 = convertirAString(derecha);

    char *resultado = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(resultado, str1);
    strcat(resultado, str2);

    free(str1);
    free(str2);

    return nuevoValorResultado(resultado, STRING);
}

Result concatenarFloatString(Result izquierda, Result derecha)
{
    char *str1 = convertirAString(izquierda);
    char *str2 = convertirAString(derecha);

    char *resultado = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(resultado, str1);
    strcat(resultado, str2);

    free(str1);
    free(str2);

    return nuevoValorResultado(resultado, STRING);
}

Result concatenarStringDouble(Result izquierda, Result derecha)
{
    char *str1 = convertirAString(izquierda);
    char *str2 = convertirAString(derecha);

    char *resultado = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(resultado, str1);
    strcat(resultado, str2);

    free(str1);
    free(str2);

    return nuevoValorResultado(resultado, STRING);
}

Result concatenarDoubleString(Result izquierda, Result derecha)
{
    char *str1 = convertirAString(izquierda);
    char *str2 = convertirAString(derecha);

    char *resultado = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(resultado, str1);
    strcat(resultado, str2);

    free(str1);
    free(str2);

    return nuevoValorResultado(resultado, STRING);
}

Result concatenarStringBoolean(Result izquierda, Result derecha)
{
    char *str1 = convertirAString(izquierda);
    char *str2 = convertirAString(derecha);

    char *resultado = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(resultado, str1);
    strcat(resultado, str2);

    free(str1);
    free(str2);

    return nuevoValorResultado(resultado, STRING);
}

Result concatenarBooleanString(Result izquierda, Result derecha)
{
    char *str1 = convertirAString(izquierda);
    char *str2 = convertirAString(derecha);

    char *resultado = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(resultado, str1);
    strcat(resultado, str2);

    free(str1);
    free(str2);

    return nuevoValorResultado(resultado, STRING);
}

Result concatenarStringChar(Result izquierda, Result derecha)
{
    char *str1 = convertirAString(izquierda);
    char *str2 = convertirAString(derecha);

    char *resultado = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(resultado, str1);
    strcat(resultado, str2);

    free(str1);
    free(str2);

    return nuevoValorResultado(resultado, STRING);
}

Result concatenarCharString(Result izquierda, Result derecha)
{
    char *str1 = convertirAString(izquierda);
    char *str2 = convertirAString(derecha);

    char *resultado = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(resultado, str1);
    strcat(resultado, str2);

    free(str1);
    free(str2);

    return nuevoValorResultado(resultado, STRING);
}

Operacion tablaOperacionesSuma[TIPO_COUNT][TIPO_COUNT] = {
    // char operations
    [CHAR][CHAR] = sumarCharChar,
    [CHAR][INT] = sumarCharInt,
    [CHAR][FLOAT] = sumarCharFloat,
    [CHAR][DOUBLE] = sumarCharDouble,
    [CHAR][STRING] = concatenarCharString,

    // int operations
    [INT][CHAR] = sumarIntChar,
    [INT][INT] = sumarIntInt,
    [INT][FLOAT] = sumarIntFloat,
    [INT][DOUBLE] = sumarIntDouble,
    [INT][STRING] = concatenarIntString,

    // float operations
    [FLOAT][CHAR] = sumarFloatChar,
    [FLOAT][INT] = sumarFloatInt,
    [FLOAT][FLOAT] = sumarFloatFloat,
    [FLOAT][DOUBLE] = sumarFloatDouble,
    [FLOAT][STRING] = concatenarFloatString,

    // double operations
    [DOUBLE][CHAR] = sumarDoubleChar,
    [DOUBLE][INT] = sumarDoubleInt,
    [DOUBLE][FLOAT] = sumarDoubleFloat,
    [DOUBLE][DOUBLE] = sumarDoubleDouble,
    [DOUBLE][STRING] = concatenarDoubleString,

    // string operations (concatenación)
    [STRING][CHAR] = concatenarStringChar,
    [STRING][INT] = concatenarStringInt,
    [STRING][FLOAT] = concatenarStringFloat,
    [STRING][DOUBLE] = concatenarStringDouble,
    [STRING][BOOLEAN] = concatenarStringBoolean,
    [STRING][STRING] = concatenarStringString,

    // boolean operations
    [BOOLEAN][STRING] = concatenarBooleanString,

    // null operations (concatenación)
    [NULO][STRING] = concatenarStringString, // null + string
    [STRING][NULO] = concatenarStringString, // string + null
};

// builders.h
AbstractExpresion *nuevoSumaExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    ExpresionLenguaje *sumaExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    sumaExpresion->tablaOperaciones = &tablaOperacionesSuma;
    return (AbstractExpresion *)sumaExpresion;
}
