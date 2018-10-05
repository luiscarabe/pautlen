// Implementation of a node containing a string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

typedef struct _Node {
	char *name;
	// void * para tabla de ambitos
} Node;

Node *newNode(char *name){
	Node *newNode;
	int len;

	newNode = (Node *) malloc(sizeof(Node));
	if (!newNode) return NULL;

	len = strlen(name);
	newNode->name = (char *) malloc((len+1)*sizeof(char));
	if (!newNode->name){
		free(newNode);
		return NULL;
	}

	strcpy(newNode->name, name);
	return newNode;
}

Node *cloneNode(Node *node){
	if (!node) return NULL;
	return newNode(node->name);
}

void deleteNode(Node *node){
	if (!node) return;
	free(node->name);
	free(node);
}

void printNode(Node *node){
	printf("%s", node->name);
}