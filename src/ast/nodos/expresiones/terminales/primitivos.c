#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "primitivos.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <wchar.h>
#include <string.h>

/*
    CREAR SIEMPRE NUEVO ESPACIO DE MEMORIA PARA ESTE ESCENARIO CON malloc
    porque si usamos la direccion de memoria de esa variable, es posible que el garbage
    collector la elimine por ser variable local
*/
Result interpretPrimitivoExpresion(AbstractExpresion *self, Context *context)
{
    PrimitivoExpresion *nodo = (PrimitivoExpresion *)self;
    switch (nodo->tipo)
    {
    case INT:
        int *valorint = malloc(sizeof(int));
        *valorint = atoi(nodo->valor);
        return nuevoValorResultado((void *)valorint, nodo->tipo);
    case BOOLEAN:
        bool *valorbool = malloc(sizeof(bool));
        if (*nodo->valor == 'T')
        {
            *valorbool = true;
        }
        else if (*nodo->valor == 'F')
        {
            *valorbool = false;
        }
        else
        {
            printf("Error desconocido al convertir el boolean\n");
        }
        return nuevoValorResultado((void *)valorbool, nodo->tipo);
    case FLOAT:
        float *valorfloat = malloc(sizeof(float));
        *valorfloat = atof(nodo->valor);
        return nuevoValorResultado((void *)valorfloat, nodo->tipo);
    case STRING:
        return nuevoValorResultado((void *)nodo->valor, nodo->tipo);
    case CHAR:
        wchar_t *valorchar = malloc(sizeof(wchar_t));
        // Parsear el carácter Unicode del formato 'x' o '\uXXXX'
        if (strlen(nodo->valor) >= 3)
        { // Al menos 'x'
            if (nodo->valor[1] == '\\' && nodo->valor[2] == 'u')
            {
                // Formato '\uXXXX' - parsear código Unicode
                char hex_str[5];
                strncpy(hex_str, &nodo->valor[3], 4);
                hex_str[4] = '\0';
                *valorchar = (wchar_t)strtol(hex_str, NULL, 16);
            }
            else
            {
                // Carácter simple 'x'
                *valorchar = (wchar_t)nodo->valor[1];
            }
        }
        else
        {
            *valorchar = L'\u0000'; // Carácter por defecto
        }
        return nuevoValorResultado((void *)valorchar, nodo->tipo);
    default:
        printf("Tipo de dato primitivo no implementado\n");
    }
    return nuevoValorResultadoVacio();
}

AbstractExpresion *nuevoPrimitivoExpresion(char *v, char tipo)
{ //, int lengthValor) {
    // reservar el espacio en memoria y obtener el puntero a este
    PrimitivoExpresion *nodo = malloc(sizeof(PrimitivoExpresion));
    if (!nodo)
        return NULL;
    // asignar valores
    buildAbstractExpresion(&nodo->base, interpretPrimitivoExpresion);

    nodo->valor = v;
    nodo->tipo = tipo;
    return (AbstractExpresion *)nodo;
}