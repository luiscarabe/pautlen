#ifndef NODE_H
#define NODE_H

// Definition of a node
#include "hash_table.h"
#include "symbols.h"

typedef struct _Node Node;

Node *newNode(char *name);
Node *newNodeTam(char *name, int tamanio);

int nameCompare(Node *node, char *name);
void deleteNode(Node *node);
void printNode(Node *node);
char *getName(Node *node);
char *getNameFunc(Node *node);
char **getAttributes(Node *node);
int getNumAttributes(Node *node);

int abrirAmbitoFunc(Node *node,
                    char* id_ambito, 
                    int categoria_ambito, 
                    int acceso_metodo, 
                    int tipo_metodo, 
                    int posicion_metodo_sobre, 
                    int tamanio,
                    int numero_parametros,
                    int *tipo_args);

int cerrarAmbitoFunc(Node *node);

// int insertarTablaSimbolos(Node *node,
// 		const char* key,            int categoria,  
// 		int tipo,                   int clase, 
// 		int direcciones,            int numero_parametros, 
// 		int posicion_parametro,
// 		int posicion_variable_local,
// 		int tamanio,           
// 		int tipo_acceso,            int tipo_miembro, 
// 		int posicion_atributo_instancia, 
// 		int posicion_metodo_sobreescribible, 
// 		int * tipo_args);

// int insertarTablaAmbitos(Node *node,
// 		const char* key,            int categoria,  
// 		int tipo,                   int clase, 
// 		int direcciones,            int numero_parametros, 
// 		int posicion_parametro, 
// 		int posicion_variable_local,
// 		int tamanio,      
// 		int tipo_acceso,            int tipo_miembro, 
// 		int posicion_atributo_instancia, 
// 		int posicion_metodo_sobreescribible, 
// 		int * tipo_args);

int insertarTablaNodo(Node *node,
		const char* key,            int categoria,  
		int tipo,                   int clase, 
		int direcciones,            int numero_parametros, 
		int posicion_parametro, 
		int posicion_variable_local,
		int tamanio,      
		int tipo_acceso,            int tipo_miembro, 
		int posicion_atributo_instancia, 
		int posicion_metodo_sobreescribible, 
		int * tipo_args);


// Para debuggear
void imprimirTablaPpal(Node *n);
void imprimirTablaFunc(Node *n);


TablaSimbolos *getPrimaryScope(Node *node);
TablaSimbolos *getFuncScope(Node *node);
int getNumMetodosSobreescribibles(Node *node);

HT_item *buscarSimbolo(Node *node, char *nombre_id);
HT_item *buscarSimboloFunc(Node *node, char *nombre_id);
HT_item *buscarSimboloEnAmbitoActual(Node *node, char *nombre_id);

char **get_atributos_clase(Node *n);
char **get_atributos_instancia(Node *n);
char **get_metodos_sobreescribibles(Node *n);
char **get_metodos_no_sobreescribibles(Node *n);

#endif
