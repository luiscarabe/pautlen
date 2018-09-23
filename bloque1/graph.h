// Definition of a graph using an adjacency matrix

#include "node.h"

typedef struct _Graph Graph;

Graph *newGraph(int n, Node **nodes);
void addEdge(Graph *graph, int src_node, int dst_node);
void addSymmetricalEdge(Graph *graph, int node_a, int node_b);
void removeEdge(Graph *graph, int src_node, int dst_node);
void removeSymmetricalEdge(Graph *graph, int node_a, int node_b);
void deleteGraph(Graph *graph);
void printGraph(Graph *graph);