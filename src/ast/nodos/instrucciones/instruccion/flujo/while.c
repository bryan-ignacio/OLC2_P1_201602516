#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "while.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Variables globales para controlar break y continue en bucles
bool whileBreak = false;
bool whileContinue = false;
bool switchBreak = false;

Result interpretWhileExpresion(AbstractExpresion *self, Context *context)
{
    // Crear nuevo contexto para el while
    Context *nuevoContexto = nuevoContext(context);

    // La condición es el primer hijo, el bloque es el segundo
    AbstractExpresion *condicion = self->hijos[0];
    AbstractExpresion *bloque = self->hijos[1];

    // Resetear flags de control
    whileBreak = false;
    whileContinue = false;

    // Bucle while principal
    while (true)
    {
        // Evaluar la condición
        Result resultCondicion = condicion->interpret(condicion, context);

        // Verificar que la condición sea booleana
        if (resultCondicion.tipo != BOOLEAN)
        {
            printf("Error: La condición del while debe ser booleana, se recibió %s\\n",
                   labelTipoDato[resultCondicion.tipo]);
            break;
        }

        // Si la condición es falsa, salir del bucle
        if (!*((bool *)resultCondicion.valor))
        {
            break;
        }

        // Resetear flag de continue para esta iteración
        whileContinue = false;

        // Ejecutar el bloque
        bloque->interpret(bloque, nuevoContexto);

        // Si se ejecutó break, salir del bucle
        if (whileBreak)
        {
            whileBreak = false; // Reset para bucles anidados
            break;
        }

        // Si se ejecutó continue, continuar con la siguiente iteración
        if (whileContinue)
        {
            whileContinue = false; // Reset para bucles anidados
            continue;
        }
    }

    return nuevoValorResultadoVacio();
}

Result interpretContinueExpresion(AbstractExpresion *self, Context *context)
{
    // Establecer flag para continuar con la siguiente iteración
    (void)self;
    (void)context;
    whileContinue = true;
    return nuevoValorResultadoVacio();
}

AbstractExpresion *nuevoWhileExpresion(AbstractExpresion *condicion, AbstractExpresion *bloque)
{
    WhileExpresion *nodo = malloc(sizeof(WhileExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretWhileExpresion);

    agregarHijo((AbstractExpresion *)nodo, condicion);
    agregarHijo((AbstractExpresion *)nodo, bloque);

    return (AbstractExpresion *)nodo;
}

AbstractExpresion *nuevoContinueExpresion()
{
    ContinueExpresion *nodo = malloc(sizeof(ContinueExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretContinueExpresion);

    return (AbstractExpresion *)nodo;
}