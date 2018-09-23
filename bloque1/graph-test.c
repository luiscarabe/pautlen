#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "node.h"

int main(int argc, char const *argv[]){
	int i;
	Node *n[3];
	Graph *g;

	n[0] = newNode("Node 0");
	n[1] = newNode("Node 1");
	n[2] = newNode("Node 2");

	printf("Nodes:\n");
	for (i = 0; i < 3; ++i){
		printf("N%d: ", i);
		printNode(n[i]);
		printf("\n");
	}
	printf("\n");

	g = newGraph(3, n);
	printf("Graph:\n");
	printGraph(g);

	addEdge(g, 0, 1);
	addEdge(g, 0, 2);
	addEdge(g, 1, 0);
	addEdge(g, 2, 1);

	printf("Graph:\n");
	printGraph(g);

	removeEdge(g, 2, 1);
	removeEdge(g, 1, 0);

	printf("Graph:\n");
	printGraph(g);

	addSymmetricalEdge(g, 1, 2);

	printf("Graph:\n");
	printGraph(g);


	for (i = 0; i < 3; ++i){
		deleteNode(n[i]);
	}

	deleteGraph(g);

	return 0;
}