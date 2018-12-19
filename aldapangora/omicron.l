%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "omicron.h"
	#include "y.tab.h"

	#define MAX_LONG_ID 50

	/* Del main*/
	extern FILE* compilador_log;
	extern FILE* yyin;

	int yylex();
	int yyleng;
	char* yytext;

	int row = 1;
	int col = 1;
	int error_flag = 0;
%}

%option noyywrap

DIGITO [0-9]
ENTERO {DIGITO}+
LETRAS [a-zA-Z]
BLANCO [ \t]
SALTO \n
COMENTARIO "//".*\n
ERROR .
IDENTIFICADOR ([a-z]|[A-Z])([a-z]|[A-Z]|[0-9])*

%%

none 		{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_NONE;}
class 		{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_CLASS;}
inherits 	{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_INHERITS;}
instance_of {	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_INSTANCE_OF;}
discard 	{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_DISCARD;}
itself 		{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_ITSELF;}
hidden 		{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_HIDDEN;}
secret 		{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_SECRET;}
exposed 	{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_EXPOSED;}
unique 		{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_UNIQUE;}


function 	{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_FUNCTION;}
return 		{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_RETURN;}
main 		{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_MAIN;}
int 		{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_INT;}
boolean 	{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_BOOLEAN;}
array 		{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_ARRAY;}
if 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_IF;}
else 		{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_ELSE;}
while 		{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_WHILE;}
scanf 		{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_SCANF;}
printf 		{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_PRINTF;}

";" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return yytext[0];}
"#" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return yytext[0];}
"," 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return yytext[0];}
"=" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return yytext[0];}
"(" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return yytext[0];}
")" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return yytext[0];}
"[" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return yytext[0];}
"]" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return yytext[0];}
"{" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return yytext[0];}
"}" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return yytext[0];}
":" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return yytext[0];}
"+" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return yytext[0];}
"-" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return yytext[0];}
"/" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return yytext[0];}
"*" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return yytext[0];}
"<" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return yytext[0];}
">" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return yytext[0];}
"&" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return yytext[0];}
"!" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return yytext[0];}
"." 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return yytext[0];}
"==" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_IGUAL;}
"!=" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_DISTINTO;}
"<="			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_MENORIGUAL;}
">=" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_MAYORIGUAL;}
"||"			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_OR;}
"&&" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_AND;}
"->" 			{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_FLECHA;}


false 		{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_FALSE;}
true 		{	col += yyleng;
				fprintf(compilador_log, ";D:\t%s\n", yytext);
				return TOK_TRUE;}

{IDENTIFICADOR} {	if(yyleng <= MAX_LONG_ID){
						col += yyleng;
						fprintf(compilador_log, ";D:\t%s\n", yytext);
						strcpy(yylval.atributos.lexema,yytext);
						return TOK_IDENTIFICADOR;
					}

					fprintf(stderr, "ERROR IDENTIFICADOR DEMASIADO LARGO: Linea %d y columna %d\n", row, col);
					col += yyleng;
					error_flag = 1;
					return TOK_ERROR;
				}

{ENTERO}		{	col += yyleng;
					fprintf(compilador_log, ";D:\t%s\n", yytext);
					yylval.atributos.valor_entero = atoi(yytext);
					return TOK_CONSTANTE_ENTERA;}

{COMENTARIO} 	{	row ++;
					col = 1;}

{BLANCO}+		{	col += yyleng;}

{SALTO}			{	row++;
					col = 1;}

{ERROR} 	{
				fprintf(stderr, "****Error morfologico en [lin %d, col %d]: simbolo no permitido (%s)\n", row, col, yytext);
				error_flag = 1;
				return TOK_ERROR;}

%%
