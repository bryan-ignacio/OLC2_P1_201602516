#ifndef DEF_H
#define DEF_H

// Contiene las definiciones basicas de tipos que se usan en varios archivos.

/*
 * se usa para no tener que escribir struct AbstractExpresion* nodo;
 * se define antes porque se accede a este tipo en el mismo struct
 */
typedef struct AbstractExpresion AbstractExpresion;

// esta estructura se usa en varios archivos para definir el tipo de dato.
typedef struct Symbol Symbol;

// esta estructura se usa en varios archivos para definir el contexto de ejecucion.
typedef struct Context Context;

#endif