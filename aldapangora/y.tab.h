/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 42 "omicron.y" /* yacc.c:1909  */


	tipo_atributos atributos;


#line 128 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
