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
    // Para el contexto global, usar directamente el contexto recibido
    // Para otros contextos, crear un nuevo contexto local
    Context *contextoEjecucion;
    if (context->anterior == NULL)
    {
        // Es el contexto global, usar directamente
        contextoEjecucion = context;
    }
    else
    {
        // Crear un nuevo contexto local para el bloque
        contextoEjecucion = nuevoContext(context);
        contextoEjecucion->archivo = context->archivo; // hereda el archivo de salida
    }

    for (size_t i = 0; i < self->numHijos; ++i)
    {
        Result resultadoSentencia = self->hijos[i]->interpret(self->hijos[i], contextoEjecucion);
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

    // Intentar asignar la línea/columna usando el contador del lexer si está disponible
    extern int yylineno;
    extern int yycolumn;
    nodo->base.linea = yylineno;
    nodo->base.columna = yycolumn;

    return (AbstractExpresion *)nodo;
}
