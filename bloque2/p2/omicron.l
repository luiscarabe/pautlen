%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "tokens.h"


	int yylex();
	FILE* yyin;
	FILE* fout;
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
				return TOK_NONE;}
class 		{	col += yyleng;
				return TOK_CLASS;}
inherits 	{	col += yyleng;
				return TOK_INHERITS;}
instance_of {	col += yyleng;
				return TOK_INSTANCE_OF;}
discard 	{	col += yyleng;
				return TOK_DISCARD;}
itself 		{	col += yyleng;
				return TOK_ITSELF;}
hidden 		{	col += yyleng;
				return TOK_HIDDEN;}
secret 		{	col += yyleng;
				return TOK_SECRET;}
exposed 	{	col += yyleng;
				return TOK_EXPOSED;}
unique 		{	col += yyleng;
				return TOK_UNIQUE;}


function 	{	col += yyleng;
				return TOK_FUNCTION;}
return 		{	col += yyleng;
				return TOK_RETURN;}
main 		{	col += yyleng;
				return TOK_MAIN;}
int 		{	col += yyleng;
				return TOK_INT;}
boolean 	{	col += yyleng;
				return TOK_BOOLEAN;}
array 		{	col += yyleng;
				return TOK_ARRAY;}	
if 			{	col += yyleng;
				return TOK_IF;}
else 		{	col += yyleng;
				return TOK_ELSE;}
while 		{	col += yyleng;
				return TOK_WHILE;}
scanf 		{	col += yyleng;
				return TOK_SCANF;}
printf 		{	col += yyleng;
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
				return TOK_IGUAL;}
"!=" 			{	col += yyleng;
				return TOK_DISTINTO;}
"<="			{	col += yyleng;
				return TOK_MENORIGUAL;}
">=" 			{	col += yyleng;
				return TOK_MAYORIGUAL;}
"||"			{	col += yyleng;
				return TOK_OR;}
"&&" 			{	col += yyleng;
				return TOK_AND;}
"->" 			{	col += yyleng;
				return TOK_FLECHA;}
false 		{	col += yyleng;
				return TOK_FALSE;}
true 		{	col += yyleng;
				return TOK_TRUE;}

{IDENTIFICADOR} {	if(yyleng <= 50){
						col += yyleng;
						return TOK_IDENTIFICADOR;
					}
					fprintf(stderr, "ERROR IDENTIFICADOR DEMASIADO LARGO: Linea %d y columna %d\n", row, col);
					return TOK_ERROR;
				}

{ENTERO}		{	col += yyleng;
					return TOK_CONSTANTE_ENTERA;}

{COMENTARIO} 	{	row ++; 
					col = 0;}

{BLANCO}+		{	col += yyleng;}	

{SALTO}			{	row++;
					col = 0;}

{ERROR} 	{	fprintf(stderr, "ERROR: Linea %d y columna %d. Provocado por: %s\n", row, col, yytext);
				return TOK_ERROR;}

%%
