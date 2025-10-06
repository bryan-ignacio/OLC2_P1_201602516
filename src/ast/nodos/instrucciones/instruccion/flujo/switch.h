#ifndef SWITCH_H
#define SWITCH_H

#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "context/result.h"

#include <stdbool.h>

// Estructura para la expresión switch
typedef struct
{
    AbstractExpresion base;
    bool tieneDefault;
} SwitchExpresion;

// Estructura para un caso individual
typedef struct
{
    AbstractExpresion base;
    bool esDefault;
} CaseExpresion;

// Estructura para break
typedef struct
{
    AbstractExpresion base;
} BreakExpresion;

// Funciones de interpretación
Result interpretSwitchExpresion(AbstractExpresion *, Context *);
Result interpretCaseExpresion(AbstractExpresion *, Context *);
Result interpretBreakExpresion(AbstractExpresion *, Context *);

// Funciones constructoras
AbstractExpresion *nuevoSwitchExpresion(AbstractExpresion *expresion, AbstractExpresion *listaCasos);
AbstractExpresion *nuevoCaseExpresion(AbstractExpresion *valor, AbstractExpresion *bloque);
AbstractExpresion *nuevoDefaultExpresion(AbstractExpresion *bloque);
AbstractExpresion *nuevoBreakExpresion();

#endif