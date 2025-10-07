#ifndef FOR_H
#define FOR_H

#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "context/result.h"

#include <stdbool.h>

// Estructura para la expresión for tradicional
typedef struct
{
    AbstractExpresion base;
    bool esForEach; // false para for tradicional, true para for-each
} ForExpresion;

// Estructura para for-each
typedef struct
{
    AbstractExpresion base;
} ForEachExpresion;

// Funciones de interpretación
Result interpretForExpresion(AbstractExpresion *, Context *);
Result interpretForEachExpresion(AbstractExpresion *, Context *);

// Funciones constructoras
AbstractExpresion *nuevoForExpresion(AbstractExpresion *inicializacion, AbstractExpresion *condicion, AbstractExpresion *incremento, AbstractExpresion *bloque);
AbstractExpresion *nuevoForEachExpresion(TipoDato tipo, char *variable, AbstractExpresion *iterable, AbstractExpresion *bloque);

#endif