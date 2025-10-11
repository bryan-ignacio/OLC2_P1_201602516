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
        // Generar reporte HTML incluso sin errores
        generarReporteErroresHTML();
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

    // Generar reporte HTML
    generarReporteErroresHTML();
}

void generarReporteErroresHTML()
{
    FILE *archivo = fopen("reporte_errores.html", "w");
    if (!archivo)
    {
        printf("Error al crear el archivo reporte_errores.html\n");
        return;
    }

    // Escribir el encabezado HTML
    fprintf(archivo, "<!DOCTYPE html>\n");
    fprintf(archivo, "<html lang=\"es\">\n");
    fprintf(archivo, "<head>\n");
    fprintf(archivo, "    <meta charset=\"UTF-8\">\n");
    fprintf(archivo, "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
    fprintf(archivo, "    <title>Reporte de Errores</title>\n");
    fprintf(archivo, "    <style>\n");
    fprintf(archivo, "        body { font-family: Arial, sans-serif; margin: 20px; background-color: #f5f5f5; }\n");
    fprintf(archivo, "        h1 { color: #d32f2f; text-align: center; margin-bottom: 30px; }\n");
    fprintf(archivo, "        .container { max-width: 1200px; margin: 0 auto; background-color: white; padding: 30px; border-radius: 10px; box-shadow: 0 2px 10px rgba(0,0,0,0.1); }\n");
    fprintf(archivo, "        table { border-collapse: collapse; width: 100%%; margin: 20px 0; }\n");
    fprintf(archivo, "        th, td { border: 1px solid #ddd; padding: 12px; text-align: left; }\n");
    fprintf(archivo, "        th { background-color: #f44336; color: white; font-weight: bold; }\n");
    fprintf(archivo, "        tr:nth-child(even) { background-color: #f9f9f9; }\n");
    fprintf(archivo, "        tr:hover { background-color: #f5f5f5; }\n");
    fprintf(archivo, "        .error-lexico { background-color: #ffebee; }\n");
    fprintf(archivo, "        .error-sintactico { background-color: #fff3e0; }\n");
    fprintf(archivo, "        .error-semantico { background-color: #e8f5e8; }\n");
    fprintf(archivo, "        .no-errores { text-align: center; color: #4caf50; font-size: 18px; margin: 40px 0; }\n");
    fprintf(archivo, "        .descripcion { margin: 20px 0; padding: 15px; background-color: #e3f2fd; border-left: 4px solid #2196f3; }\n");
    fprintf(archivo, "        .stats { display: flex; justify-content: space-around; margin: 20px 0; }\n");
    fprintf(archivo, "        .stat-box { background-color: #f8f9fa; padding: 15px; border-radius: 5px; text-align: center; min-width: 120px; }\n");
    fprintf(archivo, "        .stat-number { font-size: 24px; font-weight: bold; color: #d32f2f; }\n");
    fprintf(archivo, "        .stat-label { font-size: 14px; color: #666; }\n");
    fprintf(archivo, "    </style>\n");
    fprintf(archivo, "</head>\n");
    fprintf(archivo, "<body>\n");
    fprintf(archivo, "    <div class=\"container\">\n");
    fprintf(archivo, "        <h1>📋 Reporte de Errores del Analizador</h1>\n");

    // Contar errores por tipo
    int totalErrores = 0;
    int erroresLexicos = 0;
    int erroresSintacticos = 0;
    int erroresSemanticos = 0;

    Error *actual = listaErrores;
    while (actual)
    {
        totalErrores++;
        if (strstr(actual->descripcion, "[LEXICO]"))
            erroresLexicos++;
        else if (strstr(actual->descripcion, "[SINTACTICO]"))
            erroresSintacticos++;
        else if (strstr(actual->descripcion, "[SEMANTICO]"))
            erroresSemanticos++;
        actual = actual->siguiente;
    }

    // Estadísticas
    fprintf(archivo, "        <div class=\"stats\">\n");
    fprintf(archivo, "            <div class=\"stat-box\">\n");
    fprintf(archivo, "                <div class=\"stat-number\">%d</div>\n", totalErrores);
    fprintf(archivo, "                <div class=\"stat-label\">Total de Errores</div>\n");
    fprintf(archivo, "            </div>\n");
    fprintf(archivo, "            <div class=\"stat-box\">\n");
    fprintf(archivo, "                <div class=\"stat-number\">%d</div>\n", erroresLexicos);
    fprintf(archivo, "                <div class=\"stat-label\">Errores Léxicos</div>\n");
    fprintf(archivo, "            </div>\n");
    fprintf(archivo, "            <div class=\"stat-box\">\n");
    fprintf(archivo, "                <div class=\"stat-number\">%d</div>\n", erroresSintacticos);
    fprintf(archivo, "                <div class=\"stat-label\">Errores Sintácticos</div>\n");
    fprintf(archivo, "            </div>\n");
    fprintf(archivo, "            <div class=\"stat-box\">\n");
    fprintf(archivo, "                <div class=\"stat-number\">%d</div>\n", erroresSemanticos);
    fprintf(archivo, "                <div class=\"stat-label\">Errores Semánticos</div>\n");
    fprintf(archivo, "            </div>\n");
    fprintf(archivo, "        </div>\n");

    if (!listaErrores)
    {
        fprintf(archivo, "        <div class=\"no-errores\">\n");
        fprintf(archivo, "            <h2>🎉 ¡Felicidades!</h2>\n");
        fprintf(archivo, "            <p>No se encontraron errores en el análisis del código.</p>\n");
        fprintf(archivo, "        </div>\n");
    }
    else
    {
        fprintf(archivo, "        <div class=\"descripcion\">\n");
        fprintf(archivo, "            <p><strong>Descripción:</strong> Este reporte muestra todos los errores encontrados durante el análisis léxico, sintáctico y semántico del código fuente.</p>\n");
        fprintf(archivo, "            <p><strong>Tipos de errores:</strong></p>\n");
        fprintf(archivo, "            <ul>\n");
        fprintf(archivo, "                <li><strong>Léxicos:</strong> Caracteres o tokens no reconocidos</li>\n");
        fprintf(archivo, "                <li><strong>Sintácticos:</strong> Violaciones de la gramática del lenguaje</li>\n");
        fprintf(archivo, "                <li><strong>Semánticos:</strong> Errores de tipos, variables no declaradas, etc.</li>\n");
        fprintf(archivo, "            </ul>\n");
        fprintf(archivo, "        </div>\n");

        // Tabla de errores
        fprintf(archivo, "        <table>\n");
        fprintf(archivo, "            <thead>\n");
        fprintf(archivo, "                <tr>\n");
        fprintf(archivo, "                    <th>#</th>\n");
        fprintf(archivo, "                    <th>Tipo</th>\n");
        fprintf(archivo, "                    <th>Línea</th>\n");
        fprintf(archivo, "                    <th>Columna</th>\n");
        fprintf(archivo, "                    <th>Ámbito</th>\n");
        fprintf(archivo, "                    <th>Descripción</th>\n");
        fprintf(archivo, "                </tr>\n");
        fprintf(archivo, "            </thead>\n");
        fprintf(archivo, "            <tbody>\n");

        // Recorrer la lista de errores e imprimirlos
        actual = listaErrores;
        int contador = 1;
        while (actual)
        {
            // Determinar el tipo de error y la clase CSS
            char *tipo = "OTRO";
            char *clase = "";

            if (strstr(actual->descripcion, "[LEXICO]"))
            {
                tipo = "LÉXICO";
                clase = "error-lexico";
            }
            else if (strstr(actual->descripcion, "[SINTACTICO]"))
            {
                tipo = "SINTÁCTICO";
                clase = "error-sintactico";
            }
            else if (strstr(actual->descripcion, "[SEMANTICO]"))
            {
                tipo = "SEMÁNTICO";
                clase = "error-semantico";
            }

            // Limpiar la descripción removiendo el prefijo [TIPO]
            char *descripcionLimpia = actual->descripcion;
            if (strstr(actual->descripcion, "] "))
            {
                descripcionLimpia = strstr(actual->descripcion, "] ") + 2;
            }

            fprintf(archivo, "                <tr class=\"%s\">\n", clase);
            fprintf(archivo, "                    <td>%d</td>\n", contador);
            fprintf(archivo, "                    <td><strong>%s</strong></td>\n", tipo);
            fprintf(archivo, "                    <td>%d</td>\n", actual->linea);
            fprintf(archivo, "                    <td>%d</td>\n", actual->columna);
            fprintf(archivo, "                    <td>%d</td>\n", actual->ambito);
            fprintf(archivo, "                    <td>%s</td>\n", descripcionLimpia);
            fprintf(archivo, "                </tr>\n");

            actual = actual->siguiente;
            contador++;
        }

        fprintf(archivo, "            </tbody>\n");
        fprintf(archivo, "        </table>\n");
    }

    // Pie de página
    fprintf(archivo, "        <div style=\"margin-top: 40px; padding-top: 20px; border-top: 1px solid #ddd; text-align: center; color: #666;\">\n");
    fprintf(archivo, "            <p>Reporte generado automáticamente por el Analizador OLC2_P1_201602516</p>\n");
    fprintf(archivo, "            <p>Fecha de generación: %s</p>\n", __DATE__);
    fprintf(archivo, "        </div>\n");
    fprintf(archivo, "    </div>\n");
    fprintf(archivo, "</body>\n");
    fprintf(archivo, "</html>\n");

    fclose(archivo);
    printf("✓ Reporte de errores HTML generado: reporte_errores.html\n");
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
