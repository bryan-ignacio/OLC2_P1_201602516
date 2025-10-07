#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "for.h"
#include "while.h" // Para acceder a las variables globales de control

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

Result interpretForExpresion(AbstractExpresion *self, Context *context)
{
    // Crear nuevo contexto para el for
    Context *nuevoContexto = nuevoContext(context);

    // Los hijos son: inicializacion, condicion, incremento, bloque
    AbstractExpresion *inicializacion = self->hijos[0];
    AbstractExpresion *condicion = self->hijos[1];
    AbstractExpresion *incremento = self->hijos[2];
    AbstractExpresion *bloque = self->hijos[3];

    // Resetear flags de control
    whileBreak = false;
    whileContinue = false;

    // Incrementar contador de bucles activos
    activeLoopCount++;

    // Ejecutar inicialización (solo una vez)
    if (inicializacion)
    {
        inicializacion->interpret(inicializacion, nuevoContexto);
    }

    // Bucle for principal
    while (true)
    {
        // Evaluar la condición
        if (condicion)
        {
            Result resultCondicion = condicion->interpret(condicion, nuevoContexto);

            // Verificar que la condición sea booleana
            if (resultCondicion.tipo != BOOLEAN)
            {
                printf("Error: La condición del for debe ser booleana, se recibió %s\\n",
                       labelTipoDato[resultCondicion.tipo]);
                break;
            }

            // Si la condición es falsa, salir del bucle
            if (!*((bool *)resultCondicion.valor))
            {
                break;
            }
        }

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
            // Ejecutar incremento incluso con continue
            if (incremento)
            {
                incremento->interpret(incremento, nuevoContexto);
            }
            continue;
        }

        // Ejecutar incremento (solo si no hubo continue)
        // Ejecutar incremento (solo si no hubo continue)
        if (incremento)
        {
            incremento->interpret(incremento, nuevoContexto);
        }
    }

    // Decrementar contador de bucles activos
    activeLoopCount--;

    return nuevoValorResultadoVacio();
}

Result interpretForEachExpresion(AbstractExpresion *self, Context *context)
{
    // Crear nuevo contexto para el for-each
    Context *nuevoContexto = nuevoContext(context);

    // Los hijos son: declaracion_variable, iterable, bloque
    AbstractExpresion *declaracionVar = self->hijos[0];
    AbstractExpresion *iterable = self->hijos[1];
    AbstractExpresion *bloque = self->hijos[2];

    // Resetear flags de control
    whileBreak = false;
    whileContinue = false;

    // TODO: Implementar iteración sobre arrays/listas
    // Por ahora, simplemente mostrar un mensaje indicando que no está implementado
    printf("For-each no está completamente implementado aún\\n");

    // Declarar la variable del for-each en el contexto
    if (declaracionVar)
    {
        declaracionVar->interpret(declaracionVar, nuevoContexto);
    }

    // Evaluar el iterable
    Result resultIterable = iterable->interpret(iterable, context);
    (void)resultIterable; // Evitar warning de variable no usada

    // Por ahora, ejecutar el bloque una vez como placeholder
    if (bloque)
    {
        bloque->interpret(bloque, nuevoContexto);
    }

    return nuevoValorResultadoVacio();
}

AbstractExpresion *nuevoForExpresion(AbstractExpresion *inicializacion, AbstractExpresion *condicion, AbstractExpresion *incremento, AbstractExpresion *bloque)
{
    ForExpresion *nodo = malloc(sizeof(ForExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretForExpresion);
    nodo->esForEach = false;

    // Agregar los hijos en orden: inicializacion, condicion, incremento, bloque
    if (inicializacion)
    {
        agregarHijo((AbstractExpresion *)nodo, inicializacion);
    }
    else
    {
        // Agregar NULL como placeholder para mantener el orden
        agregarHijo((AbstractExpresion *)nodo, NULL);
    }

    if (condicion)
    {
        agregarHijo((AbstractExpresion *)nodo, condicion);
    }
    else
    {
        agregarHijo((AbstractExpresion *)nodo, NULL);
    }

    if (incremento)
    {
        agregarHijo((AbstractExpresion *)nodo, incremento);
    }
    else
    {
        agregarHijo((AbstractExpresion *)nodo, NULL);
    }

    agregarHijo((AbstractExpresion *)nodo, bloque);

    return (AbstractExpresion *)nodo;
}

AbstractExpresion *nuevoForEachExpresion(TipoDato tipo, char *variable, AbstractExpresion *iterable, AbstractExpresion *bloque)
{
    ForEachExpresion *nodo = malloc(sizeof(ForEachExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretForEachExpresion);

    // Crear una declaración de variable para el for-each
    AbstractExpresion *declaracionVar = nuevoDeclaracionVariables(tipo, variable, NULL, 0, 0);

    agregarHijo((AbstractExpresion *)nodo, declaracionVar);
    agregarHijo((AbstractExpresion *)nodo, iterable);
    agregarHijo((AbstractExpresion *)nodo, bloque);

    return (AbstractExpresion *)nodo;
}