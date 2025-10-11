#include "ast_report.h"
#include "../ast/AbstractExpresion.h"
#include "../ast/nodos/builders.h"
#include "../ast/nodos/instrucciones/instruccion/declaracion.h"
#include "../ast/nodos/expresiones/terminales/primitivos.h"
#include "../ast/nodos/expresiones/terminales/identificadores.h"
#include "../ast/nodos/instrucciones/instruccion/funcion.h"
#include "definiciones.h"
#include "result.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * Implementación del reporte de Árbol de Sintaxis Abstracta (AST)
 * utilizando Graphviz para generar representaciones gráficas.
 */

// Estructura para mapear funciones de interpretación con nombres de nodos
typedef struct
{
    void *funcion;
    const char *nombre;
    const char *color;
} MapaFuncionNodo;

// Nota: No podemos hacer referencia directa a las funciones desde aquí
// debido a dependencias circulares, así que usaremos heurísticas más simples

/**
 * Genera un reporte completo del AST: archivo DOT y imagen PNG
 */
void generarReporteASTCompleto(AbstractExpresion *raiz, const char *nombreArchivoBase)
{
    if (!raiz || !nombreArchivoBase)
    {
        printf("Error: Parámetros inválidos para generar reporte AST\n");
        return;
    }

    char archivoDOT[256];
    char archivoImagen[256];

    snprintf(archivoDOT, sizeof(archivoDOT), "%s.dot", nombreArchivoBase);
    snprintf(archivoImagen, sizeof(archivoImagen), "%s.png", nombreArchivoBase);

    printf("Generando reporte AST...\n");

    // Generar archivo DOT
    generarReporteAST(raiz, archivoDOT);

    // Convertir a imagen
    convertirDOTaImagen(archivoDOT, archivoImagen);

    printf("Reporte AST generado: %s y %s\n", archivoDOT, archivoImagen);
}

/**
 * Genera un archivo DOT con la representación del AST
 */
void generarReporteAST(AbstractExpresion *raiz, const char *nombreArchivo)
{
    if (!raiz || !nombreArchivo)
    {
        printf("Error: Parámetros inválidos para generar reporte AST\n");
        return;
    }

    ASTReportContext context;
    context.contador = 0;
    context.profundidad = 0; // Inicializar profundidad
    context.archivo = fopen(nombreArchivo, "w");

    if (!context.archivo)
    {
        printf("Error: No se pudo crear el archivo %s\n", nombreArchivo);
        return;
    }

    // Escribir encabezado DOT
    fprintf(context.archivo, "digraph AST {\n");
    fprintf(context.archivo, "    rankdir=TB;\n");
    fprintf(context.archivo, "    node [shape=box, style=filled, fontname=\"Arial\", fontsize=10];\n");
    fprintf(context.archivo, "    edge [fontname=\"Arial\", fontsize=8];\n");
    fprintf(context.archivo, "    \n");

    // Generar el grafo recursivamente
    graficarNodoAST(raiz, &context, -1);

    // Escribir cierre DOT
    fprintf(context.archivo, "}\n");
    fclose(context.archivo);
}

/**
 * Inicializa el contexto del reporte y escribe el encabezado del archivo DOT
 */
void iniciarReporteAST(ASTReportContext *context, const char *nombreArchivo)
{
    context->contador = 0;
    context->archivo = fopen(nombreArchivo, "w");

    if (context->archivo)
    {
        fprintf(context->archivo, "digraph AST {\n");
        fprintf(context->archivo, "    rankdir=TB;\n");
        fprintf(context->archivo, "    node [shape=box, style=filled, fontname=\"Arial\", fontsize=10];\n");
        fprintf(context->archivo, "    edge [fontname=\"Arial\", fontsize=8];\n");
        fprintf(context->archivo, "    \n");
        fprintf(context->archivo, "    // Configuración general del grafo\n");
        fprintf(context->archivo, "    graph [fontname=\"Arial\", fontsize=14, label=\"Árbol de Sintaxis Abstracta\\nGenerado por el Analizador Sintáctico\"];\n");
        fprintf(context->archivo, "    \n");
    }
}

/**
 * Finaliza el archivo DOT
 */
void finalizarReporteAST(ASTReportContext *context)
{
    if (context->archivo)
    {
        fprintf(context->archivo, "}\n");
        fclose(context->archivo);
    }
}

/**
 * Grafica un nodo del AST y sus hijos recursivamente
 */
int graficarNodoAST(AbstractExpresion *nodo, ASTReportContext *context, int idPadre)
{
    // Verificaciones básicas de seguridad
    if (!nodo || !context || !context->archivo)
    {
        return -1;
    }

    // Evitar recursión infinita con un límite más conservador
    if (context->profundidad > 20)
    {
        fprintf(context->archivo, "    node%d [label=\"...\\n(Profundidad máxima alcanzada)\", fillcolor=\"red\"];\n", context->contador);
        if (idPadre >= 0)
        {
            fprintf(context->archivo, "    node%d -> node%d;\n", idPadre, context->contador);
        }
        context->contador++;
        return context->contador - 1;
    }

    // Verificar si el nodo ya fue procesado (prevenir ciclos)
    static void *nodos_procesados[1000];
    static int num_procesados = 0;

    // Al inicio de una nueva generación, reiniciar la lista
    if (context->profundidad == 0)
    {
        num_procesados = 0;
    }

    // Verificar si este nodo ya fue procesado
    for (int i = 0; i < num_procesados; i++)
    {
        if (nodos_procesados[i] == nodo)
        {
            fprintf(context->archivo, "    node%d [label=\"(Referencia circular)\\n%p\", fillcolor=\"orange\"];\n", context->contador, nodo);
            if (idPadre >= 0)
            {
                fprintf(context->archivo, "    node%d -> node%d;\n", idPadre, context->contador);
            }
            context->contador++;
            return context->contador - 1;
        }
    }

    // Agregar nodo a la lista de procesados
    if (num_procesados < 1000)
    {
        nodos_procesados[num_procesados++] = nodo;
    }

    context->profundidad++;

    int idActual = context->contador++;
    const char *tipo = obtenerTipoNodo(nodo);
    const char *etiqueta = obtenerEtiquetaNodo(nodo);
    const char *color = obtenerColorNodo(nodo);

    // Verificar que las cadenas no sean NULL y sean seguras
    if (!tipo || strlen(tipo) == 0)
        tipo = "Desconocido";
    if (!etiqueta || strlen(etiqueta) == 0)
        etiqueta = "Sin info";
    if (!color || strlen(color) == 0)
        color = "lightgray";

    // Escribir el nodo con formato mejorado
    fprintf(context->archivo, "    node%d [label=\"%s\\n%s\", fillcolor=\"%s\"];\n",
            idActual, tipo, etiqueta, color);

    // Conectar con el padre si existe
    if (idPadre >= 0)
    {
        fprintf(context->archivo, "    node%d -> node%d;\n", idPadre, idActual);
    }

    // Graficar los hijos de forma segura
    if (nodo->hijos && nodo->numHijos > 0 && nodo->numHijos < 1000)
    { // Límite razonable
        for (size_t i = 0; i < nodo->numHijos; i++)
        {
            if (nodo->hijos[i] && nodo->hijos[i] != nodo)
            { // Evitar auto-referencia
                graficarNodoAST(nodo->hijos[i], context, idActual);
            }
        }
    }

    context->profundidad--;
    return idActual;
}

/**
 * Obtiene el índice del hijo (para etiquetas de aristas)
 */
size_t obtenerIndiceHijo(AbstractExpresion *nodo, int idPadre)
{
    // Esta función es más para fines estéticos en las etiquetas de las aristas
    // En una implementación más completa, podrías rastrear la relación padre-hijo
    return 0;
}

/**
 * Obtiene el tipo de nodo basado en su función de interpretación y características
 */
const char *obtenerTipoNodo(AbstractExpresion *nodo)
{
    if (!nodo || !nodo->interpret)
    {
        return "Nodo Nulo";
    }

    // Incluir encabezados para acceder a las funciones de interpretación
    extern Result interpretDeclaracionVariable(AbstractExpresion *, Context *);
    extern Result interpretDeclaracionConstante(AbstractExpresion *, Context *);
    extern Result interpretAsignacionVariable(AbstractExpresion *, Context *);
    extern Result interpretFuncionExpresion(AbstractExpresion *, Context *);
    extern Result interpretPrintExpresion(AbstractExpresion *, Context *);
    extern Result interpretReturnExpresion(AbstractExpresion *, Context *);
    extern Result interpretPrimitivoExpresion(AbstractExpresion *, Context *);
    extern Result interpretIdentificadorExpresion(AbstractExpresion *, Context *);
    extern Result interpretInstrucciones(AbstractExpresion *, Context *);
    extern Result interpretForExpresion(AbstractExpresion *, Context *);
    extern Result interpretIfExpresion(AbstractExpresion *, Context *);
    extern Result interpretWhileExpresion(AbstractExpresion *, Context *);

    // Identificar tipos específicos por función de interpretación
    if (nodo->interpret == interpretDeclaracionVariable)
        return "Declaración Variable";
    else if (nodo->interpret == interpretDeclaracionConstante)
        return "Declaración Constante";
    else if (nodo->interpret == interpretAsignacionVariable)
        return "Asignación";
    else if (nodo->interpret == interpretFuncionExpresion)
        return "Función";
    else if (nodo->interpret == interpretPrintExpresion)
        return "Print";
    else if (nodo->interpret == interpretReturnExpresion)
        return "Return";
    else if (nodo->interpret == interpretPrimitivoExpresion)
        return "Primitivo";
    else if (nodo->interpret == interpretIdentificadorExpresion)
        return "Identificador";
    else if (nodo->interpret == interpretInstrucciones)
        return "Lista Instrucciones";
    else if (nodo->interpret == interpretForExpresion)
        return "For";
    else if (nodo->interpret == interpretIfExpresion)
        return "If";
    else if (nodo->interpret == interpretWhileExpresion)
        return "While";

    // Fallback basado en número de hijos para casos no identificados
    if (!nodo->hijos || nodo->numHijos == 0)
        return "Terminal";
    else if (nodo->numHijos == 1)
        return "Unario";
    else if (nodo->numHijos == 2)
        return "Binario";
    else if (nodo->numHijos == 3)
        return "Ternario";
    else
        return "N-ario";
}

/**
 * Genera una etiqueta descriptiva para el nodo con información específica
 */
const char *obtenerEtiquetaNodo(AbstractExpresion *nodo)
{
    static char etiqueta[512];

    if (!nodo)
    {
        strcpy(etiqueta, "NULL");
        return etiqueta;
    }

    // Declaraciones externas para acceso a funciones
    extern Result interpretDeclaracionVariable(AbstractExpresion *, Context *);
    extern Result interpretDeclaracionConstante(AbstractExpresion *, Context *);
    extern Result interpretAsignacionVariable(AbstractExpresion *, Context *);
    extern Result interpretFuncionExpresion(AbstractExpresion *, Context *);
    extern Result interpretPrimitivoExpresion(AbstractExpresion *, Context *);
    extern Result interpretIdentificadorExpresion(AbstractExpresion *, Context *);

    // Generar etiqueta específica según el tipo de nodo
    if (nodo->interpret == interpretDeclaracionVariable)
    {
        // Para declaraciones de variables, intentar obtener información específica
        snprintf(etiqueta, sizeof(etiqueta), "Declaración\\nVariable\\nL:%d C:%d\\nHijos: %zu",
                 nodo->linea, nodo->columna, nodo->numHijos);
    }
    else if (nodo->interpret == interpretDeclaracionConstante)
    {
        snprintf(etiqueta, sizeof(etiqueta), "Declaración\\nConstante\\nL:%d C:%d\\nHijos: %zu",
                 nodo->linea, nodo->columna, nodo->numHijos);
    }
    else if (nodo->interpret == interpretAsignacionVariable)
    {
        snprintf(etiqueta, sizeof(etiqueta), "Asignación\\nVariable\\nL:%d C:%d\\nHijos: %zu",
                 nodo->linea, nodo->columna, nodo->numHijos);
    }
    else if (nodo->interpret == interpretFuncionExpresion)
    {
        snprintf(etiqueta, sizeof(etiqueta), "Función\\nDefinición\\nL:%d C:%d\\nHijos: %zu",
                 nodo->linea, nodo->columna, nodo->numHijos);
    }
    else if (nodo->interpret == interpretPrimitivoExpresion)
    {
        // Para primitivos, intentar mostrar el tipo
        snprintf(etiqueta, sizeof(etiqueta), "Primitivo\\nValor Literal\\nL:%d C:%d",
                 nodo->linea, nodo->columna);
    }
    else if (nodo->interpret == interpretIdentificadorExpresion)
    {
        snprintf(etiqueta, sizeof(etiqueta), "Identificador\\nVariable/Func\\nL:%d C:%d",
                 nodo->linea, nodo->columna);
    }
    else if (nodo->numHijos == 0)
    {
        snprintf(etiqueta, sizeof(etiqueta), "Terminal\\nHoja\\nL:%d C:%d",
                 nodo->linea, nodo->columna);
    }
    else if (nodo->numHijos > 20)
    {
        snprintf(etiqueta, sizeof(etiqueta), "Lista\\nInstrucciones\\nL:%d C:%d\\nHijos: %zu",
                 nodo->linea, nodo->columna, nodo->numHijos);
    }
    else if (nodo->numHijos == 2)
    {
        snprintf(etiqueta, sizeof(etiqueta), "Expresión\\nBinaria\\nL:%d C:%d\\nHijos: %zu",
                 nodo->linea, nodo->columna, nodo->numHijos);
    }
    else if (nodo->numHijos == 1)
    {
        snprintf(etiqueta, sizeof(etiqueta), "Expresión\\nUnaria\\nL:%d C:%d\\nHijos: %zu",
                 nodo->linea, nodo->columna, nodo->numHijos);
    }
    else
    {
        snprintf(etiqueta, sizeof(etiqueta), "Nodo\\nComplejo\\nL:%d C:%d\\nHijos: %zu",
                 nodo->linea, nodo->columna, nodo->numHijos);
    }

    // Asegurar que la cadena esté terminada correctamente
    etiqueta[sizeof(etiqueta) - 1] = '\0';

    return etiqueta;
}

/**
 * Asigna un color al nodo según su tipo específico
 */
const char *obtenerColorNodo(AbstractExpresion *nodo)
{
    if (!nodo)
    {
        return "lightgray";
    }

    // Declaraciones externas para acceso a funciones
    extern Result interpretDeclaracionVariable(AbstractExpresion *, Context *);
    extern Result interpretDeclaracionConstante(AbstractExpresion *, Context *);
    extern Result interpretAsignacionVariable(AbstractExpresion *, Context *);
    extern Result interpretFuncionExpresion(AbstractExpresion *, Context *);
    extern Result interpretPrintExpresion(AbstractExpresion *, Context *);
    extern Result interpretReturnExpresion(AbstractExpresion *, Context *);
    extern Result interpretPrimitivoExpresion(AbstractExpresion *, Context *);
    extern Result interpretIdentificadorExpresion(AbstractExpresion *, Context *);
    extern Result interpretInstrucciones(AbstractExpresion *, Context *);

    // Colores específicos por tipo de nodo
    if (nodo->interpret == interpretDeclaracionVariable)
        return "lightcyan"; // Azul claro para declaraciones de variables
    else if (nodo->interpret == interpretDeclaracionConstante)
        return "lightsteelblue"; // Azul acero para constantes
    else if (nodo->interpret == interpretAsignacionVariable)
        return "lightpink"; // Rosa para asignaciones
    else if (nodo->interpret == interpretFuncionExpresion)
        return "lightgoldenrodyellow"; // Amarillo para funciones
    else if (nodo->interpret == interpretPrintExpresion)
        return "lightgreen"; // Verde para print
    else if (nodo->interpret == interpretReturnExpresion)
        return "lightsalmon"; // Salmón para return
    else if (nodo->interpret == interpretPrimitivoExpresion)
        return "lightblue"; // Azul para primitivos
    else if (nodo->interpret == interpretIdentificadorExpresion)
        return "lightcoral"; // Coral para identificadores
    else if (nodo->interpret == interpretInstrucciones)
        return "lightyellow"; // Amarillo claro para listas de instrucciones

    // Colores por estructura para casos no identificados
    else if (nodo->numHijos == 0)
        return "lightblue"; // Nodos terminales
    else if (nodo->numHijos == 1)
        return "lightseagreen"; // Operaciones unarias
    else if (nodo->numHijos == 2)
        return "lightsalmon"; // Operaciones binarias
    else if (nodo->numHijos == 3)
        return "lightviolet"; // Operaciones ternarias
    else if (nodo->numHijos > 10)
        return "wheat"; // Nodos complejos
    else
        return "lightgray"; // Por defecto
}

/**
 * Convierte un archivo DOT a imagen usando Graphviz
 */
void convertirDOTaImagen(const char *archivoDOT, const char *archivoImagen)
{
    if (!archivoDOT || !archivoImagen)
    {
        printf("Error: Parámetros inválidos para conversión\n");
        return;
    }

    char comando[512];
    snprintf(comando, sizeof(comando), "dot -Tpng \"%s\" -o \"%s\" 2>/dev/null", archivoDOT, archivoImagen);

    printf("Ejecutando: dot -Tpng %s -o %s\n", archivoDOT, archivoImagen);

    int resultado = system(comando);

    if (resultado == 0)
    {
        printf("✓ Imagen AST generada exitosamente: %s\n", archivoImagen);
    }
    else
    {
        printf("⚠ Error al generar la imagen. Verificando Graphviz...\n");

        // Verificar si Graphviz está instalado
        int checkGraphviz = system("which dot > /dev/null 2>&1");
        if (checkGraphviz != 0)
        {
            printf("✗ Graphviz no está instalado.\n");
            printf("Para instalar Graphviz:\n");
            printf("  Ubuntu/Debian: sudo apt-get install graphviz\n");
            printf("  CentOS/RHEL:   sudo yum install graphviz\n");
            printf("  Arch Linux:    sudo pacman -S graphviz\n");
            printf("  macOS:         brew install graphviz\n");
        }
        else
        {
            printf("✓ Graphviz está instalado, pero hubo un error en la conversión.\n");
            printf("  Verifica que el archivo DOT sea válido: %s\n", archivoDOT);
        }
    }
}

// ============================================================================
// FUNCIONES PARA EXTRAER INFORMACIÓN ESPECÍFICA DE NODOS
// ============================================================================

/**
 * Convierte un TipoDato a string legible
 */
const char *obtenerTipoDatoString(TipoDato tipo)
{
    switch (tipo)
    {
    case VOID:
        return "void";
    case BOOLEAN:
        return "boolean";
    case CHAR:
        return "char";
    case INT:
        return "int";
    case FLOAT:
        return "float";
    case DOUBLE:
        return "double";
    case STRING:
        return "String";
    case ARRAY:
        return "Array";
    case MATRIX:
        return "Matrix";
    case NULO:
        return "null";
    default:
        return "unknown";
    }
}

/**
 * Extrae información específica de nodos de declaración
 */
const char *obtenerInformacionDeclaracion(AbstractExpresion *nodo)
{
    static char info[256];

    if (!nodo)
    {
        strcpy(info, "");
        return info;
    }

    // Solo intentar extraer información si hay suficientes indicios
    // Por ejemplo, si tiene exactamente 1 hijo (expresión inicial)
    if (nodo->numHijos == 1)
    {
        snprintf(info, sizeof(info), "Declaración\\nHijos: %zu", nodo->numHijos);
        return info;
    }

    strcpy(info, "");
    return info;
}

/**
 * Extrae información específica de nodos primitivos
 */
const char *obtenerInformacionPrimitivo(AbstractExpresion *nodo)
{
    static char info[256];

    if (!nodo)
    {
        strcpy(info, "");
        return info;
    }

    // Solo si es un nodo terminal (0 hijos) podría ser primitivo
    if (nodo->numHijos == 0)
    {
        snprintf(info, sizeof(info), "Terminal\\nPrimitivo");
        return info;
    }

    strcpy(info, "");
    return info;
}

/**
 * Extrae información específica de nodos identificador
 */
const char *obtenerInformacionIdentificador(AbstractExpresion *nodo)
{
    static char info[256];

    if (!nodo)
    {
        strcpy(info, "");
        return info;
    }

    // Solo si es un nodo terminal podría ser identificador
    if (nodo->numHijos == 0)
    {
        snprintf(info, sizeof(info), "Terminal\\nIdentificador");
        return info;
    }

    strcpy(info, "");
    return info;
}

/**
 * Extrae información específica de nodos de asignación
 */
const char *obtenerInformacionAsignacion(AbstractExpresion *nodo)
{
    static char info[256];

    if (!nodo)
    {
        strcpy(info, "");
        return info;
    }

    // Solo si tiene exactamente 1 hijo (expresión a asignar) podría ser asignación
    if (nodo->numHijos == 1)
    {
        snprintf(info, sizeof(info), "Asignación\\nExpresión");
        return info;
    }

    strcpy(info, "");
    return info;
}

/**
 * Extrae información específica de operadores aritméticos
 */
const char *obtenerInformacionOperador(AbstractExpresion *nodo)
{
    static char info[256];

    if (!nodo)
    {
        strcpy(info, "");
        return info;
    }

    // Basándose en el número de hijos, determinar el tipo de operador
    if (nodo->numHijos == 2)
    {
        strcpy(info, "Operador\\nBinario");
    }
    else if (nodo->numHijos == 1)
    {
        strcpy(info, "Operador\\nUnario");
    }
    else if (nodo->numHijos == 3)
    {
        strcpy(info, "Operador\\nTernario");
    }
    else
    {
        strcpy(info, "Operador");
    }

    return info;
}

/**
 * Extrae información específica de nodos de función
 */
const char *obtenerInformacionFuncion(AbstractExpresion *nodo)
{
    static char info[256];

    if (!nodo)
    {
        strcpy(info, "");
        return info;
    }

    // Esta implementación es básica, se puede mejorar cuando se tenga
    // acceso a la estructura específica de FuncionExpresion
    snprintf(info, sizeof(info), "Función\\nParams: %zu", nodo->numHijos);

    return info;
}