/***************************************************************************
hash_table.c

PAULEN
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash_table.h"

#define HASHSIZE 3 // Prime number to choose
#define POW 191 // Prime for the hash


/* Item de la tabla hash */
struct _HT_item {
	char* key; // Key value
	struct _Element * value;
	struct _HT_item* next;
};
/* Tabla hash */
struct _HT_hash_table {
	char* name;// crear funcion que devuelva el nombre de la tabla
	int size;
	int count;
	HT_item ** items;
};
/* Elemento de la tabla hash */
struct _Element{
	int category;// 3: variable, parámetro de función, función o clase
	int basic_type;// 2: boolean e int
	int basic_class;// 2: escalar y vector
	int num_rows;// Sólo para identificadores de vectores
	int num_params;// Sólo para Elementos de tipo función
	int param_position;// Sólo para Elementos de tipo paraámetro de función
	int num_local_variables;// Sólo para Elementos de tipo función
	int local_variable_position;// Variable local de función
};



/**********************************************/
/*																						*/
/*																						*/
/*						AUXILIAR FUNCTIONS							*/
/*																						*/
/*																						*/
/**********************************************/

// Returns if the given number is prime
int is_prime(int num){
	int i, limit;

	if((num % 2)==0)
		return num == 2;
	else {
		limit = sqrt(num);
		for (i = 3; i <= limit; i+=2){
			if (num % i == 0)
				return 0;
		}
	}
	return 1;
}

// Returns the next prime number of a given one
int next_prime(int num){
    int c;

    if(num < 2)
        c = 2;
    else if (num == 2)
        c = 3;
    else if(num % 2){
        num += 2;
        if (is_prime(num)){
        	return num;
        }else{
        	return next_prime(num);
        }
    } else
        c = next_prime(num + 1);

    return c;
}




/**********************************************/
/*																						*/
/*																						*/
/*									ELEMENT										*/
/*																						*/
/*																						*/
/**********************************************/
Element * new_element(int category,
											int basic_type,
											int basic_class,
											int num_rows,
											int num_params,
											int param_position,
											int num_local_variables,
											int local_variable_position){

	Element * e = NULL;

	if(category < 0 || basic_type < 0 || basic_class < 0 || num_rows < 0 || num_params < 0
		|| param_position < 0 || num_local_variables < 0 || local_variable_position < 0){
		/* If anyone of the arguments' value is less than zero return error */
		printf("ERROR. argumentos new element mal\n");
		return NULL;
	}

	e = (Element*)malloc(sizeof(Element));
	if(e == NULL){
		/* error */
		printf("ERROR. Elemento no creado\n");
		return NULL;
	}

	e->category = category;
	e->basic_type = basic_type;
	e->basic_class = basic_class;
	e->num_rows = num_rows;
	e->num_params = num_params;
	e->param_position = param_position;
	e->num_local_variables = num_local_variables;
	e->local_variable_position = local_variable_position;

	return e;
}

static int modify_element(Element * e,
													int category,
													int basic_type,
													int basic_class,
													int num_rows,
													int num_params,
													int param_position,
													int num_local_variables,
													int local_variable_position){

	if(e == NULL || category < 0 || basic_type < 0 || basic_class < 0 || num_rows < 0 || num_params < 0
		|| param_position < 0 || num_local_variables < 0 || local_variable_position < 0){
		/* If anyone of the arguments' value is less than zero return error */
		printf("ERROR. argumentos new element mal\n");
		return -1;
	}

	e->category = category;
	e->basic_type = basic_type;
	e->basic_class = basic_class;
	e->num_rows = num_rows;
	e->num_params = num_params;
	e->param_position = param_position;
	e->num_local_variables = num_local_variables;
	e->local_variable_position = local_variable_position;

	return 0;
}

static void del_element(Element * e){
	if(e == NULL){
		printf("ERROR. Elemento vacío\n");
		return;
	}

	free(e);
	return;
}


/**********************************************/
/*																						*/
/*																						*/
/*									HASH ITEM									*/
/*																						*/
/*																						*/
/**********************************************/






/* Generate new hash table item */
static HT_item* ht_new_item(const char* k,
														int category,
														int basic_type,
														int basic_class,
														int num_rows,
														int num_params,
														int param_position,
														int num_local_variables,
														int local_variable_position) {

		HT_item* item = malloc(sizeof(HT_item));
		if(item == NULL){
			/* Error */
			return NULL;
		}
		item->key = strdup(k);
		
		item->value = new_element(category,
															basic_type,
															basic_class,
															num_rows,
															num_params,
															param_position,
															num_local_variables,
															local_variable_position);

		if(item-> value == NULL){
			/* Error */
			free(item->key);
			free(item);
			return NULL;
		}

		item->next = NULL;

		return item;
}


int print_item(HT_item * item){
	if(item == NULL){
		return -1;
	}

	printf("Item %s:\n", item->key);
	printf("\t Categoria: %d\n", item->value->category);
	printf("\t Tipo básico: %d\n", item->value->basic_type);
	printf("\t Clase: %d\n", item->value->basic_class);
	printf("\t Número de filas: %d\n", item->value->num_rows);
	printf("\t Número de parámetros: %d\n", item->value->num_params);
	printf("\t Posición parámetro: %d\n", item->value->param_position);
	printf("\t Número de variables locales: %d\n", item->value->num_local_variables);
	printf("\t Posición variable local: %d\n", item->value->local_variable_position);

	return 0;
}

Element * ht_item_get_value(HT_item * item){
	if(item == NULL){
		return NULL;
	}

	return item->value;
}

/* Delete hash table item */
static void ht_del_item(HT_item* item) {
	if(item == NULL){
		printf("ERROR. Item vacío\n");
		return;
	}
	free(item->key);
	del_element(item->value);
	free(item);
}


/**********************************************/
/*																						*/
/*																						*/
/*							HASH FUNCTION									*/
/*																						*/
/*																						*/
/**********************************************/

/* EN CASO DE QUE LE QUERAMOS PONER TAMAÑO A CADA TABLA HASH
static int ht_get_hash(const char* s, const int size){
	long hash = 0;
	const int len_s = strlen(s);
	for (int i = 0; i < len_s; i++){
			hash += (long)pow(a, len_s - (i+1)) * s[i];
			hash = hash % size;
	}
	return (int)hash;
}
*/
/* Returs the hash value of an item */
static int ht_get_hash(const char* s, const int size){
	long hash = 0;
	const int len_s = strlen(s);
	for (int i = 0; i < len_s; i++){
			hash += (long)pow(POW, len_s - (i+1)) * s[i];
			hash = hash % size;
	}
	return (int)hash;
}


/**********************************************/
/*																						*/
/*																						*/
/*								HASH TABLE									*/
/*																						*/
/*																						*/
/**********************************************/


/* EN CASO DE QUE LE QUERAMOS PONER TAMAÑO A CADA TABLA HASH
HT_hash_table* ht_new(int min_size) {
		HT_hash_table* ht = NULL;
		int num;

		if(!is_prime(min_size)){
			num = next_prime(min_size);
		}else{
			num = min_size;
		}
		ht = malloc(sizeof(HT_hash_table));
		if(ht == NULL){
			return NULL;
		}

		ht->size = num;
		ht->count = 0;
		// Make them point to NULL
		ht->items = calloc((size_t)ht->size, sizeof(HT_item*));
		return ht;
}
*/

/* Generate new hash table */
HT_hash_table* ht_new() {
		HT_hash_table* ht = NULL;

		ht = malloc(sizeof(HT_hash_table));
		if(ht == NULL){
			return NULL;
		}

		ht->size = HASHSIZE;
		ht->count = 0;
		// Make them point to NULL
		ht->items = (HT_item **) calloc(HASHSIZE, sizeof(HT_item *));
		if(ht->items == NULL){
			free(ht);
			return NULL;
		}
		return ht;
}

/* Delete row of items */
static void ht_del_row(HT_item* item){
	if(item->next != NULL){
		ht_del_row(item->next);
	}
	ht_del_item(item);
	return;
}

/* Delete hash table */
void ht_del_hash_table(HT_hash_table* ht) {
	HT_item* item = NULL;

	for (int i = 0; i < ht->size; i++) {
			item = ht->items[i];
			if (item != NULL) {
					ht_del_row(item);
			}
	}
	free(ht->items);
	free(ht);
}

HT_item * ht_insert_item(HT_hash_table* ht, const char* key,
																			int category,
																			int basic_type,
																			int basic_class,
																			int num_rows,
																			int num_params,
																			int param_position,
																			int num_local_variables,
																			int local_variable_position) {


	int index;
	HT_item* cur_item = NULL;

	HT_item* item = ht_new_item(key,
															category,
															basic_type,
															basic_class,
															num_rows,
															num_params,
															param_position,
															num_local_variables,
															local_variable_position);

	if (item == NULL) {
		ht_del_item(item);
		printf("ERROR, no se ha creado el item\n");
		return NULL;
	}
	index = ht_get_hash(item->key, ht->size);
	printf(" INDEXXXXX %d\n", index);
	cur_item = ht->items[index];
	if(cur_item == NULL){
		// If the position in the hash table is empty
		ht->items[index] = item;
		ht->count++;
	}else{
		// Collision
		if(strcmp(cur_item->key, item->key) == 0){
			ht_del_item(item);
			printf("ERROR, el item ya existe en la tabla\n");
			return NULL;
		}
		// If not check the next position in the linked list
		while (cur_item->next != NULL) {
			if(strcmp(cur_item->key, item->key) == 0){
				ht_del_item(item);
				printf("ERROR, el item ya existe en la tabla\n");
				return NULL;
			}
			cur_item = cur_item->next;
		}
		// When NULL make it point to the new item
		cur_item->next = item;
		ht->count++;
	}
	return item;
}


// Returns the value of the item if exists
HT_item * ht_search_item(HT_hash_table* ht, const char* key) {
	int index;
	HT_item* item = NULL;


	if(ht == NULL || key == NULL){
		printf("ERROR buscando elemento. Tabla o key vacías.\n");
		return NULL;
	}

	index = ht_get_hash(key, ht->size);

	item = ht->items[index];
	if(item == NULL){
		printf("ERROR. la posición en la tabla está vacía\n");
		return NULL;
	}

	while (strcmp(item->key, key) != 0) {
		if(item->next == NULL){
			return NULL;
		}
		item = item->next;
	}
	return item;
}

HT_item * ht_modify_item(HT_hash_table* ht, const char* key,
																						int category,
																						int basic_type,
																						int basic_class,
																						int num_rows,
																						int num_params,
																						int param_position,
																						int num_local_variables,
																						int local_variable_position){

	HT_item * item = NULL;
	int res = -1;

	if(ht == NULL || key == NULL){
		printf("ERROR buscando elemento. Tabla o key vacías.\n");
		return NULL;
	}

	item = ht_search_item(ht, key);
	if(item == NULL){
		printf("ERROR al modificar item. El item no existe\n");
		return NULL;
	}


	res = modify_element(item->value, category, basic_type, basic_class, num_rows, num_params, param_position, num_local_variables, local_variable_position );
	if(res != 0){
		printf("ERROR al modificar item. Fallo en la actualización de los valores\n");
		return NULL;
	}

	return item;
}
