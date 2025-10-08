#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "context/error_report.h"
#include "stringValueOf.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constructor para String.valueOf()
AbstractExpresion *nuevoStringValueOfExpresion(AbstractExpresion *expresion, int linea, int columna)
{
    StringValueOfExpresion *nuevo = (StringValueOfExpresion *)malloc(sizeof(StringValueOfExpresion));
    if (!nuevo)
        return NULL;

    nuevo->super.interpret = interpretarStringValueOf;
    nuevo->super.linea = linea;
    nuevo->super.columna = columna;
    nuevo->expresion = expresion;

    return (AbstractExpresion *)nuevo;
}

// Función de interpretación
Result interpretarStringValueOf(AbstractExpresion *expresion, Context *contexto)
{
    StringValueOfExpresion *stringValueOf = (StringValueOfExpresion *)expresion;

    // Interpretar la expresión que vamos a convertir
    Result valorAConvertir = stringValueOf->expresion->interpret(stringValueOf->expresion, contexto);

    // Si hay error en la evaluación, propagar el error con resultado vacío
    if (valorAConvertir.tipo == NULO)
    {
        return nuevoValorResultadoVacio();
    }

    // Convertir el valor a string
    char *stringResultado = convertirValorAString(&valorAConvertir);
    if (!stringResultado)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Error al convertir valor a string en String.valueOf()");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        return nuevoValorResultadoVacio();
    }

    // Crear resultado como string
    Result resultado = nuevoValorResultado(stringResultado, STRING);

    return resultado;
}

// Función para convertir cualquier valor a string
char *convertirValorAString(Result *valor)
{
    if (!valor)
        return NULL;

    char *buffer = (char *)malloc(256); // Buffer suficiente para cualquier conversión
    if (!buffer)
        return NULL;

    switch (valor->tipo)
    {
    case INT:
        snprintf(buffer, 256, "%d", *(int *)valor->valor);
        break;

    case FLOAT:
        // Formatear sin decimales innecesarios si es número entero
        {
            float floatVal = *(float *)valor->valor;
            if (floatVal == (int)floatVal)
            {
                snprintf(buffer, 256, "%.0f", floatVal);
            }
            else
            {
                snprintf(buffer, 256, "%g", floatVal);
            }
        }
        break;

    case DOUBLE:
        // Formatear sin decimales innecesarios si es número entero
        {
            double doubleVal = *(double *)valor->valor;
            if (doubleVal == (int)doubleVal)
            {
                snprintf(buffer, 256, "%.0f", doubleVal);
            }
            else
            {
                snprintf(buffer, 256, "%g", doubleVal);
            }
        }
        break;

    case BOOLEAN:
        snprintf(buffer, 256, "%s", *(bool *)valor->valor ? "true" : "false");
        break;

    case CHAR:
        snprintf(buffer, 256, "%c", *(char *)valor->valor);
        break;

    case STRING:
        // Para string, simplemente hacer una copia
        free(buffer);
        return strdup((char *)valor->valor);

    default:
        // Para tipos no soportados, convertir a "null" o el tipo
        snprintf(buffer, 256, "null");
        break;
    }

    return buffer;
}