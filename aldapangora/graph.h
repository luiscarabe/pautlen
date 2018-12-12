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
int abrirClaseHeredaN(Graph* t, char* id_clase, int num_padres, char **id_padres);
int cerrarClase(Graph* t,
                char* id_clase);

int insertarTablaSimbolosClases(Graph * grafo, 
		char * id_clase,                 int categoria,
		char* id,                        int clase,
		int tipo,												 int direcciones,                    
		int numero_parametros,        
		int posicion_variable_local,     int posicion_parametro,
		int tamanio,      
		int tipo_acceso,                 int tipo_miembro, 
		int posicion_atributo_instancia, int posicion_metodo_sobreescribible,
		int * tipo_args);

int insertarTablaSimbolosMain(Graph * grafo, int categoria,
		char* id,                        int clase,
		int tipo,												 int direcciones,                    
		int numero_parametros,        
		int posicion_variable_local,     int posicion_parametro,
		int tamanio,      
		int tipo_acceso,                 int tipo_miembro, 
		int posicion_atributo_instancia, int posicion_metodo_sobreescribible,
		int * tipo_args);

int tablaSimbolosClasesCerrarAmbitoEnMain(Graph* grafo);

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

int tablaSimbolosClasesAbrirAmbitoEnMain(Graph * grafo, 
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

int buscarParaDeclararMiembroClase(Graph *t,
													char * nombre_id,
													char * nombre_clase_desde,
													HT_item ** e,
													char * nombre_ambito_encontrado);

int buscarParaDeclararMiembroInstancia(Graph *t,
													char * nombre_id,
													char * nombre_clase_desde,
													HT_item ** e,
													char * nombre_ambito_encontrado);

int buscarIdCualificadoClase(	Graph *g, char * nombre_clase_cualifica,
								char * nombre_id, char * nombre_clase_desde,
								HT_item ** e,
								char * nombre_ambito_encontrado);

int buscarIdCualificadoInstancia(	Graph *g,
									char * nombre_instancia_cualifica,
									char * nombre_id, char * nombre_clase_desde,
									HT_item ** e,
									char * nombre_ambito_encontrado);

// Para debuggear - usar con precaucion
void imprimirTablasHash(Graph *g);
void imprimirTablaTrasActualizacion(FILE * fout, Graph *g, char * name);

// void graph_enrouteParentsLastNode(Graph * g);

int buscarParaDeclararIdTablaSimbolosAmbitos(Graph * g, 
                                    char* id, 
                                    HT_item** e,  
                                    char* id_ambito);

int buscarParaDeclararIdLocalEnMetodo(Graph *g,
																			char * nombre_clase,
																			char * nombre_id,
																			HT_item ** e,
																			char * nombre_ambito_encontrado);

int tablaSimbolosClasesANasm(Graph *g, FILE *f_nasm);