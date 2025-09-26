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
    STRING,
    NULO,
    TIPO_COUNT
} TipoDato;

extern char *labelTipoDato[];

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