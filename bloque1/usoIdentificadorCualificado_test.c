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

	insertarTablaSimbolosMain(g, VARIABLE, "main_varGlob", ESCALAR,
								INT, 0, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	printf("Abrir clase AA\n");
	abrirClase(g, "AA");
	
	printf("Atributo inspub\n");
	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_INSTANCIA, "AA_inspub", 0, 
								OBJETO, 0, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	printf("Atributo insprot\n");
	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_INSTANCIA, "AA_insprot", 0, 
								OBJETO, 0, 0, 0, 0, 0, ACCESO_HERENCIA,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	printf("Atributo inspriv\n");
	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_INSTANCIA, "AA_inspriv", 0, 
								OBJETO, 0, 0, 0, 0, 0, ACCESO_CLASE,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	printf("Atributo clasepub\n");
	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_INSTANCIA, "AA_clasepub", 0, 
								OBJETO, 0, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_UNICO, 0, 0, NULL);

	printf("Atributo claseprot\n");
	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_INSTANCIA, "AA_claseprot", 0, 
								OBJETO, 0, 0, 0, 0, 0, ACCESO_HERENCIA,
								MIEMBRO_UNICO, 0, 0, NULL);

	printf("Atributo clasepriv\n");
	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_INSTANCIA, "AA_clasepriv", 0, 
								OBJETO, 0, 0, 0, 0, 0, ACCESO_CLASE,
								MIEMBRO_UNICO, 0, 0, NULL);

	printf("Atributo miaa\n");
	insertarTablaSimbolosClases(g, "AA", ATRIBUTO_INSTANCIA, "AA_miaa", 0, 
								OBJETO, 0, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	printf("Funcion prueba\n");
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "AA", "AA_prueba", METODO_SOBREESCRIBIBLE, 
											ACCESO_HERENCIA, INT, 0, 0, 0, NULL);

	status = buscarIdCualificadoInstancia(g, "miaa", "inspriv", "AA", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "miaa", "insprot", "AA", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "miaa", "inspub", "AA", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoClase(g, "AA", "claseprot", "AA", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoClase(g, "AA", "clasepub", "AA", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoClase(g, "AA", "clasepriv", "AA", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	printf("Cerrar funcion\n");
	tablaSimbolosClasesCerrarAmbitoEnClase(g, "AA");
	

	printf("Clase BB hereda de AA\n");
	abrirClaseHereda(g, "BB", "AA", NULL);

	printf("Atributo mibb en BB\n");
	insertarTablaSimbolosClases(g, "BB", ATRIBUTO_INSTANCIA, "BB_mibb", 0, 
								OBJETO, 1, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	printf("Atributo MainMiBB en main\n");
	insertarTablaSimbolosMain(g, VARIABLE, "main_MainMiBB", 0,
								OBJETO, 1, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	printf("Atributo MainMiBB2 en main\n");
	insertarTablaSimbolosMain(g, VARIABLE, "main_MainMiBB2", 0,
								OBJETO, 1, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	status = buscarIdCualificadoInstancia(g, "MainMiBB", "insnoexiste", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	printf("Clase CC\n");
	abrirClase(g, "CC");

	printf("Atributo miCC en CC\n");
	insertarTablaSimbolosClases(g, "CC", ATRIBUTO_INSTANCIA, "CC_micc", 0, 
								OBJETO, 2, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	printf("Clase DD hereda de AA y CC\n");
	abrirClaseHereda(g, "DD", "AA", "CC", NULL);

	printf("Atributo midd en DD\n");
	insertarTablaSimbolosClases(g, "DD", ATRIBUTO_INSTANCIA, "DD_midd", 0, 
								OBJETO, 3, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	printf("Clase EE hereda de BB y DD\n");
	abrirClaseHereda(g, "EE", "BB", "DD", NULL);

	printf("Atributo miee en EE\n");
	insertarTablaSimbolosClases(g, "EE", ATRIBUTO_INSTANCIA, "EE_miee", 0, 
								OBJETO, 4, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_NO_UNICO, 0, 0, NULL);


	printf("Funcion mE en EE\n");
	tablaSimbolosClasesAbrirAmbitoEnClase(g, "EE", "EE_mE", METODO_SOBREESCRIBIBLE, 
											ACCESO_TODOS, 0, 0, 1, 0, NULL);

	printf("Atributo varLoc en funcion mE de EE\n");
	insertarTablaSimbolosClases(g, "EE", VARIABLE, "mE_varLoc", 0, 
								OBJETO, 4, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	status = buscarIdCualificadoClase(g, "EE", "clasepub", "EE", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoClase(g, "EE", "clasepriv", "EE", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoClase(g, "EE", "claseNoExiste", "EE", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoClase(g, "noExiste", "claseNoExiste", "EE", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "MainMiBB2", "inspub", "EE", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "miee", "insNoExiste", "EE", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	printf("*varLoc.inspub\n");
	status = buscarIdCualificadoInstancia(g, "varLoc", "inspub", "EE", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "miee", "inspub", "EE", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "miee", "insprot", "EE", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	tablaSimbolosClasesCerrarAmbitoEnClase(g, "EE");
	
	abrirClaseHereda(g, "FF", "CC", "EE", NULL);

	insertarTablaSimbolosClases(g, "FF", ATRIBUTO_INSTANCIA, "FF_miff", 0, 
								OBJETO, 5, 0, 0, 0, 0, ACCESO_TODOS,
								MIEMBRO_NO_UNICO, 0, 0, NULL);


	tablaSimbolosClasesAbrirAmbitoEnMain(g, "main_prueba", FUNCION, NINGUNO,
								INT, 0, 0, 0, NULL);

	printf("*FF\n");
	status = buscarIdCualificadoClase(g, "AA", "clasepriv", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoClase(g, "AA", "clasepub", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoClase(g, "AA", "claseNoExiste", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoClase(g, "noExiste", "claseNoExiste", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "MainMiBB2", "inspriv", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "MainMiBB2", "insNoExiste", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	tablaSimbolosClasesCerrarAmbitoEnMain(g);
	
	tablaSimbolosClasesAbrirAmbitoEnMain(g, "main_f2", FUNCION, ACCESO_CLASE,
								INT, 0, 0, 0, NULL);

	insertarTablaSimbolosMain(g, VARIABLE, "main_varLoc", ESCALAR, 
								INT, 0, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	insertarTablaSimbolosMain(g, VARIABLE, "main_MainMiBB3", 0, 
								OBJETO, 1, 0, 0, 0, 0, NINGUNO,
								MIEMBRO_NO_UNICO, 0, 0, NULL);

	status = buscarIdCualificadoInstancia(g, "MainMiBB2", "insNoExiste", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "MainMiBB2", "inspub", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "MainMiBB2", "inspriv", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoClase(g, "AA", "clasepub", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoClase(g, "AA", "clasepriv", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "MainMiBB2", "inspub", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	tablaSimbolosClasesCerrarAmbitoEnMain(g);

	status = buscarIdCualificadoClase(g, "JJ", "noExiste", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoInstancia(g, "MainMiBB2", "inspub", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoClase(g, "AA", "clasepub", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoClase(g, "AA", "clasepriv", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoClase(g, "AA", "noexiste", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	status = buscarIdCualificadoClase(g, "Noexiste", "noexiste", "main", &item, name);
	printf("%s %s\n", status == 0 ? "Encontrado en" : "No encontrado", name);

	return 0;
}