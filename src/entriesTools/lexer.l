%{
#include "parser.tab.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

extern void yyerror(const char *s);

/* Rangos para enteros de 32 bits */
#define INT32_MIN_VALUE -2147483648LL
#define INT32_MAX_VALUE  2147483647LL

/* Función para validar rango de enteros de 32 bits */
int validar_int32(const char *str) {
    char *endptr;
    errno = 0;
    long long val = strtoll(str, &endptr, 10);
    
    /* Verificar si la conversión fue exitosa */
    if (errno == ERANGE || *endptr != '\0') {
        return 0; /* Error de conversión */
    }
    
    /* Verificar rango de 32 bits */
    if (val < INT32_MIN_VALUE || val > INT32_MAX_VALUE) {
        return 0; /* Fuera de rango */
    }
    
    return 1; /* Válido */
}

/* Contador de columna */
int yycolumn = 1;

/* Se ejecuta antes de cada accion, actualiza yylloc y columna */
#define YY_USER_ACTION                                   \
    yylloc.first_line   = yylineno;                      \
    yylloc.first_column = yycolumn;                      \
    yylloc.last_line    = yylineno;                      \
    yylloc.last_column  = yycolumn + yyleng - 1;         \
    yycolumn += yyleng;
%}

/* Opciones de Flex 
 * yylineno:  mantenga el numero de la linea actual
 leida desde su entrada en la variable global yylineno.
 * noyywrap:  hace que el analizador no llame a yywrap() hasta el fin-de-fichero, 
 pero simplemente asume que no hay mas ficheros que analizar.
*/
%option noyywrap yylineno nounput noinput

/* Condiciones de arranque */
%x COMMENT2 COMMENTLINEA

/* ------------ patrones para los tokens -------------------- */
white_space       [ \t]*
digit             [0-9]
alpha             [A-Za-z_]
alpha_num         ({alpha}|{digit})
/* hex_digit         [0-9A-F] */
identifier        {alpha}{alpha_num}*
unsigned_integer  {digit}+
signed_integer    \-{digit}+
/* hex_integer       ${hex_digit}{hex_digit}* */
exponent          e[+-]?{digit}+
i                 {unsigned_integer}
real              ({i}\.{i}?|{i}?\.{i}){exponent}?
string            \"([^"\n]|\"\")+\"
bad_string        \"([^"\n]|\"\")+

/* Reconocimiento de comentarios y comentario multilinea. */
%%
"//"                     BEGIN(COMMENTLINEA);
<COMMENTLINEA>[^\n\r]+ 
<COMMENTLINEA><<EOF>>    yyerror("EOF in comment");
<COMMENTLINEA>[\n\r]     {yycolumn=1; BEGIN(INITIAL);}

"/*"                 BEGIN(COMMENT2);
<COMMENT2>[^*\n\r]+
<COMMENT2>[\n\r]     {yycolumn=1;}
<COMMENT2><<EOF>>    yyerror("EOF in comment");
<COMMENT2>"*/"       BEGIN(INITIAL);
<COMMENT2>[*]

if                  return(TOKEN_IF); // palabras reservadas, estructuras de control.
else                return(TOKEN_ELSE);
print               return(TOKEN_PRINT);
func                return(TOKEN_FUNC);
int                 return(TOKEN_DINT); // aqui comienzan las declaraciones de tipos primitivos.
float               return(TOKEN_DFLOAT);
String              return(TOKEN_DSTRING);
true                return(TOKEN_TRUE);
false               return(TOKEN_FALSE);
return              return(TOKEN_RETURN);

{unsigned_integer}   {
                        /* Validar rango de 32 bits para enteros */
                        if (!validar_int32(yytext)) {
                            char error_msg[256];
                            snprintf(error_msg, sizeof(error_msg), 
                                   "Entero fuera de rango de 32 bits: %s. Rango válido: -2147483648 a 2147483647", 
                                   yytext);
                            yyerror(error_msg);
                            return -1; /* Token de error */
                        }
                        yylval.string = strdup(yytext); 
                        return(TOKEN_UNSIGNED_INTEGER);
                    }
{signed_integer}     {
                        /* Validar rango de 32 bits para enteros negativos */
                        if (!validar_int32(yytext)) {
                            char error_msg[256];
                            snprintf(error_msg, sizeof(error_msg), 
                                   "Entero fuera de rango de 32 bits: %s. Rango válido: -2147483648 a 2147483647", 
                                   yytext);
                            yyerror(error_msg);
                            return -1; /* Token de error */
                        }
                        yylval.string = strdup(yytext); 
                        return(TOKEN_UNSIGNED_INTEGER);
                    }
{real}               {yylval.string = strdup(yytext); return(TOKEN_REAL);} // real se utiliza para numeros de punto flotante y retorna el token correspondiente.
{string}             {
                        /* Manejar cadenas de texto correctamente */
                        int len = yyleng - 2; /* Quitar comillas */
                        yylval.string = malloc(len + 1); /* +1 para terminador nulo */
                        strncpy(yylval.string, &yytext[1], len); /* Copiar sin comillas */
                        yylval.string[len] = '\0'; /* Agregar terminador nulo */
                        return(TOKEN_STRING);
                    }
{bad_string}         yyerror("Unterminated string"); // bad_string se utiliza para cadenas de texto que no fueron terminadas correctamente y lanza un error.

{identifier}         {yylval.string = strdup(yytext); return(TOKEN_IDENTIFIER);} // identifier se utiliza para identificadores y retorna el token correspondiente.

[*/+\-,^()\[\]{}\;=\>\<!]      return(yytext[0]); // esta es una expresion regular que reconoce varios simbolos de uno solo caracter y retorna el mismo caracter como token.

{white_space}        // este white_space se utiliza para espacios en blanco y no hace nada.
[\n\r]               {yycolumn=1;} // este patron reconoce saltos de linea y reinicia el contador de columna.
.                    yyerror("Illegal input"); // el punto ayuda  otro caracter no reconocido lanza un error.

%%
