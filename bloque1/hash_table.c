/***************************************************************************
hash_table.h

PAULEN
***************************************************************************/





/* Resizable??????????????????????? */

#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"

#define HASHSIZE 29


/* Generate new hash table item */
static ht_item* ht_new_item(const char* k, const void* v) {
    ht_item* item = malloc(sizeof(ht_item));
    item->key = strdup(k);
    /* Copiar valor de  v*/
    /* item->value */
    item->next = NULL;

    return i;
}


/* Generate new hash table */
ht_hash_table* ht_new() {
    ht_hash_table* ht = malloc(sizeof(ht_hash_table));

    ht->size = HASHSIZE;
    ht->count = 0;
    // Make them point to NULL
    ht->items = calloc((size_t)ht->size, sizeof(ht_item*));
    return ht;
}

/* Delete hash table item */
static void ht_del_item(ht_item* item) {
    free(item->key);
    free(item->value);
    free(item);
}

/* Delete row of items */
void ht_del_row(ht_item* item){
	if(item->next != NULL){
		ht_del_row(item->next);
	}
	ht_del_item(item);
	return;
}

/* Delete hash table */
void ht_del_hash_table(ht_hash_table* ht) {
    for (int i = 0; i < ht->size; i++) {
        ht_item* item = ht->items[i];
        if (item != NULL) {
            ht_del_row(item);
        }
    }
    free(ht->items);
    free(ht);
}


static int ht_hash(const char* s, const int a, const int m){
  long hash = 0;
  const int len_s = strlen(s);
  for (int i = 0; i < len_s; i++){
      hash += (long)pow(a, len_s - (i+1)) * s[i];
      hash = hash % m;
  }
  return (int)hash;
}

static ht_item HT_DELETED_ITEM = {NULL, NULL};


int ht_insert(ht_hash_table* ht, const char* key, const void* value) {
	int index;
	ht_item* cur_item = NULL;
	ht_item*

  ht_item* item = ht_new_item(key, value);
  if (item == NULL) {
    ht_del_item(item);
    return -1;
  }
  index = ht_get_hash(item->key, ht->size, 0);
  cur_item = ht->items[index];
  if(cur_item == NULL){
  	// If the position in the hash table is empty
  	cur_item = item;
  	ht->count++;
  }else{
  	// Collision
  	// If not check the next position in the linked list
	  while (cur_item->next != NULL) {
	  	if(strcmp(cur_item->key, item->key) == 0){
	  		return -1;
	  	}
	  	cur_item = cur_item->next;
	  }
	  // When NULL make it point to the new item
	  cur_item->next = item;
	  ht->count++;
	}
	return 0;
}


// Devuelve el valor del item
void* ht_search(ht_hash_table* ht, const char* key) {
    int index = ht_get_hash(key, ht->size, 0);
    ht_item* item = ht->items[index];

    while (strcmp(item->key, key) != 0) {
    	if(item->next == NULL){
    		return NULL;
    	}
    	item = item->next;
    }
    return item->value;
}




// Mirar esto xDD
void ht_delete(ht_hash_table* ht, const char* key) {
    int index = ht_get_hash(key, ht->size, 0);
    ht_item* item = ht->items[index];
    ht-item* aux = NULL;

    while (strcmp(item->key, key) != 0) {
    	if(item->next == NULL){
    		return NULL;
    	}
    	aux = item;
    	item = item->next;
    }

    index = ht_get_hash(key, ht->size, i);
    item = ht->items[index];
    i++;
    
    ht->count--;
}





