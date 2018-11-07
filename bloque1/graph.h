// Definition of a graph using an adjacency matrix
#include "node.h"
#include "symbols.h"

typedef struct _Graph Graph;

Graph *newGraph(char *name);
int addNode(Graph *graph, Node *node);
void addParent(Graph *graph, int child, int parent);
void deleteGraph(Graph *graph);
void printGraph(Graph *graph);
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


// int abrirAmbitoClase(Node** t, char* id_clase, int tamanio);

int insertarTablaSimbolosAmbitos(Graph *grafo, char *id_clase, 
		int categoria,
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
		int * tipo_args);

// int abrirAmbitoPrefijos(Node* node, 
//                         char* id_ambito, 
//                         int categoria_ambito, 
//                         int acceso_metodo, 
//                         int tipo_metodo, 
//                         int posicion_metodo_sobre, 
//                         int tamanio);

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
		int * tipo_args);


int tablaSimbolosClasesAbrirAmbitoEnClase(Graph * grafo, 
																char * id_clase,
																char* id_ambito, 
																int categoria_ambito, 
																int acceso_metodo, 
																int tipo_metodo, 
																int posicion_metodo_sobre, 
																int tamanio,
																int numero_parametros,
																int *tipo_args);

int tablaSimbolosClasesCerrarAmbitoEnClase(Graph* grafo, 
                            char * id_clase);

int buscarIdNoCualificado(Graph *t, 
                          // tablaAmbitos *tabla_main,
                 					char * nombre_id, 
                 					char * nombre_clase_desde,
                 					HT_item ** e, 
  												char * nombre_ambito_encontrado);



// Para debuggear - usar con precaucion
void imprimirTablasHash(Graph *g);

// void graph_enrouteParentsLastNode(Graph * g);


