#ifndef BUILDERS_H
#define BUILDERS_H

#include "ast/AbstractExpresion.h"
#include "ast/nodos/instrucciones/instruccion/declaracion.h"
#include "ast/nodos/expresiones/integerParseInt.h"
#include "ast/nodos/expresiones/floatParse.h"
#include "ast/nodos/expresiones/stringValueOf.h"

/*
    Estructura de un builder:
    AbstractExpresion* nombreExpresionNodo a construir (datos iniciales)
*/

AbstractExpresion *nuevoInstruccionesExpresion(void);
AbstractExpresion *nuevoPrintExpresion(AbstractExpresion *listaExpresiones);
AbstractExpresion *nuevoPrimitivoExpresion(char *valor, char tipo);
AbstractExpresion *nuevoListaExpresiones(void);
AbstractExpresion *nuevoDeclaracionVariables(TipoDato, char *nombre, AbstractExpresion *expresion, int linea, int columna);
AbstractExpresion *nuevoDeclaracionConstante(TipoDato tipo, char *nombre, AbstractExpresion *expresion, int linea, int columna);
AbstractExpresion *nuevoAsignacionExpresion(char *nombre, AbstractExpresion *expresion, int linea, int columna);
AbstractExpresion *nuevoAsignacionCompuesta(char *nombre, TipoAsignacionCompuesta tipoOperador, AbstractExpresion *expresion, int linea, int columna);
AbstractExpresion *nuevoIdentificadorExpresion(char *nombre, int linea, int columna);
// AbstractExpresion* nuevoExpresionLenguaje(char op, AbstractExpresion* izquierda, AbstractExpresion* derecha);

/*
    Builds expresiones
*/
AbstractExpresion *nuevoSumaExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha);
AbstractExpresion *nuevoRestaExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha);
AbstractExpresion *nuevoMultiplicacionExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha);
AbstractExpresion *nuevoDivisionExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha);
AbstractExpresion *nuevoModuloExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha);
AbstractExpresion *nuevoUnarioExpresion(AbstractExpresion *expresion);
AbstractExpresion *nuevoCastingExpresion(AbstractExpresion *expresion, TipoDato tipoDestino);

AbstractExpresion *nuevoComparacionExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha);
AbstractExpresion *nuevoIgualdadExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha);
AbstractExpresion *nuevoDesigualdadExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha);
AbstractExpresion *nuevoMayorQueExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha);
AbstractExpresion *nuevoMenorQueExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha);
AbstractExpresion *nuevoMayorIgualExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha);
AbstractExpresion *nuevoMenorIgualExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha);

/*
    Builds logical operations
*/
AbstractExpresion *nuevoLogicAndExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha);
AbstractExpresion *nuevoLogicOrExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha);
AbstractExpresion *nuevoLogicNotExpresion(AbstractExpresion *operando);

/*
    Builds bitwise operations
*/
AbstractExpresion *nuevoBitwiseAndExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha);
AbstractExpresion *nuevoBitwiseOrExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha);
AbstractExpresion *nuevoBitwiseXorExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha);
AbstractExpresion *nuevoBitwiseNotExpresion(AbstractExpresion *operando);
AbstractExpresion *nuevoBitwiseLeftShiftExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha);
AbstractExpresion *nuevoBitwiseRightShiftExpresion(AbstractExpresion *izquierda, AbstractExpresion *derecha);

/*
    Builds if
*/
AbstractExpresion *nuevoIfExpresion(AbstractExpresion *expresion, AbstractExpresion *bloqueTrue);
AbstractExpresion *nuevoIfElseExpresion(AbstractExpresion *expresion, AbstractExpresion *bloqueTrue, AbstractExpresion *bloqueFalse);
AbstractExpresion *nuevoElseIfExpresion(AbstractExpresion *expresion, AbstractExpresion *bloqueTrue, AbstractExpresion *IfExpresionSiguiente);

/*
    Builds switch-case
*/
AbstractExpresion *nuevoSwitchExpresion(AbstractExpresion *expresion, AbstractExpresion *listaCasos);
AbstractExpresion *nuevoCaseExpresion(AbstractExpresion *valor, AbstractExpresion *bloque);
AbstractExpresion *nuevoDefaultExpresion(AbstractExpresion *bloque);
AbstractExpresion *nuevoBreakExpresion(int linea, int columna);
AbstractExpresion *nuevoListaCasos();

/*
    Builds while
*/
AbstractExpresion *nuevoWhileExpresion(AbstractExpresion *condicion, AbstractExpresion *bloque);
AbstractExpresion *nuevoContinueExpresion(int linea, int columna);

/*
    Builds for
*/
AbstractExpresion *nuevoForExpresion(AbstractExpresion *inicializacion, AbstractExpresion *condicion, AbstractExpresion *incremento, AbstractExpresion *bloque);
AbstractExpresion *nuevoForEachExpresion(TipoDato tipo, char *variable, AbstractExpresion *iterable, AbstractExpresion *bloque);

/*
    Builds arrays
*/
AbstractExpresion *nuevoDeclaracionArrayNew(TipoDato tipoArray, char *identificador, TipoDato tipoElemento, AbstractExpresion *tamaño, int linea, int columna);
AbstractExpresion *nuevoDeclaracionArrayInit(TipoDato tipoArray, char *identificador, AbstractExpresion *listaElementos, int linea, int columna);
AbstractExpresion *nuevoAccesoArrayExpresion(char *identificador, AbstractExpresion *indice, int linea, int columna);
AbstractExpresion *nuevoAsignacionArrayExpresion(char *identificador, AbstractExpresion *indice, AbstractExpresion *valor, int linea, int columna);
AbstractExpresion *nuevoListaElementos();

// Matrix functions
AbstractExpresion *nuevoDeclaracionMatrixNew(TipoDato tipoMatrix, char *identificador, TipoDato tipoElemento, AbstractExpresion *filas, AbstractExpresion *columnas, int linea, int columna);
AbstractExpresion *nuevoDeclaracionMatrixInit(TipoDato tipoMatrix, char *identificador, AbstractExpresion *listaFilas, int linea, int columna);
AbstractExpresion *nuevoAccesoMatrixExpresion(char *identificador, AbstractExpresion *fila, AbstractExpresion *columna, int linea, int columna_pos);
AbstractExpresion *nuevoAsignacionMatrixExpresion(char *identificador, AbstractExpresion *fila, AbstractExpresion *columna, AbstractExpresion *valor, int linea, int columna_pos);
AbstractExpresion *nuevoListaFilas();

AbstractExpresion *nuevoFuncionExpresion(TipoDato tipoDato, char *nombre, AbstractExpresion *listaExpr, AbstractExpresion *bloque);
AbstractExpresion *nuevoLlamadaExpresion(char *id, AbstractExpresion *listaExpresiones);
AbstractExpresion *nuevoListaParametros();
AbstractExpresion *nuevoReturnExpresion(AbstractExpresion *expresion);

/*
    Integer functions
*/
AbstractExpresion *nuevoIntegerParseIntExpresion(AbstractExpresion *expresion, int linea, int columna);

/*
    Float and Double functions
*/
AbstractExpresion *nuevoDoubleParseDoubleExpresion(AbstractExpresion *expresion, int linea, int columna);
AbstractExpresion *nuevoFloatParseFloatExpresion(AbstractExpresion *expresion, int linea, int columna);
AbstractExpresion *nuevoStringValueOfExpresion(AbstractExpresion *expresion, int linea, int columna);

#endif