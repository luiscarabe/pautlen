// Implementation of a node containing a string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "hash_table.h"

typedef struct _Node {
	char *name;
	TablaSimbolos *primary_scope;
	TablaSimbolos *func_scope;
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

char **getAttributes(Node *node){
	if (!node) return NULL;

	return ht_get_name_symbols(node->primary_scope);
}

int getNumAttributes(Node *node){
	if (!node) return -1;

	return ht_get_count(node->primary_scope);
}

int insertarTablaSimbolos(Node *node,
		const char* key,            int categoria,  
		int tipo,                   int clase, 
		int direcciones,            int numero_parametros, 
		int posicion_parametro,     int numero_variables_locales, 
		int posicion_variable_local,
		int tamanio,                int numero_atributos_clase, 
		int numero_atributos_instancia, 
		int numero_metodos_sobreescribibles, 
		int numero_metodos_no_sobreescribibles, 
		int tipo_acceso,            int tipo_miembro, 
		int posicion_atributo_instancia, 
		int posicion_metodo_sobreescribible, 
		int num_acumulado_atributos_instancia, 
		int num_acumulado_metodos_sobreescritura, 
		int * tipo_args){
	
	if (!node || !key) return -1;

	if (!ht_insert_item(node->primary_scope, 
										 key,
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
										 tipo_args))
		return -1;
	return 0;
}

int abrirAmbitoFunc(Node *node,
                                char* id_ambito, 
                                int categoria_ambito, 
                                int acceso_metodo, 
                                int tipo_metodo, 
                                int posicion_metodo_sobre, 
                                int tamanio){
	char *name;

	if (!node) return -1;

	name = (char *) malloc(sizeof(char) * (strlen(node->name) + strlen(id_ambito) + 2));
	if (!name) return -1;

	if (strcpy(name, node->name) < 0){
		free(name);
		return -1;
	}

	if (!strcat(strcat(name, "_"), id_ambito)){
		free(name);
		return -1;
	}

	if (!ht_insert_item(node->primary_scope, 
										 name,
										 categoria_ambito,
										 tipo_metodo,
										 0,
										 0,
										 0,
										 0,
										 0,
										 0,
										 tamanio,
										 0,
										 0,
										 0,
										 0,
										 acceso_metodo,
										 0,
										 0,
										 posicion_metodo_sobre,
										 0,
										 0,
										 0)){
		free(name);
		return -1;
	}

	free(name);

	node->func_scope = ht_new();
	if (!node->func_scope) return -1;

	if (!ht_insert_item(node->func_scope, 
										 id_ambito,
										 categoria_ambito,
										 tipo_metodo,
										 0,
										 0,
										 0,
										 0,
										 0,
										 0,
										 tamanio,
										 0,
										 0,
										 0,
										 0,
										 acceso_metodo,
										 0,
										 0,
										 posicion_metodo_sobre,
										 0,
										 0,
										 0)){
		ht_del_hash_table(node->func_scope);
		return -1;
	}

	return 0;
}

int cerrarAmbitoFunc(Node *node){
	if (!node) return -1;

	ht_del_hash_table(node->func_scope);
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

Element *buscarSimbolo(Node *node, char *nombre_id){
	char *name;
	Element *e;

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

	e = ht_item_get_value(ht_search_item(node->primary_scope, name));

	free(name);

	return e;
}
