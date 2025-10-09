#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "context/error_report.h"
#include "stringJoin.h"
#include "stringValueOf.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constructor para String.join()
AbstractExpresion *nuevoStringJoinExpresion(AbstractExpresion *argumentos, int linea, int columna)
{
    StringJoinExpresion *nuevo = (StringJoinExpresion *)malloc(sizeof(StringJoinExpresion));
    if (!nuevo)
        return NULL;

    nuevo->super.interpret = interpretarStringJoin;
    nuevo->super.linea = linea;
    nuevo->super.columna = columna;
    nuevo->argumentos = argumentos;

    return (AbstractExpresion *)nuevo;
}

// Función de interpretación
Result interpretarStringJoin(AbstractExpresion *expresion, Context *contexto)
{
    StringJoinExpresion *stringJoin = (StringJoinExpresion *)expresion;

    // Obtener la lista de argumentos
    AbstractExpresion *lista = stringJoin->argumentos;
    if (!lista->hijos || lista->numHijos < 2)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "String.join() requiere al menos 2 argumentos (delimitador + elementos)");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        return nuevoValorResultadoVacio();
    }

    // El primer argumento es el delimitador
    Result resultDelimitador = lista->hijos[0]->interpret(lista->hijos[0], contexto);
    if (resultDelimitador.tipo == NULO)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Error al interpretar delimitador en String.join()");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        return nuevoValorResultadoVacio();
    }

    if (resultDelimitador.tipo != STRING)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "El delimitador debe ser un string en String.join()");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        return nuevoValorResultadoVacio();
    }

    char *delimitador = (char *)resultDelimitador.valor;

    // Verificar si tenemos exactamente 2 argumentos (delimitador + array)
    if (lista->numHijos == 2)
    {
        // Caso: String.join(delimitador, array)
        Result resultArray = lista->hijos[1]->interpret(lista->hijos[1], contexto);

        if (resultArray.tipo == NULO)
        {
            char buffer[256];
            snprintf(buffer, sizeof(buffer), "Error al interpretar array en String.join()");
            agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
            return nuevoValorResultadoVacio();
        }

        if (resultArray.tipo == ARRAY)
        {
            // Procesar array
            ArrayStruct *arrayStruct = (ArrayStruct *)resultArray.valor;
            if (arrayStruct->tipoElemento != STRING)
            {
                char buffer[256];
                snprintf(buffer, sizeof(buffer), "String.join() solo soporta arrays de String");
                agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
                return nuevoValorResultadoVacio();
            }

            int numElementos = arrayStruct->tamaño;
            char **elementos = (char **)malloc(sizeof(char *) * numElementos);
            if (!elementos)
            {
                char buffer[256];
                snprintf(buffer, sizeof(buffer), "Error de memoria en String.join()");
                agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
                return nuevoValorResultadoVacio();
            }

            // Copiar elementos del array
            for (int i = 0; i < numElementos; i++)
            {
                elementos[i] = strdup((char *)arrayStruct->elementos[i]);
                if (!elementos[i])
                {
                    // Error al copiar
                    for (int j = 0; j < i; j++)
                    {
                        free(elementos[j]);
                    }
                    free(elementos);
                    char buffer[256];
                    snprintf(buffer, sizeof(buffer), "Error al copiar elemento %d del array en String.join()", i);
                    agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
                    return nuevoValorResultadoVacio();
                }
            }

            // Unir strings con delimitador
            char *stringResultado = unirStringsConDelimitador(delimitador, elementos, numElementos);

            // Liberar memoria de elementos
            for (int i = 0; i < numElementos; i++)
            {
                free(elementos[i]);
            }
            free(elementos);

            if (!stringResultado)
            {
                char buffer[256];
                snprintf(buffer, sizeof(buffer), "Error al unir strings en String.join()");
                agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
                return nuevoValorResultadoVacio();
            }

            return nuevoValorResultado(stringResultado, STRING);
        }
        else
        {
            // Si no es array, tratarlo como argumento individual
            char **elementos = (char **)malloc(sizeof(char *) * 1);
            if (!elementos)
            {
                char buffer[256];
                snprintf(buffer, sizeof(buffer), "Error de memoria en String.join()");
                agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
                return nuevoValorResultadoVacio();
            }

            if (resultArray.tipo == STRING)
            {
                elementos[0] = strdup((char *)resultArray.valor);
            }
            else
            {
                elementos[0] = convertirValorAString(&resultArray);
            }

            if (!elementos[0])
            {
                free(elementos);
                char buffer[256];
                snprintf(buffer, sizeof(buffer), "Error al convertir elemento a string en String.join()");
                agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
                return nuevoValorResultadoVacio();
            }

            char *stringResultado = unirStringsConDelimitador(delimitador, elementos, 1);
            free(elementos[0]);
            free(elementos);

            if (!stringResultado)
            {
                char buffer[256];
                snprintf(buffer, sizeof(buffer), "Error al unir strings en String.join()");
                agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
                return nuevoValorResultadoVacio();
            }

            return nuevoValorResultado(stringResultado, STRING);
        }
    }

    // Caso: String.join(delimitador, arg1, arg2, arg3, ...)
    // Los elementos a unir son los argumentos restantes
    int numElementos = lista->numHijos - 1;
    char **elementos = (char **)malloc(sizeof(char *) * numElementos);
    if (!elementos)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Error de memoria en String.join()");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        return nuevoValorResultadoVacio();
    }

    // Convertir cada elemento a string
    for (int i = 0; i < numElementos; i++)
    {
        Result resultado = lista->hijos[i + 1]->interpret(lista->hijos[i + 1], contexto);

        if (resultado.tipo == NULO)
        {
            // Error en la evaluación
            for (int j = 0; j < i; j++)
            {
                free(elementos[j]);
            }
            free(elementos);
            char buffer[256];
            snprintf(buffer, sizeof(buffer), "Error al evaluar elemento %d en String.join()", i + 1);
            agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
            return nuevoValorResultadoVacio();
        }

        // Convertir el resultado a string
        if (resultado.tipo == STRING)
        {
            elementos[i] = strdup((char *)resultado.valor);
        }
        else
        {
            // Usar String.valueOf() para convertir otros tipos
            elementos[i] = convertirValorAString(&resultado);
        }

        if (!elementos[i])
        {
            // Error al convertir
            for (int j = 0; j < i; j++)
            {
                free(elementos[j]);
            }
            free(elementos);
            char buffer[256];
            snprintf(buffer, sizeof(buffer), "Error al convertir elemento %d a string en String.join()", i + 1);
            agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
            return nuevoValorResultadoVacio();
        }
    }

    // Unir strings con delimitador
    char *stringResultado = unirStringsConDelimitador(delimitador, elementos, numElementos);

    // Liberar memoria de elementos
    for (int i = 0; i < numElementos; i++)
    {
        free(elementos[i]);
    }
    free(elementos);

    if (!stringResultado)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Error al unir strings en String.join()");
        agregarErrorSemantico(buffer, expresion->linea, expresion->columna, contexto->nombre);
        return nuevoValorResultadoVacio();
    }

    return nuevoValorResultado(stringResultado, STRING);
}

// Función para unir strings con delimitador
char *unirStringsConDelimitador(char *delimitador, char **elementos, int numElementos)
{
    if (numElementos == 0)
    {
        return strdup("");
    }

    if (numElementos == 1)
    {
        return strdup(elementos[0]);
    }

    // Calcular tamaño total necesario
    int tamanoTotal = 0;
    int tamanoDelimitador = strlen(delimitador);

    for (int i = 0; i < numElementos; i++)
    {
        tamanoTotal += strlen(elementos[i]);
        if (i < numElementos - 1)
        {
            tamanoTotal += tamanoDelimitador;
        }
    }
    tamanoTotal += 1; // Para el '\0'

    // Crear el string resultado
    char *resultado = (char *)malloc(tamanoTotal);
    if (!resultado)
        return NULL;

    strcpy(resultado, elementos[0]);

    for (int i = 1; i < numElementos; i++)
    {
        strcat(resultado, delimitador);
        strcat(resultado, elementos[i]);
    }

    return resultado;
}