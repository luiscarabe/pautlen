/**************************************************************************
hash_table.h

PAULEN
***************************************************************************/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>

// Posicionar estos defines
/* Categoría del dato */
enum categoria {
	VARIABLE = 1,
	PARAMETRO,
	FUNCION,
	CLASE,
	METODO_SOBREESCRIBIBLE,
	METODO_NO_SOBREESCRIBIBLE,
	ATRIBUTO_CLASE,
	ATRIBUTO_INSTANCIA
};
/* Tipo básico de dato */
enum tipo {
	BOOLEAN = 1,
	INT
};
/* Clase del dato */
enum clase {
	ESCALAR = 1,
	VECTOR,
	OBJETO
};
/* Tipo de acceso */
enum acceso {
	NINGUNO = 1,
	ACCESO_CLASE,	//hidden
	ACCESO_HERENCIA,//secret
	ACCESO_TODOS	//exposed
};
/* Tipo miembro */
enum miembro {
	MIEMBRO_UNICO = 1,
	MIEMBRO_NO_UNICO
};



typedef struct _HT_item HT_item;
typedef struct _TablaSimbolos TablaSimbolos;
typedef struct _Element Element;



int is_prime(int num);
int next_prime(int num);


TablaSimbolos * ht_new();
// nueva
TablaSimbolos* new_tabla_simbolos(int min_size);
int ht_get_size(TablaSimbolos * ts);
int ht_get_count(TablaSimbolos * ts);
void ht_del_hash_table(TablaSimbolos* ht);
HT_item * ht_insert_item(TablaSimbolos* ht, 
		const char* key,							int categoria,	
		int tipo,											int clase, 
		int direcciones, 							int numero_parametros, 
		int posicion_parametro, 			int numero_variables_locales, 
		int posicion_variable_local, 	int tamanio, 
		int numero_atributos_clase, 	int numero_atributos_instancia, 
		int numero_metodos_sobreescribibles, 
		int numero_metodos_no_sobreescribibles, 
		int tipo_acceso, 							int tipo_miembro, 
		int posicion_atributo_instancia, 
		int posicion_metodo_sobreescribible, 
		int num_acumulado_atributos_instancia, 
		int num_acumulado_metodos_sobreescritura, 
		int * tipo_args);

char ** ht_get_name_symbols(TablaSimbolos * ts);

int print_item(HT_item * item);
HT_item * ht_search_item(TablaSimbolos* ht, const char* key);

HT_item * ht_modify_item(TablaSimbolos* ht, 
		const char* key,							int categoria,	
		int tipo,											int clase, 
		int direcciones, 							int numero_parametros, 
		int posicion_parametro, 			int numero_variables_locales, 
		int posicion_variable_local, 	int tamanio, 
		int numero_atributos_clase, 	int numero_atributos_instancia, 
		int numero_metodos_sobreescribibles, 
		int numero_metodos_no_sobreescribibles, 
		int tipo_acceso, 							int tipo_miembro, 
		int posicion_atributo_instancia, 
		int posicion_metodo_sobreescribible, 
		int num_acumulado_atributos_instancia, 
		int num_acumulado_metodos_sobreescritura, 
		int * tipo_args);

Element * ht_item_get_value(HT_item * item);
void ht_del_hash_table(TablaSimbolos* h);

// Para debuggear
void imprimirTabla(TablaSimbolos *ht);

// Funciones que he añadido fruto de la desorientación
int get_num_atributos_instancia(TablaSimbolos *ht, const char *key);
int get_num_metodos_sobreescritura(TablaSimbolos *ht, const char *key);
int get_num_atributos_instancia_acum(TablaSimbolos *ht, const char *key);
int get_num_metodos_sobreescritura_acum(TablaSimbolos *ht, const char *key);

int modify_atributos_instancia(TablaSimbolos *ht, const char *key, int x,	int (*f)(int *a, int b));
int modify_metodos_sobreescritura(TablaSimbolos *ht, const char *key, int x, int (*f)(int *a, int b));
int modify_atributos_instancia_acum(TablaSimbolos *ht, const char *key, int x, int (*f)(int *a, int b));
int modify_metodos_sobre_acum(TablaSimbolos *ht, const char *key, int x, int (*f)(int *a, int b));

// Getters
enum acceso HT_itemGetAccess(HT_item *e);


#endif /* HASH_TABLE_H */