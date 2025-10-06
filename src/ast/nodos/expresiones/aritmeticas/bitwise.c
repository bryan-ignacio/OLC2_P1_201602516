#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "bitwise.h"
#include "ast/nodos/expresiones/expresiones.h"

#include <stdlib.h>
#include <stdio.h>

// ========== FUNCIONES DE ERROR PARA TIPOS NO SOPORTADOS ==========

Result errorBitwiseIncompatible(Result izquierda, Result derecha)
{
    (void)izquierda;
    (void)derecha; // Suprimir warnings
    printf("Error: Las operaciones bitwise solo están permitidas entre tipos enteros (int, char)\n");
    return nuevoValorResultadoVacio();
}

Result errorBitwiseUnarioIncompatible(Result operando, Result unused)
{
    (void)operando;
    (void)unused; // Suprimir warnings
    printf("Error: Las operaciones bitwise unarias solo están permitidas en tipos enteros (int, char)\n");
    return nuevoValorResultadoVacio();
}

// ========== OPERACIONES BITWISE AND (&) ==========

Result bitwiseAndIntInt(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((int *)izquierda.valor) & *((int *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result bitwiseAndCharChar(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((char *)izquierda.valor) & *((char *)derecha.valor);
    return nuevoValorResultado(res, INT); // char & char promociona a int
}

Result bitwiseAndCharInt(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((char *)izquierda.valor) & *((int *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result bitwiseAndIntChar(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((int *)izquierda.valor) & *((char *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Operacion tablaOperacionesBitwiseAnd[TIPO_COUNT][TIPO_COUNT] = {
    // boolean operations - error
    [BOOLEAN][BOOLEAN] = errorBitwiseIncompatible,
    [BOOLEAN][CHAR] = errorBitwiseIncompatible,
    [BOOLEAN][INT] = errorBitwiseIncompatible,
    [BOOLEAN][FLOAT] = errorBitwiseIncompatible,
    [BOOLEAN][DOUBLE] = errorBitwiseIncompatible,
    [BOOLEAN][STRING] = errorBitwiseIncompatible,

    // char operations
    [CHAR][BOOLEAN] = errorBitwiseIncompatible,
    [CHAR][CHAR] = bitwiseAndCharChar,
    [CHAR][INT] = bitwiseAndCharInt,
    [CHAR][FLOAT] = errorBitwiseIncompatible,
    [CHAR][DOUBLE] = errorBitwiseIncompatible,
    [CHAR][STRING] = errorBitwiseIncompatible,

    // int operations
    [INT][BOOLEAN] = errorBitwiseIncompatible,
    [INT][CHAR] = bitwiseAndIntChar,
    [INT][INT] = bitwiseAndIntInt,
    [INT][FLOAT] = errorBitwiseIncompatible,
    [INT][DOUBLE] = errorBitwiseIncompatible,
    [INT][STRING] = errorBitwiseIncompatible,

    // float operations - error
    [FLOAT][BOOLEAN] = errorBitwiseIncompatible,
    [FLOAT][CHAR] = errorBitwiseIncompatible,
    [FLOAT][INT] = errorBitwiseIncompatible,
    [FLOAT][FLOAT] = errorBitwiseIncompatible,
    [FLOAT][DOUBLE] = errorBitwiseIncompatible,
    [FLOAT][STRING] = errorBitwiseIncompatible,

    // double operations - error
    [DOUBLE][BOOLEAN] = errorBitwiseIncompatible,
    [DOUBLE][CHAR] = errorBitwiseIncompatible,
    [DOUBLE][INT] = errorBitwiseIncompatible,
    [DOUBLE][FLOAT] = errorBitwiseIncompatible,
    [DOUBLE][DOUBLE] = errorBitwiseIncompatible,
    [DOUBLE][STRING] = errorBitwiseIncompatible,

    // string operations - error
    [STRING][BOOLEAN] = errorBitwiseIncompatible,
    [STRING][CHAR] = errorBitwiseIncompatible,
    [STRING][INT] = errorBitwiseIncompatible,
    [STRING][FLOAT] = errorBitwiseIncompatible,
    [STRING][DOUBLE] = errorBitwiseIncompatible,
    [STRING][STRING] = errorBitwiseIncompatible,

    // nulo operations - error
    [NULO][BOOLEAN] = errorBitwiseIncompatible,
    [NULO][CHAR] = errorBitwiseIncompatible,
    [NULO][INT] = errorBitwiseIncompatible,
    [NULO][FLOAT] = errorBitwiseIncompatible,
    [NULO][DOUBLE] = errorBitwiseIncompatible,
    [NULO][STRING] = errorBitwiseIncompatible,
};

// ========== OPERACIONES BITWISE OR (|) ==========

Result bitwiseOrIntInt(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((int *)izquierda.valor) | *((int *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result bitwiseOrCharChar(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((char *)izquierda.valor) | *((char *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result bitwiseOrCharInt(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((char *)izquierda.valor) | *((int *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result bitwiseOrIntChar(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((int *)izquierda.valor) | *((char *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Operacion tablaOperacionesBitwiseOr[TIPO_COUNT][TIPO_COUNT] = {
    // boolean operations - error
    [BOOLEAN][BOOLEAN] = errorBitwiseIncompatible,
    [BOOLEAN][CHAR] = errorBitwiseIncompatible,
    [BOOLEAN][INT] = errorBitwiseIncompatible,
    [BOOLEAN][FLOAT] = errorBitwiseIncompatible,
    [BOOLEAN][DOUBLE] = errorBitwiseIncompatible,
    [BOOLEAN][STRING] = errorBitwiseIncompatible,

    // char operations
    [CHAR][BOOLEAN] = errorBitwiseIncompatible,
    [CHAR][CHAR] = bitwiseOrCharChar,
    [CHAR][INT] = bitwiseOrCharInt,
    [CHAR][FLOAT] = errorBitwiseIncompatible,
    [CHAR][DOUBLE] = errorBitwiseIncompatible,
    [CHAR][STRING] = errorBitwiseIncompatible,

    // int operations
    [INT][BOOLEAN] = errorBitwiseIncompatible,
    [INT][CHAR] = bitwiseOrIntChar,
    [INT][INT] = bitwiseOrIntInt,
    [INT][FLOAT] = errorBitwiseIncompatible,
    [INT][DOUBLE] = errorBitwiseIncompatible,
    [INT][STRING] = errorBitwiseIncompatible,

    // float operations - error
    [FLOAT][BOOLEAN] = errorBitwiseIncompatible,
    [FLOAT][CHAR] = errorBitwiseIncompatible,
    [FLOAT][INT] = errorBitwiseIncompatible,
    [FLOAT][FLOAT] = errorBitwiseIncompatible,
    [FLOAT][DOUBLE] = errorBitwiseIncompatible,
    [FLOAT][STRING] = errorBitwiseIncompatible,

    // double operations - error
    [DOUBLE][BOOLEAN] = errorBitwiseIncompatible,
    [DOUBLE][CHAR] = errorBitwiseIncompatible,
    [DOUBLE][INT] = errorBitwiseIncompatible,
    [DOUBLE][FLOAT] = errorBitwiseIncompatible,
    [DOUBLE][DOUBLE] = errorBitwiseIncompatible,
    [DOUBLE][STRING] = errorBitwiseIncompatible,

    // string operations - error
    [STRING][BOOLEAN] = errorBitwiseIncompatible,
    [STRING][CHAR] = errorBitwiseIncompatible,
    [STRING][INT] = errorBitwiseIncompatible,
    [STRING][FLOAT] = errorBitwiseIncompatible,
    [STRING][DOUBLE] = errorBitwiseIncompatible,
    [STRING][STRING] = errorBitwiseIncompatible,

    // nulo operations - error
    [NULO][BOOLEAN] = errorBitwiseIncompatible,
    [NULO][CHAR] = errorBitwiseIncompatible,
    [NULO][INT] = errorBitwiseIncompatible,
    [NULO][FLOAT] = errorBitwiseIncompatible,
    [NULO][DOUBLE] = errorBitwiseIncompatible,
    [NULO][STRING] = errorBitwiseIncompatible,
};

// ========== OPERACIONES BITWISE XOR (^) ==========

Result bitwiseXorIntInt(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((int *)izquierda.valor) ^ *((int *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result bitwiseXorCharChar(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((char *)izquierda.valor) ^ *((char *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result bitwiseXorCharInt(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((char *)izquierda.valor) ^ *((int *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result bitwiseXorIntChar(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    *res = *((int *)izquierda.valor) ^ *((char *)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Operacion tablaOperacionesBitwiseXor[TIPO_COUNT][TIPO_COUNT] = {
    // boolean operations - error
    [BOOLEAN][BOOLEAN] = errorBitwiseIncompatible,
    [BOOLEAN][CHAR] = errorBitwiseIncompatible,
    [BOOLEAN][INT] = errorBitwiseIncompatible,
    [BOOLEAN][FLOAT] = errorBitwiseIncompatible,
    [BOOLEAN][DOUBLE] = errorBitwiseIncompatible,
    [BOOLEAN][STRING] = errorBitwiseIncompatible,

    // char operations
    [CHAR][BOOLEAN] = errorBitwiseIncompatible,
    [CHAR][CHAR] = bitwiseXorCharChar,
    [CHAR][INT] = bitwiseXorCharInt,
    [CHAR][FLOAT] = errorBitwiseIncompatible,
    [CHAR][DOUBLE] = errorBitwiseIncompatible,
    [CHAR][STRING] = errorBitwiseIncompatible,

    // int operations
    [INT][BOOLEAN] = errorBitwiseIncompatible,
    [INT][CHAR] = bitwiseXorIntChar,
    [INT][INT] = bitwiseXorIntInt,
    [INT][FLOAT] = errorBitwiseIncompatible,
    [INT][DOUBLE] = errorBitwiseIncompatible,
    [INT][STRING] = errorBitwiseIncompatible,

    // float operations - error
    [FLOAT][BOOLEAN] = errorBitwiseIncompatible,
    [FLOAT][CHAR] = errorBitwiseIncompatible,
    [FLOAT][INT] = errorBitwiseIncompatible,
    [FLOAT][FLOAT] = errorBitwiseIncompatible,
    [FLOAT][DOUBLE] = errorBitwiseIncompatible,
    [FLOAT][STRING] = errorBitwiseIncompatible,

    // double operations - error
    [DOUBLE][BOOLEAN] = errorBitwiseIncompatible,
    [DOUBLE][CHAR] = errorBitwiseIncompatible,
    [DOUBLE][INT] = errorBitwiseIncompatible,
    [DOUBLE][FLOAT] = errorBitwiseIncompatible,
    [DOUBLE][DOUBLE] = errorBitwiseIncompatible,
    [DOUBLE][STRING] = errorBitwiseIncompatible,

    // string operations - error
    [STRING][BOOLEAN] = errorBitwiseIncompatible,
    [STRING][CHAR] = errorBitwiseIncompatible,
    [STRING][INT] = errorBitwiseIncompatible,
    [STRING][FLOAT] = errorBitwiseIncompatible,
    [STRING][DOUBLE] = errorBitwiseIncompatible,
    [STRING][STRING] = errorBitwiseIncompatible,

    // nulo operations - error
    [NULO][BOOLEAN] = errorBitwiseIncompatible,
    [NULO][CHAR] = errorBitwiseIncompatible,
    [NULO][INT] = errorBitwiseIncompatible,
    [NULO][FLOAT] = errorBitwiseIncompatible,
    [NULO][DOUBLE] = errorBitwiseIncompatible,
    [NULO][STRING] = errorBitwiseIncompatible,
};

// ========== OPERACIONES BITWISE NOT (~) ==========

Result bitwiseNotInt(Result operando, Result unused)
{
    (void)unused; // Suprimir warning de parámetro no usado
    int *res = malloc(sizeof(int));
    *res = ~(*((int *)operando.valor));
    return nuevoValorResultado(res, INT);
}

Result bitwiseNotChar(Result operando, Result unused)
{
    (void)unused; // Suprimir warning de parámetro no usado
    int *res = malloc(sizeof(int));
    *res = ~(*((char *)operando.valor));
    return nuevoValorResultado(res, INT);
}

Operacion tablaOperacionesBitwiseNot[TIPO_COUNT][TIPO_COUNT] = {
    // Operaciones unarias, se usa [tipo][NULO] como en las otras operaciones unarias
    [BOOLEAN][NULO] = errorBitwiseUnarioIncompatible,
    [CHAR][NULO] = bitwiseNotChar,
    [INT][NULO] = bitwiseNotInt,
    [FLOAT][NULO] = errorBitwiseUnarioIncompatible,
    [DOUBLE][NULO] = errorBitwiseUnarioIncompatible,
    [STRING][NULO] = errorBitwiseUnarioIncompatible,
    [NULO][NULO] = errorBitwiseUnarioIncompatible,
};

// ========== OPERACIONES BITWISE LEFT SHIFT (<<) ==========

Result bitwiseLeftShiftIntInt(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    int valorIzq = *((int *)izquierda.valor);
    int desplazamiento = *((int *)derecha.valor);

    // Validar que el desplazamiento sea válido (no negativo y menor que 32)
    if (desplazamiento < 0 || desplazamiento >= 32)
    {
        printf("Error: Desplazamiento inválido: %d. Debe estar entre 0 y 31\n", desplazamiento);
        *res = 0;
    }
    else
    {
        *res = valorIzq << desplazamiento;
    }
    return nuevoValorResultado(res, INT);
}

Result bitwiseLeftShiftCharChar(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    int valorIzq = *((char *)izquierda.valor);
    int desplazamiento = *((char *)derecha.valor);

    if (desplazamiento < 0 || desplazamiento >= 32)
    {
        printf("Error: Desplazamiento inválido: %d. Debe estar entre 0 y 31\n", desplazamiento);
        *res = 0;
    }
    else
    {
        *res = valorIzq << desplazamiento;
    }
    return nuevoValorResultado(res, INT);
}

Result bitwiseLeftShiftCharInt(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    int valorIzq = *((char *)izquierda.valor);
    int desplazamiento = *((int *)derecha.valor);

    if (desplazamiento < 0 || desplazamiento >= 32)
    {
        printf("Error: Desplazamiento inválido: %d. Debe estar entre 0 y 31\n", desplazamiento);
        *res = 0;
    }
    else
    {
        *res = valorIzq << desplazamiento;
    }
    return nuevoValorResultado(res, INT);
}

Result bitwiseLeftShiftIntChar(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    int valorIzq = *((int *)izquierda.valor);
    int desplazamiento = *((char *)derecha.valor);

    if (desplazamiento < 0 || desplazamiento >= 32)
    {
        printf("Error: Desplazamiento inválido: %d. Debe estar entre 0 y 31\n", desplazamiento);
        *res = 0;
    }
    else
    {
        *res = valorIzq << desplazamiento;
    }
    return nuevoValorResultado(res, INT);
}

Operacion tablaOperacionesBitwiseLeftShift[TIPO_COUNT][TIPO_COUNT] = {
    // boolean operations - error
    [BOOLEAN][BOOLEAN] = errorBitwiseIncompatible,
    [BOOLEAN][CHAR] = errorBitwiseIncompatible,
    [BOOLEAN][INT] = errorBitwiseIncompatible,
    [BOOLEAN][FLOAT] = errorBitwiseIncompatible,
    [BOOLEAN][DOUBLE] = errorBitwiseIncompatible,
    [BOOLEAN][STRING] = errorBitwiseIncompatible,

    // char operations
    [CHAR][BOOLEAN] = errorBitwiseIncompatible,
    [CHAR][CHAR] = bitwiseLeftShiftCharChar,
    [CHAR][INT] = bitwiseLeftShiftCharInt,
    [CHAR][FLOAT] = errorBitwiseIncompatible,
    [CHAR][DOUBLE] = errorBitwiseIncompatible,
    [CHAR][STRING] = errorBitwiseIncompatible,

    // int operations
    [INT][BOOLEAN] = errorBitwiseIncompatible,
    [INT][CHAR] = bitwiseLeftShiftIntChar,
    [INT][INT] = bitwiseLeftShiftIntInt,
    [INT][FLOAT] = errorBitwiseIncompatible,
    [INT][DOUBLE] = errorBitwiseIncompatible,
    [INT][STRING] = errorBitwiseIncompatible,

    // float operations - error
    [FLOAT][BOOLEAN] = errorBitwiseIncompatible,
    [FLOAT][CHAR] = errorBitwiseIncompatible,
    [FLOAT][INT] = errorBitwiseIncompatible,
    [FLOAT][FLOAT] = errorBitwiseIncompatible,
    [FLOAT][DOUBLE] = errorBitwiseIncompatible,
    [FLOAT][STRING] = errorBitwiseIncompatible,

    // double operations - error
    [DOUBLE][BOOLEAN] = errorBitwiseIncompatible,
    [DOUBLE][CHAR] = errorBitwiseIncompatible,
    [DOUBLE][INT] = errorBitwiseIncompatible,
    [DOUBLE][FLOAT] = errorBitwiseIncompatible,
    [DOUBLE][DOUBLE] = errorBitwiseIncompatible,
    [DOUBLE][STRING] = errorBitwiseIncompatible,

    // string operations - error
    [STRING][BOOLEAN] = errorBitwiseIncompatible,
    [STRING][CHAR] = errorBitwiseIncompatible,
    [STRING][INT] = errorBitwiseIncompatible,
    [STRING][FLOAT] = errorBitwiseIncompatible,
    [STRING][DOUBLE] = errorBitwiseIncompatible,
    [STRING][STRING] = errorBitwiseIncompatible,

    // nulo operations - error
    [NULO][BOOLEAN] = errorBitwiseIncompatible,
    [NULO][CHAR] = errorBitwiseIncompatible,
    [NULO][INT] = errorBitwiseIncompatible,
    [NULO][FLOAT] = errorBitwiseIncompatible,
    [NULO][DOUBLE] = errorBitwiseIncompatible,
    [NULO][STRING] = errorBitwiseIncompatible,
};

// ========== OPERACIONES BITWISE RIGHT SHIFT (>>) ==========

Result bitwiseRightShiftIntInt(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    int valorIzq = *((int *)izquierda.valor);
    int desplazamiento = *((int *)derecha.valor);

    // Validar que el desplazamiento sea válido (no negativo y menor que 32)
    if (desplazamiento < 0 || desplazamiento >= 32)
    {
        printf("Error: Desplazamiento inválido: %d. Debe estar entre 0 y 31\n", desplazamiento);
        *res = 0;
    }
    else
    {
        *res = valorIzq >> desplazamiento;
    }
    return nuevoValorResultado(res, INT);
}

Result bitwiseRightShiftCharChar(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    int valorIzq = *((char *)izquierda.valor);
    int desplazamiento = *((char *)derecha.valor);

    if (desplazamiento < 0 || desplazamiento >= 32)
    {
        printf("Error: Desplazamiento inválido: %d. Debe estar entre 0 y 31\n", desplazamiento);
        *res = 0;
    }
    else
    {
        *res = valorIzq >> desplazamiento;
    }
    return nuevoValorResultado(res, INT);
}

Result bitwiseRightShiftCharInt(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    int valorIzq = *((char *)izquierda.valor);
    int desplazamiento = *((int *)derecha.valor);

    if (desplazamiento < 0 || desplazamiento >= 32)
    {
        printf("Error: Desplazamiento inválido: %d. Debe estar entre 0 y 31\n", desplazamiento);
        *res = 0;
    }
    else
    {
        *res = valorIzq >> desplazamiento;
    }
    return nuevoValorResultado(res, INT);
}

Result bitwiseRightShiftIntChar(Result izquierda, Result derecha)
{
    int *res = malloc(sizeof(int));
    int valorIzq = *((int *)izquierda.valor);
    int desplazamiento = *((char *)derecha.valor);

    if (desplazamiento < 0 || desplazamiento >= 32)
    {
        printf("Error: Desplazamiento inválido: %d. Debe estar entre 0 y 31\n", desplazamiento);
        *res = 0;
    }
    else
    {
        *res = valorIzq >> desplazamiento;
    }
    return nuevoValorResultado(res, INT);
}

Operacion tablaOperacionesBitwiseRightShift[TIPO_COUNT][TIPO_COUNT] = {
    // boolean operations - error
    [BOOLEAN][BOOLEAN] = errorBitwiseIncompatible,
    [BOOLEAN][CHAR] = errorBitwiseIncompatible,
    [BOOLEAN][INT] = errorBitwiseIncompatible,
    [BOOLEAN][FLOAT] = errorBitwiseIncompatible,
    [BOOLEAN][DOUBLE] = errorBitwiseIncompatible,
    [BOOLEAN][STRING] = errorBitwiseIncompatible,

    // char operations
    [CHAR][BOOLEAN] = errorBitwiseIncompatible,
    [CHAR][CHAR] = bitwiseRightShiftCharChar,
    [CHAR][INT] = bitwiseRightShiftCharInt,
    [CHAR][FLOAT] = errorBitwiseIncompatible,
    [CHAR][DOUBLE] = errorBitwiseIncompatible,
    [CHAR][STRING] = errorBitwiseIncompatible,

    // int operations
    [INT][BOOLEAN] = errorBitwiseIncompatible,
    [INT][CHAR] = bitwiseRightShiftIntChar,
    [INT][INT] = bitwiseRightShiftIntInt,
    [INT][FLOAT] = errorBitwiseIncompatible,
    [INT][DOUBLE] = errorBitwiseIncompatible,
    [INT][STRING] = errorBitwiseIncompatible,

    // float operations - error
    [FLOAT][BOOLEAN] = errorBitwiseIncompatible,
    [FLOAT][CHAR] = errorBitwiseIncompatible,
    [FLOAT][INT] = errorBitwiseIncompatible,
    [FLOAT][FLOAT] = errorBitwiseIncompatible,
    [FLOAT][DOUBLE] = errorBitwiseIncompatible,
    [FLOAT][STRING] = errorBitwiseIncompatible,

    // double operations - error
    [DOUBLE][BOOLEAN] = errorBitwiseIncompatible,
    [DOUBLE][CHAR] = errorBitwiseIncompatible,
    [DOUBLE][INT] = errorBitwiseIncompatible,
    [DOUBLE][FLOAT] = errorBitwiseIncompatible,
    [DOUBLE][DOUBLE] = errorBitwiseIncompatible,
    [DOUBLE][STRING] = errorBitwiseIncompatible,

    // string operations - error
    [STRING][BOOLEAN] = errorBitwiseIncompatible,
    [STRING][CHAR] = errorBitwiseIncompatible,
    [STRING][INT] = errorBitwiseIncompatible,
    [STRING][FLOAT] = errorBitwiseIncompatible,
    [STRING][DOUBLE] = errorBitwiseIncompatible,
    [STRING][STRING] = errorBitwiseIncompatible,

    // nulo operations - error
    [NULO][BOOLEAN] = errorBitwiseIncompatible,
    [NULO][CHAR] = errorBitwiseIncompatible,
    [NULO][INT] = errorBitwiseIncompatible,
    [NULO][FLOAT] = errorBitwiseIncompatible,
    [NULO][DOUBLE] = errorBitwiseIncompatible,
    [NULO][STRING] = errorBitwiseIncompatible,
};

// ========== BUILDERS ==========

AbstractExpresion *nuevoBitwiseAndExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    ExpresionLenguaje *bitwiseAndExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    bitwiseAndExpresion->tablaOperaciones = &tablaOperacionesBitwiseAnd;
    return (AbstractExpresion *)bitwiseAndExpresion;
}

AbstractExpresion *nuevoBitwiseOrExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    ExpresionLenguaje *bitwiseOrExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    bitwiseOrExpresion->tablaOperaciones = &tablaOperacionesBitwiseOr;
    return (AbstractExpresion *)bitwiseOrExpresion;
}

AbstractExpresion *nuevoBitwiseXorExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    ExpresionLenguaje *bitwiseXorExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    bitwiseXorExpresion->tablaOperaciones = &tablaOperacionesBitwiseXor;
    return (AbstractExpresion *)bitwiseXorExpresion;
}

AbstractExpresion *nuevoBitwiseNotExpresion(AbstractExpresion *operando)
{
    ExpresionLenguaje *bitwiseNotExpresion = nuevoExpresionLenguaje(interpretUnarioLenguaje, operando, NULL);
    bitwiseNotExpresion->tablaOperaciones = &tablaOperacionesBitwiseNot;
    return (AbstractExpresion *)bitwiseNotExpresion;
}

AbstractExpresion *nuevoBitwiseLeftShiftExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    ExpresionLenguaje *bitwiseLeftShiftExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    bitwiseLeftShiftExpresion->tablaOperaciones = &tablaOperacionesBitwiseLeftShift;
    return (AbstractExpresion *)bitwiseLeftShiftExpresion;
}

AbstractExpresion *nuevoBitwiseRightShiftExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha)
{
    ExpresionLenguaje *bitwiseRightShiftExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    bitwiseRightShiftExpresion->tablaOperaciones = &tablaOperacionesBitwiseRightShift;
    return (AbstractExpresion *)bitwiseRightShiftExpresion;
}