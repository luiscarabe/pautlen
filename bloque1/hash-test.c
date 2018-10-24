#include <stdlib.h>
#include <stdio.h>

#include "hash_table.h"

int main(int argc, char const *argv[]){
	int i;
	HT_hash_table * new_ht = NULL;
	HT_item * hti1 = NULL;
	HT_item * hti2 = NULL;
	int aux;
	int category1 = 1, category2 = 2;
	int basic_type1 = 1, basic_type2 = 2;
	int basic_class1 = 1, basic_class2 = 2;
	int num_rows1 = 1, num_rows2 = 2;
	int num_params1 = 1, num_params2 = 2;
	int param_position1 = 1, param_position2 = 2;
	int num_local_variables1 = 1, num_local_variables2 = 2;
	int local_variable_position1 = 1, local_variable_position2 = 2;

	printf("Creando tabla hash....");
	new_ht = ht_new();
	if(new_ht == NULL){
		printf("ERROR\n");
	}
	printf("OK\n");

	printf("Insertando elemento 1 en tabla hash....");
	hti1 = ht_insert_item(new_ht, (const char*)"item1", category1, basic_type1, basic_class1, num_rows1, num_params1, param_position1, num_local_variables1, local_variable_position1);
	if(hti1 == NULL){
		printf("ERROR\n");
	}
	printf("OK\n");

	printf("Insertando elemento 1 en tabla hash....");
	hti2 = ht_insert_item(new_ht, (const char*)"item1", category2, basic_type1, basic_class1, num_rows1, num_params1, param_position1, num_local_variables1, local_variable_position1);
	if(hti2 != NULL){
		printf("ERROR\n");
	}
	printf("La inserción ha fallado: OK\n");

	printf("Insertando elemento 2 en tabla hash....");
	hti2 = ht_insert_item(new_ht, (const char*)"item2", category2, basic_type1, basic_class1, num_rows1, num_params1, param_position1, num_local_variables1, local_variable_position1);
	if(hti2 == NULL){
		printf("ERROR\n");
	}
	printf("OK\n");

	printf("Insertando elemento 3 en tabla hash....");
	hti2 = ht_insert_item(new_ht, (const char*)"item3", category2, basic_type2, basic_class1, num_rows1, num_params1, param_position1, num_local_variables1, local_variable_position1);
	if(hti2 == NULL){
		printf("ERROR\n");
	}
	printf("OK\n");

	printf("Insertando elemento 4 en tabla hash....");
	hti2 = ht_insert_item(new_ht, (const char*)"item4", category2, basic_type2, basic_class2, num_rows1, num_params1, param_position1, num_local_variables1, local_variable_position1);
	if(hti2 == NULL){
		printf("ERROR\n");
	}
	printf("OK\n");

	printf("Insertando elemento 5 en tabla hash....");
	hti2 = ht_insert_item(new_ht, (const char*)"item5", category2, basic_type2, basic_class2, num_rows2, num_params1, param_position1, num_local_variables1, local_variable_position1);
	if(hti2 == NULL){
		printf("ERROR\n");
	}
	printf("OK\n");

	printf("Buscando e imprimiendo elemento item1\n");
	print_item(ht_search_item(new_ht, "item1"));

	printf("Buscando e imprimiendo elemento item2\n");
	print_item(ht_search_item(new_ht, "item2"));

	printf("Buscando e imprimiendo elemento item3\n");
	print_item(ht_search_item(new_ht, "item3"));

	printf("Buscando e imprimiendo elemento item4\n");
	print_item(ht_search_item(new_ht, "item4"));

	printf("Buscando e imprimiendo elemento item5\n");
	print_item(ht_search_item(new_ht, "item5"));

	printf("Modificando elemento 5 en tabla hash....");
	hti2 = ht_modify_item(new_ht, (const char*)"item5", category1, basic_type1, basic_class1, num_rows1, num_params1, param_position1, num_local_variables1, local_variable_position1);
	if(hti2 == NULL){
		printf("ERROR\n");
	}
	printf("OK\n");

	printf("Buscando e imprimiendo elemento item5\n");
	print_item(ht_search_item(new_ht, "item5"));

	printf("Eliminando tabla hash....");
	ht_del_hash_table(new_ht);
	printf("OK\n");



	

	return 0;
}