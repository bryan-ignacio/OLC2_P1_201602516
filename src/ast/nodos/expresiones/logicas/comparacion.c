#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "ast/nodos/expresiones/expresiones.h"
#include "logicas.h"

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// ======================= FUNCIONES DE IGUALDAD =======================

Result igualdadIntInt(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((int *)izquierda.valor) == *((int *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result igualdadFloatFloat(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((float *)izquierda.valor) == *((float *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result igualdadDoubleDouble(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((double *)izquierda.valor) == *((double *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result igualdadCharChar(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((char *)izquierda.valor) == *((char *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result igualdadBooleanBoolean(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((bool *)izquierda.valor) == *((bool *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result igualdadStringString(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    // Manejar casos de strings nulos
    if (izquierda.valor == NULL && derecha.valor == NULL)
    {
        *res = true;
    }
    else if (izquierda.valor == NULL || derecha.valor == NULL)
    {
        *res = false;
    }
    else
    {
        *res = strcmp((char *)izquierda.valor, (char *)derecha.valor) == 0;
    }
    return nuevoValorResultado(res, BOOLEAN);
}

// ======================= FUNCIONES DE DESIGUALDAD =======================

Result desigualdadIntInt(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((int *)izquierda.valor) != *((int *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result desigualdadFloatFloat(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((float *)izquierda.valor) != *((float *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result desigualdadDoubleDouble(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((double *)izquierda.valor) != *((double *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result desigualdadCharChar(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((char *)izquierda.valor) != *((char *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result desigualdadBooleanBoolean(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((bool *)izquierda.valor) != *((bool *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result desigualdadStringString(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    // Manejar casos de strings nulos
    if (izquierda.valor == NULL && derecha.valor == NULL)
    {
        *res = false;
    }
    else if (izquierda.valor == NULL || derecha.valor == NULL)
    {
        *res = true;
    }
    else
    {
        *res = strcmp((char *)izquierda.valor, (char *)derecha.valor) != 0;
    }
    return nuevoValorResultado(res, BOOLEAN);
}

// ======================= TABLAS DE OPERACIONES =======================

Operacion tablaOperacionesIgualdad[TIPO_COUNT][TIPO_COUNT] = {
    [BOOLEAN][BOOLEAN] = igualdadBooleanBoolean,
    [CHAR][CHAR] = igualdadCharChar,
    [INT][INT] = igualdadIntInt,
    [FLOAT][FLOAT] = igualdadFloatFloat,
    [DOUBLE][DOUBLE] = igualdadDoubleDouble,
    [STRING][STRING] = igualdadStringString,
};

Operacion tablaOperacionesDesigualdad[TIPO_COUNT][TIPO_COUNT] = {
    [BOOLEAN][BOOLEAN] = desigualdadBooleanBoolean,
    [CHAR][CHAR] = desigualdadCharChar,
    [INT][INT] = desigualdadIntInt,
    [FLOAT][FLOAT] = desigualdadFloatFloat,
    [DOUBLE][DOUBLE] = desigualdadDoubleDouble,
    [STRING][STRING] = desigualdadStringString,
};

// Mantener compatibilidad con código existente
Operacion tablaOperacionesComparacion[TIPO_COUNT][TIPO_COUNT] = {
    [INT][INT] = igualdadIntInt,
};

// ======================= FUNCIONES CONSTRUCTORAS =======================

AbstractExpresion *nuevoIgualdadExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    ExpresionLenguaje *igualdadExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    igualdadExpresion->tablaOperaciones = &tablaOperacionesIgualdad;
    return (AbstractExpresion *)igualdadExpresion;
}

AbstractExpresion *nuevoDesigualdadExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    ExpresionLenguaje *desigualdadExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    desigualdadExpresion->tablaOperaciones = &tablaOperacionesDesigualdad;
    return (AbstractExpresion *)desigualdadExpresion;
}

// Mantener compatibilidad con código existente
AbstractExpresion *nuevoComparacionExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    return nuevoIgualdadExpresion(izquierda, derecha);
}
