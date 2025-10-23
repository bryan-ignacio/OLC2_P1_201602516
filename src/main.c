#include "ast/AbstractExpresion.h"
#include "ast/nodos/instrucciones/instrucciones.h"
#include "ast/nodos/instrucciones/instruccion/funcion.h"

#include "context/context.h"
#include "context/error_report.h"
#include "context/ast_report.h" // Incluir reporte AST
// Contexto actual para reporte de errores
Context *contextoActualReporte = NULL;

#include <stdlib.h>
#include <stdio.h>

/* Declaraciones generadas por Bison/Flex */
int yyparse(void);

extern FILE *yyin;

// Raíz del árbol de sintaxis abstracta (AST)
AbstractExpresion *ast_root = NULL;

/*
Archivo principal del proyecto.
Es el punto de entrada del programa.
 */
// Función principal del programa.
int main(int argc, char **argv)
{
    // Manejo de argumentos para entrada desde archivo.
    if (argc > 1)
    {
        // abre el archivo de entrada y se lo asigna a yyin para que el analizador léxico lo procese.
        yyin = fopen(argv[1], "r"); // si no se puede abrir el archivo, muestra un mensaje de error y termina el programa.
        // Se verifica si el archivo se abrió correctamente.
        if (!yyin)
        {
            perror("fopen");
            return 1;
        }
    }

    // Llama al analizador sintáctico generado por Bison.
    int parseResult = yyparse();
    if (parseResult == 0)
    {
        if (ast_root)
        {
            printf("Inicio, cantidad de instrucciones: %ld \n", ast_root->numHijos);

            // Generar reporte del AST antes de la interpretación
            printf("\n=== Generando Reporte del Árbol AST ===\n");
            generarReporteASTCompleto(ast_root, "reporte_ast");
            printf("=======================================\n\n");

            Context *contextPadre = nuevoContext(NULL);
            contextoActualReporte = contextPadre;
            contextPadre->archivo = fopen("salida.txt", "w");
            if (contextPadre->archivo == NULL)
            {
                printf("Error: No se pudo abrir el archivo.\n");
                imprimirErrores();
                liberarErrores();
                return 1;
            }
            Result resultado = ast_root->interpret(ast_root, contextPadre);
            (void)resultado;

            // Después de procesar todas las declaraciones, ejecutar la función main
            Result resultadoMain = ejecutarFuncionMainPendiente();
            (void)resultadoMain;

            fclose(contextPadre->archivo);

            // Generar reporte de tabla de símbolos
            generarReporteTablaSimbolos(contextPadre, "tabla_simbolos.html");

            printf("Fin, archivo validado.\n");
        }
        else
        {
            printf("No se analizó ninguna entrada.\n");
        }
    }
    else
    {
        fprintf(stderr, "El análisis sintáctico falló.\n");
    }
    imprimirErrores();
    liberarErrores();
    // Si se abrió un archivo de entrada, se cierra antes de terminar el programa.
    if (yyin && yyin != stdin)
    {
        fclose(yyin);
    }
    // Termina el programa con código de éxito.
    return 0;
}