#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "context/error_report.h"
#include "floatParse.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <math.h>

// Función auxiliar para validar si una cadena es numérica flotante
int esNumericoFlotante(const char *str)
{
    if (str == NULL || *str == '\0')
    {
        return 0; // Cadena vacía o nula
    }

    int i = 0;
    int tienePunto = 0;
    int tieneExponente = 0;
    int tieneDigitos = 0;

    // Permitir signo negativo o positivo al inicio
    if (str[i] == '-' || str[i] == '+')
    {
        i++;
        if (str[i] == '\0')
        {
            return 0; // Solo signo sin dígitos
        }
    }

    // Verificar el resto de la cadena
    while (str[i] != '\0')
    {
        char c = str[i];

        if (isdigit(c))
        {
            tieneDigitos = 1;
        }
        else if (c == '.' && !tienePunto && !tieneExponente)
        {
            tienePunto = 1;
        }
        else if ((c == 'e' || c == 'E') && !tieneExponente && tieneDigitos)
        {
            tieneExponente = 1;
            // Permitir signo después de 'e' o 'E'
            if (str[i + 1] == '+' || str[i + 1] == '-')
            {
                i++;
                if (str[i + 1] == '\0')
                {
                    return 0; // 'e+' o 'e-' sin dígitos
                }
            }
        }
        else
        {
            return 0; // Carácter no válido
        }
        i++;
    }

    return tieneDigitos; // Debe tener al menos un dígito
}

// Función auxiliar para validar rango de double
int validarRangoDouble(const char *str)
{
    errno = 0;
    char *endptr;
    double valor = strtod(str, &endptr);

    // Verificar si hubo error en la conversión
    if (errno == ERANGE || *endptr != '\0')
    {
        return 0;
    }

    // Verificar si es infinito o NaN
    if (isinf(valor) || isnan(valor))
    {
        return 0;
    }

    return 1;
}

// Función auxiliar para validar rango de float
int validarRangoFloat(const char *str)
{
    errno = 0;
    char *endptr;
    float valor = strtof(str, &endptr);

    // Verificar si hubo error en la conversión
    if (errno == ERANGE || *endptr != '\0')
    {
        return 0;
    }

    // Verificar si es infinito o NaN
    if (isinf(valor) || isnan(valor))
    {
        return 0;
    }

    return 1;
}

Result interpretDoubleParseDoubleExpresion(AbstractExpresion *self, Context *context)
{
    // Evaluar la expresión que debería ser un string
    Result resultadoExpresion = self->hijos[0]->interpret(self->hijos[0], context);

    // Verificar que el resultado sea un string
    if (resultadoExpresion.tipo != STRING)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
                 "Double.parseDouble() requiere un argumento de tipo String, pero se recibió: %s",
                 labelTipoDato[resultadoExpresion.tipo]);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, self->linea, self->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Verificar que el string no sea nulo
    if (resultadoExpresion.valor == NULL)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
                 "Double.parseDouble() no puede procesar un string nulo");
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, self->linea, self->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    char *cadena = (char *)resultadoExpresion.valor;

    // Verificar que la cadena represente un número flotante válido
    if (!esNumericoFlotante(cadena))
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
                 "Double.parseDouble() - La cadena '%s' no es un número de punto flotante válido",
                 cadena);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, self->linea, self->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Verificar que esté en el rango de double
    if (!validarRangoDouble(cadena))
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
                 "Double.parseDouble() - El número '%s' está fuera del rango de double o no es válido",
                 cadena);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, self->linea, self->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Convertir la cadena a double
    double *valor = malloc(sizeof(double));
    *valor = strtod(cadena, NULL);

    return nuevoValorResultado(valor, DOUBLE);
}

Result interpretFloatParseFloatExpresion(AbstractExpresion *self, Context *context)
{
    // Evaluar la expresión que debería ser un string
    Result resultadoExpresion = self->hijos[0]->interpret(self->hijos[0], context);

    // Verificar que el resultado sea un string
    if (resultadoExpresion.tipo != STRING)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
                 "Float.parseFloat() requiere un argumento de tipo String, pero se recibió: %s",
                 labelTipoDato[resultadoExpresion.tipo]);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, self->linea, self->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Verificar que el string no sea nulo
    if (resultadoExpresion.valor == NULL)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
                 "Float.parseFloat() no puede procesar un string nulo");
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, self->linea, self->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    char *cadena = (char *)resultadoExpresion.valor;

    // Verificar que la cadena represente un número flotante válido
    if (!esNumericoFlotante(cadena))
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
                 "Float.parseFloat() - La cadena '%s' no es un número de punto flotante válido",
                 cadena);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, self->linea, self->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Verificar que esté en el rango de float
    if (!validarRangoFloat(cadena))
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
                 "Float.parseFloat() - El número '%s' está fuera del rango de float o no es válido",
                 cadena);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, self->linea, self->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Convertir la cadena a float
    float *valor = malloc(sizeof(float));
    *valor = strtof(cadena, NULL);

    return nuevoValorResultado(valor, FLOAT);
}

AbstractExpresion *nuevoDoubleParseDoubleExpresion(AbstractExpresion *expresion, int linea, int columna)
{
    DoubleParseDoubleExpresion *nodo = malloc(sizeof(DoubleParseDoubleExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretDoubleParseDoubleExpresion);
    nodo->base.linea = linea;
    nodo->base.columna = columna;

    if (expresion)
    {
        agregarHijo((AbstractExpresion *)nodo, expresion);
    }

    return (AbstractExpresion *)nodo;
}

AbstractExpresion *nuevoFloatParseFloatExpresion(AbstractExpresion *expresion, int linea, int columna)
{
    FloatParseFloatExpresion *nodo = malloc(sizeof(FloatParseFloatExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretFloatParseFloatExpresion);
    nodo->base.linea = linea;
    nodo->base.columna = columna;

    if (expresion)
    {
        agregarHijo((AbstractExpresion *)nodo, expresion);
    }

    return (AbstractExpresion *)nodo;
}