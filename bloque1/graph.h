// Definition of a graph using an adjacency matrix

typedef struct _Graph Graph;

Graph *newGraph();
int addNode(Graph *graph, char *node_name, void *content);
void addParent(Graph *graph, int child, int parent);
void *getContentOfNode(Graph *graph, char *node_name);
void deleteGraph(Graph *graph);
void printGraph(Graph *graph);
// void **getAncestorsOfNode(Graph *graph, char *node_name);
// Graph * tablaSimbolosClasesToDot(Graph * grafo);


// int iniciarTablaSimbolosClases(tablaSimbolosClases** t, char * nombre);
// int abrirClase(tablaSimbolosClases* t, char* id_clase);
// int abrirClaseHereda(tablaSimbolosClases* t, char* id_clase, ...);
// int cerrarClase(tablaSimbolosClases* t,
//                 char* id_clase, 
//                 int num_atributos_clase, 
//                 int num_atributos_instancia, 
//                 int num_metodos_sobreescribibles, 
//                 int num_metodos_no_sobreescribibles);

// void graph_enrouteParentsLastNode(tablaSimbolosClases * g);


