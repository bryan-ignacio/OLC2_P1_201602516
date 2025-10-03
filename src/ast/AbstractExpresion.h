#ifndef ABSTRACT_EXPRESION_H
#define ABSTRACT_EXPRESION_H

#include "context/definiciones.h"
#include "context/result.h"
#include "context/context.h"
#include <stddef.h>

// Definen la estructura base para todos los nodos del AST.

// Definición del tipo de función para interpretar nodos.
typedef Result (*Interpret)(AbstractExpresion *, Context *);

// Definición del tipo de función para graficar nodos.
typedef void (*Graficar)(AbstractExpresion *);

// Estructura base para todos los nodos del AST
struct AbstractExpresion
{
    Interpret interpret; // Método interpretar puntero, puntero a funcion de interpretacion.
    // Graficar graficar; //Método graficar puntero
    AbstractExpresion **hijos; // Array dinámico de nodos hijos.
    size_t numHijos;           // cantidad de hijos.
    int linea;                 // línea de código fuente
    int columna;               // columna de código fuente
};

// Funciones para manejar el AST
void agregarHijo(AbstractExpresion *padre, AbstractExpresion *hijo);

// liberar AST: liberar memoria del AST
void liberarAST(AbstractExpresion *raiz);

/// Construir una expresión abstracta con un método interpretar específico.
void buildAbstractExpresion(AbstractExpresion *base, Interpret interpretPuntero);

#endif