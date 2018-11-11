#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "node.h"
#include "hash_table.h"

// Libera memoria otra persona
int main(int argc, char const *argv[]){
	Graph *g;
	HT_item *item;
	char *name = (char *) malloc(sizeof(char)*64);

	iniciarTablaSimbolosClases(&g, "Menudotestazo2");

	abrirClase(g, "AA");

	if (buscarParaDeclararMiembroClase(g, "sA1", "AA", &item, name) == -1)
		printf("No se encuentra \n");
	else printf("%s\n", name);
	
	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_CLASE, "sA1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_HERENCIA,
								MIEMBRO_UNICO, 0, 0, NULL);

	if (buscarParaDeclararMiembroClase(g, "sA1", "AA", &item, name) == -1)
		printf("No se encuentra \n");
	else printf("%s\n", name);

	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_CLASE, "sA1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_HERENCIA,
								MIEMBRO_UNICO, 0, 0, NULL);

	if (buscarParaDeclararMiembroClase(g, "hA1", "AA", &item, name) == -1)
		printf("No se encuentra \n");
	else printf("%s\n", name);

	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_CLASE, "hA1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_CLASE,
								MIEMBRO_UNICO, 0, 0, NULL);

	if (buscarParaDeclararMiembroClase(g, "eA1", "AA", &item, name) == -1)
		printf("No se encuentra \n");
	else printf("%s\n", name);

	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_CLASE, "eA1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_UNICO, 0, 0, NULL);
	
	int tipos[1] = {INT};
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "AA", "MA1", METODO_NO_SOBREESCRIBIBLE, 
											ACCESO_CLASE, INT, 0, 0, 1, tipos);

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "AA");
	
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "AA", "MA1", METODO_NO_SOBREESCRIBIBLE, 
											ACCESO_HERENCIA, INT, 0, 0, 1, tipos);

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "AA");

	int tipos2[2] = {INT, INT};
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "AA", "MA1", METODO_NO_SOBREESCRIBIBLE, 
											ACCESO_CLASE, INT, 0, 0, 2, tipos2);


	abrirClase(g, "BB");

	if (buscarParaDeclararMiembroClase(g, "sA1", "BB", &item, name) == -1)
		printf("No se encuentra \n");
	else printf("%s\n", name);

	insertarTablaSimbolosClases(g, "BB", ATRIBUTO_CLASE, "sA1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_HERENCIA,
								MIEMBRO_UNICO, 0, 0, NULL);

	if (buscarParaDeclararMiembroClase(g, "sA1", "BB", &item, name) == -1)
		printf("No se encuentra \n");
	else printf("%s\n", name);

	insertarTablaSimbolosClases(g, "BB", ATRIBUTO_CLASE, "sA1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_HERENCIA,
								MIEMBRO_UNICO, 0, 0, NULL);

	if (buscarParaDeclararMiembroClase(g, "hA1", "BB", &item, name) == -1)
		printf("No se encuentra \n");
	else printf("%s\n", name);

	insertarTablaSimbolosClases(g, "BB", ATRIBUTO_CLASE, "hA1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_CLASE,
								MIEMBRO_UNICO, 0, 0, NULL);

	if (buscarParaDeclararMiembroClase(g, "xA1", "BB", &item, name) == -1)
		printf("No se encuentra \n");
	else printf("%s\n", name);

	insertarTablaSimbolosClases(g, "BB", ATRIBUTO_CLASE, "xA1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_UNICO, 0, 0, NULL);

	tablaSimbolosClasesAbrirAmbitoEnClase(g, "BB", "MB1", METODO_NO_SOBREESCRIBIBLE, 
											ACCESO_HERENCIA, INT, 0, 0, 1, tipos);

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "BB");

	tablaSimbolosClasesAbrirAmbitoEnClase(g, "BB", "MA1", METODO_NO_SOBREESCRIBIBLE, 
											ACCESO_CLASE, INT, 0, 0, 1, tipos);

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "BB");

	tablaSimbolosClasesAbrirAmbitoEnClase(g, "BB", "MA2", METODO_NO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 1, tipos2);

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "BB");

	return 0;
}