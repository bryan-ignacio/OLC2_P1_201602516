#include "context.h"
#include "ast/AbstractExpresion.h"
#include "context/error_report.h"
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
    nuevo->esConstante = 0; // Es variable, no constante
    nuevo->esConstante = 0; // Es variable, no constante
    return nuevo;
}

// Crea una nueva constante con el nombre, valor y tipo especificados.
// Crea una nueva constante con el nombre, valor y tipo especificados.
// Las constantes son inmutables después de su inicialización.
Symbol *nuevoConstante(char *nombre, void *valor, TipoDato tipo)
{
    Symbol *nuevo = malloc(sizeof(Symbol));
    nuevo->nombre = nombre;
    nuevo->valor = valor;
    nuevo->tipo = tipo;
    nuevo->clase = VARIABLE; // Usamos VARIABLE pero marcado como constante
    nuevo->esConstante = 1;  // Es constante - protegida contra reasignación
    return nuevo;
}

// Crea una nueva función con el nombre, tipo de retorno y nodo AST especificados.
Symbol *nuevaFuncion(char *nombre, TipoDato tipo, AbstractExpresion *nodo)
{
    Symbol *nuevo = malloc(sizeof(Symbol));
    nuevo->nombre = nombre;
    nuevo->tipo = tipo;
    nuevo->clase = FUNCION;
    nuevo->esConstante = 0; // Las funciones no son constantes
    nuevo->nodo = nodo;
    return nuevo;
}

// Agrega un símbolo al contexto actual, verificando si ya existe.
void agregarSymbol(Context *actual, Symbol *symbol)
{
    Symbol *existente = buscarSymbol(actual->ultimoSymbol, symbol->nombre);
    if (existente)
    {
// Reportar error de redeclaración con ubicación si es posible
#include "context/error_report.h"
        int linea = 0, columna = 0, ambito = actual ? actual->nombre : 0;
        if (symbol->nodo)
        {
            linea = symbol->nodo->linea;
            columna = symbol->nodo->columna;
        }
        char buffer[256];
        const char *tipoSymbol = symbol->esConstante ? "constante" : "variable";
        const char *tipoExistente = existente->esConstante ? "constante" : "variable";
        snprintf(buffer, sizeof(buffer), "La %s '%s' ya existe como %s.", tipoSymbol, symbol->nombre, tipoExistente);
        agregarErrorSemantico(buffer, linea, columna, ambito);
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