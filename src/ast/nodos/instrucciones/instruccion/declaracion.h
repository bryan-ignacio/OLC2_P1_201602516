#ifndef PRINT_H
#define PRINT_H

#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "context/result.h"

typedef struct
{
    AbstractExpresion base;
    char *nombre;
    TipoDato tipo;
} DeclaracionVariable;

typedef struct
{
    AbstractExpresion base;
    char *nombre;
    TipoDato tipo;
} DeclaracionConstante;

typedef struct
{
    AbstractExpresion base;
    char *nombre;
} AsignacionVariable;

Result interpretDeclaracionVariable(AbstractExpresion *, Context *);
Result interpretDeclaracionConstante(AbstractExpresion *, Context *);
Result interpretAsignacionVariable(AbstractExpresion *, Context *);

#endif
