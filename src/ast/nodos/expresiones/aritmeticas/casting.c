#include "casting.h"
#include "ast/nodos/builders.h"
#include "context/error_report.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <wchar.h>
#include <math.h>

/*
 * Función para convertir un Result a un tipo específico
 */
Result convertirTipo(Result origen, TipoDato tipoDestino, Context *context)
{
    // Si el tipo origen y destino son iguales, retornar el mismo resultado
    if (origen.tipo == tipoDestino)
    {
        return origen;
    }

    // Crear nuevo valor convertido
    void *nuevoValor = NULL;

    switch (tipoDestino)
    {
    case CHAR:
    {
        char *valorChar = malloc(sizeof(char));
        if (!valorChar)
        {
            return nuevoValorResultadoVacio();
        }
        switch (origen.tipo)
        {
        case INT:
            *valorChar = (char)(*(int *)origen.valor);
            break;
        case FLOAT:
            *valorChar = (char)(*(float *)origen.valor);
            break;
        case DOUBLE:
            *valorChar = (char)(*(double *)origen.valor);
            break;
        case BOOLEAN:
            *valorChar = (*(bool *)origen.valor) ? '1' : '0';
            break;
        case STRING:
        {
            char *str = (char *)origen.valor;
            if (str != NULL && strlen(str) > 0)
            {
                *valorChar = str[0];
            }
            else
            {
                *valorChar = '\0';
            }
            break;
        }
        default:
            *valorChar = '\0';
            break;
        }
        nuevoValor = valorChar;
        break;
    }

    case INT:
    {
        int *valorInt = malloc(sizeof(int));
        if (!valorInt)
        {
            return nuevoValorResultadoVacio();
        }
        switch (origen.tipo)
        {
        case CHAR:
            *valorInt = (int)(*(char *)origen.valor);
            break;
        case FLOAT:
            *valorInt = (int)(*(float *)origen.valor);
            break;
        case DOUBLE:
            *valorInt = (int)(*(double *)origen.valor);
            break;
        case BOOLEAN:
            *valorInt = (*(bool *)origen.valor) ? 1 : 0;
            break;
        case STRING:
        {
            char *str = (char *)origen.valor;
            if (str != NULL)
            {
                *valorInt = atoi(str);
            }
            else
            {
                *valorInt = 0;
            }
            break;
        }
        default:
            *valorInt = 0;
            break;
        }
        nuevoValor = valorInt;
        break;
    }

    case FLOAT:
    {
        float *valorFloat = malloc(sizeof(float));
        if (!valorFloat)
        {
            return nuevoValorResultadoVacio();
        }
        switch (origen.tipo)
        {
        case CHAR:
            *valorFloat = (float)(*(char *)origen.valor);
            break;
        case INT:
            *valorFloat = (float)(*(int *)origen.valor);
            break;
        case DOUBLE:
            *valorFloat = (float)(*(double *)origen.valor);
            break;
        case BOOLEAN:
            *valorFloat = (*(bool *)origen.valor) ? 1.0f : 0.0f;
            break;
        case STRING:
        {
            char *str = (char *)origen.valor;
            if (str != NULL)
            {
                *valorFloat = atof(str);
            }
            else
            {
                *valorFloat = 0.0f;
            }
            break;
        }
        default:
            *valorFloat = 0.0f;
            break;
        }
        nuevoValor = valorFloat;
        break;
    }

    case DOUBLE:
    {
        double *valorDouble = malloc(sizeof(double));
        if (!valorDouble)
        {
            return nuevoValorResultadoVacio();
        }
        switch (origen.tipo)
        {
        case CHAR:
            *valorDouble = (double)(*(char *)origen.valor);
            break;
        case INT:
            *valorDouble = (double)(*(int *)origen.valor);
            break;
        case FLOAT:
            *valorDouble = (double)(*(float *)origen.valor);
            break;
        case BOOLEAN:
            *valorDouble = (*(bool *)origen.valor) ? 1.0 : 0.0;
            break;
        case STRING:
        {
            char *str = (char *)origen.valor;
            if (str != NULL)
            {
                *valorDouble = strtod(str, NULL);
            }
            else
            {
                *valorDouble = 0.0;
            }
            break;
        }
        default:
            *valorDouble = 0.0;
            break;
        }
        nuevoValor = valorDouble;
        break;
    }

    case BOOLEAN:
    {
        bool *valorBool = malloc(sizeof(bool));
        switch (origen.tipo)
        {
        case CHAR:
            *valorBool = (*(char *)origen.valor) != '\0';
            break;
        case INT:
            *valorBool = (*(int *)origen.valor) != 0;
            break;
        case FLOAT:
            *valorBool = (*(float *)origen.valor) != 0.0f;
            break;
        case DOUBLE:
            *valorBool = (*(double *)origen.valor) != 0.0;
            break;
        case STRING:
        {
            char *str = (char *)origen.valor;
            *valorBool = strlen(str) > 0;
            break;
        }
        default:
            *valorBool = false;
            break;
        }
        nuevoValor = valorBool;
        break;
    }

    case STRING:
    {
        char *valorString = malloc(256); // Buffer para la conversión
        switch (origen.tipo)
        {
        case CHAR:
            snprintf(valorString, 256, "%c", *(char *)origen.valor);
            break;
        case INT:
            snprintf(valorString, 256, "%d", *(int *)origen.valor);
            break;
        case FLOAT:
            snprintf(valorString, 256, "%.6f", *(float *)origen.valor);
            break;
        case DOUBLE:
            snprintf(valorString, 256, "%.15f", *(double *)origen.valor);
            break;
        case BOOLEAN:
            strcpy(valorString, (*(bool *)origen.valor) ? "true" : "false");
            break;
        default:
            strcpy(valorString, "");
            break;
        }
        nuevoValor = valorString;
        break;
    }

    default:
        return nuevoValorResultadoVacio();
    }

    return nuevoValorResultado(nuevoValor, tipoDestino);
}

Result interpretCastingExpresion(AbstractExpresion *self, Context *context)
{
    CastingExpresion *nodo = (CastingExpresion *)self;

    // Interpretar la expresión a convertir
    Result resultadoOrigen = nodo->expresion->interpret(nodo->expresion, context);

    // Verificar si hubo error en la evaluación
    if (resultadoOrigen.tipo == NULO)
    {
        return nuevoValorResultadoVacio();
    }

    // Realizar la conversión
    Result resultadoConvertido = convertirTipo(resultadoOrigen, nodo->tipoDestino, context);

    // NO LIBERAR MEMORIA DEL RESULTADO ORIGINAL AQUÍ
    // porque puede estar siendo usado por otros nodos o variables
    // La gestión de memoria debe ser manejada por el garbage collector del contexto

    return resultadoConvertido;
}

AbstractExpresion *nuevoCastingExpresion(AbstractExpresion *expresion, TipoDato tipoDestino)
{
    CastingExpresion *nodo = malloc(sizeof(CastingExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretCastingExpresion);
    nodo->expresion = expresion;
    nodo->tipoDestino = tipoDestino;

    // Agregar la expresión como hijo
    agregarHijo((AbstractExpresion *)nodo, expresion);

    return (AbstractExpresion *)nodo;
}