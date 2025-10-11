#include "context.h"
#include "ast/AbstractExpresion.h"
#include "context/error_report.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
------ Este archivo: contiene el contexto de ejecucion de variables y funciones.
*/

// Crea un nuevo contexto, enlazándolo con un contexto anterior si se proporciona.
Context *nuevoContext(Context *anterior)
{
    Context *nuevo = malloc(sizeof(Context));
    nuevo->anterior = anterior;
    if (anterior)
    {
        nuevo->nombre = anterior->nombre + 1;
        nuevo->global = anterior->global;
    }
    else
    {
        nuevo->global = nuevo;
    }
    nuevo->ultimoSymbol = NULL;

    return nuevo;
}

// Crea una nueva variable con el nombre, valor y tipo especificados.
Symbol *nuevoVariable(char *nombre, void *valor, TipoDato tipo, int linea, int columna, int ambito)
{
    Symbol *nuevo = malloc(sizeof(Symbol));
    nuevo->nombre = nombre;
    nuevo->valor = valor;
    nuevo->tipo = tipo;
    nuevo->clase = VARIABLE;
    nuevo->esConstante = 0; // Es variable, no constante
    nuevo->linea = linea;
    nuevo->columna = columna;
    nuevo->ambito = ambito;
    nuevo->nodo = NULL;
    nuevo->anterior = NULL;
    return nuevo;
}

// Crea una nueva constante con el nombre, valor y tipo especificados.
// Las constantes son inmutables después de su inicialización.
Symbol *nuevoConstante(char *nombre, void *valor, TipoDato tipo, int linea, int columna, int ambito)
{
    Symbol *nuevo = malloc(sizeof(Symbol));
    nuevo->nombre = nombre;
    nuevo->valor = valor;
    nuevo->tipo = tipo;
    nuevo->clase = VARIABLE; // Usamos VARIABLE pero marcado como constante
    nuevo->esConstante = 1;  // Es constante - protegida contra reasignación
    nuevo->linea = linea;
    nuevo->columna = columna;
    nuevo->ambito = ambito;
    nuevo->nodo = NULL;
    nuevo->anterior = NULL;
    return nuevo;
}

// Crea una nueva función con el nombre, tipo de retorno y nodo AST especificados.
Symbol *nuevaFuncion(char *nombre, TipoDato tipo, AbstractExpresion *nodo, int linea, int columna, int ambito)
{
    Symbol *nuevo = malloc(sizeof(Symbol));
    nuevo->nombre = nombre;
    nuevo->tipo = tipo;
    nuevo->clase = FUNCION;
    nuevo->esConstante = 0; // Las funciones no son constantes
    nuevo->nodo = nodo;
    nuevo->linea = linea;
    nuevo->columna = columna;
    nuevo->ambito = ambito;
    nuevo->valor = NULL;
    nuevo->anterior = NULL;
    return nuevo;
}

// Agrega un símbolo al contexto actual, verificando si ya existe.
void agregarSymbol(Context *actual, Symbol *symbol)
{
    Symbol *existente = buscarSymbol(actual->ultimoSymbol, symbol->nombre);
    if (existente)
    {
// Reportar error de redeclaración con ubicación si es posible
#include "context/error_report.h"
        int linea = symbol->linea, columna = symbol->columna, ambito = symbol->ambito;
        char buffer[256];
        const char *tipoSymbol = symbol->esConstante ? "constante" : "variable";
        const char *tipoExistente = existente->esConstante ? "constante" : "variable";
        snprintf(buffer, sizeof(buffer), "La %s '%s' ya existe como %s.", tipoSymbol, symbol->nombre, tipoExistente);
        agregarErrorSemantico(buffer, linea, columna, ambito);
        return;
    }

    // Si el símbolo no tiene ámbito asignado, usar el del contexto actual
    if (symbol->ambito == 0 && actual)
    {
        symbol->ambito = actual->nombre;
    }

    symbol->anterior = actual->ultimoSymbol;
    actual->ultimoSymbol = symbol;
}

// Busca un símbolo por nombre en la lista de símbolos proporcionada.
Symbol *buscarSymbol(Symbol *actual, char *nombre)
{
    while (actual)
    {
        if (strcmp(actual->nombre, nombre) == 0)
        {
            return actual;
        }
        actual = actual->anterior;
    }
    return NULL;
}

// Busca un símbolo por nombre en el contexto actual y sus contextos anteriores.
Symbol *buscarTablaSimbolos(Context *actual, char *nombre)
{
    while (actual)
    {
        Symbol *symbolEncontrado = buscarSymbol(actual->ultimoSymbol, nombre);
        if (symbolEncontrado)
        {
            return symbolEncontrado;
        }
        actual = actual->anterior;
    }
    return NULL;
}

// Funciones para el reporte de tabla de símbolos

// Genera el reporte completo de la tabla de símbolos en un archivo HTML
void generarReporteTablaSimbolos(Context *global, const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "w");
    if (!archivo)
    {
        printf("Error: No se pudo crear el archivo de reporte de tabla de símbolos: %s\n", nombreArchivo);
        return;
    }

    // Escribir encabezado HTML
    fprintf(archivo, "<!DOCTYPE html>\n");
    fprintf(archivo, "<html lang=\"es\">\n");
    fprintf(archivo, "<head>\n");
    fprintf(archivo, "    <meta charset=\"UTF-8\">\n");
    fprintf(archivo, "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
    fprintf(archivo, "    <title>Reporte de Tabla de Símbolos</title>\n");
    fprintf(archivo, "    <style>\n");
    fprintf(archivo, "        body { font-family: Arial, sans-serif; margin: 20px; }\n");
    fprintf(archivo, "        h1 { color: #333; text-align: center; }\n");
    fprintf(archivo, "        h2 { color: #666; margin-top: 30px; }\n");
    fprintf(archivo, "        table { border-collapse: collapse; width: 100%%; margin: 20px 0; }\n");
    fprintf(archivo, "        th, td { border: 1px solid #ddd; padding: 8px; text-align: left; }\n");
    fprintf(archivo, "        th { background-color: #f2f2f2; font-weight: bold; }\n");
    fprintf(archivo, "        tr:nth-child(even) { background-color: #f9f9f9; }\n");
    fprintf(archivo, "        .descripcion { margin: 20px 0; padding: 15px; background-color: #f0f8ff; border-left: 4px solid #0066cc; }\n");
    fprintf(archivo, "        .constante { background-color: #e8f5e8; }\n");
    fprintf(archivo, "        .funcion { background-color: #fff2e8; }\n");
    fprintf(archivo, "    </style>\n");
    fprintf(archivo, "</head>\n");
    fprintf(archivo, "<body>\n");
    fprintf(archivo, "    <h1>Reporte de tabla de símbolos</h1>\n");
    fprintf(archivo, "    <div class=\"descripcion\">\n");
    fprintf(archivo, "        <p>Este reporte mostrará la tabla de símbolos después de la ejecución del archivo.\n");
    fprintf(archivo, "    </div>\n");

    // Escribir tabla de símbolos
    fprintf(archivo, "    <table>\n");
    fprintf(archivo, "        <thead>\n");
    fprintf(archivo, "            <tr>\n");
    fprintf(archivo, "                <th>ID</th>\n");
    fprintf(archivo, "                <th>Tipo símbolo</th>\n");
    fprintf(archivo, "                <th>Tipo dato</th>\n");
    fprintf(archivo, "                <th>Ámbito</th>\n");
    fprintf(archivo, "                <th>Línea</th>\n");
    fprintf(archivo, "                <th>Columna</th>\n");
    fprintf(archivo, "            </tr>\n");
    fprintf(archivo, "        </thead>\n");
    fprintf(archivo, "        <tbody>\n");

    int contador = 1;
    escribirSimbolosContexto(archivo, global, &contador);

    fprintf(archivo, "        </tbody>\n");
    fprintf(archivo, "    </table>\n");
    fprintf(archivo, "</body>\n");
    fprintf(archivo, "</html>\n");

    fclose(archivo);
    printf("Reporte de tabla de símbolos generado: %s\n", nombreArchivo);
}

// Escribe recursivamente los símbolos de un contexto y sus contextos hijos
void escribirSimbolosContexto(FILE *archivo, Context *contexto, int *contador)
{
    if (!contexto)
        return;

    // Escribir símbolos del contexto actual (recorrer en orden inverso para mostrar en orden correcto)
    Symbol *simboloActual = contexto->ultimoSymbol;
    while (simboloActual)
    {
        // Determinar clase CSS según el tipo de símbolo
        const char *claseCSS = "";
        if (simboloActual->esConstante)
            claseCSS = " class=\"constante\"";
        else if (simboloActual->clase == FUNCION)
            claseCSS = " class=\"funcion\"";

        fprintf(archivo, "            <tr%s>\n", claseCSS);
        fprintf(archivo, "                <td>%s</td>\n", simboloActual->nombre);

        // Mostrar si es constante en el tipo de símbolo
        if (simboloActual->esConstante)
            fprintf(archivo, "                <td>Constante</td>\n");
        else
            fprintf(archivo, "                <td>%s</td>\n", obtenerTipoClase(simboloActual->clase));

        fprintf(archivo, "                <td>%s</td>\n", labelTipoDato[simboloActual->tipo]);
        fprintf(archivo, "                <td>%s</td>\n", obtenerAmbito(simboloActual->ambito));
        fprintf(archivo, "                <td>%d</td>\n", simboloActual->linea);
        fprintf(archivo, "                <td>%d</td>\n", simboloActual->columna);
        fprintf(archivo, "            </tr>\n");

        simboloActual = simboloActual->anterior;
        (*contador)++;
    }

    // Nota: Esta implementación solo muestra el contexto actual.
    // Si necesitas mostrar contextos anidados, deberías mantener una lista
    // de todos los contextos creados o recorrer desde el contexto más profundo.
}

// Retorna la cadena correspondiente al tipo de clase del símbolo
const char *obtenerTipoClase(Clase clase)
{
    switch (clase)
    {
    case VARIABLE:
        return "Variable";
    case FUNCION:
        return "Función";
    case STRUCT:
        return "Struct";
    default:
        return "Desconocido";
    }
}

// Retorna la cadena correspondiente al ámbito
const char *obtenerAmbito(int ambito)
{
    if (ambito == 0)
        return "Global";
    else
    {
        static char buffer[20];
        snprintf(buffer, sizeof(buffer), "Local %d", ambito);
        return buffer;
    }
}