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
    // recorremos cada expresion y lo que nos devuelva imprimimos el valor
    AbstractExpresion *listaExpresiones = self->hijos[0];

    // Si solo hay una expresión, la evaluamos e imprimimos
    if (listaExpresiones->numHijos == 1)
    {
        Result result = listaExpresiones->hijos[0]->interpret(listaExpresiones->hijos[0], context);
        switch (result.tipo)
        {
        case STRING:
            if (result.valor == NULL)
            {
                fprintf(context->global->archivo, "null");
            }
            else
            {
                fprintf(context->global->archivo, "%s", (char *)result.valor);
            }
            break;
        case INT:
            fprintf(context->global->archivo, "%d", *(int *)result.valor);
            break;
        case FLOAT:
            fprintf(context->global->archivo, "%g", *(float *)result.valor);
            break;
        case DOUBLE:
            fprintf(context->global->archivo, "%.15g", *(double *)result.valor);
            break;
        case BOOLEAN:
            fprintf(context->global->archivo, "%s", *(bool *)result.valor ? "true" : "false");
            break;
        case CHAR:
            if (*(wchar_t *)result.valor == L'\0')
            {
                fprintf(context->global->archivo, "\\0");
            }
            else
            {
                fprintf(context->global->archivo, "%lc", *(wchar_t *)result.valor);
            }
            break;
        case NULO:
            fprintf(context->global->archivo, "null");
            break;
        case VOID:
            // No imprimir nada para void
            break;
        case ARRAY:
        {
            ArrayStruct *array = (ArrayStruct *)result.valor;
            if (array)
            {
                fprintf(context->global->archivo, "[");
                for (int i = 0; i < array->tamaño; i++)
                {
                    if (i > 0)
                        fprintf(context->global->archivo, ", ");

                    if (array->elementos[i])
                    {
                        switch (array->tipoElemento)
                        {
                        case INT:
                            fprintf(context->global->archivo, "%d", *(int *)array->elementos[i]);
                            break;
                        case FLOAT:
                            fprintf(context->global->archivo, "%g", *(float *)array->elementos[i]);
                            break;
                        case DOUBLE:
                            fprintf(context->global->archivo, "%.15g", *(double *)array->elementos[i]);
                            break;
                        case BOOLEAN:
                            fprintf(context->global->archivo, "%s", *(bool *)array->elementos[i] ? "true" : "false");
                            break;
                        case CHAR:
                            fprintf(context->global->archivo, "%c", *(char *)array->elementos[i]);
                            break;
                        case STRING:
                            fprintf(context->global->archivo, "%s", (char *)array->elementos[i]);
                            break;
                        default:
                            fprintf(context->global->archivo, "?");
                        }
                    }
                    else
                    {
                        fprintf(context->global->archivo, "null");
                    }
                }
                fprintf(context->global->archivo, "]");
            }
            else
            {
                fprintf(context->global->archivo, "null");
            }
            break;
        }
        default:
            fprintf(context->global->archivo, "undefined");
        }
    }
    else
    {
        // Si hay múltiples expresiones, las concatenamos como strings
        for (size_t i = 0; i < listaExpresiones->numHijos; ++i)
        {
            Result result = listaExpresiones->hijos[i]->interpret(listaExpresiones->hijos[i], context);
            switch (result.tipo)
            {
            case STRING:
                if (result.valor == NULL)
                {
                    fprintf(context->global->archivo, "null");
                }
                else
                {
                    fprintf(context->global->archivo, "%s", (char *)result.valor);
                }
                break;
            case INT:
                fprintf(context->global->archivo, "%d", *(int *)result.valor);
                break;
            case FLOAT:
                fprintf(context->global->archivo, "%g", *(float *)result.valor);
                break;
            case DOUBLE:
                fprintf(context->global->archivo, "%.15g", *(double *)result.valor);
                break;
            case BOOLEAN:
                fprintf(context->global->archivo, "%s", *(bool *)result.valor ? "true" : "false");
                break;
            case CHAR:
                if (*(wchar_t *)result.valor == L'\0')
                {
                    fprintf(context->global->archivo, "\\0");
                }
                else
                {
                    fprintf(context->global->archivo, "%lc", *(wchar_t *)result.valor);
                }
                break;
            case NULO:
                fprintf(context->global->archivo, "null");
                break;
            case VOID:
                // No imprimir nada para void
                break;
            case ARRAY:
            {
                ArrayStruct *array = (ArrayStruct *)result.valor;
                if (array)
                {
                    fprintf(context->global->archivo, "[");
                    for (int i = 0; i < array->tamaño; i++)
                    {
                        if (i > 0)
                            fprintf(context->global->archivo, ", ");

                        if (array->elementos[i])
                        {
                            switch (array->tipoElemento)
                            {
                            case INT:
                                fprintf(context->global->archivo, "%d", *(int *)array->elementos[i]);
                                break;
                            case FLOAT:
                                fprintf(context->global->archivo, "%g", *(float *)array->elementos[i]);
                                break;
                            case DOUBLE:
                                fprintf(context->global->archivo, "%.15g", *(double *)array->elementos[i]);
                                break;
                            case BOOLEAN:
                                fprintf(context->global->archivo, "%s", *(bool *)array->elementos[i] ? "true" : "false");
                                break;
                            case CHAR:
                                fprintf(context->global->archivo, "%c", *(char *)array->elementos[i]);
                                break;
                            case STRING:
                                fprintf(context->global->archivo, "%s", (char *)array->elementos[i]);
                                break;
                            default:
                                fprintf(context->global->archivo, "?");
                            }
                        }
                        else
                        {
                            fprintf(context->global->archivo, "null");
                        }
                    }
                    fprintf(context->global->archivo, "]");
                }
                else
                {
                    fprintf(context->global->archivo, "null");
                }
                break;
            }
            default:
                fprintf(context->global->archivo, "undefined");
            }
        }
    }

    // Agregar salto de línea al final
    fprintf(context->global->archivo, "\n");
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