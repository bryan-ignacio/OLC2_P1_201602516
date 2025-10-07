#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "instrucciones.h"
#include "instruccion/flujo/while.h" // Para acceder a los flags de control

#include <stdlib.h>
#include <stdio.h>

Result interpretInstrucciones(AbstractExpresion *self, Context *context)
{
    // Crear un nuevo contexto local para el bloque
    Context *contextoLocal = nuevoContext(context);
    contextoLocal->archivo = context->archivo; // hereda el archivo de salida
    for (size_t i = 0; i < self->numHijos; ++i)
    {
        Result resultadoSentencia = self->hijos[i]->interpret(self->hijos[i], contextoLocal);
        if (resultadoSentencia.isReturn)
        {
            return resultadoSentencia;
        }

        // Verificar flags de control de bucle
        if (whileBreak || whileContinue)
        {
            break; // Salir del bloque inmediatamente
        }

        // Verificar flag de control de switch (solo para switch)
        if (switchBreak)
        {
            break; // Salir del bloque inmediatamente
        }
    }
    return nuevoValorResultadoVacio();
}

AbstractExpresion *nuevoInstruccionesExpresion()
{
    // asignar memoria
    InstruccionesExpresion *nodo = malloc(sizeof(InstruccionesExpresion));
    if (!nodo)
        return NULL;
    buildAbstractExpresion(&nodo->base, interpretInstrucciones);

    return (AbstractExpresion *)nodo;
}
