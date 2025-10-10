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
  YYSYMBOL_TOKEN_PUBLIC = 13,              /* TOKEN_PUBLIC  */
  YYSYMBOL_TOKEN_STATIC = 14,              /* TOKEN_STATIC  */
  YYSYMBOL_TOKEN_INTEGER = 15,             /* TOKEN_INTEGER  */
  YYSYMBOL_TOKEN_DOUBLE_CLASS = 16,        /* TOKEN_DOUBLE_CLASS  */
  YYSYMBOL_TOKEN_FLOAT_CLASS = 17,         /* TOKEN_FLOAT_CLASS  */
  YYSYMBOL_TOKEN_STRING_CLASS = 18,        /* TOKEN_STRING_CLASS  */
  YYSYMBOL_TOKEN_ARRAYS = 19,              /* TOKEN_ARRAYS  */
  YYSYMBOL_TOKEN_LENGTH = 20,              /* TOKEN_LENGTH  */
  YYSYMBOL_TOKEN_DBOOLEAN = 21,            /* TOKEN_DBOOLEAN  */
  YYSYMBOL_TOKEN_DCHAR = 22,               /* TOKEN_DCHAR  */
  YYSYMBOL_TOKEN_UNSIGNED_INTEGER = 23,    /* TOKEN_UNSIGNED_INTEGER  */
  YYSYMBOL_TOKEN_REAL = 24,                /* TOKEN_REAL  */
  YYSYMBOL_TOKEN_DOUBLE = 25,              /* TOKEN_DOUBLE  */
  YYSYMBOL_TOKEN_STRING = 26,              /* TOKEN_STRING  */
  YYSYMBOL_TOKEN_CHAR = 27,                /* TOKEN_CHAR  */
  YYSYMBOL_TOKEN_IDENTIFIER = 28,          /* TOKEN_IDENTIFIER  */
  YYSYMBOL_TOKEN_RETURN = 29,              /* TOKEN_RETURN  */
  YYSYMBOL_TOKEN_FINAL = 30,               /* TOKEN_FINAL  */
  YYSYMBOL_TOKEN_LEFT_SHIFT = 31,          /* TOKEN_LEFT_SHIFT  */
  YYSYMBOL_TOKEN_RIGHT_SHIFT = 32,         /* TOKEN_RIGHT_SHIFT  */
  YYSYMBOL_TOKEN_EQ = 33,                  /* TOKEN_EQ  */
  YYSYMBOL_TOKEN_NE = 34,                  /* TOKEN_NE  */
  YYSYMBOL_TOKEN_GE = 35,                  /* TOKEN_GE  */
  YYSYMBOL_TOKEN_LE = 36,                  /* TOKEN_LE  */
  YYSYMBOL_TOKEN_AND = 37,                 /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 38,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_INCREMENT = 39,           /* TOKEN_INCREMENT  */
  YYSYMBOL_TOKEN_DECREMENT = 40,           /* TOKEN_DECREMENT  */
  YYSYMBOL_TOKEN_PLUS_ASSIGN = 41,         /* TOKEN_PLUS_ASSIGN  */
  YYSYMBOL_TOKEN_MINUS_ASSIGN = 42,        /* TOKEN_MINUS_ASSIGN  */
  YYSYMBOL_TOKEN_MULT_ASSIGN = 43,         /* TOKEN_MULT_ASSIGN  */
  YYSYMBOL_TOKEN_DIV_ASSIGN = 44,          /* TOKEN_DIV_ASSIGN  */
  YYSYMBOL_TOKEN_MOD_ASSIGN = 45,          /* TOKEN_MOD_ASSIGN  */
  YYSYMBOL_TOKEN_AND_ASSIGN = 46,          /* TOKEN_AND_ASSIGN  */
  YYSYMBOL_TOKEN_OR_ASSIGN = 47,           /* TOKEN_OR_ASSIGN  */
  YYSYMBOL_TOKEN_XOR_ASSIGN = 48,          /* TOKEN_XOR_ASSIGN  */
  YYSYMBOL_TOKEN_LSHIFT_ASSIGN = 49,       /* TOKEN_LSHIFT_ASSIGN  */
  YYSYMBOL_TOKEN_RSHIFT_ASSIGN = 50,       /* TOKEN_RSHIFT_ASSIGN  */
  YYSYMBOL_TOKEN_SWITCH = 51,              /* TOKEN_SWITCH  */
  YYSYMBOL_TOKEN_CASE = 52,                /* TOKEN_CASE  */
  YYSYMBOL_TOKEN_BREAK = 53,               /* TOKEN_BREAK  */
  YYSYMBOL_TOKEN_DEFAULT = 54,             /* TOKEN_DEFAULT  */
  YYSYMBOL_TOKEN_WHILE = 55,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_CONTINUE = 56,            /* TOKEN_CONTINUE  */
  YYSYMBOL_TOKEN_FOR = 57,                 /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_NEW = 58,                 /* TOKEN_NEW  */
  YYSYMBOL_59_ = 59,                       /* '?'  */
  YYSYMBOL_60_ = 60,                       /* ':'  */
  YYSYMBOL_61_ = 61,                       /* '+'  */
  YYSYMBOL_62_ = 62,                       /* '-'  */
  YYSYMBOL_63_ = 63,                       /* '*'  */
  YYSYMBOL_64_ = 64,                       /* '/'  */
  YYSYMBOL_65_ = 65,                       /* '%'  */
  YYSYMBOL_NEG = 66,                       /* NEG  */
  YYSYMBOL_67_ = 67,                       /* ';'  */
  YYSYMBOL_68_ = 68,                       /* '('  */
  YYSYMBOL_69_ = 69,                       /* ')'  */
  YYSYMBOL_70_ = 70,                       /* ','  */
  YYSYMBOL_71_ = 71,                       /* '{'  */
  YYSYMBOL_72_ = 72,                       /* '}'  */
  YYSYMBOL_73_ = 73,                       /* '='  */
  YYSYMBOL_74_ = 74,                       /* '['  */
  YYSYMBOL_75_ = 75,                       /* ']'  */
  YYSYMBOL_76_ = 76,                       /* '&'  */
  YYSYMBOL_77_ = 77,                       /* '|'  */
  YYSYMBOL_78_ = 78,                       /* '^'  */
  YYSYMBOL_79_ = 79,                       /* '~'  */
  YYSYMBOL_80_ = 80,                       /* '>'  */
  YYSYMBOL_81_ = 81,                       /* '<'  */
  YYSYMBOL_82_ = 82,                       /* '!'  */
  YYSYMBOL_83_ = 83,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 84,                  /* $accept  */
  YYSYMBOL_s = 85,                         /* s  */
  YYSYMBOL_programa = 86,                  /* programa  */
  YYSYMBOL_declaraciones_globales = 87,    /* declaraciones_globales  */
  YYSYMBOL_declaracion_global = 88,        /* declaracion_global  */
  YYSYMBOL_funcion_main = 89,              /* funcion_main  */
  YYSYMBOL_lSentencia = 90,                /* lSentencia  */
  YYSYMBOL_sentencia = 91,                 /* sentencia  */
  YYSYMBOL_lista_Expr = 92,                /* lista_Expr  */
  YYSYMBOL_imprimir = 93,                  /* imprimir  */
  YYSYMBOL_bloque = 94,                    /* bloque  */
  YYSYMBOL_declaracion_var = 95,           /* declaracion_var  */
  YYSYMBOL_declaracion_const = 96,         /* declaracion_const  */
  YYSYMBOL_asignacion = 97,                /* asignacion  */
  YYSYMBOL_sentencia_if = 98,              /* sentencia_if  */
  YYSYMBOL_lista_parametros = 99,          /* lista_parametros  */
  YYSYMBOL_sentencia_funcion = 100,        /* sentencia_funcion  */
  YYSYMBOL_sentencia_switch = 101,         /* sentencia_switch  */
  YYSYMBOL_lista_casos = 102,              /* lista_casos  */
  YYSYMBOL_caso = 103,                     /* caso  */
  YYSYMBOL_sentencia_while = 104,          /* sentencia_while  */
  YYSYMBOL_sentencia_for = 105,            /* sentencia_for  */
  YYSYMBOL_expr = 106,                     /* expr  */
  YYSYMBOL_primitivo = 107,                /* primitivo  */
  YYSYMBOL_tipoPrimitivo = 108,            /* tipoPrimitivo  */
  YYSYMBOL_tipoArray = 109,                /* tipoArray  */
  YYSYMBOL_declaracion_array = 110,        /* declaracion_array  */
  YYSYMBOL_lista_elementos = 111,          /* lista_elementos  */
  YYSYMBOL_acceso_array = 112,             /* acceso_array  */
  YYSYMBOL_tipoMatrix = 113,               /* tipoMatrix  */
  YYSYMBOL_declaracion_matrix = 114,       /* declaracion_matrix  */
  YYSYMBOL_lista_filas = 115,              /* lista_filas  */
  YYSYMBOL_lista_fila = 116,               /* lista_fila  */
  YYSYMBOL_acceso_matrix = 117             /* acceso_matrix  */
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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1678

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  156
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  361

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


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
       2,     2,     2,    82,     2,     2,     2,    65,    76,     2,
      68,    69,    63,    61,    70,    62,    83,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    60,    67,
      81,    73,    80,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    74,     2,    75,    78,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,    77,    72,    79,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    66
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    58,    58,    59,    63,    69,    75,    83,    87,    95,
      99,   109,   110,   115,   116,   121,   122,   127,   128,   133,
     134,   139,   140,   145,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   164,   165,
     172,   173,   179,   182,   183,   186,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   208,   209,   210,   213,   214,   219,   220,
     221,   222,   225,   228,   229,   236,   237,   240,   243,   244,
     245,   246,   247,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   306,   314,   322,   330,
     338,   346,   347,   348,   349,   359,   360,   361,   362,   366,
     367,   368,   369,   370,   371,   372,   375,   376,   377,   378,
     379,   380,   381,   385,   388,   389,   390,   393,   394,   401,
     405,   408,   409,   412,   413,   420,   423
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
  "TOKEN_ELSE", "TOKEN_TRUE", "TOKEN_FALSE", "TOKEN_FUNC", "TOKEN_PUBLIC",
  "TOKEN_STATIC", "TOKEN_INTEGER", "TOKEN_DOUBLE_CLASS",
  "TOKEN_FLOAT_CLASS", "TOKEN_STRING_CLASS", "TOKEN_ARRAYS",
  "TOKEN_LENGTH", "TOKEN_DBOOLEAN", "TOKEN_DCHAR",
  "TOKEN_UNSIGNED_INTEGER", "TOKEN_REAL", "TOKEN_DOUBLE", "TOKEN_STRING",
  "TOKEN_CHAR", "TOKEN_IDENTIFIER", "TOKEN_RETURN", "TOKEN_FINAL",
  "TOKEN_LEFT_SHIFT", "TOKEN_RIGHT_SHIFT", "TOKEN_EQ", "TOKEN_NE",
  "TOKEN_GE", "TOKEN_LE", "TOKEN_AND", "TOKEN_OR", "TOKEN_INCREMENT",
  "TOKEN_DECREMENT", "TOKEN_PLUS_ASSIGN", "TOKEN_MINUS_ASSIGN",
  "TOKEN_MULT_ASSIGN", "TOKEN_DIV_ASSIGN", "TOKEN_MOD_ASSIGN",
  "TOKEN_AND_ASSIGN", "TOKEN_OR_ASSIGN", "TOKEN_XOR_ASSIGN",
  "TOKEN_LSHIFT_ASSIGN", "TOKEN_RSHIFT_ASSIGN", "TOKEN_SWITCH",
  "TOKEN_CASE", "TOKEN_BREAK", "TOKEN_DEFAULT", "TOKEN_WHILE",
  "TOKEN_CONTINUE", "TOKEN_FOR", "TOKEN_NEW", "'?'", "':'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "NEG", "';'", "'('", "')'", "','", "'{'", "'}'",
  "'='", "'['", "']'", "'&'", "'|'", "'^'", "'~'", "'>'", "'<'", "'!'",
  "'.'", "$accept", "s", "programa", "declaraciones_globales",
  "declaracion_global", "funcion_main", "lSentencia", "sentencia",
  "lista_Expr", "imprimir", "bloque", "declaracion_var",
  "declaracion_const", "asignacion", "sentencia_if", "lista_parametros",
  "sentencia_funcion", "sentencia_switch", "lista_casos", "caso",
  "sentencia_while", "sentencia_for", "expr", "primitivo", "tipoPrimitivo",
  "tipoArray", "declaracion_array", "lista_elementos", "acceso_array",
  "tipoMatrix", "declaracion_matrix", "lista_filas", "lista_fila",
  "acceso_matrix", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-313)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-77)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     120,  -313,  -313,  -313,  -313,    55,  -313,  -313,  -313,   119,
    -313,   120,  -313,   177,  -313,     1,    57,  -313,    17,  -313,
    -313,   177,    89,    68,    95,  -313,   104,    18,   106,    27,
     107,  -313,    59,   115,   108,   107,    61,   710,  -313,   107,
     177,   102,   107,  -313,   107,   111,   125,  1604,   524,   177,
     159,   166,   129,  -313,   132,  -313,   133,   670,   143,  -313,
     144,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,    32,
     184,  -313,   185,  -313,  -313,  -313,   524,  -313,  -313,   416,
     524,  -313,  -313,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   435,   524,   524,  -313,  -313,   131,   134,
     135,   138,   139,  -313,  -313,  -313,  -313,  -313,    26,   188,
     196,   524,   327,   524,   524,  1551,  -313,  -313,  -313,   197,
    -313,  -313,   524,   524,    70,   160,  -313,   161,   144,  -313,
    -313,  -313,  -313,  -313,    -5,   151,   162,   164,  1551,  -313,
      65,  1551,   721,  1551,  1551,  1551,  1551,  1551,  1551,  1551,
    1551,  1551,  1551,  -313,    94,  1551,   774,   210,   211,   212,
     213,   214,  -313,  -313,   505,   524,  -313,  -313,   171,   176,
     186,   189,   190,   191,   809,   171,   171,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,    75,   173,   862,   915,
     524,   194,   225,  -313,  -313,   183,   346,    15,  -313,   524,
     107,  -313,    66,   195,   198,   199,   201,   202,  -313,    96,
     924,   524,   524,   524,   524,   524,  -313,  1551,  1551,  1551,
    1551,  1551,  1551,  1551,  1551,   977,  1559,  1559,   171,   171,
     171,  1551,  1551,  1551,  1551,  1551,  -313,   204,   524,   193,
     107,   985,   524,    38,   200,   177,   524,  1551,   177,   203,
    1551,   256,   524,   524,   524,   524,   524,   524,   524,  -313,
     208,  1551,  1551,  1551,  1551,  1551,   524,   524,  1551,   -35,
    -313,    -2,  1038,   524,  -313,   215,  1551,    37,   216,   524,
      43,  -313,    -1,  1551,  1047,  1100,  1153,  1206,    99,  1259,
     101,   524,  1551,  1312,   524,   217,    50,  -313,   863,   107,
     207,     2,  1365,   524,   524,  -313,   524,    44,   203,  -313,
    -313,  -313,   205,  -313,  -313,  -313,  -313,  -313,  -313,  1374,
    -313,  1427,   710,  -313,  -313,  -313,   107,   107,   218,   107,
    1436,  1551,  1489,  -313,  -313,   524,  -313,   710,   590,  -313,
    -313,   107,  -313,  -313,   222,  1551,   630,  -313,   524,  1498,
    -313
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   137,   138,   139,   136,     0,   140,   141,   142,     0,
       2,     0,     8,     6,     9,     0,     0,     1,     0,     7,
       4,     5,     0,     0,     0,     3,     0,     0,     0,     0,
       0,    67,     0,     0,     0,     0,     0,     0,    71,     0,
       0,    43,     0,    69,     0,     0,     0,     0,    36,     0,
       0,     0,     0,    34,     0,    35,     0,     0,     0,    24,
      14,    26,    27,    30,    16,    31,    18,    20,    22,     0,
       0,    28,     0,    29,    70,    66,     0,    10,    68,     0,
       0,    60,    62,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,     0,     0,
       0,     0,     0,   129,   131,   132,   130,   133,   112,     0,
       0,     0,     0,     0,     0,    37,   111,   121,   122,     0,
      59,    61,     0,     0,     0,     0,    42,     0,    13,    15,
      17,    19,    21,    12,    43,     0,     0,     0,    44,    41,
       0,    39,     0,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    33,     0,    46,     0,     0,     0,     0,
       0,     0,   126,   128,     0,     0,   125,   127,    94,     0,
       0,     0,     0,     0,     0,    95,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,    11,   143,     0,     0,    40,     0,
       0,    32,     0,     0,     0,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,     0,    93,    91,    92,    96,
      97,   100,   101,   102,   103,     0,    83,    84,    85,    86,
      87,    88,    89,    90,    98,    99,   123,     0,     0,     0,
       0,     0,     0,    43,     0,     0,     0,   146,     0,     0,
      38,    63,     0,     0,     0,     0,     0,     0,     0,   113,
     149,   107,   108,   109,   106,   110,     0,     0,    45,     0,
      77,     0,     0,     0,   150,     0,   148,     0,     0,     0,
       0,   154,     0,    47,     0,     0,     0,     0,     0,    39,
       0,     0,   105,     0,     0,     0,     0,    74,     0,     0,
       0,     0,     0,     0,     0,   145,     0,     0,     0,   152,
      64,    65,     0,   115,   116,   117,   119,   118,   120,     0,
     124,     0,     0,    72,    73,    81,     0,     0,     0,     0,
       0,   147,     0,   155,   153,     0,   156,     0,     0,    80,
      79,     0,    82,   144,     0,    48,     0,    78,     0,     0,
     151
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -313,  -313,  -313,   260,     7,   273,  -312,   -55,   -82,  -313,
     -30,   -19,  -313,  -265,   -56,   257,    97,   -54,  -313,   -21,
     -53,   -51,   -33,  -313,    72,  -313,  -313,     9,  -313,  -313,
    -313,  -313,   -27,  -313
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     9,    10,    11,    12,    13,    57,    58,   140,    59,
      60,    61,    62,    63,    64,    32,    65,    66,   306,   307,
      67,    68,   141,   116,    69,    70,    71,   287,   117,    72,
      73,   290,   291,   118
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,   129,   127,   130,   131,    43,   132,    46,    31,    74,
      31,   154,    77,    22,    78,   115,   310,   304,    19,   305,
     348,    75,     1,     2,     3,     4,   308,   128,    19,    23,
     308,     1,     2,     3,     4,   356,     6,    50,    51,     7,
       8,    50,    51,   138,    22,     6,   338,   142,     7,     8,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     134,   155,   156,    27,    24,   162,   163,   309,    76,    16,
      37,   337,    15,   258,     1,     2,     3,     4,   168,   174,
     175,   176,   219,    15,    25,    15,   259,    30,     6,   198,
     199,     7,     8,    15,   164,   246,    35,    14,   283,    33,
     165,    33,   304,   247,   305,   201,   135,   314,    14,   315,
      14,    76,    33,   318,   314,   319,   343,    26,    14,    17,
      18,   119,   333,    28,     1,     2,     3,     4,    39,    40,
      44,    40,   220,     5,   208,   209,    27,   200,     6,   262,
     263,     7,     8,    41,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   211,   209,   269,   209,   251,   326,   209,
     328,   209,    29,   257,    34,    76,   260,    42,    37,    79,
     261,     1,     2,     3,     4,   298,   300,   120,   271,   272,
     273,   274,   275,    80,   121,     6,   202,   122,     7,     8,
     123,   124,   177,   178,   179,   180,   181,   182,   183,   184,
     133,   -25,   136,   137,   157,   278,   166,   158,   159,   282,
     280,   160,   161,   286,   167,   197,   205,   203,   204,   293,
     294,   295,   296,   297,   299,   206,   321,   207,   213,   214,
     215,   216,   217,   302,   303,   221,   248,   191,   192,   193,
     312,   194,   195,   253,   196,   222,   286,   254,   223,   224,
     225,   252,   320,   264,   279,   292,   265,   266,   329,   267,
     268,   331,   277,    21,   289,   284,   336,   332,   345,   335,
     340,   341,   301,   342,    20,   334,    36,   351,     0,   313,
     316,   344,   129,   127,   130,   131,   358,   132,   317,     0,
     129,   127,   130,   131,     0,   132,   349,   350,     0,   352,
       0,     0,   355,     0,     0,     0,     0,     0,   128,     0,
       0,   357,     0,     0,     0,   359,   128,   285,     0,     0,
     288,   169,   170,   171,   172,     0,     0,    96,    97,     0,
       0,     0,    98,    99,   100,   101,   102,     0,     0,   173,
     103,   104,   105,   106,   107,   108,    96,    97,     0,     0,
       0,    98,    99,   100,   101,   102,   109,   110,     0,   103,
     104,   105,   106,   107,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,     0,     0,   111,
       0,     0,     0,     0,     0,   112,     0,     0,     0,     0,
       0,     0,     0,     0,   255,     0,   113,     0,   111,   114,
       0,     0,     0,     0,   112,     0,     0,   256,     0,     0,
       0,     0,     0,     0,     0,   113,    96,    97,   114,     0,
       0,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,   108,    96,    97,     0,     0,     0,
      98,    99,   100,   101,   102,   109,   110,     0,   103,   104,
     105,   106,   107,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   110,     0,     0,   111,     0,
       0,     0,     0,     0,   112,   139,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,     0,   111,   114,     0,
       0,     0,     0,   112,   153,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,    96,    97,   114,     0,     0,
      98,    99,   100,   101,   102,     0,     0,     0,   103,   104,
     105,   106,   107,   108,    96,    97,     0,     0,     0,    98,
      99,   100,   101,   102,   109,   110,     0,   103,   104,   105,
     106,   107,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,   110,     0,     0,   111,     0,     0,
       0,     0,     0,   112,   218,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,     0,   111,   114,     0,     0,
       0,   125,   112,    45,     1,     2,     3,     4,    46,     0,
       0,     0,     0,   113,     0,     0,   114,     0,     6,     0,
       0,     7,     8,     0,     0,     0,     0,     0,    47,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,    50,
      51,   125,     0,    45,     1,     2,     3,     4,    46,     0,
       0,    52,   -76,    53,   -76,    54,    55,    56,     6,     0,
       0,     7,     8,     0,     0,     0,     0,     0,    47,    48,
      49,    37,   -76,     0,     0,     0,     0,     0,     0,    50,
      51,   125,     0,    45,     1,     2,     3,     4,    46,     0,
       0,    52,   -75,    53,   -75,    54,    55,    56,     6,     0,
       0,     7,     8,     0,     0,     0,     0,     0,    47,    48,
      49,    37,   -75,     0,     0,     0,     0,     0,     0,    50,
      51,     0,     0,    45,     1,     2,     3,     4,    46,     0,
       0,    52,     0,    53,     0,    54,    55,    56,     6,     0,
       0,     7,     8,     0,     0,     0,     0,     0,    47,    48,
      49,    37,   126,     0,     0,     0,     0,     0,     0,    50,
      51,     0,   177,   178,   179,   180,   181,   182,   183,   184,
       0,    52,     0,    53,     0,    54,    55,    56,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     185,    37,   186,   187,   188,   189,   190,     0,     0,     0,
     210,     0,     0,     0,     0,     0,     0,   191,   192,   193,
       0,   194,   195,     0,   196,   177,   178,   179,   180,   181,
     182,   183,   184,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   185,     0,   186,   187,   188,   189,   190,
     177,   178,   179,   180,   181,   182,   183,   184,     0,   212,
     191,   192,   193,     0,   194,   195,     0,   196,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   185,     0,
     186,   187,   188,   189,   190,     0,     0,     0,   226,     0,
       0,     0,     0,     0,     0,   191,   192,   193,     0,   194,
     195,     0,   196,   177,   178,   179,   180,   181,   182,   183,
     184,     0,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,     0,     0,     0,     0,     0,     0,
       0,   185,     0,   186,   187,   188,   189,   190,     0,     0,
       0,   249,     0,     0,     0,     0,    94,    95,   191,   192,
     193,     0,   194,   195,     0,   196,   177,   178,   179,   180,
     181,   182,   183,   184,     0,   177,   178,   179,   180,   181,
     182,   183,   184,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   185,     0,   186,   187,   188,   189,
     190,     0,     0,   185,   250,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,     0,   196,   270,
     191,   192,   193,     0,   194,   195,     0,   196,   177,   178,
     179,   180,   181,   182,   183,   184,   177,   178,   179,   180,
     181,   182,   183,   184,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   185,   276,   186,   187,
     188,   189,   190,     0,   185,     0,   186,   187,   188,   189,
     190,     0,   281,   191,   192,   193,     0,   194,   195,     0,
     196,   191,   192,   193,     0,   194,   195,     0,   196,   177,
     178,   179,   180,   181,   182,   183,   184,     0,   177,   178,
     179,   180,   181,   182,   183,   184,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   185,     0,   186,
     187,   188,   189,   190,     0,   311,   185,     0,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
       0,   196,   322,   191,   192,   193,     0,   194,   195,     0,
     196,   177,   178,   179,   180,   181,   182,   183,   184,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   185,
       0,   186,   187,   188,   189,   190,     0,     0,     0,   323,
       0,     0,     0,     0,     0,     0,   191,   192,   193,     0,
     194,   195,     0,   196,   177,   178,   179,   180,   181,   182,
     183,   184,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   185,     0,   186,   187,   188,   189,   190,     0,
       0,     0,   324,     0,     0,     0,     0,     0,     0,   191,
     192,   193,     0,   194,   195,     0,   196,   177,   178,   179,
     180,   181,   182,   183,   184,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   185,     0,   186,   187,   188,
     189,   190,     0,     0,     0,   325,     0,     0,     0,     0,
       0,     0,   191,   192,   193,     0,   194,   195,     0,   196,
     177,   178,   179,   180,   181,   182,   183,   184,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   185,     0,
     186,   187,   188,   189,   190,     0,     0,     0,   327,     0,
       0,     0,     0,     0,     0,   191,   192,   193,     0,   194,
     195,     0,   196,   177,   178,   179,   180,   181,   182,   183,
     184,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   185,     0,   186,   187,   188,   189,   190,     0,     0,
       0,   330,     0,     0,     0,     0,     0,     0,   191,   192,
     193,     0,   194,   195,     0,   196,   177,   178,   179,   180,
     181,   182,   183,   184,     0,   177,   178,   179,   180,   181,
     182,   183,   184,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   185,     0,   186,   187,   188,   189,
     190,     0,     0,   185,   339,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,     0,   196,   346,
     191,   192,   193,     0,   194,   195,     0,   196,   177,   178,
     179,   180,   181,   182,   183,   184,     0,   177,   178,   179,
     180,   181,   182,   183,   184,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   185,   347,   186,   187,
     188,   189,   190,     0,     0,   185,     0,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,     0,
     196,   353,   191,   192,   193,     0,   194,   195,     0,   196,
     177,   178,   179,   180,   181,   182,   183,   184,     0,   177,
     178,   179,   180,   181,   182,   183,   184,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   185,     0,
     186,   187,   188,   189,   190,     0,     0,   185,     0,   186,
     187,   188,   189,   190,   354,   191,   192,   193,     0,   194,
     195,     0,   196,   360,   191,   192,   193,     0,   194,   195,
       0,   196,   177,   178,   179,   180,   181,   182,   183,   184,
     177,   178,   179,   180,   181,   182,   183,   184,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     185,     0,   186,   187,   188,   189,   190,     0,     0,     0,
       0,     0,   188,   189,   190,     0,     0,   191,   192,   193,
       0,   194,   195,     0,   196,   191,   192,   193,     0,   194,
     195,     0,   196,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,     0,     0,    94,    95
};

static const yytype_int16 yycheck[] =
{
      30,    57,    57,    57,    57,    35,    57,     8,    27,    39,
      29,    93,    42,    12,    44,    48,   281,    52,    11,    54,
     332,    40,     4,     5,     6,     7,    28,    57,    21,    28,
      28,     4,     5,     6,     7,   347,    18,    39,    40,    21,
      22,    39,    40,    76,    12,    18,   311,    80,    21,    22,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      28,    94,    95,    68,     7,    39,    40,    69,    73,    14,
      71,    69,     0,    58,     4,     5,     6,     7,   111,   112,
     113,   114,   164,    11,    67,    13,    71,    69,    18,   122,
     123,    21,    22,    21,    68,    20,    69,     0,    60,    27,
      74,    29,    52,    28,    54,   124,    74,    70,    11,    72,
      13,    73,    40,    70,    70,    72,    72,    28,    21,     0,
       1,    49,    72,    28,     4,     5,     6,     7,    69,    70,
      69,    70,   165,    13,    69,    70,    68,    67,    18,    73,
      74,    21,    22,    28,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,    69,    70,    69,    70,   200,    69,    70,
      69,    70,    68,   206,    68,    73,   209,    69,    71,    68,
     210,     4,     5,     6,     7,   267,   268,    28,   221,   222,
     223,   224,   225,    68,    28,    18,   124,    68,    21,    22,
      68,    68,    31,    32,    33,    34,    35,    36,    37,    38,
      67,    67,    28,    28,    83,   248,    28,    83,    83,   252,
     250,    83,    83,   256,    28,    28,    75,    67,    67,   262,
     263,   264,   265,   266,   267,    73,   292,    73,    28,    28,
      28,    28,    28,   276,   277,    69,    73,    76,    77,    78,
     283,    80,    81,    28,    83,    69,   289,    74,    69,    69,
      69,    67,   292,    68,    71,     9,    68,    68,   301,    68,
      68,   304,    68,    13,    71,    75,    69,    60,    73,   309,
     313,   314,    74,   316,    11,   306,    29,    69,    -1,    74,
      74,   318,   348,   348,   348,   348,    74,   348,   289,    -1,
     356,   356,   356,   356,    -1,   356,   336,   337,    -1,   339,
      -1,    -1,   345,    -1,    -1,    -1,    -1,    -1,   348,    -1,
      -1,   351,    -1,    -1,    -1,   358,   356,   255,    -1,    -1,
     258,     4,     5,     6,     7,    -1,    -1,    10,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    39,    40,    -1,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    79,    -1,    62,    82,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    10,    11,    82,    -1,
      -1,    15,    16,    17,    18,    19,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    10,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    39,    40,    -1,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    62,    82,    -1,
      -1,    -1,    -1,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    10,    11,    82,    -1,    -1,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    10,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    39,    40,    -1,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    62,    82,    -1,    -1,
      -1,     1,    68,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    82,    -1,    18,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    18,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    18,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      -1,    51,    -1,    53,    -1,    55,    56,    57,    18,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    51,    -1,    53,    -1,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    71,    61,    62,    63,    64,    65,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,
      -1,    80,    81,    -1,    83,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    61,    62,    63,    64,    65,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    75,
      76,    77,    78,    -1,    80,    81,    -1,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      61,    62,    63,    64,    65,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    77,    78,    -1,    80,
      81,    -1,    83,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    61,    62,    63,    64,    65,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    73,    74,    76,    77,
      78,    -1,    80,    81,    -1,    83,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    61,    62,    63,    64,
      65,    -1,    -1,    59,    69,    61,    62,    63,    64,    65,
      -1,    76,    77,    78,    -1,    80,    81,    -1,    83,    75,
      76,    77,    78,    -1,    80,    81,    -1,    83,    31,    32,
      33,    34,    35,    36,    37,    38,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    -1,    59,    -1,    61,    62,    63,    64,
      65,    -1,    67,    76,    77,    78,    -1,    80,    81,    -1,
      83,    76,    77,    78,    -1,    80,    81,    -1,    83,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    61,
      62,    63,    64,    65,    -1,    67,    59,    -1,    61,    62,
      63,    64,    65,    -1,    76,    77,    78,    -1,    80,    81,
      -1,    83,    75,    76,    77,    78,    -1,    80,    81,    -1,
      83,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    61,    62,    63,    64,    65,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    -1,
      80,    81,    -1,    83,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    61,    62,    63,    64,    65,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    -1,    80,    81,    -1,    83,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    61,    62,    63,
      64,    65,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    78,    -1,    80,    81,    -1,    83,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      61,    62,    63,    64,    65,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    77,    78,    -1,    80,
      81,    -1,    83,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    61,    62,    63,    64,    65,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,
      78,    -1,    80,    81,    -1,    83,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    61,    62,    63,    64,
      65,    -1,    -1,    59,    69,    61,    62,    63,    64,    65,
      -1,    76,    77,    78,    -1,    80,    81,    -1,    83,    75,
      76,    77,    78,    -1,    80,    81,    -1,    83,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    -1,    -1,    59,    -1,    61,    62,    63,
      64,    65,    -1,    76,    77,    78,    -1,    80,    81,    -1,
      83,    75,    76,    77,    78,    -1,    80,    81,    -1,    83,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      61,    62,    63,    64,    65,    -1,    -1,    59,    -1,    61,
      62,    63,    64,    65,    75,    76,    77,    78,    -1,    80,
      81,    -1,    83,    75,    76,    77,    78,    -1,    80,    81,
      -1,    83,    31,    32,    33,    34,    35,    36,    37,    38,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    61,    62,    63,    64,    65,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    -1,    -1,    76,    77,    78,
      -1,    80,    81,    -1,    83,    76,    77,    78,    -1,    80,
      81,    -1,    83,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    73,    74
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     6,     7,    13,    18,    21,    22,    85,
      86,    87,    88,    89,   100,   108,    14,     0,     1,    88,
      89,    87,    12,    28,     7,    67,    28,    68,    28,    68,
      69,    95,    99,   108,    68,    69,    99,    71,    94,    69,
      70,    28,    69,    94,    69,     3,     8,    28,    29,    30,
      39,    40,    51,    53,    55,    56,    57,    90,    91,    93,
      94,    95,    96,    97,    98,   100,   101,   104,   105,   108,
     109,   110,   113,   114,    94,    95,    73,    94,    94,    68,
      68,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    68,    73,    74,    10,    11,    15,    16,
      17,    18,    19,    23,    24,    25,    26,    27,    28,    39,
      40,    62,    68,    79,    82,   106,   107,   112,   117,   108,
      28,    28,    68,    68,    68,     1,    72,    91,    94,    98,
     101,   104,   105,    67,    28,    74,    28,    28,   106,    69,
      92,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,    69,    92,   106,   106,    83,    83,    83,
      83,    83,    39,    40,    68,    74,    28,    28,   106,     4,
       5,     6,     7,    22,   106,   106,   106,    31,    32,    33,
      34,    35,    36,    37,    38,    59,    61,    62,    63,    64,
      65,    76,    77,    78,    80,    81,    83,    28,   106,   106,
      67,    95,   108,    67,    67,    75,    73,    73,    69,    70,
      69,    69,    75,    28,    28,    28,    28,    28,    69,    92,
     106,    69,    69,    69,    69,    69,    69,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,    20,    28,    73,    69,
      69,   106,    67,    28,    74,    58,    71,   106,    58,    71,
     106,    94,    73,    74,    68,    68,    68,    68,    68,    69,
      75,   106,   106,   106,   106,   106,    60,    68,   106,    71,
      94,    67,   106,    60,    75,   108,   106,   111,   108,    71,
     115,   116,     9,   106,   106,   106,   106,   106,    92,   106,
      92,    74,   106,   106,    52,    54,   102,   103,    28,    69,
      97,    67,   106,    74,    70,    72,    74,   111,    70,    72,
      94,    98,    75,    69,    69,    69,    69,    69,    69,   106,
      69,   106,    60,    72,   103,    94,    69,    69,    97,    69,
     106,   106,   106,    72,   116,    73,    75,    60,    90,    94,
      94,    69,    94,    75,    75,   106,    90,    94,    74,   106,
      75
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    84,    85,    85,    86,    86,    86,    87,    87,    88,
      89,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    92,    92,
      93,    93,    94,    95,    95,    96,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    98,    98,    98,    99,    99,   100,   100,
     100,   100,   101,   102,   102,   103,   103,   104,   105,   105,
     105,   105,   105,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   107,
     107,   107,   107,   107,   107,   107,   108,   108,   108,   108,
     108,   108,   108,   109,   110,   110,   110,   111,   111,   112,
     113,   114,   114,   115,   115,   116,   117
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     2,     2,     1,     2,     1,     1,
       7,     3,     2,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     1,     1,     1,     2,     3,     1,
       4,     3,     3,     2,     4,     5,     3,     6,     9,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     5,     7,     7,     3,     1,     7,     6,
       6,     5,     7,     2,     1,     4,     3,     5,     9,     8,
       8,     7,     8,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     5,     4,     4,     4,     4,
       4,     1,     1,     4,     3,     6,     6,     6,     6,     6,
       6,     1,     1,     3,     6,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     8,     6,     4,     3,     1,     4,
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
  case 2: /* s: programa  */
#line 58 "src/entriesTools/parser.y"
             { ast_root = (yyvsp[0].nodo); (yyval.nodo) = (yyvsp[0].nodo); }
#line 1818 "build/parser.tab.c"
    break;

  case 3: /* s: s error ';'  */
#line 59 "src/entriesTools/parser.y"
                  { yyerrok; }
#line 1824 "build/parser.tab.c"
    break;

  case 4: /* programa: declaraciones_globales funcion_main  */
#line 63 "src/entriesTools/parser.y"
                                              {
        AbstractExpresion* programa = nuevoInstruccionesExpresion();
        agregarHijo(programa, (yyvsp[-1].nodo));
        agregarHijo(programa, (yyvsp[0].nodo));
        (yyval.nodo) = programa;
    }
#line 1835 "build/parser.tab.c"
    break;

  case 5: /* programa: funcion_main declaraciones_globales  */
#line 69 "src/entriesTools/parser.y"
                                          {
        AbstractExpresion* programa = nuevoInstruccionesExpresion();
        agregarHijo(programa, (yyvsp[-1].nodo));
        agregarHijo(programa, (yyvsp[0].nodo));
        (yyval.nodo) = programa;
    }
#line 1846 "build/parser.tab.c"
    break;

  case 6: /* programa: funcion_main  */
#line 75 "src/entriesTools/parser.y"
                   {
        AbstractExpresion* programa = nuevoInstruccionesExpresion();
        agregarHijo(programa, (yyvsp[0].nodo));
        (yyval.nodo) = programa;
    }
#line 1856 "build/parser.tab.c"
    break;

  case 7: /* declaraciones_globales: declaraciones_globales declaracion_global  */
#line 83 "src/entriesTools/parser.y"
                                                                  { 
        agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo)); 
        (yyval.nodo) = (yyvsp[-1].nodo);
    }
#line 1865 "build/parser.tab.c"
    break;

  case 8: /* declaraciones_globales: declaracion_global  */
#line 87 "src/entriesTools/parser.y"
                         {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 1875 "build/parser.tab.c"
    break;

  case 9: /* declaracion_global: sentencia_funcion  */
#line 95 "src/entriesTools/parser.y"
                                      { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1881 "build/parser.tab.c"
    break;

  case 10: /* funcion_main: TOKEN_PUBLIC TOKEN_STATIC TOKEN_DVOID TOKEN_IDENTIFIER '(' ')' bloque  */
#line 99 "src/entriesTools/parser.y"
                                                                                    {
        // Verificar que el identificador sea "main"
        if (strcmp((yyvsp[-3].string), "main") != 0) {
            yyerror("Se esperaba 'main' como nombre de la función principal");
        }
        (yyval.nodo) = nuevoFuncionMainExpresion((yyvsp[0].nodo));
    }
#line 1893 "build/parser.tab.c"
    break;

  case 11: /* lSentencia: lSentencia sentencia ';'  */
#line 109 "src/entriesTools/parser.y"
                                     { agregarHijo((yyvsp[-2].nodo), (yyvsp[-1].nodo)); (yyval.nodo) = (yyvsp[-2].nodo);}
#line 1899 "build/parser.tab.c"
    break;

  case 12: /* lSentencia: sentencia ';'  */
#line 110 "src/entriesTools/parser.y"
                    {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[-1].nodo));
        (yyval.nodo) =  b;
    }
#line 1909 "build/parser.tab.c"
    break;

  case 13: /* lSentencia: lSentencia bloque  */
#line 115 "src/entriesTools/parser.y"
                        { agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1915 "build/parser.tab.c"
    break;

  case 14: /* lSentencia: bloque  */
#line 116 "src/entriesTools/parser.y"
             {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 1925 "build/parser.tab.c"
    break;

  case 15: /* lSentencia: lSentencia sentencia_if  */
#line 121 "src/entriesTools/parser.y"
                              { agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1931 "build/parser.tab.c"
    break;

  case 16: /* lSentencia: sentencia_if  */
#line 122 "src/entriesTools/parser.y"
                   {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 1941 "build/parser.tab.c"
    break;

  case 17: /* lSentencia: lSentencia sentencia_switch  */
#line 127 "src/entriesTools/parser.y"
                                  { agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1947 "build/parser.tab.c"
    break;

  case 18: /* lSentencia: sentencia_switch  */
#line 128 "src/entriesTools/parser.y"
                       {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 1957 "build/parser.tab.c"
    break;

  case 19: /* lSentencia: lSentencia sentencia_while  */
#line 133 "src/entriesTools/parser.y"
                                 { agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1963 "build/parser.tab.c"
    break;

  case 20: /* lSentencia: sentencia_while  */
#line 134 "src/entriesTools/parser.y"
                      {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 1973 "build/parser.tab.c"
    break;

  case 21: /* lSentencia: lSentencia sentencia_for  */
#line 139 "src/entriesTools/parser.y"
                               { agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1979 "build/parser.tab.c"
    break;

  case 22: /* lSentencia: sentencia_for  */
#line 140 "src/entriesTools/parser.y"
                    {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 1989 "build/parser.tab.c"
    break;

  case 23: /* lSentencia: lSentencia error ';'  */
#line 145 "src/entriesTools/parser.y"
                           { yyerrok; (yyval.nodo) = (yyvsp[-2].nodo); }
#line 1995 "build/parser.tab.c"
    break;

  case 24: /* sentencia: imprimir  */
#line 148 "src/entriesTools/parser.y"
                    {(yyval.nodo) = (yyvsp[0].nodo); }
#line 2001 "build/parser.tab.c"
    break;

  case 25: /* sentencia: bloque  */
#line 149 "src/entriesTools/parser.y"
             {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2007 "build/parser.tab.c"
    break;

  case 26: /* sentencia: declaracion_var  */
#line 150 "src/entriesTools/parser.y"
                      {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2013 "build/parser.tab.c"
    break;

  case 27: /* sentencia: declaracion_const  */
#line 151 "src/entriesTools/parser.y"
                        {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2019 "build/parser.tab.c"
    break;

  case 28: /* sentencia: declaracion_array  */
#line 152 "src/entriesTools/parser.y"
                        {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2025 "build/parser.tab.c"
    break;

  case 29: /* sentencia: declaracion_matrix  */
#line 153 "src/entriesTools/parser.y"
                         {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2031 "build/parser.tab.c"
    break;

  case 30: /* sentencia: asignacion  */
#line 154 "src/entriesTools/parser.y"
                 {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2037 "build/parser.tab.c"
    break;

  case 31: /* sentencia: sentencia_funcion  */
#line 155 "src/entriesTools/parser.y"
                        { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2043 "build/parser.tab.c"
    break;

  case 32: /* sentencia: TOKEN_IDENTIFIER '(' lista_Expr ')'  */
#line 156 "src/entriesTools/parser.y"
                                          { (yyval.nodo) = nuevoLlamadaExpresion((yyvsp[-3].string), (yyvsp[-1].nodo)); }
#line 2049 "build/parser.tab.c"
    break;

  case 33: /* sentencia: TOKEN_IDENTIFIER '(' ')'  */
#line 157 "src/entriesTools/parser.y"
                               { (yyval.nodo) = nuevoLlamadaExpresion((yyvsp[-2].string), NULL); }
#line 2055 "build/parser.tab.c"
    break;

  case 34: /* sentencia: TOKEN_BREAK  */
#line 158 "src/entriesTools/parser.y"
                  { (yyval.nodo) = nuevoBreakExpresion((yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2061 "build/parser.tab.c"
    break;

  case 35: /* sentencia: TOKEN_CONTINUE  */
#line 159 "src/entriesTools/parser.y"
                     { (yyval.nodo) = nuevoContinueExpresion((yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2067 "build/parser.tab.c"
    break;

  case 36: /* sentencia: TOKEN_RETURN  */
#line 160 "src/entriesTools/parser.y"
                   { (yyval.nodo) = NULL; }
#line 2073 "build/parser.tab.c"
    break;

  case 37: /* sentencia: TOKEN_RETURN expr  */
#line 161 "src/entriesTools/parser.y"
                        { (yyval.nodo) = nuevoReturnExpresion((yyvsp[0].nodo)); }
#line 2079 "build/parser.tab.c"
    break;

  case 38: /* lista_Expr: lista_Expr ',' expr  */
#line 164 "src/entriesTools/parser.y"
                                 { agregarHijo((yyvsp[-2].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-2].nodo); }
#line 2085 "build/parser.tab.c"
    break;

  case 39: /* lista_Expr: expr  */
#line 165 "src/entriesTools/parser.y"
           { 
                AbstractExpresion* b = nuevoListaExpresiones();
                agregarHijo(b, (yyvsp[0].nodo));
                (yyval.nodo) =  b;
            }
#line 2095 "build/parser.tab.c"
    break;

  case 40: /* imprimir: TOKEN_PRINT '(' lista_Expr ')'  */
#line 172 "src/entriesTools/parser.y"
                                         { (yyval.nodo) =  nuevoPrintExpresion((yyvsp[-1].nodo)); }
#line 2101 "build/parser.tab.c"
    break;

  case 41: /* imprimir: TOKEN_PRINT '(' ')'  */
#line 173 "src/entriesTools/parser.y"
                          { 
        yyerror("System.out.println() sin argumentos no está permitido. Debe proporcionar al menos un argumento.");
        (yyval.nodo) = NULL;
    }
#line 2110 "build/parser.tab.c"
    break;

  case 42: /* bloque: '{' lSentencia '}'  */
#line 179 "src/entriesTools/parser.y"
                           { (yyval.nodo) =  (yyvsp[-1].nodo); }
#line 2116 "build/parser.tab.c"
    break;

  case 43: /* declaracion_var: tipoPrimitivo TOKEN_IDENTIFIER  */
#line 182 "src/entriesTools/parser.y"
                                                { (yyval.nodo) = nuevoDeclaracionVariables((yyvsp[-1].tipoDato), (yyvsp[0].string), NULL, (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2122 "build/parser.tab.c"
    break;

  case 44: /* declaracion_var: tipoPrimitivo TOKEN_IDENTIFIER '=' expr  */
#line 183 "src/entriesTools/parser.y"
                                              { (yyval.nodo) = nuevoDeclaracionVariables((yyvsp[-3].tipoDato), (yyvsp[-2].string), (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2128 "build/parser.tab.c"
    break;

  case 45: /* declaracion_const: TOKEN_FINAL tipoPrimitivo TOKEN_IDENTIFIER '=' expr  */
#line 186 "src/entriesTools/parser.y"
                                                                       { (yyval.nodo) = nuevoDeclaracionConstante((yyvsp[-3].tipoDato), (yyvsp[-2].string), (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2134 "build/parser.tab.c"
    break;

  case 46: /* asignacion: TOKEN_IDENTIFIER '=' expr  */
#line 189 "src/entriesTools/parser.y"
                                      { (yyval.nodo) = nuevoAsignacionExpresion((yyvsp[-2].string), (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2140 "build/parser.tab.c"
    break;

  case 47: /* asignacion: TOKEN_IDENTIFIER '[' expr ']' '=' expr  */
#line 190 "src/entriesTools/parser.y"
                                             { (yyval.nodo) = nuevoAsignacionArrayExpresion((yyvsp[-5].string), (yyvsp[-3].nodo), (yyvsp[0].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column); }
#line 2146 "build/parser.tab.c"
    break;

  case 48: /* asignacion: TOKEN_IDENTIFIER '[' expr ']' '[' expr ']' '=' expr  */
#line 191 "src/entriesTools/parser.y"
                                                          { (yyval.nodo) = nuevoAsignacionMatrixExpresion((yyvsp[-8].string), (yyvsp[-6].nodo), (yyvsp[-3].nodo), (yyvsp[0].nodo), (yylsp[-8]).first_line, (yylsp[-8]).first_column); }
#line 2152 "build/parser.tab.c"
    break;

  case 49: /* asignacion: TOKEN_IDENTIFIER TOKEN_PLUS_ASSIGN expr  */
#line 192 "src/entriesTools/parser.y"
                                              { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_SUMA, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2158 "build/parser.tab.c"
    break;

  case 50: /* asignacion: TOKEN_IDENTIFIER TOKEN_MINUS_ASSIGN expr  */
#line 193 "src/entriesTools/parser.y"
                                               { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_RESTA, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2164 "build/parser.tab.c"
    break;

  case 51: /* asignacion: TOKEN_IDENTIFIER TOKEN_MULT_ASSIGN expr  */
#line 194 "src/entriesTools/parser.y"
                                              { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_MULT, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2170 "build/parser.tab.c"
    break;

  case 52: /* asignacion: TOKEN_IDENTIFIER TOKEN_DIV_ASSIGN expr  */
#line 195 "src/entriesTools/parser.y"
                                             { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_DIV, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2176 "build/parser.tab.c"
    break;

  case 53: /* asignacion: TOKEN_IDENTIFIER TOKEN_MOD_ASSIGN expr  */
#line 196 "src/entriesTools/parser.y"
                                             { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_MOD, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2182 "build/parser.tab.c"
    break;

  case 54: /* asignacion: TOKEN_IDENTIFIER TOKEN_AND_ASSIGN expr  */
#line 197 "src/entriesTools/parser.y"
                                             { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_AND, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2188 "build/parser.tab.c"
    break;

  case 55: /* asignacion: TOKEN_IDENTIFIER TOKEN_OR_ASSIGN expr  */
#line 198 "src/entriesTools/parser.y"
                                            { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_OR, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2194 "build/parser.tab.c"
    break;

  case 56: /* asignacion: TOKEN_IDENTIFIER TOKEN_XOR_ASSIGN expr  */
#line 199 "src/entriesTools/parser.y"
                                             { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_XOR, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2200 "build/parser.tab.c"
    break;

  case 57: /* asignacion: TOKEN_IDENTIFIER TOKEN_LSHIFT_ASSIGN expr  */
#line 200 "src/entriesTools/parser.y"
                                                { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_LSHIFT, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2206 "build/parser.tab.c"
    break;

  case 58: /* asignacion: TOKEN_IDENTIFIER TOKEN_RSHIFT_ASSIGN expr  */
#line 201 "src/entriesTools/parser.y"
                                                { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_RSHIFT, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2212 "build/parser.tab.c"
    break;

  case 59: /* asignacion: TOKEN_INCREMENT TOKEN_IDENTIFIER  */
#line 202 "src/entriesTools/parser.y"
                                       { (yyval.nodo) = nuevoPreIncrementoExpresion((yyvsp[0].string), (yylsp[-1]).first_line, (yylsp[-1]).first_column); }
#line 2218 "build/parser.tab.c"
    break;

  case 60: /* asignacion: TOKEN_IDENTIFIER TOKEN_INCREMENT  */
#line 203 "src/entriesTools/parser.y"
                                       { (yyval.nodo) = nuevoPostIncrementoExpresion((yyvsp[-1].string), (yylsp[-1]).first_line, (yylsp[-1]).first_column); }
#line 2224 "build/parser.tab.c"
    break;

  case 61: /* asignacion: TOKEN_DECREMENT TOKEN_IDENTIFIER  */
#line 204 "src/entriesTools/parser.y"
                                       { (yyval.nodo) = nuevoPreDecrementoExpresion((yyvsp[0].string), (yylsp[-1]).first_line, (yylsp[-1]).first_column); }
#line 2230 "build/parser.tab.c"
    break;

  case 62: /* asignacion: TOKEN_IDENTIFIER TOKEN_DECREMENT  */
#line 205 "src/entriesTools/parser.y"
                                       { (yyval.nodo) = nuevoPostDecrementoExpresion((yyvsp[-1].string), (yylsp[-1]).first_line, (yylsp[-1]).first_column); }
#line 2236 "build/parser.tab.c"
    break;

  case 63: /* sentencia_if: TOKEN_IF '(' expr ')' bloque  */
#line 208 "src/entriesTools/parser.y"
                                           { (yyval.nodo) = nuevoIfExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2242 "build/parser.tab.c"
    break;

  case 64: /* sentencia_if: TOKEN_IF '(' expr ')' bloque TOKEN_ELSE bloque  */
#line 209 "src/entriesTools/parser.y"
                                                     { (yyval.nodo) = nuevoIfElseExpresion((yyvsp[-4].nodo), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2248 "build/parser.tab.c"
    break;

  case 65: /* sentencia_if: TOKEN_IF '(' expr ')' bloque TOKEN_ELSE sentencia_if  */
#line 210 "src/entriesTools/parser.y"
                                                           { (yyval.nodo) = nuevoElseIfExpresion((yyvsp[-4].nodo), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2254 "build/parser.tab.c"
    break;

  case 66: /* lista_parametros: lista_parametros ',' declaracion_var  */
#line 213 "src/entriesTools/parser.y"
                                                       { agregarHijo((yyvsp[-2].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-2].nodo); }
#line 2260 "build/parser.tab.c"
    break;

  case 67: /* lista_parametros: declaracion_var  */
#line 214 "src/entriesTools/parser.y"
                      { AbstractExpresion* b = nuevoListaParametros();
                agregarHijo(b, (yyvsp[0].nodo));
                (yyval.nodo) =  b; }
#line 2268 "build/parser.tab.c"
    break;

  case 68: /* sentencia_funcion: tipoPrimitivo TOKEN_FUNC TOKEN_IDENTIFIER '(' lista_parametros ')' bloque  */
#line 219 "src/entriesTools/parser.y"
                                                                                             {  (yyval.nodo) = nuevoFuncionExpresion((yyvsp[-6].tipoDato), (yyvsp[-4].string), (yyvsp[-2].nodo), (yyvsp[0].nodo));}
#line 2274 "build/parser.tab.c"
    break;

  case 69: /* sentencia_funcion: tipoPrimitivo TOKEN_FUNC TOKEN_IDENTIFIER '(' ')' bloque  */
#line 220 "src/entriesTools/parser.y"
                                                               {  (yyval.nodo) = nuevoFuncionExpresion((yyvsp[-5].tipoDato), (yyvsp[-3].string), NULL, (yyvsp[0].nodo));}
#line 2280 "build/parser.tab.c"
    break;

  case 70: /* sentencia_funcion: tipoPrimitivo TOKEN_IDENTIFIER '(' lista_parametros ')' bloque  */
#line 221 "src/entriesTools/parser.y"
                                                                     {  (yyval.nodo) = nuevoFuncionExpresion((yyvsp[-5].tipoDato), (yyvsp[-4].string), (yyvsp[-2].nodo), (yyvsp[0].nodo));}
#line 2286 "build/parser.tab.c"
    break;

  case 71: /* sentencia_funcion: tipoPrimitivo TOKEN_IDENTIFIER '(' ')' bloque  */
#line 222 "src/entriesTools/parser.y"
                                                    {  (yyval.nodo) = nuevoFuncionExpresion((yyvsp[-4].tipoDato), (yyvsp[-3].string), NULL, (yyvsp[0].nodo));}
#line 2292 "build/parser.tab.c"
    break;

  case 72: /* sentencia_switch: TOKEN_SWITCH '(' expr ')' '{' lista_casos '}'  */
#line 225 "src/entriesTools/parser.y"
                                                                { (yyval.nodo) = nuevoSwitchExpresion((yyvsp[-4].nodo), (yyvsp[-1].nodo)); }
#line 2298 "build/parser.tab.c"
    break;

  case 73: /* lista_casos: lista_casos caso  */
#line 228 "src/entriesTools/parser.y"
                              { agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2304 "build/parser.tab.c"
    break;

  case 74: /* lista_casos: caso  */
#line 229 "src/entriesTools/parser.y"
           { 
        AbstractExpresion* b = nuevoListaCasos();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 2314 "build/parser.tab.c"
    break;

  case 75: /* caso: TOKEN_CASE expr ':' lSentencia  */
#line 236 "src/entriesTools/parser.y"
                                     { (yyval.nodo) = nuevoCaseExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2320 "build/parser.tab.c"
    break;

  case 76: /* caso: TOKEN_DEFAULT ':' lSentencia  */
#line 237 "src/entriesTools/parser.y"
                                   { (yyval.nodo) = nuevoDefaultExpresion((yyvsp[0].nodo)); }
#line 2326 "build/parser.tab.c"
    break;

  case 77: /* sentencia_while: TOKEN_WHILE '(' expr ')' bloque  */
#line 240 "src/entriesTools/parser.y"
                                                 { (yyval.nodo) = nuevoWhileExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2332 "build/parser.tab.c"
    break;

  case 78: /* sentencia_for: TOKEN_FOR '(' declaracion_var ';' expr ';' asignacion ')' bloque  */
#line 243 "src/entriesTools/parser.y"
                                                                                { (yyval.nodo) = nuevoForExpresion((yyvsp[-6].nodo), (yyvsp[-4].nodo), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2338 "build/parser.tab.c"
    break;

  case 79: /* sentencia_for: TOKEN_FOR '(' declaracion_var ';' expr ';' ')' bloque  */
#line 244 "src/entriesTools/parser.y"
                                                            { (yyval.nodo) = nuevoForExpresion((yyvsp[-5].nodo), (yyvsp[-3].nodo), NULL, (yyvsp[0].nodo)); }
#line 2344 "build/parser.tab.c"
    break;

  case 80: /* sentencia_for: TOKEN_FOR '(' ';' expr ';' asignacion ')' bloque  */
#line 245 "src/entriesTools/parser.y"
                                                       { (yyval.nodo) = nuevoForExpresion(NULL, (yyvsp[-4].nodo), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2350 "build/parser.tab.c"
    break;

  case 81: /* sentencia_for: TOKEN_FOR '(' ';' expr ';' ')' bloque  */
#line 246 "src/entriesTools/parser.y"
                                            { (yyval.nodo) = nuevoForExpresion(NULL, (yyvsp[-3].nodo), NULL, (yyvsp[0].nodo)); }
#line 2356 "build/parser.tab.c"
    break;

  case 82: /* sentencia_for: TOKEN_FOR '(' tipoPrimitivo TOKEN_IDENTIFIER ':' expr ')' bloque  */
#line 247 "src/entriesTools/parser.y"
                                                                       { (yyval.nodo) = nuevoForEachExpresion((yyvsp[-5].tipoDato), (yyvsp[-4].string), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2362 "build/parser.tab.c"
    break;

  case 83: /* expr: expr '+' expr  */
#line 266 "src/entriesTools/parser.y"
                      { (yyval.nodo) =  nuevoSumaExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo));  }
#line 2368 "build/parser.tab.c"
    break;

  case 84: /* expr: expr '-' expr  */
#line 267 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoRestaExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2374 "build/parser.tab.c"
    break;

  case 85: /* expr: expr '*' expr  */
#line 268 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoMultiplicacionExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2380 "build/parser.tab.c"
    break;

  case 86: /* expr: expr '/' expr  */
#line 269 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoDivisionExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2386 "build/parser.tab.c"
    break;

  case 87: /* expr: expr '%' expr  */
#line 270 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoModuloExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2392 "build/parser.tab.c"
    break;

  case 88: /* expr: expr '&' expr  */
#line 271 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoBitwiseAndExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2398 "build/parser.tab.c"
    break;

  case 89: /* expr: expr '|' expr  */
#line 272 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoBitwiseOrExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2404 "build/parser.tab.c"
    break;

  case 90: /* expr: expr '^' expr  */
#line 273 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoBitwiseXorExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2410 "build/parser.tab.c"
    break;

  case 91: /* expr: expr TOKEN_LEFT_SHIFT expr  */
#line 274 "src/entriesTools/parser.y"
                                 { (yyval.nodo) =  nuevoBitwiseLeftShiftExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2416 "build/parser.tab.c"
    break;

  case 92: /* expr: expr TOKEN_RIGHT_SHIFT expr  */
#line 275 "src/entriesTools/parser.y"
                                  { (yyval.nodo) =  nuevoBitwiseRightShiftExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2422 "build/parser.tab.c"
    break;

  case 93: /* expr: '(' expr ')'  */
#line 276 "src/entriesTools/parser.y"
                   { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2428 "build/parser.tab.c"
    break;

  case 94: /* expr: '-' expr  */
#line 277 "src/entriesTools/parser.y"
                          { (yyval.nodo) =  nuevoUnarioExpresion((yyvsp[0].nodo));  }
#line 2434 "build/parser.tab.c"
    break;

  case 95: /* expr: '~' expr  */
#line 278 "src/entriesTools/parser.y"
                          { (yyval.nodo) =  nuevoBitwiseNotExpresion((yyvsp[0].nodo));  }
#line 2440 "build/parser.tab.c"
    break;

  case 96: /* expr: expr TOKEN_EQ expr  */
#line 279 "src/entriesTools/parser.y"
                         { (yyval.nodo) = nuevoIgualdadExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2446 "build/parser.tab.c"
    break;

  case 97: /* expr: expr TOKEN_NE expr  */
#line 280 "src/entriesTools/parser.y"
                         { (yyval.nodo) = nuevoDesigualdadExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2452 "build/parser.tab.c"
    break;

  case 98: /* expr: expr '>' expr  */
#line 281 "src/entriesTools/parser.y"
                    { (yyval.nodo) = nuevoMayorQueExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2458 "build/parser.tab.c"
    break;

  case 99: /* expr: expr '<' expr  */
#line 282 "src/entriesTools/parser.y"
                    { (yyval.nodo) = nuevoMenorQueExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2464 "build/parser.tab.c"
    break;

  case 100: /* expr: expr TOKEN_GE expr  */
#line 283 "src/entriesTools/parser.y"
                         { (yyval.nodo) = nuevoMayorIgualExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2470 "build/parser.tab.c"
    break;

  case 101: /* expr: expr TOKEN_LE expr  */
#line 284 "src/entriesTools/parser.y"
                         { (yyval.nodo) = nuevoMenorIgualExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2476 "build/parser.tab.c"
    break;

  case 102: /* expr: expr TOKEN_AND expr  */
#line 285 "src/entriesTools/parser.y"
                          { (yyval.nodo) = nuevoLogicAndExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2482 "build/parser.tab.c"
    break;

  case 103: /* expr: expr TOKEN_OR expr  */
#line 286 "src/entriesTools/parser.y"
                         { (yyval.nodo) = nuevoLogicOrExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2488 "build/parser.tab.c"
    break;

  case 104: /* expr: '!' expr  */
#line 287 "src/entriesTools/parser.y"
                         { (yyval.nodo) = nuevoLogicNotExpresion((yyvsp[0].nodo)); }
#line 2494 "build/parser.tab.c"
    break;

  case 105: /* expr: expr '?' expr ':' expr  */
#line 288 "src/entriesTools/parser.y"
                             { (yyval.nodo) = nuevoOperadorTernarioExpresion((yyvsp[-4].nodo), (yyvsp[-2].nodo), (yyvsp[0].nodo), (yylsp[-4]).first_line, (yylsp[-4]).first_column); }
#line 2500 "build/parser.tab.c"
    break;

  case 106: /* expr: '(' TOKEN_DVOID ')' expr  */
#line 289 "src/entriesTools/parser.y"
                               { (yyval.nodo) = nuevoCastingExpresion((yyvsp[0].nodo), VOID); }
#line 2506 "build/parser.tab.c"
    break;

  case 107: /* expr: '(' TOKEN_DINT ')' expr  */
#line 290 "src/entriesTools/parser.y"
                              { (yyval.nodo) = nuevoCastingExpresion((yyvsp[0].nodo), INT); }
#line 2512 "build/parser.tab.c"
    break;

  case 108: /* expr: '(' TOKEN_DFLOAT ')' expr  */
#line 291 "src/entriesTools/parser.y"
                                { (yyval.nodo) = nuevoCastingExpresion((yyvsp[0].nodo), FLOAT); }
#line 2518 "build/parser.tab.c"
    break;

  case 109: /* expr: '(' TOKEN_DDOUBLE ')' expr  */
#line 292 "src/entriesTools/parser.y"
                                 { (yyval.nodo) = nuevoCastingExpresion((yyvsp[0].nodo), DOUBLE); }
#line 2524 "build/parser.tab.c"
    break;

  case 110: /* expr: '(' TOKEN_DCHAR ')' expr  */
#line 293 "src/entriesTools/parser.y"
                               { (yyval.nodo) = nuevoCastingExpresion((yyvsp[0].nodo), CHAR); }
#line 2530 "build/parser.tab.c"
    break;

  case 111: /* expr: primitivo  */
#line 294 "src/entriesTools/parser.y"
                { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2536 "build/parser.tab.c"
    break;

  case 112: /* expr: TOKEN_IDENTIFIER  */
#line 295 "src/entriesTools/parser.y"
                       { (yyval.nodo) = nuevoIdentificadorExpresion((yyvsp[0].string), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2542 "build/parser.tab.c"
    break;

  case 113: /* expr: TOKEN_IDENTIFIER '(' lista_Expr ')'  */
#line 296 "src/entriesTools/parser.y"
                                          { (yyval.nodo) = nuevoLlamadaExpresion((yyvsp[-3].string), (yyvsp[-1].nodo)); }
#line 2548 "build/parser.tab.c"
    break;

  case 114: /* expr: TOKEN_IDENTIFIER '(' ')'  */
#line 297 "src/entriesTools/parser.y"
                               { (yyval.nodo) = nuevoLlamadaExpresion((yyvsp[-2].string), NULL); }
#line 2554 "build/parser.tab.c"
    break;

  case 115: /* expr: TOKEN_INTEGER '.' TOKEN_IDENTIFIER '(' expr ')'  */
#line 298 "src/entriesTools/parser.y"
                                                      { 
        if (strcmp((yyvsp[-3].string), "parseInt") == 0) {
            (yyval.nodo) = nuevoIntegerParseIntExpresion((yyvsp[-1].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        } else {
            yyerror("Método no reconocido en clase Integer");
            (yyval.nodo) = NULL;
        }
    }
#line 2567 "build/parser.tab.c"
    break;

  case 116: /* expr: TOKEN_DOUBLE_CLASS '.' TOKEN_IDENTIFIER '(' expr ')'  */
#line 306 "src/entriesTools/parser.y"
                                                           { 
        if (strcmp((yyvsp[-3].string), "parseDouble") == 0) {
            (yyval.nodo) = nuevoDoubleParseDoubleExpresion((yyvsp[-1].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        } else {
            yyerror("Método no reconocido en clase Double");
            (yyval.nodo) = NULL;
        }
    }
#line 2580 "build/parser.tab.c"
    break;

  case 117: /* expr: TOKEN_FLOAT_CLASS '.' TOKEN_IDENTIFIER '(' expr ')'  */
#line 314 "src/entriesTools/parser.y"
                                                          { 
        if (strcmp((yyvsp[-3].string), "parseFloat") == 0) {
            (yyval.nodo) = nuevoFloatParseFloatExpresion((yyvsp[-1].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        } else {
            yyerror("Método no reconocido en clase Float");
            (yyval.nodo) = NULL;
        }
    }
#line 2593 "build/parser.tab.c"
    break;

  case 118: /* expr: TOKEN_STRING_CLASS '.' TOKEN_IDENTIFIER '(' expr ')'  */
#line 322 "src/entriesTools/parser.y"
                                                           { 
        if (strcmp((yyvsp[-3].string), "valueOf") == 0) {
            (yyval.nodo) = nuevoStringValueOfExpresion((yyvsp[-1].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        } else {
            yyerror("Método no reconocido en clase String");
            (yyval.nodo) = NULL;
        }
    }
#line 2606 "build/parser.tab.c"
    break;

  case 119: /* expr: TOKEN_STRING_CLASS '.' TOKEN_IDENTIFIER '(' lista_Expr ')'  */
#line 330 "src/entriesTools/parser.y"
                                                                 { 
        if (strcmp((yyvsp[-3].string), "join") == 0) {
            (yyval.nodo) = nuevoStringJoinExpresion((yyvsp[-1].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        } else {
            yyerror("Método no reconocido en clase String");
            (yyval.nodo) = NULL;
        }
    }
#line 2619 "build/parser.tab.c"
    break;

  case 120: /* expr: TOKEN_ARRAYS '.' TOKEN_IDENTIFIER '(' lista_Expr ')'  */
#line 338 "src/entriesTools/parser.y"
                                                           { 
        if (strcmp((yyvsp[-3].string), "indexOf") == 0) {
            (yyval.nodo) = nuevoArraysIndexOfExpresion((yyvsp[-1].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        } else {
            yyerror("Método no reconocido en clase Arrays");
            (yyval.nodo) = NULL;
        }
    }
#line 2632 "build/parser.tab.c"
    break;

  case 121: /* expr: acceso_array  */
#line 346 "src/entriesTools/parser.y"
                   { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2638 "build/parser.tab.c"
    break;

  case 122: /* expr: acceso_matrix  */
#line 347 "src/entriesTools/parser.y"
                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2644 "build/parser.tab.c"
    break;

  case 123: /* expr: expr '.' TOKEN_LENGTH  */
#line 348 "src/entriesTools/parser.y"
                            { (yyval.nodo) = nuevoArrayLengthExpresion((yyvsp[-2].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2650 "build/parser.tab.c"
    break;

  case 124: /* expr: expr '.' TOKEN_IDENTIFIER '(' expr ')'  */
#line 349 "src/entriesTools/parser.y"
                                             { 
        if (strcmp((yyvsp[-3].string), "add") == 0) {
            (yyval.nodo) = nuevoArrayAddExpresion((yyvsp[-5].nodo), (yyvsp[-1].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        } else {
            char buffer[256];
            snprintf(buffer, sizeof(buffer), "Método '%s' no reconocido para arrays", (yyvsp[-3].string));
            yyerror(buffer);
            (yyval.nodo) = NULL;
        }
    }
#line 2665 "build/parser.tab.c"
    break;

  case 125: /* expr: TOKEN_INCREMENT TOKEN_IDENTIFIER  */
#line 359 "src/entriesTools/parser.y"
                                       { (yyval.nodo) = nuevoPreIncrementoExpresion((yyvsp[0].string), (yylsp[-1]).first_line, (yylsp[-1]).first_column); }
#line 2671 "build/parser.tab.c"
    break;

  case 126: /* expr: TOKEN_IDENTIFIER TOKEN_INCREMENT  */
#line 360 "src/entriesTools/parser.y"
                                       { (yyval.nodo) = nuevoPostIncrementoExpresion((yyvsp[-1].string), (yylsp[-1]).first_line, (yylsp[-1]).first_column); }
#line 2677 "build/parser.tab.c"
    break;

  case 127: /* expr: TOKEN_DECREMENT TOKEN_IDENTIFIER  */
#line 361 "src/entriesTools/parser.y"
                                       { (yyval.nodo) = nuevoPreDecrementoExpresion((yyvsp[0].string), (yylsp[-1]).first_line, (yylsp[-1]).first_column); }
#line 2683 "build/parser.tab.c"
    break;

  case 128: /* expr: TOKEN_IDENTIFIER TOKEN_DECREMENT  */
#line 362 "src/entriesTools/parser.y"
                                       { (yyval.nodo) = nuevoPostDecrementoExpresion((yyvsp[-1].string), (yylsp[-1]).first_line, (yylsp[-1]).first_column); }
#line 2689 "build/parser.tab.c"
    break;

  case 129: /* primitivo: TOKEN_UNSIGNED_INTEGER  */
#line 366 "src/entriesTools/parser.y"
                                  { (yyval.nodo) =  nuevoPrimitivoExpresion((yyvsp[0].string), INT); }
#line 2695 "build/parser.tab.c"
    break;

  case 130: /* primitivo: TOKEN_STRING  */
#line 367 "src/entriesTools/parser.y"
                   { (yyval.nodo) =  nuevoPrimitivoExpresion((yyvsp[0].string), STRING); }
#line 2701 "build/parser.tab.c"
    break;

  case 131: /* primitivo: TOKEN_REAL  */
#line 368 "src/entriesTools/parser.y"
                 { (yyval.nodo) =  nuevoPrimitivoExpresion((yyvsp[0].string), FLOAT); }
#line 2707 "build/parser.tab.c"
    break;

  case 132: /* primitivo: TOKEN_DOUBLE  */
#line 369 "src/entriesTools/parser.y"
                   { (yyval.nodo) =  nuevoPrimitivoExpresion((yyvsp[0].string), DOUBLE); }
#line 2713 "build/parser.tab.c"
    break;

  case 133: /* primitivo: TOKEN_CHAR  */
#line 370 "src/entriesTools/parser.y"
                 { (yyval.nodo) =  nuevoPrimitivoExpresion((yyvsp[0].string), CHAR); }
#line 2719 "build/parser.tab.c"
    break;

  case 134: /* primitivo: TOKEN_TRUE  */
#line 371 "src/entriesTools/parser.y"
                 { (yyval.nodo) =  nuevoPrimitivoExpresion("T", BOOLEAN); }
#line 2725 "build/parser.tab.c"
    break;

  case 135: /* primitivo: TOKEN_FALSE  */
#line 372 "src/entriesTools/parser.y"
                  { (yyval.nodo) =  nuevoPrimitivoExpresion("F", BOOLEAN); }
#line 2731 "build/parser.tab.c"
    break;

  case 136: /* tipoPrimitivo: TOKEN_DVOID  */
#line 375 "src/entriesTools/parser.y"
                           { (yyval.tipoDato) = VOID; }
#line 2737 "build/parser.tab.c"
    break;

  case 137: /* tipoPrimitivo: TOKEN_DINT  */
#line 376 "src/entriesTools/parser.y"
                 { (yyval.tipoDato) = INT; }
#line 2743 "build/parser.tab.c"
    break;

  case 138: /* tipoPrimitivo: TOKEN_DFLOAT  */
#line 377 "src/entriesTools/parser.y"
                   { (yyval.tipoDato) = FLOAT; }
#line 2749 "build/parser.tab.c"
    break;

  case 139: /* tipoPrimitivo: TOKEN_DDOUBLE  */
#line 378 "src/entriesTools/parser.y"
                    { (yyval.tipoDato) = DOUBLE; }
#line 2755 "build/parser.tab.c"
    break;

  case 140: /* tipoPrimitivo: TOKEN_STRING_CLASS  */
#line 379 "src/entriesTools/parser.y"
                         { (yyval.tipoDato) = STRING; }
#line 2761 "build/parser.tab.c"
    break;

  case 141: /* tipoPrimitivo: TOKEN_DBOOLEAN  */
#line 380 "src/entriesTools/parser.y"
                     { (yyval.tipoDato) = BOOLEAN; }
#line 2767 "build/parser.tab.c"
    break;

  case 142: /* tipoPrimitivo: TOKEN_DCHAR  */
#line 381 "src/entriesTools/parser.y"
                  { (yyval.tipoDato) = CHAR; }
#line 2773 "build/parser.tab.c"
    break;

  case 143: /* tipoArray: tipoPrimitivo '[' ']'  */
#line 385 "src/entriesTools/parser.y"
                                 { (yyval.tipoDato) = (yyvsp[-2].tipoDato); }
#line 2779 "build/parser.tab.c"
    break;

  case 144: /* declaracion_array: tipoArray TOKEN_IDENTIFIER '=' TOKEN_NEW tipoPrimitivo '[' expr ']'  */
#line 388 "src/entriesTools/parser.y"
                                                                                       { (yyval.nodo) = nuevoDeclaracionArrayNew((yyvsp[-7].tipoDato), (yyvsp[-6].string), (yyvsp[-3].tipoDato), (yyvsp[-1].nodo), (yylsp[-6]).first_line, (yylsp[-6]).first_column); }
#line 2785 "build/parser.tab.c"
    break;

  case 145: /* declaracion_array: tipoArray TOKEN_IDENTIFIER '=' '{' lista_elementos '}'  */
#line 389 "src/entriesTools/parser.y"
                                                             { (yyval.nodo) = nuevoDeclaracionArrayInit((yyvsp[-5].tipoDato), (yyvsp[-4].string), (yyvsp[-1].nodo), (yylsp[-4]).first_line, (yylsp[-4]).first_column); }
#line 2791 "build/parser.tab.c"
    break;

  case 146: /* declaracion_array: tipoArray TOKEN_IDENTIFIER '=' expr  */
#line 390 "src/entriesTools/parser.y"
                                          { (yyval.nodo) = nuevoDeclaracionArrayExpresion((yyvsp[-3].tipoDato), (yyvsp[-2].string), (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2797 "build/parser.tab.c"
    break;

  case 147: /* lista_elementos: lista_elementos ',' expr  */
#line 393 "src/entriesTools/parser.y"
                                          { agregarHijo((yyvsp[-2].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-2].nodo); }
#line 2803 "build/parser.tab.c"
    break;

  case 148: /* lista_elementos: expr  */
#line 394 "src/entriesTools/parser.y"
           { 
        AbstractExpresion* b = nuevoListaElementos();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 2813 "build/parser.tab.c"
    break;

  case 149: /* acceso_array: TOKEN_IDENTIFIER '[' expr ']'  */
#line 401 "src/entriesTools/parser.y"
                                            { (yyval.nodo) = nuevoAccesoArrayExpresion((yyvsp[-3].string), (yyvsp[-1].nodo), (yylsp[-3]).first_line, (yylsp[-3]).first_column); }
#line 2819 "build/parser.tab.c"
    break;

  case 150: /* tipoMatrix: tipoPrimitivo '[' ']' '[' ']'  */
#line 405 "src/entriesTools/parser.y"
                                          { (yyval.tipoDato) = (yyvsp[-4].tipoDato); }
#line 2825 "build/parser.tab.c"
    break;

  case 151: /* declaracion_matrix: tipoMatrix TOKEN_IDENTIFIER '=' TOKEN_NEW tipoPrimitivo '[' expr ']' '[' expr ']'  */
#line 408 "src/entriesTools/parser.y"
                                                                                                      { (yyval.nodo) = nuevoDeclaracionMatrixNew((yyvsp[-10].tipoDato), (yyvsp[-9].string), (yyvsp[-6].tipoDato), (yyvsp[-4].nodo), (yyvsp[-1].nodo), (yylsp[-9]).first_line, (yylsp[-9]).first_column); }
#line 2831 "build/parser.tab.c"
    break;

  case 152: /* declaracion_matrix: tipoMatrix TOKEN_IDENTIFIER '=' '{' lista_filas '}'  */
#line 409 "src/entriesTools/parser.y"
                                                          { (yyval.nodo) = nuevoDeclaracionMatrixInit((yyvsp[-5].tipoDato), (yyvsp[-4].string), (yyvsp[-1].nodo), (yylsp[-4]).first_line, (yylsp[-4]).first_column); }
#line 2837 "build/parser.tab.c"
    break;

  case 153: /* lista_filas: lista_filas ',' lista_fila  */
#line 412 "src/entriesTools/parser.y"
                                        { agregarHijo((yyvsp[-2].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-2].nodo); }
#line 2843 "build/parser.tab.c"
    break;

  case 154: /* lista_filas: lista_fila  */
#line 413 "src/entriesTools/parser.y"
                 { 
        AbstractExpresion* b = nuevoListaFilas();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 2853 "build/parser.tab.c"
    break;

  case 155: /* lista_fila: '{' lista_elementos '}'  */
#line 420 "src/entriesTools/parser.y"
                                    { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2859 "build/parser.tab.c"
    break;

  case 156: /* acceso_matrix: TOKEN_IDENTIFIER '[' expr ']' '[' expr ']'  */
#line 423 "src/entriesTools/parser.y"
                                                          { (yyval.nodo) = nuevoAccesoMatrixExpresion((yyvsp[-6].string), (yyvsp[-4].nodo), (yyvsp[-1].nodo), (yylsp[-6]).first_line, (yylsp[-6]).first_column); }
#line 2865 "build/parser.tab.c"
    break;


#line 2869 "build/parser.tab.c"

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

#line 425 "src/entriesTools/parser.y"


/* definición de yyerror, usa el yylloc global para ubicación */
void yyerror(const char *s) {
    int ambito = contextoActualReporte ? contextoActualReporte->nombre : 0;
    agregarErrorSintactico(s, yylloc.first_line, yylloc.first_column, ambito);
}
