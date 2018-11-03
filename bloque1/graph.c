// Implementation of a graph using an adjacency matrix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "graph.h"
#include "node.h"

#define NREALLOC 64
#define min(x, y) ((((x) < (y)) || (y) == 0) ? (x) : (y))

typedef struct _Graph {
	char *name; 
	int n; // number of nodes
	int allocated; // number of potential nodes with memory already allocated
	Node **nodes; // nodes of the graph
	char **amatrix; // adjacency matrix
	// int clase_actual;
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

	if (!graph || !name) return -1;

	for (i = 0; i < graph->n; i++){
		if (nameCompare(graph->nodes[i], name) == 0)
			return i;
	}
	return -1;
}

// Self-explanatory
Graph *newGraph(char *name){
	Graph *newGraph;

	if (!name) return NULL;

	newGraph = (Graph *) malloc(sizeof(Graph));
	if (!newGraph) return NULL;

	newGraph->name = (char *) malloc(sizeof(char *) * (strlen(name) + 1));
	if (!newGraph->name){
		free(newGraph);
		return NULL;
	}
	if (strcpy(newGraph->name, name) < 0){
		free(newGraph->name);
		free(newGraph);
		return NULL;
	}

	newGraph->n = 0;
	newGraph->allocated = NREALLOC;

	if (buildMatrix(newGraph) == -1){
		free(newGraph->name);
		free(newGraph);
		return NULL;
	}

	newGraph->nodes = (Node **) malloc(NREALLOC*sizeof(Node*));
	if (!newGraph->nodes){
		free(newGraph->name);
		free(newGraph);
		return NULL;
	}

	return newGraph;
}

// Creates a node and inserts it into the graph
int addNode(Graph *graph, Node *node){

	if (!node) return -1;

	if (graph->n >= graph->allocated){
		if (reallocate(graph) == -1)
			return -1;
	}

	graph->nodes[graph->n] = node;
	return graph->n++;
}

// Adds an edge between two nodes given their indexes
void addParent(Graph *graph, int child, int parent){
	int i;

	if (!graph) return;
	if (child < 0 || parent < 0 || child >= graph->n || parent >= graph->n) return;
	
	// Child-Parent relation
	graph->amatrix[parent][child] = 1;

	// Update the ancestors of parent 
	for (i = 0; i < graph->allocated; i++)
		if (graph->amatrix[child][i] && parent != i)
			graph->amatrix[parent][i] = min((graph->amatrix[child][i] + 1), graph->amatrix[parent][i]);
	
	// Update the sucessors of child 
	for (i = 0; i < graph->allocated; i++)
		if (graph->amatrix[i][parent] && i != child)
			graph->amatrix[i][child] = min((graph->amatrix[i][parent] + 1), graph->amatrix[i][child]);

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

Graph * tablaSimbolosClasesToDot(Graph * grafo){
	char *file_name;
	FILE *f;
	int i, j;
	char **args;

	if (!grafo || !grafo->name) return NULL;

	file_name = (char *) malloc(sizeof(char *) * (strlen(grafo->name) + 5));
	if (!file_name) return NULL;

	if (strcpy(file_name, grafo->name) < 0){
		free(file_name);
		return NULL;
	}

	if (!strcat(file_name, ".dot")){
		free(file_name);
		return NULL;
	}

	f = fopen(file_name, "w+");
	if (!f) {
		free(file_name);
		return NULL;
	}

	fprintf(f, "digraph %s { rankdir=BT;\n", grafo->name);
	fprintf(f, "\t edge [arrowhead = empty]\n");

	for (i = 0; i < grafo->n; i++){
		fprintf(f, "\t%s [label=\"{%s|%s\\l" , getName(grafo->nodes[i]), getName(grafo->nodes[i]), getName(grafo->nodes[i]));
		args = getAttributes(grafo->nodes[i]);
		for (j = 0; j < getNumAttributes(grafo->nodes[i]); j++)
			fprintf(f, "%s\\l", args[j]);

		fprintf(f, "}\"][shape=record];\n");
	}

	for (i = 0; i < grafo->n; i++){
		for (j = 0; j < grafo->n; j++){
			if (grafo->amatrix[i][j] == 1)
				fprintf(f, "\t %s -> %s ;\n", getName(grafo->nodes[j]), getName(grafo->nodes[i]));
		}
	}

	fprintf(f, "\t edge [arrowhead = normal]\n");

	for (i = 0; i < grafo->n; i++)
		fprintf(f, "\t%s [label=\"%s\"][shape=oval];\n" , getName(grafo->nodes[i]), getName(grafo->nodes[i]));

	for (i = 0; i < grafo->n - 1; i++)
			fprintf(f, "\t %sN%d -> %sN%d\n", getName(grafo->nodes[i]), i, getName(grafo->nodes[i+1]), i+1);

	fprintf(f, "}\n");
	
	fclose(f);	
	free(file_name);
	
	return grafo;	
}

int iniciarTablaSimbolosClases(Graph** t, char * nombre){
	if (!t || !nombre) return -1;

	*t = newGraph(nombre);
	if (!t) return -1;
	return 0;
}

int abrirClase(Graph* t, char* id_clase){
	Node *node;

	if (!t || !id_clase) return 0;

	node = newNode(id_clase);
	if (!node) return 0;

	return addNode(t, node);
}

int abrirClaseHereda(Graph* t, char* id_clase, ...){
	va_list valist;
	int p, n;
	char *arg;
	Node *node;

	if (!t || !id_clase) return -1;

	node = newNode(id_clase);
	if (!node) return -1;

	if ((n = addNode(t, node)) == -1) return -1;

	va_start(valist, id_clase);
	while ((arg = va_arg(valist, char*))){
		if ((p = indexOf(t, arg)) >= 0){
			addParent(t, n, p);
		}
	}
	va_end(valist);

	return 0;
}

// int aniadirAtributoClase(Graph *graph, char *atributo){
// 	if (!graph || !atributo) return -1;

// }

// int abrirFuncionClase(Graph *graph, char *funcion){
// 	if (!graph || !atributo) return -1;

// }

// int cerrarFuncionClase(Graph *graph, char *funcion){
// 	if (!graph || !atributo) return -1;

// }

int cerrarClase(Graph* t,
								char* id_clase, 
								int num_atributos_clase, 
								int num_atributos_instancia, 
								int num_metodos_sobreescribibles, 
								int num_metodos_no_sobreescribibles){
	if (!id_clase || num_atributos_clase < 0 || num_atributos_instancia < 0 || num_metodos_sobreescribibles < 0 || num_metodos_no_sobreescribibles < 0)
		return -1;

	// if (!strcmp(getName(t->nodes[clase_actual]), id_clase)){
	// 	clase_actual = -1;
	// 	return 1;
	// }

	return 0;
}

int abrirAmbitoClase(Node** t, char* id_clase, int tamanio){

	if (!id_clase || tamanio <= 0 || !t) return -1;

	*t = newNodeTam(id_clase, tamanio);
	if (!*t) return -1;

	return 0;
}

int insertarTablaSimbolosClases(Graph * grafo, 
		char * id_clase,                 int categoria,
		char* id,                        int clase,
		int tipo,												 int direcciones,                    
		int numero_parametros,           int numero_variables_locales,        
		int posicion_variable_local,     int posicion_parametro,
		int tamanio,                     int numero_atributos_clase,            
		int numero_atributos_instancia,  int numero_metodos_sobreescribibles,    
		int numero_metodos_no_sobreescribibles,
		int tipo_acceso,                 int tipo_miembro, 
		int posicion_atributo_instancia, int posicion_metodo_sobreescribible,
		int num_acumulado_atributos_instancia,   
		int num_acumulado_metodos_sobreescritura,
		int * tipo_args){


	int index_clase;

	if (!grafo || !id_clase || !id) return -1;

	index_clase = indexOf(grafo, id_clase);
	if (index_clase == -1) return -1;

	return insertarTablaSimbolos(grafo->nodes[index_clase], 
															 id,
															 categoria,
															 tipo,
															 clase,
															 direcciones,
															 numero_parametros,
															 posicion_parametro,
															 numero_variables_locales,
															 posicion_variable_local,
															 tamanio,
															 numero_atributos_clase,
															 numero_atributos_instancia,
															 numero_metodos_sobreescribibles,
															 numero_metodos_no_sobreescribibles,
															 tipo_acceso,
															 tipo_miembro,
															 posicion_atributo_instancia,
															 posicion_metodo_sobreescribible,
															 num_acumulado_atributos_instancia,
															 num_acumulado_metodos_sobreescritura,
															 tipo_args);
}


int tablaSimbolosClasesAbrirAmbitoEnClase(Graph * grafo, 
																char * id_clase,
																char* id_ambito, 
																int categoria_ambito, 
																int acceso_metodo, 
																int tipo_metodo, 
																int posicion_metodo_sobre, 
																int tamanio){

	int clase;

	if (!grafo || !id_clase || !id_ambito) return -1;

	clase = indexOf(grafo, id_clase);
	if (clase == -1) return -1;

	return abrirAmbitoFunc(grafo->nodes[clase], id_clase,
												 id_ambito, 
												 categoria_ambito, 
												 acceso_metodo, 
												 tipo_metodo, 
												 posicion_metodo_sobre, 
												 tamanio);

}

int tablaSimbolosClasesCerrarAmbitoEnClase(Graph* grafo, 
                            char * id_clase){

	int clase;

	if (!grafo || !id_clase) return -1;

	clase = indexOf(grafo, id_clase);
	if (clase == -1) return -1;

	return cerrarAmbitoFunc(grafo->nodes[clase]);

}





