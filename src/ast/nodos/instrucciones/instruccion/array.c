#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "context/error_report.h"
#include "array.h"
#include "declaracion.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Función para obtener valor por defecto según el tipo
void *obtenerValorDefecto(TipoDato tipo)
{
    switch (tipo)
    {
    case INT:
    {
        int *valor = malloc(sizeof(int));
        *valor = 0;
        return valor;
    }
    case FLOAT:
    {
        float *valor = malloc(sizeof(float));
        *valor = 0.0f;
        return valor;
    }
    case DOUBLE:
    {
        double *valor = malloc(sizeof(double));
        *valor = 0.0;
        return valor;
    }
    case BOOLEAN:
    {
        bool *valor = malloc(sizeof(bool));
        *valor = false;
        return valor;
    }
    case CHAR:
    {
        char *valor = malloc(sizeof(char));
        *valor = '\0';
        return valor;
    }
    case STRING:
    {
        char **valor = malloc(sizeof(char *));
        *valor = strdup("");
        return valor;
    }
    default:
        return NULL;
    }
}

// Función para crear un array
ArrayStruct *crearArray(TipoDato tipoElemento, int tamaño)
{
    ArrayStruct *array = malloc(sizeof(ArrayStruct));
    array->tipoElemento = tipoElemento;
    array->tamaño = tamaño;
    array->elementos = malloc(sizeof(void *) * tamaño);

    // Inicializar todos los elementos con valores por defecto
    for (int i = 0; i < tamaño; i++)
    {
        array->elementos[i] = obtenerValorDefecto(tipoElemento);
    }

    return array;
}

// Función para liberar un array
void liberarArray(ArrayStruct *array)
{
    if (array)
    {
        if (array->elementos)
        {
            for (int i = 0; i < array->tamaño; i++)
            {
                if (array->elementos[i])
                {
                    free(array->elementos[i]);
                }
            }
            free(array->elementos);
        }
        free(array);
    }
}

Result interpretDeclaracionArrayNewExpresion(AbstractExpresion *self, Context *context)
{
    DeclaracionArrayNewExpresion *nodo = (DeclaracionArrayNewExpresion *)self;

    // Evaluar la expresión del tamaño
    AbstractExpresion *expresionTamaño = self->hijos[0];
    Result resultTamaño = expresionTamaño->interpret(expresionTamaño, context);

    // Verificar que el tamaño sea un entero
    if (resultTamaño.tipo != INT)
    {
        int ambito = context ? context->nombre : 0;
        agregarErrorSemantico("El tamaño del array debe ser un entero",
                              nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    int tamaño = *((int *)resultTamaño.valor);

    // Verificar que el tamaño sea positivo
    if (tamaño < 0)
    {
        int ambito = context ? context->nombre : 0;
        agregarErrorSemantico("El tamaño del array debe ser positivo",
                              nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Crear el array
    ArrayStruct *array = crearArray(nodo->tipoElemento, tamaño);

    // Crear un Symbol para el array
    Symbol *simboloArray = nuevoVariable(nodo->identificador, array, ARRAY, nodo->base.linea, nodo->base.columna, context ? context->nombre : 0);

    // Agregar el array al contexto
    agregarSymbol(context, simboloArray);

    return nuevoValorResultadoVacio();
}

Result interpretDeclaracionArrayInitExpresion(AbstractExpresion *self, Context *context)
{
    DeclaracionArrayInitExpresion *nodo = (DeclaracionArrayInitExpresion *)self;

    // La lista de elementos es el primer hijo
    AbstractExpresion *listaElementos = self->hijos[0];

    // Crear array del tamaño de la lista de elementos
    ArrayStruct *array = crearArray(nodo->tipoElemento, listaElementos->numHijos);

    // Evaluar cada elemento y asignarlo al array
    for (size_t i = 0; i < listaElementos->numHijos; i++)
    {
        Result resultElemento = listaElementos->hijos[i]->interpret(listaElementos->hijos[i], context);

        // Verificar compatibilidad de tipos
        if (resultElemento.tipo != nodo->tipoElemento)
        {
            int ambito = context ? context->nombre : 0;
            char buffer[256];
            snprintf(buffer, sizeof(buffer),
                     "Tipo incompatible en elemento %zu: esperado %s, recibido %s",
                     i, labelTipoDato[nodo->tipoElemento], labelTipoDato[resultElemento.tipo]);
            agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
            liberarArray(array);
            return nuevoValorResultadoVacio();
        }

        // Liberar el valor por defecto y asignar el nuevo valor
        free(array->elementos[i]);
        array->elementos[i] = resultElemento.valor;
    }

    // Crear un Symbol para el array
    Symbol *simboloArray = nuevoVariable(nodo->identificador, array, ARRAY, nodo->base.linea, nodo->base.columna, context ? context->nombre : 0);

    // Agregar el array al contexto
    agregarSymbol(context, simboloArray);

    return nuevoValorResultadoVacio();
}

Result interpretAccesoArrayExpresion(AbstractExpresion *self, Context *context)
{
    AccesoArrayExpresion *nodo = (AccesoArrayExpresion *)self;

    // Buscar el array en el contexto
    Symbol *simbolo = buscarTablaSimbolos(context, nodo->identificador);
    if (!simbolo)
    {
        int ambito = context ? context->nombre : 0;
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Array '%s' no declarado", nodo->identificador);
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    if (simbolo->tipo != ARRAY)
    {
        int ambito = context ? context->nombre : 0;
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "'%s' no es un array", nodo->identificador);
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    ArrayStruct *array = (ArrayStruct *)simbolo->valor;

    // Evaluar el índice
    AbstractExpresion *expresionIndice = self->hijos[0];
    Result resultIndice = expresionIndice->interpret(expresionIndice, context);

    if (resultIndice.tipo != INT)
    {
        int ambito = context ? context->nombre : 0;
        agregarErrorSemantico("El índice del array debe ser un entero",
                              nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    int indice = *((int *)resultIndice.valor);

    // Verificar que el índice esté en rango
    if (indice < 0 || indice >= array->tamaño)
    {
        int ambito = context ? context->nombre : 0;
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
                 "Índice fuera de rango: %d. Rango válido: 0 a %d",
                 indice, array->tamaño - 1);
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Crear una copia del valor para evitar problemas de referencia
    void *valorCopia = NULL;

    switch (array->tipoElemento)
    {
    case INT:
    {
        int *original = (int *)array->elementos[indice];
        int *copia = malloc(sizeof(int));
        *copia = *original;
        valorCopia = copia;
        break;
    }
    case FLOAT:
    {
        float *original = (float *)array->elementos[indice];
        float *copia = malloc(sizeof(float));
        *copia = *original;
        valorCopia = copia;
        break;
    }
    case DOUBLE:
    {
        double *original = (double *)array->elementos[indice];
        double *copia = malloc(sizeof(double));
        *copia = *original;
        valorCopia = copia;
        break;
    }
    case STRING:
    {
        char *original = (char *)array->elementos[indice];
        if (original)
        {
            char *copia = malloc(strlen(original) + 1);
            strcpy(copia, original);
            valorCopia = copia;
        }
        else
        {
            valorCopia = NULL;
        }
        break;
    }
    case BOOLEAN:
    {
        bool *original = (bool *)array->elementos[indice];
        bool *copia = malloc(sizeof(bool));
        *copia = *original;
        valorCopia = copia;
        break;
    }
    case CHAR:
    {
        char *original = (char *)array->elementos[indice];
        char *copia = malloc(sizeof(char));
        *copia = *original;
        valorCopia = copia;
        break;
    }
    default:
        valorCopia = array->elementos[indice];
        break;
    }

    // Retornar el elemento copiado
    return nuevoValorResultado(valorCopia, array->tipoElemento);
}

Result interpretListaElementosExpresion(AbstractExpresion *self, Context *context)
{
    // Esta función no se ejecuta directamente, solo sirve como contenedor
    (void)self;
    (void)context;
    return nuevoValorResultadoVacio();
}

Result interpretAsignacionArrayExpresion(AbstractExpresion *self, Context *context)
{
    AsignacionArrayExpresion *nodo = (AsignacionArrayExpresion *)self;

    // Buscar el array en el contexto
    Symbol *simbolo = buscarTablaSimbolos(context, nodo->identificador);
    if (!simbolo)
    {
        int ambito = context ? context->nombre : 0;
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Array '%s' no declarado", nodo->identificador);
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    if (simbolo->tipo != ARRAY)
    {
        int ambito = context ? context->nombre : 0;
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "'%s' no es un array", nodo->identificador);
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    ArrayStruct *array = (ArrayStruct *)simbolo->valor;

    // Evaluar el índice (primer hijo)
    AbstractExpresion *expresionIndice = self->hijos[0];
    Result resultIndice = expresionIndice->interpret(expresionIndice, context);

    if (resultIndice.tipo != INT)
    {
        int ambito = context ? context->nombre : 0;
        agregarErrorSemantico("El índice del array debe ser un entero",
                              nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    int indice = *((int *)resultIndice.valor);

    // Verificar que el índice esté en rango
    if (indice < 0 || indice >= array->tamaño)
    {
        int ambito = context ? context->nombre : 0;
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
                 "Índice fuera de rango: %d. Rango válido: 0 a %d",
                 indice, array->tamaño - 1);
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Evaluar el nuevo valor (segundo hijo)
    AbstractExpresion *expresionValor = self->hijos[1];
    Result resultValor = expresionValor->interpret(expresionValor, context);

    // Verificar compatibilidad de tipos
    if (resultValor.tipo != array->tipoElemento)
    {
        int ambito = context ? context->nombre : 0;
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
                 "Tipo incompatible: esperado %s, recibido %s",
                 labelTipoDato[array->tipoElemento], labelTipoDato[resultValor.tipo]);
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Para strings, necesitamos crear una copia para evitar problemas de memoria
    if (resultValor.tipo == STRING)
    {
        // Liberar el valor anterior
        if (array->elementos[indice])
        {
            free(array->elementos[indice]);
        }
        // Crear una copia del string
        char *valorString = (char *)resultValor.valor;
        char *copia = malloc(strlen(valorString) + 1);
        strcpy(copia, valorString);
        array->elementos[indice] = copia;
    }
    else
    {
        // Para tipos primitivos, podemos reutilizar el puntero sin liberar
        // Esto evita problemas cuando intercambiamos valores
        if (array->elementos[indice])
        {
            free(array->elementos[indice]);
        }
        array->elementos[indice] = resultValor.valor;
    }

    return nuevoValorResultadoVacio();
}

// Función para intercambiar elementos de array sin liberar memoria
Result intercambiarElementosArray(char *identificador, int indice1, int indice2, Context *context)
{
    Symbol *simbolo = buscarTablaSimbolos(context, identificador);
    if (!simbolo || simbolo->tipo != ARRAY)
    {
        return nuevoValorResultadoVacio();
    }

    ArrayStruct *array = (ArrayStruct *)simbolo->valor;

    // Verificar índices válidos
    if (indice1 < 0 || indice1 >= array->tamaño || indice2 < 0 || indice2 >= array->tamaño)
    {
        return nuevoValorResultadoVacio();
    }

    // Intercambiar punteros directamente sin liberar memoria
    void *temp = array->elementos[indice1];
    array->elementos[indice1] = array->elementos[indice2];
    array->elementos[indice2] = temp;

    return nuevoValorResultadoVacio();
}

AbstractExpresion *nuevoDeclaracionArrayNew(TipoDato tipoArray, char *identificador, TipoDato tipoElemento, AbstractExpresion *tamaño, int linea, int columna)
{
    DeclaracionArrayNewExpresion *nodo = malloc(sizeof(DeclaracionArrayNewExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretDeclaracionArrayNewExpresion);
    nodo->tipoArray = tipoArray;
    nodo->tipoElemento = tipoElemento;
    nodo->identificador = strdup(identificador);
    nodo->linea = linea;
    nodo->columna = columna;

    agregarHijo((AbstractExpresion *)nodo, tamaño);

    return (AbstractExpresion *)nodo;
}

AbstractExpresion *nuevoDeclaracionArrayInit(TipoDato tipoArray, char *identificador, AbstractExpresion *listaElementos, int linea, int columna)
{
    DeclaracionArrayInitExpresion *nodo = malloc(sizeof(DeclaracionArrayInitExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretDeclaracionArrayInitExpresion);
    nodo->tipoArray = tipoArray;
    nodo->tipoElemento = tipoArray; // En declaraciones con init, el tipo del array es el tipo de elemento
    nodo->identificador = strdup(identificador);
    nodo->linea = linea;
    nodo->columna = columna;

    agregarHijo((AbstractExpresion *)nodo, listaElementos);

    return (AbstractExpresion *)nodo;
}

AbstractExpresion *nuevoAccesoArrayExpresion(char *identificador, AbstractExpresion *indice, int linea, int columna)
{
    AccesoArrayExpresion *nodo = malloc(sizeof(AccesoArrayExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretAccesoArrayExpresion);
    nodo->identificador = strdup(identificador);
    nodo->linea = linea;
    nodo->columna = columna;

    agregarHijo((AbstractExpresion *)nodo, indice);

    return (AbstractExpresion *)nodo;
}

AbstractExpresion *nuevoListaElementos()
{
    ListaElementosExpresion *nodo = malloc(sizeof(ListaElementosExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretListaElementosExpresion);

    extern int yylineno;
    extern int yycolumn;
    nodo->base.linea = yylineno;
    nodo->base.columna = yycolumn;

    return (AbstractExpresion *)nodo;
}

AbstractExpresion *nuevoAsignacionArrayExpresion(char *identificador, AbstractExpresion *indice, AbstractExpresion *valor, int linea, int columna)
{
    AsignacionArrayExpresion *nodo = malloc(sizeof(AsignacionArrayExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretAsignacionArrayExpresion);
    nodo->identificador = strdup(identificador);
    nodo->linea = linea;
    nodo->columna = columna;

    // Agregar los hijos: índice y valor
    agregarHijo((AbstractExpresion *)nodo, indice);
    agregarHijo((AbstractExpresion *)nodo, valor);

    return (AbstractExpresion *)nodo;
}

// Implementación para declaración de array con expresión
Result interpretDeclaracionArrayExpresion(AbstractExpresion *self, Context *context)
{
    DeclaracionArrayExpresion *nodo = (DeclaracionArrayExpresion *)self;

    // Evaluar la expresión que debe devolver un array
    AbstractExpresion *expresion = self->hijos[0];
    Result resultExpresion = expresion->interpret(expresion, context);

    if (resultExpresion.tipo == NULO)
    {
        int ambito = context ? context->nombre : 0;
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Error al evaluar la expresión en declaración de array '%s'", nodo->identificador);
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Verificar que el resultado sea un array
    if (resultExpresion.tipo != ARRAY)
    {
        int ambito = context ? context->nombre : 0;
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "La expresión no devuelve un array en declaración de '%s'", nodo->identificador);
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Obtener el array resultante
    ArrayStruct *arrayResultante = (ArrayStruct *)resultExpresion.valor;
    if (!arrayResultante)
    {
        int ambito = context ? context->nombre : 0;
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Array inválido en declaración de '%s'", nodo->identificador);
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Verificar compatibilidad de tipos
    if (arrayResultante->tipoElemento != nodo->tipoArray)
    {
        int ambito = context ? context->nombre : 0;
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Tipo incompatible en declaración de array '%s': esperado %s, recibido %s",
                 nodo->identificador, labelTipoDato[nodo->tipoArray], labelTipoDato[arrayResultante->tipoElemento]);
        agregarErrorSemantico(buffer, nodo->linea, nodo->columna, ambito);
        return nuevoValorResultadoVacio();
    }

    // Crear el símbolo en la tabla de símbolos
    Symbol *simboloArray = nuevoVariable(nodo->identificador, arrayResultante, ARRAY, nodo->linea, nodo->columna, context ? context->nombre : 0);
    agregarSymbol(context, simboloArray);

    return nuevoValorResultadoVacio();
}

AbstractExpresion *nuevoDeclaracionArrayExpresion(TipoDato tipoArray, char *identificador, AbstractExpresion *expresion, int linea, int columna)
{
    DeclaracionArrayExpresion *nodo = malloc(sizeof(DeclaracionArrayExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretDeclaracionArrayExpresion);
    nodo->tipoArray = tipoArray;
    nodo->identificador = strdup(identificador);
    nodo->linea = linea;
    nodo->columna = columna;

    agregarHijo((AbstractExpresion *)nodo, expresion);

    return (AbstractExpresion *)nodo;
}

// Función para declarar arrays como parámetros de función
// Función para interpretar declaración de parámetros de array
Result interpretDeclaracionArrayParametro(AbstractExpresion *nodo, Context *context)
{
    DeclaracionVariable *self = (DeclaracionVariable *)nodo;

    // Para parámetros de array, solo creamos el símbolo sin inicializar
    // El valor se asignará cuando se llame la función
    Symbol *var = nuevoVariable(self->nombre, NULL, ARRAY, nodo->linea, nodo->columna, context ? context->nombre : 0);
    var->nodo = nodo;
    agregarSymbol(context, var);

    return nuevoValorResultadoVacio();
}

AbstractExpresion *nuevoDeclaracionArrayParametro(TipoDato tipoElemento, char *identificador, int linea, int columna)
{
    // Para parámetros de array, usamos la misma estructura que DeclaracionVariable
    // pero marcándola como ARRAY en lugar del tipo primitivo
    DeclaracionVariable *nodo = malloc(sizeof(DeclaracionVariable));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretDeclaracionArrayParametro);
    nodo->tipo = ARRAY; // Marcar como tipo ARRAY
    nodo->nombre = strdup(identificador);
    nodo->base.linea = linea;
    nodo->base.columna = columna;

    return (AbstractExpresion *)nodo;
}