/***************************************************************************
hash_table.c

PAULEN
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash_table.h"

#define HASHSIZE 3 // Prime number to choose 1009 
#define POW 191 // Prime for the hash


/* Item de la tabla hash */
struct _HT_item {
	char* key; // Key value
	struct _Element * value;
	struct _HT_item* next;
};
/* Tabla hash */
struct _TablaSimbolos {
	int size;
	int count;
	HT_item ** items;
};
/* Elemento de la tabla hash */
struct _Element{
	/* VARIABLE PARAMETRO FUNCION CLASE METODO_SOBREESCRIBIBLE METODO_NO_SOBREESCRIBIBLE ATRIBUTO_CLASE ATRIBUTO_INSTANCIA */
	int categoria;// 3: variable, parámetro de función, función o clase
	/* INT FLOAT (no este curso) BOOLEAN Y PARA LAS CLASES, ALGÚN MECANISMO (-índice en el vector del grafo??)  */
	int tipo;// 2: boolean e int
	/* ESCALAR PUNTERO VECTOR CONJUNTO (no este año) OBJETO */
	int clase;


	int direcciones;/* >=1  SI ES VARIABLE 1*/
	int numero_parametros;// Sólo para Elementos de tipo función
	int posicion_parametro;// Sólo para Elementos de tipo paraámetro de función
	int numero_variables_locales;// Sólo para Elementos de tipo función
	int posicion_variable_local;// Variable local de función
	int tamanio;		/* 1-64 */
	/* INFORMACION PARA CLASES */
	int numero_atributos_clase;
	int numero_atributos_instancia;
	int numero_metodos_sobreescribibles;
	int numero_metodos_no_sobreescribibles;
	/*NINGUNO (exposed) ACCESO_CLASE (hidden) ACCESO_HERENCIA	(secret) ACCESO_TODOS (exposed) */
	int tipo_acceso;  
	/*MIEMBRO_UNICO (unique) MIEMBRO_NO_UNICO*/
	int tipo_miembro;
		
	int posicion_atributo_instancia;
	int posicion_metodo_sobreescribible;
	int num_acumulado_atributos_instancia;
	int num_acumulado_metodos_sobreescritura;
	int * tipo_args;
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
Element * new_element(int categoria,
											int tipo,
											int clase,
											int direcciones,
											int numero_parametros,
											int posicion_parametro,
											int posicion_variable_local,
											int tamanio,
											int tipo_acceso,
											int tipo_miembro,
											int posicion_atributo_instancia,
											int posicion_metodo_sobreescribible,
											int * tipo_args){

	Element * e = NULL;

	if(categoria < 0 || tipo < 0 || clase < 0 || direcciones < 0 || numero_parametros < 0
		|| posicion_parametro < 0 || posicion_variable_local < 0){
		/* If anyone of the arguments' value is less than zero return error */
		//printf("ERROR. argumentos new element mal\n");
		return NULL;
	}

	e = (Element*)malloc(sizeof(Element));
	if(e == NULL){
		/* error */
		//printf("ERROR. Elemento no creado\n");
		return NULL;
	}
	// esto se multiplica por numero parametros?
	/*e->tipo_args = (int*)malloc(sizeof(int));
	if(e->tipo_args == NULL){*/
		/* error */
	/*	free(e);
		//printf("ERROR. Elemento no creado\n");
		return NULL;
	}*/
	e->tipo_args = tipo_args;

	e->categoria = categoria;
	e->tipo = tipo;
	e->clase = clase;
	e->direcciones = direcciones;
	e->numero_parametros = numero_parametros;
	e->posicion_parametro = posicion_parametro;
	e->numero_variables_locales = 0;
	e->posicion_variable_local = posicion_variable_local;
	e->tamanio = tamanio;
	e->numero_atributos_clase = 0;
	e->numero_atributos_instancia = 0;
	e->numero_metodos_sobreescribibles = 0;
	e->numero_metodos_no_sobreescribibles = 0;
	e->tipo_acceso = tipo_acceso;
	e->tipo_miembro = tipo_miembro;
	e->posicion_atributo_instancia = posicion_atributo_instancia;
	e->posicion_metodo_sobreescribible = posicion_metodo_sobreescribible;
	e->num_acumulado_atributos_instancia = 0;
	e->num_acumulado_metodos_sobreescritura = 0;

	return e;
}

static int modify_element(Element * e,
													int categoria,
													int tipo,
													int clase,
													int direcciones,
													int numero_parametros,
													int posicion_parametro,
													int numero_variables_locales,
													int posicion_variable_local,
													int tamanio,
													int numero_atributos_clase,
													int numero_atributos_instancia,
													int numero_metodos_sobreescribibles,
													int numero_metodos_no_sobreescribibles,
													int tipo_acceso,
													int tipo_miembro,
													int posicion_atributo_instancia,
													int posicion_metodo_sobreescribible,
													int num_acumulado_atributos_instancia,
													int num_acumulado_metodos_sobreescritura,
													int * tipo_args){

	if(e == NULL || categoria < 0 || tipo < 0 || clase < 0 || direcciones < 0 || numero_parametros < 0
		|| posicion_parametro < 0 || numero_variables_locales < 0 || posicion_variable_local < 0){
		/* If anyone of the arguments' value is less than zero return error */
		//printf("ERROR. argumentos new element mal\n");
		return -1;
	}

	// esto se multiplica por numero parametros?
	/*e->tipo_args = (int*)malloc(sizeof(int));
	if(e->tipo_args == NULL){*/
		/* error */
		/*free(e);
		//printf("ERROR. Elemento no creado\n");
		return NULL;
	}*/
	e->tipo_args = tipo_args;

	e->categoria = categoria;
	e->tipo = tipo;
	e->clase = clase;
	e->direcciones = direcciones;
	e->numero_parametros = numero_parametros;
	e->posicion_parametro = posicion_parametro;
	e->numero_variables_locales = numero_variables_locales;
	e->posicion_variable_local = posicion_variable_local;
	e->tamanio = tamanio;
	e->numero_atributos_clase = numero_atributos_clase;
	e->numero_atributos_instancia = numero_atributos_instancia;
	e->numero_metodos_sobreescribibles = numero_metodos_sobreescribibles;
	e->numero_metodos_no_sobreescribibles = numero_metodos_no_sobreescribibles;
	e->tipo_acceso = tipo_acceso;
	e->tipo_miembro = tipo_miembro;
	e->posicion_atributo_instancia = posicion_atributo_instancia;
	e->posicion_metodo_sobreescribible = posicion_metodo_sobreescribible;
	e->num_acumulado_atributos_instancia = num_acumulado_atributos_instancia;
	e->num_acumulado_metodos_sobreescritura = num_acumulado_metodos_sobreescritura;

	return 0;
}

static void del_element(Element * e){
	if(e == NULL){
		//printf("ERROR. Elemento vacío\n");
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
														int categoria,
														int tipo,
														int clase,
														int direcciones,
														int numero_parametros,
														int posicion_parametro,
														int posicion_variable_local,
														int tamanio,
														int tipo_acceso,
														int tipo_miembro,
														int posicion_atributo_instancia,
														int posicion_metodo_sobreescribible,
														int * tipo_args) {

		HT_item* item = malloc(sizeof(HT_item));
		if(item == NULL){
			/* Error */
			return NULL;
		}
		item->key = strdup(k);
		
		item->value = new_element(categoria,
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
															tipo_args);

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
	printf("\t Categoria: %d\n", item->value->categoria);
	printf("\t Tipo básico: %d\n", item->value->tipo);
	printf("\t Clase: %d\n", item->value->clase);
	printf("\t Direcciones: %d\n", item->value->direcciones);
	printf("\t Número de parámetros: %d\n", item->value->numero_parametros);
	printf("\t Posición parámetro: %d\n", item->value->posicion_parametro);
	printf("\t Número de variables locales: %d\n", item->value->numero_variables_locales);
	printf("\t Posición variable local: %d\n", item->value->posicion_variable_local);
	printf("\t Tamaño: %d\n", item->value->tamanio);
	printf("\t Número atributos clase: %d\n", item->value->numero_atributos_clase);
	printf("\t Número atributos instancia: %d\n", item->value->numero_atributos_instancia);
	printf("\t Número métodos sobreescribibles: %d\n", item->value->numero_metodos_sobreescribibles);
	printf("\t Número métodos no sobreescribibles: %d\n", item->value->numero_metodos_no_sobreescribibles);
	printf("\t Número acumulado atributos instancia: %d\n", item->value->num_acumulado_atributos_instancia);
	printf("\t Número acumulado métodos sobrescritura: %d\n", item->value->num_acumulado_metodos_sobreescritura);
	if (item->value->tipo_args)
		printf("\t Puntero %d\n", *(item->value->tipo_args)); // (Primera posicion del array)
	else
		printf("\t Puntero: (null)");

	return 0;
}

Element * ht_item_get_value(HT_item * item){
	if(item == NULL){
		return NULL;
	}

	return item->value;
}

char * ht_item_get_name(HT_item * item){
	if(item == NULL){
		return NULL;
	}

	return item->key;
}



/* Delete hash table item */
static void ht_del_item(HT_item* item) {
	if(item == NULL){
		//printf("ERROR. Item vacío\n");
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


/* EN CASO DE QUE LE QUERAMOS PONER TAMAÑO A CADA TABLA HASH */
/* Generate new hash table */
TablaSimbolos* new_tabla_simbolos(int min_size) {
		TablaSimbolos* ht = NULL;
		int num;

		if(!is_prime(min_size)){
			num = next_prime(min_size);
		}else{
			num = min_size;
		}
		ht = malloc(sizeof(TablaSimbolos));
		if(ht == NULL){
			return NULL;
		}

		ht->size = num;
		ht->count = 0;
		// Make them point to NULL
		ht->items = (HT_item **) calloc(ht->size, sizeof(HT_item *));
		if(ht->items == NULL){
			free(ht);
			return NULL;
		}
		return ht;
}


/* Generate new hash table */
TablaSimbolos* ht_new() {
		TablaSimbolos* ht = NULL;

		ht = malloc(sizeof(TablaSimbolos));
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

int ht_get_size(TablaSimbolos * ts){
	if(ts == NULL){
		//printf("ERROR, la tabla simbolos no existe\n");
		return -1;
	}

	return ts->size;
}
int ht_get_count(TablaSimbolos * ts){
	if(ts == NULL){
		//printf("ERROR, la tabla simbolos no existe\n");
		return -1;
	}

	return ts->count;
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
void ht_del_hash_table(TablaSimbolos* ht) {
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

HT_item * ht_insert_item(TablaSimbolos* ht, 
		const char* key,							int categoria,	
		int tipo,											int clase, 
		int direcciones, 							int numero_parametros, 
		int posicion_parametro,
		int posicion_variable_local, 	int tamanio, 
		int tipo_acceso, 							int tipo_miembro, 
		int posicion_atributo_instancia, 
		int posicion_metodo_sobreescribible, 
		int * tipo_args) {


	int index;
	HT_item* cur_item = NULL;

	HT_item* item = ht_new_item(key,
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
															tipo_args);

	if (item == NULL) {
		ht_del_item(item);
		//printf("ERROR, no se ha creado el item\n");
		return NULL;
	}
	index = ht_get_hash(item->key, ht->size);
	//printf(" INDEXXXXX %d\n", index);
	cur_item = ht->items[index];
	if(cur_item == NULL){
		// If the position in the hash table is empty
		ht->items[index] = item;
		ht->count++;
	}else{
		// Collision
		if(strcmp(cur_item->key, item->key) == 0){
			ht_del_item(item);
			//printf("ERROR, el item ya existe en la tabla\n");
			return NULL;
		}
		// If not check the next position in the linked list
		while (cur_item->next != NULL) {
			if(strcmp(cur_item->key, item->key) == 0){
				ht_del_item(item);
				//printf("ERROR, el item ya existe en la tabla\n");
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

/* Auxiliar */

int get_names_row(HT_item * item,char ** names, int *count){
	if(item == NULL || names == NULL){
		//printf("ERROR, item vacío\n");
		return -1;
	}
	names[count[0]] = strdup(item->key);
	if(names[count[0]] == NULL){
		//printf("ERROR, no se ha copiado el nombre del elemento\n");
		return -1;
	}
	count[0]++;
	if(item->next != NULL){
		if(get_names_row(item->next, names, count) != 0){
			//printf("ERROR, en la recursión al coger nombres\n");
			return -1;
		}
	}

	
	
	return 0;
}


char ** ht_get_name_symbols(TablaSimbolos * ts){
	char ** names = NULL;
	int count[1];
	int i;
	if(ts == NULL){
		//printf("ERROR, al coger los nombres de los elementos de la tabla, ésta no existe\n");
		return NULL;
	}

	count[0] = 0;
	names = (char **)malloc(sizeof(char*) * ts->count);
	if(names == NULL){
		//printf("ERROR: No se ha podido guardar memoria para los nombres\n");
		return NULL;
	}
	for(i = 0; i < ts->size; i ++){
		if(ts->items[i] != NULL){
			if(get_names_row(ts->items[i], names, count) != 0){
				//printf("ERROR, al coger nombres de fila\n");
				return NULL;
			}
		}
	}
	if(names == NULL){
		//printf("algo faaaalla\n");
	}

	return names;
}

// Returns the value of the item if exists
HT_item * ht_search_item(TablaSimbolos* ht, const char* key) {
	int index;
	HT_item* item = NULL;


	if(ht == NULL || key == NULL){
		//printf("ERROR buscando elemento. Tabla o key vacías.\n");
		return NULL;
	}

	index = ht_get_hash(key, ht->size);

	item = ht->items[index];
	if(item == NULL){
		//printf("ERROR. la posición en la tabla está vacía\n");
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

HT_item * ht_modify_item(TablaSimbolos* ht, const char* key,
																						int categoria,
																						int tipo,
																						int clase,
																						int direcciones,
																						int numero_parametros,
																						int posicion_parametro,
																						int numero_variables_locales,
																						int posicion_variable_local,
																						int tamanio,
																						int numero_atributos_clase,
																						int numero_atributos_instancia,
																						int numero_metodos_sobreescribibles,
																						int numero_metodos_no_sobreescribibles,
																						int tipo_acceso,
																						int tipo_miembro,
																						int posicion_atributo_instancia,
																						int posicion_metodo_sobreescribible,
																						int num_acumulado_atributos_instancia,
																						int num_acumulado_metodos_sobreescritura,
																						int * tipo_args){

	HT_item * item = NULL;
	int res = -1;

	if(ht == NULL || key == NULL){
		//printf("ERROR buscando elemento. Tabla o key vacías.\n");
		return NULL;
	}

	item = ht_search_item(ht, key);
	if(item == NULL){
		//printf("ERROR al modificar item. El item no existe\n");
		return NULL;
	}


	res = modify_element(item->value,
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
															tipo_args);
	if(res != 0){
		//printf("ERROR al modificar item. Fallo en la actualización de los valores\n");
		return NULL;
	}

	return item;
}

void imprimirTabla(TablaSimbolos *ht){
	if (!ht) return;
	HT_item *next = NULL;

	for (int i = 0; i < ht->size; i++){
		if (ht->items[i]){
			print_item(ht->items[i]);
			printf("\n");
			
			next = ht->items[i]->next;
			while (next){
				print_item(next);
				printf("\n");
				next = next->next;
			}
		}
	}
}

int get_num_atributos_instancia(TablaSimbolos *ht, const char *key){
	HT_item *item;

	if (!ht || !key) return -1;

	item = ht_search_item(ht, key);
	if (!item) return -1;

	return item->value->numero_atributos_instancia;
}

int get_num_metodos_sobreescritura(TablaSimbolos *ht, const char *key){
	HT_item *item;

	if (!ht || !key) return -1;

	item = ht_search_item(ht, key);
	if (!item) return -1;

	return item->value->numero_metodos_sobreescribibles;
}

int get_num_atributos_instancia_acum(TablaSimbolos *ht, const char *key){
	HT_item *item;

	if (!ht || !key) return -1;

	item = ht_search_item(ht, key);
	if (!item) return -1;

	return item->value->num_acumulado_atributos_instancia;
}

int get_num_metodos_sobreescritura_acum(TablaSimbolos *ht, const char *key){
	HT_item *item;

	if (!ht || !key) return -1;

	item = ht_search_item(ht, key);
	if (!item) return -1;

	return item->value->num_acumulado_metodos_sobreescritura;
}

int modify_atributos_instancia(TablaSimbolos *ht, const char *key, int x, int (*f)(int *a, int b)){
	HT_item *item;

	if (!ht || !key) return -1;

	item = ht_search_item(ht, key);
	if (!item) return -1;

	return f(&item->value->numero_atributos_instancia, x);
}


int modify_metodos_sobreescritura(TablaSimbolos *ht, const char *key, int x, int (*f)(int *a, int b)){
	HT_item *item;

	if (!ht || !key) return -1;

	item = ht_search_item(ht, key);
	if (!item) return -1;

	return f(&item->value->numero_metodos_sobreescribibles, x);
}

int modify_atributos_instancia_acum(TablaSimbolos *ht, const char *key, int x, int (*f)(int *a, int b)){
	HT_item *item;

	if (!ht || !key) return -1;

	item = ht_search_item(ht, key);
	if (!item) return -1;

	return f(&item->value->num_acumulado_atributos_instancia, x);
}


int modify_metodos_sobre_acum(TablaSimbolos *ht, const char *key, int x, int (*f)(int *a, int b)){
	HT_item *item;

	if (!ht || !key) return -1;

	item = ht_search_item(ht, key);
	if (!item) return -1;

	return f(&item->value->num_acumulado_metodos_sobreescritura, x);
}


int HT_itemGetAccess(HT_item *e){
	if (!e) return -1;
	return e->value->tipo_acceso;
}

int HT_itemGetCategory(HT_item *e){
	if (!e) return -1;
	return e->value->categoria;
}

int HT_itemGetClass(HT_item *e){
	if (!e) return -1;
	return e->value->clase;
}

int HT_itemGetType(HT_item *e){
	if (!e) return -1;
	return e->value->tipo;
}