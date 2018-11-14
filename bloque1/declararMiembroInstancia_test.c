#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "node.h"
#include "hash_table.h"

// Libera memoria otra persona
int main(int argc, char const *argv[]){
	Graph *g;
	int tipos[2] = {BOOLEAN, INT};
	HT_item *item;
	char *name = (char *) malloc(sizeof(char)*64);

	iniciarTablaSimbolosClases(&g, "Menudotestazo3");

	// CLASE AA

	printf("Variables AA\n");
	abrirClase(g, "AA");

	if (buscarParaDeclararMiembroInstancia(g, "AA_sa1", "AA", &item, name) == -1){
		printf("No se encuentra. SE PUEDE DECLARAR\n");
		insertarTablaSimbolosClases(g, "AA", ATRIBUTO_CLASE, "AA_sa1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_HERENCIA,
								MIEMBRO_NO_UNICO, 0, 0, NULL);
	}else{
		printf("Se encuentra en la clase %s o en jerarquía. NO SE PUEDE DECLARAR\n", name);
	}
	
	

	if (buscarParaDeclararMiembroInstancia(g, "AA_sa1", "AA", &item, name) == -1){
		printf("No se encuentra. SE PUEDE DECLARAR\n");
		insertarTablaSimbolosClases(g, "AA", ATRIBUTO_CLASE, "AA_sa1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_HERENCIA,
								MIEMBRO_NO_UNICO, 0, 0, NULL);
	}else{
		printf("Se encuentra en la clase %s o en jerarquía. NO SE PUEDE DECLARAR\n", name);
	}

	if (buscarParaDeclararMiembroInstancia(g, "AA_ha1", "AA", &item, name) == -1){
		printf("No se encuentra. SE PUEDE DECLARAR\n");
		insertarTablaSimbolosClases(g, "AA", ATRIBUTO_CLASE, "AA_ha1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_HERENCIA,
								MIEMBRO_NO_UNICO, 0, 0, NULL);
	}else{
		printf("Se encuentra en la clase %s o en jerarquía. NO SE PUEDE DECLARAR\n", name);
	}
	if (buscarParaDeclararMiembroInstancia(g, "AA_hc1", "AA", &item, name) == -1){
		printf("No se encuentra. SE PUEDE DECLARAR\n");
		insertarTablaSimbolosClases(g, "AA", ATRIBUTO_CLASE, "AA_hc1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_CLASE,
								MIEMBRO_NO_UNICO, 0, 0, NULL);
	}else{
		printf("Se encuentra en la clase %s o en jerarquía. NO SE PUEDE DECLARAR\n", name);
	}

	if (buscarParaDeclararMiembroInstancia(g, "AA_xa1", "AA", &item, name) == -1){
		printf("No se encuentra. SE PUEDE DECLARAR\n");
		insertarTablaSimbolosClases(g, "AA", ATRIBUTO_CLASE, "AA_xa1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_NO_UNICO, 0, 0, NULL);
	}else{
		printf("Se encuentra en la clase %s o en jerarquía. NO SE PUEDE DECLARAR\n", name);
	}
	

	printf("Métodos AA\n");
	//METODOS
	if (buscarParaDeclararMiembroInstancia(g, "AA_mA1@1@2", "AA", &item, name) == -1){
		printf("No se encuentra. SE PUEDE DECLARAR\n");
		insertarTablaSimbolosClases(g, "AA", METODO_SOBREESCRIBIBLE, "AA_mA1@1@2", 0, 
									INT, 0, 2, 0, 0, 0, ACCESO_HERENCIA,
									MIEMBRO_NO_UNICO, 0, 0, tipos);
	}else{
		printf("Se encuentra en la clase %s o en jerarquía. NO SE PUEDE DECLARAR\n", name);
	}
	
	if (buscarParaDeclararMiembroInstancia(g, "AA_mA1@1@2", "AA", &item, name) == -1){
		printf("No se encuentra. SE PUEDE DECLARAR\n");
		insertarTablaSimbolosClases(g, "AA", METODO_SOBREESCRIBIBLE, "AA_mA1@1@2", 0, 
									INT, 0, 2, 0, 0, 0, ACCESO_CLASE,
									MIEMBRO_NO_UNICO, 0, 0, tipos);
	}else{
		printf("Se encuentra en la clase %s o en jerarquía. NO SE PUEDE DECLARAR\n", name);
	}

	if (buscarParaDeclararMiembroInstancia(g, "AA_mA1@1@2", "AA", &item, name) == -1){
		printf("No se encuentra. SE PUEDE DECLARAR\n");
		insertarTablaSimbolosClases(g, "AA", METODO_SOBREESCRIBIBLE, "AA_mA1@1@2", 0, 
									INT, 0, 2, 0, 0, 0, ACCESO_HERENCIA,
									MIEMBRO_NO_UNICO, 0, 0, tipos);
	}else{
		printf("Se encuentra en la clase %s o en jerarquía. NO SE PUEDE DECLARAR\n", name);
	}

	if (buscarParaDeclararMiembroInstancia(g, "AA_mA2@1@2", "AA", &item, name) == -1){
		printf("No se encuentra. SE PUEDE DECLARAR\n");
		insertarTablaSimbolosClases(g, "AA", METODO_SOBREESCRIBIBLE, "AA_mA2@1@2", 0, 
									INT, 0, 2, 0, 0, 0, ACCESO_CLASE,
									MIEMBRO_NO_UNICO, 0, 0, tipos);
	}else{
		printf("Se encuentra en la clase %s o en jerarquía. NO SE PUEDE DECLARAR\n", name);
	}

	if (buscarParaDeclararMiembroInstancia(g, "AA_mA3@1@2", "AA", &item, name) == -1){
		printf("No se encuentra. SE PUEDE DECLARAR\n");
		insertarTablaSimbolosClases(g, "AA", METODO_SOBREESCRIBIBLE, "AA_mA3@1@2", 0, 
									INT, 0, 2, 0, 0, 0, ACCESO_TODOS,
									MIEMBRO_NO_UNICO, 0, 0, tipos);
	}else{
		printf("Se encuentra en la clase %s o en jerarquía. NO SE PUEDE DECLARAR\n", name);
	}


	printf("Variables BB\n");
	// CLASE BB
	abrirClaseHereda(g, "BB", "AA", NULL);

	if (buscarParaDeclararMiembroInstancia(g, "BB_sa1", "BB", &item, name) == -1){
		printf("No se encuentra. SE PUEDE DECLARAR\n");
		insertarTablaSimbolosClases(g, "BB", ATRIBUTO_CLASE, "BB_sa1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_HERENCIA,
								MIEMBRO_NO_UNICO, 0, 0, NULL);
	}else{
		printf("Se encuentra en la clase %s o en jerarquía. NO SE PUEDE DECLARAR\n", name);
	}

	

	if (buscarParaDeclararMiembroInstancia(g, "BB_ha1", "BB", &item, name) == -1){
		printf("No se encuentra. SE PUEDE DECLARAR\n");
		insertarTablaSimbolosClases(g, "BB", ATRIBUTO_CLASE, "BB_ha1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_CLASE,
								MIEMBRO_NO_UNICO, 0, 0, NULL);
	}else{
		printf("Se encuentra en la clase %s o en jerarquía. NO SE PUEDE DECLARAR\n", name);
	}

	if (buscarParaDeclararMiembroInstancia(g, "BB_hc1", "BB", &item, name) == -1){
		printf("No se encuentra. SE PUEDE DECLARAR\n");
		insertarTablaSimbolosClases(g, "BB", ATRIBUTO_CLASE, "BB_hc1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_CLASE,
								MIEMBRO_NO_UNICO, 0, 0, NULL);
	}else{
		printf("Se encuentra en la clase %s o en jerarquía. NO SE PUEDE DECLARAR\n", name);
	}

	if (buscarParaDeclararMiembroInstancia(g, "BB_hb1", "BB", &item, name) == -1){
		printf("No se encuentra. SE PUEDE DECLARAR\n");
		insertarTablaSimbolosClases(g, "BB", ATRIBUTO_CLASE, "BB_hb1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_CLASE,
								MIEMBRO_NO_UNICO, 0, 0, NULL);
	}else{
		printf("Se encuentra en la clase %s o en jerarquía. NO SE PUEDE DECLARAR\n", name);
	}

	if (buscarParaDeclararMiembroInstancia(g, "BB_xa1", "BB", &item, name) == -1){
		printf("No se encuentra. SE PUEDE DECLARAR\n");
		insertarTablaSimbolosClases(g, "BB", ATRIBUTO_CLASE, "BB_xa1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_NO_UNICO, 0, 0, NULL);
	}else{
		printf("Se encuentra en la clase %s o en jerarquía. NO SE PUEDE DECLARAR\n", name);
	}


	printf("Métodos BB\n");
	//METODOS

	if (buscarParaDeclararMiembroInstancia(g, "BB_mA1@1@2", "BB", &item, name) == -1){
		printf("No se encuentra. SE PUEDE DECLARAR\n");
		insertarTablaSimbolosClases(g, "BB", METODO_SOBREESCRIBIBLE, "BB_mA1@1@2", 0, 
									INT, 0, 2, 0, 0, 0, ACCESO_HERENCIA,
									MIEMBRO_NO_UNICO, 0, 0, tipos);
	}else{
		printf("Se encuentra en la clase %s o en jerarquía. NO SE PUEDE DECLARAR\n", name);
	}

	
	if (buscarParaDeclararMiembroInstancia(g, "BB_mB1@1@2", "BB", &item, name) == -1){
		printf("No se encuentra. SE PUEDE DECLARAR\n");
		insertarTablaSimbolosClases(g, "BB", METODO_SOBREESCRIBIBLE, "BB_mB1@1@2", 0, 
									INT, 0, 2, 0, 0, 0, ACCESO_HERENCIA,
									MIEMBRO_NO_UNICO, 0, 0, tipos);
	}else{
		printf("Se encuentra en la clase %s o en jerarquía. NO SE PUEDE DECLARAR\n", name);
	}

	if (buscarParaDeclararMiembroInstancia(g, "BB_mA2@1@2", "BB", &item, name) == -1){
		printf("No se encuentra. SE PUEDE DECLARAR\n");
		insertarTablaSimbolosClases(g, "BB", METODO_SOBREESCRIBIBLE, "BB_mA2@1@2", 0, 
									INT, 0, 2, 0, 0, 0, ACCESO_CLASE,
									MIEMBRO_NO_UNICO, 0, 0, tipos);
	}else{
		printf("Se encuentra en la clase %s o en jerarquía. NO SE PUEDE DECLARAR\n", name);
	}

	if (buscarParaDeclararMiembroInstancia(g, "BB_mA3@1@2", "BB", &item, name) == -1){
		printf("No se encuentra. SE PUEDE DECLARAR\n");
		insertarTablaSimbolosClases(g, "BB", METODO_SOBREESCRIBIBLE, "BB_mA3@1@2", 0, 
									INT, 0, 2, 0, 0, 0, ACCESO_TODOS,
									MIEMBRO_NO_UNICO, 0, 0, tipos);
	}else{
		printf("Se encuentra en la clase %s o en jerarquía. NO SE PUEDE DECLARAR\n", name);
	}



	return 0;
}