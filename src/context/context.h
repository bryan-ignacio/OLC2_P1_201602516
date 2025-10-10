#ifndef CONTEXT_H
#define CONTEXT_H

#include "definiciones.h"
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

// Estructura para el contexto de ejecución.
struct Context
{
    int nombre;           // id numérico del contexto.
    Context *global;      // referencia al contexto global
    Context *anterior;    // contexto padre (para scoping)
    Symbol *ultimoSymbol; // tabla de simbolos (lista enlazada)
    FILE *archivo;        // archivo donde escribir salida
};

// Estructura para un símbolo en la tabla de símbolos.
struct Symbol
{
    char *nombre;            // Nombre del símbolo
    void *valor;             // Valor actual (para variables)
    TipoDato tipo;           // Tipo de dato
    Clase clase;             // VARIABLE, FUNCION, STRUCT
    int esConstante;         // 1 si es constante, 0 si es variable
    AbstractExpresion *nodo; // Nodo AST (para funciones)
    int linea;               // Línea donde se declaró el símbolo
    int columna;             // Columna donde se declaró el símbolo
    int ambito;              // Ámbito donde se declaró el símbolo
    Symbol *anterior;        // Lista enlazada
};

// Declaraciones de funciones para manejar el contexto y la tabla de símbolos.
Context *nuevoContext(Context *anterior);
Symbol *nuevoVariable(char *nombre, void *valor, TipoDato tipo, int linea, int columna, int ambito);
Symbol *nuevoConstante(char *nombre, void *valor, TipoDato tipo, int linea, int columna, int ambito);
Symbol *nuevaFuncion(char *nombre, TipoDato tipo, AbstractExpresion *nodo, int linea, int columna, int ambito);
void agregarSymbol(Context *actual, Symbol *);
Symbol *buscarSymbol(Symbol *actual, char *nombre);
Symbol *buscarTablaSimbolos(Context *actual, char *nombre);

// Funciones para el reporte de tabla de símbolos
void generarReporteTablaSimbolos(Context *global, const char *nombreArchivo);
void escribirSimbolosContexto(FILE *archivo, Context *contexto, int *contador);
const char *obtenerTipoClase(Clase clase);
const char *obtenerAmbito(int ambito);

// cambiar la lista de symbol con una tabla hash donde la funcion hash esta dada por el nombre del symbol + la linea + columna inicio + columna final + tipo + clase

#endif