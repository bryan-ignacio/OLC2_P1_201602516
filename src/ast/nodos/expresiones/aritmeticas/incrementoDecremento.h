#ifndef INCREMENT_DECREMENT_H
#define INCREMENT_DECREMENT_H

#include "../../../../context/definiciones.h"
#include "../../../../context/context.h"
#include "../../../../context/result.h"
#include "../../../AbstractExpresion.h"

// Tipos de operación de incremento/decremento
typedef enum
{
    OP_PRE_INCREMENT,  // ++variable
    OP_POST_INCREMENT, // variable++
    OP_PRE_DECREMENT,  // --variable
    OP_POST_DECREMENT  // variable--
} TipoIncrementoDecremento;

// Estructura para operadores de incremento y decremento
typedef struct IncrementoDecrementoExpresion
{
    AbstractExpresion super;
    char *identificador;           // Nombre de la variable
    TipoIncrementoDecremento tipo; // Tipo de operación
} IncrementoDecrementoExpresion;

// Constructores
AbstractExpresion *nuevoPreIncrementoExpresion(char *identificador, int linea, int columna);
AbstractExpresion *nuevoPostIncrementoExpresion(char *identificador, int linea, int columna);
AbstractExpresion *nuevoPreDecrementoExpresion(char *identificador, int linea, int columna);
AbstractExpresion *nuevoPostDecrementoExpresion(char *identificador, int linea, int columna);

// Función de interpretación
Result interpretarIncrementoDecremento(AbstractExpresion *expresion, Context *contexto);

#endif // INCREMENT_DECREMENT_H