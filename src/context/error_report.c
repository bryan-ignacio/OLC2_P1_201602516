#include "error_report.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Error *listaErrores = NULL;

void agregarError(const char *descripcion, int linea, int columna, int ambito)
{
    Error *nuevo = malloc(sizeof(Error));
    nuevo->descripcion = strdup(descripcion);
    nuevo->linea = linea;
    nuevo->columna = columna;
    nuevo->ambito = ambito;
    nuevo->siguiente = listaErrores;
    listaErrores = nuevo;
    // Imprimir el error en consola inmediatamente
    // fprintf(stderr, "[ERROR] Ambito: %d | Linea: %d, Columna: %d | %s\n", ambito, linea, columna, descripcion);
}

void agregarErrorLexico(const char *descripcion, int linea, int columna)
{
    char buffer[512];
    snprintf(buffer, sizeof(buffer), "[LEXICO] %s", descripcion);
    agregarError(buffer, linea, columna, 0);
}

void agregarErrorSintactico(const char *descripcion, int linea, int columna, int ambito)
{
    char buffer[512];
    snprintf(buffer, sizeof(buffer), "[SINTACTICO] %s", descripcion);
    agregarError(buffer, linea, columna, ambito);
}

void agregarErrorSemantico(const char *descripcion, int linea, int columna, int ambito)
{
    char buffer[512];
    snprintf(buffer, sizeof(buffer), "[SEMANTICO] %s", descripcion);
    agregarError(buffer, linea, columna, ambito);
}

void imprimirErrores()
{
    Error *actual = listaErrores;
    FILE *f = fopen("errores.txt", "w");
    if (!actual)
    {
        printf("No se encontraron errores.\n");
        if (f)
        {
            fprintf(f, "No se encontraron errores.\n");
            fclose(f);
        }
        return;
    }
    printf("\nReporte de errores:\n");
    printf("---------------------------------------------\n");
    if (f)
    {
        fprintf(f, "\nReporte de errores:\n");
        fprintf(f, "---------------------------------------------\n");
    }
    while (actual)
    {
        printf("Ambito: %d | Linea: %d, Columna: %d | %s\n", actual->ambito, actual->linea, actual->columna, actual->descripcion);
        if (f)
        {
            fprintf(f, "Ambito: %d | Linea: %d, Columna: %d | %s\n", actual->ambito, actual->linea, actual->columna, actual->descripcion);
        }
        actual = actual->siguiente;
    }
    printf("---------------------------------------------\n");
    if (f)
    {
        fprintf(f, "---------------------------------------------\n");
        fclose(f);
    }
}

void liberarErrores()
{
    Error *actual = listaErrores;
    while (actual)
    {
        Error *temp = actual;
        actual = actual->siguiente;
        free(temp->descripcion);
        free(temp);
    }
    listaErrores = NULL;
}

int tieneErrores()
{
    return listaErrores != NULL;
}
