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
        if (resultado.tipo == self->tipo)
        {
            Symbol *var = nuevoVariable(self->nombre, resultado.valor, self->tipo);
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

    Symbol *var = nuevoVariable(self->nombre, valorPorDefecto, self->tipo);
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

    if (resultado.tipo == self->tipo)
    {
        // Crear el símbolo como constante
        Symbol *constante = nuevoConstante(self->nombre, resultado.valor, self->tipo);
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
    if (resultado.tipo != variable->tipo)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Tipos incompatibles para la asignación a '%s'. Esperado: %d, Recibido: %d",
                 self->nombre, variable->tipo, resultado.tipo);
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
