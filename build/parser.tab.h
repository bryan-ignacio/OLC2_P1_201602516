/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BUILD_PARSER_TAB_H_INCLUDED
# define YY_YY_BUILD_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 19 "src/entriesTools/parser.y"

    #include "ast/nodos/builders.h"
    #include "context/result.h"

#line 54 "build/parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_PRINT = 258,             /* TOKEN_PRINT  */
    TOKEN_DINT = 259,              /* TOKEN_DINT  */
    TOKEN_DFLOAT = 260,            /* TOKEN_DFLOAT  */
    TOKEN_DDOUBLE = 261,           /* TOKEN_DDOUBLE  */
    TOKEN_DVOID = 262,             /* TOKEN_DVOID  */
    TOKEN_IF = 263,                /* TOKEN_IF  */
    TOKEN_ELSE = 264,              /* TOKEN_ELSE  */
    TOKEN_TRUE = 265,              /* TOKEN_TRUE  */
    TOKEN_FALSE = 266,             /* TOKEN_FALSE  */
    TOKEN_FUNC = 267,              /* TOKEN_FUNC  */
    TOKEN_INTEGER = 268,           /* TOKEN_INTEGER  */
    TOKEN_DSTRING = 269,           /* TOKEN_DSTRING  */
    TOKEN_DBOOLEAN = 270,          /* TOKEN_DBOOLEAN  */
    TOKEN_DCHAR = 271,             /* TOKEN_DCHAR  */
    TOKEN_UNSIGNED_INTEGER = 272,  /* TOKEN_UNSIGNED_INTEGER  */
    TOKEN_REAL = 273,              /* TOKEN_REAL  */
    TOKEN_DOUBLE = 274,            /* TOKEN_DOUBLE  */
    TOKEN_STRING = 275,            /* TOKEN_STRING  */
    TOKEN_CHAR = 276,              /* TOKEN_CHAR  */
    TOKEN_IDENTIFIER = 277,        /* TOKEN_IDENTIFIER  */
    TOKEN_RETURN = 278,            /* TOKEN_RETURN  */
    TOKEN_FINAL = 279,             /* TOKEN_FINAL  */
    TOKEN_LEFT_SHIFT = 280,        /* TOKEN_LEFT_SHIFT  */
    TOKEN_RIGHT_SHIFT = 281,       /* TOKEN_RIGHT_SHIFT  */
    TOKEN_EQ = 282,                /* TOKEN_EQ  */
    TOKEN_NE = 283,                /* TOKEN_NE  */
    TOKEN_GE = 284,                /* TOKEN_GE  */
    TOKEN_LE = 285,                /* TOKEN_LE  */
    TOKEN_AND = 286,               /* TOKEN_AND  */
    TOKEN_OR = 287,                /* TOKEN_OR  */
    TOKEN_PLUS_ASSIGN = 288,       /* TOKEN_PLUS_ASSIGN  */
    TOKEN_MINUS_ASSIGN = 289,      /* TOKEN_MINUS_ASSIGN  */
    TOKEN_MULT_ASSIGN = 290,       /* TOKEN_MULT_ASSIGN  */
    TOKEN_DIV_ASSIGN = 291,        /* TOKEN_DIV_ASSIGN  */
    TOKEN_MOD_ASSIGN = 292,        /* TOKEN_MOD_ASSIGN  */
    TOKEN_AND_ASSIGN = 293,        /* TOKEN_AND_ASSIGN  */
    TOKEN_OR_ASSIGN = 294,         /* TOKEN_OR_ASSIGN  */
    TOKEN_XOR_ASSIGN = 295,        /* TOKEN_XOR_ASSIGN  */
    TOKEN_LSHIFT_ASSIGN = 296,     /* TOKEN_LSHIFT_ASSIGN  */
    TOKEN_RSHIFT_ASSIGN = 297,     /* TOKEN_RSHIFT_ASSIGN  */
    TOKEN_SWITCH = 298,            /* TOKEN_SWITCH  */
    TOKEN_CASE = 299,              /* TOKEN_CASE  */
    TOKEN_BREAK = 300,             /* TOKEN_BREAK  */
    TOKEN_DEFAULT = 301,           /* TOKEN_DEFAULT  */
    TOKEN_WHILE = 302,             /* TOKEN_WHILE  */
    TOKEN_CONTINUE = 303,          /* TOKEN_CONTINUE  */
    TOKEN_FOR = 304,               /* TOKEN_FOR  */
    TOKEN_NEW = 305,               /* TOKEN_NEW  */
    NEG = 306                      /* NEG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "src/entriesTools/parser.y"

  char* string;
  AbstractExpresion* nodo;
  TipoDato tipoDato;

#line 128 "build/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_BUILD_PARSER_TAB_H_INCLUDED  */
