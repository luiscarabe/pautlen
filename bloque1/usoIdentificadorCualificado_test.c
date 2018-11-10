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
	

	iniciarTablaSimbolosClases(&g, "Menudotestazo4");

	insertarTablaSimbolosMain(g, VARIABLE, "varGlob", ESCALAR,
								INT, 0, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	abrirClase(g, "AA");
	
	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_INSTANCIA, "inspub", 0, 
								OBJETO, 0, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_INSTANCIA, "insprot", 0, 
								OBJETO, 0, 0, 0, 0, 0, ACCESO_HERENCIA,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_INSTANCIA, "inspriv", 0, 
								OBJETO, 0, 0, 0, 0, 0, ACCESO_CLASE,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_INSTANCIA, "clasepub", 0, 
								OBJETO, 0, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_UNICO, 0, 0, NULL);

	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_INSTANCIA, "claseprot", 0, 
								OBJETO, 0, 0, 0, 0, 0, ACCESO_HERENCIA,
								MIEMBRO_UNICO, 0, 0, NULL);

	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_INSTANCIA, "clasepriv", 0, 
								OBJETO, 0, 0, 0, 0, 0, ACCESO_CLASE,
								MIEMBRO_UNICO, 0, 0, NULL);

	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_INSTANCIA, "miaa", 0, 
								OBJETO, 0, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	tablaSimbolosClasesAbrirAmbitoEnClase(g, "AA", "prueba", METODO_SOBREESCRIBIBLE, 
											ACCESO_HERENCIA, INT, 0, 0, 0, NULL);

	status = buscarIdCualificadoInstancia(g, "miaa", "inspriv", "AA", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "miaa", "insprot", "AA", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "miaa", "inspub", "AA", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdIDCualificadoClase(g, "AA", "claseprot", "AA", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdIDCualificadoClase(g, "AA", "clasepub", "AA", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdIDCualificadoClase(g, "AA", "clasepriv", "AA", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "AA");
	

	abrirClaseHereda(g, "BB", "AA", NULL);

	insertarTablaSimbolosClases(g, "BB", ATRIBUTO_INSTANCIA, "mibb", 0, 
								OBJETO, 1, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	insertarTablaSimbolosMain(g, VARIABLE, "MainMiBB", 0,
								OBJETO, 1, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	insertarTablaSimbolosMain(g, VARIABLE, "MainMiBB2", 0,
								OBJETO, 1, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	status = buscarIdCualificadoInstancia(g, "MainMiBB", "insnoexiste", "AA", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	abrirClase(g, "CC");

	insertarTablaSimbolosClases(g, "CC", ATRIBUTO_INSTANCIA, "micc", 0, 
								OBJETO, 2, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	abrirClaseHereda(g, "DD", "AA", "CC", NULL);

	insertarTablaSimbolosClases(g, "DD", ATRIBUTO_INSTANCIA, "midd", 0, 
								OBJETO, 3, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	abrirClaseHereda(g, "EE", "BB", "DD", NULL);

	insertarTablaSimbolosClases(g, "EE", ATRIBUTO_INSTANCIA, "miee", 0, 
								OBJETO, 4, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_NO_UNICO, 0, 0, NULL);


	tablaSimbolosClasesAbrirAmbitoEnClase(g, "EE", "mE", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, 0, 0, 1, 0, NULL);

	insertarTablaSimbolosAmbitos(g, "EE", VARIABLE, "varLoc", 0, 
								OBJETO, 4, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	status = buscarIdIDCualificadoClase(g, "EE", "clasepub", "EE", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdIDCualificadoClase(g, "EE", "clasepriv", "EE", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdIDCualificadoClase(g, "EE", "claseNoExiste", "EE", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdIDCualificadoClase(g, "noExiste", "claseNoExiste", "EE", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "MainMiBB2", "inspub", "EE", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "miee", "insNoExiste", "EE", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "varLoc", "inspub", "EE", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "miee", "inspub", "EE", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "miee", "insprot", "EE", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "EE");
	
	abrirClaseHereda(g, "FF", "CC", "EE", NULL);

	insertarTablaSimbolosClases(g, "FF", ATRIBUTO_INSTANCIA, "miff", 0, 
								OBJETO, 5, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_NO_UNICO, 0, 0, NULL);


	tablaSimbolosClasesAbrirAmbitoEnMain(g, "prueba", FUNCION, NINGUNO,
								INT, 0, 0, 0, NULL);

	status = buscarIdIDCualificadoClase(g, "AA", "clasepriv", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdIDCualificadoClase(g, "AA", "clasepub", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdIDCualificadoClase(g, "AA", "claseNoExiste", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdIDCualificadoClase(g, "noExiste", "claseNoExiste", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "MainMiBB2", "inspriv", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "MainMiBB2", "insNoExiste", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	tablaSimbolosClasesCerrarAmbitoEnMain(g);
	
	tablaSimbolosClasesAbrirAmbitoEnMain(g, "f2", FUNCION, ACCESO_CLASE,
								INT, 0, 0, 0, NULL);

	insertarTablaSimbolosAmbitosMain(g, VARIABLE, "varLoc", ESCALAR, 
								INT, 0, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	insertarTablaSimbolosAmbitosMain(g, VARIABLE, "MainMiBB3", 0, 
								OBJETO, 1, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	status = buscarIdCualificadoInstancia(g, "MainMiBB2", "insNoExiste", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "MainMiBB2", "inspub", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "MainMiBB2", "inspriv", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdIDCualificadoClase(g, "AA", "clasepub", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdIDCualificadoClase(g, "AA", "clasepriv", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "MainMiBB2", "inspub", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	tablaSimbolosClasesCerrarAmbitoEnMain(g);

	status = buscarIdIDCualificadoClase(g, "JJ", "noExiste", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "MainMiBB2", "inspub", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdIDCualificadoClase(g, "AA", "clasepub", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdIDCualificadoClase(g, "AA", "clasepriv", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdIDCualificadoClase(g, "AA", "noexiste", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	status = buscarIdIDCualificadoClase(g, "Noexiste", "noexiste", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado" : "No encontrado", name);

	return 0;
}