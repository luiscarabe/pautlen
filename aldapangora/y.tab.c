/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "omicron.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "omicron.h"
	#include "generacion.h"
	#include "graph.h"

	/* Del main*/
	extern FILE* yyin;
	extern FILE* compilador_log;

	/*Fichero para guardar codigo NASM*/

	extern FILE* fout;

	/* En fichero especificacion Flex*/
	extern int yylex(void);
	extern int row;
	extern int col;
	extern int error_flag;

	Graph* tabla_simbolos;

	/*Variables globales necesarias para la inserción de identificadores en la tabla de símbolos*/
	//int categoria;
	int tipo_actual;
	int clase_actual;

	int tamanio_vector_actual;
	int num_variable_local_actual;
	int pos_variable_local_actual;
	int num_param;
	int pos_param;

	/* Locales */
	int yyerror (const char *s);



#line 107 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_NONE = 258,
    TOK_CLASS = 259,
    TOK_INHERITS = 260,
    TOK_INSTANCE_OF = 261,
    TOK_DISCARD = 262,
    TOK_ITSELF = 263,
    TOK_HIDDEN = 264,
    TOK_SECRET = 265,
    TOK_EXPOSED = 266,
    TOK_UNIQUE = 267,
    TOK_FUNCTION = 268,
    TOK_RETURN = 269,
    TOK_MAIN = 270,
    TOK_INT = 271,
    TOK_BOOLEAN = 272,
    TOK_ARRAY = 273,
    TOK_IF = 274,
    TOK_ELSE = 275,
    TOK_WHILE = 276,
    TOK_SCANF = 277,
    TOK_PRINTF = 278,
    TOK_IDENTIFICADOR = 279,
    TOK_IGUAL = 280,
    TOK_DISTINTO = 281,
    TOK_MENORIGUAL = 282,
    TOK_MAYORIGUAL = 283,
    TOK_OR = 284,
    TOK_AND = 285,
    TOK_CONSTANTE_ENTERA = 286,
    TOK_FALSE = 287,
    TOK_TRUE = 288,
    NEG_UNARIA = 289
  };
#endif
/* Tokens.  */
#define TOK_NONE 258
#define TOK_CLASS 259
#define TOK_INHERITS 260
#define TOK_INSTANCE_OF 261
#define TOK_DISCARD 262
#define TOK_ITSELF 263
#define TOK_HIDDEN 264
#define TOK_SECRET 265
#define TOK_EXPOSED 266
#define TOK_UNIQUE 267
#define TOK_FUNCTION 268
#define TOK_RETURN 269
#define TOK_MAIN 270
#define TOK_INT 271
#define TOK_BOOLEAN 272
#define TOK_ARRAY 273
#define TOK_IF 274
#define TOK_ELSE 275
#define TOK_WHILE 276
#define TOK_SCANF 277
#define TOK_PRINTF 278
#define TOK_IDENTIFICADOR 279
#define TOK_IGUAL 280
#define TOK_DISTINTO 281
#define TOK_MENORIGUAL 282
#define TOK_MAYORIGUAL 283
#define TOK_OR 284
#define TOK_AND 285
#define TOK_CONSTANTE_ENTERA 286
#define TOK_FALSE 287
#define TOK_TRUE 288
#define NEG_UNARIA 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 42 "omicron.y" /* yacc.c:355  */


	tipo_atributos atributos;


#line 221 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 238 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   269

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  218

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,     2,     2,     2,     2,     2,
      46,    47,    36,    34,    45,    35,    48,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
      50,    49,    51,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   145,   145,   146,   148,   150,   151,   154,   156,   158,
     159,   160,   161,   162,   163,   164,   165,   167,   170,   173,
     178,   179,   182,   185,   190,   194,   200,   203,   212,   214,
     217,   249,   250,   253,   257,   258,   259,   262,   263,   266,
     267,   270,   271,   274,   275,   278,   279,   282,   283,   286,
     287,   288,   289,   290,   291,   292,   295,   298,   299,   302,
     328,   329,   330,   331,   334,   337,   338,   341,   344,   345,
     348,   354,   355,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   387,   392,   393,   394,   395,   396,   397,   400,
     401,   404,   405,   408,   409,   412,   413,   414,   415,   416,
     417,   420,   420,   422,   430,   430,   433,   433,   437,   447,
     454,   459
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_NONE", "TOK_CLASS", "TOK_INHERITS",
  "TOK_INSTANCE_OF", "TOK_DISCARD", "TOK_ITSELF", "TOK_HIDDEN",
  "TOK_SECRET", "TOK_EXPOSED", "TOK_UNIQUE", "TOK_FUNCTION", "TOK_RETURN",
  "TOK_MAIN", "TOK_INT", "TOK_BOOLEAN", "TOK_ARRAY", "TOK_IF", "TOK_ELSE",
  "TOK_WHILE", "TOK_SCANF", "TOK_PRINTF", "TOK_IDENTIFICADOR", "TOK_IGUAL",
  "TOK_DISTINTO", "TOK_MENORIGUAL", "TOK_MAYORIGUAL", "TOK_OR", "TOK_AND",
  "TOK_CONSTANTE_ENTERA", "TOK_FALSE", "TOK_TRUE", "'+'", "'-'", "'*'",
  "'/'", "NEG_UNARIA", "'!'", "'{'", "'}'", "';'", "'['", "']'", "','",
  "'('", "')'", "'.'", "'='", "'<'", "'>'", "$accept", "programa",
  "inicioTabla", "declaraciones", "declaracion", "modificadores_acceso",
  "clase", "declaracion_clase", "modificadores_clase", "clase_escalar",
  "tipo", "clase_objeto", "clase_vector", "identificadores",
  "identificador", "funciones", "funcion", "tipo_retorno",
  "parametros_funcion", "resto_parametros_funcion", "parametro_funcion",
  "declaraciones_funcion", "sentencias", "sentencia", "sentencia_simple",
  "destruir_objeto", "bloque", "asignacion", "elemento_vector",
  "condicional", "bucle", "lectura", "escritura", "retorno_funcion", "exp",
  "identificador_clase", "lista_expresiones", "resto_lista_expresiones",
  "comparacion", "constante", "$@1", "constante_logica", "$@2", "$@3",
  "constante_entera", "escritura_cabeceras_datos", "escritura_main",
  "escritura_fin", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    43,    45,    42,    47,   289,    33,
     123,   125,    59,    91,    93,    44,    40,    41,    46,    61,
      60,    62
};
# endif

#define YYPACT_NINF -100

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-100)))

#define YYTABLE_NINF -90

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -100,    12,    22,  -100,    -8,  -100,   180,    36,    42,    49,
    -100,   102,    50,    55,    17,  -100,    50,  -100,  -100,  -100,
      10,  -100,  -100,  -100,  -100,    24,    51,    52,    32,    79,
    -100,  -100,  -100,  -100,   208,  -100,  -100,  -100,  -100,    61,
     208,    43,    46,  -100,    54,    56,  -100,    74,    75,  -100,
      14,    78,    86,    96,   141,    48,    80,   208,    99,  -100,
    -100,  -100,    93,  -100,  -100,  -100,  -100,  -100,   106,   111,
     114,   131,  -100,  -100,    52,    -1,  -100,  -100,   115,  -100,
    -100,  -100,   141,   141,   141,  -100,   217,   116,  -100,  -100,
    -100,   141,   141,   124,  -100,   217,   141,   141,    84,  -100,
    -100,  -100,    94,   146,    53,  -100,   133,  -100,    52,   102,
     141,  -100,  -100,  -100,  -100,   109,   128,   141,   141,   141,
     141,   141,   141,   155,  -100,   165,   174,   206,   189,   139,
     164,   217,   181,   217,   -18,   182,   183,   166,   172,  -100,
    -100,   177,    50,   186,   141,   141,   141,   141,  -100,   141,
     141,  -100,   -21,  -100,   -21,   -21,  -100,  -100,   191,   188,
     198,  -100,   141,  -100,  -100,   193,   199,   141,   141,  -100,
    -100,   204,    53,  -100,   102,   207,  -100,   217,   217,   217,
     217,   217,   217,   141,   208,   208,   189,   141,   141,   202,
     217,    55,   172,    50,  -100,   209,   214,   216,  -100,   211,
     212,  -100,  -100,   208,  -100,   219,  -100,   241,  -100,  -100,
    -100,   221,  -100,   223,  -100,   208,   224,  -100
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,   109,    32,    12,    13,    14,
      15,    16,    32,     5,    22,   110,    32,     9,    10,    11,
       0,   110,     6,    24,    25,     0,     0,     0,     0,     0,
      17,    23,    19,    18,     0,    31,    34,    35,    36,     0,
       0,     0,     0,    30,     0,    28,     8,     0,     0,    90,
       0,     0,     0,     0,     0,    89,     0,    45,     0,    55,
      48,    49,     0,    57,    58,    51,    50,    52,     0,     0,
       0,     0,    26,     7,     0,     0,    56,    72,    81,   108,
     106,   104,     0,     0,     0,    85,    71,     0,    82,   101,
     103,     0,     0,    68,    69,    70,     0,    92,     0,     3,
      46,    47,     0,     0,    38,   111,     0,    29,     0,    16,
      92,   107,   105,    77,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,     0,     0,     0,    94,     0,
       0,    59,     0,    60,     0,     0,     0,     0,    40,     2,
      27,     0,    32,     0,     0,     0,     0,     0,    83,     0,
       0,    84,    79,    78,    73,    74,    76,    75,    88,     0,
       0,    64,     0,    91,    54,     0,     0,    92,     0,    41,
      42,     0,     0,    37,    16,     0,    86,    95,    96,    97,
      98,    99,   100,    92,     0,     0,    94,    92,    92,     0,
      63,    44,    40,    32,    21,     0,     0,     0,    93,     0,
       0,    53,    43,     0,    39,     0,    87,    65,    67,    62,
      61,     0,    20,     0,    33,     0,     0,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -100,  -100,  -100,    -6,  -100,   253,  -100,  -100,  -100,  -100,
       4,    16,  -100,   -53,  -100,   -11,  -100,  -100,  -100,    76,
      95,  -100,   -37,  -100,  -100,  -100,  -100,  -100,   -34,  -100,
    -100,  -100,  -100,  -100,   -40,   -32,   -99,    83,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,   245,  -100
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    12,    13,    14,    27,    28,    29,    30,
     135,   136,    33,    44,    45,    15,    16,    39,   137,   173,
     138,   203,    56,    57,    58,    59,    60,    61,    85,    63,
      64,    65,    66,    67,   128,    87,   129,   163,   116,    88,
     124,    89,   112,   111,    90,     6,    34,   139
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,    21,    68,    70,   108,    35,    62,    22,    68,   118,
      86,   143,     3,    36,    95,   121,   122,    77,    31,    94,
     100,   107,    49,    62,    37,    68,    23,    24,   167,    41,
      32,   168,     5,    23,    24,    25,    38,     4,    78,   109,
      23,    24,   113,   114,   115,    79,    80,    81,    17,    82,
      26,   125,   126,    83,    18,   141,   127,    26,   131,   -16,
      84,    19,   133,    11,     7,     8,     9,    10,   189,    23,
      24,   -16,   -16,   -16,    46,    42,    43,   152,   153,   154,
     155,   156,   157,    47,   195,    69,    71,    72,   199,   200,
     130,    96,    49,    26,    97,   -16,    73,    98,    75,    76,
     132,    74,    49,   142,   177,   178,   179,   180,    78,   181,
     182,     7,     8,     9,    10,    79,    80,    81,    78,    82,
      93,    99,   186,    83,    91,    79,    80,    81,   190,    82,
      84,   175,    92,    83,   144,   145,   146,   147,   117,   118,
      84,   101,   102,   119,   120,   121,   122,   196,   197,    49,
      62,    62,    68,    68,   103,   105,   148,   104,    96,   149,
     150,   110,   106,   -89,   123,    78,   211,    96,   193,    62,
     134,    68,    79,    80,    81,   151,    82,   140,   216,   158,
      83,    62,   205,    68,   -16,   202,   164,    84,   165,     7,
       8,     9,    10,    11,   117,   118,   -16,   -16,   -16,   119,
     120,   121,   122,   117,   118,   166,   169,   170,   119,   120,
     121,   122,   159,   171,   172,    48,    49,   174,   117,   118,
     -16,   160,    50,   119,   120,   121,   122,    51,   184,    52,
      53,    54,    55,   176,   162,   117,   118,   183,   185,   187,
     119,   120,   121,   122,   191,   188,   117,   118,   194,   201,
     161,   119,   120,   121,   122,   207,   206,   208,   209,   210,
     212,   213,   214,   215,    20,   217,    40,   192,   204,   198
};

static const yytype_uint8 yycheck[] =
{
      34,    12,    34,    40,     5,    16,    40,    13,    40,    30,
      50,   110,     0,     3,    54,    36,    37,     3,    14,    53,
      57,    74,     8,    57,    20,    57,    16,    17,    46,    25,
      14,    49,    40,    16,    17,    18,    20,    15,    24,    40,
      16,    17,    82,    83,    84,    31,    32,    33,    12,    35,
      40,    91,    92,    39,    12,   108,    96,    40,    98,     4,
      46,    12,   102,    13,     9,    10,    11,    12,   167,    16,
      17,    16,    17,    18,    42,    24,    24,   117,   118,   119,
     120,   121,   122,     4,   183,    24,    43,    41,   187,   188,
       6,    43,     8,    40,    46,    40,    42,    49,    24,    24,
       6,    45,     8,   109,   144,   145,   146,   147,    24,   149,
     150,     9,    10,    11,    12,    31,    32,    33,    24,    35,
      24,    41,   162,    39,    46,    31,    32,    33,   168,    35,
      46,   142,    46,    39,    25,    26,    27,    28,    29,    30,
      46,    42,    49,    34,    35,    36,    37,   184,   185,     8,
     184,   185,   184,   185,    48,    41,    47,    46,    43,    50,
      51,    46,    31,    48,    48,    24,   203,    43,   174,   203,
      24,   203,    31,    32,    33,    47,    35,    44,   215,    24,
      39,   215,   193,   215,     4,   191,    47,    46,    24,     9,
      10,    11,    12,    13,    29,    30,    16,    17,    18,    34,
      35,    36,    37,    29,    30,    24,    24,    24,    34,    35,
      36,    37,    47,    47,    42,     7,     8,    40,    29,    30,
      40,    47,    14,    34,    35,    36,    37,    19,    40,    21,
      22,    23,    24,    47,    45,    29,    30,    46,    40,    46,
      34,    35,    36,    37,    40,    46,    29,    30,    41,    47,
      44,    34,    35,    36,    37,    41,    47,    41,    47,    47,
      41,    20,    41,    40,    11,    41,    21,   172,   192,   186
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,    54,     0,    15,    40,    97,     9,    10,    11,
      12,    13,    55,    56,    57,    67,    68,    12,    12,    12,
      57,    67,    55,    16,    17,    18,    40,    58,    59,    60,
      61,    62,    63,    64,    98,    67,     3,    62,    63,    69,
      98,    62,    24,    24,    65,    66,    42,     4,     7,     8,
      14,    19,    21,    22,    23,    24,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    87,    24,
      74,    43,    41,    42,    45,    24,    24,     3,    24,    31,
      32,    33,    35,    39,    46,    80,    86,    87,    91,    93,
      96,    46,    46,    24,    80,    86,    43,    46,    49,    41,
      74,    42,    49,    48,    46,    41,    31,    65,     5,    40,
      46,    95,    94,    86,    86,    86,    90,    29,    30,    34,
      35,    36,    37,    48,    92,    86,    86,    86,    86,    88,
       6,    86,     6,    86,    24,    62,    63,    70,    72,    99,
      44,    65,    55,    88,    25,    26,    27,    28,    47,    50,
      51,    47,    86,    86,    86,    86,    86,    86,    24,    47,
      47,    44,    45,    89,    47,    24,    24,    46,    49,    24,
      24,    47,    42,    71,    40,    67,    47,    86,    86,    86,
      86,    86,    86,    46,    40,    40,    86,    46,    46,    88,
      86,    40,    72,    55,    41,    88,    74,    74,    89,    88,
      88,    47,    55,    73,    71,    67,    47,    41,    41,    47,
      47,    74,    41,    20,    41,    40,    74,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    54,    55,    55,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    58,    58,
      59,    59,    60,    61,    62,    62,    63,    64,    65,    65,
      66,    67,    67,    68,    69,    69,    69,    70,    70,    71,
      71,    72,    72,    73,    73,    74,    74,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    77,    78,    78,    79,
      79,    79,    79,    79,    80,    81,    81,    82,    83,    83,
      84,    85,    85,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    87,
      87,    88,    88,    89,    89,    90,    90,    90,    90,    90,
      90,    92,    91,    91,    94,    93,    95,    93,    96,    97,
      98,    99
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    10,     8,     0,     1,     2,     4,     3,     2,
       2,     2,     1,     1,     1,     1,     0,     1,     1,     1,
       9,     7,     0,     1,     1,     1,     3,     5,     1,     3,
       1,     2,     0,    11,     1,     1,     1,     2,     0,     3,
       0,     2,     2,     1,     0,     1,     2,     2,     1,     1,
       1,     1,     1,     6,     4,     1,     2,     1,     1,     3,
       3,     7,     7,     5,     4,     7,    11,     7,     2,     2,
       2,     2,     2,     3,     3,     3,     3,     2,     3,     3,
       2,     1,     1,     3,     3,     1,     4,     6,     3,     1,
       1,     2,     0,     3,     0,     3,     3,     3,     3,     3,
       3,     0,     2,     1,     0,     2,     0,     2,     1,     0,
       0,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 145 "omicron.y" /* yacc.c:1646  */
    { fprintf(compilador_log, ";R:\tprograma: TOK_MAIN '{' declaraciones funciones sentencias '}'\n");}
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 146 "omicron.y" /* yacc.c:1646  */
    { fprintf(compilador_log, ";R:\tprograma: TOK_MAIN '{' funciones sentencias '}'\n");}
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 148 "omicron.y" /* yacc.c:1646  */
    { iniciarTablaSimbolosClases(&tabla_simbolos, "Tablasimbolos"); }
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 150 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tdeclaraciones: declaracion\n");}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 151 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tdeclaraciones: declaracion declaraciones\n");}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 155 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tdeclaracion: modificadores_acceso clase identificadores ';'\n");}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 156 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tdeclaracion: modificadores_acceso declaracion_clase ';'\n");}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 158 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_HIDDEN TOK_UNIQUE\n");}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 159 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_SECRET TOK_UNIQUE\n");}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 160 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_EXPOSED TOK_UNIQUE\n");}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 161 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_HIDDEN\n");}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 162 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_SECRET\n");}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 163 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_EXPOSED\n");}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 164 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_UNIQUE\n");}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 165 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tmodificadores_acceso: \n");}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 168 "omicron.y" /* yacc.c:1646  */
    { fprintf(compilador_log, ";R:\tclase: clase_escalar\n");
		  clase_actual=ESCALAR;	}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 171 "omicron.y" /* yacc.c:1646  */
    { fprintf(compilador_log, ";R:\tclase: clase_vector\n");
	 	  clase_actual = VECTOR; }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 174 "omicron.y" /* yacc.c:1646  */
    { fprintf(compilador_log, ";R:\tclase: clase_objeto\n");
	   	  clase_actual = OBJETO; }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 178 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR TOK_INHERITS identificadores '{' declaraciones funciones '}'\n");}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 179 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}'\n");}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 182 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tmodificadores_clase: \n");}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 186 "omicron.y" /* yacc.c:1646  */
    { fprintf(compilador_log, ";R:\tclase_escalar: tipo\n");
				  tamanio_vector_actual = 1;}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 191 "omicron.y" /* yacc.c:1646  */
    {   fprintf(compilador_log, ";R:\ttipo: TOK_INT\n");
			tipo_actual = INT;
	    }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 195 "omicron.y" /* yacc.c:1646  */
    { 	fprintf(compilador_log, ";R:\ttipo: TOK_BOOLEAN\n");
			tipo_actual = BOOLEAN;
		}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 200 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tclase_objeto: '{' TOK_IDENTIFICADOR '}'\n");}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 204 "omicron.y" /* yacc.c:1646  */
    { fprintf(compilador_log, ";R:\tclase_vector: TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']'\n");
				  tamanio_vector_actual = (yyvsp[-1].atributos).valor_entero;
				  if ((tamanio_vector_actual < 1) || (tamanio_vector_actual > MAX_TAMANIO_VECTOR)){
					fprintf(stderr, "Error, tamaño de vector no válido. Linea %d columna %d", row, col);
					return 0;
					}}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 212 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tidentificadores: TOK_IDENTIFICADOR\n");
								}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 214 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tidentificadores: TOK_IDENTIFICADOR ',' identificadores\n");}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 218 "omicron.y" /* yacc.c:1646  */
    {
					HT_item *e;
					char nombre [100];
					int aux;

					/*TODO, conseguir el nombre del ambito*/
					sprintf(nombre, "main_%s", (yyvsp[0].atributos).lexema);
					if(buscarParaDeclararIdTablaSimbolosAmbitos(tabla_simbolos, nombre, &e, "main") == OK){
						fprintf(stderr, "Identificador %s duplicado. Linea %d columna %d\n", (yyvsp[0].atributos).lexema, row, col);
						return ERR;
					}

					printf("declarando variable %s", nombre);

					/*TODO llamada correcta funcion*/
					aux = insertarTablaSimbolosMain(tabla_simbolos, VARIABLE,
											  nombre,         clase_actual,
											  tipo_actual,	  0,                    
											  0,      		  0,
											  0,              tamanio_vector_actual,      
											  ACCESO_TODOS,        MIEMBRO_NO_UNICO, 
											  0,              0,
											  NULL);
					
					printf("RETORNO %d", aux);
					/*Insertamos en segmento .bss*/

					declarar_variable(fout, (yyvsp[0].atributos).lexema,  tipo_actual,  tamanio_vector_actual);

				}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 249 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tfunciones: funcion funciones\n");}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 250 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tfunciones: \n");}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 254 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tfuncion: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'\n");}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 257 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\ttipo_retorno: TOK_NONE\n");}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 258 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\ttipo_retorno: tipo\n");}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 259 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\ttipo_retorno: clase_objeto\n");}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 262 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tparametros_funcion: parametro_funcion resto_parametros_funcion\n");}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 263 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tparametros_funcion: \n");}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 266 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tresto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion\n");}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 267 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tresto_parametros_funcion: \n");}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 270 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tparametro_funcion: tipo TOK_IDENTIFICADOR\n");}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 271 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tparametro_funcion: clase_objeto TOK_IDENTIFICADOR\n");}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 274 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tdeclaraciones_funcion: declaraciones\n");}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 275 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tdeclaraciones_funcion: \n");}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 278 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencias: sentencia\n");}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 279 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencias: sentencia sentencias\n");}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 282 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencia: sentencia_simple ';'\n");}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 283 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencia: bloque\n");}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 286 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencia_simple: asignacion\n");}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 287 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencia_simple: escritura\n");}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 288 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencia_simple: lectura\n");}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 289 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencia_simple: retorno_funcion\n");}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 290 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencia_simple: identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 291 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencia_simple: TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 292 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencia_simple: destruir_objeto\n");}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 295 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tdestruir_objeto: TOK_DISCARD TOK_IDENTIFICADOR\n");}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 298 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tbloque: condicional\n");}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 299 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tbloque: bucle\n");}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 303 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tasignacion: TOK_IDENTIFICADOR '=' exp\n");
			 //TODO nombre ambito
			char nombre[100];
			char nombre_ambito_encontrado [100];
			HT_item* e;
			sprintf(nombre, "main_%s", (yyvsp[-2].atributos).lexema);
			printf("buscando variabe %s", nombre);
			if(buscarIdNoCualificado(tabla_simbolos, 
                 					nombre, 
                 					"main",
                 					&e, 
  									nombre_ambito_encontrado) == ERR){
    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se encuentra simbolo en asignacion\n", row, col);}
    		else if (HT_itemGetCategory(e) == FUNCION){
    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se puede asignar una funcion\n", row, col);}
    		else if (HT_itemGetClass(e) == VECTOR){
    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. La clase del simboo es vector\n", row, col);
    		}
    		else if(HT_itemGetType(e) != (yyvsp[0].atributos).tipo){
    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. Asignacion de tipos incompatibles\n", row, col);
    		}

    		asignar(fout, (yyvsp[-2].atributos).lexema, (yyvsp[0].atributos).direcciones);

			}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 328 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tasignacion: elemento_vector '=' exp\n");}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 329 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tasignacion: elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 330 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tasignacion: TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 331 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tasignacion: identificador_clase '.' TOK_IDENTIFICADOR '=' exp\n");}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 334 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\telemento_vector: TOK_IDENTIFICADOR '[' exp ']'\n");}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 337 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tcondicional: TOK_IF '(' exp ')' '{' sentencias '}'\n");}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 338 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tcondicional: TOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}'\n");}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 341 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tdbucle: TOK_WHILE '(' exp ')' '{' sentencias '}'\n");}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 344 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tlectura: TOK_SCANF TOK_IDENTIFICADOR\n");}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 345 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tlectura: TOK_SCANF elemento_vector\n");}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 349 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tescritura: TOK_PRINTF exp\n");
			escribir(fout, (yyvsp[0].atributos).direcciones, (yyvsp[0].atributos).tipo);			
			}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 354 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tretorno_funcion: TOK_RETURN exp\n");}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 355 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tretorno_funcion: TOK_RETURN TOK_NONE\n");}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 358 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: exp '+' exp\n");}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 359 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: exp '-' exp\n");}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 360 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: exp '/' exp\n");}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 361 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: exp '*' exp\n");}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 362 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: '-' exp\n");}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 363 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: exp TOK_AND exp\n");}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 364 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: exp TOK_OR exp\n");}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 365 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: '!' exp\n");}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 366 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: TOK_IDENTIFICADOR\n");
	//TODO conseguir nombre con ambit bien
			char nombre[100];
			char nombre_ambito_encontrado [100];
			HT_item* e = NULL;
			sprintf(nombre, "main_%s", (yyvsp[0].atributos).lexema);
			if(buscarIdNoCualificado(tabla_simbolos, 
                 					nombre, 
                 					"main",
                 					&e, 
  									nombre_ambito_encontrado) == ERR){
    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se encuentra simbolo.\n", row, col);}
    		else if (HT_itemGetCategory(e) == FUNCION){
    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. El simbolo en asignacion es una funcion\n", row, col);}
    		else if (HT_itemGetClass(e) == VECTOR){
    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. La clase del simboo es vector\n", row, col);
    		}
    		(yyval.atributos).tipo = HT_itemGetType(e);
    		(yyval.atributos).direcciones = 1;
    		escribir_operando(fout, (yyvsp[0].atributos).lexema, 1);
    	}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 388 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: constante\n");
   		 (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
   		 (yyval.atributos).direcciones = (yyvsp[0].atributos).direcciones; }
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 392 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: '(' exp ')'\n");}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 393 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: '(' comparacion ')'\n");}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 394 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: elemento_vector\n");}
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 395 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 396 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 397 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR\n");}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 400 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tidentificador_clase: TOK_IDENTIFICADOR\n");}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 401 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tidentificador_clase: TOK_ITSELF\n");}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 404 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tlista_expresiones: exp resto_lista_expresiones\n");}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 405 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tlista_expresiones: \n");}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 408 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tresto_lista_expresiones: ',' exp resto_lista_expresiones\n");}
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 409 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tresto_lista_expresiones: \n");}
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 412 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tcomparacion: exp TOK_IGUAL exp\n");}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 413 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tcomparacion: exp TOK_DISTINTO exp\n");}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 414 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tcomparacion: exp TOK_MENORIGUAL exp\n");}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 415 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tcomparacion: exp TOK_MAYORIGUAL exp\n");}
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 416 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tcomparacion: exp '<' exp\n");}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 417 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tcomparacion: exp '>' exp\n");}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 420 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tconstante: constante_logica\n");}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 421 "omicron.y" /* yacc.c:1646  */
    {}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 423 "omicron.y" /* yacc.c:1646  */
    {
		 	fprintf(compilador_log, ";R:\tconstante: constante_entera\n");
		 	(yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
		 	(yyval.atributos).direcciones = (yyvsp[0].atributos).direcciones;
		 }
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 430 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tconstante_logica: TOK_TRUE\n");}
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 431 "omicron.y" /* yacc.c:1646  */
    {}
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 433 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tconstante_logica: TOK_FALSE\n");}
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 434 "omicron.y" /* yacc.c:1646  */
    {}
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 438 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tconstante_entera: TOK_CONSTANTE_ENTERA\n");
					 (yyval.atributos).tipo=INT;
					 (yyval.atributos).direcciones = 0 ;
					 (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
					 char aux[10];
					 sprintf(aux, "%d", (yyvsp[0].atributos).valor_entero);
					 escribir_operando(fout, aux, 0);
					}
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 447 "omicron.y" /* yacc.c:1646  */
    {
	escribir_subseccion_data(fout);
	escribir_cabecera_bss(fout);

}
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 454 "omicron.y" /* yacc.c:1646  */
    {
  escribir_segmento_codigo(fout);
	escribir_inicio_main(fout);
}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 459 "omicron.y" /* yacc.c:1646  */
    {
	escribir_fin(fout);
}
#line 2251 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2255 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 464 "omicron.y" /* yacc.c:1906  */



int yyerror (const char *s)
{
	if(error_flag == 0){
    	fprintf(stderr, "****Error sintactico en [lin %d, col %d]\n", row, col);
    }
    return 0;
}
