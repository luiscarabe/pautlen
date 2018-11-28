// Implementation of a node containing a string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "hash_table.h"
#include "omicron.h"

typedef struct _Node {
	char *name;
	TablaSimbolos *primary_scope;
	TablaSimbolos *func_scope;
	char *curr_func;
} Node;

Node *newNode(char *name){
	Node *newNode;
	int len;

	newNode = (Node *) malloc(sizeof(Node));
	if (!newNode) return NULL;

	newNode->primary_scope = ht_new();
	if (!newNode->primary_scope){
		free(newNode);
	}

	newNode->func_scope = NULL;

	len = strlen(name);
	newNode->name = (char *) malloc((len+1)*sizeof(char));
	if (!newNode->name){
		ht_del_hash_table(newNode->primary_scope);
		free(newNode);
		return NULL;
	}

	strcpy(newNode->name, name);
	return newNode;
}

Node *newNodeTam(char *name, int tamanio){
	Node *newNode;
	int len;

	newNode = (Node *) malloc(sizeof(Node));
	if (!newNode) return NULL;

	newNode->primary_scope = new_tabla_simbolos(tamanio);
	if (!newNode->primary_scope){
		free(newNode);
	}

	newNode->func_scope = NULL;

	len = strlen(name);
	newNode->name = (char *) malloc((len+1)*sizeof(char));
	if (!newNode->name){
		ht_del_hash_table(newNode->primary_scope);
		free(newNode);
		return NULL;
	}

	strcpy(newNode->name, name);
	return newNode;
}

void deleteNode(Node *node){
	if (!node) return;
	ht_del_hash_table(node->primary_scope);
	free(node->name);
	free(node);
}

void printNode(Node *node){
	printf("%s", node->name);
}

int nameCompare(Node *node, char *name){
	if (!node || !name) return -1;
	return strcmp(node->name, name);
}

char *getName(Node *node){
	if (!node) return NULL;
	return node->name;
}

char *getNameFunc(Node *node){
	if (!node) return NULL;
	return node->curr_func;
}

char **getAttributes(Node *node){
	if (!node) return NULL;

	return ht_get_name_symbols(node->primary_scope);
}

int getNumAttributes(Node *node){
	if (!node) return -1;

	return ht_get_count(node->primary_scope);
}

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
// 		int * tipo_args){

// 	// char *name;

// 	if (numero_parametros < 0 || !node || !key) return ERR;
// 	if (!node->curr_func) return ERR;

	
// 	// name = (char *) malloc(sizeof(char) * (strlen(key) + 2 + strlen(node->curr_func)));
// 	// if (!name) return ERR;
	
// 	// if(strcpy(name, node->curr_func) < 0){
// 	// 	free(name);
// 	// 	return ERR;
// 	// }

// 	// if (!strcat(strcat(name, "_"), key)){
// 	// 	free(name);
// 	// 	return ERR;
// 	// }

// 	if (!ht_insert_item(node->func_scope, 
// 										 key,
// 										 categoria,
// 										 tipo,
// 										 clase,
// 										 direcciones,
// 										 numero_parametros,
// 										 posicion_parametro,
// 										 posicion_variable_local,
// 										 tamanio,
// 										 tipo_acceso,
// 										 tipo_miembro,
// 										 posicion_atributo_instancia,
// 										 posicion_metodo_sobreescribible,
// 										 tipo_args))
// 		return ERR;
// 	return OK;
// }

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
// 		int * tipo_args){
// 	char *name, type[2];
// 	int i;
	
// 	if (!node || !key) return -1;

// 	// if (categoria == FUNCION || categoria == METODO_SOBREESCRIBIBLE || categoria == METODO_NO_SOBREESCRIBIBLE){
// 	// 	if (numero_parametros < 0 || !tipo_args) return ERR;
// 	// 	name = (char *) malloc(sizeof(char) * (strlen(key) + 1 + 2*numero_parametros));
// 	// 	if (!name) return ERR;
// 	// 	if(strcpy(name, key) < 0){
// 	// 		free(name);
// 	// 		return ERR;
// 	// 	}
// 	// 	for (i = 0; i < numero_parametros; i ++){
// 	// 		sprintf(type, "%d", tipo_args[i]);
// 	// 		if (strcat(strcat(name, "@"), type) < 0){
// 	// 			free(name);
// 	// 			return ERR;
// 	// 		}
// 	// 	}
// 	// } else {
// 	// 	name = key;
// 	// }

// 	if (!ht_insert_item(node->primary_scope, 
// 										 key,
// 										 categoria,
// 										 tipo,
// 										 clase,
// 										 direcciones,
// 										 numero_parametros,
// 										 posicion_parametro,
// 										 posicion_variable_local,
// 										 tamanio,
// 										 tipo_acceso,
// 										 tipo_miembro,
// 										 posicion_atributo_instancia,
// 										 posicion_metodo_sobreescribible,
// 										 tipo_args))
// 		return -1;
// 	return 0;
// }

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
		int * tipo_args){
	
	TablaSimbolos *ts;

	if (!node || !key) return -1;

	// if (categoria == FUNCION || categoria == METODO_SOBREESCRIBIBLE || categoria == METODO_NO_SOBREESCRIBIBLE){
	// 	if (numero_parametros < 0 || !tipo_args) return ERR;
	// 	name = (char *) malloc(sizeof(char) * (strlen(key) + 1 + 2*numero_parametros));
	// 	if (!name) return ERR;
	// 	if(strcpy(name, key) < 0){
	// 		free(name);
	// 		return ERR;
	// 	}
	// 	for (i = 0; i < numero_parametros; i ++){
	// 		sprintf(type, "%d", tipo_args[i]);
	// 		if (strcat(strcat(name, "@"), type) < 0){
	// 			free(name);
	// 			return ERR;
	// 		}
	// 	}
	// } else {
	// 	name = key;
	// }

	if (node->func_scope)
		ts = node->func_scope;
	else
		ts = node->primary_scope;

	if (!ht_insert_item(ts, 
										 key,
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
										 tipo_args))
			return ERR;

	return OK;
	
}

int abrirAmbitoFunc(Node *node,
                    char* id_ambito, 
                    int categoria_ambito, 
                    int acceso_metodo, 
                    int tipo_metodo, 
                    int posicion_metodo_sobre, 
                    int tamanio,
                    int numero_parametros,
                    int *tipo_args){
	char *name;

	if (!node) return -1;

	name = (char *) malloc(sizeof(char) * (strlen(id_ambito) + 1));
	if (!name)	return -1;

	if (strcpy(name, id_ambito) < 0){
		free(name);
		return -1;
	}

	node->curr_func = (char *) malloc(sizeof(char) * (strlen(id_ambito) + 1));
	if (!node->curr_func){
		free(name);
		return -1;
	}

	strtok(name, "_");
	strcpy(node->curr_func, strtok(NULL, "_"));


	// for (i = 0; i < numero_parametros; i++){
	// 	sprintf(type, "%d", tipo_args[i]);
	// 	if (!strcat(strcat(node->curr_func, "@"), type)){
	// 		free(node->curr_func);
	// 		node->curr_func = NULL;
	// 		return ERR;
	// 	}
	// }

	// name = (char *) malloc(sizeof(char) * (strlen(node->name) + strlen(node->curr_func) + 1));
	// if (!name){
	// 	free(node->curr_func);
	// 	node->curr_func = NULL;
	// 	return -1;
	// }

	// if (strcpy(name, node->name) < 0){
	// 	free(name);
	// 	free(node->curr_func);
	// 	node->curr_func = NULL;
	// 	return -1;
	// }

	// if (!strcat(strcat(name, "_"), node->curr_func)){
	// 	free(name);
	// 	free(node->curr_func);
	// 	node->curr_func = NULL;
	// 	return -1;
	// }

	if (!ht_insert_item(node->primary_scope, 
										 id_ambito,
										 categoria_ambito,
										 tipo_metodo,
										 METODO_SOBREESCRIBIBLE,
										 0,
										 numero_parametros,
										 0,
										 0,
										 tamanio,
										 acceso_metodo,
										 0,
										 0,
										 posicion_metodo_sobre,
										 tipo_args)){
		free(name);
		free(node->curr_func);
		node->curr_func = NULL;
		return -1;
	}

	node->func_scope = ht_new();
	if (!node->func_scope){
		free(name);
		free(node->curr_func);
		node->curr_func = NULL;
	 	return -1;
	}

	if (!ht_insert_item(node->func_scope, 
										 id_ambito,
										 categoria_ambito,
										 tipo_metodo,
										 METODO_SOBREESCRIBIBLE,
										 0,
										 numero_parametros,
										 0,
										 0,
										 tamanio,
										 acceso_metodo,
										 0,
										 0,
										 posicion_metodo_sobre,
										 tipo_args)){
		ht_del_hash_table(node->func_scope);
		free(name);
		free(node->curr_func);
		node->curr_func = NULL;
		return -1;
	}
	free(name);

	return 0;
}

int cerrarAmbitoFunc(Node *node){
	if (!node) return -1;

	ht_del_hash_table(node->func_scope);
	node->func_scope = NULL;

	free(node->curr_func);
	// node->curr_func = NULL;

	return 0;
}

void imprimirTablaPpal(Node *n){
	if (!n) return;
	imprimirTabla(n->primary_scope);
}

void imprimirTablaFunc(Node *n){
	if (!n) return;
	imprimirTabla(n->func_scope);
}

TablaSimbolos *getPrimaryScope(Node *node){
	if (!node) return NULL;
	return node->primary_scope;
}

TablaSimbolos *getFuncScope(Node *node){
	if (!node) return NULL;
	return node->func_scope;
}

HT_item *buscarSimbolo(Node *node, char *nombre_id){
	char *name;
	HT_item *e;

	if (!node || !nombre_id) return NULL;

	name = (char *) malloc(sizeof(char) * (strlen(node->name) + strlen(nombre_id) + 2));
	if (!name) return NULL;

	if (strcpy(name, node->name) < 0){
		free(name);
		return NULL;
	}

	if (!strcat(strcat(name, "_"), nombre_id)){
		free(name);
		return NULL;
	}

	e = ht_search_item(node->primary_scope, name);

	free(name);

	return e;
}

HT_item *buscarSimboloFunc(Node *node, char *nombre_id){
	HT_item *e;
	char *name;
	
	if (!node || !nombre_id) return NULL;


	if (node->func_scope){
		name = (char *) malloc(sizeof(char) * (strlen(node->curr_func) + strlen(nombre_id) + 2));
		if (!name) return NULL;

		if (strcpy(name, node->curr_func) < 0){
			free(name);
			return NULL;
		}

		if (!strcat(strcat(name, "_"), nombre_id)){
			free(name);
			return NULL;
		}

		e = ht_search_item(node->func_scope, nombre_id);

		return e;
	}
	return NULL;
}

HT_item *buscarSimboloEnAmbitoActual(Node *node, char *nombre_id){
	if (!node || !nombre_id) return NULL;

	if (node->func_scope){
		return ht_search_item(node->func_scope, nombre_id);
	}
	else
		return ht_search_item(node->primary_scope, nombre_id);
}
