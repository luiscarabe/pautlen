#include <stdlib.h>
#include <stdio.h>

#include "graph.h"

int main(int argc, char const *argv[]){
	Graph *g;

	g = newGraph();

	addNode(g, "Node 0", (void *)0);
	addNode(g, "Node 1", (void *)1);
	addNode(g, "Node 2", (void *)2);

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

	printf("Content of node 0: ");
	printf("%p\n", getContentOfNode(g, "Node 0"));
	printf("Content of node 1: ");
	printf("%p\n", getContentOfNode(g, "Node 1"));
	printf("Content of node 2: ");
	printf("%p\n", getContentOfNode(g, "Node 2"));

	deleteGraph(g);

	return 0;
}