// Implementation of a graph using an adjacency matrix

#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "node.h"

#define NREALLOC 64

typedef struct _Graph {
	int n; // number of nodes
	int allocated; // number of potential nodes with memory already allocated
	Node **nodes; // nodes of the graph
	char **amatrix; // adjacency matrix
} Graph;


int buildMatrix(Graph *graph){
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

int reallocate(Graph *graph) {
	int i, j;

	if (!graph) return -1;

	graph->nodes = (Node **) realloc(graph->nodes, (graph->allocated + NREALLOC) * sizeof(Node *));

	graph->amatrix = (char **) realloc(graph->amatrix, (graph->allocated + NREALLOC) * sizeof(char *));
	for (i = 0; i < graph->allocated; i++){
		graph->amatrix[i] = (char *) realloc(graph->amatrix[i], (graph->allocated + NREALLOC) * sizeof(char));
		for (j = 0; j < NREALLOC; j++){
			graph->amatrix[i][j] = 0;
		}
	}
	for (; i < NREALLOC; i++){
		graph->amatrix[i] = (char *) malloc((graph->allocated + NREALLOC) * sizeof(char));
		if (!graph->amatrix[i]){
			for (i--; i >= graph->allocated; i--) free(graph->amatrix[i]);
			for (i--; i >= 0; i--) graph->amatrix[i] = (char *) realloc(graph->amatrix[i], graph->allocated * sizeof(char));
			graph->amatrix = (char **) realloc(graph->amatrix, graph->allocated * sizeof(char));
			graph->nodes = (Node **) realloc(graph->nodes, graph->allocated * sizeof(Node *));
			return -1;
		}
		for (j = 0; j < graph->allocated + NREALLOC; j++){
			graph->amatrix[i][j] = 0;
		}
	}

	graph->allocated += NREALLOC;

	return 0;
}

int indexOf(Graph *graph, char *name){
	int i;

	if (!graph | !name) return -1;

	for (i = 0; i < graph->n; i++){
		if (nameCompare(graph->nodes[i], name) == 0)
			return i;
	}
	return -1;
}


Graph *newGraph(){
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
		free(newGraph);
		return NULL;
	}

	return newGraph;
}

int addNode(Graph *graph, char *node_name, void *content){
	Node *n;

	n = newNode(node_name, content);
	if (!n) return -1;

	if (graph->n >= graph->allocated){
		if (reallocate(graph) == -1){
			deleteNode(n);
			return -1;
		}
	}

	graph->nodes[graph->n] = n;
	graph->n++;

	return 0;
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

void *getContentOfNode(Graph *graph, char *node_name){
	int i;

	if (!graph | !node_name) return NULL;

	i = indexOf(graph, node_name);
	if (i == -1) return NULL;

	return getContent(graph->nodes[i]);
}

void deleteGraph(Graph *graph){
	int i;

	if (!graph) return;

	for (i = 0; i < graph->n; i++) deleteNode(graph->nodes[i]);
	free(graph->nodes);

	for (i = 0; i < graph->allocated; i++) free(graph->amatrix[i]);
	free(graph->amatrix);
	free(graph);
}

void printGraph(Graph *graph){
	int i, j;

	for (i = 0; i < graph->n; i++){
		printf("N%d: ", i);
		printf("\n\t");
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