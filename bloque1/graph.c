// Implementation of a graph using an adjacency matrix

#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "node.h"

#define NREALLOC 64
#define min(x, y) ((((x) < (y)) || (y) == 0) ? (x) : (y))

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

// Reallocates memory for nodes and amatrix when allocated is reached.
int reallocate(Graph *graph) {
	int i, j;

	if (!graph) return -1;

	// Adding new nodes
	graph->nodes = (Node **) realloc(graph->nodes, (graph->allocated + NREALLOC) * sizeof(Node *));

	// Adding rows to the matrix
	graph->amatrix = (char **) realloc(graph->amatrix, (graph->allocated + NREALLOC) * sizeof(char *));
	for (i = 0; i < graph->allocated; i++){ 
		// ...and columns to the existing rows
		graph->amatrix[i] = (char *) realloc(graph->amatrix[i], (graph->allocated + NREALLOC) * sizeof(char));
		for (j = graph->allocated; j < graph->allocated + NREALLOC; j++){
			graph->amatrix[i][j] = 0;
		}
	}
	// For the rows we just added
	for (; i < graph->allocated + NREALLOC; i++){
		graph->amatrix[i] = (char *) malloc((graph->allocated + NREALLOC) * sizeof(char));
		if (!graph->amatrix[i]){
			// Scary lines: restore changes
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

// Returns the index of a node given its name
int indexOf(Graph *graph, char *name){
	int i;

	if (!graph | !name) return -1;

	for (i = 0; i < graph->n; i++){
		if (nameCompare(graph->nodes[i], name) == 0)
			return i;
	}
	return -1;
}

// Self-explanatory
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

// Creates a node and inserts it into the graph
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

// Adds an edge between two nodes given their indexes
void addEdge(Graph *graph, int src_node, int dst_node){
	int i;

	if (!graph) return;
	if (src_node < 0 || dst_node < 0 || src_node >= graph->n || dst_node >= graph->n) return;
	
	// Child-Parent relation
	graph->amatrix[dst_node][src_node] = 1;

	// Update the ancestors of dst_node 
	for (i = 0; i < graph->allocated; i++)
		if (graph->amatrix[src_node][i] && dst_node != i)
			graph->amatrix[dst_node][i] = min((graph->amatrix[src_node][i] + 1), graph->amatrix[dst_node][i]);
	
	// Update the sucessors of src_node 
	for (i = 0; i < graph->allocated; i++)
		if (graph->amatrix[i][dst_node] && i != src_node)
			graph->amatrix[i][src_node] = min((graph->amatrix[i][dst_node] + 1), graph->amatrix[i][src_node]);

}

void addSymmetricalEdge(Graph *graph, int node_a, int node_b){
	addEdge(graph, node_a, node_b);
	addEdge(graph, node_b, node_a);
}

// Self-explanatory
void *getContentOfNode(Graph *graph, char *node_name){
	int i;

	if (!graph | !node_name) return NULL;

	i = indexOf(graph, node_name);
	if (i == -1) return NULL;

	return getContent(graph->nodes[i]);
}

// Self-explanatory
void **getAncestorsOfNode(Graph *graph, char *node_name){
	int i, j, allocated, inserted;
	void **ancestors;

	if (!graph | !node_name) return NULL;

	i = indexOf(graph, node_name);
	if (i == -1) return NULL;

	ancestors = (void **) malloc(sizeof(void *));
	allocated = 1;
	inserted = 0;
	for (j = 0; j < graph->allocated; j++){
		if (graph->amatrix[i][j] >= 1){
			if (allocated <= inserted) {
				ancestors = (void **) realloc(ancestors, sizeof(void *) * (allocated + 1));
				allocated ++;
			}
			ancestors[inserted] = getContent(graph->nodes[j]);
			inserted ++;
		}
	}

	return ancestors;
}

// Self-explanatory
void deleteGraph(Graph *graph){
	int i;

	if (!graph) return;

	for (i = 0; i < graph->n; i++) deleteNode(graph->nodes[i]);
	free(graph->nodes);

	for (i = 0; i < graph->allocated; i++) free(graph->amatrix[i]);
	free(graph->amatrix);
	free(graph);
}

// Self-explanatory
void printGraph(Graph *graph){
	int i, j;

	for (i = 0; i < graph->n; i++){
		printf("N%d:\t", i);
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