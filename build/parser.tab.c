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

#line 87 "build/parser.tab.c"

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
  YYSYMBOL_TOKEN_IF = 7,                   /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELSE = 8,                 /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_TRUE = 9,                 /* TOKEN_TRUE  */
  YYSYMBOL_TOKEN_FALSE = 10,               /* TOKEN_FALSE  */
  YYSYMBOL_TOKEN_FUNC = 11,                /* TOKEN_FUNC  */
  YYSYMBOL_TOKEN_DSTRING = 12,             /* TOKEN_DSTRING  */
  YYSYMBOL_TOKEN_DBOOLEAN = 13,            /* TOKEN_DBOOLEAN  */
  YYSYMBOL_TOKEN_DCHAR = 14,               /* TOKEN_DCHAR  */
  YYSYMBOL_TOKEN_UNSIGNED_INTEGER = 15,    /* TOKEN_UNSIGNED_INTEGER  */
  YYSYMBOL_TOKEN_REAL = 16,                /* TOKEN_REAL  */
  YYSYMBOL_TOKEN_DOUBLE = 17,              /* TOKEN_DOUBLE  */
  YYSYMBOL_TOKEN_STRING = 18,              /* TOKEN_STRING  */
  YYSYMBOL_TOKEN_CHAR = 19,                /* TOKEN_CHAR  */
  YYSYMBOL_TOKEN_IDENTIFIER = 20,          /* TOKEN_IDENTIFIER  */
  YYSYMBOL_TOKEN_RETURN = 21,              /* TOKEN_RETURN  */
  YYSYMBOL_TOKEN_FINAL = 22,               /* TOKEN_FINAL  */
  YYSYMBOL_TOKEN_LEFT_SHIFT = 23,          /* TOKEN_LEFT_SHIFT  */
  YYSYMBOL_TOKEN_RIGHT_SHIFT = 24,         /* TOKEN_RIGHT_SHIFT  */
  YYSYMBOL_TOKEN_EQ = 25,                  /* TOKEN_EQ  */
  YYSYMBOL_TOKEN_NE = 26,                  /* TOKEN_NE  */
  YYSYMBOL_TOKEN_PLUS_ASSIGN = 27,         /* TOKEN_PLUS_ASSIGN  */
  YYSYMBOL_TOKEN_MINUS_ASSIGN = 28,        /* TOKEN_MINUS_ASSIGN  */
  YYSYMBOL_TOKEN_MULT_ASSIGN = 29,         /* TOKEN_MULT_ASSIGN  */
  YYSYMBOL_TOKEN_DIV_ASSIGN = 30,          /* TOKEN_DIV_ASSIGN  */
  YYSYMBOL_TOKEN_MOD_ASSIGN = 31,          /* TOKEN_MOD_ASSIGN  */
  YYSYMBOL_TOKEN_AND_ASSIGN = 32,          /* TOKEN_AND_ASSIGN  */
  YYSYMBOL_TOKEN_OR_ASSIGN = 33,           /* TOKEN_OR_ASSIGN  */
  YYSYMBOL_TOKEN_XOR_ASSIGN = 34,          /* TOKEN_XOR_ASSIGN  */
  YYSYMBOL_TOKEN_LSHIFT_ASSIGN = 35,       /* TOKEN_LSHIFT_ASSIGN  */
  YYSYMBOL_TOKEN_RSHIFT_ASSIGN = 36,       /* TOKEN_RSHIFT_ASSIGN  */
  YYSYMBOL_37_ = 37,                       /* '+'  */
  YYSYMBOL_38_ = 38,                       /* '-'  */
  YYSYMBOL_39_ = 39,                       /* '*'  */
  YYSYMBOL_40_ = 40,                       /* '/'  */
  YYSYMBOL_41_ = 41,                       /* '%'  */
  YYSYMBOL_NEG = 42,                       /* NEG  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_45_ = 45,                       /* '('  */
  YYSYMBOL_46_ = 46,                       /* ')'  */
  YYSYMBOL_47_ = 47,                       /* '{'  */
  YYSYMBOL_48_ = 48,                       /* '}'  */
  YYSYMBOL_49_ = 49,                       /* '='  */
  YYSYMBOL_50_ = 50,                       /* '&'  */
  YYSYMBOL_51_ = 51,                       /* '|'  */
  YYSYMBOL_52_ = 52,                       /* '^'  */
  YYSYMBOL_53_ = 53,                       /* '~'  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_s = 55,                         /* s  */
  YYSYMBOL_lSentencia = 56,                /* lSentencia  */
  YYSYMBOL_sentencia = 57,                 /* sentencia  */
  YYSYMBOL_lista_Expr = 58,                /* lista_Expr  */
  YYSYMBOL_imprimir = 59,                  /* imprimir  */
  YYSYMBOL_bloque = 60,                    /* bloque  */
  YYSYMBOL_declaracion_var = 61,           /* declaracion_var  */
  YYSYMBOL_declaracion_const = 62,         /* declaracion_const  */
  YYSYMBOL_asignacion = 63,                /* asignacion  */
  YYSYMBOL_sentencia_if = 64,              /* sentencia_if  */
  YYSYMBOL_lista_parametros = 65,          /* lista_parametros  */
  YYSYMBOL_sentencia_funcion = 66,         /* sentencia_funcion  */
  YYSYMBOL_expr = 67,                      /* expr  */
  YYSYMBOL_primitivo = 68,                 /* primitivo  */
  YYSYMBOL_tipoPrimitivo = 69              /* tipoPrimitivo  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   315

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
       2,     2,     2,     2,     2,     2,     2,    41,    50,     2,
      45,    46,    39,    37,    44,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
       2,    49,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,    51,    48,    53,     2,     2,     2,
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
      35,    36,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    56,    56,    57,    61,    62,    67,    68,    73,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    87,    88,
      95,    98,   101,   102,   105,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   121,   122,   123,   126,
     127,   132,   133,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   178,   179,   180,   181,
     182,   183,   184,   187,   188,   189,   190,   191,   192
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
  "TOKEN_DINT", "TOKEN_DFLOAT", "TOKEN_DDOUBLE", "TOKEN_IF", "TOKEN_ELSE",
  "TOKEN_TRUE", "TOKEN_FALSE", "TOKEN_FUNC", "TOKEN_DSTRING",
  "TOKEN_DBOOLEAN", "TOKEN_DCHAR", "TOKEN_UNSIGNED_INTEGER", "TOKEN_REAL",
  "TOKEN_DOUBLE", "TOKEN_STRING", "TOKEN_CHAR", "TOKEN_IDENTIFIER",
  "TOKEN_RETURN", "TOKEN_FINAL", "TOKEN_LEFT_SHIFT", "TOKEN_RIGHT_SHIFT",
  "TOKEN_EQ", "TOKEN_NE", "TOKEN_PLUS_ASSIGN", "TOKEN_MINUS_ASSIGN",
  "TOKEN_MULT_ASSIGN", "TOKEN_DIV_ASSIGN", "TOKEN_MOD_ASSIGN",
  "TOKEN_AND_ASSIGN", "TOKEN_OR_ASSIGN", "TOKEN_XOR_ASSIGN",
  "TOKEN_LSHIFT_ASSIGN", "TOKEN_RSHIFT_ASSIGN", "'+'", "'-'", "'*'", "'/'",
  "'%'", "NEG", "';'", "','", "'('", "')'", "'{'", "'}'", "'='", "'&'",
  "'|'", "'^'", "'~'", "$accept", "s", "lSentencia", "sentencia",
  "lista_Expr", "imprimir", "bloque", "declaracion_var",
  "declaracion_const", "asignacion", "sentencia_if", "lista_parametros",
  "sentencia_funcion", "expr", "primitivo", "tipoPrimitivo", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-123)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-11)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     102,   -42,  -123,  -123,  -123,   -34,  -123,  -123,  -123,   266,
     166,   106,   102,    36,   130,   -10,  -123,     5,  -123,  -123,
    -123,  -123,  -123,    33,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,   -14,   166,    51,   166,   221,  -123,
      31,   152,  -123,     9,    11,    15,     5,  -123,    39,    13,
     -36,   221,   183,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,    -3,   137,    17,    18,    26,    27,
     202,   137,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,    25,  -123,  -123,  -123,  -123,    30,
     166,   166,  -123,    41,  -123,   -12,   166,   166,   166,   166,
    -123,   221,   221,   221,   221,   240,   240,   137,   137,   137,
     221,   221,   221,   166,   134,   221,   221,    83,  -123,   221,
     221,   221,   221,   221,    41,  -123,     3,    72,    -2,  -123,
     106,    41,  -123,  -123,  -123,  -123
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    73,    74,    75,     0,    76,    77,    78,     0,
      16,     0,     0,     0,     0,     0,     9,     7,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    71,    72,    66,
      68,    69,    67,    70,    63,     0,     0,     0,    17,    62,
       0,     0,     1,     0,     0,     0,     6,     5,     0,    22,
       0,    19,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    25,     0,    54,     0,     0,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     3,     8,     4,     0,
       0,     0,    20,     0,    65,     0,     0,     0,     0,     0,
      53,    51,    52,    56,    57,    43,    44,    45,    46,    47,
      48,    49,    50,     0,     0,    23,    18,    36,    64,    58,
      59,    60,    61,    24,     0,    40,     0,     0,     0,    42,
       0,     0,    37,    38,    39,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -123,  -123,    81,    -5,    23,  -123,   -13,  -122,  -123,  -123,
     -40,  -123,  -123,    -6,  -123,   -11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    13,    14,    15,    60,    16,    17,    18,    19,    20,
      21,   136,    22,    61,    49,    23
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    56,   135,    24,    48,     5,    37,    38,   101,    55,
     102,    25,    39,    40,    41,    42,    43,    44,   144,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,   101,    57,   128,    45,    52,    53,    56,    75,
      80,    81,    46,   104,    58,    12,    55,   140,   -10,   141,
      47,    94,    96,    59,    97,    76,    77,    78,    98,    99,
      37,    38,   100,   106,   107,    79,    39,    40,    41,    42,
      43,    44,   108,   109,   123,   124,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    12,    45,
     127,   138,    59,    51,   125,   126,    46,   105,   143,     0,
     129,   130,   131,   132,    47,     1,     2,     3,     4,     5,
       2,     3,     4,   137,     6,     7,     8,   133,     6,     7,
       8,   139,     9,    10,    11,   142,     0,     0,   145,   137,
      -2,    54,     0,     1,     2,     3,     4,     5,     2,     3,
       4,     0,     6,     7,     8,     0,     6,     7,     8,    12,
       9,    10,    11,    54,     0,     1,     2,     3,     4,     5,
      82,    83,    84,    85,     6,     7,     8,     0,     0,     0,
       0,     0,     9,    10,    11,    37,    38,    12,     0,     0,
     134,    39,    40,    41,    42,    43,    44,    91,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
      95,     0,     0,     0,    45,     0,    82,    83,    84,    85,
       0,    46,     0,     0,     0,     0,     0,     0,     0,    47,
      86,    87,    88,    89,    90,    82,    83,    84,    85,   103,
       0,     0,     0,    91,    92,    93,     0,     0,     0,    86,
      87,    88,    89,    90,    82,    83,    84,    85,   110,     0,
       0,     0,    91,    92,    93,     0,     0,     0,    86,    87,
      88,    89,    90,    82,    83,    84,    85,     0,     0,     0,
       0,    91,    92,    93,     0,     0,     0,     0,     0,    88,
      89,    90,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36
};

static const yytype_int16 yycheck[] =
{
      11,    14,   124,    45,    10,     7,     9,    10,    44,    14,
      46,    45,    15,    16,    17,    18,    19,    20,   140,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    45,    44,    43,    46,    38,     0,     1,    51,    45,
      46,    47,    45,    46,    11,    47,    51,    44,    43,    46,
      53,    20,    43,    20,    43,     4,     5,     6,    43,    20,
       9,    10,    49,    46,    46,    14,    15,    16,    17,    18,
      19,    20,    46,    46,    49,    45,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    47,    38,
     103,     8,    20,    12,   100,   101,    45,    74,   138,    -1,
     106,   107,   108,   109,    53,     3,     4,     5,     6,     7,
       4,     5,     6,   124,    12,    13,    14,   123,    12,    13,
      14,   134,    20,    21,    22,   138,    -1,    -1,   141,   140,
       0,     1,    -1,     3,     4,     5,     6,     7,     4,     5,
       6,    -1,    12,    13,    14,    -1,    12,    13,    14,    47,
      20,    21,    22,     1,    -1,     3,     4,     5,     6,     7,
      23,    24,    25,    26,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,     9,    10,    47,    -1,    -1,
      46,    15,    16,    17,    18,    19,    20,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    -1,    38,    -1,    23,    24,    25,    26,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      37,    38,    39,    40,    41,    23,    24,    25,    26,    46,
      -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    23,    24,    25,    26,    46,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    12,    13,    14,    20,
      21,    22,    47,    55,    56,    57,    59,    60,    61,    62,
      63,    64,    66,    69,    45,    45,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    49,     9,    10,    15,
      16,    17,    18,    19,    20,    38,    45,    53,    67,    68,
      69,    56,     0,     1,     1,    57,    60,    43,    11,    20,
      58,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    45,    67,     4,     5,     6,    14,
      67,    67,    23,    24,    25,    26,    37,    38,    39,    40,
      41,    50,    51,    52,    20,    48,    43,    43,    43,    20,
      49,    44,    46,    46,    46,    58,    46,    46,    46,    46,
      46,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    49,    45,    67,    67,    60,    46,    67,
      67,    67,    67,    67,    46,    61,    65,    69,     8,    60,
      44,    46,    60,    64,    61,    60
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    56,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    58,    58,
      59,    60,    61,    61,    62,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    64,    64,    64,    65,
      65,    66,    66,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    68,    68,    68,    68,
      68,    68,    68,    69,    69,    69,    69,    69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     2,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     1,
       4,     3,     2,     4,     5,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     7,     7,     3,
       1,     7,     6,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     3,     4,     4,
       4,     4,     1,     1,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 56 "src/entriesTools/parser.y"
               { ast_root = (yyvsp[0].nodo); (yyval.nodo) = (yyvsp[0].nodo); }
#line 1389 "build/parser.tab.c"
    break;

  case 3: /* s: s error ';'  */
#line 57 "src/entriesTools/parser.y"
                  { yyerrok; }
#line 1395 "build/parser.tab.c"
    break;

  case 4: /* lSentencia: lSentencia sentencia ';'  */
#line 61 "src/entriesTools/parser.y"
                                     { agregarHijo((yyvsp[-2].nodo), (yyvsp[-1].nodo)); (yyval.nodo) = (yyvsp[-2].nodo);}
#line 1401 "build/parser.tab.c"
    break;

  case 5: /* lSentencia: sentencia ';'  */
#line 62 "src/entriesTools/parser.y"
                    {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[-1].nodo));
        (yyval.nodo) =  b;
    }
#line 1411 "build/parser.tab.c"
    break;

  case 6: /* lSentencia: lSentencia bloque  */
#line 67 "src/entriesTools/parser.y"
                        { agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1417 "build/parser.tab.c"
    break;

  case 7: /* lSentencia: bloque  */
#line 68 "src/entriesTools/parser.y"
             {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 1427 "build/parser.tab.c"
    break;

  case 8: /* lSentencia: lSentencia error ';'  */
#line 73 "src/entriesTools/parser.y"
                           { yyerrok; (yyval.nodo) = (yyvsp[-2].nodo); }
#line 1433 "build/parser.tab.c"
    break;

  case 9: /* sentencia: imprimir  */
#line 76 "src/entriesTools/parser.y"
                    {(yyval.nodo) = (yyvsp[0].nodo); }
#line 1439 "build/parser.tab.c"
    break;

  case 10: /* sentencia: bloque  */
#line 77 "src/entriesTools/parser.y"
             {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1445 "build/parser.tab.c"
    break;

  case 11: /* sentencia: declaracion_var  */
#line 78 "src/entriesTools/parser.y"
                      {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1451 "build/parser.tab.c"
    break;

  case 12: /* sentencia: declaracion_const  */
#line 79 "src/entriesTools/parser.y"
                        {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1457 "build/parser.tab.c"
    break;

  case 13: /* sentencia: asignacion  */
#line 80 "src/entriesTools/parser.y"
                 {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1463 "build/parser.tab.c"
    break;

  case 14: /* sentencia: sentencia_if  */
#line 81 "src/entriesTools/parser.y"
                   { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1469 "build/parser.tab.c"
    break;

  case 15: /* sentencia: sentencia_funcion  */
#line 82 "src/entriesTools/parser.y"
                        { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1475 "build/parser.tab.c"
    break;

  case 16: /* sentencia: TOKEN_RETURN  */
#line 83 "src/entriesTools/parser.y"
                   { (yyval.nodo) = NULL; }
#line 1481 "build/parser.tab.c"
    break;

  case 17: /* sentencia: TOKEN_RETURN expr  */
#line 84 "src/entriesTools/parser.y"
                        { (yyval.nodo) = nuevoReturnExpresion((yyvsp[0].nodo)); }
#line 1487 "build/parser.tab.c"
    break;

  case 18: /* lista_Expr: lista_Expr ',' expr  */
#line 87 "src/entriesTools/parser.y"
                                 { agregarHijo((yyvsp[-2].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-2].nodo); }
#line 1493 "build/parser.tab.c"
    break;

  case 19: /* lista_Expr: expr  */
#line 88 "src/entriesTools/parser.y"
           { 
                AbstractExpresion* b = nuevoListaExpresiones();
                agregarHijo(b, (yyvsp[0].nodo));
                (yyval.nodo) =  b;
            }
#line 1503 "build/parser.tab.c"
    break;

  case 20: /* imprimir: TOKEN_PRINT '(' lista_Expr ')'  */
#line 95 "src/entriesTools/parser.y"
                                         { (yyval.nodo) =  nuevoPrintExpresion((yyvsp[-1].nodo)); }
#line 1509 "build/parser.tab.c"
    break;

  case 21: /* bloque: '{' lSentencia '}'  */
#line 98 "src/entriesTools/parser.y"
                           { (yyval.nodo) =  (yyvsp[-1].nodo); }
#line 1515 "build/parser.tab.c"
    break;

  case 22: /* declaracion_var: tipoPrimitivo TOKEN_IDENTIFIER  */
#line 101 "src/entriesTools/parser.y"
                                                { (yyval.nodo) = nuevoDeclaracionVariables((yyvsp[-1].tipoDato), (yyvsp[0].string), NULL, (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 1521 "build/parser.tab.c"
    break;

  case 23: /* declaracion_var: tipoPrimitivo TOKEN_IDENTIFIER '=' expr  */
#line 102 "src/entriesTools/parser.y"
                                              { (yyval.nodo) = nuevoDeclaracionVariables((yyvsp[-3].tipoDato), (yyvsp[-2].string), (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1527 "build/parser.tab.c"
    break;

  case 24: /* declaracion_const: TOKEN_FINAL tipoPrimitivo TOKEN_IDENTIFIER '=' expr  */
#line 105 "src/entriesTools/parser.y"
                                                                       { (yyval.nodo) = nuevoDeclaracionConstante((yyvsp[-3].tipoDato), (yyvsp[-2].string), (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1533 "build/parser.tab.c"
    break;

  case 25: /* asignacion: TOKEN_IDENTIFIER '=' expr  */
#line 108 "src/entriesTools/parser.y"
                                      { (yyval.nodo) = nuevoAsignacionExpresion((yyvsp[-2].string), (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1539 "build/parser.tab.c"
    break;

  case 26: /* asignacion: TOKEN_IDENTIFIER TOKEN_PLUS_ASSIGN expr  */
#line 109 "src/entriesTools/parser.y"
                                              { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_SUMA, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1545 "build/parser.tab.c"
    break;

  case 27: /* asignacion: TOKEN_IDENTIFIER TOKEN_MINUS_ASSIGN expr  */
#line 110 "src/entriesTools/parser.y"
                                               { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_RESTA, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1551 "build/parser.tab.c"
    break;

  case 28: /* asignacion: TOKEN_IDENTIFIER TOKEN_MULT_ASSIGN expr  */
#line 111 "src/entriesTools/parser.y"
                                              { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_MULT, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1557 "build/parser.tab.c"
    break;

  case 29: /* asignacion: TOKEN_IDENTIFIER TOKEN_DIV_ASSIGN expr  */
#line 112 "src/entriesTools/parser.y"
                                             { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_DIV, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1563 "build/parser.tab.c"
    break;

  case 30: /* asignacion: TOKEN_IDENTIFIER TOKEN_MOD_ASSIGN expr  */
#line 113 "src/entriesTools/parser.y"
                                             { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_MOD, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1569 "build/parser.tab.c"
    break;

  case 31: /* asignacion: TOKEN_IDENTIFIER TOKEN_AND_ASSIGN expr  */
#line 114 "src/entriesTools/parser.y"
                                             { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_AND, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1575 "build/parser.tab.c"
    break;

  case 32: /* asignacion: TOKEN_IDENTIFIER TOKEN_OR_ASSIGN expr  */
#line 115 "src/entriesTools/parser.y"
                                            { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_OR, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1581 "build/parser.tab.c"
    break;

  case 33: /* asignacion: TOKEN_IDENTIFIER TOKEN_XOR_ASSIGN expr  */
#line 116 "src/entriesTools/parser.y"
                                             { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_XOR, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1587 "build/parser.tab.c"
    break;

  case 34: /* asignacion: TOKEN_IDENTIFIER TOKEN_LSHIFT_ASSIGN expr  */
#line 117 "src/entriesTools/parser.y"
                                                { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_LSHIFT, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1593 "build/parser.tab.c"
    break;

  case 35: /* asignacion: TOKEN_IDENTIFIER TOKEN_RSHIFT_ASSIGN expr  */
#line 118 "src/entriesTools/parser.y"
                                                { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_RSHIFT, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 1599 "build/parser.tab.c"
    break;

  case 36: /* sentencia_if: TOKEN_IF '(' expr ')' bloque  */
#line 121 "src/entriesTools/parser.y"
                                           { (yyval.nodo) = nuevoIfExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1605 "build/parser.tab.c"
    break;

  case 37: /* sentencia_if: TOKEN_IF '(' expr ')' bloque TOKEN_ELSE bloque  */
#line 122 "src/entriesTools/parser.y"
                                                     { (yyval.nodo) = nuevoIfElseExpresion((yyvsp[-4].nodo), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1611 "build/parser.tab.c"
    break;

  case 38: /* sentencia_if: TOKEN_IF '(' expr ')' bloque TOKEN_ELSE sentencia_if  */
#line 123 "src/entriesTools/parser.y"
                                                           { (yyval.nodo) = nuevoElseIfExpresion((yyvsp[-4].nodo), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1617 "build/parser.tab.c"
    break;

  case 39: /* lista_parametros: lista_parametros ',' declaracion_var  */
#line 126 "src/entriesTools/parser.y"
                                                       { agregarHijo((yyvsp[-2].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-2].nodo); }
#line 1623 "build/parser.tab.c"
    break;

  case 40: /* lista_parametros: declaracion_var  */
#line 127 "src/entriesTools/parser.y"
                      { AbstractExpresion* b = nuevoListaParametros();
                agregarHijo(b, (yyvsp[0].nodo));
                (yyval.nodo) =  b; }
#line 1631 "build/parser.tab.c"
    break;

  case 41: /* sentencia_funcion: tipoPrimitivo TOKEN_FUNC TOKEN_IDENTIFIER '(' lista_parametros ')' bloque  */
#line 132 "src/entriesTools/parser.y"
                                                                                             {  (yyval.nodo) = nuevoFuncionExpresion((yyvsp[-6].tipoDato), (yyvsp[-4].string), (yyvsp[-2].nodo), (yyvsp[0].nodo));}
#line 1637 "build/parser.tab.c"
    break;

  case 42: /* sentencia_funcion: tipoPrimitivo TOKEN_FUNC TOKEN_IDENTIFIER '(' ')' bloque  */
#line 133 "src/entriesTools/parser.y"
                                                               {  (yyval.nodo) = nuevoFuncionExpresion((yyvsp[-5].tipoDato), (yyvsp[-3].string), NULL, (yyvsp[0].nodo));}
#line 1643 "build/parser.tab.c"
    break;

  case 43: /* expr: expr '+' expr  */
#line 152 "src/entriesTools/parser.y"
                      { (yyval.nodo) =  nuevoSumaExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo));  }
#line 1649 "build/parser.tab.c"
    break;

  case 44: /* expr: expr '-' expr  */
#line 153 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoRestaExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1655 "build/parser.tab.c"
    break;

  case 45: /* expr: expr '*' expr  */
#line 154 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoMultiplicacionExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1661 "build/parser.tab.c"
    break;

  case 46: /* expr: expr '/' expr  */
#line 155 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoDivisionExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1667 "build/parser.tab.c"
    break;

  case 47: /* expr: expr '%' expr  */
#line 156 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoModuloExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1673 "build/parser.tab.c"
    break;

  case 48: /* expr: expr '&' expr  */
#line 157 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoBitwiseAndExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1679 "build/parser.tab.c"
    break;

  case 49: /* expr: expr '|' expr  */
#line 158 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoBitwiseOrExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1685 "build/parser.tab.c"
    break;

  case 50: /* expr: expr '^' expr  */
#line 159 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoBitwiseXorExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1691 "build/parser.tab.c"
    break;

  case 51: /* expr: expr TOKEN_LEFT_SHIFT expr  */
#line 160 "src/entriesTools/parser.y"
                                 { (yyval.nodo) =  nuevoBitwiseLeftShiftExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1697 "build/parser.tab.c"
    break;

  case 52: /* expr: expr TOKEN_RIGHT_SHIFT expr  */
#line 161 "src/entriesTools/parser.y"
                                  { (yyval.nodo) =  nuevoBitwiseRightShiftExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1703 "build/parser.tab.c"
    break;

  case 53: /* expr: '(' expr ')'  */
#line 162 "src/entriesTools/parser.y"
                   { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1709 "build/parser.tab.c"
    break;

  case 54: /* expr: '-' expr  */
#line 163 "src/entriesTools/parser.y"
                          { (yyval.nodo) =  nuevoUnarioExpresion((yyvsp[0].nodo));  }
#line 1715 "build/parser.tab.c"
    break;

  case 55: /* expr: '~' expr  */
#line 164 "src/entriesTools/parser.y"
                          { (yyval.nodo) =  nuevoBitwiseNotExpresion((yyvsp[0].nodo));  }
#line 1721 "build/parser.tab.c"
    break;

  case 56: /* expr: expr TOKEN_EQ expr  */
#line 165 "src/entriesTools/parser.y"
                         { (yyval.nodo) = nuevoIgualdadExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1727 "build/parser.tab.c"
    break;

  case 57: /* expr: expr TOKEN_NE expr  */
#line 166 "src/entriesTools/parser.y"
                         { (yyval.nodo) = nuevoDesigualdadExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1733 "build/parser.tab.c"
    break;

  case 58: /* expr: '(' TOKEN_DINT ')' expr  */
#line 167 "src/entriesTools/parser.y"
                              { (yyval.nodo) = nuevoCastingExpresion((yyvsp[0].nodo), INT); }
#line 1739 "build/parser.tab.c"
    break;

  case 59: /* expr: '(' TOKEN_DFLOAT ')' expr  */
#line 168 "src/entriesTools/parser.y"
                                { (yyval.nodo) = nuevoCastingExpresion((yyvsp[0].nodo), FLOAT); }
#line 1745 "build/parser.tab.c"
    break;

  case 60: /* expr: '(' TOKEN_DDOUBLE ')' expr  */
#line 169 "src/entriesTools/parser.y"
                                 { (yyval.nodo) = nuevoCastingExpresion((yyvsp[0].nodo), DOUBLE); }
#line 1751 "build/parser.tab.c"
    break;

  case 61: /* expr: '(' TOKEN_DCHAR ')' expr  */
#line 170 "src/entriesTools/parser.y"
                               { (yyval.nodo) = nuevoCastingExpresion((yyvsp[0].nodo), CHAR); }
#line 1757 "build/parser.tab.c"
    break;

  case 62: /* expr: primitivo  */
#line 171 "src/entriesTools/parser.y"
                { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1763 "build/parser.tab.c"
    break;

  case 63: /* expr: TOKEN_IDENTIFIER  */
#line 172 "src/entriesTools/parser.y"
                       { (yyval.nodo) = nuevoIdentificadorExpresion((yyvsp[0].string), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 1769 "build/parser.tab.c"
    break;

  case 64: /* expr: TOKEN_IDENTIFIER '(' lista_Expr ')'  */
#line 173 "src/entriesTools/parser.y"
                                          { (yyval.nodo) = nuevoLlamadaExpresion((yyvsp[-3].string), (yyvsp[-1].nodo)); }
#line 1775 "build/parser.tab.c"
    break;

  case 65: /* expr: TOKEN_IDENTIFIER '(' ')'  */
#line 174 "src/entriesTools/parser.y"
                              { /* sin implementar */ }
#line 1781 "build/parser.tab.c"
    break;

  case 66: /* primitivo: TOKEN_UNSIGNED_INTEGER  */
#line 178 "src/entriesTools/parser.y"
                                  { (yyval.nodo) =  nuevoPrimitivoExpresion((yyvsp[0].string), INT); }
#line 1787 "build/parser.tab.c"
    break;

  case 67: /* primitivo: TOKEN_STRING  */
#line 179 "src/entriesTools/parser.y"
                   { (yyval.nodo) =  nuevoPrimitivoExpresion((yyvsp[0].string), STRING); }
#line 1793 "build/parser.tab.c"
    break;

  case 68: /* primitivo: TOKEN_REAL  */
#line 180 "src/entriesTools/parser.y"
                 { (yyval.nodo) =  nuevoPrimitivoExpresion((yyvsp[0].string), FLOAT); }
#line 1799 "build/parser.tab.c"
    break;

  case 69: /* primitivo: TOKEN_DOUBLE  */
#line 181 "src/entriesTools/parser.y"
                   { (yyval.nodo) =  nuevoPrimitivoExpresion((yyvsp[0].string), DOUBLE); }
#line 1805 "build/parser.tab.c"
    break;

  case 70: /* primitivo: TOKEN_CHAR  */
#line 182 "src/entriesTools/parser.y"
                 { (yyval.nodo) =  nuevoPrimitivoExpresion((yyvsp[0].string), CHAR); }
#line 1811 "build/parser.tab.c"
    break;

  case 71: /* primitivo: TOKEN_TRUE  */
#line 183 "src/entriesTools/parser.y"
                 { (yyval.nodo) =  nuevoPrimitivoExpresion("T", BOOLEAN); }
#line 1817 "build/parser.tab.c"
    break;

  case 72: /* primitivo: TOKEN_FALSE  */
#line 184 "src/entriesTools/parser.y"
                  { (yyval.nodo) =  nuevoPrimitivoExpresion("F", BOOLEAN); }
#line 1823 "build/parser.tab.c"
    break;

  case 73: /* tipoPrimitivo: TOKEN_DINT  */
#line 187 "src/entriesTools/parser.y"
                          { (yyval.tipoDato) = INT; }
#line 1829 "build/parser.tab.c"
    break;

  case 74: /* tipoPrimitivo: TOKEN_DFLOAT  */
#line 188 "src/entriesTools/parser.y"
                   { (yyval.tipoDato) = FLOAT; }
#line 1835 "build/parser.tab.c"
    break;

  case 75: /* tipoPrimitivo: TOKEN_DDOUBLE  */
#line 189 "src/entriesTools/parser.y"
                    { (yyval.tipoDato) = DOUBLE; }
#line 1841 "build/parser.tab.c"
    break;

  case 76: /* tipoPrimitivo: TOKEN_DSTRING  */
#line 190 "src/entriesTools/parser.y"
                    { (yyval.tipoDato) = STRING; }
#line 1847 "build/parser.tab.c"
    break;

  case 77: /* tipoPrimitivo: TOKEN_DBOOLEAN  */
#line 191 "src/entriesTools/parser.y"
                     { (yyval.tipoDato) = BOOLEAN; }
#line 1853 "build/parser.tab.c"
    break;

  case 78: /* tipoPrimitivo: TOKEN_DCHAR  */
#line 192 "src/entriesTools/parser.y"
                  { (yyval.tipoDato) = CHAR; }
#line 1859 "build/parser.tab.c"
    break;


#line 1863 "build/parser.tab.c"

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

#line 194 "src/entriesTools/parser.y"


/* definición de yyerror, usa el yylloc global para ubicación */
void yyerror(const char *s) {
    int ambito = contextoActualReporte ? contextoActualReporte->nombre : 0;
    agregarErrorSintactico(s, yylloc.first_line, yylloc.first_column, ambito);
}
