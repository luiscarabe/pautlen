// Implementation of a node containing a string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "hash_table.h"

typedef struct _Node {
	char *name;
	void *content;
	HT_hash_table *primary_scope;
	HT_hash_table *func_scope;
} Node;

Node *newNode(char *name, void *content){
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
	newNode->content = content;
	return newNode;
}

void deleteNode(Node *node){
	if (!node) return;
	ht_del_hash_table(node->primary_scope);
	free(node->name);
	free(node);
}

void printNode(Node *node){
	printf("%s: %p", node->name, node->content);
}

int nameCompare(Node *node, char *name){
	if (!node | !name) return 0;
	return strcmp(node->name, name);
}

void *getContent(Node *node){
	if (!node) return NULL;
	return node->content;
}