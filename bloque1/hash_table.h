/***************************************************************************
hash_table.h

PAULEN
***************************************************************************/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>

// Posicionar estos defines
/* Categoría del dato */
#define VARIABLE 1
#define PARAMETRO 2
#define FUNCION 3
/* Tipo básico de dato */
#define ESCALAR 1
#define VECTOR 2
/* Clase del dato */
#define ESCALAR 1
#define VECTOR 2



typedef struct _HT_item HT_item;
typedef struct _HT_hash_table HT_hash_table;
typedef struct _Element Element;



int is_prime(int num);
int next_prime(int num);


HT_hash_table * ht_new();
void ht_del_hash_table(HT_hash_table* ht);
HT_item * ht_insert_item(HT_hash_table* ht, const char* key,int category, int basic_type, int basic_class, int num_rows, int num_params, int param_position, int num_local_variables, int local_variable_position);
HT_item * ht_search_item(HT_hash_table* ht, const char* key);
HT_item * ht_modify_item(HT_hash_table* ht, const char* key,int category, int basic_type, int basic_class, int num_rows, int num_params, int param_position, int num_local_variables, int local_variable_position);
Element * ht_item_get_value(HT_item * item);
void ht_del_hash_table(HT_hash_table* h);

#endif /* HASH_TABLE_H */