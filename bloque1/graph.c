// Implementation of a graph using an adjacency matrix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "graph.h"
#include "node.h"
#include "hash_table.h"

#define NREALLOC 64
#define min(x, y) ((((x) < (y)) || (y) == 0) ? (x) : (y))

typedef struct _Graph {
	char *name; 
	int n; // number of nodes
	int allocated; // number of potential nodes with memory already allocated
	Node **nodes; // nodes of the graph
	char **amatrix; // adjacency matrix
	// int clase_actual;
	Node *main;
} Graph;

int modificar_insertar(TablaSimbolos *ht, 
											 TablaSimbolos *main, 
											 char *id_clase, 
											 int x,
											 int (*f)(TablaSimbolos *ts, const char *key, int incr, int (*g)(int *a, int b)));

int increment(int *a, int b){
	(*a) += b;
	return *a;
}

int decrement(int *a, int b){
	(*a) -= b;
	return *a;
}

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

	for (i = 0; i < graph->n; i++) 
		deleteNode(graph->nodes[i]);
	free(graph->nodes);

	for (i = 0; i < graph->allocated; i++) 
		free(graph->amatrix[i]);
	free(graph->amatrix);

	deleteNode(graph->main);
	free(graph->name);
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
	int num_attributes;

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
		num_attributes = getNumAttributes(grafo->nodes[i]);
		for (j = 0; j < num_attributes; j++)
			fprintf(f, "%s\\l", args[j]);

		fprintf(f, "}\"][shape=record];\n");
		for (j = 0; j < num_attributes; j++)
			free(args[j]);
		free(args);
	}

	for (i = 0; i < grafo->n; i++){
		for (j = 0; j < grafo->n; j++){
			if (grafo->amatrix[i][j] == 1)
				fprintf(f, "\t %s -> %s ;\n", getName(grafo->nodes[j]), getName(grafo->nodes[i]));
		}
	}

	fprintf(f, "\t edge [arrowhead = normal]\n");

	for (i = 0; i < grafo->n; i++)
		fprintf(f, "\t%sN%d [label=\"%s\"][shape=oval];\n" , getName(grafo->nodes[i]), i, getName(grafo->nodes[i]));

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

	(*t)->main = newNode("main");
	if (!(*t)->main){
		free(*t);
		return -1;
	}

	return 0;
}

int abrirClase(Graph* t, char* id_clase){
	Node *node;
	char *name;

	if (!t || !id_clase) return 0;

	node = newNode(id_clase);
	if (!node) return 0;

	name = (char *) malloc(sizeof(char) * (strlen(id_clase) + 6));
	if (!name){
		deleteNode(node);
		return 0;
	}

	if (strcpy(name, "main_") < 0){
		deleteNode(node);
		free(name);
		return 0;
	}

	if (!strcat(name, id_clase)){
		deleteNode(node);
		free(name);
		return 0;
	}

	insertarTablaNodo(t->main, name, CLASE, 0, OBJETO, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, NULL);

	insertarTablaNodo(node, id_clase, CLASE, 0, OBJETO, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, NULL);

	free(name);
	return addNode(t, node);
}

int abrirClaseHeredaN(Graph* t, char* id_clase, int num_padres, char **id_padres){
	int i, p, n;

	if (!t || !id_clase) return -1;

	if ((n = abrirClase(t, id_clase)) == -1) return -1;

	for (i = 0; i < num_padres; i++){
		if ((p = indexOf(t, id_padres[i])) < 0)
			return -i;
		addParent(t, n, p);
	}

	return 0;
}

int abrirClaseHereda(Graph* t, char* id_clase, ...){
	va_list valist;
	int p, n;
	char *arg;
	int atributos_instancia_acum, metodos_sobre_acum;

	if (!t || !id_clase) return -1;

	if ((n = abrirClase(t, id_clase)) == -1) return -1;

	atributos_instancia_acum = 0;
	metodos_sobre_acum = 0;

	va_start(valist, id_clase);
	while ((arg = va_arg(valist, char*))){
		if ((p = indexOf(t, arg)) >= 0){
			addParent(t, n, p);
			atributos_instancia_acum += get_num_atributos_instancia(getPrimaryScope(t->nodes[p]), arg);
			atributos_instancia_acum += get_num_atributos_instancia_acum(getPrimaryScope(t->nodes[p]), arg);

			metodos_sobre_acum += get_num_metodos_sobreescritura(getPrimaryScope(t->nodes[p]), arg);
			metodos_sobre_acum += get_num_metodos_sobreescritura_acum(getPrimaryScope(t->nodes[p]), arg);
		}
	}
	va_end(valist);

	if (atributos_instancia_acum > 0){
		modificar_insertar(getPrimaryScope(t->nodes[n]),
											 getPrimaryScope(t->main),
											 id_clase,
											 atributos_instancia_acum,
											 &modify_atributos_instancia_acum);
	}

	if (metodos_sobre_acum > 0){
		modificar_insertar(getPrimaryScope(t->nodes[n]),
											 getPrimaryScope(t->main),
											 id_clase,
											 metodos_sobre_acum,
											 &modify_metodos_sobre_acum);
	}

	return 0;
}

int cerrarClase(Graph* t,
								char* id_clase){
	if (!id_clase)
		return -1;

	return 0;
}

int modificar_insertar(TablaSimbolos *ht, 
											 TablaSimbolos *main, 
											 char *id_clase, 
											 int x,
											 int (*f)(TablaSimbolos *ts, const char *key, int incr, int (*g)(int *a, int b))){
	char *name_main;

	if (!ht || !main)	return -1;

	name_main = (char *) malloc(sizeof(char) * (strlen(id_clase) + 6));
	if (strcpy(name_main, "main_") < 0){
		free(name_main);
		return -1;
	}

	if (!strcat(name_main, id_clase)){
		free(name_main);
		return -1;
	}

	if(f(ht, id_clase, x, &increment) == -1){
		free(name_main);
		return -1;
	}

	if(f(main, name_main, x, &increment) == -1){
		f(ht, id_clase, x, &decrement);
		free(name_main);
		return -1;
	}

	free(name_main);
	return 0;
}

int insertarTablaSimbolosAmbitosMain(Graph *grafo, 
		int categoria,
		char* id,                        int clase,
		int tipo,												 int direcciones,                    
		int numero_parametros,                 
		int posicion_variable_local,     int posicion_parametro,
		int tamanio,                                
		int tipo_acceso,                 int tipo_miembro, 
		int posicion_atributo_instancia, int posicion_metodo_sobreescribible,
		int * tipo_args){

	if (!grafo || !id) return ERR;

	return insertarTablaNodo(grafo->main, 
								id,
								categoria,
								tipo,
								clase,
								direcciones,
								numero_parametros,
								posicion_parametro,
								posicion_variable_local,
								tamanio,
								tipo_acceso,
								tipo_miembro,
								posicion_atributo_instancia,
								posicion_metodo_sobreescribible,
								tipo_args);

}

int insertarTablaSimbolosAmbitos(Graph *grafo, char *id_clase, 
		int categoria,
		char* id,                        int clase,
		int tipo,												 int direcciones,                    
		int numero_parametros,                 
		int posicion_variable_local,     int posicion_parametro,
		int tamanio,                                
		int tipo_acceso,                 int tipo_miembro, 
		int posicion_atributo_instancia, int posicion_metodo_sobreescribible,
		int * tipo_args){

	int index_clase;

	if (!grafo || !id_clase || !id) return ERR;

	index_clase = indexOf(grafo, id_clase);
	if (index_clase == ERR) return ERR;

	return insertarTablaNodo(grafo->nodes[index_clase], 
								id,
								categoria,
								tipo,
								clase,
								direcciones,
								numero_parametros,
								posicion_parametro,
								posicion_variable_local,
								tamanio,
								tipo_acceso,
								tipo_miembro,
								posicion_atributo_instancia,
								posicion_metodo_sobreescribible,
								tipo_args);


}

int insertarTablaSimbolosMain(Graph * grafo, int categoria,
		char* id,                        int clase,
		int tipo,												 int direcciones,                    
		int numero_parametros,        
		int posicion_variable_local,     int posicion_parametro,
		int tamanio,      
		int tipo_acceso,                 int tipo_miembro, 
		int posicion_atributo_instancia, int posicion_metodo_sobreescribible,
		int * tipo_args){

	if (!grafo || !id) return -1;

	return insertarTablaNodo(grafo->main, 
								id,
								categoria,
								tipo,
								clase,
								direcciones,
								numero_parametros,
								posicion_parametro,
								posicion_variable_local,
								tamanio,
								tipo_acceso,
								tipo_miembro,
								posicion_atributo_instancia,
								posicion_metodo_sobreescribible,
								tipo_args);
}


int insertarTablaSimbolosClases(Graph * grafo, 
		char * id_clase,                 int categoria,
		char* id,                        int clase,
		int tipo,												 int direcciones,                    
		int numero_parametros,        
		int posicion_variable_local,     int posicion_parametro,
		int tamanio,      
		int tipo_acceso,                 int tipo_miembro, 
		int posicion_atributo_instancia, int posicion_metodo_sobreescribible,
		int * tipo_args){

	int index_clase;

	if (!grafo || !id_clase || !id) return ERR;

	index_clase = indexOf(grafo, id_clase);
	if (index_clase == ERR) return ERR;

	// if (categoria == ATRIBUTO_INSTANCIA){
	// 	if (modificar_insertar(getPrimaryScope(grafo->nodes[index_clase]), 
	// 												 getPrimaryScope(grafo->main), 
	// 												 id_clase, 
	// 												 1,
	// 												 &modify_atributos_instancia) == -1){
	// 		free(name);
	// 		return -1;
	// 	}
	// }
	// else if (categoria == METODO_SOBREESCRIBIBLE){
	// 	if (modificar_insertar(getPrimaryScope(grafo->nodes[index_clase]), 
	// 												 getPrimaryScope(grafo->main), 
	// 												 id_clase, 
	// 												 1,
	// 												 &modify_metodos_sobreescritura)){
	// 		free(name);
	// 		return -1;
	// 	}
	// }


	return insertarTablaNodo(grafo->nodes[index_clase], 
								id,
								categoria,
								tipo,
								clase,
								direcciones,
								numero_parametros,
								posicion_parametro,
								posicion_variable_local,
								tamanio,
								tipo_acceso,
								tipo_miembro,
								posicion_atributo_instancia,
								posicion_metodo_sobreescribible,
								tipo_args);

}

int tablaSimbolosClasesAbrirAmbitoEnMain(Graph * grafo, 
																char* id_ambito, 
																int categoria_ambito, 
																int acceso_metodo, 
																int tipo_metodo, 
																int posicion_metodo_sobre, 
																int tamanio,
																int numero_parametros,
																int *tipo_args){
	if (!grafo || !id_ambito) return ERR;

	return abrirAmbitoFunc(grafo->main,
							id_ambito, 
							categoria_ambito, 
							acceso_metodo, 
							tipo_metodo, 
							posicion_metodo_sobre, 
							tamanio,
							numero_parametros,
							tipo_args);
}
int tablaSimbolosClasesAbrirAmbitoEnClase(	Graph * grafo, 
											char * id_clase,
											char* id_ambito, 
											int categoria_ambito, 
											int acceso_metodo, 
											int tipo_metodo, 
											int posicion_metodo_sobre, 
											int tamanio,
											int numero_parametros,
											int *tipo_args){

	int clase;

	if (!grafo || !id_clase || !id_ambito) return ERR;

	clase = indexOf(grafo, id_clase);
	if (clase == ERR) return ERR;

	return abrirAmbitoFunc(grafo->nodes[clase],
							id_ambito, 
							categoria_ambito, 
							acceso_metodo, 
							tipo_metodo, 
							posicion_metodo_sobre, 
							tamanio,
							numero_parametros,
							tipo_args);

}

int tablaSimbolosClasesCerrarAmbitoEnMain(Graph* grafo){
	if (!grafo) return -1;

	return cerrarAmbitoFunc(grafo->main);

}

int tablaSimbolosClasesCerrarAmbitoEnClase(Graph* grafo, char * id_clase){
	int clase;

	if (!grafo || !id_clase) return -1;

	clase = indexOf(grafo, id_clase);
	if (clase == -1) return -1;

	return cerrarAmbitoFunc(grafo->nodes[clase]);

}

int esDescendiente(Graph *g, char *descendiente, char *antecesor){
	int i_desc, i_ante;

	if (!g || !descendiente || !antecesor) return ERR;

	if (strcmp(descendiente, antecesor) == 0) return OK;

	i_desc = indexOf(g, descendiente);
	if (i_desc == -1) return ERR;
	i_ante = indexOf(g, antecesor);
	if (i_ante == -1) return ERR;

	if (g->amatrix[i_ante][i_desc] > 0)
		return OK;
	else
		return ERR;
	

}

int aplicarAccesos(Graph *g, char * nombre_clase_ambito_actual, char * clase_declaro, HT_item * pelem){
	enum acceso access;

	if (!g || !nombre_clase_ambito_actual || !clase_declaro || !pelem) return ERR;

	access = HT_itemGetAccess(pelem);
	//printf("Acceso desde %s a %s: %d\n", nombre_clase_ambito_actual, clase_declaro, access);

	if (strcmp(nombre_clase_ambito_actual, "main") == 0){
		if (access == ACCESO_CLASE)
			return ERR;
		else
			return OK;
	} else {
		switch(access){
			case ACCESO_CLASE:
				if (strcmp(nombre_clase_ambito_actual, clase_declaro) != 0)
					return ERR;
				else
					return OK;
				break;
			case ACCESO_HERENCIA:
				return esDescendiente(g, nombre_clase_ambito_actual, clase_declaro);
				break;
			default:
				return OK;
		}
	}
}

int buscarIdEnJerarquiaDesdeClase(Graph *g, char * nombre_id, char * nombre_clase_desde, HT_item ** e, char * nombre_ambito_encontrado){
	int i, index, last_found, len;
	HT_item *result;

	if (!g || !nombre_id || !nombre_clase_desde || !e || !nombre_ambito_encontrado) return ERR;

	last_found = g->n;

	index = indexOf(g, nombre_clase_desde);
	if (index == -1) return ERR;

	result = buscarSimboloFunc(g->nodes[index], nombre_id);
	if (result){
		len = strlen(getNameFunc(g->nodes[index]));
		strncpy(nombre_ambito_encontrado, getNameFunc(g->nodes[index]), len*sizeof(char));
		nombre_ambito_encontrado[len] = '\0';
		*e = result;
		return OK;
	}

	result = buscarSimbolo(g->nodes[index], nombre_id);
	if (result){
		len = strlen(getName(g->nodes[index]));
		strncpy(nombre_ambito_encontrado, getName(g->nodes[index]), len*sizeof(char));
		nombre_ambito_encontrado[len] = '\0';
		*e = result;
		return OK;
	}

	for (i = index-1; i >= 0 && last_found > 1; i--){
		if (g->amatrix[i][index] > 0 && g->amatrix[i][index] < last_found){
			result = buscarSimbolo(g->nodes[i], nombre_id);
			if (aplicarAccesos(g, nombre_clase_desde, getName(g->nodes[i]), result) == OK){
				len = strlen(getName(g->nodes[i]));
				strncpy(nombre_ambito_encontrado, getName(g->nodes[i]), len*sizeof(char));
				nombre_ambito_encontrado[len] = '\0';
				*e = result;
				last_found = g->amatrix[i][index];
			}
		}
	}

	if (last_found < g->n)
		return OK;
	else
		return ERR;

}

int buscarIdNoCualificado(Graph *t, char * nombre_id, char * nombre_clase_desde, HT_item ** e, char * nombre_ambito_encontrado){
	HT_item *ret;
	int len;

	if (!t || !nombre_id || !nombre_clase_desde || !e)
		return ERR;

	if (buscarIdEnJerarquiaDesdeClase(t, nombre_id, nombre_clase_desde, e, nombre_ambito_encontrado) == OK)
		return OK;

	ret = buscarSimboloFunc(t->main, nombre_id);
	if (!ret){
		ret = buscarSimbolo(t->main, nombre_id);
		if (!ret) return ERR;
		strncpy(nombre_ambito_encontrado, "main", 5*sizeof(char));
		nombre_ambito_encontrado[4] = '\0';
	}
	else{
		len = strlen(getNameFunc(t->main));
		strncpy(nombre_ambito_encontrado, getNameFunc(t->main), len*sizeof(char));
		nombre_ambito_encontrado[len] = '\0';
	}
	
	*e = ret;
	return aplicarAccesos(t, nombre_clase_desde, nombre_ambito_encontrado, ret);
}


int buscarParaDeclararMiembroClase(Graph *t, char * nombre_id, char * nombre_clase_desde, HT_item ** e, char * nombre_ambito_encontrado){
	int index, len;
	HT_item * result;

	if (!t || !nombre_id || !nombre_clase_desde || !e)
		return ERR;

	//segun las transparencias esto solo se debe buscar en la clase, NO en jerarquia
	//if (buscarIdEnJerarquiaDesdeClase(t, nombre_id, nombre_clase_desde, e, nombre_ambito_encontrado) == OK)
	//	return OK;

	index = indexOf(t, nombre_clase_desde);
	if (index == -1) return ERR;

	// No tiene sentido buscar en la función
	result = buscarSimbolo(t->nodes[index], nombre_id);
	if (result){
		len = strlen(getName(t->nodes[index]));
		strncpy(nombre_ambito_encontrado, getName(t->nodes[index]), len*sizeof(char));
		nombre_ambito_encontrado[len] = '\0';
		*e = result;
		return OK;
	}

	return ERR;
}

int buscarParaDeclararMiembroInstancia(Graph *t, char * nombre_id, char * nombre_clase_desde, HT_item ** e, char * nombre_ambito_encontrado){

	if (!t || !nombre_id || !nombre_clase_desde || !e)
		return ERR;

	if (buscarIdEnJerarquiaDesdeClase(t, nombre_id, nombre_clase_desde, e, nombre_ambito_encontrado) == ERR)
		return ERR;

	return aplicarAccesos(t, nombre_clase_desde, nombre_ambito_encontrado, *e);
}


int buscarIdCualificadoClase(	Graph *g, char * nombre_clase_cualifica,
								char * nombre_id, char * nombre_clase_desde,
								HT_item ** e,
								char * nombre_ambito_encontrado){
	int index_clase_cualifica;

	if (!g || !nombre_clase_cualifica || !nombre_id || !nombre_clase_desde || !e || !nombre_ambito_encontrado)
		return ERR;

	index_clase_cualifica = indexOf(g, nombre_clase_cualifica);
	if(index_clase_cualifica == ERR) return ERR;

	if (buscarIdEnJerarquiaDesdeClase(g, nombre_id, nombre_clase_cualifica, e, nombre_ambito_encontrado) == ERR)
		return ERR;

	return aplicarAccesos(g, nombre_clase_desde, nombre_ambito_encontrado, *e);
}



int buscarIdCualificadoInstancia(	Graph *g,
									char * nombre_instancia_cualifica,
									char * nombre_id, char * nombre_clase_desde,
									HT_item ** e,
									char * nombre_ambito_encontrado){
	int index_clase;

	if (!g || ! nombre_instancia_cualifica || !nombre_id || !nombre_clase_desde || !e || !nombre_ambito_encontrado)
		return ERR;


	// Busca el nombre de la instancia
	if (buscarIdNoCualificado(g, nombre_instancia_cualifica, nombre_clase_desde, e, nombre_ambito_encontrado) == ERR){
		//printf("No encontrada instancia_cualifica %s\n", nombre_instancia_cualifica);
		return ERR;
	}

	// Mira la clase a la que pertenece la instancia
	index_clase = - HT_itemGetClass(*e);
	if (index_clase < 0){
		//printf("%s no es una instancia de clase\n", nombre_instancia_cualifica);
		return ERR;
	}

	// Mira si hay acceso a la instancia desde el ambito actual
	if (aplicarAccesos(g, nombre_clase_desde, nombre_ambito_encontrado, *e) == ERR){
		//printf("No hay acceso desde %s a %s\n", nombre_clase_desde, nombre_instancia_cualifica);
		return ERR;
	}

	// printf("Buscando %s en jerarquia desde %s\n", nombre_id, getName(g->nodes[index_clase]));

	if (buscarIdEnJerarquiaDesdeClase(g, nombre_id, getName(g->nodes[index_clase]), e, nombre_ambito_encontrado) == ERR){
		// printf("No encontrado %s\n", nombre_id);
		return ERR;
	}

	return aplicarAccesos(g, nombre_clase_desde, nombre_ambito_encontrado, *e);
}

int buscarParaDeclararIdTablaSimbolosAmbitos(Graph * g, char* id, HT_item** e, char* id_ambito){
	int index;
	Node *clase;

	// No tiene sentido el parametro e no??
	// Creo que habría que asignarlo en la llamada a la búsqueda

	if(!g || !id || !e || !id_ambito) return ERR;


	if (strcmp(id_ambito, "main") == 0){
		clase = g->main;
	}
	else{
		index = indexOf(g, id_ambito);

		if (index == ERR) return ERR;

		clase = g->nodes[index];
	}

	return buscarSimboloEnAmbitoActual(clase, id) ? OK : ERR;
}


int buscarParaDeclararIdLocalEnMetodo(Graph *g,
																			char * nombre_clase,
																			char * nombre_id,
																			HT_item ** e,
																			char * nombre_ambito_encontrado){
	int index, len;
	Node *clase;

	// No tiene sentido el parámetro nombre_ambito_encontrado no?
	// Ni el e no? --> asignacion

	if(!g || !nombre_clase || !nombre_id || !e || !nombre_ambito_encontrado) return ERR;

	if (strcmp(nombre_clase, "main") == 0){
		clase = g->main;
	}
	else{
		index = indexOf(g, nombre_clase);

		if (index == ERR) return ERR;

		clase = g->nodes[index];
	}

	*e = buscarSimboloFunc(clase, nombre_id);
	if(!*e) return ERR;

	len = strlen(getNameFunc(g->nodes[index]));
	strncpy(nombre_ambito_encontrado, getNameFunc(g->nodes[index]), len*sizeof(char));
	nombre_ambito_encontrado[len] = '\0';

	return OK;
}

void imprimirTablasHash(Graph *g){
	if (!g) return;

	printf("Tabla del main\n");
	imprimirTablaPpal(g->main);
	printf("\nfunc:\n");
	imprimirTablaFunc(g->main);
	printf("\n\n");

	for (int i = 0; i < g->n ; i++){
		printf("Tabla del nodo %s\n", getName(g->nodes[i]));
		imprimirTablaPpal(g->nodes[i]);
		printf("\nfunc:\n");
		imprimirTablaFunc(g->nodes[i]);
		printf("\n\n");
	}
}


int tablSimbolosClasesANasm(Graph *g, FILE *f_nasm){
	char ***tablas_ms;
	int **posiciones_rellenas;
	int i, j, k;
	int num_metodos_sobre_acumulado;

	if (!g || !f_nasm) return ERR;

	// Conjunto de offsets de cada método sobreescribible
	// Conjunto de offsets de cada atributo de instancia
	// Los métodos de clase y los atributos de clase simplemente deben ser definidos


	// Tabla de métodos sobreescribiles de cada clase
	posiciones_rellenas = (int **) malloc(g->n * sizeof(int **));
	if (!posiciones_rellenas) return ERR;

	tablas_ms = (char ***) malloc(g->n * sizeof(char **));
	if (!tablas_ms){
		free(posiciones_rellenas);
		return ERR;
	}

	for (i = 0, k = 0, num_metodos_sobre_acumulado = 0; i < g->n; i++){
		// Dimensionamiento
		num_metodos_sobre_acumulado += getNumMetodosSobreescribibles(g->nodes[i]);

		tablas_ms[i] = (char **) malloc(num_metodos_sobre_acumulado * sizeof(char *));
		if (!tablas_ms[i]){
			for (i--; i >= 0; i--)
				free(tablas_ms[i]);
			free(tablas_ms);
			free(posiciones_rellenas);
			return ERR;
		}

		posiciones_rellenas[i] = (int *) malloc((num_metodos_sobre_acumulado + 1) * sizeof(int)); // +1 porque van a acabar todos en -1 (del estilo del '\0' en strings)
		if (!posiciones_rellenas[i]){
			for (i--; i >= 0; i--){
				free(tablas_ms[i]);
				free(posiciones_rellenas[i]);
			}
			free(tablas_ms);
			free(posiciones_rellenas);
			return ERR;
		}

		// Eleccion de padres de los que heredar
		for (j = 0; j < i; j++){
			if (g->amatrix[j][i] == 1){ // j padre directo de i
				for (k = 0; posiciones_rellenas[j][k] != -1; k++){
					// Copia posiciones rellenas del padre en el nodo actual
					tablas_ms[i][posiciones_rellenas[j][k]] = tablas_ms[j][posiciones_rellenas[j][k]];
					posiciones_rellenas[i][k] = posiciones_rellenas[j][k];
				}
			}
		}

		// Sobreescrituras de la clase
		// Metodos sobreescribibles propios

		// Falta recorrer todos los elementos de la tabla hash de i
		// Si son metodos sobreescribibles:
		// 				Comprobar si sobreescriben alguno de los del padre (comparar nombres sin prefijo)
		// 					1) si lo hacen, sustituir en la misma posicion con el prefijo nuevo
		// 					2) si no, meterlos en una nueva posicion
		// 						ir actualizando posiciones rellenas (recordar terminarlo siempre con -1)
	}
}