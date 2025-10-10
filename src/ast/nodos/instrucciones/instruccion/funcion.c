#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "funcion.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Variable global para almacenar la función main
static AbstractExpresion *funcionMainPendiente = NULL;
static Context *contextoMainPendiente = NULL;

// solo se declara y guarda la referencia del subarbol de la funcion para ejectuar en la llamada
Result interpretFuncionExpresion(AbstractExpresion *nodo, Context *context)
{
    FuncionExpresion *self = (FuncionExpresion *)nodo;

    agregarSymbol(context, nuevaFuncion(self->nombre, self->tipo, &self->base, nodo->linea, nodo->columna, context ? context->nombre : 0));

    // Si es la función main, guardarla para ejecutar después
    if (strcmp(self->nombre, "main") == 0)
    {
        funcionMainPendiente = nodo;
        contextoMainPendiente = context;
    }

    return nuevoValorResultadoVacio();
}

// Función para ejecutar la función main pendiente
Result ejecutarFuncionMainPendiente()
{
    if (funcionMainPendiente && contextoMainPendiente)
    {
        // Crear un contexto para la función main
        Context *contextMain = nuevoContext(contextoMainPendiente);
        contextMain->archivo = contextoMainPendiente->archivo;   // Heredar el archivo de salida
        contextMain->nombre = contextoMainPendiente->nombre + 1; // Incrementar el nivel de anidación

        // Ejecutar el bloque de la función main (último hijo)
        if (funcionMainPendiente->numHijos > 0)
        {
            AbstractExpresion *bloque = funcionMainPendiente->hijos[funcionMainPendiente->numHijos - 1];
            Result resultado = bloque->interpret(bloque, contextMain);

            // Limpiar las variables globales
            funcionMainPendiente = NULL;
            contextoMainPendiente = NULL;

            return resultado;
        }
    }
    return nuevoValorResultadoVacio();
}

AbstractExpresion *nuevoFuncionExpresion(TipoDato tipoDato, char *nombre, AbstractExpresion *ListaParametros, AbstractExpresion *bloque)
{
    // reservar el espacio en memoria y obtener el puntero a este
    FuncionExpresion *nodo = malloc(sizeof(FuncionExpresion));
    if (!nodo)
        return NULL;
    // asignar valores
    buildAbstractExpresion(&nodo->base, interpretFuncionExpresion);
    nodo->nombre = nombre;
    nodo->tipo = tipoDato;

    if (ListaParametros)
        agregarHijo((AbstractExpresion *)nodo, ListaParametros);
    agregarHijo((AbstractExpresion *)nodo, bloque);

    return (AbstractExpresion *)nodo;
}

AbstractExpresion *nuevoFuncionMainExpresion(AbstractExpresion *bloque)
{
    // Crear la función main con tipo void y nombre "main"
    FuncionExpresion *nodo = malloc(sizeof(FuncionExpresion));
    if (!nodo)
        return NULL;

    // asignar valores
    buildAbstractExpresion(&nodo->base, interpretFuncionExpresion);
    nodo->nombre = "main";
    nodo->tipo = VOID;

    // Solo agregar el bloque, sin parámetros
    agregarHijo((AbstractExpresion *)nodo, bloque);

    return (AbstractExpresion *)nodo;
}