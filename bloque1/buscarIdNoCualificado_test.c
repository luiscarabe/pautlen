#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "node.h"
#include "hash_table.h"

int main(int argc, char const *argv[]){
	Graph *g;

	iniciarTablaSimbolosClases(&g, "Menudo testazo");

	abrirClase(g, "AA");
	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_CLASE, "a1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_UNICO, 0, 0, 0, 0, NULL);
	
	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_CLASE, "sa1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ACCESO_CLASE,
								MIEMBRO_NO_UNICO, 0, 0, 0, 0, NULL);

	// Creo que no haria falta
	insertarTablaSimbolosClases(g, "AA", METODO_SOBREESCRIBIBLE, "mA1", 0, 
								0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_NO_UNICO, 0, 0, 0, 0, {INT});

	tablaSimbolosClasesAbrirAmbitoEnClase(	g, "AA", "mA1@2", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0);

	// Falta terminar


	return 0;
}