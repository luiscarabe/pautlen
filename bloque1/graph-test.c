#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "node.h"
#include "hash_table.h"

int main(int argc, char const *argv[]){
	
	// g = newGraph();

	// if (addNode(g, "Node 0", (void *)0) == -1){
	// 	printf("Something went wrong\n");
	// 	return -1;
	// }
	// if (addNode(g, "Node 1", (void *)1) == -1){
	// 	printf("Something went wrong\n");
	// 	return -1;
	// }
	// if (addNode(g, "Node 2", (void *)2) == -1){
	// 	printf("Something went wrong\n");
	// 	return -1;
	// }

	// if (addNode(g, "Node 3", (void *)3) == -1){
	// 	printf("Something went wrong\n");
	// 	return -1;
	// }

	// printf("Graph:\n");
	// printGraph(g);

	// addParent(g, 0, 1);
	// printGraph(g);

	// addParent(g, 0, 2);
	// printGraph(g);

	// addParent(g, 1, 0);
	// printGraph(g);

	// addParent(g, 2, 1);	

	// printf("Graph:\n");
	// printGraph(g);

	// addParent(g, 2, 3);	

	// printf("Graph:\n");
	// printGraph(g);


	// printf("Content of node 0: ");
	// printf("%p\n", getContentOfNode(g, "Node 0"));

	// printf("\n\nContent of node 1: ");
	// printf("\n%p\n", getContentOfNode(g, "Node 1"));
	
	// printf("\n\nContent of node 2: ");
	// printf("\n%p\n", getContentOfNode(g, "Node 2"));

	Graph *g;

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

	abrirClaseHereda(g, "E", "ABCD", "D", NULL);
	printf("Graph:\n");
	printGraph(g);

	insertarTablaSimbolosClases(g, "E", VARIABLE, "e", ESCALAR, 
															INT, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, NINGUNO,
															MIEMBRO_NO_UNICO, 0, 0, 0, 0, NULL);


	tablaSimbolosClasesToDot(g);

	imprimirTablasHash(g);

	deleteGraph(g);

	return 0;
}