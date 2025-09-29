#include "context.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
------ Este archivo: contiene el contexto de ejecucion de variables y funciones.
*/

// Crea un nuevo contexto, enlazándolo con un contexto anterior si se proporciona.
Context *nuevoContext(Context *anterior)
{
    Context *nuevo = malloc(sizeof(Context));
    nuevo->anterior = anterior;
    if (anterior)
    {
        nuevo->nombre = anterior->nombre + 1;
        nuevo->global = anterior->global;
    }
    else
    {
        nuevo->global = nuevo;
    }
    nuevo->ultimoSymbol = NULL;

    return nuevo;
}

// Crea una nueva variable con el nombre, valor y tipo especificados.
Symbol *nuevoVariable(char *nombre, void *valor, TipoDato tipo)
{
    Symbol *nuevo = malloc(sizeof(Symbol));
    nuevo->nombre = nombre;
    nuevo->valor = valor;
    nuevo->tipo = tipo;
    nuevo->clase = VARIABLE;
    return nuevo;
}

// Crea una nueva función con el nombre, tipo de retorno y nodo AST especificados.
Symbol *nuevaFuncion(char *nombre, TipoDato tipo, AbstractExpresion *nodo)
{
    Symbol *nuevo = malloc(sizeof(Symbol));
    nuevo->nombre = nombre;
    nuevo->tipo = tipo;
    nuevo->clase = FUNCION;
    nuevo->nodo = nodo;
    return nuevo;
}

// Agrega un símbolo al contexto actual, verificando si ya existe.
void agregarSymbol(Context *actual, Symbol *symbol)
{
    if (buscarSymbol(actual->ultimoSymbol, symbol->nombre))
    {
        printf("La variable de nombre '%s' ya existe.\n", symbol->nombre);
        return;
    }
    symbol->anterior = actual->ultimoSymbol;
    actual->ultimoSymbol = symbol;
}

// Busca un símbolo por nombre en la lista de símbolos proporcionada.
Symbol *buscarSymbol(Symbol *actual, char *nombre)
{
    while (actual)
    {
        if (strcmp(actual->nombre, nombre) == 0)
        {
            return actual;
        }
        actual = actual->anterior;
    }
    return NULL;
}

// Busca un símbolo por nombre en el contexto actual y sus contextos anteriores.
Symbol *buscarTablaSimbolos(Context *actual, char *nombre)
{
    while (actual)
    {
        Symbol *symbolEncontrado = buscarSymbol(actual->ultimoSymbol, nombre);
        if (symbolEncontrado)
        {
            return symbolEncontrado;
        }
        actual = actual->anterior;
    }
    return NULL;
}