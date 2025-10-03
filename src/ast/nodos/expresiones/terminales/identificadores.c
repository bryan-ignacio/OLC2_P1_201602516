#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "identificadores.h"
#include "context/error_report.h"
#include <stdlib.h>
#include <stdio.h>

Result interpretIdentificadorExpresion(AbstractExpresion *self, Context *context)
{
    IdentificadorExpresion *nodo = (IdentificadorExpresion *)self;
    Symbol *valorEncontrado = buscarTablaSimbolos(context, nodo->nombre);
    if (valorEncontrado)
    {
        return nuevoValorResultado(valorEncontrado->valor, valorEncontrado->tipo);
    }
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "El identificador no existe %s", nodo->nombre);
    int ambito = context && context->nombre ? context->nombre : 0;
    agregarError(buffer, self->linea, self->columna, ambito);
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