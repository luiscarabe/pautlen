// Definition of a graph using an adjacency matrix
#include "node.h"

typedef struct _Graph Graph;

Graph *newGraph(char *name);
int addNode(Graph *graph, Node *node);
void addParent(Graph *graph, int child, int parent);
// void *getContentOfNode(Graph *graph, char *node_name);
void deleteGraph(Graph *graph);
void printGraph(Graph *graph);
// void **getAncestorsOfNode(Graph *graph, char *node_name);
Graph * tablaSimbolosClasesToDot(Graph * grafo);


int iniciarTablaSimbolosClases(Graph** t, char * nombre);
int abrirClase(Graph* t, char* id_clase);
int abrirClaseHereda(Graph* t, char* id_clase, ...);
int cerrarClase(Graph* t,
                char* id_clase, 
                int num_atributos_clase, 
                int num_atributos_instancia, 
                int num_metodos_sobreescribibles, 
                int num_metodos_no_sobreescribibles);

// void graph_enrouteParentsLastNode(Graph * g);


