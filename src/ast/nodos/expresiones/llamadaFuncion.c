#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "llamadaFuncion.h"

#include <stdlib.h>
#include <stdio.h>

Result interpretLlamadaFuncionExpresion(AbstractExpresion *self, Context *context)
{
    LlamadaFuncionExpresion *nodo = (LlamadaFuncionExpresion *)self;
    Symbol *symbolEncontrado = buscarTablaSimbolos(context, nodo->id);
    if (symbolEncontrado && symbolEncontrado->clase == FUNCION)
    {
        // crear nuevo contexto
        Context *contextFuncion = nuevoContext(context->global);
        int posicionInstruccciones = 0;
        if (symbolEncontrado->nodo->numHijos > 1)
        {
            AbstractExpresion *listaParametros = symbolEncontrado->nodo->hijos[0];
            // Verificar si tenemos argumentos en la llamada
            if (self->numHijos > 0)
            {
                AbstractExpresion *listaArgumentos = self->hijos[0];
                if (listaParametros->numHijos != listaArgumentos->numHijos)
                {
                    printf("La cantidad de argumentos es inesperada\n");
                    return nuevoValorResultadoVacio();
                }
                for (size_t i = 0; i < listaParametros->numHijos; ++i)
                {
                    Result resultDeclararParametro = listaParametros->hijos[i]->interpret(listaParametros->hijos[i], contextFuncion);
                    Result resultadoArgumento = listaArgumentos->hijos[i]->interpret(listaArgumentos->hijos[i], context);
                    // asignar el valor del argumento
                    if (contextFuncion->ultimoSymbol->tipo != resultadoArgumento.tipo)
                    {
                        printf("Error el tipo del parametro no coincide, %s %s\n", labelTipoDato[contextFuncion->ultimoSymbol->tipo], labelTipoDato[resultadoArgumento.tipo]);
                        return nuevoValorResultadoVacio();
                    }
                    contextFuncion->ultimoSymbol->valor = resultadoArgumento.valor;
                }
            }
            else
            {
                // No hay argumentos pero la función espera parámetros
                printf("La cantidad de argumentos es inesperada\n");
                return nuevoValorResultadoVacio();
            }
            posicionInstruccciones = 1;
        }
        else
        {
            // Función sin parámetros
            if (self->numHijos > 0)
            {
                printf("La función no espera argumentos\n");
                return nuevoValorResultadoVacio();
            }
        }
        Result resultadoFuncion = symbolEncontrado->nodo->hijos[posicionInstruccciones]->interpret(symbolEncontrado->nodo->hijos[posicionInstruccciones], contextFuncion);

        // Para funciones void, no importa lo que retorne el bloque
        if (symbolEncontrado->tipo == VOID)
        {
            return nuevoValorResultado(NULL, VOID);
        }

        if (resultadoFuncion.tipo != symbolEncontrado->tipo)
        {
            printf("Error el tipo no coincide con la funcion, %s %s\n", labelTipoDato[resultadoFuncion.tipo], labelTipoDato[symbolEncontrado->tipo]);
            return nuevoValorResultadoVacio();
        }
        return resultadoFuncion;
    }
    printf("El identificador no existe %s\n", nodo->id);
    return nuevoValorResultadoVacio();
}

AbstractExpresion *nuevoLlamadaExpresion(char *id, AbstractExpresion *listaExpresiones)
{
    // reservar el espacio en memoria y obtener el puntero a este
    LlamadaFuncionExpresion *nodo = malloc(sizeof(LlamadaFuncionExpresion));
    if (!nodo)
        return NULL;
    // asignar valores
    buildAbstractExpresion(&nodo->base, interpretLlamadaFuncionExpresion);
    nodo->id = id;

    if (listaExpresiones)
        agregarHijo((AbstractExpresion *)nodo, listaExpresiones);
    return (AbstractExpresion *)nodo;
}