/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/entriesTools/parser.y"

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

#line 88 "build/parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_PRINT = 3,                /* TOKEN_PRINT  */
  YYSYMBOL_TOKEN_DINT = 4,                 /* TOKEN_DINT  */
  YYSYMBOL_TOKEN_DFLOAT = 5,               /* TOKEN_DFLOAT  */
  YYSYMBOL_TOKEN_DDOUBLE = 6,              /* TOKEN_DDOUBLE  */
  YYSYMBOL_TOKEN_DVOID = 7,                /* TOKEN_DVOID  */
  YYSYMBOL_TOKEN_IF = 8,                   /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELSE = 9,                 /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_TRUE = 10,                /* TOKEN_TRUE  */
  YYSYMBOL_TOKEN_FALSE = 11,               /* TOKEN_FALSE  */
  YYSYMBOL_TOKEN_FUNC = 12,                /* TOKEN_FUNC  */
  YYSYMBOL_TOKEN_INTEGER = 13,             /* TOKEN_INTEGER  */
  YYSYMBOL_TOKEN_DOUBLE_CLASS = 14,        /* TOKEN_DOUBLE_CLASS  */
  YYSYMBOL_TOKEN_FLOAT_CLASS = 15,         /* TOKEN_FLOAT_CLASS  */
  YYSYMBOL_TOKEN_STRING_CLASS = 16,        /* TOKEN_STRING_CLASS  */
  YYSYMBOL_TOKEN_ARRAYS = 17,              /* TOKEN_ARRAYS  */
  YYSYMBOL_TOKEN_DBOOLEAN = 18,            /* TOKEN_DBOOLEAN  */
  YYSYMBOL_TOKEN_DCHAR = 19,               /* TOKEN_DCHAR  */
  YYSYMBOL_TOKEN_UNSIGNED_INTEGER = 20,    /* TOKEN_UNSIGNED_INTEGER  */
  YYSYMBOL_TOKEN_REAL = 21,                /* TOKEN_REAL  */
  YYSYMBOL_TOKEN_DOUBLE = 22,              /* TOKEN_DOUBLE  */
  YYSYMBOL_TOKEN_STRING = 23,              /* TOKEN_STRING  */
  YYSYMBOL_TOKEN_CHAR = 24,                /* TOKEN_CHAR  */
  YYSYMBOL_TOKEN_IDENTIFIER = 25,          /* TOKEN_IDENTIFIER  */
  YYSYMBOL_TOKEN_RETURN = 26,              /* TOKEN_RETURN  */
  YYSYMBOL_TOKEN_FINAL = 27,               /* TOKEN_FINAL  */
  YYSYMBOL_TOKEN_LEFT_SHIFT = 28,          /* TOKEN_LEFT_SHIFT  */
  YYSYMBOL_TOKEN_RIGHT_SHIFT = 29,         /* TOKEN_RIGHT_SHIFT  */
  YYSYMBOL_TOKEN_EQ = 30,                  /* TOKEN_EQ  */
  YYSYMBOL_TOKEN_NE = 31,                  /* TOKEN_NE  */
  YYSYMBOL_TOKEN_GE = 32,                  /* TOKEN_GE  */
  YYSYMBOL_TOKEN_LE = 33,                  /* TOKEN_LE  */
  YYSYMBOL_TOKEN_AND = 34,                 /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 35,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_PLUS_ASSIGN = 36,         /* TOKEN_PLUS_ASSIGN  */
  YYSYMBOL_TOKEN_MINUS_ASSIGN = 37,        /* TOKEN_MINUS_ASSIGN  */
  YYSYMBOL_TOKEN_MULT_ASSIGN = 38,         /* TOKEN_MULT_ASSIGN  */
  YYSYMBOL_TOKEN_DIV_ASSIGN = 39,          /* TOKEN_DIV_ASSIGN  */
  YYSYMBOL_TOKEN_MOD_ASSIGN = 40,          /* TOKEN_MOD_ASSIGN  */
  YYSYMBOL_TOKEN_AND_ASSIGN = 41,          /* TOKEN_AND_ASSIGN  */
  YYSYMBOL_TOKEN_OR_ASSIGN = 42,           /* TOKEN_OR_ASSIGN  */
  YYSYMBOL_TOKEN_XOR_ASSIGN = 43,          /* TOKEN_XOR_ASSIGN  */
  YYSYMBOL_TOKEN_LSHIFT_ASSIGN = 44,       /* TOKEN_LSHIFT_ASSIGN  */
  YYSYMBOL_TOKEN_RSHIFT_ASSIGN = 45,       /* TOKEN_RSHIFT_ASSIGN  */
  YYSYMBOL_TOKEN_SWITCH = 46,              /* TOKEN_SWITCH  */
  YYSYMBOL_TOKEN_CASE = 47,                /* TOKEN_CASE  */
  YYSYMBOL_TOKEN_BREAK = 48,               /* TOKEN_BREAK  */
  YYSYMBOL_TOKEN_DEFAULT = 49,             /* TOKEN_DEFAULT  */
  YYSYMBOL_TOKEN_WHILE = 50,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_CONTINUE = 51,            /* TOKEN_CONTINUE  */
  YYSYMBOL_TOKEN_FOR = 52,                 /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_NEW = 53,                 /* TOKEN_NEW  */
  YYSYMBOL_54_ = 54,                       /* '+'  */
  YYSYMBOL_55_ = 55,                       /* '-'  */
  YYSYMBOL_56_ = 56,                       /* '*'  */
  YYSYMBOL_57_ = 57,                       /* '/'  */
  YYSYMBOL_58_ = 58,                       /* '%'  */
  YYSYMBOL_NEG = 59,                       /* NEG  */
  YYSYMBOL_60_ = 60,                       /* ';'  */
  YYSYMBOL_61_ = 61,                       /* '('  */
  YYSYMBOL_62_ = 62,                       /* ')'  */
  YYSYMBOL_63_ = 63,                       /* ','  */
  YYSYMBOL_64_ = 64,                       /* '{'  */
  YYSYMBOL_65_ = 65,                       /* '}'  */
  YYSYMBOL_66_ = 66,                       /* '='  */
  YYSYMBOL_67_ = 67,                       /* '['  */
  YYSYMBOL_68_ = 68,                       /* ']'  */
  YYSYMBOL_69_ = 69,                       /* ':'  */
  YYSYMBOL_70_ = 70,                       /* '&'  */
  YYSYMBOL_71_ = 71,                       /* '|'  */
  YYSYMBOL_72_ = 72,                       /* '^'  */
  YYSYMBOL_73_ = 73,                       /* '~'  */
  YYSYMBOL_74_ = 74,                       /* '>'  */
  YYSYMBOL_75_ = 75,                       /* '<'  */
  YYSYMBOL_76_ = 76,                       /* '!'  */
  YYSYMBOL_77_ = 77,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 78,                  /* $accept  */
  YYSYMBOL_s = 79,                         /* s  */
  YYSYMBOL_lSentencia = 80,                /* lSentencia  */
  YYSYMBOL_sentencia = 81,                 /* sentencia  */
  YYSYMBOL_lista_Expr = 82,                /* lista_Expr  */
  YYSYMBOL_imprimir = 83,                  /* imprimir  */
  YYSYMBOL_bloque = 84,                    /* bloque  */
  YYSYMBOL_declaracion_var = 85,           /* declaracion_var  */
  YYSYMBOL_declaracion_const = 86,         /* declaracion_const  */
  YYSYMBOL_asignacion = 87,                /* asignacion  */
  YYSYMBOL_sentencia_if = 88,              /* sentencia_if  */
  YYSYMBOL_lista_parametros = 89,          /* lista_parametros  */
  YYSYMBOL_sentencia_funcion = 90,         /* sentencia_funcion  */
  YYSYMBOL_sentencia_switch = 91,          /* sentencia_switch  */
  YYSYMBOL_lista_casos = 92,               /* lista_casos  */
  YYSYMBOL_caso = 93,                      /* caso  */
  YYSYMBOL_sentencia_while = 94,           /* sentencia_while  */
  YYSYMBOL_sentencia_for = 95,             /* sentencia_for  */
  YYSYMBOL_expr = 96,                      /* expr  */
  YYSYMBOL_primitivo = 97,                 /* primitivo  */
  YYSYMBOL_tipoPrimitivo = 98,             /* tipoPrimitivo  */
  YYSYMBOL_tipoArray = 99,                 /* tipoArray  */
  YYSYMBOL_declaracion_array = 100,        /* declaracion_array  */
  YYSYMBOL_lista_elementos = 101,          /* lista_elementos  */
  YYSYMBOL_acceso_array = 102,             /* acceso_array  */
  YYSYMBOL_tipoMatrix = 103,               /* tipoMatrix  */
  YYSYMBOL_declaracion_matrix = 104,       /* declaracion_matrix  */
  YYSYMBOL_lista_filas = 105,              /* lista_filas  */
  YYSYMBOL_lista_fila = 106,               /* lista_fila  */
  YYSYMBOL_acceso_matrix = 107             /* acceso_matrix  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  78
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1291

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  321

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   309


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    76,     2,     2,     2,    58,    70,     2,
      61,    62,    56,    54,    63,    55,    77,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    69,    60,
      75,    66,    74,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    67,     2,    68,    72,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,    71,    65,    73,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    57,    57,    58,    62,    63,    68,    69,    74,    75,
      80,    81,    86,    87,    92,    93,    98,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   117,   118,   125,   128,   131,   132,   135,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   153,   154,   155,   158,   159,   164,   165,   166,   167,
     170,   173,   174,   181,   182,   185,   188,   189,   190,   191,
     192,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   250,   258,   266,   274,   282,   290,   291,
     295,   296,   297,   298,   299,   300,   301,   304,   305,   306,
     307,   308,   309,   310,   314,   317,   318,   321,   322,   329,
     333,   336,   337,   340,   341,   348,   351
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_PRINT",
  "TOKEN_DINT", "TOKEN_DFLOAT", "TOKEN_DDOUBLE", "TOKEN_DVOID", "TOKEN_IF",
  "TOKEN_ELSE", "TOKEN_TRUE", "TOKEN_FALSE", "TOKEN_FUNC", "TOKEN_INTEGER",
  "TOKEN_DOUBLE_CLASS", "TOKEN_FLOAT_CLASS", "TOKEN_STRING_CLASS",
  "TOKEN_ARRAYS", "TOKEN_DBOOLEAN", "TOKEN_DCHAR",
  "TOKEN_UNSIGNED_INTEGER", "TOKEN_REAL", "TOKEN_DOUBLE", "TOKEN_STRING",
  "TOKEN_CHAR", "TOKEN_IDENTIFIER", "TOKEN_RETURN", "TOKEN_FINAL",
  "TOKEN_LEFT_SHIFT", "TOKEN_RIGHT_SHIFT", "TOKEN_EQ", "TOKEN_NE",
  "TOKEN_GE", "TOKEN_LE", "TOKEN_AND", "TOKEN_OR", "TOKEN_PLUS_ASSIGN",
  "TOKEN_MINUS_ASSIGN", "TOKEN_MULT_ASSIGN", "TOKEN_DIV_ASSIGN",
  "TOKEN_MOD_ASSIGN", "TOKEN_AND_ASSIGN", "TOKEN_OR_ASSIGN",
  "TOKEN_XOR_ASSIGN", "TOKEN_LSHIFT_ASSIGN", "TOKEN_RSHIFT_ASSIGN",
  "TOKEN_SWITCH", "TOKEN_CASE", "TOKEN_BREAK", "TOKEN_DEFAULT",
  "TOKEN_WHILE", "TOKEN_CONTINUE", "TOKEN_FOR", "TOKEN_NEW", "'+'", "'-'",
  "'*'", "'/'", "'%'", "NEG", "';'", "'('", "')'", "','", "'{'", "'}'",
  "'='", "'['", "']'", "':'", "'&'", "'|'", "'^'", "'~'", "'>'", "'<'",
  "'!'", "'.'", "$accept", "s", "lSentencia", "sentencia", "lista_Expr",
  "imprimir", "bloque", "declaracion_var", "declaracion_const",
  "asignacion", "sentencia_if", "lista_parametros", "sentencia_funcion",
  "sentencia_switch", "lista_casos", "caso", "sentencia_while",
  "sentencia_for", "expr", "primitivo", "tipoPrimitivo", "tipoArray",
  "declaracion_array", "lista_elementos", "acceso_array", "tipoMatrix",
  "declaracion_matrix", "lista_filas", "lista_fila", "acceso_matrix", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-227)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-65)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     629,    10,  -227,  -227,  -227,  -227,    74,  -227,  -227,  -227,
    1217,   391,    68,    78,  -227,    80,  -227,    90,   629,    52,
     527,    49,  -227,   101,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,    26,    18,  -227,   142,  -227,   391,   391,   391,
     391,   391,   391,   391,   391,   391,   391,   391,   391,   321,
     391,   391,  -227,  -227,    96,    98,   102,   104,   105,  -227,
    -227,  -227,  -227,  -227,    39,   391,   305,   391,   391,  1216,
    -227,  -227,  -227,   144,   391,   391,    92,   579,  -227,   114,
     118,   123,   101,  -227,  -227,  -227,  -227,  -227,   159,    41,
     119,   122,   125,     5,  1216,   630,  1216,  1216,  1216,  1216,
    1216,  1216,  1216,  1216,  1216,  1216,  -227,    51,  1216,   678,
     164,   167,   168,   169,   170,   348,   391,   537,   134,   135,
     136,   137,   139,   709,   537,   537,   391,   391,   391,   391,
     391,   391,   391,   391,   391,   391,   391,   391,   391,   391,
     391,   391,   391,   391,   138,   757,   768,   391,   143,   177,
    -227,  -227,  -227,  -227,   150,    72,   391,   145,    -3,    48,
    -227,   391,   149,  -227,    37,   153,   154,   157,   158,   160,
    -227,    91,   816,   391,   391,   391,   391,   391,  -227,  1216,
    1216,  1216,  1216,  1216,  1216,  1216,  1216,   210,   210,   537,
     537,   537,  1216,  1216,  1216,  1216,  1216,   391,   162,   149,
     825,   391,    71,    76,   149,  -227,    93,   197,  1216,   161,
      68,   391,    68,   163,  1216,   219,   391,   391,   391,   391,
     391,   391,   391,  -227,   166,  1216,  1216,  1216,  1216,  1216,
    1216,     0,  -227,   -16,   873,   391,   149,    95,  -227,   149,
      68,   171,  -227,   180,  1216,    79,   183,   391,    83,  -227,
       2,  1216,   881,   929,   940,   988,    97,   999,   109,   391,
     391,   165,   -23,  -227,   -22,   149,   173,   -14,  1047,  -227,
     149,  -227,  -227,   391,   391,  -227,   391,    84,   163,  -227,
    -227,  -227,   186,  -227,  -227,  -227,  -227,  -227,  -227,  1056,
    1104,   629,  -227,  -227,  -227,   149,   149,   192,   149,  -227,
    1112,  1216,  1160,  -227,  -227,   391,  -227,   629,   422,  -227,
    -227,   149,  -227,  -227,   188,  1216,   474,  -227,   391,  1168,
    -227
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,   118,   119,   120,   117,     0,   121,   122,   123,
       0,    29,     0,     0,    27,     0,    28,     0,     0,     0,
       0,     0,    17,     7,    19,    20,    23,     9,    24,    11,
      13,    15,     0,     0,    21,     0,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   115,   116,     0,     0,     0,     0,     0,   110,
     112,   113,   111,   114,    99,     0,     0,     0,     0,    30,
      98,   108,   109,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     6,     8,    10,    12,    14,     5,     0,    35,
       0,     0,     0,     0,    32,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    26,     0,    38,     0,
       0,     0,     0,     0,     0,     0,     0,    82,     0,     0,
       0,     0,     0,     0,    83,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     3,    16,     4,     0,     0,     0,   124,     0,     0,
      33,     0,     0,    25,     0,     0,     0,     0,     0,     0,
     101,     0,     0,     0,     0,     0,     0,     0,    81,    79,
      80,    84,    85,    88,    89,    90,    91,    71,    72,    73,
      74,    75,    76,    77,    78,    86,    87,     0,     0,     0,
       0,     0,    35,     0,     0,    55,     0,     0,    36,     0,
       0,     0,     0,     0,    31,    51,     0,     0,     0,     0,
       0,     0,     0,   100,   129,    94,    95,    96,    93,    97,
      37,     0,    65,     0,     0,     0,     0,     0,    59,     0,
       0,    35,   130,     0,   128,     0,     0,     0,     0,   134,
       0,    39,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     0,    62,     0,     0,     0,     0,     0,    57,
       0,    58,    54,     0,     0,   126,     0,     0,     0,   132,
      52,    53,     0,   102,   103,   104,   106,   105,   107,     0,
       0,     0,    60,    61,    69,     0,     0,     0,     0,    56,
       0,   127,     0,   135,   133,     0,   136,     0,     0,    68,
      67,     0,    70,   125,     0,    40,     0,    66,     0,     0,
     131
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -227,  -227,    -5,   -17,   -45,  -227,   -19,   -70,  -227,  -226,
     -18,    27,  -227,   -15,  -227,    -6,   -12,    -8,   -11,  -227,
      13,  -227,  -227,    11,  -227,  -227,  -227,  -227,   -21,  -227
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,    93,    22,    23,    24,    25,    26,
      27,   206,    28,    29,   262,   263,    30,    31,    94,    70,
      32,    33,    34,   245,    71,    35,    36,   248,   249,    72
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      69,    82,    83,    81,   107,    84,   148,   266,    85,   264,
       6,   264,    86,    77,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,   260,    73,   261,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    88,   108,
     109,   297,   292,    91,    50,    51,   265,   260,   296,   261,
     210,    89,    78,    79,   117,   123,   124,   125,    82,    83,
      81,   211,    84,   145,   146,    85,    18,   160,   161,    86,
     171,    37,     2,     3,     4,     5,     2,     3,     4,     5,
       2,     3,     4,     5,     7,   205,     8,     9,     7,   149,
       8,     9,     7,    90,     8,     9,     2,     3,     4,     5,
     115,   212,   155,   216,   217,   172,   116,   156,     7,    87,
       8,     9,   213,   163,   161,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   205,   204,    38,   200,   156,   236,    74,
     235,    75,   274,   215,   275,   208,   278,   274,   279,   303,
     214,    76,   147,   223,   161,   239,   240,   270,   240,   286,
     161,   -18,   225,   226,   227,   228,   229,    92,   207,   144,
     272,   288,   161,   110,   151,   111,   256,   258,   152,   112,
     232,   113,   114,   153,   154,   238,   230,   157,   158,   165,
     234,   159,   166,   167,   168,   169,   173,   174,   175,   176,
     244,   177,   202,   201,   197,   251,   252,   253,   254,   255,
     257,   203,   209,    18,   218,   219,   207,   269,   220,   221,
     271,   222,   241,   243,   268,   246,   231,   247,   250,   242,
     237,   280,   281,   259,   291,   295,   244,   156,   126,   127,
     128,   129,   130,   131,   132,   133,   294,   273,   289,   290,
     276,   299,   305,   207,   311,   318,   293,   304,   277,     0,
       0,     0,   300,   301,     0,   302,   136,   137,   138,     0,
       0,     0,     0,     0,     0,     0,   309,   310,     0,   312,
     139,   140,   141,     0,   142,   143,   308,     0,     0,    82,
      83,    81,   317,    84,   315,     0,    85,    82,    83,    81,
      86,    84,   316,     0,    85,     0,     0,   319,    86,   118,
     119,   120,   121,     0,     0,    52,    53,     0,    54,    55,
      56,    57,    58,     0,   122,    59,    60,    61,    62,    63,
      64,    52,    53,     0,    54,    55,    56,    57,    58,     0,
       0,    59,    60,    61,    62,    63,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,    53,
      65,    54,    55,    56,    57,    58,    66,     0,    59,    60,
      61,    62,    63,    64,     0,     0,    65,     0,    67,     0,
       0,    68,    66,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,     0,     0,    68,     0,     0,
       0,    52,    53,    65,    54,    55,    56,    57,    58,    66,
     170,    59,    60,    61,    62,    63,    64,     0,     0,     0,
       0,    67,     0,    80,    68,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     0,     0,     0,     0,     7,     0,
       8,     9,     0,     0,     0,     0,    65,    10,    11,    12,
       0,     0,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,     0,     0,    68,    13,   -64,
      14,   -64,    15,    16,    17,    80,     0,     1,     2,     3,
       4,     5,     6,     0,     0,     0,    18,   -64,     0,     0,
       7,     0,     8,     9,     0,     0,     0,     0,     0,    10,
      11,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,   -63,    14,   -63,    15,    16,    17,    -2,    80,     0,
       1,     2,     3,     4,     5,     6,     0,     0,    18,   -63,
       0,     0,     0,     7,     0,     8,     9,     0,     0,     0,
       0,     0,    10,    11,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,   127,   128,   129,   130,
     131,   132,   133,    13,     0,    14,     0,    15,    16,    17,
      80,     0,     1,     2,     3,     4,     5,     6,     0,     0,
       0,    18,     0,     0,     0,     7,     0,     8,     9,     0,
       0,     0,     0,     0,    10,    11,    12,   139,   140,   141,
       0,   142,   143,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0,    14,     0,    15,
      16,    17,     1,     2,     3,     4,     5,     6,     0,     0,
       0,     0,     0,    18,   150,     7,     0,     8,     9,     0,
       0,     0,     0,     0,    10,    11,    12,     0,   126,   127,
     128,   129,   130,   131,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0,    14,     0,    15,
      16,    17,     0,     0,   134,   135,   136,   137,   138,     0,
       0,     0,   162,    18,     0,     0,     0,     0,     0,     0,
     139,   140,   141,     0,   142,   143,   126,   127,   128,   129,
     130,   131,   132,   133,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   126,   127,   128,
     129,   130,   131,   132,   133,     0,   164,     0,   139,   140,
     141,     0,   142,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   135,   136,   137,   138,     0,     0,
       0,   178,     0,     0,     0,     0,     0,     0,     0,   139,
     140,   141,     0,   142,   143,   126,   127,   128,   129,   130,
     131,   132,   133,     0,     0,     0,   126,   127,   128,   129,
     130,   131,   132,   133,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,     0,     0,     0,   198,
       0,     0,   134,   135,   136,   137,   138,   139,   140,   141,
     199,   142,   143,     0,     0,     0,     0,     0,   139,   140,
     141,     0,   142,   143,   126,   127,   128,   129,   130,   131,
     132,   133,     0,   126,   127,   128,   129,   130,   131,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,   136,   137,   138,     0,     0,     0,     0,   134,
     135,   136,   137,   138,   224,   233,   139,   140,   141,     0,
     142,   143,     0,     0,     0,   139,   140,   141,     0,   142,
     143,   126,   127,   128,   129,   130,   131,   132,   133,   126,
     127,   128,   129,   130,   131,   132,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,     0,   267,     0,   134,   135,   136,   137,   138,
       0,     0,     0,   139,   140,   141,     0,   142,   143,   282,
       0,   139,   140,   141,     0,   142,   143,   126,   127,   128,
     129,   130,   131,   132,   133,     0,     0,     0,   126,   127,
     128,   129,   130,   131,   132,   133,     0,     0,     0,     0,
       0,     0,     0,   134,   135,   136,   137,   138,     0,     0,
       0,   283,     0,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   284,   142,   143,     0,     0,     0,     0,     0,
     139,   140,   141,     0,   142,   143,   126,   127,   128,   129,
     130,   131,   132,   133,     0,     0,     0,   126,   127,   128,
     129,   130,   131,   132,   133,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,     0,     0,     0,
     285,     0,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   287,   142,   143,     0,     0,     0,     0,     0,   139,
     140,   141,     0,   142,   143,   126,   127,   128,   129,   130,
     131,   132,   133,     0,   126,   127,   128,   129,   130,   131,
     132,   133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,     0,     0,     0,   298,
     134,   135,   136,   137,   138,     0,     0,   139,   140,   141,
       0,   142,   143,     0,   306,     0,   139,   140,   141,     0,
     142,   143,   126,   127,   128,   129,   130,   131,   132,   133,
     126,   127,   128,   129,   130,   131,   132,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   135,
     136,   137,   138,     0,     0,     0,   134,   135,   136,   137,
     138,     0,     0,   307,   139,   140,   141,     0,   142,   143,
     313,     0,   139,   140,   141,     0,   142,   143,   126,   127,
     128,   129,   130,   131,   132,   133,   126,   127,   128,   129,
     130,   131,   132,   133,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   135,   136,   137,   138,     0,
       0,     0,   134,   135,   136,   137,   138,     0,   314,     0,
     139,   140,   141,     0,   142,   143,   320,     0,   139,   140,
     141,     0,   142,   143,   126,   127,   128,   129,   130,   131,
     132,   133,     0,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,     0,     0,     0,     0,     0,     0,
     134,   135,   136,   137,   138,     0,     0,     0,    49,     0,
       0,     0,     0,    50,    51,     0,   139,   140,   141,     0,
     142,   143
};

static const yytype_int16 yycheck[] =
{
      11,    20,    20,    20,    49,    20,    76,   233,    20,    25,
       8,    25,    20,    18,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    47,    12,    49,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    12,    50,
      51,   267,    65,    25,    66,    67,    62,    47,    62,    49,
      53,    25,     0,     1,    65,    66,    67,    68,    77,    77,
      77,    64,    77,    74,    75,    77,    64,    62,    63,    77,
     115,    61,     4,     5,     6,     7,     4,     5,     6,     7,
       4,     5,     6,     7,    16,   155,    18,    19,    16,    76,
      18,    19,    16,    67,    18,    19,     4,     5,     6,     7,
      61,    53,    61,    66,    67,   116,    67,    66,    16,    60,
      18,    19,    64,    62,    63,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   203,    62,    61,   147,    66,    62,    61,
      69,    61,    63,   162,    65,   156,    63,    63,    65,    65,
     161,    61,    60,    62,    63,    62,    63,    62,    63,    62,
      63,    60,   173,   174,   175,   176,   177,    25,   155,    25,
     240,    62,    63,    77,    60,    77,   221,   222,    60,    77,
     199,    77,    77,    60,    25,   204,   197,    68,    66,    25,
     201,    66,    25,    25,    25,    25,    62,    62,    62,    62,
     211,    62,    25,    60,    66,   216,   217,   218,   219,   220,
     221,    61,    67,    64,    61,    61,   203,   236,    61,    61,
     239,    61,    25,   210,   235,   212,    64,    64,     9,    68,
     203,   250,   250,    67,    69,    62,   247,    66,    28,    29,
      30,    31,    32,    33,    34,    35,   265,    67,   259,   260,
      67,   270,    66,   240,    62,    67,   262,   278,   247,    -1,
      -1,    -1,   273,   274,    -1,   276,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   295,   296,    -1,   298,
      70,    71,    72,    -1,    74,    75,   291,    -1,    -1,   308,
     308,   308,   311,   308,   305,    -1,   308,   316,   316,   316,
     308,   316,   307,    -1,   316,    -1,    -1,   318,   316,     4,
       5,     6,     7,    -1,    -1,    10,    11,    -1,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    10,    11,    -1,    13,    14,    15,    16,    17,    -1,
      -1,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,
      55,    13,    14,    15,    16,    17,    61,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    55,    -1,    73,    -1,
      -1,    76,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    76,    -1,    -1,
      -1,    10,    11,    55,    13,    14,    15,    16,    17,    61,
      62,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    73,    -1,     1,    76,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,
      18,    19,    -1,    -1,    -1,    -1,    55,    25,    26,    27,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    76,    46,    47,
      48,    49,    50,    51,    52,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    64,    65,    -1,    -1,
      16,    -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,     0,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    64,    65,
      -1,    -1,    -1,    16,    -1,    18,    19,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    46,    -1,    48,    -1,    50,    51,    52,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    16,    -1,    18,    19,    -1,
      -1,    -1,    -1,    -1,    25,    26,    27,    70,    71,    72,
      -1,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    48,    -1,    50,
      51,    52,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    64,    65,    16,    -1,    18,    19,    -1,
      -1,    -1,    -1,    -1,    25,    26,    27,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    48,    -1,    50,
      51,    52,    -1,    -1,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    62,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    -1,    74,    75,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    56,    57,    58,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    68,    -1,    70,    71,
      72,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    56,    57,    58,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    74,    75,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    56,    57,    58,    -1,    -1,    -1,    62,
      -1,    -1,    54,    55,    56,    57,    58,    70,    71,    72,
      62,    74,    75,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    -1,    74,    75,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    54,
      55,    56,    57,    58,    68,    60,    70,    71,    72,    -1,
      74,    75,    -1,    -1,    -1,    70,    71,    72,    -1,    74,
      75,    28,    29,    30,    31,    32,    33,    34,    35,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,
      57,    58,    -1,    60,    -1,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    70,    71,    72,    -1,    74,    75,    68,
      -1,    70,    71,    72,    -1,    74,    75,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    56,    57,    58,    -1,    -1,
      -1,    62,    -1,    -1,    54,    55,    56,    57,    58,    70,
      71,    72,    62,    74,    75,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    -1,    74,    75,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      62,    -1,    -1,    54,    55,    56,    57,    58,    70,    71,
      72,    62,    74,    75,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    74,    75,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    56,    57,    58,    -1,    -1,    -1,    62,
      54,    55,    56,    57,    58,    -1,    -1,    70,    71,    72,
      -1,    74,    75,    -1,    68,    -1,    70,    71,    72,    -1,
      74,    75,    28,    29,    30,    31,    32,    33,    34,    35,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
      56,    57,    58,    -1,    -1,    -1,    54,    55,    56,    57,
      58,    -1,    -1,    69,    70,    71,    72,    -1,    74,    75,
      68,    -1,    70,    71,    72,    -1,    74,    75,    28,    29,
      30,    31,    32,    33,    34,    35,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    54,    55,    56,    57,    58,    -1,    68,    -1,
      70,    71,    72,    -1,    74,    75,    68,    -1,    70,    71,
      72,    -1,    74,    75,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    56,    57,    58,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    66,    67,    -1,    70,    71,    72,    -1,
      74,    75
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    16,    18,    19,
      25,    26,    27,    46,    48,    50,    51,    52,    64,    79,
      80,    81,    83,    84,    85,    86,    87,    88,    90,    91,
      94,    95,    98,    99,   100,   103,   104,    61,    61,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    61,
      66,    67,    10,    11,    13,    14,    15,    16,    17,    20,
      21,    22,    23,    24,    25,    55,    61,    73,    76,    96,
      97,   102,   107,    98,    61,    61,    61,    80,     0,     1,
       1,    81,    84,    88,    91,    94,    95,    60,    12,    25,
      67,    25,    25,    82,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    62,    82,    96,    96,
      77,    77,    77,    77,    77,    61,    67,    96,     4,     5,
       6,     7,    19,    96,    96,    96,    28,    29,    30,    31,
      32,    33,    34,    35,    54,    55,    56,    57,    58,    70,
      71,    72,    74,    75,    25,    96,    96,    60,    85,    98,
      65,    60,    60,    60,    25,    61,    66,    68,    66,    66,
      62,    63,    62,    62,    68,    25,    25,    25,    25,    25,
      62,    82,    96,    62,    62,    62,    62,    62,    62,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    66,    62,    62,
      96,    60,    25,    61,    62,    85,    89,    98,    96,    67,
      53,    64,    53,    64,    96,    84,    66,    67,    61,    61,
      61,    61,    61,    62,    68,    96,    96,    96,    96,    96,
      96,    64,    84,    60,    96,    69,    62,    89,    84,    62,
      63,    25,    68,    98,    96,   101,    98,    64,   105,   106,
       9,    96,    96,    96,    96,    96,    82,    96,    82,    67,
      47,    49,    92,    93,    25,    62,    87,    60,    96,    84,
      62,    84,    85,    67,    63,    65,    67,   101,    63,    65,
      84,    88,    68,    62,    62,    62,    62,    62,    62,    96,
      96,    69,    65,    93,    84,    62,    62,    87,    62,    84,
      96,    96,    96,    65,   106,    66,    68,    69,    80,    84,
      84,    62,    84,    68,    68,    96,    80,    84,    67,    96,
      68
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    78,    79,    79,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    82,    82,    83,    84,    85,    85,    86,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    88,    88,    88,    89,    89,    90,    90,    90,    90,
      91,    92,    92,    93,    93,    94,    95,    95,    95,    95,
      95,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    98,    98,    98,
      98,    98,    98,    98,    99,   100,   100,   101,   101,   102,
     103,   104,   104,   105,   105,   106,   107
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     2,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     1,     1,     1,
       2,     3,     1,     4,     3,     2,     4,     5,     3,     6,
       9,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     7,     7,     3,     1,     7,     6,     6,     5,
       7,     2,     1,     4,     3,     5,     9,     8,     8,     7,
       8,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     4,     4,     4,     4,     4,     1,     1,
       4,     3,     6,     6,     6,     6,     6,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     8,     6,     3,     1,     4,
       5,    11,     6,     3,     1,     3,     7
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* s: lSentencia  */
#line 57 "src/entriesTools/parser.y"
               { ast_root = (yyvsp[0].nodo); (yyval.nodo) = (yyvsp[0].nodo); }
#line 1707 "build/parser.tab.c"
    break;

  case 3: /* s: s error ';'  */
#line 58 "src/entriesTools/parser.y"
                  { yyerrok; }
#line 1713 "build/parser.tab.c"
    break;

  case 4: /* lSentencia: lSentencia sentencia ';'  */
#line 62 "src/entriesTools/parser.y"
                                     { agregarHijo((yyvsp[-2].nodo), (yyvsp[-1].nodo)); (yyval.nodo) = (yyvsp[-2].nodo);}
#line 1719 "build/parser.tab.c"
    break;

  case 5: /* lSentencia: sentencia ';'  */
#line 63 "src/entriesTools/parser.y"
                    {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[-1].nodo));
        (yyval.nodo) =  b;
    }
#line 1729 "build/parser.tab.c"
    break;

  case 6: /* lSentencia: lSentencia bloque  */
#line 68 "src/entriesTools/parser.y"
                        { agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1735 "build/parser.tab.c"
    break;

  case 7: /* lSentencia: bloque  */
#line 69 "src/entriesTools/parser.y"
             {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 1745 "build/parser.tab.c"
    break;

  case 8: /* lSentencia: lSentencia sentencia_if  */
#line 74 "src/entriesTools/parser.y"
                              { agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1751 "build/parser.tab.c"
    break;

  case 9: /* lSentencia: sentencia_if  */
#line 75 "src/entriesTools/parser.y"
                   {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 1761 "build/parser.tab.c"
    break;

  case 10: /* lSentencia: lSentencia sentencia_switch  */
#line 80 "src/entriesTools/parser.y"
                                  { agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1767 "build/parser.tab.c"
    break;

  case 11: /* lSentencia: sentencia_switch  */
#line 81 "src/entriesTools/parser.y"
                       {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 1777 "build/parser.tab.c"
    break;

  case 12: /* lSentencia: lSentencia sentencia_while  */
#line 86 "src/entriesTools/parser.y"
                                 { agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1783 "build/parser.tab.c"
    break;

  case 13: /* lSentencia: sentencia_while  */
#line 87 "src/entriesTools/parser.y"
                      {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 1793 "build/parser.tab.c"
    break;

  case 14: /* lSentencia: lSentencia sentencia_for  */
#line 92 "src/entriesTools/parser.y"
                               { agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1799 "build/parser.tab.c"
    break;

  case 15: /* lSentencia: sentencia_for  */
#line 93 "src/entriesTools/parser.y"
                    {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 1809 "build/parser.tab.c"
    break;

  case 16: /* lSentencia: lSentencia error ';'  */
#line 98 "src/entriesTools/parser.y"
                           { yyerrok; (yyval.nodo) = (yyvsp[-2].nodo); }
#line 1815 "build/parser.tab.c"
    break;

  case 17: /* sentencia: imprimir  */
#line 101 "src/entriesTools/parser.y"
                    {(yyval.nodo) = (yyvsp[0].nodo); }
#line 1821 "build/parser.tab.c"
    break;

  case 18: /* sentencia: bloque  */
#line 102 "src/entriesTools/parser.y"
             {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1827 "build/parser.tab.c"
    break;

  case 19: /* sentencia: declaracion_var  */
#line 103 "src/entriesTools/parser.y"
                      {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1833 "build/parser.tab.c"
    break;

  case 20: /* sentencia: declaracion_const  */
#line 104 "src/entriesTools/parser.y"
                        {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1839 "build/parser.tab.c"
    break;

  case 21: /* sentencia: declaracion_array  */
#line 105 "src/entriesTools/parser.y"
                        {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1845 "build/parser.tab.c"
    break;

  case 22: /* sentencia: declaracion_matrix  */
#line 106 "src/entriesTools/parser.y"
                         {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1851 "build/parser.tab.c"
    break;

  case 23: /* sentencia: asignacion  */
#line 107 "src/entriesTools/parser.y"
                 {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1857 "build/parser.tab.c"
    break;

  case 24: /* sentencia: sentencia_funcion  */
#line 108 "src/entriesTools/parser.y"
                        { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1863 "build/parser.tab.c"
    break;

  case 25: /* sentencia: TOKEN_IDENTIFIER '(' lista_Expr ')'  */
#line 109 "src/entriesTools/parser.y"
                                          { (yyval.nodo) = nuevoLlamadaExpresion((yyvsp[-3].string), (yyvsp[-1].nodo)); }
#line 1869 "build/parser.tab.c"
    break;

  case 26: /* sentencia: TOKEN_IDENTIFIER '(' ')'  */
#line 110 "src/entriesTools/parser.y"
                               { (yyval.nodo) = nuevoLlamadaExpresion((yyvsp[-2].string), NULL); }
#line 1875 "build/parser.tab.c"
    break;

  case 27: /* sentencia: TOKEN_BREAK  */
#line 111 "src/entriesTools/parser.y"
                  { (yyval.nodo) = nuevoBreakExpresion((yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 1881 "build/parser.tab.c"
    break;

  case 28: /* sentencia: TOKEN_CONTINUE  */
#line 112 "src/entriesTools/parser.y"
                     { (yyval.nodo) = nuevoContinueExpresion((yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 1887 "build/parser.tab.c"
    break;

  case 29: /* sentencia: TOKEN_RETURN  */
#line 113 "src/entriesTools/parser.y"
                   { (yyval.nodo) = NULL; }
#line 1893 "build/parser.tab.c"
    break;

  case 30: /* sentencia: TOKEN_RETURN expr  */
#line 114 "src/entriesTools/parser.y"
                        { (yyval.nodo) = nuevoReturnExpresion((yyvsp[0].nodo)); }
#line 1899 "build/parser.tab.c"
    break;

  case 31: /* lista_Expr: lista_Expr ',' expr  */
#line 117 "src/entriesTools/parser.y"
                                 { agregarHijo((yyvsp[-2].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-2].nodo); }
#line 1905 "build/parser.tab.c"
    break;

  case 32: /* lista_Expr: expr  */
#line 118 "src/entriesTools/parser.y"
           { 
                AbstractExpresion* b = nuevoListaExpresiones();
                agregarHijo(b, (yyvsp[0].nodo));
                (yyval.nodo) =  b;
            }
#line 1915 "build/parser.tab.c"
    break;

  case 33: /* imprimir: TOKEN_PRINT '(' lista_Expr ')'  */
#line 125 "src/entriesTools/parser.y"
                                         { (yyval.nodo) =  nuevoPrintExpresion((yyvsp[-1].nodo)); }
#line 1921 "build/parser.tab.c"
    break;

  case 34: /* bloque: '{' lSentencia '}'  */
#line 128 "src/entriesTools/parser.y"
                           { (yyval.nodo) =  (yyvsp[-1].nodo); }
#line 1927 "build/parser.tab.c"
    break;

  case 35: /* declaracion_var: tipoPrimitivo TOKEN_IDENTIFIER  */
#line 131 "src/entriesTools/parser.y"
                                                { (yyval.nodo) = nuevoDeclaracionVariables((yyvsp[-1].tipoDato), (yyvsp[0].string), NULL, (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 1933 "build/parser.tab.c"
    break;

  case 36: /* declaracion_var: tipoPrimitivo TOKEN_IDENTIFIER '=' expr  */
#line 132 "src/entriesTools/parser.y"
                                              { (yyval.nodo) = nuevoDeclaracionVariables((yyvsp[-3].tipoDato), (yyvsp[-2].string), (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1939 "build/parser.tab.c"
    break;

  case 37: /* declaracion_const: TOKEN_FINAL tipoPrimitivo TOKEN_IDENTIFIER '=' expr  */
#line 135 "src/entriesTools/parser.y"
                                                                       { (yyval.nodo) = nuevoDeclaracionConstante((yyvsp[-3].tipoDato), (yyvsp[-2].string), (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1945 "build/parser.tab.c"
    break;

  case 38: /* asignacion: TOKEN_IDENTIFIER '=' expr  */
#line 138 "src/entriesTools/parser.y"
                                      { (yyval.nodo) = nuevoAsignacionExpresion((yyvsp[-2].string), (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1951 "build/parser.tab.c"
    break;

  case 39: /* asignacion: TOKEN_IDENTIFIER '[' expr ']' '=' expr  */
#line 139 "src/entriesTools/parser.y"
                                             { (yyval.nodo) = nuevoAsignacionArrayExpresion((yyvsp[-5].string), (yyvsp[-3].nodo), (yyvsp[0].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column); }
#line 1957 "build/parser.tab.c"
    break;

  case 40: /* asignacion: TOKEN_IDENTIFIER '[' expr ']' '[' expr ']' '=' expr  */
#line 140 "src/entriesTools/parser.y"
                                                          { (yyval.nodo) = nuevoAsignacionMatrixExpresion((yyvsp[-8].string), (yyvsp[-6].nodo), (yyvsp[-3].nodo), (yyvsp[0].nodo), (yylsp[-8]).first_line, (yylsp[-8]).first_column); }
#line 1963 "build/parser.tab.c"
    break;

  case 41: /* asignacion: TOKEN_IDENTIFIER TOKEN_PLUS_ASSIGN expr  */
#line 141 "src/entriesTools/parser.y"
                                              { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_SUMA, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1969 "build/parser.tab.c"
    break;

  case 42: /* asignacion: TOKEN_IDENTIFIER TOKEN_MINUS_ASSIGN expr  */
#line 142 "src/entriesTools/parser.y"
                                               { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_RESTA, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1975 "build/parser.tab.c"
    break;

  case 43: /* asignacion: TOKEN_IDENTIFIER TOKEN_MULT_ASSIGN expr  */
#line 143 "src/entriesTools/parser.y"
                                              { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_MULT, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1981 "build/parser.tab.c"
    break;

  case 44: /* asignacion: TOKEN_IDENTIFIER TOKEN_DIV_ASSIGN expr  */
#line 144 "src/entriesTools/parser.y"
                                             { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_DIV, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1987 "build/parser.tab.c"
    break;

  case 45: /* asignacion: TOKEN_IDENTIFIER TOKEN_MOD_ASSIGN expr  */
#line 145 "src/entriesTools/parser.y"
                                             { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_MOD, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1993 "build/parser.tab.c"
    break;

  case 46: /* asignacion: TOKEN_IDENTIFIER TOKEN_AND_ASSIGN expr  */
#line 146 "src/entriesTools/parser.y"
                                             { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_AND, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1999 "build/parser.tab.c"
    break;

  case 47: /* asignacion: TOKEN_IDENTIFIER TOKEN_OR_ASSIGN expr  */
#line 147 "src/entriesTools/parser.y"
                                            { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_OR, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2005 "build/parser.tab.c"
    break;

  case 48: /* asignacion: TOKEN_IDENTIFIER TOKEN_XOR_ASSIGN expr  */
#line 148 "src/entriesTools/parser.y"
                                             { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_XOR, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2011 "build/parser.tab.c"
    break;

  case 49: /* asignacion: TOKEN_IDENTIFIER TOKEN_LSHIFT_ASSIGN expr  */
#line 149 "src/entriesTools/parser.y"
                                                { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_LSHIFT, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2017 "build/parser.tab.c"
    break;

  case 50: /* asignacion: TOKEN_IDENTIFIER TOKEN_RSHIFT_ASSIGN expr  */
#line 150 "src/entriesTools/parser.y"
                                                { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_RSHIFT, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2023 "build/parser.tab.c"
    break;

  case 51: /* sentencia_if: TOKEN_IF '(' expr ')' bloque  */
#line 153 "src/entriesTools/parser.y"
                                           { (yyval.nodo) = nuevoIfExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2029 "build/parser.tab.c"
    break;

  case 52: /* sentencia_if: TOKEN_IF '(' expr ')' bloque TOKEN_ELSE bloque  */
#line 154 "src/entriesTools/parser.y"
                                                     { (yyval.nodo) = nuevoIfElseExpresion((yyvsp[-4].nodo), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2035 "build/parser.tab.c"
    break;

  case 53: /* sentencia_if: TOKEN_IF '(' expr ')' bloque TOKEN_ELSE sentencia_if  */
#line 155 "src/entriesTools/parser.y"
                                                           { (yyval.nodo) = nuevoElseIfExpresion((yyvsp[-4].nodo), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2041 "build/parser.tab.c"
    break;

  case 54: /* lista_parametros: lista_parametros ',' declaracion_var  */
#line 158 "src/entriesTools/parser.y"
                                                       { agregarHijo((yyvsp[-2].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-2].nodo); }
#line 2047 "build/parser.tab.c"
    break;

  case 55: /* lista_parametros: declaracion_var  */
#line 159 "src/entriesTools/parser.y"
                      { AbstractExpresion* b = nuevoListaParametros();
                agregarHijo(b, (yyvsp[0].nodo));
                (yyval.nodo) =  b; }
#line 2055 "build/parser.tab.c"
    break;

  case 56: /* sentencia_funcion: tipoPrimitivo TOKEN_FUNC TOKEN_IDENTIFIER '(' lista_parametros ')' bloque  */
#line 164 "src/entriesTools/parser.y"
                                                                                             {  (yyval.nodo) = nuevoFuncionExpresion((yyvsp[-6].tipoDato), (yyvsp[-4].string), (yyvsp[-2].nodo), (yyvsp[0].nodo));}
#line 2061 "build/parser.tab.c"
    break;

  case 57: /* sentencia_funcion: tipoPrimitivo TOKEN_FUNC TOKEN_IDENTIFIER '(' ')' bloque  */
#line 165 "src/entriesTools/parser.y"
                                                               {  (yyval.nodo) = nuevoFuncionExpresion((yyvsp[-5].tipoDato), (yyvsp[-3].string), NULL, (yyvsp[0].nodo));}
#line 2067 "build/parser.tab.c"
    break;

  case 58: /* sentencia_funcion: tipoPrimitivo TOKEN_IDENTIFIER '(' lista_parametros ')' bloque  */
#line 166 "src/entriesTools/parser.y"
                                                                     {  (yyval.nodo) = nuevoFuncionExpresion((yyvsp[-5].tipoDato), (yyvsp[-4].string), (yyvsp[-2].nodo), (yyvsp[0].nodo));}
#line 2073 "build/parser.tab.c"
    break;

  case 59: /* sentencia_funcion: tipoPrimitivo TOKEN_IDENTIFIER '(' ')' bloque  */
#line 167 "src/entriesTools/parser.y"
                                                    {  (yyval.nodo) = nuevoFuncionExpresion((yyvsp[-4].tipoDato), (yyvsp[-3].string), NULL, (yyvsp[0].nodo));}
#line 2079 "build/parser.tab.c"
    break;

  case 60: /* sentencia_switch: TOKEN_SWITCH '(' expr ')' '{' lista_casos '}'  */
#line 170 "src/entriesTools/parser.y"
                                                                { (yyval.nodo) = nuevoSwitchExpresion((yyvsp[-4].nodo), (yyvsp[-1].nodo)); }
#line 2085 "build/parser.tab.c"
    break;

  case 61: /* lista_casos: lista_casos caso  */
#line 173 "src/entriesTools/parser.y"
                              { agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2091 "build/parser.tab.c"
    break;

  case 62: /* lista_casos: caso  */
#line 174 "src/entriesTools/parser.y"
           { 
        AbstractExpresion* b = nuevoListaCasos();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 2101 "build/parser.tab.c"
    break;

  case 63: /* caso: TOKEN_CASE expr ':' lSentencia  */
#line 181 "src/entriesTools/parser.y"
                                     { (yyval.nodo) = nuevoCaseExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2107 "build/parser.tab.c"
    break;

  case 64: /* caso: TOKEN_DEFAULT ':' lSentencia  */
#line 182 "src/entriesTools/parser.y"
                                   { (yyval.nodo) = nuevoDefaultExpresion((yyvsp[0].nodo)); }
#line 2113 "build/parser.tab.c"
    break;

  case 65: /* sentencia_while: TOKEN_WHILE '(' expr ')' bloque  */
#line 185 "src/entriesTools/parser.y"
                                                 { (yyval.nodo) = nuevoWhileExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2119 "build/parser.tab.c"
    break;

  case 66: /* sentencia_for: TOKEN_FOR '(' declaracion_var ';' expr ';' asignacion ')' bloque  */
#line 188 "src/entriesTools/parser.y"
                                                                                { (yyval.nodo) = nuevoForExpresion((yyvsp[-6].nodo), (yyvsp[-4].nodo), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2125 "build/parser.tab.c"
    break;

  case 67: /* sentencia_for: TOKEN_FOR '(' declaracion_var ';' expr ';' ')' bloque  */
#line 189 "src/entriesTools/parser.y"
                                                            { (yyval.nodo) = nuevoForExpresion((yyvsp[-5].nodo), (yyvsp[-3].nodo), NULL, (yyvsp[0].nodo)); }
#line 2131 "build/parser.tab.c"
    break;

  case 68: /* sentencia_for: TOKEN_FOR '(' ';' expr ';' asignacion ')' bloque  */
#line 190 "src/entriesTools/parser.y"
                                                       { (yyval.nodo) = nuevoForExpresion(NULL, (yyvsp[-4].nodo), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2137 "build/parser.tab.c"
    break;

  case 69: /* sentencia_for: TOKEN_FOR '(' ';' expr ';' ')' bloque  */
#line 191 "src/entriesTools/parser.y"
                                            { (yyval.nodo) = nuevoForExpresion(NULL, (yyvsp[-3].nodo), NULL, (yyvsp[0].nodo)); }
#line 2143 "build/parser.tab.c"
    break;

  case 70: /* sentencia_for: TOKEN_FOR '(' tipoPrimitivo TOKEN_IDENTIFIER ':' expr ')' bloque  */
#line 192 "src/entriesTools/parser.y"
                                                                       { (yyval.nodo) = nuevoForEachExpresion((yyvsp[-5].tipoDato), (yyvsp[-4].string), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2149 "build/parser.tab.c"
    break;

  case 71: /* expr: expr '+' expr  */
#line 211 "src/entriesTools/parser.y"
                      { (yyval.nodo) =  nuevoSumaExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo));  }
#line 2155 "build/parser.tab.c"
    break;

  case 72: /* expr: expr '-' expr  */
#line 212 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoRestaExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2161 "build/parser.tab.c"
    break;

  case 73: /* expr: expr '*' expr  */
#line 213 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoMultiplicacionExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2167 "build/parser.tab.c"
    break;

  case 74: /* expr: expr '/' expr  */
#line 214 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoDivisionExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2173 "build/parser.tab.c"
    break;

  case 75: /* expr: expr '%' expr  */
#line 215 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoModuloExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2179 "build/parser.tab.c"
    break;

  case 76: /* expr: expr '&' expr  */
#line 216 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoBitwiseAndExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2185 "build/parser.tab.c"
    break;

  case 77: /* expr: expr '|' expr  */
#line 217 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoBitwiseOrExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2191 "build/parser.tab.c"
    break;

  case 78: /* expr: expr '^' expr  */
#line 218 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoBitwiseXorExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2197 "build/parser.tab.c"
    break;

  case 79: /* expr: expr TOKEN_LEFT_SHIFT expr  */
#line 219 "src/entriesTools/parser.y"
                                 { (yyval.nodo) =  nuevoBitwiseLeftShiftExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2203 "build/parser.tab.c"
    break;

  case 80: /* expr: expr TOKEN_RIGHT_SHIFT expr  */
#line 220 "src/entriesTools/parser.y"
                                  { (yyval.nodo) =  nuevoBitwiseRightShiftExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2209 "build/parser.tab.c"
    break;

  case 81: /* expr: '(' expr ')'  */
#line 221 "src/entriesTools/parser.y"
                   { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2215 "build/parser.tab.c"
    break;

  case 82: /* expr: '-' expr  */
#line 222 "src/entriesTools/parser.y"
                          { (yyval.nodo) =  nuevoUnarioExpresion((yyvsp[0].nodo));  }
#line 2221 "build/parser.tab.c"
    break;

  case 83: /* expr: '~' expr  */
#line 223 "src/entriesTools/parser.y"
                          { (yyval.nodo) =  nuevoBitwiseNotExpresion((yyvsp[0].nodo));  }
#line 2227 "build/parser.tab.c"
    break;

  case 84: /* expr: expr TOKEN_EQ expr  */
#line 224 "src/entriesTools/parser.y"
                         { (yyval.nodo) = nuevoIgualdadExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2233 "build/parser.tab.c"
    break;

  case 85: /* expr: expr TOKEN_NE expr  */
#line 225 "src/entriesTools/parser.y"
                         { (yyval.nodo) = nuevoDesigualdadExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2239 "build/parser.tab.c"
    break;

  case 86: /* expr: expr '>' expr  */
#line 226 "src/entriesTools/parser.y"
                    { (yyval.nodo) = nuevoMayorQueExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2245 "build/parser.tab.c"
    break;

  case 87: /* expr: expr '<' expr  */
#line 227 "src/entriesTools/parser.y"
                    { (yyval.nodo) = nuevoMenorQueExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2251 "build/parser.tab.c"
    break;

  case 88: /* expr: expr TOKEN_GE expr  */
#line 228 "src/entriesTools/parser.y"
                         { (yyval.nodo) = nuevoMayorIgualExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2257 "build/parser.tab.c"
    break;

  case 89: /* expr: expr TOKEN_LE expr  */
#line 229 "src/entriesTools/parser.y"
                         { (yyval.nodo) = nuevoMenorIgualExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2263 "build/parser.tab.c"
    break;

  case 90: /* expr: expr TOKEN_AND expr  */
#line 230 "src/entriesTools/parser.y"
                          { (yyval.nodo) = nuevoLogicAndExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2269 "build/parser.tab.c"
    break;

  case 91: /* expr: expr TOKEN_OR expr  */
#line 231 "src/entriesTools/parser.y"
                         { (yyval.nodo) = nuevoLogicOrExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2275 "build/parser.tab.c"
    break;

  case 92: /* expr: '!' expr  */
#line 232 "src/entriesTools/parser.y"
                         { (yyval.nodo) = nuevoLogicNotExpresion((yyvsp[0].nodo)); }
#line 2281 "build/parser.tab.c"
    break;

  case 93: /* expr: '(' TOKEN_DVOID ')' expr  */
#line 233 "src/entriesTools/parser.y"
                               { (yyval.nodo) = nuevoCastingExpresion((yyvsp[0].nodo), VOID); }
#line 2287 "build/parser.tab.c"
    break;

  case 94: /* expr: '(' TOKEN_DINT ')' expr  */
#line 234 "src/entriesTools/parser.y"
                              { (yyval.nodo) = nuevoCastingExpresion((yyvsp[0].nodo), INT); }
#line 2293 "build/parser.tab.c"
    break;

  case 95: /* expr: '(' TOKEN_DFLOAT ')' expr  */
#line 235 "src/entriesTools/parser.y"
                                { (yyval.nodo) = nuevoCastingExpresion((yyvsp[0].nodo), FLOAT); }
#line 2299 "build/parser.tab.c"
    break;

  case 96: /* expr: '(' TOKEN_DDOUBLE ')' expr  */
#line 236 "src/entriesTools/parser.y"
                                 { (yyval.nodo) = nuevoCastingExpresion((yyvsp[0].nodo), DOUBLE); }
#line 2305 "build/parser.tab.c"
    break;

  case 97: /* expr: '(' TOKEN_DCHAR ')' expr  */
#line 237 "src/entriesTools/parser.y"
                               { (yyval.nodo) = nuevoCastingExpresion((yyvsp[0].nodo), CHAR); }
#line 2311 "build/parser.tab.c"
    break;

  case 98: /* expr: primitivo  */
#line 238 "src/entriesTools/parser.y"
                { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2317 "build/parser.tab.c"
    break;

  case 99: /* expr: TOKEN_IDENTIFIER  */
#line 239 "src/entriesTools/parser.y"
                       { (yyval.nodo) = nuevoIdentificadorExpresion((yyvsp[0].string), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2323 "build/parser.tab.c"
    break;

  case 100: /* expr: TOKEN_IDENTIFIER '(' lista_Expr ')'  */
#line 240 "src/entriesTools/parser.y"
                                          { (yyval.nodo) = nuevoLlamadaExpresion((yyvsp[-3].string), (yyvsp[-1].nodo)); }
#line 2329 "build/parser.tab.c"
    break;

  case 101: /* expr: TOKEN_IDENTIFIER '(' ')'  */
#line 241 "src/entriesTools/parser.y"
                               { (yyval.nodo) = nuevoLlamadaExpresion((yyvsp[-2].string), NULL); }
#line 2335 "build/parser.tab.c"
    break;

  case 102: /* expr: TOKEN_INTEGER '.' TOKEN_IDENTIFIER '(' expr ')'  */
#line 242 "src/entriesTools/parser.y"
                                                      { 
        if (strcmp((yyvsp[-3].string), "parseInt") == 0) {
            (yyval.nodo) = nuevoIntegerParseIntExpresion((yyvsp[-1].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        } else {
            yyerror("Método no reconocido en clase Integer");
            (yyval.nodo) = NULL;
        }
    }
#line 2348 "build/parser.tab.c"
    break;

  case 103: /* expr: TOKEN_DOUBLE_CLASS '.' TOKEN_IDENTIFIER '(' expr ')'  */
#line 250 "src/entriesTools/parser.y"
                                                           { 
        if (strcmp((yyvsp[-3].string), "parseDouble") == 0) {
            (yyval.nodo) = nuevoDoubleParseDoubleExpresion((yyvsp[-1].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        } else {
            yyerror("Método no reconocido en clase Double");
            (yyval.nodo) = NULL;
        }
    }
#line 2361 "build/parser.tab.c"
    break;

  case 104: /* expr: TOKEN_FLOAT_CLASS '.' TOKEN_IDENTIFIER '(' expr ')'  */
#line 258 "src/entriesTools/parser.y"
                                                          { 
        if (strcmp((yyvsp[-3].string), "parseFloat") == 0) {
            (yyval.nodo) = nuevoFloatParseFloatExpresion((yyvsp[-1].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        } else {
            yyerror("Método no reconocido en clase Float");
            (yyval.nodo) = NULL;
        }
    }
#line 2374 "build/parser.tab.c"
    break;

  case 105: /* expr: TOKEN_STRING_CLASS '.' TOKEN_IDENTIFIER '(' expr ')'  */
#line 266 "src/entriesTools/parser.y"
                                                           { 
        if (strcmp((yyvsp[-3].string), "valueOf") == 0) {
            (yyval.nodo) = nuevoStringValueOfExpresion((yyvsp[-1].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        } else {
            yyerror("Método no reconocido en clase String");
            (yyval.nodo) = NULL;
        }
    }
#line 2387 "build/parser.tab.c"
    break;

  case 106: /* expr: TOKEN_STRING_CLASS '.' TOKEN_IDENTIFIER '(' lista_Expr ')'  */
#line 274 "src/entriesTools/parser.y"
                                                                 { 
        if (strcmp((yyvsp[-3].string), "join") == 0) {
            (yyval.nodo) = nuevoStringJoinExpresion((yyvsp[-1].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        } else {
            yyerror("Método no reconocido en clase String");
            (yyval.nodo) = NULL;
        }
    }
#line 2400 "build/parser.tab.c"
    break;

  case 107: /* expr: TOKEN_ARRAYS '.' TOKEN_IDENTIFIER '(' lista_Expr ')'  */
#line 282 "src/entriesTools/parser.y"
                                                           { 
        if (strcmp((yyvsp[-3].string), "indexOf") == 0) {
            (yyval.nodo) = nuevoArraysIndexOfExpresion((yyvsp[-1].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        } else {
            yyerror("Método no reconocido en clase Arrays");
            (yyval.nodo) = NULL;
        }
    }
#line 2413 "build/parser.tab.c"
    break;

  case 108: /* expr: acceso_array  */
#line 290 "src/entriesTools/parser.y"
                   { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2419 "build/parser.tab.c"
    break;

  case 109: /* expr: acceso_matrix  */
#line 291 "src/entriesTools/parser.y"
                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2425 "build/parser.tab.c"
    break;

  case 110: /* primitivo: TOKEN_UNSIGNED_INTEGER  */
#line 295 "src/entriesTools/parser.y"
                                  { (yyval.nodo) =  nuevoPrimitivoExpresion((yyvsp[0].string), INT); }
#line 2431 "build/parser.tab.c"
    break;

  case 111: /* primitivo: TOKEN_STRING  */
#line 296 "src/entriesTools/parser.y"
                   { (yyval.nodo) =  nuevoPrimitivoExpresion((yyvsp[0].string), STRING); }
#line 2437 "build/parser.tab.c"
    break;

  case 112: /* primitivo: TOKEN_REAL  */
#line 297 "src/entriesTools/parser.y"
                 { (yyval.nodo) =  nuevoPrimitivoExpresion((yyvsp[0].string), FLOAT); }
#line 2443 "build/parser.tab.c"
    break;

  case 113: /* primitivo: TOKEN_DOUBLE  */
#line 298 "src/entriesTools/parser.y"
                   { (yyval.nodo) =  nuevoPrimitivoExpresion((yyvsp[0].string), DOUBLE); }
#line 2449 "build/parser.tab.c"
    break;

  case 114: /* primitivo: TOKEN_CHAR  */
#line 299 "src/entriesTools/parser.y"
                 { (yyval.nodo) =  nuevoPrimitivoExpresion((yyvsp[0].string), CHAR); }
#line 2455 "build/parser.tab.c"
    break;

  case 115: /* primitivo: TOKEN_TRUE  */
#line 300 "src/entriesTools/parser.y"
                 { (yyval.nodo) =  nuevoPrimitivoExpresion("T", BOOLEAN); }
#line 2461 "build/parser.tab.c"
    break;

  case 116: /* primitivo: TOKEN_FALSE  */
#line 301 "src/entriesTools/parser.y"
                  { (yyval.nodo) =  nuevoPrimitivoExpresion("F", BOOLEAN); }
#line 2467 "build/parser.tab.c"
    break;

  case 117: /* tipoPrimitivo: TOKEN_DVOID  */
#line 304 "src/entriesTools/parser.y"
                           { (yyval.tipoDato) = VOID; }
#line 2473 "build/parser.tab.c"
    break;

  case 118: /* tipoPrimitivo: TOKEN_DINT  */
#line 305 "src/entriesTools/parser.y"
                 { (yyval.tipoDato) = INT; }
#line 2479 "build/parser.tab.c"
    break;

  case 119: /* tipoPrimitivo: TOKEN_DFLOAT  */
#line 306 "src/entriesTools/parser.y"
                   { (yyval.tipoDato) = FLOAT; }
#line 2485 "build/parser.tab.c"
    break;

  case 120: /* tipoPrimitivo: TOKEN_DDOUBLE  */
#line 307 "src/entriesTools/parser.y"
                    { (yyval.tipoDato) = DOUBLE; }
#line 2491 "build/parser.tab.c"
    break;

  case 121: /* tipoPrimitivo: TOKEN_STRING_CLASS  */
#line 308 "src/entriesTools/parser.y"
                         { (yyval.tipoDato) = STRING; }
#line 2497 "build/parser.tab.c"
    break;

  case 122: /* tipoPrimitivo: TOKEN_DBOOLEAN  */
#line 309 "src/entriesTools/parser.y"
                     { (yyval.tipoDato) = BOOLEAN; }
#line 2503 "build/parser.tab.c"
    break;

  case 123: /* tipoPrimitivo: TOKEN_DCHAR  */
#line 310 "src/entriesTools/parser.y"
                  { (yyval.tipoDato) = CHAR; }
#line 2509 "build/parser.tab.c"
    break;

  case 124: /* tipoArray: tipoPrimitivo '[' ']'  */
#line 314 "src/entriesTools/parser.y"
                                 { (yyval.tipoDato) = (yyvsp[-2].tipoDato); }
#line 2515 "build/parser.tab.c"
    break;

  case 125: /* declaracion_array: tipoArray TOKEN_IDENTIFIER '=' TOKEN_NEW tipoPrimitivo '[' expr ']'  */
#line 317 "src/entriesTools/parser.y"
                                                                                       { (yyval.nodo) = nuevoDeclaracionArrayNew((yyvsp[-7].tipoDato), (yyvsp[-6].string), (yyvsp[-3].tipoDato), (yyvsp[-1].nodo), (yylsp[-6]).first_line, (yylsp[-6]).first_column); }
#line 2521 "build/parser.tab.c"
    break;

  case 126: /* declaracion_array: tipoArray TOKEN_IDENTIFIER '=' '{' lista_elementos '}'  */
#line 318 "src/entriesTools/parser.y"
                                                             { (yyval.nodo) = nuevoDeclaracionArrayInit((yyvsp[-5].tipoDato), (yyvsp[-4].string), (yyvsp[-1].nodo), (yylsp[-4]).first_line, (yylsp[-4]).first_column); }
#line 2527 "build/parser.tab.c"
    break;

  case 127: /* lista_elementos: lista_elementos ',' expr  */
#line 321 "src/entriesTools/parser.y"
                                          { agregarHijo((yyvsp[-2].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-2].nodo); }
#line 2533 "build/parser.tab.c"
    break;

  case 128: /* lista_elementos: expr  */
#line 322 "src/entriesTools/parser.y"
           { 
        AbstractExpresion* b = nuevoListaElementos();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 2543 "build/parser.tab.c"
    break;

  case 129: /* acceso_array: TOKEN_IDENTIFIER '[' expr ']'  */
#line 329 "src/entriesTools/parser.y"
                                            { (yyval.nodo) = nuevoAccesoArrayExpresion((yyvsp[-3].string), (yyvsp[-1].nodo), (yylsp[-3]).first_line, (yylsp[-3]).first_column); }
#line 2549 "build/parser.tab.c"
    break;

  case 130: /* tipoMatrix: tipoPrimitivo '[' ']' '[' ']'  */
#line 333 "src/entriesTools/parser.y"
                                          { (yyval.tipoDato) = (yyvsp[-4].tipoDato); }
#line 2555 "build/parser.tab.c"
    break;

  case 131: /* declaracion_matrix: tipoMatrix TOKEN_IDENTIFIER '=' TOKEN_NEW tipoPrimitivo '[' expr ']' '[' expr ']'  */
#line 336 "src/entriesTools/parser.y"
                                                                                                      { (yyval.nodo) = nuevoDeclaracionMatrixNew((yyvsp[-10].tipoDato), (yyvsp[-9].string), (yyvsp[-6].tipoDato), (yyvsp[-4].nodo), (yyvsp[-1].nodo), (yylsp[-9]).first_line, (yylsp[-9]).first_column); }
#line 2561 "build/parser.tab.c"
    break;

  case 132: /* declaracion_matrix: tipoMatrix TOKEN_IDENTIFIER '=' '{' lista_filas '}'  */
#line 337 "src/entriesTools/parser.y"
                                                          { (yyval.nodo) = nuevoDeclaracionMatrixInit((yyvsp[-5].tipoDato), (yyvsp[-4].string), (yyvsp[-1].nodo), (yylsp[-4]).first_line, (yylsp[-4]).first_column); }
#line 2567 "build/parser.tab.c"
    break;

  case 133: /* lista_filas: lista_filas ',' lista_fila  */
#line 340 "src/entriesTools/parser.y"
                                        { agregarHijo((yyvsp[-2].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-2].nodo); }
#line 2573 "build/parser.tab.c"
    break;

  case 134: /* lista_filas: lista_fila  */
#line 341 "src/entriesTools/parser.y"
                 { 
        AbstractExpresion* b = nuevoListaFilas();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 2583 "build/parser.tab.c"
    break;

  case 135: /* lista_fila: '{' lista_elementos '}'  */
#line 348 "src/entriesTools/parser.y"
                                    { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2589 "build/parser.tab.c"
    break;

  case 136: /* acceso_matrix: TOKEN_IDENTIFIER '[' expr ']' '[' expr ']'  */
#line 351 "src/entriesTools/parser.y"
                                                          { (yyval.nodo) = nuevoAccesoMatrixExpresion((yyvsp[-6].string), (yyvsp[-4].nodo), (yyvsp[-1].nodo), (yylsp[-6]).first_line, (yylsp[-6]).first_column); }
#line 2595 "build/parser.tab.c"
    break;


#line 2599 "build/parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 353 "src/entriesTools/parser.y"


/* definición de yyerror, usa el yylloc global para ubicación */
void yyerror(const char *s) {
    int ambito = contextoActualReporte ? contextoActualReporte->nombre : 0;
    agregarErrorSintactico(s, yylloc.first_line, yylloc.first_column, ambito);
}
