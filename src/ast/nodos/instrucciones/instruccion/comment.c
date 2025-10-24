#include "comment.h"
#include "../../builders.h"
#include "../../../../context/result.h"
#include <stdlib.h>
#include <string.h>

typedef struct
{
    AbstractExpresion base;
    char *text;
    int is_block;
} CommentExpresion;

Result interpretComentario(AbstractExpresion *self, Context *context)
{
    (void)self;
    (void)context;
    // Los comentarios no producen efecto en tiempo de ejecución.
    return nuevoValorResultadoVacio();
}

AbstractExpresion *nuevoComentarioExpresion(char *text, int is_block, int linea, int columna)
{
    CommentExpresion *nodo = malloc(sizeof(CommentExpresion));
    if (!nodo)
        return NULL;

    buildAbstractExpresion(&nodo->base, interpretComentario);
    nodo->text = text; // tomar ownership del puntero strdup() provisto por el lexer
    nodo->is_block = is_block;
    nodo->base.linea = linea;
    nodo->base.columna = columna;

    return (AbstractExpresion *)nodo;
}

const char *comment_get_text(AbstractExpresion *nodo)
{
    if (!nodo)
        return NULL;
    CommentExpresion *c = (CommentExpresion *)nodo;
    return c->text;
}

int comment_get_is_block(AbstractExpresion *nodo)
{
    if (!nodo)
        return 0;
    CommentExpresion *c = (CommentExpresion *)nodo;
    return c->is_block;
}
