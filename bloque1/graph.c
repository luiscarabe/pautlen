// Implementation of a graph using an adjacency matrix

#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

#define NREALLOC 64

typedef struct _Graph {
	int n; // number of nodes
	int allocated;
	Node **nodes; // nodes of the graph
	char **amatrix; // adjacency matrix
} Graph;


int buildMatrix(ph *graph){
	int i, j;

	graph->amatrix = (char **) malloc(NREALLOC*sizeof(char*));
	if (!graph->amatrix) return -1;

	for (i = 0; i < NREALLOC; i++){
		graph->amatrix[i] = (char *) malloc(NREALLOC*sizeof(char));
		if (!graph->amatrix[i]){
			for (i--; i >= 0; i--) free(graph->amatrix[j]);
			free(graph->amatrix);
			return -1;
		}

		for (j = 0; j < NREALLOC; j++){
			graph->amatrix[i][j] = 0;
		}
	}

	return 0;
}

void deleteMatrix(Graph *graph){
	int i;

	for (i = 0; i < graph->n; i++) free(graph->amatrix[i]);
	free(graph->amatrix);
}

int reallocate(Graph *graph) {
	int i;

	if (!graph) return -1;

	graph-> allocated += NREALLOC;
	graph->amatrix = realloc(graph->amatrix, graph->allocated);
	for (i = 0; i < graph->allocated +)
}


Graph *newGraph(){
	int i;
	Graph *newGraph;

	newGraph = (Graph *) malloc(sizeof(Graph));
	if (!newGraph) return NULL;

	newGraph->n = 0;
	newGraph->allocated = NREALLOC;

	if (buildMatrix(newGraph) == -1){
		free(newGraph);
		return NULL;
	}

	newGraph->nodes = (Node **) malloc(NREALLOC*sizeof(Node*));
	if (!newGraph->nodes){
		deleteMatrix(newGraph);
		free(newGraph);
		return NULL;
	}

	return newGraph;
}

int addNode(Graph *graph, Node *node){
	Node *n;

	if (graph->n >= graph->allocated)
		if (reallocate(graph) == -1)
			return -1;

	n = cloneNode(node);
	if (!n) return -1;

	graph->nodes[graph->n] = n;
}

void addEdge(Graph *graph, int src_node, int dst_node){
	if (!graph) return;
	if (src_node < 0 | dst_node < 0 | src_node >= graph->n | dst_node >= graph->n) return;
	graph->amatrix[src_node][dst_node] = 1;
}

void addSymmetricalEdge(Graph *graph, int node_a, int node_b){
	addEdge(graph, node_a, node_b);
	addEdge(graph, node_b, node_a);
}

void removeEdge(Graph *graph, int src_node, int dst_node){
	if (!graph) return;
	if (src_node < 0 | dst_node < 0 | src_node >= graph->n | dst_node >= graph->n) return;
	graph->amatrix[src_node][dst_node] = 0;
}

void removeSymmetricalEdge(Graph *graph, int node_a, int node_b){
	removeEdge(graph, node_a, node_b);
	removeEdge(graph, node_b, node_a);
}

void deleteGraph(Graph *graph){
	int i;

	if (!graph) return;

	for (i = 0; i < graph->n; i++) deleteNode(graph->nodes[i]);
	free(graph->nodes);
	//deleteMatrix(graph);
	for (i = 0; i < graph->n; i++) free(graph->amatrix[i]);
	free(graph->amatrix);
	free(graph);
}

void printGraph(Graph *graph){
	int i, j;

	for (i = 0; i < graph->n; i++){
		printf("N%d: ", i);
		printNode(graph->nodes[i]);
		printf("\n");
	}
	printf("\n ");

	for (i = 0; i < graph->n; i++)
		printf("\t%d", i);
	printf("\n");

	for (i = 0; i < graph->n; i++){
		printf("%d", i);
		for (j = 0; j < graph->n; j++)
			printf("\t%d", graph->amatrix[i][j]);
		printf("\n");
	}
	printf("\n");
}