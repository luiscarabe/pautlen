#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "node.h"
#include "hash_table.h"

int main(int argc, char const *argv[]){
	
	Graph *g;
	HT_item *item;
	char *name = (char *) malloc(sizeof(char)*64);

	iniciarTablaSimbolosClases(&g, "Supergrafo");

	abrirClase(g, "A");
	printf("Graph:\n");
	printGraph(g);

	insertarTablaSimbolosClases(g, "A", VARIABLE, "a", ESCALAR, 
															INT, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, NINGUNO,
															MIEMBRO_NO_UNICO, 0, 0, 0, 0, NULL);

	insertarTablaSimbolosClases(g, "A", ATRIBUTO_INSTANCIA, "Ainstancia", ESCALAR, 
															INT, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, NINGUNO,
															MIEMBRO_NO_UNICO, 0, 0, 0, 0, NULL);
	
	insertarTablaSimbolosClases(g, "A", ATRIBUTO_CLASE, "Aclase", ESCALAR, 
															INT, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, NINGUNO,
															MIEMBRO_NO_UNICO, 0, 0, 0, 0, NULL);

	abrirClase(g, "B");
	printf("Graph:\n");
	printGraph(g);

	insertarTablaSimbolosClases(g, "B", VARIABLE, "b", ESCALAR, 
															INT, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, NINGUNO,
															MIEMBRO_NO_UNICO, 0, 0, 0, 0, NULL);

	abrirClase(g, "C");
	printf("Graph:\n");
	printGraph(g);
	insertarTablaSimbolosClases(g, "C", VARIABLE, "c", ESCALAR, 
															INT, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, NINGUNO,
															MIEMBRO_NO_UNICO, 0, 0, 0, 0, NULL);

	abrirClase(g, "D");
	printf("Graph:\n");
	printGraph(g);

	insertarTablaSimbolosClases(g, "D", VARIABLE, "d", ESCALAR, 
															INT, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, NINGUNO,
															MIEMBRO_NO_UNICO, 0, 0, 0, 0, NULL);

	insertarTablaSimbolosClases(g, "D", ATRIBUTO_INSTANCIA, "Dinstancia", ESCALAR, 
															INT, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, NINGUNO,
															MIEMBRO_NO_UNICO, 0, 0, 0, 0, NULL);


	abrirClaseHereda(g, "ABC", "B", "A", "C", NULL);
	printf("Graph:\n");
	printGraph(g);

	insertarTablaSimbolosClases(g, "ABC", VARIABLE, "abc", ESCALAR, 
															INT, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, NINGUNO,
															MIEMBRO_NO_UNICO, 0, 0, 0, 0, NULL);


	abrirClaseHereda(g, "ABCD", "ABC", "D", NULL);
	printf("Graph:\n");
	printGraph(g);

	insertarTablaSimbolosClases(g, "ABCD", VARIABLE, "abcd", ESCALAR, 
															INT, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, NINGUNO,
															MIEMBRO_NO_UNICO, 0, 0, 0, 0, NULL);

	tablaSimbolosClasesAbrirAmbitoEnClase(g, "ABCD", "funcabcd", METODO_SOBREESCRIBIBLE, 
											NINGUNO, INT, 2, 8);

	if (buscarIdNoCualificado(g, "funcabcd", "ABCD", &item, name) == -1)
		printf("No se encuentra \n");
	else printf("%s\n", name);

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "ABCD");

	abrirClaseHereda(g, "E", "ABCD", "D", NULL);
	printf("Graph:\n");
	printGraph(g);

	insertarTablaSimbolosClases(g, "E", VARIABLE, "e", ESCALAR, 
															INT, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, NINGUNO,
															MIEMBRO_NO_UNICO, 0, 0, 0, 0, NULL);

	tablaSimbolosClasesToDot(g);

	imprimirTablasHash(g);
	
	buscarIdNoCualificado(g, "e", "E", &item, name);
	printf("%s\n", name);

	buscarIdNoCualificado(g, "Aclase", "E", &item, name);
	printf("%s\n", name);
	
	free(name);
	deleteGraph(g);

	return 0;
}