#ifndef ARRAY_H
#define ARRAY_H

#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "context/result.h"

#include <stdbool.h>

// Estructura para declaración de array con new
typedef struct
{
    AbstractExpresion base;
    TipoDato tipoArray;
    TipoDato tipoElemento;
    char *identificador;
    int linea;
    int columna;
} DeclaracionArrayNewExpresion;

// Estructura para declaración de array con inicialización
typedef struct
{
    AbstractExpresion base;
    TipoDato tipoArray;
    TipoDato tipoElemento;
    char *identificador;
    int linea;
    int columna;
} DeclaracionArrayInitExpresion;

// Estructura para acceso a array
typedef struct
{
    AbstractExpresion base;
    char *identificador;
    int linea;
    int columna;
} AccesoArrayExpresion;

// Estructura para lista de elementos
typedef struct
{
    AbstractExpresion base;
} ListaElementosExpresion;

// Estructura para asignación a array
typedef struct
{
    AbstractExpresion base;
    char *identificador;
    int linea;
    int columna;
} AsignacionArrayExpresion;

// Funciones de interpretación
Result interpretDeclaracionArrayNewExpresion(AbstractExpresion *, Context *);
Result interpretDeclaracionArrayInitExpresion(AbstractExpresion *, Context *);
Result interpretAccesoArrayExpresion(AbstractExpresion *, Context *);
Result interpretListaElementosExpresion(AbstractExpresion *, Context *);
Result interpretAsignacionArrayExpresion(AbstractExpresion *, Context *);

// Funciones constructoras
AbstractExpresion *nuevoDeclaracionArrayNew(TipoDato tipoArray, char *identificador, TipoDato tipoElemento, AbstractExpresion *tamaño, int linea, int columna);
AbstractExpresion *nuevoDeclaracionArrayInit(TipoDato tipoArray, char *identificador, AbstractExpresion *listaElementos, int linea, int columna);
AbstractExpresion *nuevoAccesoArrayExpresion(char *identificador, AbstractExpresion *indice, int linea, int columna);
AbstractExpresion *nuevoAsignacionArrayExpresion(char *identificador, AbstractExpresion *indice, AbstractExpresion *valor, int linea, int columna);
AbstractExpresion *nuevoListaElementos();

// Funciones auxiliares
void *obtenerValorDefecto(TipoDato tipo);
ArrayStruct *crearArray(TipoDato tipoElemento, int tamaño);
void liberarArray(ArrayStruct *array);

#endif