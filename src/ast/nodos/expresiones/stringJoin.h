#ifndef STRING_JOIN_H
#define STRING_JOIN_H

#include "../../../context/definiciones.h"
#include "../../../context/context.h"
#include "../../../context/result.h"
#include "../../AbstractExpresion.h"

// Estructura para String.join()
typedef struct StringJoinExpresion
{
    AbstractExpresion super;
    AbstractExpresion *argumentos; // Lista completa: delimitador + elementos
} StringJoinExpresion;

// Constructor para String.join()
AbstractExpresion *nuevoStringJoinExpresion(AbstractExpresion *argumentos, int linea, int columna);

// Función de interpretación
Result interpretarStringJoin(AbstractExpresion *expresion, Context *contexto);

// Función para unir strings con delimitador
char *unirStringsConDelimitador(char *delimitador, char **elementos, int numElementos);

#endif // STRING_JOIN_H