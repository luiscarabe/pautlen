/***************************************************************************
hash_table.h

PAULEN
***************************************************************************/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>

// Elemento de la tabla hash
typedef struct _ht_item {
  char* key;
  void* value;
  _ht_item* next;
} ht_item;

typedef struct {
	char* name;// crear funcion que devuelva el nombre de la tabla
	int size;
	int count;
	ht_item ** items;
}ht_hash_table;


void ht_insert(ht_hash_table* ht, const char* key, const char* value);
char* ht_search(ht_hash_table* ht, const char* key);
void ht_delete(ht_hash_table* h, const char* key);

#endif /* HASH_TABLE_H */