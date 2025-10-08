#ifndef RESULT_H
#define RESULT_H

#include <stdbool.h>
// El orden es la jerarquia del resultado en la operación
typedef enum
{
    VOID,
    BOOLEAN,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    STRING,
    ARRAY,  // Nuevo tipo para arrays
    MATRIX, // Nuevo tipo para matrices
    NULO,
    TIPO_COUNT
} TipoDato;

extern char *labelTipoDato[];

// Estructura para representar arrays
typedef struct ArrayStruct
{
    TipoDato tipoElemento; // Tipo de los elementos del array
    void **elementos;      // Array de punteros a los elementos
    int tamaño;            // Número de elementos en el array
} ArrayStruct;

// Estructura para representar matrices (arrays bidimensionales)
typedef struct MatrixStruct
{
    TipoDato tipoElemento; // Tipo de los elementos de la matriz
    void ***elementos;     // Matriz de punteros a los elementos [fila][columna]
    int filas;             // Número de filas
    int columnas;          // Número de columnas
} MatrixStruct;

typedef struct Result
{
    TipoDato tipo;
    void *valor;
    bool isReturn;
} Result;

TipoDato tipoResultante(Result, Result);
/*utilizado para devolver un Result*/
Result nuevoValorResultado(void *valor, TipoDato tipo);
/*Utilizado para devolver una repuesta nula */
Result nuevoValorResultadoVacio(void);

#endif