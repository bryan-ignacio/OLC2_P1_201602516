#include "ast/AbstractExpresion.h"
#include "ast/nodos/instrucciones/instrucciones.h"
#include "context/context.h"

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
    if (yyparse() == 0)
    {
        // Si el análisis sintáctico fue exitoso, se procesa el AST.
        if (ast_root)
        {
            // Se imprime la cantidad de instrucciones en el AST.
            printf("Inicio, cantidad de instrucciones: %ld \n", ast_root->numHijos);
            // Se crea un contexto padre para la interpretación del AST.
            Context *contextPadre = nuevoContext(NULL);
            // Se abre el archivo desde el contexto padre para escribir la salida.
            contextPadre->archivo = fopen("salida.txt", "w");

            // Si el contexto padre no pudo abrir el archivo, muestra un mensaje de error y termina el programa.
            if (contextPadre->archivo == NULL)
            {
                printf("Error: No se pudo abrir el archivo.\n");
                return 1;
            }

            // Se interpreta el AST en el contexto padre y se obtiene el resultado.
            Result resultado = ast_root->interpret(ast_root, contextPadre);

            (void)resultado; // Suprimir warning de variable no utilizada
            // Se cierra el archivo asociado al contexto padre.
            fclose(contextPadre->archivo);
            // Se imprime un mensaje indicando que el archivo fue validado correctamente.
            printf("Fin, archivo validado.\n");
        }
        // Si no se generó un AST, muestra un mensaje indicando que no se analizó ninguna entrada.
        else
        {
            printf("No se analizó ninguna entrada.\n");
        }
    }
    // Si el análisis sintáctico falló, muestra un mensaje de error.
    else
    {
        fprintf(stderr, "El análisis sintáctico falló.\n");
    }
    // Si se abrió un archivo de entrada, se cierra antes de terminar el programa.
    if (yyin && yyin != stdin)
    {
        fclose(yyin);
    }
    // Termina el programa con código de éxito.
    return 0;
}