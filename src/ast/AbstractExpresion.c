#include "AbstractExpresion.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Este archivo contiene las funciones para manejar el AST (Abstract Syntax Tree).

// Añadir hijo al Nodo
void agregarHijo(AbstractExpresion *padre, AbstractExpresion *hijo)
{
    if (!padre || !hijo)
        return;
    // reasignar el tamaño del bloque de almacenamiento
    // si tenia 4 espacios de tipo puntero le sumamos 1 espacio más
    // realloc(puntero al principio del bloque, tamaño )
    // TODO: mejorar
    AbstractExpresion **newarr = realloc(padre->hijos, sizeof(AbstractExpresion *) * (padre->numHijos + 1));
    if (!newarr)
    {
        perror("realloc");
        exit(EXIT_FAILURE);
    }
    padre->hijos = newarr;
    padre->hijos[padre->numHijos] = hijo;
    padre->numHijos++;
}

/* liberación */
void liberarAST(AbstractExpresion *raiz)
{
    if (!raiz)
        return;
    for (size_t i = 0; i < raiz->numHijos; ++i)
    {
        liberarAST(raiz->hijos[i]);
    }
    free(raiz->hijos);
    free(raiz);
}

/*
 * Construye una expresión abstracta con un método interpretar específico.
- Analiza un nodo del AST
- @param base: nodo base a construir.
- @param interpretPuntero: puntero a la función de interpretación.
Con esto asigna la funcion Interpret y inicializa el array de hijos.
 */
void buildAbstractExpresion(AbstractExpresion *base, Interpret interpretPuntero)
{
    // asignar valores
    base->interpret = interpretPuntero;
    base->graficar = NULL; // Inicializar puntero graficar
    base->hijos = NULL;
    base->numHijos = 0;
    base->linea = 0;
    base->columna = 0;
}

/*
 * Construye una expresión abstracta con métodos interpretar y graficar específicos.
 */
void buildAbstractExpresionCompleta(AbstractExpresion *base, Interpret interpretPuntero, Graficar graficarPuntero)
{
    // asignar valores
    base->interpret = interpretPuntero;
    base->graficar = graficarPuntero;
    base->hijos = NULL;
    base->numHijos = 0;
    base->linea = 0;
    base->columna = 0;
}

/*
 * Establece la posición en el código fuente para un nodo del AST
 */
void establecerPosicion(AbstractExpresion *nodo, int linea, int columna)
{
    if (nodo)
    {
        nodo->linea = linea;
        nodo->columna = columna;
    }
}
