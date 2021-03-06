#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "symbols.h"
#include "node.h"
#include "hash_table.h"

int main(int argc, char const *argv[]){
	Graph *g;
	FILE *f;

	iniciarTablaSimbolosClases(&g, "Menudotestazo");

	abrirClase(g, "A");
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "A", "A_msa1", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 0, NULL);
	tablaSimbolosClasesCerrarAmbitoEnClase(g, "A");

	tablaSimbolosClasesAbrirAmbitoEnClase(g, "A", "A_msa2", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 0, NULL);
	tablaSimbolosClasesCerrarAmbitoEnClase(g, "A");


	abrirClase(g, "B");
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "B", "B_msb1", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 0, NULL);
	tablaSimbolosClasesCerrarAmbitoEnClase(g, "B");

	tablaSimbolosClasesAbrirAmbitoEnClase(g, "B", "B_msb2", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 0, NULL);
	tablaSimbolosClasesCerrarAmbitoEnClase(g, "B");


	abrirClaseHereda(g, "C", "A", "B", NULL);
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "C", "C_msc1", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 0, NULL);
	tablaSimbolosClasesCerrarAmbitoEnClase(g, "C");

	tablaSimbolosClasesAbrirAmbitoEnClase(g, "C", "C_msc2", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 0, NULL);
	tablaSimbolosClasesCerrarAmbitoEnClase(g, "C");


	abrirClaseHereda(g, "D", "A", "B", NULL);
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "D", "D_msd1", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 0, NULL);
	tablaSimbolosClasesCerrarAmbitoEnClase(g, "D");

	tablaSimbolosClasesAbrirAmbitoEnClase(g, "D", "D_msd2", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 0, NULL);
	tablaSimbolosClasesCerrarAmbitoEnClase(g, "D");

	tablaSimbolosClasesAbrirAmbitoEnClase(g, "D", "D_msa2", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 0, NULL);
	tablaSimbolosClasesCerrarAmbitoEnClase(g, "D");

	f = fopen("tst.asm", "w+");
	tablaSimbolosClasesANasm(g, f);
	tablaSimbolosClasesToDot(g);
	// imprimirTablasHash(g);

	deleteGraph(g);


	return 0;
}