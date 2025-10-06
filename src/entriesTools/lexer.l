%{
#include "parser.tab.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <float.h>
#include <math.h>
#include "context/error_report.h"

extern void yyerror(const char *s);
extern Context* contextoActualReporte; // Para obtener el ámbito actual

/* Contador de columna global */
extern int yycolumn;

/* Declaraciones de funciones de validación */
int validar_int32(const char *str);
int validar_float32(const char *str);
int validar_double64(const char *str);
char* procesar_secuencias_escape(const char* input);

/* Función para reportar errores léxicos sin detener la ejecución */
void reportar_error_lexico(const char* mensaje) {
    agregarErrorLexico(mensaje, yylineno, yycolumn);
}

/* Rangos para enteros de 32 bits */
#define INT32_MIN_VALUE -2147483648LL
#define INT32_MAX_VALUE  2147483647LL

/* Rangos para float de 32 bits */
#define FLOAT32_MAX_VALUE  3.4028235E38f
#define FLOAT32_MIN_VALUE  1.4E-45f

/* Rangos para double de 64 bits */
#define DOUBLE64_MAX_VALUE  1.7976931348623157e308
#define DOUBLE64_MIN_VALUE  4.9e-324

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

/* Función para validar rango de float de 32 bits */
int validar_float32(const char *str) {
    char *endptr;
    errno = 0;
    
    /* Crear una copia del string sin la 'f' al final */
    int len = strlen(str);
    if (len == 0 || str[len-1] != 'f') {
        return 0; /* Debe terminar en 'f' */
    }
    
    char *temp_str = malloc(len);
    strncpy(temp_str, str, len-1);
    temp_str[len-1] = '\0';
    
    /* Convertir a float */
    float val = strtof(temp_str, &endptr);
    free(temp_str);
    
    /* Verificar si la conversión fue exitosa */
    if (errno == ERANGE || *endptr != '\0') {
        return 0; /* Error de conversión */
    }
    
    /* Verificar si es cero, infinito o NaN (casos especiales) */
    if (val == 0.0f || isinf(val) || isnan(val)) {
        return 1;
    }
    
    /* Verificar rango de 32 bits para valores no cero */
    float abs_val = fabsf(val);
    
    /* Ser más tolerante con los límites debido a la precisión flotante */
    if (abs_val > FLOAT32_MAX_VALUE) {
        return 0; /* Fuera de rango máximo */
    }
    
    /* Para el límite mínimo, ser más flexible - solo verificar para valores muy pequeños */
    if (abs_val != 0.0f && abs_val < FLOAT32_MIN_VALUE) {
        return 0; /* Demasiado pequeño */
    }
    
    return 1; /* Válido */
}

/* Función para validar rango de double de 64 bits */
int validar_double64(const char *str) {
    char *endptr;
    errno = 0;
    
    /* Los doubles NO deben terminar en 'f' */
    int len = strlen(str);
    if (len > 0 && str[len-1] == 'f') {
        return 0; /* No debe terminar en 'f' */
    }
    
    /* Convertir a double */
    double val = strtod(str, &endptr);
    
    /* Verificar si la conversión fue exitosa */
    if (errno == ERANGE || *endptr != '\0') {
        return 0; /* Error de conversión */
    }
    
    /* Verificar si es cero, infinito o NaN (casos especiales) */
    if (val == 0.0 || isinf(val) || isnan(val)) {
        return 1;
    }
    
    /* Verificar rango de 64 bits para valores no cero */
    double abs_val = fabs(val);
    
    /* Verificar límites de double de 64 bits */
    if (abs_val > DOUBLE64_MAX_VALUE) {
        return 0; /* Fuera de rango máximo */
    }
    
    if (abs_val != 0.0 && abs_val < DOUBLE64_MIN_VALUE * 0.1) {
        return 0; /* Demasiado pequeño */
    }
    
    return 1; /* Válido */
}

/* Función para procesar secuencias de escape en strings */
char* procesar_secuencias_escape(const char* input) {
    int len = strlen(input);
    char* result = malloc(len + 1); /* En el peor caso, mismo tamaño */
    int i = 0, j = 0;
    
    while (i < len) {
        if (input[i] == '\\' && i + 1 < len) {
            switch (input[i + 1]) {
                case '"':
                    result[j++] = '"';
                    i += 2;
                    break;
                case '\\':
                    result[j++] = '\\';
                    i += 2;
                    break;
                case 'n':
                    result[j++] = '\n';
                    i += 2;
                    break;
                case 't':
                    result[j++] = '\t';
                    i += 2;
                    break;
                case 'r':
                    result[j++] = '\r';
                    i += 2;
                    break;
                default:
                    /* Si no es una secuencia reconocida, copiar literal */
                    result[j++] = input[i++];
                    break;
            }
        } else {
            result[j++] = input[i++];
        }
    }
    
    result[j] = '\0';
    return result;
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
exponent          [eE][+-]?{digit}+
i                 {unsigned_integer}
real              ({i}\.{i}?|{i}?\.{i}){exponent}?
float_literal     ({i}\.{i}?|{i}?\.{i}){exponent}?f
string            \"([^"\n\\]|\\.)*\"
bad_string        \"([^"\n\\]|\\.)*
char_literal      '([^'\n\\]|\\u[0-9a-fA-F]{4}|\\.)'
bad_char          '([^'\n\\]|\\u[0-9a-fA-F]{4}|\\.)*

/* Reconocimiento de comentarios y comentario multilinea. */
%%
"//"                     BEGIN(COMMENTLINEA);
<COMMENTLINEA>[^\n\r]+ 
<COMMENTLINEA><<EOF>>    {
                        reportar_error_lexico("Fin de archivo en comentario de línea");
                        BEGIN(INITIAL);
                    }
<COMMENTLINEA>[\n\r]     {yycolumn=1; BEGIN(INITIAL);}

"/*"                 BEGIN(COMMENT2);
<COMMENT2>[^*\n\r]+
<COMMENT2>[\n\r]     {yycolumn=1;}
<COMMENT2><<EOF>>    {
                        reportar_error_lexico("Fin de archivo en comentario multilínea");
                        BEGIN(INITIAL);
                    }
<COMMENT2>"*/"       BEGIN(INITIAL);
<COMMENT2>[*]

if                  return(TOKEN_IF); // palabras reservadas, estructuras de control.
else                return(TOKEN_ELSE);
switch              return(TOKEN_SWITCH);
case                return(TOKEN_CASE);
break               return(TOKEN_BREAK);
default             return(TOKEN_DEFAULT);
final               return(TOKEN_FINAL);
System\.out\.println    return(TOKEN_PRINT);
func                return(TOKEN_FUNC);
int                 return(TOKEN_DINT); // aqui comienzan las declaraciones de tipos primitivos.
float               return(TOKEN_DFLOAT);
double              return(TOKEN_DDOUBLE);
String              return(TOKEN_DSTRING);
boolean             return(TOKEN_DBOOLEAN);
char                return(TOKEN_DCHAR);
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
                            reportar_error_lexico(error_msg);
                            /* Retornar un token válido con valor 0 para continuar */
                            yylval.string = strdup("0");
                            return(TOKEN_UNSIGNED_INTEGER);
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
                            reportar_error_lexico(error_msg);
                            /* Retornar un token válido con valor 0 para continuar */
                            yylval.string = strdup("0");
                            return(TOKEN_UNSIGNED_INTEGER);
                        }
                        yylval.string = strdup(yytext); 
                        return(TOKEN_UNSIGNED_INTEGER);
                    }
{float_literal}      {
                        /* Validar rango de 32 bits para float con notación explícita 'f' */
                        if (!validar_float32(yytext)) {
                            char error_msg[256];
                            snprintf(error_msg, sizeof(error_msg), 
                                   "Float fuera de rango de 32 bits: %s. Rango válido: 1.4E-45f a 3.4028235E38f", 
                                   yytext);
                            reportar_error_lexico(error_msg);
                            /* Retornar un token válido con valor 0.0f para continuar */
                            yylval.string = strdup("0.0f");
                            return(TOKEN_REAL);
                        }
                        yylval.string = strdup(yytext); 
                        return(TOKEN_REAL);
                    }
{real}               {
                        /* Los números sin 'f' al final se tratan como double de 64 bits */
                        if (!validar_double64(yytext)) {
                            char error_msg[256];
                            snprintf(error_msg, sizeof(error_msg), 
                                   "Double fuera de rango de 64 bits: %s. Rango válido: 4.9e-324 a 1.7976931348623157e308", 
                                   yytext);
                            reportar_error_lexico(error_msg);
                            /* Retornar un token válido con valor 0.0 para continuar */
                            yylval.string = strdup("0.0");
                            return(TOKEN_DOUBLE);
                        }
                        yylval.string = strdup(yytext); 
                        return(TOKEN_DOUBLE);
                    }
{string}             {
                        /* Manejar cadenas de texto con secuencias de escape */
                        int len = yyleng - 2; /* Quitar comillas */
                        char* temp = malloc(len + 1);
                        strncpy(temp, &yytext[1], len); /* Copiar sin comillas */
                        temp[len] = '\0';
                        
                        /* Procesar secuencias de escape */
                        yylval.string = procesar_secuencias_escape(temp);
                        free(temp);
                        return(TOKEN_STRING);
                    }
{char_literal}       {
                        /* Manejar caracteres Unicode correctamente */
                        yylval.string = strdup(yytext);
                        return(TOKEN_CHAR);
                    }
{bad_char}           {
                        reportar_error_lexico("Carácter no terminado correctamente");
                        /* Retornar un token válido para continuar */
                        yylval.string = strdup("'\0'");
                        return(TOKEN_CHAR);
                    }
{bad_string}         {
                        reportar_error_lexico("Cadena de texto no terminada correctamente");
                        /* Retornar un token válido para continuar */
                        yylval.string = strdup("");
                        return(TOKEN_STRING);
                    }

{identifier}         {yylval.string = strdup(yytext); return(TOKEN_IDENTIFIER);} // identifier se utiliza para identificadores y retorna el token correspondiente.

"<<"                 return(TOKEN_LEFT_SHIFT); // operador de desplazamiento a la izquierda
">>"                 return(TOKEN_RIGHT_SHIFT); // operador de desplazamiento a la derecha
"=="                 return(TOKEN_EQ); // operador de igualdad
"!="                 return(TOKEN_NE); // operador de desigualdad
">="                 return(TOKEN_GE); // operador mayor o igual
"<="                 return(TOKEN_LE); // operador menor o igual
"&&"                 return(TOKEN_AND); // operador lógico AND
"||"                 return(TOKEN_OR); // operador lógico OR
"+="                 return(TOKEN_PLUS_ASSIGN); // operador de asignación suma
"-="                 return(TOKEN_MINUS_ASSIGN); // operador de asignación resta
"*="                 return(TOKEN_MULT_ASSIGN); // operador de asignación multiplicación
"/="                 return(TOKEN_DIV_ASSIGN); // operador de asignación división
"%="                 return(TOKEN_MOD_ASSIGN); // operador de asignación módulo
"&="                 return(TOKEN_AND_ASSIGN); // operador de asignación AND bitwise
"|="                 return(TOKEN_OR_ASSIGN); // operador de asignación OR bitwise
"^="                 return(TOKEN_XOR_ASSIGN); // operador de asignación XOR bitwise
"<<="                return(TOKEN_LSHIFT_ASSIGN); // operador de asignación desplazamiento izquierda
">>="                return(TOKEN_RSHIFT_ASSIGN); // operador de asignación desplazamiento derecha

[*/+\-%,^&|~()\[\]{}\;=\>\<!:]      return(yytext[0]); // esta es una expresion regular que reconoce varios simbolos de uno solo caracter y retorna el mismo caracter como token.

{white_space}        // este white_space se utiliza para espacios en blanco y no hace nada.
[\n\r]               {yycolumn=1;} // este patron reconoce saltos de linea y reinicia el contador de columna.
.                    {
                        char error_msg[256];
                        snprintf(error_msg, sizeof(error_msg), "Carácter ilegal: '%c'", yytext[0]);
                        reportar_error_lexico(error_msg);
                        /* Ignorar el carácter y continuar */
                    }

%%
