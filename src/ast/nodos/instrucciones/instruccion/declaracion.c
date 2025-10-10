#include <string.h>
#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "context/error_report.h"
#include "declaracion.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <wchar.h>

// Lista de palabras reservadas
const char *palabras_reservadas[] = {
    "int", "float", "double", "String", "boolean", "char", "if", "else", "func", "return", "true", "false", "System.out.println", "final"};

int es_palabra_reservada(const char *nombre)
{
    size_t n = sizeof(palabras_reservadas) / sizeof(palabras_reservadas[0]);
    for (size_t i = 0; i < n; ++i)
    {
        if (strcmp(nombre, palabras_reservadas[i]) == 0)
            return 1;
    }
    return 0;
}

// Función para verificar si un tipo puede convertirse a otro
int es_conversion_valida(TipoDato tipoFuente, TipoDato tipoDestino)
{
    // Los tipos idénticos siempre son válidos
    if (tipoFuente == tipoDestino)
        return 1;

    // Conversiones numéricas válidas (sin pérdida de datos o conversiones estándar)
    switch (tipoDestino)
    {
    case FLOAT:
        // char e int pueden convertirse a float
        return (tipoFuente == CHAR || tipoFuente == INT);
    case DOUBLE:
        // char, int y float pueden convertirse a double
        return (tipoFuente == CHAR || tipoFuente == INT || tipoFuente == FLOAT);
    case INT:
        // char puede convertirse a int
        return (tipoFuente == CHAR);
    default:
        return 0;
    }
}

// Función para convertir un valor a otro tipo
Result convertir_tipo(Result resultado, TipoDato tipoDestino)
{
    if (resultado.tipo == tipoDestino)
        return resultado;

    switch (tipoDestino)
    {
    case FLOAT:
        if (resultado.tipo == CHAR)
        {
            float *nuevoValor = malloc(sizeof(float));
            *nuevoValor = (float)*((char *)resultado.valor);
            return nuevoValorResultado(nuevoValor, FLOAT);
        }
        else if (resultado.tipo == INT)
        {
            float *nuevoValor = malloc(sizeof(float));
            *nuevoValor = (float)*((int *)resultado.valor);
            return nuevoValorResultado(nuevoValor, FLOAT);
        }
        break;
    case DOUBLE:
        if (resultado.tipo == CHAR)
        {
            double *nuevoValor = malloc(sizeof(double));
            *nuevoValor = (double)*((char *)resultado.valor);
            return nuevoValorResultado(nuevoValor, DOUBLE);
        }
        else if (resultado.tipo == INT)
        {
            double *nuevoValor = malloc(sizeof(double));
            *nuevoValor = (double)*((int *)resultado.valor);
            return nuevoValorResultado(nuevoValor, DOUBLE);
        }
        else if (resultado.tipo == FLOAT)
        {
            double *nuevoValor = malloc(sizeof(double));
            *nuevoValor = (double)*((float *)resultado.valor);
            return nuevoValorResultado(nuevoValor, DOUBLE);
        }
        break;
    case INT:
        if (resultado.tipo == CHAR)
        {
            int *nuevoValor = malloc(sizeof(int));
            *nuevoValor = (int)*((char *)resultado.valor);
            return nuevoValorResultado(nuevoValor, INT);
        }
        break;
    }

    // Si no se puede convertir, devolver el resultado original
    return resultado;
}

Result interpretDeclaracionVariable(AbstractExpresion *nodo, Context *context)
{
    DeclaracionVariable *self = (DeclaracionVariable *)nodo;

    // Verificar si el nombre es palabra reservada
    if (es_palabra_reservada(self->nombre))
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "'%s' es una palabra reservada y no puede usarse como nombre de variable.", self->nombre);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }
    // se esta definiendo con valor inicial
    if (nodo->numHijos > 0)
    {
        Result resultado = nodo->hijos[0]->interpret(nodo->hijos[0], context);

        // Verificar si el tipo es compatible o puede convertirse
        if (es_conversion_valida(resultado.tipo, self->tipo))
        {
            // Convertir el tipo si es necesario
            Result resultadoConvertido = convertir_tipo(resultado, self->tipo);

            Symbol *var = nuevoVariable(self->nombre, resultadoConvertido.valor, self->tipo, nodo->linea, nodo->columna, context ? context->nombre : 0);
            var->nodo = nodo;
            agregarSymbol(context, var);
            return nuevoValorResultadoVacio();
        }

        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Tipos incorrectos para la variable '%s'. Esperado: %d, Recibido: %d", self->nombre, self->tipo, resultado.tipo);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Declaración sin inicialización - asignar valores por defecto
    void *valorPorDefecto = NULL;

    switch (self->tipo)
    {
    case INT:
    {
        int *valorInt = malloc(sizeof(int));
        *valorInt = 0; // Valor por defecto para int es 0
        valorPorDefecto = valorInt;
        break;
    }
    case FLOAT:
    {
        float *valorFloat = malloc(sizeof(float));
        *valorFloat = 0.0f; // Valor por defecto para float es 0.0f
        valorPorDefecto = valorFloat;
        break;
    }
    case DOUBLE:
    {
        double *valorDouble = malloc(sizeof(double));
        *valorDouble = 0.0; // Valor por defecto para double es 0.0
        valorPorDefecto = valorDouble;
        break;
    }
    case STRING:
    {
        // Valor por defecto para string es null
        valorPorDefecto = NULL;
        break;
    }
    case BOOLEAN:
    {
        bool *valorBool = malloc(sizeof(bool));
        *valorBool = false; // Valor por defecto para boolean es false
        valorPorDefecto = valorBool;
        break;
    }
    case CHAR:
    {
        wchar_t *valorChar = malloc(sizeof(wchar_t));
        *valorChar = L'\0'; // Valor por defecto para char es \0
        valorPorDefecto = valorChar;
        break;
    }
    default:
        // Para tipos no implementados, usar NULL
        valorPorDefecto = NULL;
        break;
    }

    Symbol *var = nuevoVariable(self->nombre, valorPorDefecto, self->tipo, nodo->linea, nodo->columna, context ? context->nombre : 0);
    var->nodo = nodo;
    agregarSymbol(context, var);
    return nuevoValorResultadoVacio();
}

// Definición correcta para el linker (al final del archivo)
AbstractExpresion *nuevoDeclaracionVariables(TipoDato tipo, char *nombre, AbstractExpresion *expresion, int linea, int columna)
{
    DeclaracionVariable *nodo = malloc(sizeof(DeclaracionVariable));
    if (!nodo)
        return NULL;
    buildAbstractExpresion(&nodo->base, interpretDeclaracionVariable);
    nodo->tipo = tipo;
    nodo->nombre = nombre;
    nodo->base.linea = linea;
    nodo->base.columna = columna;
    if (expresion)
        agregarHijo((AbstractExpresion *)nodo, expresion);
    return (AbstractExpresion *)nodo;
}

Result interpretDeclaracionConstante(AbstractExpresion *nodo, Context *context)
{
    DeclaracionConstante *self = (DeclaracionConstante *)nodo;

    // Verificar si el nombre es palabra reservada
    if (es_palabra_reservada(self->nombre))
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "'%s' es una palabra reservada y no puede usarse como nombre de constante.", self->nombre);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Las constantes DEBEN tener un valor inicial
    if (nodo->numHijos == 0)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Error: La constante '%s' debe ser inicializada con un valor al momento de su declaración.", self->nombre);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Evaluar la expresión de inicialización
    Result resultado = nodo->hijos[0]->interpret(nodo->hijos[0], context);

    // Verificar que la evaluación fue exitosa
    if (resultado.valor == NULL && resultado.tipo != STRING)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Error: No se pudo evaluar la expresión de inicialización para la constante '%s'.", self->nombre);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    if (es_conversion_valida(resultado.tipo, self->tipo))
    {
        // Convertir el tipo si es necesario
        Result resultadoConvertido = convertir_tipo(resultado, self->tipo);

        // Crear el símbolo como constante
        Symbol *constante = nuevoConstante(self->nombre, resultadoConvertido.valor, self->tipo, nodo->linea, nodo->columna, context ? context->nombre : 0);
        constante->nodo = nodo;
        agregarSymbol(context, constante);
        return nuevoValorResultadoVacio();
    }

    char buffer[256];
    snprintf(buffer, sizeof(buffer), "Tipos incorrectos para la constante '%s'. Esperado: %d, Recibido: %d", self->nombre, self->tipo, resultado.tipo);
    int ambito = context && context->nombre ? context->nombre : 0;
    agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
    return nuevoValorResultadoVacio();
}

AbstractExpresion *nuevoDeclaracionConstante(TipoDato tipo, char *nombre, AbstractExpresion *expresion, int linea, int columna)
{
    DeclaracionConstante *nodo = malloc(sizeof(DeclaracionConstante));
    if (!nodo)
        return NULL;
    buildAbstractExpresion(&nodo->base, interpretDeclaracionConstante);
    nodo->tipo = tipo;
    nodo->nombre = nombre;
    nodo->base.linea = linea;
    nodo->base.columna = columna;
    if (expresion)
        agregarHijo((AbstractExpresion *)nodo, expresion);
    return (AbstractExpresion *)nodo;
}

Result interpretAsignacionVariable(AbstractExpresion *nodo, Context *context)
{
    AsignacionVariable *self = (AsignacionVariable *)nodo;

    // Buscar la variable en la tabla de símbolos
    Symbol *variable = buscarTablaSimbolos(context, self->nombre);
    if (!variable)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "La variable '%s' no ha sido declarada.", self->nombre);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Verificar si es una constante
    if (variable->esConstante)
    {
        char buffer[300];
        snprintf(buffer, sizeof(buffer),
                 "Error: No se puede reasignar la constante '%s'. Las constantes son inmutables después de su inicialización. "
                 "Considera usar una variable en lugar de una constante si necesitas modificar el valor.",
                 self->nombre);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Verificar si es una función
    if (variable->clase == FUNCION)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "No se puede asignar un valor a la función '%s'.", self->nombre);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Evaluar la expresión del lado derecho
    if (nodo->numHijos == 0)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Asignación sin valor para la variable '%s'.", self->nombre);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    Result resultado = nodo->hijos[0]->interpret(nodo->hijos[0], context);

    // Verificar compatibilidad de tipos
    if (es_conversion_valida(resultado.tipo, variable->tipo))
    {
        // Convertir el tipo si es necesario
        Result resultadoConvertido = convertir_tipo(resultado, variable->tipo);

        // Liberar memoria del valor anterior si es necesario
        if (variable->valor && variable->tipo == STRING)
        {
            free(variable->valor);
        }

        // Asignar el nuevo valor
        variable->valor = resultadoConvertido.valor;

        return nuevoValorResultadoVacio();
    }

    char buffer[256];
    snprintf(buffer, sizeof(buffer), "Tipos incompatibles para la asignación a '%s'. Esperado: %d, Recibido: %d",
             self->nombre, variable->tipo, resultado.tipo);
    int ambito = context && context->nombre ? context->nombre : 0;
    agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
    return nuevoValorResultadoVacio();
}

AbstractExpresion *nuevoAsignacionExpresion(char *nombre, AbstractExpresion *expresion, int linea, int columna)
{
    AsignacionVariable *nodo = malloc(sizeof(AsignacionVariable));
    if (!nodo)
        return NULL;
    buildAbstractExpresion(&nodo->base, interpretAsignacionVariable);
    nodo->nombre = nombre;
    nodo->base.linea = linea;
    nodo->base.columna = columna;
    if (expresion)
        agregarHijo((AbstractExpresion *)nodo, expresion);
    return (AbstractExpresion *)nodo;
}

Result interpretAsignacionCompuesta(AbstractExpresion *nodo, Context *context)
{
    AsignacionCompuesta *self = (AsignacionCompuesta *)nodo;

    // Buscar la variable en la tabla de símbolos
    Symbol *variable = buscarTablaSimbolos(context, self->nombre);
    if (!variable)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "La variable '%s' no ha sido declarada.", self->nombre);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Verificar si es una constante
    if (variable->esConstante)
    {
        char buffer[300];
        snprintf(buffer, sizeof(buffer),
                 "Error: No se puede reasignar la constante '%s'. Las constantes son inmutables después de su inicialización.",
                 self->nombre);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Verificar si es una función
    if (variable->clase == FUNCION)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "No se puede asignar un valor a la función '%s'.", self->nombre);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Evaluar la expresión del lado derecho
    if (nodo->numHijos == 0)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Asignación compuesta sin valor para la variable '%s'.", self->nombre);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    Result valorDerecho = nodo->hijos[0]->interpret(nodo->hijos[0], context);

    // Aplicar la operación correspondiente según el tipo de asignación compuesta
    Result resultado;
    switch (self->tipoOperador)
    {
    case ASIG_SUMA:
        // variable += expresion equivale a variable = variable + expresion
        if (variable->tipo == INT && valorDerecho.tipo == INT)
        {
            int *res = malloc(sizeof(int));
            *res = *((int *)variable->valor) + *((int *)valorDerecho.valor);
            resultado = nuevoValorResultado(res, INT);
        }
        else if (variable->tipo == FLOAT && valorDerecho.tipo == FLOAT)
        {
            float *res = malloc(sizeof(float));
            *res = *((float *)variable->valor) + *((float *)valorDerecho.valor);
            resultado = nuevoValorResultado(res, FLOAT);
        }
        else if (variable->tipo == DOUBLE && valorDerecho.tipo == DOUBLE)
        {
            double *res = malloc(sizeof(double));
            *res = *((double *)variable->valor) + *((double *)valorDerecho.valor);
            resultado = nuevoValorResultado(res, DOUBLE);
        }
        else
        {
            // Intentar conversión automática
            if (es_conversion_valida(valorDerecho.tipo, variable->tipo))
            {
                Result valorConvertido = convertir_tipo(valorDerecho, variable->tipo);
                if (variable->tipo == INT)
                {
                    int *res = malloc(sizeof(int));
                    *res = *((int *)variable->valor) + *((int *)valorConvertido.valor);
                    resultado = nuevoValorResultado(res, INT);
                }
                else if (variable->tipo == FLOAT)
                {
                    float *res = malloc(sizeof(float));
                    *res = *((float *)variable->valor) + *((float *)valorConvertido.valor);
                    resultado = nuevoValorResultado(res, FLOAT);
                }
                else if (variable->tipo == DOUBLE)
                {
                    double *res = malloc(sizeof(double));
                    *res = *((double *)variable->valor) + *((double *)valorConvertido.valor);
                    resultado = nuevoValorResultado(res, DOUBLE);
                }
                else
                {
                    char buffer[256];
                    snprintf(buffer, sizeof(buffer), "Tipos incompatibles para += en variable '%s'", self->nombre);
                    int ambito = context && context->nombre ? context->nombre : 0;
                    agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
                    return nuevoValorResultadoVacio();
                }
            }
            else
            {
                char buffer[256];
                snprintf(buffer, sizeof(buffer), "Tipos incompatibles para += en variable '%s'", self->nombre);
                int ambito = context && context->nombre ? context->nombre : 0;
                agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
                return nuevoValorResultadoVacio();
            }
        }
        break;

    case ASIG_RESTA:
        // variable -= expresion equivale a variable = variable - expresion
        if (variable->tipo == INT && valorDerecho.tipo == INT)
        {
            int *res = malloc(sizeof(int));
            *res = *((int *)variable->valor) - *((int *)valorDerecho.valor);
            resultado = nuevoValorResultado(res, INT);
        }
        else if (variable->tipo == FLOAT && valorDerecho.tipo == FLOAT)
        {
            float *res = malloc(sizeof(float));
            *res = *((float *)variable->valor) - *((float *)valorDerecho.valor);
            resultado = nuevoValorResultado(res, FLOAT);
        }
        else if (variable->tipo == DOUBLE && valorDerecho.tipo == DOUBLE)
        {
            double *res = malloc(sizeof(double));
            *res = *((double *)variable->valor) - *((double *)valorDerecho.valor);
            resultado = nuevoValorResultado(res, DOUBLE);
        }
        else
        {
            // Intentar conversión automática
            if (es_conversion_valida(valorDerecho.tipo, variable->tipo))
            {
                Result valorConvertido = convertir_tipo(valorDerecho, variable->tipo);
                if (variable->tipo == INT)
                {
                    int *res = malloc(sizeof(int));
                    *res = *((int *)variable->valor) - *((int *)valorConvertido.valor);
                    resultado = nuevoValorResultado(res, INT);
                }
                else if (variable->tipo == FLOAT)
                {
                    float *res = malloc(sizeof(float));
                    *res = *((float *)variable->valor) - *((float *)valorConvertido.valor);
                    resultado = nuevoValorResultado(res, FLOAT);
                }
                else if (variable->tipo == DOUBLE)
                {
                    double *res = malloc(sizeof(double));
                    *res = *((double *)variable->valor) - *((double *)valorConvertido.valor);
                    resultado = nuevoValorResultado(res, DOUBLE);
                }
                else
                {
                    char buffer[256];
                    snprintf(buffer, sizeof(buffer), "Tipos incompatibles para -= en variable '%s'", self->nombre);
                    int ambito = context && context->nombre ? context->nombre : 0;
                    agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
                    return nuevoValorResultadoVacio();
                }
            }
            else
            {
                char buffer[256];
                snprintf(buffer, sizeof(buffer), "Tipos incompatibles para -= en variable '%s'", self->nombre);
                int ambito = context && context->nombre ? context->nombre : 0;
                agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
                return nuevoValorResultadoVacio();
            }
        }
        break;

    case ASIG_MULT:
        // variable *= expresion equivale a variable = variable * expresion
        if (variable->tipo == INT && valorDerecho.tipo == INT)
        {
            int *res = malloc(sizeof(int));
            *res = *((int *)variable->valor) * *((int *)valorDerecho.valor);
            resultado = nuevoValorResultado(res, INT);
        }
        else if (variable->tipo == FLOAT && valorDerecho.tipo == FLOAT)
        {
            float *res = malloc(sizeof(float));
            *res = *((float *)variable->valor) * *((float *)valorDerecho.valor);
            resultado = nuevoValorResultado(res, FLOAT);
        }
        else if (variable->tipo == DOUBLE && valorDerecho.tipo == DOUBLE)
        {
            double *res = malloc(sizeof(double));
            *res = *((double *)variable->valor) * *((double *)valorDerecho.valor);
            resultado = nuevoValorResultado(res, DOUBLE);
        }
        else
        {
            // Intentar conversión automática
            if (es_conversion_valida(valorDerecho.tipo, variable->tipo))
            {
                Result valorConvertido = convertir_tipo(valorDerecho, variable->tipo);
                if (variable->tipo == INT)
                {
                    int *res = malloc(sizeof(int));
                    *res = *((int *)variable->valor) * *((int *)valorConvertido.valor);
                    resultado = nuevoValorResultado(res, INT);
                }
                else if (variable->tipo == FLOAT)
                {
                    float *res = malloc(sizeof(float));
                    *res = *((float *)variable->valor) * *((float *)valorConvertido.valor);
                    resultado = nuevoValorResultado(res, FLOAT);
                }
                else if (variable->tipo == DOUBLE)
                {
                    double *res = malloc(sizeof(double));
                    *res = *((double *)variable->valor) * *((double *)valorConvertido.valor);
                    resultado = nuevoValorResultado(res, DOUBLE);
                }
                else
                {
                    char buffer[256];
                    snprintf(buffer, sizeof(buffer), "Tipos incompatibles para *= en variable '%s'", self->nombre);
                    int ambito = context && context->nombre ? context->nombre : 0;
                    agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
                    return nuevoValorResultadoVacio();
                }
            }
            else
            {
                char buffer[256];
                snprintf(buffer, sizeof(buffer), "Tipos incompatibles para *= en variable '%s'", self->nombre);
                int ambito = context && context->nombre ? context->nombre : 0;
                agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
                return nuevoValorResultadoVacio();
            }
        }
        break;

    case ASIG_DIV:
        // variable /= expresion equivale a variable = variable / expresion
        if (variable->tipo == INT && valorDerecho.tipo == INT)
        {
            if (*((int *)valorDerecho.valor) == 0)
            {
                char buffer[256];
                snprintf(buffer, sizeof(buffer), "División por cero en /= para variable '%s'", self->nombre);
                int ambito = context && context->nombre ? context->nombre : 0;
                agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
                return nuevoValorResultadoVacio();
            }
            int *res = malloc(sizeof(int));
            *res = *((int *)variable->valor) / *((int *)valorDerecho.valor);
            resultado = nuevoValorResultado(res, INT);
        }
        else if (variable->tipo == FLOAT && valorDerecho.tipo == FLOAT)
        {
            if (*((float *)valorDerecho.valor) == 0.0f)
            {
                char buffer[256];
                snprintf(buffer, sizeof(buffer), "División por cero en /= para variable '%s'", self->nombre);
                int ambito = context && context->nombre ? context->nombre : 0;
                agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
                return nuevoValorResultadoVacio();
            }
            float *res = malloc(sizeof(float));
            *res = *((float *)variable->valor) / *((float *)valorDerecho.valor);
            resultado = nuevoValorResultado(res, FLOAT);
        }
        else if (variable->tipo == DOUBLE && valorDerecho.tipo == DOUBLE)
        {
            if (*((double *)valorDerecho.valor) == 0.0)
            {
                char buffer[256];
                snprintf(buffer, sizeof(buffer), "División por cero en /= para variable '%s'", self->nombre);
                int ambito = context && context->nombre ? context->nombre : 0;
                agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
                return nuevoValorResultadoVacio();
            }
            double *res = malloc(sizeof(double));
            *res = *((double *)variable->valor) / *((double *)valorDerecho.valor);
            resultado = nuevoValorResultado(res, DOUBLE);
        }
        else
        {
            // Intentar conversión automática
            if (es_conversion_valida(valorDerecho.tipo, variable->tipo))
            {
                Result valorConvertido = convertir_tipo(valorDerecho, variable->tipo);
                if (variable->tipo == INT)
                {
                    if (*((int *)valorConvertido.valor) == 0)
                    {
                        char buffer[256];
                        snprintf(buffer, sizeof(buffer), "División por cero en /= para variable '%s'", self->nombre);
                        int ambito = context && context->nombre ? context->nombre : 0;
                        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
                        return nuevoValorResultadoVacio();
                    }
                    int *res = malloc(sizeof(int));
                    *res = *((int *)variable->valor) / *((int *)valorConvertido.valor);
                    resultado = nuevoValorResultado(res, INT);
                }
                else if (variable->tipo == FLOAT)
                {
                    if (*((float *)valorConvertido.valor) == 0.0f)
                    {
                        char buffer[256];
                        snprintf(buffer, sizeof(buffer), "División por cero en /= para variable '%s'", self->nombre);
                        int ambito = context && context->nombre ? context->nombre : 0;
                        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
                        return nuevoValorResultadoVacio();
                    }
                    float *res = malloc(sizeof(float));
                    *res = *((float *)variable->valor) / *((float *)valorConvertido.valor);
                    resultado = nuevoValorResultado(res, FLOAT);
                }
                else if (variable->tipo == DOUBLE)
                {
                    if (*((double *)valorConvertido.valor) == 0.0)
                    {
                        char buffer[256];
                        snprintf(buffer, sizeof(buffer), "División por cero en /= para variable '%s'", self->nombre);
                        int ambito = context && context->nombre ? context->nombre : 0;
                        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
                        return nuevoValorResultadoVacio();
                    }
                    double *res = malloc(sizeof(double));
                    *res = *((double *)variable->valor) / *((double *)valorConvertido.valor);
                    resultado = nuevoValorResultado(res, DOUBLE);
                }
                else
                {
                    char buffer[256];
                    snprintf(buffer, sizeof(buffer), "Tipos incompatibles para /= en variable '%s'", self->nombre);
                    int ambito = context && context->nombre ? context->nombre : 0;
                    agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
                    return nuevoValorResultadoVacio();
                }
            }
            else
            {
                char buffer[256];
                snprintf(buffer, sizeof(buffer), "Tipos incompatibles para /= en variable '%s'", self->nombre);
                int ambito = context && context->nombre ? context->nombre : 0;
                agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
                return nuevoValorResultadoVacio();
            }
        }
        break;

    case ASIG_MOD:
        // variable %= expresion equivale a variable = variable % expresion (solo enteros)
        if ((variable->tipo == INT || variable->tipo == CHAR) && (valorDerecho.tipo == INT || valorDerecho.tipo == CHAR))
        {
            int valorIzq = (variable->tipo == INT) ? *((int *)variable->valor) : *((char *)variable->valor);
            int valorDer = (valorDerecho.tipo == INT) ? *((int *)valorDerecho.valor) : *((char *)valorDerecho.valor);
            if (valorDer == 0)
            {
                char buffer[256];
                snprintf(buffer, sizeof(buffer), "División por cero en %%= para variable '%s'", self->nombre);
                int ambito = context && context->nombre ? context->nombre : 0;
                agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
                return nuevoValorResultadoVacio();
            }
            int *res = malloc(sizeof(int));
            *res = valorIzq % valorDer;
            resultado = nuevoValorResultado(res, INT);
            variable->tipo = INT; // Promocionar a INT
        }
        else
        {
            char buffer[256];
            snprintf(buffer, sizeof(buffer), "Operador %%= solo permitido en tipos enteros para variable '%s'", self->nombre);
            int ambito = context && context->nombre ? context->nombre : 0;
            agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
            return nuevoValorResultadoVacio();
        }
        break;

    case ASIG_AND:
        // variable &= expresion equivale a variable = variable & expresion (solo enteros)
        if ((variable->tipo == INT || variable->tipo == CHAR) && (valorDerecho.tipo == INT || valorDerecho.tipo == CHAR))
        {
            int valorIzq = (variable->tipo == INT) ? *((int *)variable->valor) : *((char *)variable->valor);
            int valorDer = (valorDerecho.tipo == INT) ? *((int *)valorDerecho.valor) : *((char *)valorDerecho.valor);
            int *res = malloc(sizeof(int));
            *res = valorIzq & valorDer;
            resultado = nuevoValorResultado(res, INT);
            variable->tipo = INT; // Promocionar a INT
        }
        else
        {
            char buffer[256];
            snprintf(buffer, sizeof(buffer), "Operador &= solo permitido en tipos enteros para variable '%s'", self->nombre);
            int ambito = context && context->nombre ? context->nombre : 0;
            agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
            return nuevoValorResultadoVacio();
        }
        break;

    case ASIG_OR:
        // variable |= expresion equivale a variable = variable | expresion (solo enteros)
        if ((variable->tipo == INT || variable->tipo == CHAR) && (valorDerecho.tipo == INT || valorDerecho.tipo == CHAR))
        {
            int valorIzq = (variable->tipo == INT) ? *((int *)variable->valor) : *((char *)variable->valor);
            int valorDer = (valorDerecho.tipo == INT) ? *((int *)valorDerecho.valor) : *((char *)valorDerecho.valor);
            int *res = malloc(sizeof(int));
            *res = valorIzq | valorDer;
            resultado = nuevoValorResultado(res, INT);
            variable->tipo = INT; // Promocionar a INT
        }
        else
        {
            char buffer[256];
            snprintf(buffer, sizeof(buffer), "Operador |= solo permitido en tipos enteros para variable '%s'", self->nombre);
            int ambito = context && context->nombre ? context->nombre : 0;
            agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
            return nuevoValorResultadoVacio();
        }
        break;

    case ASIG_XOR:
        // variable ^= expresion equivale a variable = variable ^ expresion (solo enteros)
        if ((variable->tipo == INT || variable->tipo == CHAR) && (valorDerecho.tipo == INT || valorDerecho.tipo == CHAR))
        {
            int valorIzq = (variable->tipo == INT) ? *((int *)variable->valor) : *((char *)variable->valor);
            int valorDer = (valorDerecho.tipo == INT) ? *((int *)valorDerecho.valor) : *((char *)valorDerecho.valor);
            int *res = malloc(sizeof(int));
            *res = valorIzq ^ valorDer;
            resultado = nuevoValorResultado(res, INT);
            variable->tipo = INT; // Promocionar a INT
        }
        else
        {
            char buffer[256];
            snprintf(buffer, sizeof(buffer), "Operador ^= solo permitido en tipos enteros para variable '%s'", self->nombre);
            int ambito = context && context->nombre ? context->nombre : 0;
            agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
            return nuevoValorResultadoVacio();
        }
        break;

    case ASIG_LSHIFT:
        // variable <<= expresion equivale a variable = variable << expresion (solo enteros)
        if ((variable->tipo == INT || variable->tipo == CHAR) && (valorDerecho.tipo == INT || valorDerecho.tipo == CHAR))
        {
            int valorIzq = (variable->tipo == INT) ? *((int *)variable->valor) : *((char *)variable->valor);
            int valorDer = (valorDerecho.tipo == INT) ? *((int *)valorDerecho.valor) : *((char *)valorDerecho.valor);
            if (valorDer < 0 || valorDer >= 32)
            {
                char buffer[256];
                snprintf(buffer, sizeof(buffer), "Desplazamiento inválido en <<= para variable '%s': %d", self->nombre, valorDer);
                int ambito = context && context->nombre ? context->nombre : 0;
                agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
                return nuevoValorResultadoVacio();
            }
            int *res = malloc(sizeof(int));
            *res = valorIzq << valorDer;
            resultado = nuevoValorResultado(res, INT);
            variable->tipo = INT; // Promocionar a INT
        }
        else
        {
            char buffer[256];
            snprintf(buffer, sizeof(buffer), "Operador <<= solo permitido en tipos enteros para variable '%s'", self->nombre);
            int ambito = context && context->nombre ? context->nombre : 0;
            agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
            return nuevoValorResultadoVacio();
        }
        break;

    case ASIG_RSHIFT:
        // variable >>= expresion equivale a variable = variable >> expresion (solo enteros)
        if ((variable->tipo == INT || variable->tipo == CHAR) && (valorDerecho.tipo == INT || valorDerecho.tipo == CHAR))
        {
            int valorIzq = (variable->tipo == INT) ? *((int *)variable->valor) : *((char *)variable->valor);
            int valorDer = (valorDerecho.tipo == INT) ? *((int *)valorDerecho.valor) : *((char *)valorDerecho.valor);
            if (valorDer < 0 || valorDer >= 32)
            {
                char buffer[256];
                snprintf(buffer, sizeof(buffer), "Desplazamiento inválido en >>= para variable '%s': %d", self->nombre, valorDer);
                int ambito = context && context->nombre ? context->nombre : 0;
                agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
                return nuevoValorResultadoVacio();
            }
            int *res = malloc(sizeof(int));
            *res = valorIzq >> valorDer;
            resultado = nuevoValorResultado(res, INT);
            variable->tipo = INT; // Promocionar a INT
        }
        else
        {
            char buffer[256];
            snprintf(buffer, sizeof(buffer), "Operador >>= solo permitido en tipos enteros para variable '%s'", self->nombre);
            int ambito = context && context->nombre ? context->nombre : 0;
            agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
            return nuevoValorResultadoVacio();
        }
        break;

    default:
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Operador de asignación compuesta no implementado para variable '%s'", self->nombre);
        int ambito = context && context->nombre ? context->nombre : 0;
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Liberar memoria del valor anterior si es necesario
    if (variable->valor && variable->tipo == STRING)
    {
        free(variable->valor);
    }

    // Asignar el nuevo valor
    variable->valor = resultado.valor;

    return nuevoValorResultadoVacio();
}

AbstractExpresion *nuevoAsignacionCompuesta(char *nombre, TipoAsignacionCompuesta tipoOperador, AbstractExpresion *expresion, int linea, int columna)
{
    AsignacionCompuesta *nodo = malloc(sizeof(AsignacionCompuesta));
    if (!nodo)
        return NULL;
    buildAbstractExpresion(&nodo->base, interpretAsignacionCompuesta);
    nodo->nombre = nombre;
    nodo->tipoOperador = tipoOperador;
    nodo->base.linea = linea;
    nodo->base.columna = columna;
    if (expresion)
        agregarHijo((AbstractExpresion *)nodo, expresion);
    return (AbstractExpresion *)nodo;
}
