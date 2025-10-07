#ifndef WHILE_H
#define WHILE_H

#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "context/result.h"

#include <stdbool.h>

// Estructura para la expresión while
typedef struct
{
    AbstractExpresion base;
} WhileExpresion;

// Estructura para continue
typedef struct
{
    AbstractExpresion base;
    int linea;
    int columna;
} ContinueExpresion;

// Variables globales para controlar el flujo del bucle
extern bool whileBreak;
extern bool whileContinue;
extern bool switchBreak;

// Variables para rastrear el contexto de control de flujo
extern int activeLoopCount;   // Contador de bucles activos (while, for)
extern int activeSwitchCount; // Contador de switches activos

// Funciones de interpretación
Result interpretWhileExpresion(AbstractExpresion *, Context *);
Result interpretContinueExpresion(AbstractExpresion *, Context *);

// Funciones constructoras
AbstractExpresion *nuevoWhileExpresion(AbstractExpresion *condicion, AbstractExpresion *bloque);
AbstractExpresion *nuevoContinueExpresion(int linea, int columna);

#endif