#ifndef AST_REPORT_H
#define AST_REPORT_H

#include "../ast/AbstractExpresion.h"
#include <stdio.h>

/*
 * Módulo para generar reportes del Árbol de Sintaxis Abstracta (AST)
 * utilizando Graphviz para crear representaciones gráficas.
 */

// Estructura para manejar el contador de nodos durante la generación del grafo
typedef struct
{
    int contador;
    FILE *archivo;
    int profundidad; // Para evitar recursión infinita
} ASTReportContext;

// Funciones principales del reporte AST
void generarReporteAST(AbstractExpresion *raiz, const char *nombreArchivo);
void generarReporteASTCompleto(AbstractExpresion *raiz, const char *nombreArchivoBase);

// Funciones auxiliares para generar el archivo DOT
void iniciarReporteAST(ASTReportContext *context, const char *nombreArchivo);
void finalizarReporteAST(ASTReportContext *context);
int graficarNodoAST(AbstractExpresion *nodo, ASTReportContext *context, int idPadre);

// Funciones para obtener información de los nodos
const char *obtenerTipoNodo(AbstractExpresion *nodo);
const char *obtenerEtiquetaNodo(AbstractExpresion *nodo);
const char *obtenerColorNodo(AbstractExpresion *nodo);
size_t obtenerIndiceHijo(AbstractExpresion *nodo, int idPadre);

// Funciones para extraer información específica de nodos
const char *obtenerTipoDatoString(TipoDato tipo);
const char *obtenerInformacionDeclaracion(AbstractExpresion *nodo);
const char *obtenerInformacionPrimitivo(AbstractExpresion *nodo);
const char *obtenerInformacionIdentificador(AbstractExpresion *nodo);
const char *obtenerInformacionOperador(AbstractExpresion *nodo);
const char *obtenerInformacionAsignacion(AbstractExpresion *nodo);
const char *obtenerInformacionFuncion(AbstractExpresion *nodo);

// Función para convertir archivo DOT a imagen
void convertirDOTaImagen(const char *archivoDOT, const char *archivoImagen);

#endif // AST_REPORT_H