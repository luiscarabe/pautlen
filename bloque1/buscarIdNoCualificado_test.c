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
	int status;
	

	iniciarTablaSimbolosClases(&g, "Menudotestazo");

	insertarTablaSimbolosMain(g, VARIABLE, "v1", ESCALAR,
								INT, 0, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	abrirClase(g, "AA");
	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_CLASE, "a1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_UNICO, 0, 0, NULL);
	
	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_CLASE, "sa1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_CLASE,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	int tipos[1] = {INT};
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "AA", "mA1", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 1, tipos);

	insertarTablaSimbolosAmbitos(g, "AA", PARAMETRO, "pmA1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	insertarTablaSimbolosAmbitos(g, "AA", VARIABLE, "vlmA1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	status = buscarIdNoCualificado(g, "v1", "AA", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdNoCualificado(g, "x", "AA", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "AA");
	
	int tipos1[1] = {BOOLEAN};
	tablaSimbolosClasesAbrirAmbitoEnMain(g, "f1", FUNCION, NINGUNO,
								INT, 0, 0, 1, tipos1);

	insertarTablaSimbolosAmbitosMain(g, PARAMETRO, "pf1", ESCALAR, 
								BOOLEAN, 0, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	insertarTablaSimbolosAmbitosMain(g, VARIABLE, "vlf11", ESCALAR, 
								INT, 0, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	status = buscarIdNoCualificado(g, "pf1", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdNoCualificado(g, "v1", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdNoCualificado(g, "a1", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	tablaSimbolosClasesCerrarAmbitoEnMain(g);

	status = buscarIdNoCualificado(g, "v1", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdNoCualificado(g, "x", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);
	

	return 0;
}