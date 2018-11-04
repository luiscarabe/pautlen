#include <stdlib.h>
#include <stdio.h>

#include "hash_table.h"

int main(int argc, char const *argv[]){
	int i, j;
	TablaSimbolos * new_ht = NULL;
	HT_item * hti1 = NULL;
	HT_item * hti2 = NULL;
	char ** names = NULL;
	int categoria1 = 1, categoria2 = 2;
	int tipo1 = 1, tipo2 = 2;
	int clase1 = 1, clase2 = 2;
	int direcciones1 = 1, direcciones2 = 2;
	int numero_parametros1 = 1, numero_parametros2 = 2;
	int posicion_parametro1 = 1	;
	int numero_variables_locales1 = 1;
	int posicion_variable_local1 = 1;
	int tamanio1 = 1;
	int numero_atributos_clase1 = 1;
	int numero_atributos_instancia1 = 1;
	int numero_metodos_sobreescribibles1 = 1;
	int numero_metodos_no_sobreescribibles1 = 1;
	int tipo_acceso1 = 1;
	int tipo_miembro1 = 1;
	int posicion_atributo_instancia1 = 1;
	int posicion_metodo_sobreescribible1 = 1;
	int num_acumulado_atributos_instancia1 = 1;
	int num_acumulado_metodos_sobreescritura1 = 1;
	int tipo_args[1];

	tipo_args[0] = 1;

	printf("Creando tabla hash....");
	new_ht = ht_new();
	if(new_ht == NULL){
		printf("ERROR\n");
	}
	printf("OK\n");

	printf("Insertando elemento 1 en tabla hash....");
	hti1 = ht_insert_item(new_ht, (const char*)"item1",
																categoria1,
																tipo1,
																clase1,
																direcciones1,
																numero_parametros1,
																posicion_parametro1,
																numero_variables_locales1,
																posicion_variable_local1,
																tamanio1,
																numero_atributos_clase1,
																numero_atributos_instancia1,
																numero_metodos_sobreescribibles1,
																numero_metodos_no_sobreescribibles1,
																tipo_acceso1,
																tipo_miembro1,
																posicion_atributo_instancia1,
																posicion_metodo_sobreescribible1,
																num_acumulado_atributos_instancia1,
																num_acumulado_metodos_sobreescritura1,
																tipo_args);
	if(hti1 == NULL){
		printf("ERROR\n");
	}
	printf("OK\n");

	printf("Insertando elemento 1 en tabla hash....");
	hti2 = ht_insert_item(new_ht, (const char*)"item1",
																categoria2,
																tipo1,
																clase1,
																direcciones1,
																numero_parametros1,
																posicion_parametro1,
																numero_variables_locales1,
																posicion_variable_local1,
																tamanio1,
																numero_atributos_clase1,
																numero_atributos_instancia1,
																numero_metodos_sobreescribibles1,
																numero_metodos_no_sobreescribibles1,
																tipo_acceso1,
																tipo_miembro1,
																posicion_atributo_instancia1,
																posicion_metodo_sobreescribible1,
																num_acumulado_atributos_instancia1,
																num_acumulado_metodos_sobreescritura1,
																tipo_args);
	if(hti2 != NULL){
		printf("ERROR\n");
	}
	printf("La inserción ha fallado: OK\n");

	printf("Insertando elemento 2 en tabla hash....");
	hti2 = ht_insert_item(new_ht, (const char*)"item2",
																categoria2,
																tipo2,
																clase1,
																direcciones1,
																numero_parametros1,
																posicion_parametro1,
																numero_variables_locales1,
																posicion_variable_local1,
																tamanio1,
																numero_atributos_clase1,
																numero_atributos_instancia1,
																numero_metodos_sobreescribibles1,
																numero_metodos_no_sobreescribibles1,
																tipo_acceso1,
																tipo_miembro1,
																posicion_atributo_instancia1,
																posicion_metodo_sobreescribible1,
																num_acumulado_atributos_instancia1,
																num_acumulado_metodos_sobreescritura1,
																tipo_args);
	if(hti2 == NULL){
		printf("ERROR\n");
	}
	printf("OK\n");

	printf("Insertando elemento 3 en tabla hash....");
	hti2 = ht_insert_item(new_ht, (const char*)"item3",
																categoria2,
																tipo2,
																clase2,
																direcciones1,
																numero_parametros1,
																posicion_parametro1,
																numero_variables_locales1,
																posicion_variable_local1,
																tamanio1,
																numero_atributos_clase1,
																numero_atributos_instancia1,
																numero_metodos_sobreescribibles1,
																numero_metodos_no_sobreescribibles1,
																tipo_acceso1,
																tipo_miembro1,
																posicion_atributo_instancia1,
																posicion_metodo_sobreescribible1,
																num_acumulado_atributos_instancia1,
																num_acumulado_metodos_sobreescritura1,
																tipo_args);
	if(hti2 == NULL){
		printf("ERROR\n");
	}
	printf("OK\n");

	printf("Insertando elemento 4 en tabla hash....");
	hti2 = ht_insert_item(new_ht, (const char*)"item4",
																categoria2,
																tipo2,
																clase2,
																direcciones2,
																numero_parametros1,
																posicion_parametro1,
																numero_variables_locales1,
																posicion_variable_local1,
																tamanio1,
																numero_atributos_clase1,
																numero_atributos_instancia1,
																numero_metodos_sobreescribibles1,
																numero_metodos_no_sobreescribibles1,
																tipo_acceso1,
																tipo_miembro1,
																posicion_atributo_instancia1,
																posicion_metodo_sobreescribible1,
																num_acumulado_atributos_instancia1,
																num_acumulado_metodos_sobreescritura1,
																tipo_args);
	if(hti2 == NULL){
		printf("ERROR\n");
	}
	printf("OK\n");

	printf("Insertando elemento 5 en tabla hash....");
	hti2 = ht_insert_item(new_ht, (const char*)"item5",
																categoria2,
																tipo2,
																clase2,
																direcciones2,
																numero_parametros2,
																posicion_parametro1,
																numero_variables_locales1,
																posicion_variable_local1,
																tamanio1,
																numero_atributos_clase1,
																numero_atributos_instancia1,
																numero_metodos_sobreescribibles1,
																numero_metodos_no_sobreescribibles1,
																tipo_acceso1,
																tipo_miembro1,
																posicion_atributo_instancia1,
																posicion_metodo_sobreescribible1,
																num_acumulado_atributos_instancia1,
																num_acumulado_metodos_sobreescritura1,
																tipo_args);
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
	hti2 = ht_modify_item(new_ht, (const char*)"item5",
																categoria1,
																tipo1,
																clase1,
																direcciones1,
																numero_parametros1,
																posicion_parametro1,
																numero_variables_locales1,
																posicion_variable_local1,
																tamanio1,
																numero_atributos_clase1,
																numero_atributos_instancia1,
																numero_metodos_sobreescribibles1,
																numero_metodos_no_sobreescribibles1,
																tipo_acceso1,
																tipo_miembro1,
																posicion_atributo_instancia1,
																posicion_metodo_sobreescribible1,
																num_acumulado_atributos_instancia1,
																num_acumulado_metodos_sobreescritura1,
																tipo_args);
	if(hti2 == NULL){
		printf("ERROR\n");
	}
	printf("OK\n");

	printf("Buscando e imprimiendo elemento item5\n");
	print_item(ht_search_item(new_ht, "item5"));

	printf("Imprimiendo nombres de los símbolos de la tabla...\n");
	names = ht_get_name_symbols(new_ht);
	if(names == NULL){
		printf("ERROR, no se han copiado los nombres\n");
	}

	i = ht_get_count(new_ht);

	for(j = 0; j < i; j++){
		printf("%s\n", names[j]);
	}

	for(j = 0; j < i; j++){
		free(names[j]);
	}
	free(names);
	printf("Eliminando tabla hash....");
	ht_del_hash_table(new_ht);
	printf("OK\n");



	

	return 0;
}
