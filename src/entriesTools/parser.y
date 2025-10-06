%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "ast/AbstractExpresion.h"
    #include "context/error_report.h"

    /* Prototipo del scanner */
    extern int yylex(void);
    extern AbstractExpresion* ast_root;
    /* yyerror con firma estándar */
    void yyerror(const char *s);
    extern int yylineno;
    extern int yycolumn;
    extern Context* contextoActualReporte; // Definir en main.c para saber el ambito
%}

/* Esto va al parser.tab.h */
%code requires {
    #include "ast/nodos/builders.h"
    #include "context/result.h"
}

/* Seguimiento de ubicaciones */
%locations
/* Mensajes de error más detallados */
//%define parse.error verbose

/* Unión de tipos semánticos */
%union {
  char* string;
  AbstractExpresion* nodo;
  TipoDato tipoDato;
}

/* Tokens tipados */
%token <string> TOKEN_PRINT TOKEN_DINT TOKEN_DFLOAT TOKEN_DDOUBLE TOKEN_IF TOKEN_ELSE TOKEN_TRUE TOKEN_FALSE TOKEN_FUNC
TOKEN_DSTRING TOKEN_DBOOLEAN TOKEN_DCHAR TOKEN_UNSIGNED_INTEGER TOKEN_REAL TOKEN_DOUBLE TOKEN_STRING TOKEN_CHAR TOKEN_IDENTIFIER TOKEN_RETURN TOKEN_FINAL TOKEN_LEFT_SHIFT TOKEN_RIGHT_SHIFT TOKEN_EQ TOKEN_NE TOKEN_GE TOKEN_LE TOKEN_AND TOKEN_OR
TOKEN_PLUS_ASSIGN TOKEN_MINUS_ASSIGN TOKEN_MULT_ASSIGN TOKEN_DIV_ASSIGN TOKEN_MOD_ASSIGN TOKEN_AND_ASSIGN TOKEN_OR_ASSIGN TOKEN_XOR_ASSIGN TOKEN_LSHIFT_ASSIGN TOKEN_RSHIFT_ASSIGN TOKEN_SWITCH TOKEN_CASE TOKEN_BREAK TOKEN_DEFAULT

/* Tipo de los no-terminales que llevan valor */
%type <nodo> s lSentencia sentencia expr imprimir lista_Expr bloque declaracion_var declaracion_const asignacion primitivo sentencia_if sentencia_funcion lista_parametros sentencia_switch lista_casos caso

%type <tipoDato> tipoPrimitivo

// precedencia menor a mayor
//%left NUMERO
%left '+' '-' //menos -
%left '*' '/' '%' //más
%left NEG

%%
// Regla inicial donde empieza a parsear.
%start s;

// lista de sentencias a ejecutar.
s: lSentencia  { ast_root = $1; $$ = $1; }
    | s error ';' { yyerrok; }
    ;
// Padre, hijo;
// Permite bloques sin punto y coma, pero las demás sentencias sí lo requieren
lSentencia: lSentencia sentencia ';' { agregarHijo($1, $2); $$ = $1;}
    | sentencia ';' {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, $1);
        $$ =  b;
    }
    | lSentencia bloque { agregarHijo($1, $2); $$ = $1; }
    | bloque {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, $1);
        $$ = b;
    }
    | lSentencia sentencia_if { agregarHijo($1, $2); $$ = $1; }
    | sentencia_if {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, $1);
        $$ = b;
    }
    | lSentencia sentencia_switch { agregarHijo($1, $2); $$ = $1; }
    | sentencia_switch {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, $1);
        $$ = b;
    }
    | lSentencia error ';' { yyerrok; $$ = $1; }
    ;
// una sentencia puede ser un print, un bloque, una declaración de variable, un if o una función
sentencia: imprimir {$$ = $1; }
    | bloque {$$ = $1;}
    | declaracion_var {$$ = $1;}
    | declaracion_const {$$ = $1;}
    | asignacion {$$ = $1;}
    | sentencia_funcion { $$ = $1; }
    | TOKEN_BREAK { $$ = nuevoBreakExpresion(); }
    | TOKEN_RETURN { $$ = NULL; }/* sin implementar */
    | TOKEN_RETURN expr { $$ = nuevoReturnExpresion($2); } /* sin implementar */
    ;

lista_Expr: lista_Expr ','  expr { agregarHijo($1, $3); $$ = $1; }
    | expr { 
                AbstractExpresion* b = nuevoListaExpresiones();
                agregarHijo(b, $1);
                $$ =  b;
            }
    ;

imprimir: TOKEN_PRINT '(' lista_Expr ')' { $$ =  nuevoPrintExpresion($3); }
    ;

bloque: '{' lSentencia '}' { $$ =  $2; }
    ;

declaracion_var: tipoPrimitivo TOKEN_IDENTIFIER { $$ = nuevoDeclaracionVariables($1, $2, NULL, @2.first_line, @2.first_column); }
    | tipoPrimitivo TOKEN_IDENTIFIER '=' expr { $$ = nuevoDeclaracionVariables($1, $2, $4, @2.first_line, @2.first_column); }
    ;

declaracion_const: TOKEN_FINAL tipoPrimitivo TOKEN_IDENTIFIER '=' expr { $$ = nuevoDeclaracionConstante($2, $3, $5, @3.first_line, @3.first_column); }
    ;

asignacion: TOKEN_IDENTIFIER '=' expr { $$ = nuevoAsignacionExpresion($1, $3, @1.first_line, @1.first_column); }
    | TOKEN_IDENTIFIER TOKEN_PLUS_ASSIGN expr { $$ = nuevoAsignacionCompuesta($1, ASIG_SUMA, $3, @1.first_line, @1.first_column); }
    | TOKEN_IDENTIFIER TOKEN_MINUS_ASSIGN expr { $$ = nuevoAsignacionCompuesta($1, ASIG_RESTA, $3, @1.first_line, @1.first_column); }
    | TOKEN_IDENTIFIER TOKEN_MULT_ASSIGN expr { $$ = nuevoAsignacionCompuesta($1, ASIG_MULT, $3, @1.first_line, @1.first_column); }
    | TOKEN_IDENTIFIER TOKEN_DIV_ASSIGN expr { $$ = nuevoAsignacionCompuesta($1, ASIG_DIV, $3, @1.first_line, @1.first_column); }
    | TOKEN_IDENTIFIER TOKEN_MOD_ASSIGN expr { $$ = nuevoAsignacionCompuesta($1, ASIG_MOD, $3, @1.first_line, @1.first_column); }
    | TOKEN_IDENTIFIER TOKEN_AND_ASSIGN expr { $$ = nuevoAsignacionCompuesta($1, ASIG_AND, $3, @1.first_line, @1.first_column); }
    | TOKEN_IDENTIFIER TOKEN_OR_ASSIGN expr { $$ = nuevoAsignacionCompuesta($1, ASIG_OR, $3, @1.first_line, @1.first_column); }
    | TOKEN_IDENTIFIER TOKEN_XOR_ASSIGN expr { $$ = nuevoAsignacionCompuesta($1, ASIG_XOR, $3, @1.first_line, @1.first_column); }
    | TOKEN_IDENTIFIER TOKEN_LSHIFT_ASSIGN expr { $$ = nuevoAsignacionCompuesta($1, ASIG_LSHIFT, $3, @1.first_line, @1.first_column); }
    | TOKEN_IDENTIFIER TOKEN_RSHIFT_ASSIGN expr { $$ = nuevoAsignacionCompuesta($1, ASIG_RSHIFT, $3, @1.first_line, @1.first_column); }
    ;

sentencia_if: TOKEN_IF '(' expr ')' bloque { $$ = nuevoIfExpresion($3, $5); }
    | TOKEN_IF '(' expr ')' bloque TOKEN_ELSE bloque { $$ = nuevoIfElseExpresion($3, $5, $7); }
    | TOKEN_IF '(' expr ')' bloque TOKEN_ELSE sentencia_if { $$ = nuevoElseIfExpresion($3, $5, $7); }
    ;

lista_parametros: lista_parametros ',' declaracion_var { agregarHijo($1, $3); $$ = $1; }
    | declaracion_var { AbstractExpresion* b = nuevoListaParametros();
                agregarHijo(b, $1);
                $$ =  b; }
    ;

sentencia_funcion: tipoPrimitivo TOKEN_FUNC TOKEN_IDENTIFIER '(' lista_parametros ')' bloque {  $$ = nuevoFuncionExpresion($1, $3, $5, $7);}
    | tipoPrimitivo TOKEN_FUNC TOKEN_IDENTIFIER '(' ')' bloque {  $$ = nuevoFuncionExpresion($1, $3, NULL, $6);}
    ;

sentencia_switch: TOKEN_SWITCH '(' expr ')' '{' lista_casos '}' { $$ = nuevoSwitchExpresion($3, $6); }
    ;

lista_casos: lista_casos caso { agregarHijo($1, $2); $$ = $1; }
    | caso { 
        AbstractExpresion* b = nuevoListaCasos();
        agregarHijo(b, $1);
        $$ = b;
    }
    ;

caso: TOKEN_CASE expr ':' lSentencia { $$ = nuevoCaseExpresion($2, $4); }
    | TOKEN_DEFAULT ':' lSentencia { $$ = nuevoDefaultExpresion($3); }
    ;

/* 
TODO: para mejorar la legibilidad en lugar de guardar la operacion por incumplir
el principio de responsabilidad única y también el Principio de abierto/cerrado (SOLID)
la accion semantica fungirá como factoría abstracta y cada expresión tendra su método interpret
para hacer la operación además de utilizar otros métodos "heredados".

expr: expr '+' expr   { $$ =  nuevoExpresionLenguaje('+', $1, $3);  }
    | expr '-' expr { $$ =  nuevoExpresionLenguaje('-', $1, $3); }
    | '(' expr ')' { $$ = $2; }
    | '-' expr %prec NEG  { $$ =  nuevoExpresionLenguaje('U', $2, NULL);  }
    | primitivo { $$ = $1; }
    ; 
*/

//---------------------- EXPRESIONES ARITMETICAS -------------------------------

expr: expr '+' expr   { $$ =  nuevoSumaExpresion($1, $3);  }
    | expr '-' expr { $$ =  nuevoRestaExpresion($1, $3); }
    | expr '*' expr { $$ =  nuevoMultiplicacionExpresion($1, $3); }
    | expr '/' expr { $$ =  nuevoDivisionExpresion($1, $3); }
    | expr '%' expr { $$ =  nuevoModuloExpresion($1, $3); }
    | expr '&' expr { $$ =  nuevoBitwiseAndExpresion($1, $3); }
    | expr '|' expr { $$ =  nuevoBitwiseOrExpresion($1, $3); }
    | expr '^' expr { $$ =  nuevoBitwiseXorExpresion($1, $3); }
    | expr TOKEN_LEFT_SHIFT expr { $$ =  nuevoBitwiseLeftShiftExpresion($1, $3); }
    | expr TOKEN_RIGHT_SHIFT expr { $$ =  nuevoBitwiseRightShiftExpresion($1, $3); }
    | '(' expr ')' { $$ = $2; }
    | '-' expr %prec NEG  { $$ =  nuevoUnarioExpresion($2);  }
    | '~' expr %prec NEG  { $$ =  nuevoBitwiseNotExpresion($2);  }
    | expr TOKEN_EQ expr { $$ = nuevoIgualdadExpresion($1, $3); }
    | expr TOKEN_NE expr { $$ = nuevoDesigualdadExpresion($1, $3); }
    | expr '>' expr { $$ = nuevoMayorQueExpresion($1, $3); }
    | expr '<' expr { $$ = nuevoMenorQueExpresion($1, $3); }
    | expr TOKEN_GE expr { $$ = nuevoMayorIgualExpresion($1, $3); }
    | expr TOKEN_LE expr { $$ = nuevoMenorIgualExpresion($1, $3); }
    | expr TOKEN_AND expr { $$ = nuevoLogicAndExpresion($1, $3); }
    | expr TOKEN_OR expr { $$ = nuevoLogicOrExpresion($1, $3); }
    | '!' expr %prec NEG { $$ = nuevoLogicNotExpresion($2); }
    | '(' TOKEN_DINT ')' expr { $$ = nuevoCastingExpresion($4, INT); }
    | '(' TOKEN_DFLOAT ')' expr { $$ = nuevoCastingExpresion($4, FLOAT); }
    | '(' TOKEN_DDOUBLE ')' expr { $$ = nuevoCastingExpresion($4, DOUBLE); }
    | '(' TOKEN_DCHAR ')' expr { $$ = nuevoCastingExpresion($4, CHAR); }
    | primitivo { $$ = $1; }
    | TOKEN_IDENTIFIER { $$ = nuevoIdentificadorExpresion($1, @1.first_line, @1.first_column); }
    | TOKEN_IDENTIFIER '(' lista_Expr ')' { $$ = nuevoLlamadaExpresion($1, $3); }
    | TOKEN_IDENTIFIER '('')' { /* sin implementar */ }
    ;

//---------------------- EXPRESIONES PRIMITIVAS -------------------------------
primitivo: TOKEN_UNSIGNED_INTEGER { $$ =  nuevoPrimitivoExpresion($1, INT); }
    | TOKEN_STRING { $$ =  nuevoPrimitivoExpresion($1, STRING); }
    | TOKEN_REAL { $$ =  nuevoPrimitivoExpresion($1, FLOAT); }
    | TOKEN_DOUBLE { $$ =  nuevoPrimitivoExpresion($1, DOUBLE); }
    | TOKEN_CHAR { $$ =  nuevoPrimitivoExpresion($1, CHAR); }
    | TOKEN_TRUE { $$ =  nuevoPrimitivoExpresion("T", BOOLEAN); }
    | TOKEN_FALSE { $$ =  nuevoPrimitivoExpresion("F", BOOLEAN); }
    ;

tipoPrimitivo: TOKEN_DINT { $$ = INT; }
    | TOKEN_DFLOAT { $$ = FLOAT; }
    | TOKEN_DDOUBLE { $$ = DOUBLE; }
    | TOKEN_DSTRING { $$ = STRING; }
    | TOKEN_DBOOLEAN { $$ = BOOLEAN; }
    | TOKEN_DCHAR { $$ = CHAR; }
    ;
%%

/* definición de yyerror, usa el yylloc global para ubicación */
void yyerror(const char *s) {
    int ambito = contextoActualReporte ? contextoActualReporte->nombre : 0;
    agregarErrorSintactico(s, yylloc.first_line, yylloc.first_column, ambito);
}
