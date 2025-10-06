#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "context/error_report.h"
#include "ast/nodos/expresiones/expresiones.h"
#include "logicas.h"

#include <stdlib.h>
#include <stdbool.h>

// ======================= FUNCIONES AND LÓGICO =======================

Result logicAndBooleanBoolean(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((bool *)izquierda.valor) && *((bool *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

// ======================= FUNCIONES OR LÓGICO =======================

Result logicOrBooleanBoolean(Result izquierda, Result derecha)
{
    bool *res = malloc(sizeof(bool));
    *res = *((bool *)izquierda.valor) || *((bool *)derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

// ======================= FUNCIONES NOT LÓGICO =======================

Result logicNotBoolean(Result operando)
{
    bool *res = malloc(sizeof(bool));
    *res = !(*((bool *)operando.valor));
    return nuevoValorResultado(res, BOOLEAN);
}

// ======================= TABLAS DE OPERACIONES =======================

Operacion tablaOperacionesLogicAnd[TIPO_COUNT][TIPO_COUNT] = {
    [BOOLEAN][BOOLEAN] = logicAndBooleanBoolean,
};

Operacion tablaOperacionesLogicOr[TIPO_COUNT][TIPO_COUNT] = {
    [BOOLEAN][BOOLEAN] = logicOrBooleanBoolean,
};

// ======================= FUNCIONES CONSTRUCTORAS =======================

AbstractExpresion *nuevoLogicAndExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    ExpresionLenguaje *logicAndExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    logicAndExpresion->tablaOperaciones = &tablaOperacionesLogicAnd;
    return (AbstractExpresion *)logicAndExpresion;
}

AbstractExpresion *nuevoLogicOrExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    ExpresionLenguaje *logicOrExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    logicOrExpresion->tablaOperaciones = &tablaOperacionesLogicOr;
    return (AbstractExpresion *)logicOrExpresion;
}

// ======================= FUNCIÓN NOT (UNARIA) =======================

Result interpretLogicNotExpresion(AbstractExpresion *nodo, Context *context)
{
    // Evaluar el operando
    Result operando = nodo->hijos[0]->interpret(nodo->hijos[0], context);

    // Verificar que sea de tipo boolean
    if (operando.tipo != BOOLEAN)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Operador lógico ! solo permitido en tipo boolean, recibido: %s", labelTipoDato[operando.tipo]);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    return logicNotBoolean(operando);
}

AbstractExpresion *nuevoLogicNotExpresion(AbstractExpresion *operando)
{
    AbstractExpresion *notExpresion = malloc(sizeof(AbstractExpresion));
    if (!notExpresion)
        return NULL;

    buildAbstractExpresion(notExpresion, interpretLogicNotExpresion);
    if (operando)
        agregarHijo(notExpresion, operando);

    return notExpresion;
}