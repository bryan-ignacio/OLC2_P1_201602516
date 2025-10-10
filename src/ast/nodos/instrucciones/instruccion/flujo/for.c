#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "for.h"
#include "while.h"                                           // Para acceder a las variables globales de control
#include "ast/nodos/instrucciones/instruccion/declaracion.h" // Para DeclaracionVariable

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Función auxiliar para obtener el tamaño de un tipo de dato
size_t obtenerTamanoTipo(TipoDato tipo)
{
    switch (tipo)
    {
    case CHAR:
        return sizeof(char);
    case INT:
        return sizeof(int);
    case FLOAT:
        return sizeof(float);
    case DOUBLE:
        return sizeof(double);
    case BOOLEAN:
        return sizeof(bool);
    case STRING:
        return sizeof(char *);
    default:
        return sizeof(void *);
    }
}

Result interpretForExpresion(AbstractExpresion *self, Context *context)
{
    // Crear nuevo contexto para el for
    Context *nuevoContexto = nuevoContext(context);

    // Los hijos son: inicializacion, condicion, incremento, bloque
    AbstractExpresion *inicializacion = self->hijos[0];
    AbstractExpresion *condicion = self->hijos[1];
    AbstractExpresion *incremento = self->hijos[2];
    AbstractExpresion *bloque = self->hijos[3];

    // Resetear flags de control
    whileBreak = false;
    whileContinue = false;

    // Incrementar contador de bucles activos
    activeLoopCount++;

    // Ejecutar inicialización (solo una vez)
    if (inicializacion)
    {
        inicializacion->interpret(inicializacion, nuevoContexto);
    }

    // Bucle for principal
    while (true)
    {
        // Evaluar la condición
        if (condicion)
        {
            Result resultCondicion = condicion->interpret(condicion, nuevoContexto);

            // Verificar que la condición sea booleana
            if (resultCondicion.tipo != BOOLEAN)
            {
                printf("Error: La condición del for debe ser booleana, se recibió %s\\n",
                       labelTipoDato[resultCondicion.tipo]);
                break;
            }

            // Si la condición es falsa, salir del bucle
            if (!*((bool *)resultCondicion.valor))
            {
                break;
            }
        }

        // Ejecutar el bloque
        bloque->interpret(bloque, nuevoContexto);

        // Si se ejecutó break, salir del bucle
        if (whileBreak)
        {
            whileBreak = false; // Reset para bucles anidados
            break;
        }

        // Si se ejecutó continue, continuar con la siguiente iteración
        if (whileContinue)
        {
            whileContinue = false; // Reset para bucles anidados
            // Ejecutar incremento incluso con continue
            if (incremento)
            {
                incremento->interpret(incremento, nuevoContexto);
            }
            continue;
        }

        // Ejecutar incremento (solo si no hubo continue)
        // Ejecutar incremento (solo si no hubo continue)
        if (incremento)
        {
            incremento->interpret(incremento, nuevoContexto);
        }
    }

    // Decrementar contador de bucles activos
    activeLoopCount--;

    return nuevoValorResultadoVacio();
}

Result interpretForEachExpresion(AbstractExpresion *self, Context *context)
{
    // Crear nuevo contexto para el for-each
    Context *nuevoContexto = nuevoContext(context);

    // Los hijos son: declaracion_variable, iterable, bloque
    AbstractExpresion *declaracionVar = self->hijos[0];
    AbstractExpresion *iterable = self->hijos[1];
    AbstractExpresion *bloque = self->hijos[2];

    // Resetear flags de control
    whileBreak = false;
    whileContinue = false;

    // Incrementar contador de bucles activos
    activeLoopCount++;

    // Evaluar el iterable para obtener el array
    Result resultIterable = iterable->interpret(iterable, context);

    // Verificar que el iterable sea un array
    if (resultIterable.tipo != ARRAY)
    {
        printf("Error: ForEach solo funciona con arrays, se recibió %s\\n",
               labelTipoDato[resultIterable.tipo]);
        activeLoopCount--;
        return nuevoValorResultadoVacio();
    }

    // Obtener la estructura del array
    ArrayStruct *array = (ArrayStruct *)resultIterable.valor;

    if (array == NULL)
    {
        printf("Error: Array nulo en forEach\\n");
        activeLoopCount--;
        return nuevoValorResultadoVacio();
    }

    // Declarar la variable del for-each en el contexto
    if (declaracionVar)
    {
        declaracionVar->interpret(declaracionVar, nuevoContexto);
    }

    // Obtener el nombre de la variable de iteración (necesario para asignación)
    DeclaracionVariable *varDecl = (DeclaracionVariable *)declaracionVar;
    char *nombreVariable = varDecl->nombre;

    // Iterar sobre cada elemento del array
    for (int i = 0; i < array->tamaño; i++)
    {
        // Si se ejecutó break, salir del bucle
        if (whileBreak)
        {
            whileBreak = false; // Reset para bucles anidados
            break;
        }

        // Buscar la variable en el contexto y asignar el nuevo valor
        Symbol *variable = buscarTablaSimbolos(nuevoContexto, nombreVariable);
        if (variable != NULL)
        {
            // Liberar el valor anterior si existe
            if (variable->valor != NULL && variable->tipo != STRING)
            {
                // No liberamos STRING porque puede ser compartido
                free(variable->valor);
            }

            // Asignar el nuevo valor (hacer una copia)
            void *nuevoValor = malloc(obtenerTamanoTipo(array->tipoElemento));
            if (nuevoValor != NULL)
            {
                memcpy(nuevoValor, array->elementos[i], obtenerTamanoTipo(array->tipoElemento));
                variable->valor = nuevoValor;
                variable->tipo = array->tipoElemento;
            }
        }

        // Ejecutar el bloque con el elemento actual
        if (bloque)
        {
            bloque->interpret(bloque, nuevoContexto);
        }

        // Si se ejecutó continue, continuar con la siguiente iteración
        if (whileContinue)
        {
            whileContinue = false; // Reset para bucles anidados
            continue;
        }
    }

    // Decrementar contador de bucles activos
    activeLoopCount--;

    return nuevoValorResultadoVacio();
}

AbstractExpresion *nuevoForExpresion(AbstractExpresion *inicializacion, AbstractExpresion *condicion, AbstractExpresion *incremento, AbstractExpresion *bloque)
{
    ForExpresion *nodo = malloc(sizeof(ForExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretForExpresion);
    nodo->esForEach = false;

    // Agregar los hijos en orden: inicializacion, condicion, incremento, bloque
    if (inicializacion)
    {
        agregarHijo((AbstractExpresion *)nodo, inicializacion);
    }
    else
    {
        // Agregar NULL como placeholder para mantener el orden
        agregarHijo((AbstractExpresion *)nodo, NULL);
    }

    if (condicion)
    {
        agregarHijo((AbstractExpresion *)nodo, condicion);
    }
    else
    {
        agregarHijo((AbstractExpresion *)nodo, NULL);
    }

    if (incremento)
    {
        agregarHijo((AbstractExpresion *)nodo, incremento);
    }
    else
    {
        agregarHijo((AbstractExpresion *)nodo, NULL);
    }

    agregarHijo((AbstractExpresion *)nodo, bloque);

    return (AbstractExpresion *)nodo;
}

AbstractExpresion *nuevoForEachExpresion(TipoDato tipo, char *variable, AbstractExpresion *iterable, AbstractExpresion *bloque)
{
    ForEachExpresion *nodo = malloc(sizeof(ForEachExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretForEachExpresion);

    // Crear una declaración de variable para el for-each
    AbstractExpresion *declaracionVar = nuevoDeclaracionVariables(tipo, variable, NULL, 0, 0);

    agregarHijo((AbstractExpresion *)nodo, declaracionVar);
    agregarHijo((AbstractExpresion *)nodo, iterable);
    agregarHijo((AbstractExpresion *)nodo, bloque);

    return (AbstractExpresion *)nodo;
}