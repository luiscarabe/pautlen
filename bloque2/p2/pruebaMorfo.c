#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
#include "lex.yy.c"

extern int row;
extern int col;
extern int yylex();
extern FILE* yyin;
extern FILE* fout;
extern int yyleng;
extern char* yytext;

int main(int argc, char** argv){

	int ret;

	if (argc != 3){
		printf("Por favor, inserta por argumento el fichero de entrada y de salida.\n");
		return 1;
	}

	yyin = fopen(argv[1], "r");

	if (!yyin){
		printf("Fichero de entrada inválido.\n");
		return 1;
	}

	fout = fopen(argv[2], "w");

	if (!fout){
		printf("Fichero de salida inválido.\n");
		fclose(yyin);
		return 1;
	}

	ret = yylex();

	while(ret){
		switch(ret){
			case TOK_NONE:
				fprintf(fout, "TOK_NONE\t%d\t%s\n", TOK_NONE, yytext);
			break;

			case TOK_CLASS:
				fprintf(fout, "TOK_CLASS\t%d\t%s\n", TOK_CLASS, yytext);
			break;

			case TOK_INHERITS:
				fprintf(fout, "TOK_INHERITS\t%d\t%s\n", TOK_INHERITS, yytext);
			break;

			case TOK_INSTANCE_OF:
				fprintf(fout, "TOK_INSTANCE_OF\t%d\t%s\n", TOK_INSTANCE_OF, yytext);
			break;

			case TOK_DISCARD:
				fprintf(fout, "TOK_DISCARD\t%d\t%s\n", TOK_DISCARD, yytext);
			break;

			case TOK_ITSELF:
				fprintf(fout, "TOK_ITSELF\t%d\t%s\n", TOK_ITSELF, yytext);
			break;

			case TOK_FLECHA:
				fprintf(fout, "TOK_FLECHA\t%d\t%s\n", TOK_FLECHA, yytext);
			break;

			case TOK_HIDDEN:
				fprintf(fout, "TOK_HIDDEN\t%d\t%s\n", TOK_HIDDEN, yytext);
			break;

			case TOK_SECRET:
				fprintf(fout, "TOK_SECRET\t%d\t%s\n", TOK_SECRET, yytext);
			break;

			case TOK_EXPOSED:
				fprintf(fout, "TOK_EXPOSED\t%d\t%s\n", TOK_EXPOSED, yytext);
			break;

			case TOK_UNIQUE:
				fprintf(fout, "TOK_UNIQUE\t%d\t%s\n", TOK_UNIQUE, yytext);
			break;

			case TOK_FUNCTION:
				fprintf(fout, "TOK_FUNCTION\t%d\t%s\n", TOK_FUNCTION, yytext);
			break;

			case TOK_RETURN:
				fprintf(fout, "TOK_RETURN\t%d\t%s\n", TOK_RETURN, yytext);
			break;

			case TOK_MAIN:
				fprintf(fout, "TOK_MAIN\t%d\t%s\n", TOK_MAIN, yytext);
			break;

			case TOK_INT:
				fprintf(fout, "TOK_INT\t%d\t%s\n", TOK_INT, yytext);
			break;

			case TOK_BOOLEAN:
				fprintf(fout, "TOK_BOOLEAN\t%d\t%s\n", TOK_BOOLEAN, yytext);
			break;

			case TOK_ARRAY:
				fprintf(fout, "TOK_ARRAY\t%d\t%s\n", TOK_ARRAY, yytext);
			break;

			case TOK_IF:
				fprintf(fout, "TOK_IF\t%d\t%s\n", TOK_IF, yytext);
			break;

			case TOK_ELSE:
				fprintf(fout, "TOK_ELSE\t%d\t%s\n", TOK_ELSE, yytext);
			break;

			case TOK_WHILE:
				fprintf(fout, "TOK_WHILE\t%d\t%s\n", TOK_WHILE, yytext);
			break;

			case TOK_SCANF:
				fprintf(fout, "TOK_SCANF\t%d\t%s\n", TOK_SCANF, yytext);
			break;

			case TOK_PRINTF:
				fprintf(fout, "TOK_PRINTF\t%d\t%s\n", TOK_PRINTF, yytext);
			break;

			case TOK_IDENTIFICADOR:
				fprintf(fout, "TOK_IDENTIFICADOR\t%d\t%s\n", TOK_IDENTIFICADOR, yytext);
			break;

			case TOK_IGUAL:
				fprintf(fout, "TOK_IGUAL\t%d\t%s\n", TOK_IGUAL, yytext);
			break;

			case TOK_DISTINTO:
				fprintf(fout, "TOK_DISTINTO\t%d\t%s\n", TOK_DISTINTO, yytext);
			break;

			case TOK_MENORIGUAL:
				fprintf(fout, "TOK_MENORIGUAL\t%d\t%s\n", TOK_MENORIGUAL, yytext);
			break;

			case TOK_MAYORIGUAL:
				fprintf(fout, "TOK_MAYORIGUAL\t%d\t%s\n", TOK_MAYORIGUAL, yytext);
			break;

			case TOK_OR:
				fprintf(fout, "TOK_OR\t%d\t%s\n", TOK_OR, yytext);
			break;

			case TOK_AND:
				fprintf(fout, "TOK_AND\t%d\t%s\n", TOK_AND, yytext);
			break;

			case TOK_CONSTANTE_ENTERA:
				fprintf(fout, "TOK_CONSTANTE_ENTERA\t%d\t%s\n", TOK_CONSTANTE_ENTERA, yytext);
			break;

			case TOK_FALSE:
				fprintf(fout, "TOK_FALSE\t%d\t%s\n", TOK_FALSE, yytext);
			break;

			case TOK_TRUE:
				fprintf(fout, "TOK_TRUE\t%d\t%s\n", TOK_TRUE, yytext);
			break;

			case TOK_FOR:
				fprintf(fout, "TOK_FOR\t%d\t%s\n", TOK_FOR, yytext);
			break;

			case TOK_SWITCH:
				fprintf(fout, "TOK_SWITCH\t%d\t%s\n", TOK_SWITCH, yytext);
			break;

			case TOK_CASE:
				fprintf(fout, "TOK_CASE\t%d\t%s\n", TOK_CASE, yytext);
			break;

			case TOK_DEFAULT:
				fprintf(fout, "TOK_DEFAULT\t%d\t%s\n", TOK_DEFAULT, yytext);
			break;

			case TOK_FLOAT:
				fprintf(fout, "TOK_FLOAT\t%d\t%s\n", TOK_FLOAT, yytext);
			break;

			case TOK_MALLOC:
				fprintf(fout, "TOK_MALLOC\t%d\t%s\n", TOK_MALLOC, yytext);
			break;

			case TOK_CPRINTF:
				fprintf(fout, "TOK_CPRINTF\t%d\t%s\n", TOK_CPRINTF, yytext);
			break;

			case TOK_ERROR:
				fprintf(fout, "TOK_ERROR\t%d\t%s\n", TOK_ERROR, yytext);
			break;

			case TOK_FREE:
				fprintf(fout, "TOK_FREE\t%d\t%s\n", TOK_FREE, yytext);
			break;

			case TOK_SET:
				fprintf(fout, "TOK_SET\t%d\t%s\n", TOK_SET, yytext);
			break;

			case TOK_OF:
				fprintf(fout, "TOK_OF\t%d\t%s\n", TOK_OF, yytext);
			break;

			case TOK_UNION:
				fprintf(fout, "TOK_UNION\t%d\t%s\n", TOK_UNION, yytext);
			break;

			case TOK_INTERSECTION:
				fprintf(fout, "TOK_INTERSECTION\t%d\t%s\n", TOK_INTERSECTION, yytext);
			break;

			case TOK_ADD:
				fprintf(fout, "TOK_ADD\t%d\t%s\n", TOK_ADD, yytext);
			break;

			case TOK_SIZE:
				fprintf(fout, "TOK_SIZE\t%d\t%s\n", TOK_SIZE, yytext);
			break;

			case TOK_CLEAR:
				fprintf(fout, "TOK_CLEAR\t%d\t%s\n", TOK_CLEAR, yytext);
			break;

			case TOK_CONTAINS:
				fprintf(fout, "TOK_CONTAINS\t%d\t%s\n", TOK_CONTAINS, yytext);
			break;

			case TOK_CONSTANTE_REAL:
				fprintf(fout, "TOK_CONSTANTE_REAL\t%d\t%s\n", TOK_CONSTANTE_REAL, yytext);
			break;

			default:
				fprintf(fout, "SIMBOLO SIMPLE\t%d\t%s\n", ret, yytext);

		}
		ret = yylex();
	}

	fclose(yyin);
	fclose(fout);

	return 0;
}