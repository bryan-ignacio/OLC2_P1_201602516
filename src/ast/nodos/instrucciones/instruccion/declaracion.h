#ifndef DECLARACION_H
#define DECLARACION_H

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

// Enumeración para los tipos de operadores de asignación compuesta
typedef enum
{
    ASIG_SUMA,   // +=
    ASIG_RESTA,  // -=
    ASIG_MULT,   // *=
    ASIG_DIV,    // /=
    ASIG_MOD,    // %=
    ASIG_AND,    // &=
    ASIG_OR,     // |=
    ASIG_XOR,    // ^=
    ASIG_LSHIFT, // <<=
    ASIG_RSHIFT  // >>=
} TipoAsignacionCompuesta;

typedef struct
{
    AbstractExpresion base;
    char *nombre;
    TipoAsignacionCompuesta tipoOperador;
} AsignacionCompuesta;

Result interpretDeclaracionVariable(AbstractExpresion *, Context *);
Result interpretDeclaracionConstante(AbstractExpresion *, Context *);
Result interpretAsignacionVariable(AbstractExpresion *, Context *);
Result interpretAsignacionCompuesta(AbstractExpresion *, Context *);

#endif
