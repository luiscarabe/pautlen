// Definition of a graph using an adjacency matrix

typedef struct _Graph Graph;

Graph *newGraph();
int addNode(Graph *graph, char *node_name, void *content);
void addEdge(Graph *graph, int src_node, int dst_node);
void addSymmetricalEdge(Graph *graph, int node_a, int node_b);
void *getContentOfNode(Graph *graph, char *node_name);
void deleteGraph(Graph *graph);
void printGraph(Graph *graph);
// void **getAncestorsOfNode(Graph *graph, char *node_name);
tablaSimbolosClases * tablaSimbolosClasesToDot(tablaSimbolosClases * grafo);