#ifndef RESULT_H
#define RESULT_H

#include <stdbool.h>
// El orden es la jerarquia del resultado en la operación
typedef enum
{
    BOOLEAN,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    STRING,
    ARRAY, // Nuevo tipo para arrays
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