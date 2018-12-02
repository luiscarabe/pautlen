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
	int categoria;
	int tipo_actual;
	int clase_actual;
	int tamanio_vector_actual;
	int num_variable_local_actual;
	int pos_variable_local_actual;
	int num_param;
	int pos_param;

	/* Locales */
	int yyerror (const char *s);



#line 106 "y.tab.c" /* yacc.c:339  */

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
#line 41 "omicron.y" /* yacc.c:355  */


	tipo_atributos atributos;


#line 217 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 234 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   260

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  225

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
       0,   144,   144,   145,   147,   149,   150,   153,   155,   157,
     158,   159,   160,   161,   162,   163,   164,   166,   168,   169,
     172,   173,   176,   179,   183,   183,   186,   186,   192,   195,
     205,   212,   215,   216,   219,   223,   224,   225,   228,   229,
     232,   233,   236,   237,   240,   241,   244,   245,   248,   249,
     252,   253,   254,   255,   256,   257,   258,   261,   264,   265,
     268,   271,   272,   273,   274,   277,   280,   281,   284,   287,
     288,   291,   295,   296,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   307,   309,   309,   311,   312,   313,   314,
     315,   316,   319,   320,   323,   324,   327,   328,   331,   332,
     333,   334,   335,   336,   339,   339,   341,   341,   345,   345,
     348,   348,   352,   352,   355,   361,   365,   370
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
  "tipo", "$@1", "$@2", "clase_objeto", "clase_vector", "identificadores",
  "funciones", "funcion", "tipo_retorno", "parametros_funcion",
  "resto_parametros_funcion", "parametro_funcion", "declaraciones_funcion",
  "sentencias", "sentencia", "sentencia_simple", "destruir_objeto",
  "bloque", "asignacion", "elemento_vector", "condicional", "bucle",
  "lectura", "escritura", "retorno_funcion", "exp", "$@3", "$@4",
  "identificador_clase", "lista_expresiones", "resto_lista_expresiones",
  "comparacion", "constante", "$@5", "$@6", "constante_logica", "$@7",
  "$@8", "constante_entera", "$@9", "escritura_cabeceras_datos",
  "escritura_TS", "escritura_main", "escritura_fin", YY_NULLPTR
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

#define YYPACT_NINF -169

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-169)))

#define YYTABLE_NINF -93

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,   -15,    53,    40,    46,  -169,    29,   115,   209,    46,
    -169,    62,    65,    77,  -169,     5,    78,  -169,    15,    58,
      61,    85,    55,    22,    70,   209,    75,  -169,  -169,  -169,
      71,  -169,  -169,  -169,  -169,  -169,    64,  -169,   115,  -169,
    -169,  -169,  -169,  -169,  -169,   109,  -169,  -169,   110,  -169,
    -169,    30,  -169,  -169,  -169,    55,    55,    55,  -169,   119,
      87,  -169,  -169,  -169,    55,    55,    95,  -169,   119,    55,
      55,    97,  -169,  -169,  -169,   134,   117,  -169,    20,    17,
    -169,  -169,   103,   101,    55,  -169,  -169,  -169,  -169,  -169,
    -169,   171,   104,    55,    55,    55,    55,    55,    55,   126,
    -169,  -169,  -169,    63,   142,   207,   190,   112,   133,   119,
     136,   119,   -34,    46,  -169,    50,   150,   139,   178,  -169,
    -169,  -169,  -169,  -169,    24,   128,    55,    55,    55,    55,
    -169,    55,    55,  -169,   -10,  -169,   -10,   -10,  -169,  -169,
     137,   144,   145,  -169,    55,  -169,  -169,   141,   146,    55,
      55,  -169,   147,   143,   149,  -169,   170,   186,   188,   148,
     172,  -169,   119,   119,   119,   119,   119,   119,    55,   209,
     209,   190,    55,    55,   168,   119,   209,   198,   150,  -169,
       9,  -169,  -169,   194,    24,  -169,   191,   199,   204,  -169,
     192,   200,  -169,   205,   206,  -169,   150,   115,    20,   172,
    -169,   228,  -169,  -169,  -169,  -169,  -169,   212,    46,  -169,
     209,  -169,   213,  -169,   115,   208,   214,   209,    46,  -169,
    -169,   215,   216,  -169,  -169
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    33,     1,     0,    16,     0,    33,
     114,    12,    13,    14,    15,     0,     0,    93,     0,     0,
       0,     0,     0,    92,     0,    46,     0,    56,    49,    50,
       0,    58,    59,    52,    51,    53,     0,    32,    16,     9,
      10,    11,    35,    24,    26,     0,    36,    37,     0,    57,
      73,    82,   112,   110,   108,     0,     0,     0,    88,    72,
       0,    84,   104,   106,     0,     0,    69,    70,    71,     0,
      95,     0,     3,    47,    48,     0,     0,   115,     5,    22,
      25,    27,     0,     0,    95,    83,   113,   111,   109,    78,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,   105,   107,     0,     0,     0,    97,     0,     0,    60,
       0,    61,     0,    33,     6,     0,     0,     0,     0,    17,
      23,    19,    18,    28,    39,     0,     0,     0,     0,     0,
      86,     0,     0,    87,    80,    79,    74,    75,    77,    76,
      91,     0,     0,    65,     0,    94,    55,     0,     0,    95,
       0,   116,     0,    30,     0,     8,     0,     0,     0,     0,
      41,    89,    98,    99,   100,   101,   102,   103,    95,     0,
       0,    97,    95,    95,     0,    64,     0,     0,     0,     7,
       0,    42,    43,     0,     0,    38,     0,     0,     0,    96,
       0,     0,    54,     0,     0,    31,     0,    16,    45,    41,
      90,    66,    68,    63,    62,   117,    29,     0,    33,    44,
       0,    40,     0,     2,    16,     0,     0,     0,    33,    21,
      34,     0,     0,    67,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -169,  -169,  -169,   -75,  -169,   247,  -169,  -169,  -169,  -169,
      -9,  -169,  -169,    -4,  -169,  -168,    -5,  -169,  -169,  -169,
      59,    76,  -169,   -24,  -169,  -169,  -169,  -169,  -169,    -8,
    -169,  -169,  -169,  -169,  -169,   -13,  -169,  -169,    -6,   -77,
      88,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,  -169
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    77,    78,    79,   116,   117,   118,   119,
     157,    80,    81,   158,   122,   154,     8,     9,    48,   159,
     185,   160,   210,    24,    25,    26,    27,    28,    29,    58,
      31,    32,    33,    34,    35,   106,    85,   100,    60,   107,
     145,    92,    61,   101,   102,    62,    88,    87,    63,    86,
      38,   113,   176,   213
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    73,    36,   114,    37,    59,    46,   125,    42,    68,
     195,    47,   149,    67,   196,   150,     1,    30,    50,    36,
      94,    43,    44,    17,   -16,     4,    97,    98,   207,    11,
      12,    13,    14,    43,    44,   115,   -16,   -16,   -16,    51,
      43,    44,    89,    90,    91,    45,    52,    53,    54,   197,
      55,   103,   104,     5,    56,     6,   105,    45,   109,     7,
     -16,    57,   111,    17,    45,    69,    43,    44,    70,    10,
     120,    71,   174,    69,    39,   121,    84,    40,   -92,    51,
     134,   135,   136,   137,   138,   139,    52,    53,    54,    41,
      55,   186,    93,    94,    56,   190,   191,    95,    96,    97,
      98,    57,    49,   108,    64,    17,   152,    65,   151,    66,
     141,    72,    76,   162,   163,   164,   165,    74,   166,   167,
      75,    51,   208,   209,    11,    12,    13,    14,    52,    53,
      54,   171,    55,    82,    83,    99,    56,   175,    69,   218,
     110,   112,    17,    57,   123,   187,   188,   124,    93,    94,
     140,   133,   193,    95,    96,    97,    98,   147,    51,   146,
     148,    30,    30,    36,    36,    52,    53,    54,    30,    55,
      36,    93,    94,    56,   153,   161,    95,    96,    97,    98,
      57,   155,   156,   168,   169,   170,   216,   172,   178,   142,
     177,   179,   173,   221,   180,   183,   126,   127,   128,   129,
      93,    94,    30,   215,    36,    95,    96,    97,    98,    30,
     181,    36,   182,   222,   184,   192,    16,    17,   130,    93,
      94,   131,   132,    18,    95,    96,    97,    98,    19,   194,
      20,    21,    22,    23,   198,   144,    93,    94,   200,   203,
     201,    95,    96,    97,    98,   202,   205,   204,   212,   219,
     206,   143,   214,   217,    15,   220,   223,   224,   211,   189,
     199
};

static const yytype_uint8 yycheck[] =
{
       8,    25,     8,    78,     9,    18,    15,    84,     3,    22,
     178,    15,    46,    21,     5,    49,    15,    25,     3,    25,
      30,    16,    17,     8,     4,    40,    36,    37,   196,     9,
      10,    11,    12,    16,    17,    18,    16,    17,    18,    24,
      16,    17,    55,    56,    57,    40,    31,    32,    33,    40,
      35,    64,    65,     0,    39,    15,    69,    40,    71,    13,
      40,    46,    75,     8,    40,    43,    16,    17,    46,    40,
      79,    49,   149,    43,    12,    79,    46,    12,    48,    24,
      93,    94,    95,    96,    97,    98,    31,    32,    33,    12,
      35,   168,    29,    30,    39,   172,   173,    34,    35,    36,
      37,    46,    24,     6,    46,     8,   115,    46,   113,    24,
      47,    41,    48,   126,   127,   128,   129,    42,   131,   132,
      49,    24,   197,   198,     9,    10,    11,    12,    31,    32,
      33,   144,    35,    24,    24,    48,    39,   150,    43,   214,
       6,    24,     8,    46,    41,   169,   170,    46,    29,    30,
      24,    47,   176,    34,    35,    36,    37,    24,    24,    47,
      24,   169,   170,   169,   170,    31,    32,    33,   176,    35,
     176,    29,    30,    39,    24,    47,    34,    35,    36,    37,
      46,    42,     4,    46,    40,    40,   210,    46,    45,    47,
      43,    42,    46,   217,    24,    47,    25,    26,    27,    28,
      29,    30,   210,   208,   210,    34,    35,    36,    37,   217,
      24,   217,    24,   218,    42,    47,     7,     8,    47,    29,
      30,    50,    51,    14,    34,    35,    36,    37,    19,    31,
      21,    22,    23,    24,    40,    45,    29,    30,    47,    47,
      41,    34,    35,    36,    37,    41,    41,    47,    20,    41,
      44,    44,    40,    40,     7,    41,    41,    41,   199,   171,
     184
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    53,    54,    40,     0,    15,    13,    68,    69,
      40,     9,    10,    11,    12,    57,     7,     8,    14,    19,
      21,    22,    23,    24,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    90,    68,   102,    12,
      12,    12,     3,    16,    17,    40,    62,    65,    70,    24,
       3,    24,    31,    32,    33,    35,    39,    46,    81,    87,
      90,    94,    97,   100,    46,    46,    24,    81,    87,    43,
      46,    49,    41,    75,    42,    49,    48,    55,    56,    57,
      63,    64,    24,    24,    46,    88,   101,    99,    98,    87,
      87,    87,    93,    29,    30,    34,    35,    36,    37,    48,
      89,    95,    96,    87,    87,    87,    87,    91,     6,    87,
       6,    87,    24,   103,    55,    18,    58,    59,    60,    61,
      62,    65,    66,    41,    46,    91,    25,    26,    27,    28,
      47,    50,    51,    47,    87,    87,    87,    87,    87,    87,
      24,    47,    47,    44,    45,    92,    47,    24,    24,    46,
      49,    68,    62,    24,    67,    42,     4,    62,    65,    71,
      73,    47,    87,    87,    87,    87,    87,    87,    46,    40,
      40,    87,    46,    46,    91,    87,   104,    43,    45,    42,
      24,    24,    24,    47,    42,    72,    91,    75,    75,    92,
      91,    91,    47,    75,    31,    67,     5,    40,    40,    73,
      47,    41,    41,    47,    47,    41,    44,    67,    55,    55,
      74,    72,    20,   105,    40,    68,    75,    40,    55,    41,
      41,    75,    68,    41,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    54,    55,    55,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    58,    58,
      59,    59,    60,    61,    63,    62,    64,    62,    65,    66,
      67,    67,    68,    68,    69,    70,    70,    70,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      77,    77,    77,    77,    77,    77,    77,    78,    79,    79,
      80,    80,    80,    80,    80,    81,    82,    82,    83,    84,
      84,    85,    86,    86,    87,    87,    87,    87,    87,    87,
      87,    87,    88,    87,    89,    87,    87,    87,    87,    87,
      87,    87,    90,    90,    91,    91,    92,    92,    93,    93,
      93,    93,    93,    93,    95,    94,    96,    94,    98,    97,
      99,    97,   101,   100,   102,   103,   104,   105
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    11,     5,     0,     1,     2,     4,     3,     2,
       2,     2,     1,     1,     1,     1,     0,     1,     1,     1,
       9,     7,     0,     1,     0,     2,     0,     2,     3,     5,
       1,     3,     2,     0,    11,     1,     1,     1,     2,     0,
       3,     0,     2,     2,     1,     0,     1,     2,     2,     1,
       1,     1,     1,     1,     6,     4,     1,     2,     1,     1,
       3,     3,     7,     7,     5,     4,     7,    11,     7,     2,
       2,     2,     2,     2,     3,     3,     3,     3,     2,     3,
       3,     2,     0,     2,     0,     2,     3,     3,     1,     4,
       6,     3,     1,     1,     2,     0,     3,     0,     3,     3,
       3,     3,     3,     3,     0,     2,     0,     2,     0,     2,
       0,     2,     0,     2,     0,     0,     0,     0
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
#line 144 "omicron.y" /* yacc.c:1646  */
    { fprintf(compilador_log, ";R:\tprograma: TOK_MAIN '{' declaraciones funciones sentencias '}'\n");}
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 145 "omicron.y" /* yacc.c:1646  */
    { fprintf(compilador_log, ";R:\tprograma: TOK_MAIN '{' funciones sentencias '}'\n");}
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 147 "omicron.y" /* yacc.c:1646  */
    {}
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 149 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tdeclaraciones: declaracion\n");}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 150 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tdeclaraciones: declaracion declaraciones\n");}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 154 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tdeclaracion: modificadores_acceso clase identificadores ';'\n");}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 155 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tdeclaracion: modificadores_acceso declaracion_clase ';'\n");}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 157 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_HIDDEN TOK_UNIQUE\n");}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 158 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_SECRET TOK_UNIQUE\n");}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 159 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_EXPOSED TOK_UNIQUE\n");}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 160 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_HIDDEN\n");}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 161 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_SECRET\n");}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 162 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_EXPOSED\n");}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 163 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_UNIQUE\n");}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 164 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tmodificadores_acceso: \n");}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 166 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tclase: clase_escalar\n");}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 168 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tclase: clase_vector\n");}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 169 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tclase: clase_objeto\n");}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 172 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR TOK_INHERITS identificadores '{' declaraciones funciones '}'\n");}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 173 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}'\n");}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 176 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tmodificadores_clase: \n");}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 179 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tclase_escalar: tipo\n");
					  clase_actual=ESCALAR;}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 183 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\ttipo: TOK_INT\n");}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 184 "omicron.y" /* yacc.c:1646  */
    { tipo_actual = TOK_INT;
}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 186 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\ttipo: TOK_BOOLEAN\n");}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 187 "omicron.y" /* yacc.c:1646  */
    {
	tipo_actual = TOK_BOOLEAN;
	}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 192 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tclase_objeto: '{' TOK_IDENTIFICADOR '}'\n");}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 196 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tclase_vector: TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']'\n");
			tamanio_vector_actual = (yyvsp[-1].atributos).valor_entero;
			clase_actual=VECTOR;
			if ((tamanio_vector_actual < 1) || (tamanio_vector_actual > MAX_TAMANIO_VECTOR)){
				fprintf(stderr, "Error, tamaño de vector no válido. Linea %d columna %d", row, col);
				return 0;
			}}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 205 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tidentificadores: TOK_IDENTIFICADOR\n");
									if(buscarIdNoCualificado(tabla_simbolos, (yyvsp[0].atributos).lexema,  	)==OK){
										fprintf(stderr, "Identificador %s duplicado. Linea %d columna %d\n", (yyvsp[0].atributos).lexema, row, col);
										return ERR;
									}

									}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 212 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tidentificadores: TOK_IDENTIFICADOR ',' identificadores\n");}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 215 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tfunciones: funcion funciones\n");}
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 216 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tfunciones: \n");}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 220 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tfuncion: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'\n");}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 223 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\ttipo_retorno: TOK_NONE\n");}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 224 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\ttipo_retorno: tipo\n");}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 225 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\ttipo_retorno: clase_objeto\n");}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 228 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tparametros_funcion: parametro_funcion resto_parametros_funcion\n");}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 229 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tparametros_funcion: \n");}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 232 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tresto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion\n");}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 233 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tresto_parametros_funcion: \n");}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 236 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tparametro_funcion: tipo TOK_IDENTIFICADOR\n");}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 237 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tparametro_funcion: clase_objeto TOK_IDENTIFICADOR\n");}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 240 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tdeclaraciones_funcion: declaraciones\n");}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 241 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tdeclaraciones_funcion: \n");}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 244 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencias: sentencia\n");}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 245 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencias: sentencia sentencias\n");}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 248 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencia: sentencia_simple ';'\n");}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 249 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencia: bloque\n");}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 252 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencia_simple: asignacion\n");}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 253 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencia_simple: escritura\n");}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 254 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencia_simple: lectura\n");}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 255 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencia_simple: retorno_funcion\n");}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 256 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencia_simple: identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 257 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencia_simple: TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 258 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tsentencia_simple: destruir_objeto\n");}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 261 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tdestruir_objeto: TOK_DISCARD TOK_IDENTIFICADOR\n");}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 264 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tbloque: condicional\n");}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 265 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tbloque: bucle\n");}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 269 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tasignacion: TOK_IDENTIFICADOR '=' exp\n");
			}
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 271 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tasignacion: elemento_vector '=' exp\n");}
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 272 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tasignacion: elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 273 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tasignacion: TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 274 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tasignacion: identificador_clase '.' TOK_IDENTIFICADOR '=' exp\n");}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 277 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\telemento_vector: TOK_IDENTIFICADOR '[' exp ']'\n");}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 280 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tcondicional: TOK_IF '(' exp ')' '{' sentencias '}'\n");}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 281 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tcondicional: TOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}'\n");}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 284 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tdbucle: TOK_WHILE '(' exp ')' '{' sentencias '}'\n");}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 287 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tlectura: TOK_SCANF TOK_IDENTIFICADOR\n");}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 288 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tlectura: TOK_SCANF elemento_vector\n");}
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 291 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tescritura: TOK_PRINTF exp\n");
														}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 295 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tretorno_funcion: TOK_RETURN exp\n");}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 296 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tretorno_funcion: TOK_RETURN TOK_NONE\n");}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 299 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: exp '+' exp\n");}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 300 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: exp '-' exp\n");}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 301 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: exp '/' exp\n");}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 302 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: exp '*' exp\n");}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 303 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: '-' exp\n");}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 304 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: exp TOK_AND exp\n");}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 305 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: exp TOK_OR exp\n");}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 306 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: '!' exp\n");}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 307 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: TOK_IDENTIFICADOR\n");}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 308 "omicron.y" /* yacc.c:1646  */
    {}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 309 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: constante\n");}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 310 "omicron.y" /* yacc.c:1646  */
    {}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 311 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: '(' exp ')'\n");}
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 312 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: '(' comparacion ')'\n");}
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 313 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: elemento_vector\n");}
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 314 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 315 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 316 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR\n");}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 319 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tidentificador_clase: TOK_IDENTIFICADOR\n");}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 320 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tidentificador_clase: TOK_ITSELF\n");}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 323 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tlista_expresiones: exp resto_lista_expresiones\n");}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 324 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tlista_expresiones: \n");}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 327 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tresto_lista_expresiones: ',' exp resto_lista_expresiones\n");}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 328 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tresto_lista_expresiones: \n");}
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 331 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tcomparacion: exp TOK_IGUAL exp\n");}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 332 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tcomparacion: exp TOK_DISTINTO exp\n");}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 333 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tcomparacion: exp TOK_MENORIGUAL exp\n");}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 334 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tcomparacion: exp TOK_MAYORIGUAL exp\n");}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 335 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tcomparacion: exp '<' exp\n");}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 336 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tcomparacion: exp '>' exp\n");}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 339 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tconstante: constante_logica\n");}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 340 "omicron.y" /* yacc.c:1646  */
    {}
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 341 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tconstante: constante_entera\n");}
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 342 "omicron.y" /* yacc.c:1646  */
    {}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 345 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tconstante_logica: TOK_TRUE\n");}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 346 "omicron.y" /* yacc.c:1646  */
    {}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 348 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tconstante_logica: TOK_FALSE\n");}
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 349 "omicron.y" /* yacc.c:1646  */
    {}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 352 "omicron.y" /* yacc.c:1646  */
    {fprintf(compilador_log, ";R:\tconstante_entera: TOK_CONSTANTE_ENTERA\n");}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 353 "omicron.y" /* yacc.c:1646  */
    {}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 355 "omicron.y" /* yacc.c:1646  */
    {
	escribir_subseccion_data(fout);
	escribir_cabecera_bss(fout);

}
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 361 "omicron.y" /* yacc.c:1646  */
    {

}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 365 "omicron.y" /* yacc.c:1646  */
    {
  escribir_segmento_codigo(fout);
	escribir_inicio_main(fout);
}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 370 "omicron.y" /* yacc.c:1646  */
    {
	escribir_fin(fout);
}
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2210 "y.tab.c" /* yacc.c:1646  */
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
#line 375 "omicron.y" /* yacc.c:1906  */



int yyerror (const char *s)
{
	if(error_flag == 0){
    	fprintf(stderr, "****Error sintactico en [lin %d, col %d]\n", row, col);
    }
    return 0;
}
