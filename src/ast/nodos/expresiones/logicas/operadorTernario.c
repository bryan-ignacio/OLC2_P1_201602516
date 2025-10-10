#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "context/error_report.h"
#include "operadorTernario.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constructor para el operador ternario
AbstractExpresion *nuevoOperadorTernarioExpresion(AbstractExpresion *condicion,
                                                  AbstractExpresion *expresionVerdadera,
                                                  AbstractExpresion *expresionFalsa,
                                                  int linea, int columna)
{
    OperadorTernarioExpresion *nuevo = (OperadorTernarioExpresion *)malloc(sizeof(OperadorTernarioExpresion));
    if (!nuevo)
        return NULL;

    nuevo->super.interpret = interpretarOperadorTernario;
    nuevo->super.linea = linea;
    nuevo->super.columna = columna;
    nuevo->condicion = condicion;
    nuevo->expresionVerdadera = expresionVerdadera;
    nuevo->expresionFalsa = expresionFalsa;

    return (AbstractExpresion *)nuevo;
}

// Función de interpretación
Result interpretarOperadorTernario(AbstractExpresion *expresion, Context *contexto)
{
    OperadorTernarioExpresion *ternario = (OperadorTernarioExpresion *)expresion;

    // Evaluar la condición
    Result resultCondicion = ternario->condicion->interpret(ternario->condicion, contexto);
    if (resultCondicion.tipo == NULO)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Error al evaluar la condición en operador ternario");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        return nuevoValorResultadoVacio();
    }

    // Convertir el resultado a booleano
    bool condicionVerdadera = false;

    switch (resultCondicion.tipo)
    {
    case BOOLEAN:
    {
        bool *valorBool = (bool *)resultCondicion.valor;
        condicionVerdadera = *valorBool;
        break;
    }
    case INT:
    {
        int *valorInt = (int *)resultCondicion.valor;
        condicionVerdadera = (*valorInt != 0);
        break;
    }
    case FLOAT:
    {
        float *valorFloat = (float *)resultCondicion.valor;
        condicionVerdadera = (*valorFloat != 0.0f);
        break;
    }
    case DOUBLE:
    {
        double *valorDouble = (double *)resultCondicion.valor;
        condicionVerdadera = (*valorDouble != 0.0);
        break;
    }
    case STRING:
    {
        char *valorString = (char *)resultCondicion.valor;
        condicionVerdadera = (valorString != NULL && strlen(valorString) > 0);
        break;
    }
    case NULO:
    {
        // null se considera falso
        condicionVerdadera = false;
        break;
    }
    default:
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Tipo no válido para condición en operador ternario");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        return nuevoValorResultadoVacio();
    }
    }

    // Evaluar la expresión correspondiente según la condición
    if (condicionVerdadera)
    {
        // Evaluar expresión verdadera
        Result resultado = ternario->expresionVerdadera->interpret(ternario->expresionVerdadera, contexto);
        return resultado;
    }
    else
    {
        // Evaluar expresión falsa
        Result resultado = ternario->expresionFalsa->interpret(ternario->expresionFalsa, contexto);
        return resultado;
    }
}