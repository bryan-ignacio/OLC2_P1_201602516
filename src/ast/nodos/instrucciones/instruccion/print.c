#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "print.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <wchar.h>

Result interpretPrintExpresion(AbstractExpresion *self, Context *context)
{
    // interpretar la lista de expresiones
    // recorremos  cada expresion y lo que nos devuelva imprimimos el valor
    AbstractExpresion *listaExpresiones = self->hijos[0];
    for (size_t i = 0; i < listaExpresiones->numHijos; ++i)
    {
        Result result = listaExpresiones->hijos[i]->interpret(listaExpresiones->hijos[i], context);
        switch (result.tipo)
        {
        case STRING:
            if (result.valor == NULL)
            {
                fprintf(context->global->archivo, "null\n");
            }
            else
            {
                fprintf(context->global->archivo, "%s\n", (char *)result.valor);
            }
            break;
        case INT:
            fprintf(context->global->archivo, "%d\n", *(int *)result.valor);
            break;
        case FLOAT:
            fprintf(context->global->archivo, "%f\n", *(float *)result.valor);
            break;
        case DOUBLE:
            fprintf(context->global->archivo, "%.15g\n", *(double *)result.valor);
            break;
        case BOOLEAN:
            fprintf(context->global->archivo, "%s\n", *(bool *)result.valor ? "true" : "false");
            break;
        case CHAR:
            if (*(wchar_t *)result.valor == L'\0')
            {
                fprintf(context->global->archivo, "\\0\n");
            }
            else
            {
                fprintf(context->global->archivo, "%lc\n", *(wchar_t *)result.valor);
            }
            break;
        case NULO:
            fprintf(context->global->archivo, "NULL\n");
            break;
        default:
            fprintf(context->global->archivo, "Tipo no implementado\n");
        }
    }
    return nuevoValorResultadoVacio();
}

AbstractExpresion *nuevoPrintExpresion(AbstractExpresion *listaExpresiones)
{
    // reservar el espacio en memoria y obtener el puntero a este
    PrintExpresion *nodo = malloc(sizeof(PrintExpresion));
    if (!nodo)
        return NULL;
    // asignar valores
    buildAbstractExpresion(&nodo->base, interpretPrintExpresion);

    if (listaExpresiones)
        agregarHijo((AbstractExpresion *)nodo, listaExpresiones);
    return (AbstractExpresion *)nodo;
}