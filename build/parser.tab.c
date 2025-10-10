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
  YYSYMBOL_TOKEN_LENGTH = 18,              /* TOKEN_LENGTH  */
  YYSYMBOL_TOKEN_DBOOLEAN = 19,            /* TOKEN_DBOOLEAN  */
  YYSYMBOL_TOKEN_DCHAR = 20,               /* TOKEN_DCHAR  */
  YYSYMBOL_TOKEN_UNSIGNED_INTEGER = 21,    /* TOKEN_UNSIGNED_INTEGER  */
  YYSYMBOL_TOKEN_REAL = 22,                /* TOKEN_REAL  */
  YYSYMBOL_TOKEN_DOUBLE = 23,              /* TOKEN_DOUBLE  */
  YYSYMBOL_TOKEN_STRING = 24,              /* TOKEN_STRING  */
  YYSYMBOL_TOKEN_CHAR = 25,                /* TOKEN_CHAR  */
  YYSYMBOL_TOKEN_IDENTIFIER = 26,          /* TOKEN_IDENTIFIER  */
  YYSYMBOL_TOKEN_RETURN = 27,              /* TOKEN_RETURN  */
  YYSYMBOL_TOKEN_FINAL = 28,               /* TOKEN_FINAL  */
  YYSYMBOL_TOKEN_LEFT_SHIFT = 29,          /* TOKEN_LEFT_SHIFT  */
  YYSYMBOL_TOKEN_RIGHT_SHIFT = 30,         /* TOKEN_RIGHT_SHIFT  */
  YYSYMBOL_TOKEN_EQ = 31,                  /* TOKEN_EQ  */
  YYSYMBOL_TOKEN_NE = 32,                  /* TOKEN_NE  */
  YYSYMBOL_TOKEN_GE = 33,                  /* TOKEN_GE  */
  YYSYMBOL_TOKEN_LE = 34,                  /* TOKEN_LE  */
  YYSYMBOL_TOKEN_AND = 35,                 /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 36,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_INCREMENT = 37,           /* TOKEN_INCREMENT  */
  YYSYMBOL_TOKEN_DECREMENT = 38,           /* TOKEN_DECREMENT  */
  YYSYMBOL_TOKEN_PLUS_ASSIGN = 39,         /* TOKEN_PLUS_ASSIGN  */
  YYSYMBOL_TOKEN_MINUS_ASSIGN = 40,        /* TOKEN_MINUS_ASSIGN  */
  YYSYMBOL_TOKEN_MULT_ASSIGN = 41,         /* TOKEN_MULT_ASSIGN  */
  YYSYMBOL_TOKEN_DIV_ASSIGN = 42,          /* TOKEN_DIV_ASSIGN  */
  YYSYMBOL_TOKEN_MOD_ASSIGN = 43,          /* TOKEN_MOD_ASSIGN  */
  YYSYMBOL_TOKEN_AND_ASSIGN = 44,          /* TOKEN_AND_ASSIGN  */
  YYSYMBOL_TOKEN_OR_ASSIGN = 45,           /* TOKEN_OR_ASSIGN  */
  YYSYMBOL_TOKEN_XOR_ASSIGN = 46,          /* TOKEN_XOR_ASSIGN  */
  YYSYMBOL_TOKEN_LSHIFT_ASSIGN = 47,       /* TOKEN_LSHIFT_ASSIGN  */
  YYSYMBOL_TOKEN_RSHIFT_ASSIGN = 48,       /* TOKEN_RSHIFT_ASSIGN  */
  YYSYMBOL_TOKEN_SWITCH = 49,              /* TOKEN_SWITCH  */
  YYSYMBOL_TOKEN_CASE = 50,                /* TOKEN_CASE  */
  YYSYMBOL_TOKEN_BREAK = 51,               /* TOKEN_BREAK  */
  YYSYMBOL_TOKEN_DEFAULT = 52,             /* TOKEN_DEFAULT  */
  YYSYMBOL_TOKEN_WHILE = 53,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_CONTINUE = 54,            /* TOKEN_CONTINUE  */
  YYSYMBOL_TOKEN_FOR = 55,                 /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_NEW = 56,                 /* TOKEN_NEW  */
  YYSYMBOL_57_ = 57,                       /* '?'  */
  YYSYMBOL_58_ = 58,                       /* ':'  */
  YYSYMBOL_59_ = 59,                       /* '+'  */
  YYSYMBOL_60_ = 60,                       /* '-'  */
  YYSYMBOL_61_ = 61,                       /* '*'  */
  YYSYMBOL_62_ = 62,                       /* '/'  */
  YYSYMBOL_63_ = 63,                       /* '%'  */
  YYSYMBOL_NEG = 64,                       /* NEG  */
  YYSYMBOL_65_ = 65,                       /* ';'  */
  YYSYMBOL_66_ = 66,                       /* '('  */
  YYSYMBOL_67_ = 67,                       /* ')'  */
  YYSYMBOL_68_ = 68,                       /* ','  */
  YYSYMBOL_69_ = 69,                       /* '{'  */
  YYSYMBOL_70_ = 70,                       /* '}'  */
  YYSYMBOL_71_ = 71,                       /* '='  */
  YYSYMBOL_72_ = 72,                       /* '['  */
  YYSYMBOL_73_ = 73,                       /* ']'  */
  YYSYMBOL_74_ = 74,                       /* '&'  */
  YYSYMBOL_75_ = 75,                       /* '|'  */
  YYSYMBOL_76_ = 76,                       /* '^'  */
  YYSYMBOL_77_ = 77,                       /* '~'  */
  YYSYMBOL_78_ = 78,                       /* '>'  */
  YYSYMBOL_79_ = 79,                       /* '<'  */
  YYSYMBOL_80_ = 80,                       /* '!'  */
  YYSYMBOL_81_ = 81,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 82,                  /* $accept  */
  YYSYMBOL_s = 83,                         /* s  */
  YYSYMBOL_lSentencia = 84,                /* lSentencia  */
  YYSYMBOL_sentencia = 85,                 /* sentencia  */
  YYSYMBOL_lista_Expr = 86,                /* lista_Expr  */
  YYSYMBOL_imprimir = 87,                  /* imprimir  */
  YYSYMBOL_bloque = 88,                    /* bloque  */
  YYSYMBOL_declaracion_var = 89,           /* declaracion_var  */
  YYSYMBOL_declaracion_const = 90,         /* declaracion_const  */
  YYSYMBOL_asignacion = 91,                /* asignacion  */
  YYSYMBOL_sentencia_if = 92,              /* sentencia_if  */
  YYSYMBOL_lista_parametros = 93,          /* lista_parametros  */
  YYSYMBOL_sentencia_funcion = 94,         /* sentencia_funcion  */
  YYSYMBOL_sentencia_switch = 95,          /* sentencia_switch  */
  YYSYMBOL_lista_casos = 96,               /* lista_casos  */
  YYSYMBOL_caso = 97,                      /* caso  */
  YYSYMBOL_sentencia_while = 98,           /* sentencia_while  */
  YYSYMBOL_sentencia_for = 99,             /* sentencia_for  */
  YYSYMBOL_expr = 100,                     /* expr  */
  YYSYMBOL_primitivo = 101,                /* primitivo  */
  YYSYMBOL_tipoPrimitivo = 102,            /* tipoPrimitivo  */
  YYSYMBOL_tipoArray = 103,                /* tipoArray  */
  YYSYMBOL_declaracion_array = 104,        /* declaracion_array  */
  YYSYMBOL_lista_elementos = 105,          /* lista_elementos  */
  YYSYMBOL_acceso_array = 106,             /* acceso_array  */
  YYSYMBOL_tipoMatrix = 107,               /* tipoMatrix  */
  YYSYMBOL_declaracion_matrix = 108,       /* declaracion_matrix  */
  YYSYMBOL_lista_filas = 109,              /* lista_filas  */
  YYSYMBOL_lista_fila = 110,               /* lista_fila  */
  YYSYMBOL_acceso_matrix = 111             /* acceso_matrix  */
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
#define YYFINAL  86
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1557

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  340

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


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
       2,     2,     2,    80,     2,     2,     2,    63,    74,     2,
      66,    67,    61,    59,    68,    60,    81,    62,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    65,
      79,    71,    78,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    72,     2,    73,    76,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,    75,    70,    77,     2,     2,     2,
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
      55,    56,    64
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    58,    58,    59,    63,    64,    69,    70,    75,    76,
      81,    82,    87,    88,    93,    94,    99,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   118,   119,   126,   127,   133,   136,   137,   140,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   162,   163,   164,   167,
     168,   173,   174,   175,   176,   179,   182,   183,   190,   191,
     194,   197,   198,   199,   200,   201,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   260,
     268,   276,   284,   292,   300,   301,   302,   303,   304,   305,
     306,   310,   311,   312,   313,   314,   315,   316,   319,   320,
     321,   322,   323,   324,   325,   329,   332,   333,   336,   337,
     344,   348,   351,   352,   355,   356,   363,   366
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
  "TOKEN_ARRAYS", "TOKEN_LENGTH", "TOKEN_DBOOLEAN", "TOKEN_DCHAR",
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
  "'.'", "$accept", "s", "lSentencia", "sentencia", "lista_Expr",
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

#define YYPACT_NINF (-242)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-70)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     644,   -47,  -242,  -242,  -242,  -242,   -41,  -242,  -242,  -242,
    1485,   418,   251,    22,    25,   -10,  -242,    -7,  -242,    15,
     644,   107,   564,    23,  -242,    27,  -242,  -242,  -242,  -242,
    -242,  -242,  -242,  -242,    -4,    72,  -242,    75,  -242,   314,
     418,  -242,  -242,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   332,   418,   418,  -242,  -242,    40,    67,
      69,    73,    86,  -242,  -242,  -242,  -242,  -242,   -14,   130,
     142,   418,    89,   418,   418,  1432,  -242,  -242,  -242,   144,
    -242,  -242,   418,   418,    11,   604,  -242,   111,   117,   118,
      27,  -242,  -242,  -242,  -242,  -242,   160,    13,   116,   121,
     122,  -242,    50,  1432,   655,  1432,  1432,  1432,  1432,  1432,
    1432,  1432,  1432,  1432,  1432,  -242,    52,  1432,   708,   169,
     176,   178,   179,   180,  -242,  -242,   400,   418,  -242,  -242,
     371,   127,   141,   143,   147,   148,   743,   371,   371,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   198,   140,
     796,   849,   418,   153,   194,  -242,  -242,  -242,  -242,   163,
     168,   418,   159,    17,    18,  -242,   418,   150,  -242,    51,
     166,   167,   172,   173,   174,  -242,    57,   858,   418,   418,
     418,   418,   418,  -242,  1432,  1432,  1432,  1432,  1432,  1432,
    1432,  1432,   911,  1440,  1440,   371,   371,   371,  1432,  1432,
    1432,  1432,  1432,  -242,   418,   175,   150,   919,   418,    19,
     193,   150,  -242,    85,   215,  1432,   170,   251,   418,   251,
     177,  1432,   236,   418,   418,   418,   418,   418,   418,   418,
    -242,   181,  1432,  1432,  1432,  1432,  1432,   418,  1432,    -3,
    -242,   -17,   972,   418,   150,    91,  -242,   150,   251,   190,
    -242,   191,  1432,   -13,   200,   418,    12,  -242,     6,  1432,
     981,  1034,  1087,  1140,    94,  1193,    96,   418,  1432,   418,
     192,   -24,  -242,   797,   150,   182,    16,  1246,  -242,   150,
    -242,  -242,   418,   418,  -242,   418,    21,   177,  -242,  -242,
    -242,   202,  -242,  -242,  -242,  -242,  -242,  -242,  1255,  1308,
     644,  -242,  -242,  -242,   150,   150,   184,   150,  -242,  1317,
    1432,  1370,  -242,  -242,   418,  -242,   644,   484,  -242,  -242,
     150,  -242,  -242,   203,  1432,   524,  -242,   418,  1379,  -242
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,   129,   130,   131,   128,     0,   132,   133,   134,
       0,    29,     0,     0,     0,     0,    27,     0,    28,     0,
       0,     0,     0,     0,    17,     7,    19,    20,    23,     9,
      24,    11,    13,    15,     0,     0,    21,     0,    22,     0,
       0,    53,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,   127,     0,     0,
       0,     0,     0,   121,   123,   124,   122,   125,   105,     0,
       0,     0,     0,     0,     0,    30,   104,   114,   115,     0,
      52,    54,     0,     0,     0,     0,     1,     0,     0,     0,
       6,     8,    10,    12,    14,     5,     0,    36,     0,     0,
       0,    34,     0,    32,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    26,     0,    39,     0,     0,
       0,     0,     0,     0,   118,   120,     0,     0,   117,   119,
      87,     0,     0,     0,     0,     0,     0,    88,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,     3,    16,     4,     0,
       0,     0,   135,     0,     0,    33,     0,     0,    25,     0,
       0,     0,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,    86,    84,    85,    89,    90,    93,    94,
      95,    96,     0,    76,    77,    78,    79,    80,    81,    82,
      83,    91,    92,   116,     0,     0,     0,     0,     0,    36,
       0,     0,    60,     0,     0,    37,     0,     0,     0,     0,
       0,    31,    56,     0,     0,     0,     0,     0,     0,     0,
     106,   140,   100,   101,   102,    99,   103,     0,    38,     0,
      70,     0,     0,     0,     0,     0,    64,     0,     0,    36,
     141,     0,   139,     0,     0,     0,     0,   145,     0,    40,
       0,     0,     0,     0,     0,    32,     0,     0,    98,     0,
       0,     0,    67,     0,     0,     0,     0,     0,    62,     0,
      63,    59,     0,     0,   137,     0,     0,     0,   143,    57,
      58,     0,   108,   109,   110,   112,   111,   113,     0,     0,
       0,    65,    66,    74,     0,     0,     0,     0,    61,     0,
     138,     0,   146,   144,     0,   147,     0,     0,    73,    72,
       0,    75,   136,     0,    41,     0,    71,     0,     0,   142
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -242,  -242,    -8,   -19,   -48,  -242,   -20,   -73,  -242,  -241,
     -21,    32,  -242,   -18,  -242,    -5,   -16,   -15,   -11,  -242,
       1,  -242,  -242,     0,  -242,  -242,  -242,  -242,   -35,  -242
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    21,    22,    23,   102,    24,    25,    26,    27,    28,
      29,   223,    30,    31,   281,   282,    32,    33,   103,    76,
      34,    35,    36,   263,    77,    37,    38,   266,   267,    78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,    91,    90,    89,    92,   116,    93,    94,    96,   283,
     285,   163,    85,    79,     6,     2,     3,     4,     5,    39,
      13,    14,    97,   124,   125,    40,   279,     7,   280,   104,
       8,     9,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   283,   117,   118,   316,   311,   279,    80,   280,
     284,    81,   126,    13,    14,   293,    82,   294,   127,    83,
     130,   136,   137,   138,    91,    90,    89,    92,    98,    93,
      94,   160,   161,   227,   229,    20,   162,   253,   186,   170,
     297,    84,   298,   315,   171,   164,   228,   230,    95,   293,
     171,   322,   -18,   131,   132,   133,   134,   222,    99,    56,
      57,   100,    58,    59,    60,    61,    62,    86,    87,   135,
      63,    64,    65,    66,    67,    68,   187,   175,   176,   178,
     176,   119,   233,   234,   240,   176,    69,    70,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   222,   120,    71,
     121,   217,   257,   258,   122,    72,   128,   232,   289,   258,
     225,   305,   176,   307,   176,   231,    73,   123,   129,    74,
     159,   224,     2,     3,     4,     5,   166,   242,   243,   244,
     245,   246,   167,   168,     7,   291,   169,     8,     9,   172,
     274,   276,   173,   174,   188,   180,   250,     2,     3,     4,
       5,   256,   181,   248,   182,   183,   184,   252,   189,     7,
     190,   214,     8,     9,   191,   192,   213,   262,   218,    20,
     219,   224,   269,   270,   271,   272,   273,   275,   261,   220,
     264,   226,   235,   236,   288,   221,   278,   290,   237,   238,
     239,   259,   287,   260,   249,   268,   265,   300,   299,   314,
     310,   330,   255,   277,   262,     2,     3,     4,     5,   224,
     254,   171,   323,   292,   313,   296,   308,     7,   309,   318,
       8,     9,   295,   324,     0,   337,   312,     0,     0,     0,
       0,   319,   320,     0,   321,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   328,   329,     0,   331,     0,     0,
       0,     0,   327,     0,     0,     0,    91,    90,    89,    92,
     336,    93,    94,   334,    91,    90,    89,    92,   335,    93,
      94,     0,     0,     0,    56,    57,   338,    58,    59,    60,
      61,    62,     0,     0,     0,    63,    64,    65,    66,    67,
      68,     0,    56,    57,     0,    58,    59,    60,    61,    62,
       0,    69,    70,    63,    64,    65,    66,    67,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
      70,     0,     0,     0,    71,     0,     0,     0,     0,     0,
      72,   101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    71,     0,    74,     0,     0,     0,    72,   115,
     139,   140,   141,   142,   143,   144,   145,   146,     0,    73,
      56,    57,    74,    58,    59,    60,    61,    62,     0,     0,
       0,    63,    64,    65,    66,    67,    68,     0,    56,    57,
       0,    58,    59,    60,    61,    62,     0,    69,    70,    63,
      64,    65,    66,    67,    68,   153,   154,   155,     0,   156,
     157,     0,   158,     0,     0,    69,    70,     0,     0,     0,
      71,     0,     0,     0,     0,     0,    72,   185,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    71,     0,
      74,     0,     0,     0,    72,    88,     0,     1,     2,     3,
       4,     5,     6,     0,     0,    73,     0,     0,    74,     0,
       7,     0,     0,     8,     9,     0,     0,     0,     0,     0,
      10,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,     0,     0,    88,     0,     1,     2,     3,
       4,     5,     6,    15,   -69,    16,   -69,    17,    18,    19,
       7,     0,     0,     8,     9,     0,     0,     0,     0,     0,
      10,    11,    12,    20,   -69,     0,     0,     0,     0,     0,
       0,    13,    14,     0,    -2,    88,     0,     1,     2,     3,
       4,     5,     6,    15,   -68,    16,   -68,    17,    18,    19,
       7,     0,     0,     8,     9,     0,     0,     0,     0,     0,
      10,    11,    12,    20,   -68,     0,     0,     0,     0,     0,
       0,    13,    14,     0,     0,    88,     0,     1,     2,     3,
       4,     5,     6,    15,     0,    16,     0,    17,    18,    19,
       7,     0,     0,     8,     9,     0,     0,     0,     0,     0,
      10,    11,    12,    20,     0,     0,     0,     0,     0,     0,
       0,    13,    14,     0,     0,     0,     0,     1,     2,     3,
       4,     5,     6,    15,     0,    16,     0,    17,    18,    19,
       7,     0,     0,     8,     9,     0,     0,     0,     0,     0,
      10,    11,    12,    20,   165,     0,     0,     0,     0,     0,
       0,    13,    14,     0,   139,   140,   141,   142,   143,   144,
     145,   146,     0,    15,     0,    16,     0,    17,    18,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,    20,   148,   149,   150,   151,   152,     0,
       0,     0,   177,     0,     0,     0,     0,     0,     0,   153,
     154,   155,     0,   156,   157,     0,   158,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,     0,   148,   149,   150,
     151,   152,   139,   140,   141,   142,   143,   144,   145,   146,
       0,   179,   153,   154,   155,     0,   156,   157,     0,   158,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,     0,   148,   149,   150,   151,   152,     0,     0,     0,
     193,     0,     0,     0,     0,     0,     0,   153,   154,   155,
       0,   156,   157,     0,   158,   139,   140,   141,   142,   143,
     144,   145,   146,     0,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,   147,     0,   148,   149,   150,   151,   152,
       0,     0,     0,   215,     0,     0,     0,     0,    54,    55,
     153,   154,   155,     0,   156,   157,     0,   158,   139,   140,
     141,   142,   143,   144,   145,   146,     0,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   147,     0,   148,   149,
     150,   151,   152,     0,     0,   147,   216,   148,   149,   150,
     151,   152,     0,   153,   154,   155,     0,   156,   157,     0,
     158,   241,   153,   154,   155,     0,   156,   157,     0,   158,
     139,   140,   141,   142,   143,   144,   145,   146,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   147,   247,
     148,   149,   150,   151,   152,     0,   147,     0,   148,   149,
     150,   151,   152,     0,   251,   153,   154,   155,     0,   156,
     157,     0,   158,   153,   154,   155,     0,   156,   157,     0,
     158,   139,   140,   141,   142,   143,   144,   145,   146,     0,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   147,
       0,   148,   149,   150,   151,   152,     0,   286,   147,     0,
     148,   149,   150,   151,   152,     0,   153,   154,   155,     0,
     156,   157,     0,   158,   301,   153,   154,   155,     0,   156,
     157,     0,   158,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   147,     0,   148,   149,   150,   151,   152,     0,     0,
       0,   302,     0,     0,     0,     0,     0,     0,   153,   154,
     155,     0,   156,   157,     0,   158,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   147,     0,   148,   149,   150,   151,
     152,     0,     0,     0,   303,     0,     0,     0,     0,     0,
       0,   153,   154,   155,     0,   156,   157,     0,   158,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,     0,   148,
     149,   150,   151,   152,     0,     0,     0,   304,     0,     0,
       0,     0,     0,     0,   153,   154,   155,     0,   156,   157,
       0,   158,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,     0,   148,   149,   150,   151,   152,     0,     0,     0,
     306,     0,     0,     0,     0,     0,     0,   153,   154,   155,
       0,   156,   157,     0,   158,   139,   140,   141,   142,   143,
     144,   145,   146,     0,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   147,     0,   148,   149,   150,   151,   152,
       0,     0,   147,   317,   148,   149,   150,   151,   152,     0,
     153,   154,   155,     0,   156,   157,     0,   158,   325,   153,
     154,   155,     0,   156,   157,     0,   158,   139,   140,   141,
     142,   143,   144,   145,   146,     0,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   326,   148,   149,   150,
     151,   152,     0,     0,   147,     0,   148,   149,   150,   151,
     152,     0,   153,   154,   155,     0,   156,   157,     0,   158,
     332,   153,   154,   155,     0,   156,   157,     0,   158,   139,
     140,   141,   142,   143,   144,   145,   146,     0,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,     0,   148,
     149,   150,   151,   152,     0,     0,   147,     0,   148,   149,
     150,   151,   152,   333,   153,   154,   155,     0,   156,   157,
       0,   158,   339,   153,   154,   155,     0,   156,   157,     0,
     158,   139,   140,   141,   142,   143,   144,   145,   146,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   147,
       0,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,   150,   151,   152,     0,     0,   153,   154,   155,     0,
     156,   157,     0,   158,   153,   154,   155,     0,   156,   157,
       0,   158,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,     0,     0,     0,    54,    55
};

static const yytype_int16 yycheck[] =
{
      11,    22,    22,    22,    22,    53,    22,    22,    12,    26,
     251,    84,    20,    12,     8,     4,     5,     6,     7,    66,
      37,    38,    26,    37,    38,    66,    50,    16,    52,    40,
      19,    20,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    26,    54,    55,   286,    70,    50,    26,    52,
      67,    26,    66,    37,    38,    68,    66,    70,    72,    66,
      71,    72,    73,    74,    85,    85,    85,    85,    72,    85,
      85,    82,    83,    56,    56,    69,    65,    58,   126,    66,
      68,    66,    70,    67,    71,    84,    69,    69,    65,    68,
      71,    70,    65,     4,     5,     6,     7,   170,    26,    10,
      11,    26,    13,    14,    15,    16,    17,     0,     1,    20,
      21,    22,    23,    24,    25,    26,   127,    67,    68,    67,
      68,    81,    71,    72,    67,    68,    37,    38,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   220,    81,    60,
      81,   162,    67,    68,    81,    66,    26,   177,    67,    68,
     171,    67,    68,    67,    68,   176,    77,    81,    26,    80,
      26,   170,     4,     5,     6,     7,    65,   188,   189,   190,
     191,   192,    65,    65,    16,   258,    26,    19,    20,    73,
     238,   239,    71,    71,    67,    26,   216,     4,     5,     6,
       7,   221,    26,   214,    26,    26,    26,   218,    67,    16,
      67,    71,    19,    20,    67,    67,    18,   228,    65,    69,
      26,   220,   233,   234,   235,   236,   237,   238,   227,    66,
     229,    72,    66,    66,   254,    67,   247,   257,    66,    66,
      66,    26,   253,    73,    69,     9,    69,   268,   268,    67,
      58,    67,   220,    72,   265,     4,     5,     6,     7,   258,
      67,    71,   297,    72,   284,   265,   277,    16,   279,   289,
      19,    20,    72,    71,    -1,    72,   281,    -1,    -1,    -1,
      -1,   292,   293,    -1,   295,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   314,   315,    -1,   317,    -1,    -1,
      -1,    -1,   310,    -1,    -1,    -1,   327,   327,   327,   327,
     330,   327,   327,   324,   335,   335,   335,   335,   326,   335,
     335,    -1,    -1,    -1,    10,    11,   337,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      26,    -1,    10,    11,    -1,    13,    14,    15,    16,    17,
      -1,    37,    38,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    60,    -1,    80,    -1,    -1,    -1,    66,    67,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    77,
      10,    11,    80,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    21,    22,    23,    24,    25,    26,    -1,    10,    11,
      -1,    13,    14,    15,    16,    17,    -1,    37,    38,    21,
      22,    23,    24,    25,    26,    74,    75,    76,    -1,    78,
      79,    -1,    81,    -1,    -1,    37,    38,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    60,    -1,
      80,    -1,    -1,    -1,    66,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    -1,    77,    -1,    -1,    80,    -1,
      16,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,     1,    -1,     3,     4,     5,
       6,     7,     8,    49,    50,    51,    52,    53,    54,    55,
      16,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,     0,     1,    -1,     3,     4,     5,
       6,     7,     8,    49,    50,    51,    52,    53,    54,    55,
      16,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,     1,    -1,     3,     4,     5,
       6,     7,     8,    49,    -1,    51,    -1,    53,    54,    55,
      16,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    49,    -1,    51,    -1,    53,    54,    55,
      16,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    49,    -1,    51,    -1,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    69,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      75,    76,    -1,    78,    79,    -1,    81,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    59,    60,    61,
      62,    63,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    73,    74,    75,    76,    -1,    78,    79,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    -1,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,
      -1,    78,    79,    -1,    81,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    71,    72,
      74,    75,    76,    -1,    78,    79,    -1,    81,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,    60,
      61,    62,    63,    -1,    -1,    57,    67,    59,    60,    61,
      62,    63,    -1,    74,    75,    76,    -1,    78,    79,    -1,
      81,    73,    74,    75,    76,    -1,    78,    79,    -1,    81,
      29,    30,    31,    32,    33,    34,    35,    36,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    -1,    57,    -1,    59,    60,
      61,    62,    63,    -1,    65,    74,    75,    76,    -1,    78,
      79,    -1,    81,    74,    75,    76,    -1,    78,    79,    -1,
      81,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    60,    61,    62,    63,    -1,    65,    57,    -1,
      59,    60,    61,    62,    63,    -1,    74,    75,    76,    -1,
      78,    79,    -1,    81,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,
      76,    -1,    78,    79,    -1,    81,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    75,    76,    -1,    78,    79,    -1,    81,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    75,    76,    -1,    78,    79,
      -1,    81,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    -1,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,
      -1,    78,    79,    -1,    81,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    60,    61,    62,    63,
      -1,    -1,    57,    67,    59,    60,    61,    62,    63,    -1,
      74,    75,    76,    -1,    78,    79,    -1,    81,    73,    74,
      75,    76,    -1,    78,    79,    -1,    81,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    57,    -1,    59,    60,    61,    62,
      63,    -1,    74,    75,    76,    -1,    78,    79,    -1,    81,
      73,    74,    75,    76,    -1,    78,    79,    -1,    81,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,
      60,    61,    62,    63,    -1,    -1,    57,    -1,    59,    60,
      61,    62,    63,    73,    74,    75,    76,    -1,    78,    79,
      -1,    81,    73,    74,    75,    76,    -1,    78,    79,    -1,
      81,    29,    30,    31,    32,    33,    34,    35,    36,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    61,    62,    63,    -1,    -1,    74,    75,    76,    -1,
      78,    79,    -1,    81,    74,    75,    76,    -1,    78,    79,
      -1,    81,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    71,    72
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    16,    19,    20,
      26,    27,    28,    37,    38,    49,    51,    53,    54,    55,
      69,    83,    84,    85,    87,    88,    89,    90,    91,    92,
      94,    95,    98,    99,   102,   103,   104,   107,   108,    66,
      66,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    66,    71,    72,    10,    11,    13,    14,
      15,    16,    17,    21,    22,    23,    24,    25,    26,    37,
      38,    60,    66,    77,    80,   100,   101,   106,   111,   102,
      26,    26,    66,    66,    66,    84,     0,     1,     1,    85,
      88,    92,    95,    98,    99,    65,    12,    26,    72,    26,
      26,    67,    86,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,    67,    86,   100,   100,    81,
      81,    81,    81,    81,    37,    38,    66,    72,    26,    26,
     100,     4,     5,     6,     7,    20,   100,   100,   100,    29,
      30,    31,    32,    33,    34,    35,    36,    57,    59,    60,
      61,    62,    63,    74,    75,    76,    78,    79,    81,    26,
     100,   100,    65,    89,   102,    70,    65,    65,    65,    26,
      66,    71,    73,    71,    71,    67,    68,    67,    67,    73,
      26,    26,    26,    26,    26,    67,    86,   100,    67,    67,
      67,    67,    67,    67,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,    18,    71,    67,    67,   100,    65,    26,
      66,    67,    89,    93,   102,   100,    72,    56,    69,    56,
      69,   100,    88,    71,    72,    66,    66,    66,    66,    66,
      67,    73,   100,   100,   100,   100,   100,    58,   100,    69,
      88,    65,   100,    58,    67,    93,    88,    67,    68,    26,
      73,   102,   100,   105,   102,    69,   109,   110,     9,   100,
     100,   100,   100,   100,    86,   100,    86,    72,   100,    50,
      52,    96,    97,    26,    67,    91,    65,   100,    88,    67,
      88,    89,    72,    68,    70,    72,   105,    68,    70,    88,
      92,    73,    67,    67,    67,    67,    67,    67,   100,   100,
      58,    70,    97,    88,    67,    67,    91,    67,    88,   100,
     100,   100,    70,   110,    71,    73,    58,    84,    88,    88,
      67,    88,    73,    73,   100,    84,    88,    72,   100,    73
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    82,    83,    83,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    86,    86,    87,    87,    88,    89,    89,    90,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    92,    92,    92,    93,
      93,    94,    94,    94,    94,    95,    96,    96,    97,    97,
      98,    99,    99,    99,    99,    99,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   101,   101,   101,   101,   101,   101,   101,   102,   102,
     102,   102,   102,   102,   102,   103,   104,   104,   105,   105,
     106,   107,   108,   108,   109,   109,   110,   111
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     2,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     1,     1,     1,
       2,     3,     1,     4,     3,     3,     2,     4,     5,     3,
       6,     9,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     5,     7,     7,     3,
       1,     7,     6,     6,     5,     7,     2,     1,     4,     3,
       5,     9,     8,     8,     7,     8,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     5,     4,
       4,     4,     4,     4,     1,     1,     4,     3,     6,     6,
       6,     6,     6,     6,     1,     1,     3,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     8,     6,     3,     1,
       4,     5,    11,     6,     3,     1,     3,     7
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
#line 58 "src/entriesTools/parser.y"
               { ast_root = (yyvsp[0].nodo); (yyval.nodo) = (yyvsp[0].nodo); }
#line 1771 "build/parser.tab.c"
    break;

  case 3: /* s: s error ';'  */
#line 59 "src/entriesTools/parser.y"
                  { yyerrok; }
#line 1777 "build/parser.tab.c"
    break;

  case 4: /* lSentencia: lSentencia sentencia ';'  */
#line 63 "src/entriesTools/parser.y"
                                     { agregarHijo((yyvsp[-2].nodo), (yyvsp[-1].nodo)); (yyval.nodo) = (yyvsp[-2].nodo);}
#line 1783 "build/parser.tab.c"
    break;

  case 5: /* lSentencia: sentencia ';'  */
#line 64 "src/entriesTools/parser.y"
                    {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[-1].nodo));
        (yyval.nodo) =  b;
    }
#line 1793 "build/parser.tab.c"
    break;

  case 6: /* lSentencia: lSentencia bloque  */
#line 69 "src/entriesTools/parser.y"
                        { agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1799 "build/parser.tab.c"
    break;

  case 7: /* lSentencia: bloque  */
#line 70 "src/entriesTools/parser.y"
             {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 1809 "build/parser.tab.c"
    break;

  case 8: /* lSentencia: lSentencia sentencia_if  */
#line 75 "src/entriesTools/parser.y"
                              { agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1815 "build/parser.tab.c"
    break;

  case 9: /* lSentencia: sentencia_if  */
#line 76 "src/entriesTools/parser.y"
                   {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 1825 "build/parser.tab.c"
    break;

  case 10: /* lSentencia: lSentencia sentencia_switch  */
#line 81 "src/entriesTools/parser.y"
                                  { agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1831 "build/parser.tab.c"
    break;

  case 11: /* lSentencia: sentencia_switch  */
#line 82 "src/entriesTools/parser.y"
                       {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 1841 "build/parser.tab.c"
    break;

  case 12: /* lSentencia: lSentencia sentencia_while  */
#line 87 "src/entriesTools/parser.y"
                                 { agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1847 "build/parser.tab.c"
    break;

  case 13: /* lSentencia: sentencia_while  */
#line 88 "src/entriesTools/parser.y"
                      {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 1857 "build/parser.tab.c"
    break;

  case 14: /* lSentencia: lSentencia sentencia_for  */
#line 93 "src/entriesTools/parser.y"
                               { agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1863 "build/parser.tab.c"
    break;

  case 15: /* lSentencia: sentencia_for  */
#line 94 "src/entriesTools/parser.y"
                    {
        AbstractExpresion* b = nuevoInstruccionesExpresion();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 1873 "build/parser.tab.c"
    break;

  case 16: /* lSentencia: lSentencia error ';'  */
#line 99 "src/entriesTools/parser.y"
                           { yyerrok; (yyval.nodo) = (yyvsp[-2].nodo); }
#line 1879 "build/parser.tab.c"
    break;

  case 17: /* sentencia: imprimir  */
#line 102 "src/entriesTools/parser.y"
                    {(yyval.nodo) = (yyvsp[0].nodo); }
#line 1885 "build/parser.tab.c"
    break;

  case 18: /* sentencia: bloque  */
#line 103 "src/entriesTools/parser.y"
             {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1891 "build/parser.tab.c"
    break;

  case 19: /* sentencia: declaracion_var  */
#line 104 "src/entriesTools/parser.y"
                      {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1897 "build/parser.tab.c"
    break;

  case 20: /* sentencia: declaracion_const  */
#line 105 "src/entriesTools/parser.y"
                        {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1903 "build/parser.tab.c"
    break;

  case 21: /* sentencia: declaracion_array  */
#line 106 "src/entriesTools/parser.y"
                        {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1909 "build/parser.tab.c"
    break;

  case 22: /* sentencia: declaracion_matrix  */
#line 107 "src/entriesTools/parser.y"
                         {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1915 "build/parser.tab.c"
    break;

  case 23: /* sentencia: asignacion  */
#line 108 "src/entriesTools/parser.y"
                 {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1921 "build/parser.tab.c"
    break;

  case 24: /* sentencia: sentencia_funcion  */
#line 109 "src/entriesTools/parser.y"
                        { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1927 "build/parser.tab.c"
    break;

  case 25: /* sentencia: TOKEN_IDENTIFIER '(' lista_Expr ')'  */
#line 110 "src/entriesTools/parser.y"
                                          { (yyval.nodo) = nuevoLlamadaExpresion((yyvsp[-3].string), (yyvsp[-1].nodo)); }
#line 1933 "build/parser.tab.c"
    break;

  case 26: /* sentencia: TOKEN_IDENTIFIER '(' ')'  */
#line 111 "src/entriesTools/parser.y"
                               { (yyval.nodo) = nuevoLlamadaExpresion((yyvsp[-2].string), NULL); }
#line 1939 "build/parser.tab.c"
    break;

  case 27: /* sentencia: TOKEN_BREAK  */
#line 112 "src/entriesTools/parser.y"
                  { (yyval.nodo) = nuevoBreakExpresion((yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 1945 "build/parser.tab.c"
    break;

  case 28: /* sentencia: TOKEN_CONTINUE  */
#line 113 "src/entriesTools/parser.y"
                     { (yyval.nodo) = nuevoContinueExpresion((yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 1951 "build/parser.tab.c"
    break;

  case 29: /* sentencia: TOKEN_RETURN  */
#line 114 "src/entriesTools/parser.y"
                   { (yyval.nodo) = NULL; }
#line 1957 "build/parser.tab.c"
    break;

  case 30: /* sentencia: TOKEN_RETURN expr  */
#line 115 "src/entriesTools/parser.y"
                        { (yyval.nodo) = nuevoReturnExpresion((yyvsp[0].nodo)); }
#line 1963 "build/parser.tab.c"
    break;

  case 31: /* lista_Expr: lista_Expr ',' expr  */
#line 118 "src/entriesTools/parser.y"
                                 { agregarHijo((yyvsp[-2].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-2].nodo); }
#line 1969 "build/parser.tab.c"
    break;

  case 32: /* lista_Expr: expr  */
#line 119 "src/entriesTools/parser.y"
           { 
                AbstractExpresion* b = nuevoListaExpresiones();
                agregarHijo(b, (yyvsp[0].nodo));
                (yyval.nodo) =  b;
            }
#line 1979 "build/parser.tab.c"
    break;

  case 33: /* imprimir: TOKEN_PRINT '(' lista_Expr ')'  */
#line 126 "src/entriesTools/parser.y"
                                         { (yyval.nodo) =  nuevoPrintExpresion((yyvsp[-1].nodo)); }
#line 1985 "build/parser.tab.c"
    break;

  case 34: /* imprimir: TOKEN_PRINT '(' ')'  */
#line 127 "src/entriesTools/parser.y"
                          { 
        yyerror("System.out.println() sin argumentos no está permitido. Debe proporcionar al menos un argumento.");
        (yyval.nodo) = NULL;
    }
#line 1994 "build/parser.tab.c"
    break;

  case 35: /* bloque: '{' lSentencia '}'  */
#line 133 "src/entriesTools/parser.y"
                           { (yyval.nodo) =  (yyvsp[-1].nodo); }
#line 2000 "build/parser.tab.c"
    break;

  case 36: /* declaracion_var: tipoPrimitivo TOKEN_IDENTIFIER  */
#line 136 "src/entriesTools/parser.y"
                                                { (yyval.nodo) = nuevoDeclaracionVariables((yyvsp[-1].tipoDato), (yyvsp[0].string), NULL, (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2006 "build/parser.tab.c"
    break;

  case 37: /* declaracion_var: tipoPrimitivo TOKEN_IDENTIFIER '=' expr  */
#line 137 "src/entriesTools/parser.y"
                                              { (yyval.nodo) = nuevoDeclaracionVariables((yyvsp[-3].tipoDato), (yyvsp[-2].string), (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2012 "build/parser.tab.c"
    break;

  case 38: /* declaracion_const: TOKEN_FINAL tipoPrimitivo TOKEN_IDENTIFIER '=' expr  */
#line 140 "src/entriesTools/parser.y"
                                                                       { (yyval.nodo) = nuevoDeclaracionConstante((yyvsp[-3].tipoDato), (yyvsp[-2].string), (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2018 "build/parser.tab.c"
    break;

  case 39: /* asignacion: TOKEN_IDENTIFIER '=' expr  */
#line 143 "src/entriesTools/parser.y"
                                      { (yyval.nodo) = nuevoAsignacionExpresion((yyvsp[-2].string), (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2024 "build/parser.tab.c"
    break;

  case 40: /* asignacion: TOKEN_IDENTIFIER '[' expr ']' '=' expr  */
#line 144 "src/entriesTools/parser.y"
                                             { (yyval.nodo) = nuevoAsignacionArrayExpresion((yyvsp[-5].string), (yyvsp[-3].nodo), (yyvsp[0].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column); }
#line 2030 "build/parser.tab.c"
    break;

  case 41: /* asignacion: TOKEN_IDENTIFIER '[' expr ']' '[' expr ']' '=' expr  */
#line 145 "src/entriesTools/parser.y"
                                                          { (yyval.nodo) = nuevoAsignacionMatrixExpresion((yyvsp[-8].string), (yyvsp[-6].nodo), (yyvsp[-3].nodo), (yyvsp[0].nodo), (yylsp[-8]).first_line, (yylsp[-8]).first_column); }
#line 2036 "build/parser.tab.c"
    break;

  case 42: /* asignacion: TOKEN_IDENTIFIER TOKEN_PLUS_ASSIGN expr  */
#line 146 "src/entriesTools/parser.y"
                                              { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_SUMA, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2042 "build/parser.tab.c"
    break;

  case 43: /* asignacion: TOKEN_IDENTIFIER TOKEN_MINUS_ASSIGN expr  */
#line 147 "src/entriesTools/parser.y"
                                               { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_RESTA, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2048 "build/parser.tab.c"
    break;

  case 44: /* asignacion: TOKEN_IDENTIFIER TOKEN_MULT_ASSIGN expr  */
#line 148 "src/entriesTools/parser.y"
                                              { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_MULT, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2054 "build/parser.tab.c"
    break;

  case 45: /* asignacion: TOKEN_IDENTIFIER TOKEN_DIV_ASSIGN expr  */
#line 149 "src/entriesTools/parser.y"
                                             { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_DIV, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2060 "build/parser.tab.c"
    break;

  case 46: /* asignacion: TOKEN_IDENTIFIER TOKEN_MOD_ASSIGN expr  */
#line 150 "src/entriesTools/parser.y"
                                             { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_MOD, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2066 "build/parser.tab.c"
    break;

  case 47: /* asignacion: TOKEN_IDENTIFIER TOKEN_AND_ASSIGN expr  */
#line 151 "src/entriesTools/parser.y"
                                             { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_AND, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2072 "build/parser.tab.c"
    break;

  case 48: /* asignacion: TOKEN_IDENTIFIER TOKEN_OR_ASSIGN expr  */
#line 152 "src/entriesTools/parser.y"
                                            { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_OR, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2078 "build/parser.tab.c"
    break;

  case 49: /* asignacion: TOKEN_IDENTIFIER TOKEN_XOR_ASSIGN expr  */
#line 153 "src/entriesTools/parser.y"
                                             { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_XOR, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2084 "build/parser.tab.c"
    break;

  case 50: /* asignacion: TOKEN_IDENTIFIER TOKEN_LSHIFT_ASSIGN expr  */
#line 154 "src/entriesTools/parser.y"
                                                { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_LSHIFT, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2090 "build/parser.tab.c"
    break;

  case 51: /* asignacion: TOKEN_IDENTIFIER TOKEN_RSHIFT_ASSIGN expr  */
#line 155 "src/entriesTools/parser.y"
                                                { (yyval.nodo) = nuevoAsignacionCompuesta((yyvsp[-2].string), ASIG_RSHIFT, (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2096 "build/parser.tab.c"
    break;

  case 52: /* asignacion: TOKEN_INCREMENT TOKEN_IDENTIFIER  */
#line 156 "src/entriesTools/parser.y"
                                       { (yyval.nodo) = nuevoPreIncrementoExpresion((yyvsp[0].string), (yylsp[-1]).first_line, (yylsp[-1]).first_column); }
#line 2102 "build/parser.tab.c"
    break;

  case 53: /* asignacion: TOKEN_IDENTIFIER TOKEN_INCREMENT  */
#line 157 "src/entriesTools/parser.y"
                                       { (yyval.nodo) = nuevoPostIncrementoExpresion((yyvsp[-1].string), (yylsp[-1]).first_line, (yylsp[-1]).first_column); }
#line 2108 "build/parser.tab.c"
    break;

  case 54: /* asignacion: TOKEN_DECREMENT TOKEN_IDENTIFIER  */
#line 158 "src/entriesTools/parser.y"
                                       { (yyval.nodo) = nuevoPreDecrementoExpresion((yyvsp[0].string), (yylsp[-1]).first_line, (yylsp[-1]).first_column); }
#line 2114 "build/parser.tab.c"
    break;

  case 55: /* asignacion: TOKEN_IDENTIFIER TOKEN_DECREMENT  */
#line 159 "src/entriesTools/parser.y"
                                       { (yyval.nodo) = nuevoPostDecrementoExpresion((yyvsp[-1].string), (yylsp[-1]).first_line, (yylsp[-1]).first_column); }
#line 2120 "build/parser.tab.c"
    break;

  case 56: /* sentencia_if: TOKEN_IF '(' expr ')' bloque  */
#line 162 "src/entriesTools/parser.y"
                                           { (yyval.nodo) = nuevoIfExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2126 "build/parser.tab.c"
    break;

  case 57: /* sentencia_if: TOKEN_IF '(' expr ')' bloque TOKEN_ELSE bloque  */
#line 163 "src/entriesTools/parser.y"
                                                     { (yyval.nodo) = nuevoIfElseExpresion((yyvsp[-4].nodo), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2132 "build/parser.tab.c"
    break;

  case 58: /* sentencia_if: TOKEN_IF '(' expr ')' bloque TOKEN_ELSE sentencia_if  */
#line 164 "src/entriesTools/parser.y"
                                                           { (yyval.nodo) = nuevoElseIfExpresion((yyvsp[-4].nodo), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2138 "build/parser.tab.c"
    break;

  case 59: /* lista_parametros: lista_parametros ',' declaracion_var  */
#line 167 "src/entriesTools/parser.y"
                                                       { agregarHijo((yyvsp[-2].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-2].nodo); }
#line 2144 "build/parser.tab.c"
    break;

  case 60: /* lista_parametros: declaracion_var  */
#line 168 "src/entriesTools/parser.y"
                      { AbstractExpresion* b = nuevoListaParametros();
                agregarHijo(b, (yyvsp[0].nodo));
                (yyval.nodo) =  b; }
#line 2152 "build/parser.tab.c"
    break;

  case 61: /* sentencia_funcion: tipoPrimitivo TOKEN_FUNC TOKEN_IDENTIFIER '(' lista_parametros ')' bloque  */
#line 173 "src/entriesTools/parser.y"
                                                                                             {  (yyval.nodo) = nuevoFuncionExpresion((yyvsp[-6].tipoDato), (yyvsp[-4].string), (yyvsp[-2].nodo), (yyvsp[0].nodo));}
#line 2158 "build/parser.tab.c"
    break;

  case 62: /* sentencia_funcion: tipoPrimitivo TOKEN_FUNC TOKEN_IDENTIFIER '(' ')' bloque  */
#line 174 "src/entriesTools/parser.y"
                                                               {  (yyval.nodo) = nuevoFuncionExpresion((yyvsp[-5].tipoDato), (yyvsp[-3].string), NULL, (yyvsp[0].nodo));}
#line 2164 "build/parser.tab.c"
    break;

  case 63: /* sentencia_funcion: tipoPrimitivo TOKEN_IDENTIFIER '(' lista_parametros ')' bloque  */
#line 175 "src/entriesTools/parser.y"
                                                                     {  (yyval.nodo) = nuevoFuncionExpresion((yyvsp[-5].tipoDato), (yyvsp[-4].string), (yyvsp[-2].nodo), (yyvsp[0].nodo));}
#line 2170 "build/parser.tab.c"
    break;

  case 64: /* sentencia_funcion: tipoPrimitivo TOKEN_IDENTIFIER '(' ')' bloque  */
#line 176 "src/entriesTools/parser.y"
                                                    {  (yyval.nodo) = nuevoFuncionExpresion((yyvsp[-4].tipoDato), (yyvsp[-3].string), NULL, (yyvsp[0].nodo));}
#line 2176 "build/parser.tab.c"
    break;

  case 65: /* sentencia_switch: TOKEN_SWITCH '(' expr ')' '{' lista_casos '}'  */
#line 179 "src/entriesTools/parser.y"
                                                                { (yyval.nodo) = nuevoSwitchExpresion((yyvsp[-4].nodo), (yyvsp[-1].nodo)); }
#line 2182 "build/parser.tab.c"
    break;

  case 66: /* lista_casos: lista_casos caso  */
#line 182 "src/entriesTools/parser.y"
                              { agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2188 "build/parser.tab.c"
    break;

  case 67: /* lista_casos: caso  */
#line 183 "src/entriesTools/parser.y"
           { 
        AbstractExpresion* b = nuevoListaCasos();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 2198 "build/parser.tab.c"
    break;

  case 68: /* caso: TOKEN_CASE expr ':' lSentencia  */
#line 190 "src/entriesTools/parser.y"
                                     { (yyval.nodo) = nuevoCaseExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2204 "build/parser.tab.c"
    break;

  case 69: /* caso: TOKEN_DEFAULT ':' lSentencia  */
#line 191 "src/entriesTools/parser.y"
                                   { (yyval.nodo) = nuevoDefaultExpresion((yyvsp[0].nodo)); }
#line 2210 "build/parser.tab.c"
    break;

  case 70: /* sentencia_while: TOKEN_WHILE '(' expr ')' bloque  */
#line 194 "src/entriesTools/parser.y"
                                                 { (yyval.nodo) = nuevoWhileExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2216 "build/parser.tab.c"
    break;

  case 71: /* sentencia_for: TOKEN_FOR '(' declaracion_var ';' expr ';' asignacion ')' bloque  */
#line 197 "src/entriesTools/parser.y"
                                                                                { (yyval.nodo) = nuevoForExpresion((yyvsp[-6].nodo), (yyvsp[-4].nodo), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2222 "build/parser.tab.c"
    break;

  case 72: /* sentencia_for: TOKEN_FOR '(' declaracion_var ';' expr ';' ')' bloque  */
#line 198 "src/entriesTools/parser.y"
                                                            { (yyval.nodo) = nuevoForExpresion((yyvsp[-5].nodo), (yyvsp[-3].nodo), NULL, (yyvsp[0].nodo)); }
#line 2228 "build/parser.tab.c"
    break;

  case 73: /* sentencia_for: TOKEN_FOR '(' ';' expr ';' asignacion ')' bloque  */
#line 199 "src/entriesTools/parser.y"
                                                       { (yyval.nodo) = nuevoForExpresion(NULL, (yyvsp[-4].nodo), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2234 "build/parser.tab.c"
    break;

  case 74: /* sentencia_for: TOKEN_FOR '(' ';' expr ';' ')' bloque  */
#line 200 "src/entriesTools/parser.y"
                                            { (yyval.nodo) = nuevoForExpresion(NULL, (yyvsp[-3].nodo), NULL, (yyvsp[0].nodo)); }
#line 2240 "build/parser.tab.c"
    break;

  case 75: /* sentencia_for: TOKEN_FOR '(' tipoPrimitivo TOKEN_IDENTIFIER ':' expr ')' bloque  */
#line 201 "src/entriesTools/parser.y"
                                                                       { (yyval.nodo) = nuevoForEachExpresion((yyvsp[-5].tipoDato), (yyvsp[-4].string), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2246 "build/parser.tab.c"
    break;

  case 76: /* expr: expr '+' expr  */
#line 220 "src/entriesTools/parser.y"
                      { (yyval.nodo) =  nuevoSumaExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo));  }
#line 2252 "build/parser.tab.c"
    break;

  case 77: /* expr: expr '-' expr  */
#line 221 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoRestaExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2258 "build/parser.tab.c"
    break;

  case 78: /* expr: expr '*' expr  */
#line 222 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoMultiplicacionExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2264 "build/parser.tab.c"
    break;

  case 79: /* expr: expr '/' expr  */
#line 223 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoDivisionExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2270 "build/parser.tab.c"
    break;

  case 80: /* expr: expr '%' expr  */
#line 224 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoModuloExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2276 "build/parser.tab.c"
    break;

  case 81: /* expr: expr '&' expr  */
#line 225 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoBitwiseAndExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2282 "build/parser.tab.c"
    break;

  case 82: /* expr: expr '|' expr  */
#line 226 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoBitwiseOrExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2288 "build/parser.tab.c"
    break;

  case 83: /* expr: expr '^' expr  */
#line 227 "src/entriesTools/parser.y"
                    { (yyval.nodo) =  nuevoBitwiseXorExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2294 "build/parser.tab.c"
    break;

  case 84: /* expr: expr TOKEN_LEFT_SHIFT expr  */
#line 228 "src/entriesTools/parser.y"
                                 { (yyval.nodo) =  nuevoBitwiseLeftShiftExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2300 "build/parser.tab.c"
    break;

  case 85: /* expr: expr TOKEN_RIGHT_SHIFT expr  */
#line 229 "src/entriesTools/parser.y"
                                  { (yyval.nodo) =  nuevoBitwiseRightShiftExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2306 "build/parser.tab.c"
    break;

  case 86: /* expr: '(' expr ')'  */
#line 230 "src/entriesTools/parser.y"
                   { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2312 "build/parser.tab.c"
    break;

  case 87: /* expr: '-' expr  */
#line 231 "src/entriesTools/parser.y"
                          { (yyval.nodo) =  nuevoUnarioExpresion((yyvsp[0].nodo));  }
#line 2318 "build/parser.tab.c"
    break;

  case 88: /* expr: '~' expr  */
#line 232 "src/entriesTools/parser.y"
                          { (yyval.nodo) =  nuevoBitwiseNotExpresion((yyvsp[0].nodo));  }
#line 2324 "build/parser.tab.c"
    break;

  case 89: /* expr: expr TOKEN_EQ expr  */
#line 233 "src/entriesTools/parser.y"
                         { (yyval.nodo) = nuevoIgualdadExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2330 "build/parser.tab.c"
    break;

  case 90: /* expr: expr TOKEN_NE expr  */
#line 234 "src/entriesTools/parser.y"
                         { (yyval.nodo) = nuevoDesigualdadExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2336 "build/parser.tab.c"
    break;

  case 91: /* expr: expr '>' expr  */
#line 235 "src/entriesTools/parser.y"
                    { (yyval.nodo) = nuevoMayorQueExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2342 "build/parser.tab.c"
    break;

  case 92: /* expr: expr '<' expr  */
#line 236 "src/entriesTools/parser.y"
                    { (yyval.nodo) = nuevoMenorQueExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2348 "build/parser.tab.c"
    break;

  case 93: /* expr: expr TOKEN_GE expr  */
#line 237 "src/entriesTools/parser.y"
                         { (yyval.nodo) = nuevoMayorIgualExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2354 "build/parser.tab.c"
    break;

  case 94: /* expr: expr TOKEN_LE expr  */
#line 238 "src/entriesTools/parser.y"
                         { (yyval.nodo) = nuevoMenorIgualExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2360 "build/parser.tab.c"
    break;

  case 95: /* expr: expr TOKEN_AND expr  */
#line 239 "src/entriesTools/parser.y"
                          { (yyval.nodo) = nuevoLogicAndExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2366 "build/parser.tab.c"
    break;

  case 96: /* expr: expr TOKEN_OR expr  */
#line 240 "src/entriesTools/parser.y"
                         { (yyval.nodo) = nuevoLogicOrExpresion((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2372 "build/parser.tab.c"
    break;

  case 97: /* expr: '!' expr  */
#line 241 "src/entriesTools/parser.y"
                         { (yyval.nodo) = nuevoLogicNotExpresion((yyvsp[0].nodo)); }
#line 2378 "build/parser.tab.c"
    break;

  case 98: /* expr: expr '?' expr ':' expr  */
#line 242 "src/entriesTools/parser.y"
                             { (yyval.nodo) = nuevoOperadorTernarioExpresion((yyvsp[-4].nodo), (yyvsp[-2].nodo), (yyvsp[0].nodo), (yylsp[-4]).first_line, (yylsp[-4]).first_column); }
#line 2384 "build/parser.tab.c"
    break;

  case 99: /* expr: '(' TOKEN_DVOID ')' expr  */
#line 243 "src/entriesTools/parser.y"
                               { (yyval.nodo) = nuevoCastingExpresion((yyvsp[0].nodo), VOID); }
#line 2390 "build/parser.tab.c"
    break;

  case 100: /* expr: '(' TOKEN_DINT ')' expr  */
#line 244 "src/entriesTools/parser.y"
                              { (yyval.nodo) = nuevoCastingExpresion((yyvsp[0].nodo), INT); }
#line 2396 "build/parser.tab.c"
    break;

  case 101: /* expr: '(' TOKEN_DFLOAT ')' expr  */
#line 245 "src/entriesTools/parser.y"
                                { (yyval.nodo) = nuevoCastingExpresion((yyvsp[0].nodo), FLOAT); }
#line 2402 "build/parser.tab.c"
    break;

  case 102: /* expr: '(' TOKEN_DDOUBLE ')' expr  */
#line 246 "src/entriesTools/parser.y"
                                 { (yyval.nodo) = nuevoCastingExpresion((yyvsp[0].nodo), DOUBLE); }
#line 2408 "build/parser.tab.c"
    break;

  case 103: /* expr: '(' TOKEN_DCHAR ')' expr  */
#line 247 "src/entriesTools/parser.y"
                               { (yyval.nodo) = nuevoCastingExpresion((yyvsp[0].nodo), CHAR); }
#line 2414 "build/parser.tab.c"
    break;

  case 104: /* expr: primitivo  */
#line 248 "src/entriesTools/parser.y"
                { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2420 "build/parser.tab.c"
    break;

  case 105: /* expr: TOKEN_IDENTIFIER  */
#line 249 "src/entriesTools/parser.y"
                       { (yyval.nodo) = nuevoIdentificadorExpresion((yyvsp[0].string), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2426 "build/parser.tab.c"
    break;

  case 106: /* expr: TOKEN_IDENTIFIER '(' lista_Expr ')'  */
#line 250 "src/entriesTools/parser.y"
                                          { (yyval.nodo) = nuevoLlamadaExpresion((yyvsp[-3].string), (yyvsp[-1].nodo)); }
#line 2432 "build/parser.tab.c"
    break;

  case 107: /* expr: TOKEN_IDENTIFIER '(' ')'  */
#line 251 "src/entriesTools/parser.y"
                               { (yyval.nodo) = nuevoLlamadaExpresion((yyvsp[-2].string), NULL); }
#line 2438 "build/parser.tab.c"
    break;

  case 108: /* expr: TOKEN_INTEGER '.' TOKEN_IDENTIFIER '(' expr ')'  */
#line 252 "src/entriesTools/parser.y"
                                                      { 
        if (strcmp((yyvsp[-3].string), "parseInt") == 0) {
            (yyval.nodo) = nuevoIntegerParseIntExpresion((yyvsp[-1].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        } else {
            yyerror("Método no reconocido en clase Integer");
            (yyval.nodo) = NULL;
        }
    }
#line 2451 "build/parser.tab.c"
    break;

  case 109: /* expr: TOKEN_DOUBLE_CLASS '.' TOKEN_IDENTIFIER '(' expr ')'  */
#line 260 "src/entriesTools/parser.y"
                                                           { 
        if (strcmp((yyvsp[-3].string), "parseDouble") == 0) {
            (yyval.nodo) = nuevoDoubleParseDoubleExpresion((yyvsp[-1].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        } else {
            yyerror("Método no reconocido en clase Double");
            (yyval.nodo) = NULL;
        }
    }
#line 2464 "build/parser.tab.c"
    break;

  case 110: /* expr: TOKEN_FLOAT_CLASS '.' TOKEN_IDENTIFIER '(' expr ')'  */
#line 268 "src/entriesTools/parser.y"
                                                          { 
        if (strcmp((yyvsp[-3].string), "parseFloat") == 0) {
            (yyval.nodo) = nuevoFloatParseFloatExpresion((yyvsp[-1].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        } else {
            yyerror("Método no reconocido en clase Float");
            (yyval.nodo) = NULL;
        }
    }
#line 2477 "build/parser.tab.c"
    break;

  case 111: /* expr: TOKEN_STRING_CLASS '.' TOKEN_IDENTIFIER '(' expr ')'  */
#line 276 "src/entriesTools/parser.y"
                                                           { 
        if (strcmp((yyvsp[-3].string), "valueOf") == 0) {
            (yyval.nodo) = nuevoStringValueOfExpresion((yyvsp[-1].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        } else {
            yyerror("Método no reconocido en clase String");
            (yyval.nodo) = NULL;
        }
    }
#line 2490 "build/parser.tab.c"
    break;

  case 112: /* expr: TOKEN_STRING_CLASS '.' TOKEN_IDENTIFIER '(' lista_Expr ')'  */
#line 284 "src/entriesTools/parser.y"
                                                                 { 
        if (strcmp((yyvsp[-3].string), "join") == 0) {
            (yyval.nodo) = nuevoStringJoinExpresion((yyvsp[-1].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        } else {
            yyerror("Método no reconocido en clase String");
            (yyval.nodo) = NULL;
        }
    }
#line 2503 "build/parser.tab.c"
    break;

  case 113: /* expr: TOKEN_ARRAYS '.' TOKEN_IDENTIFIER '(' lista_Expr ')'  */
#line 292 "src/entriesTools/parser.y"
                                                           { 
        if (strcmp((yyvsp[-3].string), "indexOf") == 0) {
            (yyval.nodo) = nuevoArraysIndexOfExpresion((yyvsp[-1].nodo), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        } else {
            yyerror("Método no reconocido en clase Arrays");
            (yyval.nodo) = NULL;
        }
    }
#line 2516 "build/parser.tab.c"
    break;

  case 114: /* expr: acceso_array  */
#line 300 "src/entriesTools/parser.y"
                   { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2522 "build/parser.tab.c"
    break;

  case 115: /* expr: acceso_matrix  */
#line 301 "src/entriesTools/parser.y"
                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2528 "build/parser.tab.c"
    break;

  case 116: /* expr: expr '.' TOKEN_LENGTH  */
#line 302 "src/entriesTools/parser.y"
                            { (yyval.nodo) = nuevoArrayLengthExpresion((yyvsp[-2].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column); }
#line 2534 "build/parser.tab.c"
    break;

  case 117: /* expr: TOKEN_INCREMENT TOKEN_IDENTIFIER  */
#line 303 "src/entriesTools/parser.y"
                                       { (yyval.nodo) = nuevoPreIncrementoExpresion((yyvsp[0].string), (yylsp[-1]).first_line, (yylsp[-1]).first_column); }
#line 2540 "build/parser.tab.c"
    break;

  case 118: /* expr: TOKEN_IDENTIFIER TOKEN_INCREMENT  */
#line 304 "src/entriesTools/parser.y"
                                       { (yyval.nodo) = nuevoPostIncrementoExpresion((yyvsp[-1].string), (yylsp[-1]).first_line, (yylsp[-1]).first_column); }
#line 2546 "build/parser.tab.c"
    break;

  case 119: /* expr: TOKEN_DECREMENT TOKEN_IDENTIFIER  */
#line 305 "src/entriesTools/parser.y"
                                       { (yyval.nodo) = nuevoPreDecrementoExpresion((yyvsp[0].string), (yylsp[-1]).first_line, (yylsp[-1]).first_column); }
#line 2552 "build/parser.tab.c"
    break;

  case 120: /* expr: TOKEN_IDENTIFIER TOKEN_DECREMENT  */
#line 306 "src/entriesTools/parser.y"
                                       { (yyval.nodo) = nuevoPostDecrementoExpresion((yyvsp[-1].string), (yylsp[-1]).first_line, (yylsp[-1]).first_column); }
#line 2558 "build/parser.tab.c"
    break;

  case 121: /* primitivo: TOKEN_UNSIGNED_INTEGER  */
#line 310 "src/entriesTools/parser.y"
                                  { (yyval.nodo) =  nuevoPrimitivoExpresion((yyvsp[0].string), INT); }
#line 2564 "build/parser.tab.c"
    break;

  case 122: /* primitivo: TOKEN_STRING  */
#line 311 "src/entriesTools/parser.y"
                   { (yyval.nodo) =  nuevoPrimitivoExpresion((yyvsp[0].string), STRING); }
#line 2570 "build/parser.tab.c"
    break;

  case 123: /* primitivo: TOKEN_REAL  */
#line 312 "src/entriesTools/parser.y"
                 { (yyval.nodo) =  nuevoPrimitivoExpresion((yyvsp[0].string), FLOAT); }
#line 2576 "build/parser.tab.c"
    break;

  case 124: /* primitivo: TOKEN_DOUBLE  */
#line 313 "src/entriesTools/parser.y"
                   { (yyval.nodo) =  nuevoPrimitivoExpresion((yyvsp[0].string), DOUBLE); }
#line 2582 "build/parser.tab.c"
    break;

  case 125: /* primitivo: TOKEN_CHAR  */
#line 314 "src/entriesTools/parser.y"
                 { (yyval.nodo) =  nuevoPrimitivoExpresion((yyvsp[0].string), CHAR); }
#line 2588 "build/parser.tab.c"
    break;

  case 126: /* primitivo: TOKEN_TRUE  */
#line 315 "src/entriesTools/parser.y"
                 { (yyval.nodo) =  nuevoPrimitivoExpresion("T", BOOLEAN); }
#line 2594 "build/parser.tab.c"
    break;

  case 127: /* primitivo: TOKEN_FALSE  */
#line 316 "src/entriesTools/parser.y"
                  { (yyval.nodo) =  nuevoPrimitivoExpresion("F", BOOLEAN); }
#line 2600 "build/parser.tab.c"
    break;

  case 128: /* tipoPrimitivo: TOKEN_DVOID  */
#line 319 "src/entriesTools/parser.y"
                           { (yyval.tipoDato) = VOID; }
#line 2606 "build/parser.tab.c"
    break;

  case 129: /* tipoPrimitivo: TOKEN_DINT  */
#line 320 "src/entriesTools/parser.y"
                 { (yyval.tipoDato) = INT; }
#line 2612 "build/parser.tab.c"
    break;

  case 130: /* tipoPrimitivo: TOKEN_DFLOAT  */
#line 321 "src/entriesTools/parser.y"
                   { (yyval.tipoDato) = FLOAT; }
#line 2618 "build/parser.tab.c"
    break;

  case 131: /* tipoPrimitivo: TOKEN_DDOUBLE  */
#line 322 "src/entriesTools/parser.y"
                    { (yyval.tipoDato) = DOUBLE; }
#line 2624 "build/parser.tab.c"
    break;

  case 132: /* tipoPrimitivo: TOKEN_STRING_CLASS  */
#line 323 "src/entriesTools/parser.y"
                         { (yyval.tipoDato) = STRING; }
#line 2630 "build/parser.tab.c"
    break;

  case 133: /* tipoPrimitivo: TOKEN_DBOOLEAN  */
#line 324 "src/entriesTools/parser.y"
                     { (yyval.tipoDato) = BOOLEAN; }
#line 2636 "build/parser.tab.c"
    break;

  case 134: /* tipoPrimitivo: TOKEN_DCHAR  */
#line 325 "src/entriesTools/parser.y"
                  { (yyval.tipoDato) = CHAR; }
#line 2642 "build/parser.tab.c"
    break;

  case 135: /* tipoArray: tipoPrimitivo '[' ']'  */
#line 329 "src/entriesTools/parser.y"
                                 { (yyval.tipoDato) = (yyvsp[-2].tipoDato); }
#line 2648 "build/parser.tab.c"
    break;

  case 136: /* declaracion_array: tipoArray TOKEN_IDENTIFIER '=' TOKEN_NEW tipoPrimitivo '[' expr ']'  */
#line 332 "src/entriesTools/parser.y"
                                                                                       { (yyval.nodo) = nuevoDeclaracionArrayNew((yyvsp[-7].tipoDato), (yyvsp[-6].string), (yyvsp[-3].tipoDato), (yyvsp[-1].nodo), (yylsp[-6]).first_line, (yylsp[-6]).first_column); }
#line 2654 "build/parser.tab.c"
    break;

  case 137: /* declaracion_array: tipoArray TOKEN_IDENTIFIER '=' '{' lista_elementos '}'  */
#line 333 "src/entriesTools/parser.y"
                                                             { (yyval.nodo) = nuevoDeclaracionArrayInit((yyvsp[-5].tipoDato), (yyvsp[-4].string), (yyvsp[-1].nodo), (yylsp[-4]).first_line, (yylsp[-4]).first_column); }
#line 2660 "build/parser.tab.c"
    break;

  case 138: /* lista_elementos: lista_elementos ',' expr  */
#line 336 "src/entriesTools/parser.y"
                                          { agregarHijo((yyvsp[-2].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-2].nodo); }
#line 2666 "build/parser.tab.c"
    break;

  case 139: /* lista_elementos: expr  */
#line 337 "src/entriesTools/parser.y"
           { 
        AbstractExpresion* b = nuevoListaElementos();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 2676 "build/parser.tab.c"
    break;

  case 140: /* acceso_array: TOKEN_IDENTIFIER '[' expr ']'  */
#line 344 "src/entriesTools/parser.y"
                                            { (yyval.nodo) = nuevoAccesoArrayExpresion((yyvsp[-3].string), (yyvsp[-1].nodo), (yylsp[-3]).first_line, (yylsp[-3]).first_column); }
#line 2682 "build/parser.tab.c"
    break;

  case 141: /* tipoMatrix: tipoPrimitivo '[' ']' '[' ']'  */
#line 348 "src/entriesTools/parser.y"
                                          { (yyval.tipoDato) = (yyvsp[-4].tipoDato); }
#line 2688 "build/parser.tab.c"
    break;

  case 142: /* declaracion_matrix: tipoMatrix TOKEN_IDENTIFIER '=' TOKEN_NEW tipoPrimitivo '[' expr ']' '[' expr ']'  */
#line 351 "src/entriesTools/parser.y"
                                                                                                      { (yyval.nodo) = nuevoDeclaracionMatrixNew((yyvsp[-10].tipoDato), (yyvsp[-9].string), (yyvsp[-6].tipoDato), (yyvsp[-4].nodo), (yyvsp[-1].nodo), (yylsp[-9]).first_line, (yylsp[-9]).first_column); }
#line 2694 "build/parser.tab.c"
    break;

  case 143: /* declaracion_matrix: tipoMatrix TOKEN_IDENTIFIER '=' '{' lista_filas '}'  */
#line 352 "src/entriesTools/parser.y"
                                                          { (yyval.nodo) = nuevoDeclaracionMatrixInit((yyvsp[-5].tipoDato), (yyvsp[-4].string), (yyvsp[-1].nodo), (yylsp[-4]).first_line, (yylsp[-4]).first_column); }
#line 2700 "build/parser.tab.c"
    break;

  case 144: /* lista_filas: lista_filas ',' lista_fila  */
#line 355 "src/entriesTools/parser.y"
                                        { agregarHijo((yyvsp[-2].nodo), (yyvsp[0].nodo)); (yyval.nodo) = (yyvsp[-2].nodo); }
#line 2706 "build/parser.tab.c"
    break;

  case 145: /* lista_filas: lista_fila  */
#line 356 "src/entriesTools/parser.y"
                 { 
        AbstractExpresion* b = nuevoListaFilas();
        agregarHijo(b, (yyvsp[0].nodo));
        (yyval.nodo) = b;
    }
#line 2716 "build/parser.tab.c"
    break;

  case 146: /* lista_fila: '{' lista_elementos '}'  */
#line 363 "src/entriesTools/parser.y"
                                    { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2722 "build/parser.tab.c"
    break;

  case 147: /* acceso_matrix: TOKEN_IDENTIFIER '[' expr ']' '[' expr ']'  */
#line 366 "src/entriesTools/parser.y"
                                                          { (yyval.nodo) = nuevoAccesoMatrixExpresion((yyvsp[-6].string), (yyvsp[-4].nodo), (yyvsp[-1].nodo), (yylsp[-6]).first_line, (yylsp[-6]).first_column); }
#line 2728 "build/parser.tab.c"
    break;


#line 2732 "build/parser.tab.c"

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

#line 368 "src/entriesTools/parser.y"


/* definición de yyerror, usa el yylloc global para ubicación */
void yyerror(const char *s) {
    int ambito = contextoActualReporte ? contextoActualReporte->nombre : 0;
    agregarErrorSintactico(s, yylloc.first_line, yylloc.first_column, ambito);
}
