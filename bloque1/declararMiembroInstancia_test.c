#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "node.h"
#include "hash_table.h"

// Libera memoria otra persona
int main(int argc, char const *argv[]){
	Graph *g;

	iniciarTablaSimbolosClases(&g, "Menudotestazo3");

	abrirClase(g, "AA");
	
	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_CLASE, "sa1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_HERENCIA,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_CLASE, "sa1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_CLASE,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_CLASE, "ha1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_HERENCIA,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_CLASE, "xa1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_NO_UNICO, 0, 0, NULL);
	
	int tipos[1] = {INT};
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "AA", "mA1", METODO_SOBREESCRIBIBLE, 
											ACCESO_CLASE, INT, 0, 0, 1, tipos);

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "AA");
	
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "AA", "mA1", METODO_SOBREESCRIBIBLE, 
											ACCESO_HERENCIA, INT, 0, 1, 1, tipos);

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "AA");

	int tipos1[2] = {INT, BOOLEAN};
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "AA", "mA1", METODO_SOBREESCRIBIBLE, 
											ACCESO_HERENCIA, INT, 0, 1, 2, tipos1);

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "AA");

	tablaSimbolosClasesAbrirAmbitoEnClase(g, "AA", "mA2", METODO_SOBREESCRIBIBLE, 
											ACCESO_CLASE, INT, 0, 2, 0, NULL);

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "AA");

	tablaSimbolosClasesAbrirAmbitoEnClase(g, "AA", "mA3", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 2, 2, tipos1);

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "AA");

	abrirClaseHereda(g, "BB", "AA", NULL);

	insertarTablaSimbolosClases(g, "BB", ATRIBUTO_CLASE, "sa1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_HERENCIA,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	insertarTablaSimbolosClases(g, "BB", ATRIBUTO_CLASE, "ha1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_CLASE,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	insertarTablaSimbolosClases(g, "BB", ATRIBUTO_CLASE, "hb1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_CLASE,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	insertarTablaSimbolosClases(g, "BB", ATRIBUTO_CLASE, "xa1", ESCALAR, 
								INT, 0, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_NO_UNICO, 0, 0, NULL);


	tablaSimbolosClasesAbrirAmbitoEnClase(g, "BB", "mA1", METODO_SOBREESCRIBIBLE, 
											ACCESO_HERENCIA, INT, 0, 3, 1, tipos);

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "BB");
	
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "BB", "mB1", METODO_SOBREESCRIBIBLE, 
											ACCESO_CLASE, INT, 0, 4, 0, NULL);

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "BB");

	tablaSimbolosClasesAbrirAmbitoEnClase(g, "BB", "mA2", METODO_SOBREESCRIBIBLE, 
											ACCESO_CLASE, INT, 0, 5, 0, NULL);

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "BB");

	int tipos2[2] = {BOOLEAN, INT};
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "BB", "mA3", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 6, 2, tipos2);

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "BB");

	abrirClaseHereda(g, "BB", "AA", NULL);


	return 0;
}