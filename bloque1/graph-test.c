#include <stdlib.h>
#include <stdio.h>

#include "graph.h"

int main(int argc, char const *argv[]){
	Graph *g;
	
	g = newGraph();

	if (addNode(g, "Node 0", (void *)0) == -1){
		printf("Something went wrong\n");
		return -1;
	}
	if (addNode(g, "Node 1", (void *)1) == -1){
		printf("Something went wrong\n");
		return -1;
	}
	if (addNode(g, "Node 2", (void *)2) == -1){
		printf("Something went wrong\n");
		return -1;
	}

	printf("Graph:\n");
	printGraph(g);

	addEdge(g, 0, 1);
	printGraph(g);

	addEdge(g, 0, 2);
	printGraph(g);

	addEdge(g, 1, 0);
	printGraph(g);

	addEdge(g, 2, 1);	

	printf("Graph:\n");
	printGraph(g);

	addSymmetricalEdge(g, 1, 2);

	printf("Graph:\n");
	printGraph(g);

	printf("Content of node 0: ");
	printf("%p\n", getContentOfNode(g, "Node 0"));

	printf("\n\nContent of node 1: ");
	printf("\n%p\n", getContentOfNode(g, "Node 1"));
	
	printf("\n\nContent of node 2: ");
	printf("\n%p\n", getContentOfNode(g, "Node 2"));

	deleteGraph(g);

	return 0;
}