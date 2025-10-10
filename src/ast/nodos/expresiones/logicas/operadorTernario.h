#ifndef OPERADOR_TERNARIO_H
#define OPERADOR_TERNARIO_H

#include "../../../../context/definiciones.h"
#include "../../../../context/context.h"
#include "../../../../context/result.h"
#include "../../../AbstractExpresion.h"

// Estructura para el operador ternario (condición ? expresiónVerdadera : expresiónFalsa)
typedef struct OperadorTernarioExpresion
{
    AbstractExpresion super;
    AbstractExpresion *condicion;          // Expresión de condición
    AbstractExpresion *expresionVerdadera; // Expresión a evaluar si la condición es verdadera
    AbstractExpresion *expresionFalsa;     // Expresión a evaluar si la condición es falsa
} OperadorTernarioExpresion;

// Constructor para el operador ternario
AbstractExpresion *nuevoOperadorTernarioExpresion(AbstractExpresion *condicion,
                                                  AbstractExpresion *expresionVerdadera,
                                                  AbstractExpresion *expresionFalsa,
                                                  int linea, int columna);

// Función de interpretación
Result interpretarOperadorTernario(AbstractExpresion *expresion, Context *contexto);

#endif // OPERADOR_TERNARIO_H