#ifndef MATRIX_H
#define MATRIX_H

#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "context/result.h"

#include <stdbool.h>

// Estructura para declaración de matriz con new
typedef struct
{
    AbstractExpresion base;
    TipoDato tipoMatrix;
    TipoDato tipoElemento;
    char *identificador;
    int linea;
    int columna;
} DeclaracionMatrixNewExpresion;

// Estructura para declaración de matriz con inicialización
typedef struct
{
    AbstractExpresion base;
    TipoDato tipoMatrix;
    TipoDato tipoElemento;
    char *identificador;
    int linea;
    int columna;
} DeclaracionMatrixInitExpresion;

// Estructura para acceso a matriz
typedef struct
{
    AbstractExpresion base;
    char *identificador;
    int linea;
    int columna;
} AccesoMatrixExpresion;

// Estructura para asignación a matriz
typedef struct
{
    AbstractExpresion base;
    char *identificador;
    int linea;
    int columna;
} AsignacionMatrixExpresion;

// Estructura para lista de filas
typedef struct
{
    AbstractExpresion base;
} ListaFilasExpresion;

// Funciones de interpretación
Result interpretDeclaracionMatrixNewExpresion(AbstractExpresion *, Context *);
Result interpretDeclaracionMatrixInitExpresion(AbstractExpresion *, Context *);
Result interpretAccesoMatrixExpresion(AbstractExpresion *, Context *);
Result interpretAsignacionMatrixExpresion(AbstractExpresion *, Context *);
Result interpretListaFilasExpresion(AbstractExpresion *, Context *);

// Funciones constructoras
AbstractExpresion *nuevoDeclaracionMatrixNew(TipoDato tipoMatrix, char *identificador, TipoDato tipoElemento, AbstractExpresion *filas, AbstractExpresion *columnas, int linea, int columna);
AbstractExpresion *nuevoDeclaracionMatrixInit(TipoDato tipoMatrix, char *identificador, AbstractExpresion *listaFilas, int linea, int columna);
AbstractExpresion *nuevoAccesoMatrixExpresion(char *identificador, AbstractExpresion *fila, AbstractExpresion *columna, int linea, int columna_pos);
AbstractExpresion *nuevoAsignacionMatrixExpresion(char *identificador, AbstractExpresion *fila, AbstractExpresion *columna, AbstractExpresion *valor, int linea, int columna_pos);
AbstractExpresion *nuevoListaFilas();

// Funciones auxiliares
MatrixStruct *crearMatrix(TipoDato tipoElemento, int filas, int columnas);
void liberarMatrix(MatrixStruct *matrix);

#endif