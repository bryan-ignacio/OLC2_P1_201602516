#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "declaracion.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <wchar.h>

Result interpretDeclaracionVariable(AbstractExpresion *nodo, Context *context)
{
    DeclaracionVariable *self = (DeclaracionVariable *)nodo;

    // se esta definiendo con valor inicial
    if (nodo->numHijos > 0)
    {
        Result resultado = nodo->hijos[0]->interpret(nodo->hijos[0], context);
        if (resultado.tipo == self->tipo)
        {
            agregarSymbol(context, nuevoVariable(self->nombre, resultado.valor, self->tipo));
            return nuevoValorResultadoVacio();
        }
        printf("Error tipos incorrectos \n");
        return nuevoValorResultadoVacio();
    }

    // Declaración sin inicialización - asignar valores por defecto
    void *valorPorDefecto = NULL;

    switch (self->tipo)
    {
    case INT:
    {
        int *valorInt = malloc(sizeof(int));
        *valorInt = 0; // Valor por defecto para int es 0
        valorPorDefecto = valorInt;
        break;
    }
    case FLOAT:
    {
        float *valorFloat = malloc(sizeof(float));
        *valorFloat = 0.0f; // Valor por defecto para float es 0.0f
        valorPorDefecto = valorFloat;
        break;
    }
    case STRING:
    {
        // Valor por defecto para string es cadena vacía
        char *valorString = malloc(1);
        valorString[0] = '\0';
        valorPorDefecto = valorString;
        break;
    }
    case BOOLEAN:
    {
        bool *valorBool = malloc(sizeof(bool));
        *valorBool = false; // Valor por defecto para boolean es false
        valorPorDefecto = valorBool;
        break;
    }
    case CHAR:
    {
        wchar_t *valorChar = malloc(sizeof(wchar_t));
        *valorChar = L'\u0000'; // Valor por defecto para char es \u0000
        valorPorDefecto = valorChar;
        break;
    }
    default:
        // Para tipos no implementados, usar NULL
        valorPorDefecto = NULL;
        break;
    }

    agregarSymbol(context, nuevoVariable(self->nombre, valorPorDefecto, self->tipo));
    return nuevoValorResultadoVacio();
}

AbstractExpresion *nuevoDeclaracionVariables(TipoDato tipo, char *nombre, AbstractExpresion *expresion)
{
    // reservar el espacio en memoria y obtener el puntero a este
    DeclaracionVariable *nodo = malloc(sizeof(DeclaracionVariable));
    if (!nodo)
        return NULL;
    // asignar valores
    buildAbstractExpresion(&nodo->base, interpretDeclaracionVariable);
    nodo->tipo = tipo;
    nodo->nombre = nombre;

    if (expresion)
        agregarHijo((AbstractExpresion *)nodo, expresion);
    return (AbstractExpresion *)nodo;
}
