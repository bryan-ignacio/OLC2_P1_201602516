#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "switch.h"
#include "while.h" // Para acceder a las variables globales de control

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Variable global para controlar break en switch
extern bool switchBreak;

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Variable global para controlar break en switch (usa la misma que while)
extern bool whileBreak;

Result interpretSwitchExpresion(AbstractExpresion *self, Context *context)
{
    // Crear nuevo contexto para el switch
    Context *nuevoContexto = nuevoContext(context);

    // Evaluar la expresión del switch
    Result valorSwitch = self->hijos[0]->interpret(self->hijos[0], context);

    // Lista de casos (segundo hijo)
    AbstractExpresion *listaCasos = self->hijos[1];

    bool casoEncontrado = false;
    bool ejecutarRestantes = false; // Para fall-through
    AbstractExpresion *casoDefault = NULL;
    switchBreak = false;

    // Primera pasada: buscar coincidencias y ejecutar casos
    for (size_t i = 0; i < listaCasos->numHijos && !switchBreak; i++)
    {
        AbstractExpresion *caso = listaCasos->hijos[i];
        CaseExpresion *nodoCase = (CaseExpresion *)caso;

        if (nodoCase->esDefault)
        {
            // Guardar referencia al caso default para después
            casoDefault = caso;
        }
        else if (!ejecutarRestantes)
        {
            // Evaluar el valor del case solo si no estamos ejecutando todos
            Result valorCase = caso->hijos[0]->interpret(caso->hijos[0], context);

            // Comparar valores (solo para tipos compatibles)
            bool coincide = false;
            if (valorSwitch.tipo == valorCase.tipo)
            {
                switch (valorSwitch.tipo)
                {
                case INT:
                    coincide = *((int *)valorSwitch.valor) == *((int *)valorCase.valor);
                    break;
                case CHAR:
                    coincide = *((char *)valorSwitch.valor) == *((char *)valorCase.valor);
                    break;
                case STRING:
                    coincide = strcmp((char *)valorSwitch.valor, (char *)valorCase.valor) == 0;
                    break;
                default:
                    // Otros tipos no soportados para switch
                    break;
                }
            }

            if (coincide)
            {
                casoEncontrado = true;
                ejecutarRestantes = true;
            }
        }

        // Si coincide o ya estamos ejecutando casos restantes (fall-through)
        if (ejecutarRestantes && !nodoCase->esDefault)
        {
            // Ejecutar el bloque del case (segundo hijo)
            if (caso->numHijos > 1)
            {
                caso->hijos[1]->interpret(caso->hijos[1], nuevoContexto);
            }
        }
    }

    // Si no se encontró ningún caso y hay default, ejecutarlo
    if (!casoEncontrado && casoDefault && !switchBreak)
    {
        // Ejecutar el bloque del default (primer hijo)
        if (casoDefault->numHijos > 0)
        {
            casoDefault->hijos[0]->interpret(casoDefault->hijos[0], nuevoContexto);
        }
    }

    // Reset break flags that were set by break within the switch
    if (whileBreak || switchBreak)
    {
        whileBreak = false;
        switchBreak = false;
    }

    return nuevoValorResultadoVacio();
}

Result interpretCaseExpresion(AbstractExpresion *self, Context *context)
{
    // Los cases se manejan desde el switch padre
    // Este método no debería llamarse directamente
    (void)self;
    (void)context;
    return nuevoValorResultadoVacio();
}

Result interpretBreakExpresion(AbstractExpresion *self, Context *context)
{
    // Establecer flag para salir del switch o bucle
    (void)self;
    (void)context;
    // Determinar si estamos en un switch o while basado en el contexto
    switchBreak = true;
    whileBreak = true; // También para compatibilidad con while
    return nuevoValorResultadoVacio();
}

AbstractExpresion *nuevoSwitchExpresion(AbstractExpresion *expresion, AbstractExpresion *listaCasos)
{
    SwitchExpresion *nodo = malloc(sizeof(SwitchExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretSwitchExpresion);
    nodo->tieneDefault = false;

    // Verificar si hay un caso default
    for (size_t i = 0; i < listaCasos->numHijos; i++)
    {
        CaseExpresion *caso = (CaseExpresion *)listaCasos->hijos[i];
        if (caso->esDefault)
        {
            nodo->tieneDefault = true;
            break;
        }
    }

    agregarHijo((AbstractExpresion *)nodo, expresion);
    agregarHijo((AbstractExpresion *)nodo, listaCasos);

    return (AbstractExpresion *)nodo;
}

AbstractExpresion *nuevoCaseExpresion(AbstractExpresion *valor, AbstractExpresion *bloque)
{
    CaseExpresion *nodo = malloc(sizeof(CaseExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretCaseExpresion);
    nodo->esDefault = false;

    agregarHijo((AbstractExpresion *)nodo, valor);
    agregarHijo((AbstractExpresion *)nodo, bloque);

    return (AbstractExpresion *)nodo;
}

AbstractExpresion *nuevoDefaultExpresion(AbstractExpresion *bloque)
{
    CaseExpresion *nodo = malloc(sizeof(CaseExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretCaseExpresion);
    nodo->esDefault = true;

    agregarHijo((AbstractExpresion *)nodo, bloque);

    return (AbstractExpresion *)nodo;
}

AbstractExpresion *nuevoBreakExpresion()
{
    BreakExpresion *nodo = malloc(sizeof(BreakExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretBreakExpresion);

    return (AbstractExpresion *)nodo;
}