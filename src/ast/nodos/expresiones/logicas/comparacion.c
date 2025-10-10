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

// ======================= FUNCIONES PARA COMPARACIONES CON NULL =======================

Result igualdadConNull(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    // Si ambos son null o alguno es null con valor NULL
    if ((izquierda.tipo == NULO && derecha.tipo == NULO) ||
        (izquierda.tipo == NULO && derecha.valor == NULL) ||
        (derecha.tipo == NULO && izquierda.valor == NULL))
    {
        *res = true;
    }
    else if (izquierda.tipo == NULO || derecha.tipo == NULO)
    {
        // Uno es null, el otro no
        *res = false;
    }
    else
    {
        // Ninguno es null, usar comparación normal
        *res = false;
    }
    return nuevoValorResultado(res, BOOLEAN);
}

Result desigualdadConNull(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    // Si ambos son null o alguno es null con valor NULL
    if ((izquierda.tipo == NULO && derecha.tipo == NULO) ||
        (izquierda.tipo == NULO && derecha.valor == NULL) ||
        (derecha.tipo == NULO && izquierda.valor == NULL))
    {
        *res = false;
    }
    else if (izquierda.tipo == NULO || derecha.tipo == NULO)
    {
        // Uno es null, el otro no
        *res = true;
    }
    else
    {
        // Ninguno es null, usar comparación normal
        *res = true;
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

// ======================= FUNCIONES MAYOR QUE =======================

Result mayorQueIntInt(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((int *)izquierda.valor) > *((int *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result mayorQueFloatFloat(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((float *)izquierda.valor) > *((float *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result mayorQueDoubleDouble(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((double *)izquierda.valor) > *((double *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result mayorQueCharChar(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((char *)izquierda.valor) > *((char *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

// ======================= FUNCIONES MENOR QUE =======================

Result menorQueIntInt(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((int *)izquierda.valor) < *((int *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result menorQueFloatFloat(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((float *)izquierda.valor) < *((float *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result menorQueDoubleDouble(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((double *)izquierda.valor) < *((double *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result menorQueCharChar(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((char *)izquierda.valor) < *((char *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

// ======================= FUNCIONES MAYOR O IGUAL =======================

Result mayorIgualIntInt(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((int *)izquierda.valor) >= *((int *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result mayorIgualFloatFloat(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((float *)izquierda.valor) >= *((float *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result mayorIgualDoubleDouble(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((double *)izquierda.valor) >= *((double *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result mayorIgualCharChar(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((char *)izquierda.valor) >= *((char *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

// Funciones adicionales para conversiones automáticas en comparaciones mayor igual
Result mayorIgualIntChar(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((int *)izquierda.valor) >= (int)*((char *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result mayorIgualCharInt(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = (int)*((char *)izquierda.valor) >= *((int *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result mayorIgualIntFloat(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = (float)*((int *)izquierda.valor) >= *((float *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result mayorIgualFloatInt(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((float *)izquierda.valor) >= (float)*((int *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

// ======================= FUNCIONES MENOR O IGUAL =======================

Result menorIgualIntInt(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((int *)izquierda.valor) <= *((int *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result menorIgualFloatFloat(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((float *)izquierda.valor) <= *((float *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result menorIgualDoubleDouble(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((double *)izquierda.valor) <= *((double *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result menorIgualCharChar(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((char *)izquierda.valor) <= *((char *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

// Funciones adicionales para conversiones automáticas en comparaciones menor igual
Result menorIgualIntChar(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((int *)izquierda.valor) <= (int)*((char *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result menorIgualCharInt(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = (int)*((char *)izquierda.valor) <= *((int *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result menorIgualIntFloat(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = (float)*((int *)izquierda.valor) <= *((float *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Result menorIgualFloatInt(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((float *)izquierda.valor) <= (float)*((int *)derecha.valor);
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
    // Comparaciones con NULL
    [NULO][NULO] = igualdadConNull,
    [NULO][BOOLEAN] = igualdadConNull,
    [NULO][CHAR] = igualdadConNull,
    [NULO][INT] = igualdadConNull,
    [NULO][FLOAT] = igualdadConNull,
    [NULO][DOUBLE] = igualdadConNull,
    [NULO][STRING] = igualdadConNull,
    [BOOLEAN][NULO] = igualdadConNull,
    [CHAR][NULO] = igualdadConNull,
    [INT][NULO] = igualdadConNull,
    [FLOAT][NULO] = igualdadConNull,
    [DOUBLE][NULO] = igualdadConNull,
    [STRING][NULO] = igualdadConNull,
};

Operacion tablaOperacionesDesigualdad[TIPO_COUNT][TIPO_COUNT] = {
    [BOOLEAN][BOOLEAN] = desigualdadBooleanBoolean,
    [CHAR][CHAR] = desigualdadCharChar,
    [INT][INT] = desigualdadIntInt,
    [FLOAT][FLOAT] = desigualdadFloatFloat,
    [DOUBLE][DOUBLE] = desigualdadDoubleDouble,
    [STRING][STRING] = desigualdadStringString,
    // Comparaciones con NULL
    [NULO][NULO] = desigualdadConNull,
    [NULO][BOOLEAN] = desigualdadConNull,
    [NULO][CHAR] = desigualdadConNull,
    [NULO][INT] = desigualdadConNull,
    [NULO][FLOAT] = desigualdadConNull,
    [NULO][DOUBLE] = desigualdadConNull,
    [NULO][STRING] = desigualdadConNull,
    [BOOLEAN][NULO] = desigualdadConNull,
    [CHAR][NULO] = desigualdadConNull,
    [INT][NULO] = desigualdadConNull,
    [FLOAT][NULO] = desigualdadConNull,
    [DOUBLE][NULO] = desigualdadConNull,
    [STRING][NULO] = desigualdadConNull,
};

Operacion tablaOperacionesMayorQue[TIPO_COUNT][TIPO_COUNT] = {
    [CHAR][CHAR] = mayorQueCharChar,
    [INT][INT] = mayorQueIntInt,
    [FLOAT][FLOAT] = mayorQueFloatFloat,
    [DOUBLE][DOUBLE] = mayorQueDoubleDouble,
};

Operacion tablaOperacionesMenorQue[TIPO_COUNT][TIPO_COUNT] = {
    [CHAR][CHAR] = menorQueCharChar,
    [INT][INT] = menorQueIntInt,
    [FLOAT][FLOAT] = menorQueFloatFloat,
    [DOUBLE][DOUBLE] = menorQueDoubleDouble,
};

Operacion tablaOperacionesMayorIgual[TIPO_COUNT][TIPO_COUNT] = {
    [CHAR][CHAR] = mayorIgualCharChar,
    [CHAR][INT] = mayorIgualCharInt,
    [INT][CHAR] = mayorIgualIntChar,
    [INT][INT] = mayorIgualIntInt,
    [INT][FLOAT] = mayorIgualIntFloat,
    [FLOAT][INT] = mayorIgualFloatInt,
    [FLOAT][FLOAT] = mayorIgualFloatFloat,
    [DOUBLE][DOUBLE] = mayorIgualDoubleDouble,
};

Operacion tablaOperacionesMenorIgual[TIPO_COUNT][TIPO_COUNT] = {
    [CHAR][CHAR] = menorIgualCharChar,
    [CHAR][INT] = menorIgualCharInt,
    [INT][CHAR] = menorIgualIntChar,
    [INT][INT] = menorIgualIntInt,
    [INT][FLOAT] = menorIgualIntFloat,
    [FLOAT][INT] = menorIgualFloatInt,
    [FLOAT][FLOAT] = menorIgualFloatFloat,
    [DOUBLE][DOUBLE] = menorIgualDoubleDouble,
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

AbstractExpresion *nuevoMayorQueExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    ExpresionLenguaje *mayorQueExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    mayorQueExpresion->tablaOperaciones = &tablaOperacionesMayorQue;
    return (AbstractExpresion *)mayorQueExpresion;
}

AbstractExpresion *nuevoMenorQueExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    ExpresionLenguaje *menorQueExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    menorQueExpresion->tablaOperaciones = &tablaOperacionesMenorQue;
    return (AbstractExpresion *)menorQueExpresion;
}

AbstractExpresion *nuevoMayorIgualExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    ExpresionLenguaje *mayorIgualExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    mayorIgualExpresion->tablaOperaciones = &tablaOperacionesMayorIgual;
    return (AbstractExpresion *)mayorIgualExpresion;
}

AbstractExpresion *nuevoMenorIgualExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    ExpresionLenguaje *menorIgualExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    menorIgualExpresion->tablaOperaciones = &tablaOperacionesMenorIgual;
    return (AbstractExpresion *)menorIgualExpresion;
}

// Mantener compatibilidad con código existente
AbstractExpresion *nuevoComparacionExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    return nuevoIgualdadExpresion(izquierda, derecha);
}
