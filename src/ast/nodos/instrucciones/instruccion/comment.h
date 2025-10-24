#ifndef COMMENT_H
#define COMMENT_H

#include "../../../../ast/AbstractExpresion.h"

// Crea un nodo de comentario. El generador tomará responsabilidad sobre la cadena 'text'.
AbstractExpresion *nuevoComentarioExpresion(char *text, int is_block, int linea, int columna);

// Accesores para el nodo de comentario
// Devuelven el texto del comentario (propiedad del nodo, no liberar) y 1 si es bloque, 0 si es línea
const char *comment_get_text(AbstractExpresion *nodo);
int comment_get_is_block(AbstractExpresion *nodo);

#endif
