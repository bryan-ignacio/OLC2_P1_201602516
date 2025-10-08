%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
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
%token <string> TOKEN_PRINT TOKEN_DINT TOKEN_DFLOAT TOKEN_DDOUBLE TOKEN_DVOID TOKEN_IF TOKEN_ELSE TOKEN_TRUE TOKEN_FALSE TOKEN_FUNC TOKEN_INTEGER TOKEN_DOUBLE_CLASS TOKEN_FLOAT_CLASS TOKEN_STRING_CLASS
TOKEN_DBOOLEAN TOKEN_DCHAR TOKEN_UNSIGNED_INTEGER TOKEN_REAL TOKEN_DOUBLE TOKEN_STRING TOKEN_CHAR TOKEN_IDENTIFIER TOKEN_RETURN TOKEN_FINAL TOKEN_LEFT_SHIFT TOKEN_RIGHT_SHIFT TOKEN_EQ TOKEN_NE TOKEN_GE TOKEN_LE TOKEN_AND TOKEN_OR
TOKEN_PLUS_ASSIGN TOKEN_MINUS_ASSIGN TOKEN_MULT_ASSIGN TOKEN_DIV_ASSIGN TOKEN_MOD_ASSIGN TOKEN_AND_ASSIGN TOKEN_OR_ASSIGN TOKEN_XOR_ASSIGN TOKEN_LSHIFT_ASSIGN TOKEN_RSHIFT_ASSIGN TOKEN_SWITCH TOKEN_CASE TOKEN_BREAK TOKEN_DEFAULT TOKEN_WHILE TOKEN_CONTINUE TOKEN_FOR TOKEN_NEW

/* Tipo de los no-terminales que llevan valor */
%type <nodo> s lSentencia sentencia expr imprimir lista_Expr bloque declaracion_var declaracion_const asignacion primitivo sentencia_if sentencia_funcion lista_parametros sentencia_switch lista_casos caso sentencia_while sentencia_for declaracion_array lista_elementos acceso_array declaracion_matrix lista_filas lista_fila acceso_matrix

%type <tipoDato> tipoPrimitivo tipoArray tipoMatrix

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
    | lSentencia sentencia_while { agregarHijo($1, $2); $$ = $1; }
    | sentencia_while {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, $1);
        $$ = b;
    }
    | lSentencia sentencia_for { agregarHijo($1, $2); $$ = $1; }
    | sentencia_for {
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
    | declaracion_array {$$ = $1;}
    | declaracion_matrix {$$ = $1;}
    | asignacion {$$ = $1;}
    | sentencia_funcion { $$ = $1; }
    | TOKEN_IDENTIFIER '(' lista_Expr ')' { $$ = nuevoLlamadaExpresion($1, $3); }
    | TOKEN_IDENTIFIER '(' ')' { $$ = nuevoLlamadaExpresion($1, NULL); }
    | TOKEN_BREAK { $$ = nuevoBreakExpresion(@1.first_line, @1.first_column); }
    | TOKEN_CONTINUE { $$ = nuevoContinueExpresion(@1.first_line, @1.first_column); }
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
    | TOKEN_IDENTIFIER '[' expr ']' '=' expr { $$ = nuevoAsignacionArrayExpresion($1, $3, $6, @1.first_line, @1.first_column); }
    | TOKEN_IDENTIFIER '[' expr ']' '[' expr ']' '=' expr { $$ = nuevoAsignacionMatrixExpresion($1, $3, $6, $9, @1.first_line, @1.first_column); }
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
    | tipoPrimitivo TOKEN_IDENTIFIER '(' lista_parametros ')' bloque {  $$ = nuevoFuncionExpresion($1, $2, $4, $6);}
    | tipoPrimitivo TOKEN_IDENTIFIER '(' ')' bloque {  $$ = nuevoFuncionExpresion($1, $2, NULL, $5);}
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

sentencia_while: TOKEN_WHILE '(' expr ')' bloque { $$ = nuevoWhileExpresion($3, $5); }
    ;

sentencia_for: TOKEN_FOR '(' declaracion_var ';' expr ';' asignacion ')' bloque { $$ = nuevoForExpresion($3, $5, $7, $9); }
    | TOKEN_FOR '(' declaracion_var ';' expr ';' ')' bloque { $$ = nuevoForExpresion($3, $5, NULL, $8); }
    | TOKEN_FOR '(' ';' expr ';' asignacion ')' bloque { $$ = nuevoForExpresion(NULL, $4, $6, $8); }
    | TOKEN_FOR '(' ';' expr ';' ')' bloque { $$ = nuevoForExpresion(NULL, $4, NULL, $7); }
    | TOKEN_FOR '(' tipoPrimitivo TOKEN_IDENTIFIER ':' expr ')' bloque { $$ = nuevoForEachExpresion($3, $4, $6, $8); }
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
    | '(' TOKEN_DVOID ')' expr { $$ = nuevoCastingExpresion($4, VOID); }
    | '(' TOKEN_DINT ')' expr { $$ = nuevoCastingExpresion($4, INT); }
    | '(' TOKEN_DFLOAT ')' expr { $$ = nuevoCastingExpresion($4, FLOAT); }
    | '(' TOKEN_DDOUBLE ')' expr { $$ = nuevoCastingExpresion($4, DOUBLE); }
    | '(' TOKEN_DCHAR ')' expr { $$ = nuevoCastingExpresion($4, CHAR); }
    | primitivo { $$ = $1; }
    | TOKEN_IDENTIFIER { $$ = nuevoIdentificadorExpresion($1, @1.first_line, @1.first_column); }
    | TOKEN_IDENTIFIER '(' lista_Expr ')' { $$ = nuevoLlamadaExpresion($1, $3); }
    | TOKEN_IDENTIFIER '(' ')' { $$ = nuevoLlamadaExpresion($1, NULL); }
    | TOKEN_INTEGER '.' TOKEN_IDENTIFIER '(' expr ')' { 
        if (strcmp($3, "parseInt") == 0) {
            $$ = nuevoIntegerParseIntExpresion($5, @1.first_line, @1.first_column);
        } else {
            yyerror("Método no reconocido en clase Integer");
            $$ = NULL;
        }
    }
    | TOKEN_DOUBLE_CLASS '.' TOKEN_IDENTIFIER '(' expr ')' { 
        if (strcmp($3, "parseDouble") == 0) {
            $$ = nuevoDoubleParseDoubleExpresion($5, @1.first_line, @1.first_column);
        } else {
            yyerror("Método no reconocido en clase Double");
            $$ = NULL;
        }
    }
    | TOKEN_FLOAT_CLASS '.' TOKEN_IDENTIFIER '(' expr ')' { 
        if (strcmp($3, "parseFloat") == 0) {
            $$ = nuevoFloatParseFloatExpresion($5, @1.first_line, @1.first_column);
        } else {
            yyerror("Método no reconocido en clase Float");
            $$ = NULL;
        }
    }
    | TOKEN_STRING_CLASS '.' TOKEN_IDENTIFIER '(' expr ')' { 
        if (strcmp($3, "valueOf") == 0) {
            $$ = nuevoStringValueOfExpresion($5, @1.first_line, @1.first_column);
        } else {
            yyerror("Método no reconocido en clase String");
            $$ = NULL;
        }
    }
    | acceso_array { $$ = $1; }
    | acceso_matrix { $$ = $1; }
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

tipoPrimitivo: TOKEN_DVOID { $$ = VOID; }
    | TOKEN_DINT { $$ = INT; }
    | TOKEN_DFLOAT { $$ = FLOAT; }
    | TOKEN_DDOUBLE { $$ = DOUBLE; }
    | TOKEN_STRING_CLASS { $$ = STRING; }
    | TOKEN_DBOOLEAN { $$ = BOOLEAN; }
    | TOKEN_DCHAR { $$ = CHAR; }
    ;

//---------------------- DECLARACIONES DE ARRAYS -------------------------------
tipoArray: tipoPrimitivo '[' ']' { $$ = $1; }
    ;

declaracion_array: tipoArray TOKEN_IDENTIFIER '=' TOKEN_NEW tipoPrimitivo '[' expr ']' { $$ = nuevoDeclaracionArrayNew($1, $2, $5, $7, @2.first_line, @2.first_column); }
    | tipoArray TOKEN_IDENTIFIER '=' '{' lista_elementos '}' { $$ = nuevoDeclaracionArrayInit($1, $2, $5, @2.first_line, @2.first_column); }
    ;

lista_elementos: lista_elementos ',' expr { agregarHijo($1, $3); $$ = $1; }
    | expr { 
        AbstractExpresion* b = nuevoListaElementos();
        agregarHijo(b, $1);
        $$ = b;
    }
    ;

acceso_array: TOKEN_IDENTIFIER '[' expr ']' { $$ = nuevoAccesoArrayExpresion($1, $3, @1.first_line, @1.first_column); }
    ;

//---------------------- DECLARACIONES DE MATRICES -------------------------------
tipoMatrix: tipoPrimitivo '[' ']' '[' ']' { $$ = $1; }
    ;

declaracion_matrix: tipoMatrix TOKEN_IDENTIFIER '=' TOKEN_NEW tipoPrimitivo '[' expr ']' '[' expr ']' { $$ = nuevoDeclaracionMatrixNew($1, $2, $5, $7, $10, @2.first_line, @2.first_column); }
    | tipoMatrix TOKEN_IDENTIFIER '=' '{' lista_filas '}' { $$ = nuevoDeclaracionMatrixInit($1, $2, $5, @2.first_line, @2.first_column); }
    ;

lista_filas: lista_filas ',' lista_fila { agregarHijo($1, $3); $$ = $1; }
    | lista_fila { 
        AbstractExpresion* b = nuevoListaFilas();
        agregarHijo(b, $1);
        $$ = b;
    }
    ;

lista_fila: '{' lista_elementos '}' { $$ = $2; }
    ;

acceso_matrix: TOKEN_IDENTIFIER '[' expr ']' '[' expr ']' { $$ = nuevoAccesoMatrixExpresion($1, $3, $6, @1.first_line, @1.first_column); }
    ;
%%

/* definición de yyerror, usa el yylloc global para ubicación */
void yyerror(const char *s) {
    int ambito = contextoActualReporte ? contextoActualReporte->nombre : 0;
    agregarErrorSintactico(s, yylloc.first_line, yylloc.first_column, ambito);
}
