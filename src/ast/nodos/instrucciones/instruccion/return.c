#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/error_report.h"
#include "context/result.h"
#include "return.h"

#include <stdlib.h>
#include <stdio.h>

Result interpretReturnExpresion(AbstractExpresion *self, Context *context)
{
    // Detectar si estamos dentro de una función (ambito == 0 es global)
    int ambito = context && context->nombre ? context->nombre : 0;
    if (ambito == 0)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Return fuera de función.");
        agregarError(buffer, self->linea, self->columna, ambito);
    }
    if (self->numHijos == 1)
    {
        Result resultadoReturn = self->hijos[0]->interpret(self->hijos[0], context);
        resultadoReturn.isReturn = true;
        return resultadoReturn;
    }
    else
    {
        Result resultadoVacio = nuevoValorResultadoVacio();
        resultadoVacio.isReturn = true;
        return resultadoVacio;
    }
}

AbstractExpresion *nuevoReturnExpresion(AbstractExpresion *expresion)
{
    // reservar el espacio en memoria y obtener el puntero a este
    ReturnExpresion *nodo = malloc(sizeof(ReturnExpresion));
    if (!nodo)
        return NULL;
    // asignar valores
    buildAbstractExpresion(&nodo->base, interpretReturnExpresion);

    if (expresion)
        agregarHijo((AbstractExpresion *)nodo, expresion);

    return (AbstractExpresion *)nodo;
}