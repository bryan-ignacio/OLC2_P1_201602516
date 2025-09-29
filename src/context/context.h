#ifndef CONTEXT_H
#define CONTEXT_H

#include "context/definiciones.h"
#include "result.h"

#include <stdio.h>

//-----Este archivo: contiene las definiciones y funciones para manejar el contexto de ejecución y la tabla de símbolos.

// Clase de símbolo: variable, función, struct
typedef enum
{
    VARIABLE,
    FUNCION,
    STRUCT,
} Clase;

// Estructura para un símbolo en la tabla de símbolos.
struct Symbol
{
    char *nombre;
    void *valor;
    TipoDato tipo;
    Clase clase;
    AbstractExpresion *nodo;
    Symbol *anterior;
};

// Estructura para el contexto de ejecución.
struct Context
{
    int nombre;
    Context *global; // referencia al contexto global
    Context *anterior;
    Symbol *ultimoSymbol; // tabla de simbolos
    FILE *archivo;
};

// Declaraciones de funciones para manejar el contexto y la tabla de símbolos.
Context *nuevoContext(Context *anterior);
Symbol *nuevoVariable(char *nombre, void *valor, TipoDato tipo);
Symbol *nuevaFuncion(char *nombre, TipoDato tipo, AbstractExpresion *nodo);
void agregarSymbol(Context *actual, Symbol *);
Symbol *buscarSymbol(Symbol *actual, char *nombre);
Symbol *buscarTablaSimbolos(Context *actual, char *nombre);

// cambiar la lista de symbol con una tabla hash donde la funcion hash esta dada por el nombre del symbol + la linea + columna inicio + columna final + tipo + clase

#endif