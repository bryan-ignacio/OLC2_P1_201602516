#ifndef CASTING_H
#define CASTING_H

#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "context/result.h"

typedef struct
{
    AbstractExpresion base;
    AbstractExpresion *expresion;
    TipoDato tipoDestino;
} CastingExpresion;

Result interpretCastingExpresion(AbstractExpresion *self, Context *context);

#endif