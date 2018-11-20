#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "symbols.h"
#include "node.h"
#include "hash_table.h"

int main(int argc, char const *argv[]){
	Graph *g;
	HT_item *item;
	int status;


	iniciarTablaSimbolosClases(&g, "Menudotestazo");

	// Caso 54
	status = buscarParaDeclararIdTablaSimbolosAmbitos(g, "main_v1", &item, "main");
	printf("Caso 54: Declarar variable no declarada %s\n", status == ERR ? " \tCORRECTO" : "\n\tINCORRECTO");

	insertarTablaSimbolosMain(g, VARIABLE, "main_v1", ESCALAR,
								INT, 0, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL); 

	// Caso 57
	status = buscarParaDeclararIdTablaSimbolosAmbitos(g, "main_v1", &item, "main");
	printf("Caso 57: Declarar variable ya declarada %s\n", status == OK ? " \tCORRECTO" : "\n\tINCORRECTO");

	// Caso 55
	status = buscarParaDeclararIdTablaSimbolosAmbitos(g, "main_f1@1", &item, "main");
	printf("Caso 55: Declarar funcion no declarada %s\n", status == ERR ? " \tCORRECTO" : "\n\tINCORRECTO");

	int tipos1[1] = {INT};
	tablaSimbolosClasesAbrirAmbitoEnMain(g, "main_f1@1", FUNCION, NINGUNO,
										INT, 0, 0, 1, tipos1);

	// Caso 56
	status = buscarParaDeclararIdTablaSimbolosAmbitos(g, "f1@1_p1", &item, "main");
	printf("Caso 56: Declarar parametro no declarado %s\n", status == ERR ? " \tCORRECTO" : "\n\tINCORRECTO");

	insertarTablaSimbolosMain(g, PARAMETRO, "f1@1_p1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	tablaSimbolosClasesCerrarAmbitoEnMain(g);

	// Caso 58
	status = buscarParaDeclararIdTablaSimbolosAmbitos(g, "main_f1@1", &item, "main");
	printf("Caso 58: Declarar funcion ya declarada %s\n", status == OK ? " \tCORRECTO" : "\n\tINCORRECTO");

	int tipos2[2] = {INT, INT};
	tablaSimbolosClasesAbrirAmbitoEnMain(g, "main_f2@1@1", FUNCION, NINGUNO,
										INT, 0, 0, 2, tipos2);

	insertarTablaSimbolosMain(g, PARAMETRO, "f2@1@1_p1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	// Caso 59
	status = buscarParaDeclararIdTablaSimbolosAmbitos(g, "f2@1@1_p1", &item, "main");
	printf("Caso 59: Declarar parametro ya declarado %s\n", status == OK ? " \tCORRECTO" : "\n\tINCORRECTO");

	tablaSimbolosClasesCerrarAmbitoEnMain(g);

	deleteGraph(g);


	return 0;
}