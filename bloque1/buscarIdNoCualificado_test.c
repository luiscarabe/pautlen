#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "symbols.h"
#include "node.h"
#include "hash_table.h"

// Libera memoria otra persona
int main(int argc, char const *argv[]){
	Graph *g;
	HT_item *item;
	char *name = (char *) malloc(sizeof(char)*64);
	int status;
	

	iniciarTablaSimbolosClases(&g, "Menudotestazo");

	insertarTablaSimbolosMain(g, VARIABLE, "main_v1", ESCALAR,
								INT, 0, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	abrirClase(g, "AA");
	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_CLASE, "AA_a1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_UNICO, 0, 0, NULL);
	
	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_CLASE, "AA_sa1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_CLASE,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	int tipos[1] = {INT};
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "AA", "AA_mA1@1", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 1, tipos);

	insertarTablaSimbolosClases(g, "AA", PARAMETRO, "mA1@1_pmA1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	insertarTablaSimbolosClases(g, "AA", VARIABLE, "mA1@1_vlmA1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	status = buscarIdNoCualificado(g, "v1", "AA", &item, name);
	printf("%s %s\n", status == OK ? "Caso 20 correcto" : "Caso 20 mal", name);

	status = buscarIdNoCualificado(g, "x", "AA", &item, name);
	printf("%s %s\n", status == OK ? "Caso 21 mal" : "Caso 21 correcto", name);

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "AA");
	
	int tipos1[1] = {BOOLEAN};
	tablaSimbolosClasesAbrirAmbitoEnMain(g, "main_f1@2", FUNCION, NINGUNO,
								INT, 0, 0, 1, tipos1);

	insertarTablaSimbolosMain(g, PARAMETRO, "f1@2_pf1", ESCALAR, 
								BOOLEAN, 0, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	insertarTablaSimbolosMain(g, VARIABLE, "f1@2_vlf11", ESCALAR, 
								INT, 0, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	imprimirTablasHash(g);

	status = buscarIdNoCualificado(g, "pf1", "main", &item, name);
	printf("%s %s\n", status == OK ? "Caso 24 correcto" : "Caso 24 mal", name);

	status = buscarIdNoCualificado(g, "v1", "main", &item, name);
	printf("%s %s\n", status == OK ? "Caso 25 correcto" : "Caso 25 mal", name);

	status = buscarIdNoCualificado(g, "a1", "main", &item, name);
	printf("%s %s\n", status == OK ? "Caso 26 mal" : "Caso 26 correcto", name);

	tablaSimbolosClasesCerrarAmbitoEnMain(g);

	status = buscarIdNoCualificado(g, "v1", "main", &item, name);
	printf("%s %s\n", status == OK ? "Caso 22 correcto" : "Caso 22 mal", name);

	status = buscarIdNoCualificado(g, "x", "main", &item, name);
	printf("%s %s\n", status == OK ? "Caso 23 mal" : "Caso 23 correcto", name);
	

	return 0;
}