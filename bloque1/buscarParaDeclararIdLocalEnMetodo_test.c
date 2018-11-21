#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "symbols.h"
#include "node.h"
#include "hash_table.h"

int main(int argc, char const *argv[]){
	Graph *g;
	HT_item *item;
	int status;
	int tipos1[1] = {INT};
	char aux[64];

	iniciarTablaSimbolosClases(&g, "Menudotestazo");

	// nombreclase, nombreid,e, nombre_ambito encontrado

	abrirClase(g, "AA");

	// Caso 60
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "AA", "AA_mA1@2", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 1, tipos1);
	status = buscarParaDeclararIdLocalEnMetodo(g, "AA", "mA1@2_p1", &item, aux);
	printf("Caso 60: Declarar parámetro NO declarado %s\n", status == ERR ? " \tCORRECTO" : "\n\tINCORRECTO");
	insertarTablaSimbolosClases(g, "AA", PARAMETRO, "mA1@2_p1", ESCALAR,
								INT, 0, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL); 


	// Caso 61
	status = buscarParaDeclararIdLocalEnMetodo(g, "AA", "mA1@2_p1", &item, aux);
	printf("Caso 61: Declarar parámetro YA declarado %s\n", status == OK ? " \tCORRECTO" : "\n\tINCORRECTO");

	// Caso 62
	status = buscarParaDeclararIdLocalEnMetodo(g, "AA", "mA1@2_mA1", &item, aux);
	printf("Caso 62: Declarar parámetro con el mismo nombre que el método %s\n", status == ERR ? " \tCORRECTO" : "\n\tINCORRECTO");
	// No declaramos porque luego hacemos la misma búsqueda

	// Caso 63
	status = buscarParaDeclararIdLocalEnMetodo(g, "AA", "mA1@2_v1", &item, aux);
	printf("Caso 63: Declarar variable NO declarada %s\n", status == ERR ? " \tCORRECTO" : "\n\tINCORRECTO");
	insertarTablaSimbolosClases(g, "AA", VARIABLE, "mA1@2_v1", ESCALAR,
								INT, 0, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	// Caso 64
	status = buscarParaDeclararIdLocalEnMetodo(g, "AA", "mA1@2_p1", &item, aux);
	printf("Caso 64: Declarar variable con nombre igual a parámetro %s\n", status == OK ? " \tCORRECTO" : "\n\tINCORRECTO");
	
	// Caso 65
	status = buscarParaDeclararIdLocalEnMetodo(g, "AA", "mA1@2_v1", &item, aux);
	printf("Caso 65: Declarar variable YA declarada %s\n", status == OK ? " \tCORRECTO" : "\n\tINCORRECTO");

	// Caso 66
	status = buscarParaDeclararIdLocalEnMetodo(g, "AA", "mA1@2_mA1", &item, aux);
	printf("Caso 66: Declarar variable con nombre igual al del método %s\n", status == ERR ? " \tCORRECTO" : "\n\tINCORRECTO");
	// no la insertamos ya que seria lo mismo que antes
	tablaSimbolosClasesCerrarAmbitoEnClase(g, "AA");

	// Caso 67
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "AA", "AA_mA8", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, INT, 0, 0, 0, NULL);

	status = buscarParaDeclararIdLocalEnMetodo(g, "AA", "mA8_mA8", &item, aux);
	printf("Caso 66: Declarar variable con nombre igual al del método %s\n", status == ERR ? " \tCORRECTO" : "\n\tINCORRECTO");

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "AA");


	deleteGraph(g);


	return 0;
}