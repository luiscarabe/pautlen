// INCLUDES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "omicron.h"
#include "graph.h"

// OPERACIONES PRINCIPALES
// Del main: 
//Declaracion/eliminacion de tablas mas generales:
#define TOK_OP_INICIA_TSC		"inicia_tsc"
#define TOK_OP_CERRAR_TSC		"cerrar_tsc"
#define TOK_OP_INICIA_TSA_MAIN       "inicia_tsa_main"
#define TOK_OP_CERRAR_TSA_MAIN 		 "cerrar_tsa_main" 
//Para el main:
//Ambito de la funcion total main
#define TOK_OP_ABRIR_AMBITO_PPAL_MAIN    "abrir_ambito_ppal_main"
/*NOTA: El cierre de este ambito se hara automaticamente en cerrar_tsa_main
		No se por que no se abre en inicia_tsa_main.*/
//Simbolos
#define TOK_OP_INSERTAR_TSA_MAIN     "insertar_tsa_main"
//Ambitos de subfuciones
#define TOK_OP_ABRIR_AMBITO_TSA_MAIN    "abrir_ambito_tsa_main"
#define TOK_OP_CERRAR_AMBITO_TSA_MAIN    "cerrar_ambito_tsa_main"
//Para cada clase: 
#define TOK_OP_ABRIR_CLASE		"abrir_clase"
#define TOK_OP_ABRIR_CLASE_HEREDA		"abrir_clase_hereda"
#define TOK_OP_CERRAR_CLASE        "cerrar_clase"
#define TOK_OP_INSERTAR_TSC		"insertar_tsc"
#define TOK_OP_ABRIR_AMBITO_TSC    "abrir_ambito_tsc"
#define TOK_OP_CERRAR_AMBITO_TSC    "cerrar_ambito_tsc"
// Busqueda
#define TOK_OP_BUSCAR            "buscar"

// PARAMETROS (en orden de aparicion en el enunciado)
// En realidad la unica funcionalidad que incorpora parametros es buscar
#define TOK_DECLARAR_MAIN        "declarar_main"
#define TOK_DECLARAR_MIEMBRO_CLASE    "declarar_miembro_clase"
#define TOK_DECLARAR_MIEMBRO_INSTANCIA    "declarar_miembro_instancia"
#define TOK_DECLARAR_ID_LOCAL_METODO    "declarar_id_local_metodo"
#define TOK_JERARQUIA "jerarquia"
#define TOK_ID_NO_CUALIFICADO		"id_no_cualificado"
#define TOK_ID_CUALIFICADO_INSTANCIA    "id_cualificado_instancia"
#define TOK_ID_CUALIFICADO_CLASE    "id_cualificado_clase"


// Declaraciones

// Declaramos estas variables aqui para que puedan ser referenciadas por extern (tal vez haga falta en un futuro)
FILE* fin; 
FILE* fout;
Graph *tabla_clases;

void gestion_inicia_tsc();
void gestion_cerrar_tsc();
void gestion_inicia_tsa_main();
void gestion_cerrar_tsa_main();
void gestion_abrir_ambito_ppal_main();
void gestion_insertar_tsa_main();
void gestion_abrir_ambito_tsa_main();
void gestion_cerrar_ambito_tsa_main();
void gestion_abrir_clase();
void gestion_abrir_clase_hereda();
void gestion_cerrar_clase();
void gestion_insertar_tsc();
void gestion_abrir_ambito_tsc();
void gestion_cerrar_ambito_tsc();
void gestion_buscar();

// Main: analiza operacion principal y distribuye en subfunciones
int main(int argc, char* argv[]){
	char linea[110];
	char* token;

	if (argc != 3){
		fprintf(stderr, "Por favor, inserta por argumento el fichero de entrada y de salida.\n");
		return 1;
	}

	fin = fopen(argv[1], "r");
	if (!fin){
		fprintf(stderr, "Fichero de entrada inválido.\n");
		return 1;
	}

	fout = fopen(argv[2], "w");
	if (!fout){
		fprintf(stderr, "Fichero de salida inválido.\n");
		fclose(fin);
		return 1;
	}

	while(fgets(linea,100,fin) != NULL){


        token=strtok(linea," \n\t");
        fprintf(fout, "Comando: %s ", token);
        // Division por operaciones:
        if(strcmp(token, TOK_OP_INICIA_TSC) == 0){
        	gestion_inicia_tsc();
        } else if (strcmp(token, TOK_OP_CERRAR_TSC) == 0){
        	gestion_cerrar_tsc();
        } else if (strcmp(token, TOK_OP_INICIA_TSA_MAIN) == 0){
    		gestion_inicia_tsa_main();
        } else if (strcmp(token, TOK_OP_CERRAR_TSA_MAIN) == 0){
        	gestion_cerrar_tsa_main();
        } else if (strcmp(token, TOK_OP_ABRIR_AMBITO_PPAL_MAIN) == 0){
        	gestion_abrir_ambito_ppal_main();
        } else if (strcmp(token, TOK_OP_INSERTAR_TSA_MAIN) == 0){
        	gestion_insertar_tsa_main();
        } else if (strcmp(token, TOK_OP_ABRIR_AMBITO_TSA_MAIN) == 0){
            gestion_abrir_ambito_tsa_main();	
        } else if (strcmp(token, TOK_OP_CERRAR_AMBITO_TSA_MAIN) == 0){
		    gestion_cerrar_ambito_tsa_main();
        } else if (strcmp(token, TOK_OP_ABRIR_CLASE) == 0){
 			gestion_abrir_clase();
        } else if (strcmp(token, TOK_OP_ABRIR_CLASE_HEREDA) == 0){
        	gestion_abrir_clase_hereda();
        } else if (strcmp(token, TOK_OP_CERRAR_CLASE) == 0){
        	gestion_cerrar_clase();
        } else if (strcmp(token, TOK_OP_INSERTAR_TSC) == 0){
        	gestion_insertar_tsc();
 		} else if (strcmp(token, TOK_OP_ABRIR_AMBITO_TSC) == 0){
 			gestion_abrir_ambito_tsc();
		} else if (strcmp(token, TOK_OP_CERRAR_AMBITO_TSC) == 0){
			gestion_cerrar_ambito_tsc();
		} else if (strcmp(token, TOK_OP_BUSCAR) == 0){
			gestion_buscar();
    	}
    	else{
    		fprintf(fout, "COMANDO NO VALIDO\n");
    		return -1;
    	}

    	fprintf(fout, "\n");
    }

   
    fclose(fin);
    fclose(fout);

    return 0;
}

void leer_siguiente(char** cadena){
	// Copia el siguiente tok en una variable
	// Asumimos que en esa variableno hay nada de provecho
	char *token;


	token=strtok(NULL," \n\t");
	*cadena = (char*) malloc((strlen(token)+1)*sizeof(char));
	strcpy(*cadena, token);
	fprintf(fout, "%s ", *cadena);

	return;
}

void gestion_inicia_tsc(){
	//Sin argumentos ni parametros
	
	//TODO: Amiguedad en el enunciado, en el ejemplo si tiene un arg pero en las especificaciones no

	iniciarTablaSimbolosClases(&tabla_clases, "hola");

}

void gestion_cerrar_tsc(){
	//Sin argumentos ni parametros

	tablaSimbolosClasesToDot(tabla_clases);
  imprimirTablasHash(tabla_clases);

	deleteGraph(tabla_clases);

}

void gestion_inicia_tsa_main(){
	//Sin argumentos ni parametros

	return;
}

void gestion_cerrar_tsa_main(){
	//Sin argumentos ni parametros

	return;
}

void gestion_abrir_ambito_ppal_main(){
	//Sin argumentos ni parametros

	return;
}

void gestion_insertar_tsa_main(){
	/*Sin parametros.
	Argumentos:
		nombre_id
		categoria
		tipo_basico
		estructura
		tipo_acceso
		tipo_miembro
	*/
	char *nombre_id = NULL, *aux = NULL;
	int categoria, tipo_basico, estructura, tipo_acceso, tipo_miembro;

	leer_siguiente(&nombre_id);

	leer_siguiente(&aux);
	categoria = atoi(aux);
	free(aux);

	leer_siguiente(&aux);
	tipo_basico = atoi(aux);
	free(aux);

	leer_siguiente(&aux);
	estructura = atoi(aux);
	free(aux);

	leer_siguiente(&aux);
	tipo_acceso = atoi(aux);
	free(aux);

	leer_siguiente(&aux);
	tipo_miembro = atoi(aux);
	free(aux);

	//TODO:

	insertarTablaSimbolosMain(tabla_clases, categoria, nombre_id, estructura, tipo_basico, 0, 0, 0, 0, 0, tipo_acceso, tipo_miembro, 0, 0, NULL);
	
	free(nombre_id);
	return;
}
void gestion_abrir_ambito_tsa_main(){
	/*Sin parametros
	Argumentos:
		nombre_ambito
		tipo_basico
	*/
	char *nombre_ambito = NULL, *aux = NULL;
	int tipo_basico;

	leer_siguiente(&nombre_ambito);

	leer_siguiente(&aux);
	tipo_basico = atoi(aux);
	free(aux);

	//TODO
	tablaSimbolosClasesAbrirAmbitoEnMain(tabla_clases, nombre_ambito, FUNCION, NINGUNO, tipo_basico, 0, 0, 0, NULL);

	free(nombre_ambito);
	return;
}

void gestion_cerrar_ambito_tsa_main(){
	//Sin argumentos ni parametros

	tablaSimbolosClasesCerrarAmbitoEnMain(tabla_clases);
	return;
}

void gestion_abrir_clase(){
	/*Sin parametros
	Argumentos:
		nombre_clase
	*/
	char *nombre_clase = NULL;

	leer_siguiente(&nombre_clase);

	abrirClase(tabla_clases, nombre_clase);
	free(nombre_clase);
	return;

}
void gestion_abrir_clase_hereda(){
	/* Sin parametros
	Argumentos:
		nombre_clase
		padre1
		padre2 
		... (num indefinido) */

	char *token = NULL;
	char *nombre_clase = NULL;
	char **nombres_padres = NULL;
	int num_padres, i;

	num_padres = 0;

	leer_siguiente(&nombre_clase);

	/*Aqui no aplicamos leer siguiente por el tema del numero de 
	  argumentos desconocido*/
	while ((token=strtok(NULL," \n\t"))!=NULL){
    num_padres++;
    nombres_padres = (char **) realloc(nombres_padres, sizeof(char*)*num_padres);                     
    nombres_padres[num_padres-1]= (char*)malloc((strlen(token)+1)*sizeof(char));
    strcpy(nombres_padres[num_padres-1], token);
  }

  abrirClaseHeredaN(tabla_clases, 
                  nombre_clase,          
                  num_padres,nombres_padres);
  for(i=0; i<num_padres; i++){
  	free(nombres_padres[i]);
  }
  free(nombres_padres);
  free(nombre_clase);

  return;

}

void gestion_cerrar_clase(){
	/*Sin parametros
	 Argumentos:
		nombre_clase
	*/

	char *nombre_clase = NULL;

	leer_siguiente(&nombre_clase);
	
	cerrarClase(tabla_clases, nombre_clase);
	free(nombre_clase);
	return;
}

void gestion_insertar_tsc(){
	/*Sin parametros
	Argumentos:
		nombre_clase
		nombre_simbolo
		categoria
		tipo_basico
		estructura
		tipo_acceso
		tipo_miembro
	*/
	char *nombre_clase = NULL , *nombre_simbolo = NULL, *aux = NULL;
	int categoria, tipo_basico, estructura, tipo_acceso, tipo_miembro;

	leer_siguiente(&nombre_clase);

	leer_siguiente(&nombre_simbolo);

	leer_siguiente(&aux);
	categoria = atoi(aux);
	free(aux);

	leer_siguiente(&aux);
	tipo_basico = atoi(aux);
	free(aux);

	leer_siguiente(&aux);
	estructura = atoi(aux);
	free(aux);

	leer_siguiente(&aux);
	tipo_acceso = atoi(aux);
	free(aux);

	leer_siguiente(&aux);
	tipo_miembro = atoi(aux);
	free(aux);

	insertarTablaSimbolosClases(tabla_clases, nombre_clase, categoria, nombre_simbolo, estructura,
		tipo_basico, 0, 0, 0, 0, 0, tipo_acceso, tipo_miembro, 0, 0, NULL);                    

	free(nombre_clase);
	free(nombre_simbolo);

	return;

}

void gestion_abrir_ambito_tsc(){
	/*Sin parametros
	Argumentos:
		nombre_clase
		nombre_ambito
		categoria
		tipo_basico
		tipo_acceso
		tipo_miembro
	*/
	char *nombre_clase = NULL, *nombre_ambito = NULL, *aux = NULL;
	int categoria, tipo_basico,  tipo_acceso, tipo_miembro;

	leer_siguiente(&nombre_clase);

	leer_siguiente(&nombre_ambito);

	leer_siguiente(&aux);
	categoria = atoi(aux);
	free(aux);

	leer_siguiente(&aux);
	tipo_basico = atoi(aux);
	free(aux);

	leer_siguiente(&aux);
	tipo_acceso = atoi(aux);
	free(aux);

	leer_siguiente(&aux);
	tipo_miembro = atoi(aux);
	free(aux);

	if (tipo_miembro == MIEMBRO_UNICO)
		tablaSimbolosClasesAbrirAmbitoEnClase(tabla_clases, nombre_clase, nombre_ambito, METODO_NO_SOBREESCRIBIBLE, NINGUNO, tipo_basico, 0, 0, 0, NULL);
	else
		tablaSimbolosClasesAbrirAmbitoEnClase(tabla_clases, nombre_clase, nombre_ambito, METODO_SOBREESCRIBIBLE, NINGUNO, tipo_basico, 0, 0, 0, NULL);

	free(nombre_clase);
	free(nombre_ambito);

	return;
}


void gestion_cerrar_ambito_tsc(){
	/*Sin parametros
	Argumentos:
		nombre_clase
	*/
	char* nombre_clase = NULL;

	leer_siguiente(&nombre_clase);

	imprimirTablasHash(tabla_clases);
	printf("____________________________________________\n");
	tablaSimbolosClasesCerrarAmbitoEnClase(tabla_clases, nombre_clase);

	free(nombre_clase);
	return;

}

void gestion_buscar(){
	/*Con Parametros y argumentos. 
		Estructuras aceptadas:
			declarar_main
				nombre_id
			declarar_miembro_clase
				nombre_clase_desde
				nombre_miembro
			declarar_miembro_instancia
				nombre_clase_desde
				nombre_miembro
			declarar_id_local_metodo
				nombre_clase
				nombre_id
			jerarquia
				nombre_id
				nombre_clase
			id_no_cualificado
				nombre_id
				nombre_clase_desde
			id_cualificado_instancia
				nombre_instancia
				nombre_id
				nombre_clase_desde
			id_cualificado_clase
				nombre_clase_cualifica
				nombre_id
				nombre_clase_desde*/

	HT_item *e;
	char *name = (char *) malloc(sizeof(char) * 64);
	char  *parametro = NULL;
	char  *nombre_id = NULL, *nombre_clase_desde = NULL, 
		  *nombre_miembro = NULL, *nombre_clase = NULL, 
		  *nombre_instancia = NULL, *nombre_clase_cualifica = NULL;

	leer_siguiente(&parametro);

	if(strcmp(parametro, TOK_DECLARAR_MAIN) == 0){

		leer_siguiente(&nombre_id);

		if (buscarIdNoCualificado(tabla_clases, nombre_id,
													"main", &e, name) == OK)
			printf("TOK_DECLARAR_MAIN OK\n");
		else
			printf("TOK_DECLARAR_MAIN ERR\n");

		free(name);
		free(nombre_id);

	} else if(strcmp(parametro, TOK_DECLARAR_MIEMBRO_CLASE) == 0){

		leer_siguiente(&nombre_clase_desde);
		leer_siguiente(&nombre_miembro);

		if (buscarParaDeclararMiembroClase(tabla_clases, nombre_miembro, nombre_clase_desde, &e, name) == OK)
			printf("TOK_DECLARAR_MIEMBRO_CLASE OK\n");
		else
			printf("TOK_DECLARAR_MIEMBRO_CLASE ERR\n");

		free(name);
		free(nombre_clase_desde);
		free(nombre_miembro);

	} else if(strcmp(parametro, TOK_DECLARAR_MIEMBRO_INSTANCIA) == 0){

		leer_siguiente(&nombre_clase_desde);
		leer_siguiente(&nombre_miembro);

		if (buscarParaDeclararMiembroInstancia(tabla_clases, nombre_miembro, nombre_clase_desde, &e, name) == OK)
			printf("TOK_DECLARAR_MIEMBRO_INSTANCIA OK\n");
		else
			printf("TOK_DECLARAR_MIEMBRO_INSTANCIA ERR\n");

		free(name);
		free(nombre_clase_desde);
		free(nombre_miembro);

	} else if(strcmp(parametro, TOK_DECLARAR_ID_LOCAL_METODO) == 0){

		leer_siguiente(&nombre_clase);
		leer_siguiente(&nombre_id);

		if (buscarIdNoCualificado(tabla_clases, nombre_id,
													nombre_clase, &e, name) == OK)
			printf("TOK_DECLARAR_ID_LOCAL_METODO OK\n");
		else
			printf("TOK_DECLARAR_ID_LOCAL_METODO ERR\n");

		free(name);
		free(nombre_clase);
		free(nombre_id);

	} else if(strcmp(parametro, TOK_JERARQUIA) == 0){

		leer_siguiente(&nombre_id);
		leer_siguiente(&nombre_clase);

		if (buscarIdNoCualificado(tabla_clases, nombre_id,
													nombre_clase, &e, name) == OK)
			printf("TOK_JERARQUIA OK\n");
		else
			printf("TOK_JERARQUIA ERR\n");

		free(name);
		free(nombre_id);
		free(nombre_clase);

	} else if(strcmp(parametro, TOK_ID_NO_CUALIFICADO) == 0){

		leer_siguiente(&nombre_id);
		leer_siguiente(&nombre_clase_desde);

		if (buscarIdNoCualificado(tabla_clases, nombre_id,
													nombre_clase, &e, name) == OK)
			printf("TOK_ID_NO_CUALIFICADO OK\n");
		else
			printf("TOK_ID_NO_CUALIFICADO ERR\n");

		free(name);
		free(nombre_id);
		free(nombre_clase_desde);

	} else if(strcmp(parametro, TOK_ID_CUALIFICADO_INSTANCIA) == 0){

		leer_siguiente(&nombre_instancia);
		leer_siguiente(&nombre_id);
		leer_siguiente(&nombre_clase_desde);

		if (buscarIdCualificadoInstancia(tabla_clases, nombre_instancia,
													nombre_id, nombre_clase, &e, name) == OK)
			printf("TOK_ID_CUALIFICADO_INSTANCIA OK\n");
		else
			printf("TOK_ID_CUALIFICADO_INSTANCIA ERR\n");

		free(name);
		free(nombre_instancia);
		free(nombre_id);
		free(nombre_clase_desde);

	} else if(strcmp(parametro, TOK_ID_CUALIFICADO_CLASE) == 0){

		leer_siguiente(&nombre_clase_cualifica);
		leer_siguiente(&nombre_id);
		leer_siguiente(&nombre_clase_desde);

		if (buscarIdCualificadoClase(tabla_clases, nombre_instancia,
													nombre_id, nombre_clase, &e, name) == OK)
			printf("TOK_ID_CUALIFICADO_CLASE OK\n");
		else
			printf("TOK_ID_CUALIFICADO_CLASE ERR\n");

		free(name);
		free(nombre_clase_cualifica);
		free(nombre_id);
		free(nombre_clase_desde);
	}

	free(parametro);
	return;
}
