#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "identificadores.h"
#include "context/error_report.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

Result interpretIdentificadorExpresion(AbstractExpresion *self, Context *context)
{
    IdentificadorExpresion *nodo = (IdentificadorExpresion *)self;
    Symbol *valorEncontrado = buscarTablaSimbolos(context, nodo->nombre);
    if (valorEncontrado)
    {
        // Crear una copia del valor para evitar problemas de referencia
        void *valorCopia = NULL;

        switch (valorEncontrado->tipo)
        {
        case INT:
        {
            int *original = (int *)valorEncontrado->valor;
            int *copia = malloc(sizeof(int));
            *copia = *original;
            valorCopia = copia;
            break;
        }
        case FLOAT:
        {
            float *original = (float *)valorEncontrado->valor;
            float *copia = malloc(sizeof(float));
            *copia = *original;
            valorCopia = copia;
            break;
        }
        case DOUBLE:
        {
            double *original = (double *)valorEncontrado->valor;
            double *copia = malloc(sizeof(double));
            *copia = *original;
            valorCopia = copia;
            break;
        }
        case STRING:
        {
            char *original = (char *)valorEncontrado->valor;
            if (original)
            {
                char *copia = malloc(strlen(original) + 1);
                strcpy(copia, original);
                valorCopia = copia;
            }
            else
            {
                valorCopia = NULL;
            }
            break;
        }
        case BOOLEAN:
        {
            bool *original = (bool *)valorEncontrado->valor;
            bool *copia = malloc(sizeof(bool));
            *copia = *original;
            valorCopia = copia;
            break;
        }
        case CHAR:
        {
            char *original = (char *)valorEncontrado->valor;
            char *copia = malloc(sizeof(char));
            *copia = *original;
            valorCopia = copia;
            break;
        }
        default:
            // Para arrays y otros tipos complejos, retornar la referencia directa
            valorCopia = valorEncontrado->valor;
            break;
        }

        return nuevoValorResultado(valorCopia, valorEncontrado->tipo);
    }
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "El identificador no existe %s", nodo->nombre);
    int ambito = context && context->nombre ? context->nombre : 0;
    agregarErrorSemantico(buffer, self->linea, self->columna, ambito);
    return nuevoValorResultadoVacio();
}

AbstractExpresion *nuevoIdentificadorExpresion(char *nombre, int linea, int columna)
{
    // reservar el espacio en memoria y obtener el puntero a este
    IdentificadorExpresion *nodo = malloc(sizeof(IdentificadorExpresion));
    if (!nodo)
        return NULL;
    // asignar valores
    buildAbstractExpresion(&nodo->base, interpretIdentificadorExpresion);

    nodo->nombre = nombre;
    nodo->base.linea = linea;
    nodo->base.columna = columna;
    return (AbstractExpresion *)nodo;
}