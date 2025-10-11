#ifndef ERROR_REPORT_H
#define ERROR_REPORT_H

#include <stddef.h>

// Estructura para un error
typedef struct Error
{
    char *descripcion;
    int linea;
    int columna;
    int ambito;
    struct Error *siguiente;
} Error;

// Lista global de errores
extern Error *listaErrores;

void agregarError(const char *descripcion, int linea, int columna, int ambito);
void agregarErrorLexico(const char *descripcion, int linea, int columna);
void agregarErrorSintactico(const char *descripcion, int linea, int columna, int ambito);
void agregarErrorSemantico(const char *descripcion, int linea, int columna, int ambito);
void imprimirErrores();
void generarReporteErroresHTML();
void liberarErrores();
int tieneErrores();

#endif
