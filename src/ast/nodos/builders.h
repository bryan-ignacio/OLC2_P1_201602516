#ifndef BUILDERS_H
#define BUILDERS_H

#include "ast/AbstractExpresion.h"
#include "ast/nodos/instrucciones/instruccion/declaracion.h"

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
AbstractExpresion *nuevoBreakExpresion();
AbstractExpresion *nuevoListaCasos();

AbstractExpresion *nuevoFuncionExpresion(TipoDato tipoDato, char *nombre, AbstractExpresion *listaExpr, AbstractExpresion *bloque);
AbstractExpresion *nuevoLlamadaExpresion(char *id, AbstractExpresion *listaExpresiones);
AbstractExpresion *nuevoListaParametros();
AbstractExpresion *nuevoReturnExpresion(AbstractExpresion *expresion);

#endif