// Implementation of a graph using an adjacency matrix

#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

typedef struct _Graph {
	int n; // number of nodes
	Node **nodes; // nodes of the graph
	char **amatrix; // adjacency matrix
} Graph;


int buildMatrix(int n, Graph *graph){
	int i, j;

	graph->amatrix = (char **) malloc(n*sizeof(char*));
	if (!graph->amatrix) return -1;

	for (i = 0; i < n; i++){
		graph->amatrix[i] = (char *) malloc(n*sizeof(char));
		if (!graph->amatrix[i]){
			for (i--; i >= 0; i--) free(graph->amatrix[j]);
			free(graph->amatrix);
			return -1;
		}

		for (j = 0; j < n; j++){
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

Graph *newGraph(int n, Node **nodes){
	int i;
	Graph *newGraph;

	if (n < 0 | !nodes) return NULL;

	newGraph = (Graph *) malloc(sizeof(Graph));
	if (!newGraph) return NULL;

	newGraph->n = n;

	if (buildMatrix(n, newGraph) == -1){
		free(newGraph);
		return NULL;
	}

	newGraph->nodes = (Node **) malloc(n*sizeof(Node*));
	if (!newGraph->nodes){
		deleteMatrix(newGraph);
		free(newGraph);
		return NULL;
	}

	for (i = 0; i < n; i++){
		newGraph->nodes[i] = cloneNode(nodes[i]);
		if (!newGraph->nodes[i]){
			for (i--; i >= 0; i--) deleteNode(newGraph->nodes[i]);
			free(newGraph->nodes);
			deleteMatrix(newGraph);
			free(newGraph);
			return NULL;
		}
	}

	return newGraph;
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