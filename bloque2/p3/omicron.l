%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"

	#define MAX_LONG_ID 50


	int yylex();
	FILE* yyin;
	int yyleng;
	char* yytext;

	int row = 1;
	int col = 1;
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
				strcpy(yylval.cadena,yytext);
				return TOK_NONE;}
class 		{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_CLASS;}
inherits 	{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_INHERITS;}
instance_of {	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_INSTANCE_OF;}
discard 	{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_DISCARD;}
itself 		{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_ITSELF;}
hidden 		{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_HIDDEN;}
secret 		{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_SECRET;}
exposed 	{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_EXPOSED;}
unique 		{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_UNIQUE;}


function 	{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_FUNCTION;}
return 		{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_RETURN;}
main 		{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_MAIN;}
int 		{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_INT;}
boolean 	{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_BOOLEAN;}
array 		{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_ARRAY;}	
if 			{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_IF;}
else 		{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_ELSE;}
while 		{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_WHILE;}
scanf 		{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_SCANF;}
printf 		{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_PRINTF;}

";" 			{	col += yyleng;
				return yytext[0];}
"#" 			{	col += yyleng;
				return yytext[0];}
"," 			{	col += yyleng;
				return yytext[0];}
"=" 			{	col += yyleng;
				return yytext[0];}
"(" 			{	col += yyleng;
				return yytext[0];}
")" 			{	col += yyleng;
				return yytext[0];}
"[" 			{	col += yyleng;
				return yytext[0];}
"]" 			{	col += yyleng;
				return yytext[0];}
"{" 			{	col += yyleng;
				return yytext[0];}
"}" 			{	col += yyleng;
				return yytext[0];}
":" 			{	col += yyleng;
				return yytext[0];}
"+" 			{	col += yyleng;
				return yytext[0];}
"-" 			{	col += yyleng;
				return yytext[0];}
"/" 			{	col += yyleng;
				return yytext[0];}
"*" 			{	col += yyleng;
				return yytext[0];}
"<" 			{	col += yyleng;
				return yytext[0];}
">" 			{	col += yyleng;
				return yytext[0];}
"&" 			{	col += yyleng;
				return yytext[0];}
"!" 			{	col += yyleng;
				return yytext[0];}
"." 			{	col += yyleng;
				return yytext[0];}
"==" 			{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_IGUAL;}
"!=" 			{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_DISTINTO;}
"<="			{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_MENORIGUAL;}
">=" 			{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_MAYORIGUAL;}
"||"			{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_OR;}
"&&" 			{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_AND;}
"->" 			{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_FLECHA;}
false 		{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_FALSE;}
true 		{	col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_TRUE;}

{IDENTIFICADOR} {	if(yyleng <= MAX_LONG_ID){
						col += yyleng;
						strcpy(yylval.cadena,yytext);
						return TOK_IDENTIFICADOR;
					}
					
					fprintf(stderr, "ERROR IDENTIFICADOR DEMASIADO LARGO: Linea %d y columna %d\n", row, col);
					col += yyleng;
					return TOK_ERROR;
				}

{ENTERO}		{	col += yyleng;
					yylval.numero = atoi(yytext);
					return TOK_CONSTANTE_ENTERA;}

{COMENTARIO} 	{	row ++;
					col = 1;}

{BLANCO}+		{	col += yyleng;}	

{SALTO}			{	row++;
					col = 1;}

{ERROR} 	{	
				fprintf(stderr, "ERROR: Linea %d y columna %d. Provocado por: %s\n", row, col, yytext);
				col += yyleng;
				strcpy(yylval.cadena,yytext);
				return TOK_ERROR;}

%%
