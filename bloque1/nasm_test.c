#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "symbols.h"
#include "node.h"
#include "hash_table.h"

int main(int argc, char const *argv[]){
	Graph *g;

	iniciarTablaSimbolosClases(&g, "Menudotestazo");

	abrirClase(g, "A");
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "A", "A_msa1", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 0, NULL);
	tablaSimbolosClasesCerrarAmbitoEnClase(g, "A");

	tablaSimbolosClasesAbrirAmbitoEnClase(g, "A", "A_msa2", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 0, NULL);
	tablaSimbolosClasesCerrarAmbitoEnClase(g, "A");


	abrirClaseHereda(g, "B", "A", NULL);
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "B", "B_msb1", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 0, NULL);
	tablaSimbolosClasesCerrarAmbitoEnClase(g, "B");

	tablaSimbolosClasesAbrirAmbitoEnClase(g, "B", "B_msb2", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 0, NULL);
	tablaSimbolosClasesCerrarAmbitoEnClase(g, "B");


	abrirClaseHereda(g, "C", "B", NULL);
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "C", "C_msc1", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 0, NULL);
	tablaSimbolosClasesCerrarAmbitoEnClase(g, "C");

	tablaSimbolosClasesAbrirAmbitoEnClase(g, "C", "C_msc2", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 0, NULL);
	tablaSimbolosClasesCerrarAmbitoEnClase(g, "C");


	abrirClaseHereda(g, "D", "C", NULL);
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "D", "D_msd1", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 0, NULL);
	tablaSimbolosClasesCerrarAmbitoEnClase(g, "D");

	tablaSimbolosClasesAbrirAmbitoEnClase(g, "D", "D_msd2", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 0, NULL);
	tablaSimbolosClasesCerrarAmbitoEnClase(g, "D");


	tablSimbolosClasesANasm(g, stdout);

	deleteGraph(g);


	return 0;
}