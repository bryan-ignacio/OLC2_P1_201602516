#ifdef __cplusplus
extern "C"
{
#endif

    AbstractExpresion *nuevoIdentificadorExpresion(char *nombre, int linea, int columna);

#ifdef __cplusplus
}
#endif
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
#endif