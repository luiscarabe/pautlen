/*
Asignatura: PAUTLEN
Bloque: Procedural
Modulo: pruebaMorfo.c

Grupo 5: Alejandro Cabana, Luis Cárabe, Emilio Cuesta, Blanca Martín, Pablo Alejo Polanía

*/

#include <stdio.h>
#include <stdlib.h>
#include "y.tab.c"

extern FILE* yyin;
FILE* fout;

int main(int argc, char** argv){

	int ret;

	if (argc != 3){
		fprintf(stderr, "Por favor, inserta por argumento el fichero de entrada y de salida.\n");
		return 1;
	}

	yyin = fopen(argv[1], "r");
	if (!yyin){
		fprintf(stderr, "Fichero de entrada inválido.\n");
		return 1;
	}

	fout = fopen(argv[2], "w");
	if (!fout){
		fprintf(stderr, "Fichero de salida inválido.\n");
		fclose(yyin);
		return 1;
	}

	ret = yyparse();

	if(ret != 0){
		fprintf(stderr, "****Error gramatical\n");
	}


	fclose(yyin);
	fclose(fout);

	return 0;
}
