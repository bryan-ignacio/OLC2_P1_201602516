#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "context/error_report.h"
#include "matrix.h"
#include "array.h" // Para usar obtenerValorDefecto

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Función para crear una matriz
MatrixStruct *crearMatrix(TipoDato tipoElemento, int filas, int columnas)
{
    MatrixStruct *matrix = malloc(sizeof(MatrixStruct));
    matrix->tipoElemento = tipoElemento;
    matrix->filas = filas;
    matrix->columnas = columnas;

    // Asignar memoria para las filas
    matrix->elementos = malloc(sizeof(void **) * filas);

    // Inicializar cada fila y sus elementos
    for (int i = 0; i < filas; i++)
    {
        matrix->elementos[i] = malloc(sizeof(void *) * columnas);
        for (int j = 0; j < columnas; j++)
        {
            matrix->elementos[i][j] = obtenerValorDefecto(tipoElemento);
        }
    }

    return matrix;
}

// Función para liberar una matriz
void liberarMatrix(MatrixStruct *matrix)
{
    if (matrix)
    {
        if (matrix->elementos)
        {
            for (int i = 0; i < matrix->filas; i++)
            {
                if (matrix->elementos[i])
                {
                    for (int j = 0; j < matrix->columnas; j++)
                    {
                        if (matrix->elementos[i][j])
                        {
                            free(matrix->elementos[i][j]);
                        }
                    }
                    free(matrix->elementos[i]);
                }
            }
            free(matrix->elementos);
        }
        free(matrix);
    }
}

Result interpretDeclaracionMatrixNewExpresion(AbstractExpresion *self, Context *context)
{
    DeclaracionMatrixNewExpresion *nodo = (DeclaracionMatrixNewExpresion *)self;

    // Evaluar la expresión de filas (primer hijo)
    AbstractExpresion *expresionFilas = self->hijos[0];
    Result resultFilas = expresionFilas->interpret(expresionFilas, context);

    // Evaluar la expresión de columnas (segundo hijo)
    AbstractExpresion *expresionColumnas = self->hijos[1];
    Result resultColumnas = expresionColumnas->interpret(expresionColumnas, context);

    // Verificar que ambas dimensiones sean enteros
    if (resultFilas.tipo != INT)
    {
        int ambito = context ? context->nombre : 0;
        agregarErrorSemantico("El número de filas debe ser un entero",
                              nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    if (resultColumnas.tipo != INT)
    {
        int ambito = context ? context->nombre : 0;
        agregarErrorSemantico("El número de columnas debe ser un entero",
                              nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    int filas = *((int *)resultFilas.valor);
    int columnas = *((int *)resultColumnas.valor);

    // Verificar que las dimensiones sean positivas
    if (filas < 0)
    {
        int ambito = context ? context->nombre : 0;
        agregarErrorSemantico("El número de filas debe ser positivo",
                              nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    if (columnas < 0)
    {
        int ambito = context ? context->nombre : 0;
        agregarErrorSemantico("El número de columnas debe ser positivo",
                              nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Crear la matriz
    MatrixStruct *matrix = crearMatrix(nodo->tipoElemento, filas, columnas);

    // Crear un Symbol para la matriz
    Symbol *simboloMatrix = nuevoVariable(nodo->identificador, matrix, MATRIX, nodo->base.linea, nodo->base.columna, context ? context->nombre : 0);

    // Agregar la matriz al contexto
    agregarSymbol(context, simboloMatrix);

    return nuevoValorResultadoVacio();
}

Result interpretDeclaracionMatrixInitExpresion(AbstractExpresion *self, Context *context)
{
    DeclaracionMatrixInitExpresion *nodo = (DeclaracionMatrixInitExpresion *)self;

    // La lista de filas es el primer hijo
    AbstractExpresion *listaFilas = self->hijos[0];

    int numFilas = listaFilas->numHijos;
    if (numFilas == 0)
    {
        int ambito = context ? context->nombre : 0;
        agregarErrorSemantico("La matriz debe tener al menos una fila",
                              nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Obtener el número de columnas de la primera fila
    AbstractExpresion *primeraFila = listaFilas->hijos[0];
    int numColumnas = primeraFila->numHijos;

    // Verificar que todas las filas tengan el mismo número de columnas
    for (size_t i = 1; i < listaFilas->numHijos; i++)
    {
        if ((int)listaFilas->hijos[i]->numHijos != numColumnas)
        {
            int ambito = context ? context->nombre : 0;
            char buffer[256];
            snprintf(buffer, sizeof(buffer),
                     "Todas las filas deben tener el mismo número de columnas. Fila %zu tiene %zu columnas, esperado %d",
                     i, listaFilas->hijos[i]->numHijos, numColumnas);
            agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
            return nuevoValorResultadoVacio();
        }
    }

    // Crear matriz del tamaño determinado
    MatrixStruct *matrix = crearMatrix(nodo->tipoElemento, numFilas, numColumnas);

    // Evaluar cada elemento y asignarlo a la matriz
    for (int i = 0; i < numFilas; i++)
    {
        AbstractExpresion *fila = listaFilas->hijos[i];
        for (int j = 0; j < numColumnas; j++)
        {
            Result resultElemento = fila->hijos[j]->interpret(fila->hijos[j], context);

            // Verificar compatibilidad de tipos
            if (resultElemento.tipo != nodo->tipoElemento)
            {
                int ambito = context ? context->nombre : 0;
                char buffer[256];
                snprintf(buffer, sizeof(buffer),
                         "Tipo incompatible en elemento [%d][%d]: esperado %s, recibido %s",
                         i, j, labelTipoDato[nodo->tipoElemento], labelTipoDato[resultElemento.tipo]);
                agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
                liberarMatrix(matrix);
                return nuevoValorResultadoVacio();
            }

            // Liberar el valor por defecto y asignar el nuevo valor
            free(matrix->elementos[i][j]);
            matrix->elementos[i][j] = resultElemento.valor;
        }
    }

    // Crear un Symbol para la matriz
    Symbol *simboloMatrix = nuevoVariable(nodo->identificador, matrix, MATRIX, nodo->base.linea, nodo->base.columna, context ? context->nombre : 0);

    // Agregar la matriz al contexto
    agregarSymbol(context, simboloMatrix);

    return nuevoValorResultadoVacio();
}

Result interpretAccesoMatrixExpresion(AbstractExpresion *self, Context *context)
{
    AccesoMatrixExpresion *nodo = (AccesoMatrixExpresion *)self;

    // Buscar la matriz en el contexto
    Symbol *simbolo = buscarTablaSimbolos(context, nodo->identificador);
    if (!simbolo)
    {
        int ambito = context ? context->nombre : 0;
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Matriz '%s' no declarada", nodo->identificador);
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    if (simbolo->tipo != MATRIX)
    {
        int ambito = context ? context->nombre : 0;
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "'%s' no es una matriz", nodo->identificador);
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    MatrixStruct *matrix = (MatrixStruct *)simbolo->valor;

    // Evaluar el índice de fila (primer hijo)
    AbstractExpresion *expresionFila = self->hijos[0];
    Result resultFila = expresionFila->interpret(expresionFila, context);

    // Evaluar el índice de columna (segundo hijo)
    AbstractExpresion *expresionColumna = self->hijos[1];
    Result resultColumna = expresionColumna->interpret(expresionColumna, context);

    if (resultFila.tipo != INT)
    {
        int ambito = context ? context->nombre : 0;
        agregarErrorSemantico("El índice de fila debe ser un entero",
                              nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    if (resultColumna.tipo != INT)
    {
        int ambito = context ? context->nombre : 0;
        agregarErrorSemantico("El índice de columna debe ser un entero",
                              nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    int fila = *((int *)resultFila.valor);
    int columna = *((int *)resultColumna.valor);

    // Verificar que los índices estén en rango
    if (fila < 0 || fila >= matrix->filas)
    {
        int ambito = context ? context->nombre : 0;
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
                 "Índice de fila fuera de rango: %d. Rango válido: 0 a %d",
                 fila, matrix->filas - 1);
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    if (columna < 0 || columna >= matrix->columnas)
    {
        int ambito = context ? context->nombre : 0;
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
                 "Índice de columna fuera de rango: %d. Rango válido: 0 a %d",
                 columna, matrix->columnas - 1);
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Retornar el elemento en la posición especificada
    return nuevoValorResultado(matrix->elementos[fila][columna], matrix->tipoElemento);
}

Result interpretAsignacionMatrixExpresion(AbstractExpresion *self, Context *context)
{
    AsignacionMatrixExpresion *nodo = (AsignacionMatrixExpresion *)self;

    // Buscar la matriz en el contexto
    Symbol *simbolo = buscarTablaSimbolos(context, nodo->identificador);
    if (!simbolo)
    {
        int ambito = context ? context->nombre : 0;
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Matriz '%s' no declarada", nodo->identificador);
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    if (simbolo->tipo != MATRIX)
    {
        int ambito = context ? context->nombre : 0;
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "'%s' no es una matriz", nodo->identificador);
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    MatrixStruct *matrix = (MatrixStruct *)simbolo->valor;

    // Evaluar el índice de fila (primer hijo)
    AbstractExpresion *expresionFila = self->hijos[0];
    Result resultFila = expresionFila->interpret(expresionFila, context);

    // Evaluar el índice de columna (segundo hijo)
    AbstractExpresion *expresionColumna = self->hijos[1];
    Result resultColumna = expresionColumna->interpret(expresionColumna, context);

    // Evaluar el nuevo valor (tercer hijo)
    AbstractExpresion *expresionValor = self->hijos[2];
    Result resultValor = expresionValor->interpret(expresionValor, context);

    if (resultFila.tipo != INT)
    {
        int ambito = context ? context->nombre : 0;
        agregarErrorSemantico("El índice de fila debe ser un entero",
                              nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    if (resultColumna.tipo != INT)
    {
        int ambito = context ? context->nombre : 0;
        agregarErrorSemantico("El índice de columna debe ser un entero",
                              nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    int fila = *((int *)resultFila.valor);
    int columna = *((int *)resultColumna.valor);

    // Verificar que los índices estén en rango
    if (fila < 0 || fila >= matrix->filas)
    {
        int ambito = context ? context->nombre : 0;
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
                 "Índice de fila fuera de rango: %d. Rango válido: 0 a %d",
                 fila, matrix->filas - 1);
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    if (columna < 0 || columna >= matrix->columnas)
    {
        int ambito = context ? context->nombre : 0;
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
                 "Índice de columna fuera de rango: %d. Rango válido: 0 a %d",
                 columna, matrix->columnas - 1);
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Verificar compatibilidad de tipos
    if (resultValor.tipo != matrix->tipoElemento)
    {
        int ambito = context ? context->nombre : 0;
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
                 "Tipo incompatible: esperado %s, recibido %s",
                 labelTipoDato[matrix->tipoElemento], labelTipoDato[resultValor.tipo]);
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Liberar el valor anterior y asignar el nuevo
    if (matrix->elementos[fila][columna])
    {
        free(matrix->elementos[fila][columna]);
    }
    matrix->elementos[fila][columna] = resultValor.valor;

    return nuevoValorResultadoVacio();
}

Result interpretListaFilasExpresion(AbstractExpresion *self, Context *context)
{
    // Esta función no se ejecuta directamente, solo sirve como contenedor
    (void)self;
    (void)context;
    return nuevoValorResultadoVacio();
}

// Funciones constructoras
AbstractExpresion *nuevoDeclaracionMatrixNew(TipoDato tipoMatrix, char *identificador, TipoDato tipoElemento, AbstractExpresion *filas, AbstractExpresion *columnas, int linea, int columna)
{
    DeclaracionMatrixNewExpresion *nodo = malloc(sizeof(DeclaracionMatrixNewExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretDeclaracionMatrixNewExpresion);
    nodo->tipoMatrix = tipoMatrix;
    nodo->tipoElemento = tipoElemento;
    nodo->identificador = strdup(identificador);
    nodo->linea = linea;
    nodo->columna = columna;

    agregarHijo((AbstractExpresion *)nodo, filas);
    agregarHijo((AbstractExpresion *)nodo, columnas);

    return (AbstractExpresion *)nodo;
}

AbstractExpresion *nuevoDeclaracionMatrixInit(TipoDato tipoMatrix, char *identificador, AbstractExpresion *listaFilas, int linea, int columna)
{
    DeclaracionMatrixInitExpresion *nodo = malloc(sizeof(DeclaracionMatrixInitExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretDeclaracionMatrixInitExpresion);
    nodo->tipoMatrix = tipoMatrix;
    nodo->tipoElemento = tipoMatrix; // En declaraciones con init, el tipo de la matriz es el tipo de elemento
    nodo->identificador = strdup(identificador);
    nodo->linea = linea;
    nodo->columna = columna;

    agregarHijo((AbstractExpresion *)nodo, listaFilas);

    return (AbstractExpresion *)nodo;
}

AbstractExpresion *nuevoAccesoMatrixExpresion(char *identificador, AbstractExpresion *fila, AbstractExpresion *columna, int linea, int columna_pos)
{
    AccesoMatrixExpresion *nodo = malloc(sizeof(AccesoMatrixExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretAccesoMatrixExpresion);
    nodo->identificador = strdup(identificador);
    nodo->linea = linea;
    nodo->columna = columna_pos;

    agregarHijo((AbstractExpresion *)nodo, fila);
    agregarHijo((AbstractExpresion *)nodo, columna);

    return (AbstractExpresion *)nodo;
}

AbstractExpresion *nuevoAsignacionMatrixExpresion(char *identificador, AbstractExpresion *fila, AbstractExpresion *columna, AbstractExpresion *valor, int linea, int columna_pos)
{
    AsignacionMatrixExpresion *nodo = malloc(sizeof(AsignacionMatrixExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretAsignacionMatrixExpresion);
    nodo->identificador = strdup(identificador);
    nodo->linea = linea;
    nodo->columna = columna_pos;

    // Agregar los hijos: fila, columna y valor
    agregarHijo((AbstractExpresion *)nodo, fila);
    agregarHijo((AbstractExpresion *)nodo, columna);
    agregarHijo((AbstractExpresion *)nodo, valor);

    return (AbstractExpresion *)nodo;
}

AbstractExpresion *nuevoListaFilas()
{
    ListaFilasExpresion *nodo = malloc(sizeof(ListaFilasExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretListaFilasExpresion);

    return (AbstractExpresion *)nodo;
}