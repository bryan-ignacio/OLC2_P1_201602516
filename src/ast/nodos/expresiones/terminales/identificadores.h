#ifndef IDENTIFICADORES_H
#define IDENTIFICADORES_H

#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "context/result.h"

typedef struct
{
    AbstractExpresion base;
    char *nombre;
} IdentificadorExpresion;

Result interpretIdentificadorExpresion(AbstractExpresion *, Context *);
AbstractExpresion *nuevoIdentificadorExpresion(char *nombre);
#endif