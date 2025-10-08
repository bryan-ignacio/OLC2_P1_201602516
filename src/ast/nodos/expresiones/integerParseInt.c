#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "context/error_report.h"
#include "integerParseInt.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

// Función auxiliar para validar si una cadena es numérica entera
int esNumericoEntero(const char *str)
{
    if (str == NULL || *str == '\0')
    {
        return 0; // Cadena vacía o nula
    }

    int i = 0;

    // Permitir signo negativo o positivo al inicio
    if (str[i] == '-' || str[i] == '+')
    {
        i++;
        if (str[i] == '\0')
        {
            return 0; // Solo signo sin dígitos
        }
    }

    // Verificar que el resto sean solo dígitos
    while (str[i] != '\0')
    {
        if (!isdigit(str[i]))
        {
            return 0; // Carácter no numérico encontrado
        }
        i++;
    }

    return 1; // Es numérico
}

// Función auxiliar para validar rango de entero de 32 bits
int validarRangoInt32(const char *str)
{
    errno = 0;
    char *endptr;
    long long valor = strtoll(str, &endptr, 10);

    // Verificar si hubo error en la conversión
    if (errno == ERANGE || *endptr != '\0')
    {
        return 0;
    }

    // Verificar si está en el rango de int de 32 bits
    if (valor < INT_MIN || valor > INT_MAX)
    {
        return 0;
    }

    return 1;
}

Result interpretIntegerParseIntExpresion(AbstractExpresion *self, Context *context)
{
    // Evaluar la expresión que debería ser un string
    Result resultadoExpresion = self->hijos[0]->interpret(self->hijos[0], context);

    // Verificar que el resultado sea un string
    if (resultadoExpresion.tipo != STRING)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
                 "Integer.parseInt() requiere un argumento de tipo String, pero se recibió: %s",
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
                 "Integer.parseInt() no puede procesar un string nulo");
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, self->linea, self->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    char *cadena = (char *)resultadoExpresion.valor;

    // Verificar que la cadena represente un número entero válido
    if (!esNumericoEntero(cadena))
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
                 "Integer.parseInt() - La cadena '%s' no es un número entero válido",
                 cadena);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, self->linea, self->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Verificar que esté en el rango de int de 32 bits
    if (!validarRangoInt32(cadena))
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
                 "Integer.parseInt() - El número '%s' está fuera del rango de enteros de 32 bits (-%d a %d)",
                 cadena, INT_MAX, INT_MAX);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, self->linea, self->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Convertir la cadena a entero
    int *valor = malloc(sizeof(int));
    *valor = (int)strtol(cadena, NULL, 10);

    return nuevoValorResultado(valor, INT);
}

AbstractExpresion *nuevoIntegerParseIntExpresion(AbstractExpresion *expresion, int linea, int columna)
{
    IntegerParseIntExpresion *nodo = malloc(sizeof(IntegerParseIntExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretIntegerParseIntExpresion);
    nodo->base.linea = linea;
    nodo->base.columna = columna;

    if (expresion)
    {
        agregarHijo((AbstractExpresion *)nodo, expresion);
    }

    return (AbstractExpresion *)nodo;
}