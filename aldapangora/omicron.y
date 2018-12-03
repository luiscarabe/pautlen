%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "omicron.h"
	#include "generacion.h"
	#include "graph.h"

	/* Del main*/
	extern FILE* yyin;
	extern FILE* compilador_log;

	/*Fichero para guardar codigo NASM*/

	extern FILE* fout;

	/* En fichero especificacion Flex*/
	extern int yylex(void);
	extern int row;
	extern int col;
	extern int error_flag;

	Graph* tabla_simbolos;

	/*Variables globales necesarias para la inserción de identificadores en la tabla de símbolos*/
	//int categoria;
	int tipo_actual;
	int clase_actual;

	int tamanio_vector_actual;
	int num_variable_local_actual;
	int pos_variable_local_actual;
	int num_param;
	int pos_param;

	/* Locales */
	int yyerror (const char *s);


%}

%union{

	tipo_atributos atributos;

}


/* PALABRAS RESERVADAS */
%token TOK_NONE
%token TOK_CLASS
%token TOK_INHERITS
%token TOK_INSTANCE_OF
%token TOK_DISCARD
%token TOK_ITSELF
%token TOK_HIDDEN
%token TOK_SECRET
%token TOK_EXPOSED
%token TOK_UNIQUE
%token TOK_FUNCTION
%token TOK_RETURN
%token TOK_MAIN
%token TOK_INT
%token TOK_BOOLEAN
%token TOK_ARRAY
%token TOK_IF
%token TOK_ELSE
%token TOK_WHILE
%token TOK_SCANF
%token TOK_PRINTF
/* IDENTIFICADOR */
%token TOK_IDENTIFICADOR
/* OPERADORES */
%token TOK_IGUAL
%token TOK_DISTINTO
%token TOK_MENORIGUAL
%token TOK_MAYORIGUAL
%token TOK_OR
%token TOK_AND
/* CONSTANTES */
%token TOK_CONSTANTE_ENTERA
%token TOK_FALSE
%token TOK_TRUE


/*SEMANTICO: simbolos con hijos terminales, no tan seguro de terminales*/
%type <atributos> TOK_CONSTANTE_ENTERA
%type <atributos> TOK_IDENTIFICADOR


/*SEMANTICO: simbolos no terminales*/
%type <atributos> programa
%type <atributos> declaraciones
%type <atributos> declaracion
%type <atributos> modificadores_acceso
%type <atributos> clase
%type <atributos> declaracion_clase
%type <atributos> modificadores_clase
%type <atributos> clase_escalar
%type <atributos> tipo
%type <atributos> clase_objeto
%type <atributos> clase_vector
%type <atributos> funciones
%type <atributos> funcion
%type <atributos> tipo_retorno
%type <atributos> parametros_funcion
%type <atributos> resto_parametros_funcion
%type <atributos> declaraciones_funcion
%type <atributos> sentencias
%type <atributos> sentencia
%type <atributos> sentencia_simple
%type <atributos> destruir_objeto
%type <atributos> bloque
%type <atributos> asignacion
%type <atributos> elemento_vector
%type <atributos> condicional
%type <atributos> bucle
%type <atributos> lectura
%type <atributos> escritura
%type <atributos> retorno_funcion
%type <atributos> exp
%type <atributos> identificador_clase
%type <atributos> lista_expresiones
%type <atributos> resto_lista_expresiones
%type <atributos> comparacion
%type <atributos> constante
%type <atributos> constante_logica
%type <atributos> constante_entera
%type <atributos> identificadores
%type <atributos> identificador
%type <atributos> inicioTabla
%type <atributos> escritura_cabeceras_datos
%type <atributos> escritura_main

%left '+' '-' TOK_OR
%left '*' '/' TOK_AND
%right NEG_UNARIA '!'

/*Axioma*/
%start programa


%% /*Seccion de reglas*/

programa: inicioTabla TOK_MAIN '{' escritura_cabeceras_datos  declaraciones  funciones escritura_main sentencias '}' escritura_fin { fprintf(compilador_log, ";R:\tprograma: TOK_MAIN '{' declaraciones funciones sentencias '}'\n");}
		| inicioTabla TOK_MAIN '{' escritura_cabeceras_datos funciones escritura_main sentencias '}' { fprintf(compilador_log, ";R:\tprograma: TOK_MAIN '{' funciones sentencias '}'\n");} ;

inicioTabla: { iniciarTablaSimbolosClases(&tabla_simbolos, "Tablasimbolos"); }

declaraciones:  declaracion {fprintf(compilador_log, ";R:\tdeclaraciones: declaracion\n");}
			 | declaracion declaraciones {fprintf(compilador_log, ";R:\tdeclaraciones: declaracion declaraciones\n");};


declaracion: modificadores_acceso clase identificadores ';'
			{fprintf(compilador_log, ";R:\tdeclaracion: modificadores_acceso clase identificadores ';'\n");}
 		   | modificadores_acceso declaracion_clase ';'  {fprintf(compilador_log, ";R:\tdeclaracion: modificadores_acceso declaracion_clase ';'\n");};

modificadores_acceso: TOK_HIDDEN TOK_UNIQUE {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_HIDDEN TOK_UNIQUE\n");}
					| TOK_SECRET TOK_UNIQUE {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_SECRET TOK_UNIQUE\n");}
					| TOK_EXPOSED TOK_UNIQUE {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_EXPOSED TOK_UNIQUE\n");}
					| TOK_HIDDEN {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_HIDDEN\n");}
					| TOK_SECRET {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_SECRET\n");}
					| TOK_EXPOSED {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_EXPOSED\n");}
					| TOK_UNIQUE {fprintf(compilador_log, ";R:\tmodificadores_acceso: TOK_UNIQUE\n");}
					| /*lambda*/{fprintf(compilador_log, ";R:\tmodificadores_acceso: \n");};

clase: clase_escalar 
		{ fprintf(compilador_log, ";R:\tclase: clase_escalar\n");
		  clase_actual=ESCALAR;	}								
	 | clase_vector 
	 	{ fprintf(compilador_log, ";R:\tclase: clase_vector\n");
	 	  clase_actual = VECTOR; }
	 | clase_objeto
	 	{ fprintf(compilador_log, ";R:\tclase: clase_objeto\n");
	   	  clase_actual = OBJETO; };


declaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR TOK_INHERITS identificadores '{' declaraciones funciones '}' {fprintf(compilador_log, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR TOK_INHERITS identificadores '{' declaraciones funciones '}'\n");}
				 | modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}' {fprintf(compilador_log, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}'\n");};


modificadores_clase: /*lambda*/ {fprintf(compilador_log, ";R:\tmodificadores_clase: \n");};


clase_escalar: tipo 
				{ fprintf(compilador_log, ";R:\tclase_escalar: tipo\n");
				  tamanio_vector_actual = 1;};


tipo: TOK_INT 
		{   fprintf(compilador_log, ";R:\ttipo: TOK_INT\n");
			tipo_actual = INT;
	    }
	| TOK_BOOLEAN 
		{ 	fprintf(compilador_log, ";R:\ttipo: TOK_BOOLEAN\n");
			tipo_actual = BOOLEAN;
		};


clase_objeto: '{' TOK_IDENTIFICADOR '}' {fprintf(compilador_log, ";R:\tclase_objeto: '{' TOK_IDENTIFICADOR '}'\n");};


clase_vector: TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']' 
				{ fprintf(compilador_log, ";R:\tclase_vector: TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']'\n");
				  tamanio_vector_actual = $4.valor_entero;
				  if ((tamanio_vector_actual < 1) || (tamanio_vector_actual > MAX_TAMANIO_VECTOR)){
					fprintf(stderr, "Error, tamaño de vector no válido. Linea %d columna %d", row, col);
					return 0;
					}};


identificadores: identificador {fprintf(compilador_log, ";R:\tidentificadores: TOK_IDENTIFICADOR\n");
								}
			   | identificador ',' identificadores {fprintf(compilador_log, ";R:\tidentificadores: TOK_IDENTIFICADOR ',' identificadores\n");};


identificador: TOK_IDENTIFICADOR 
				{
					HT_item *e;
					char nombre [100];
					int aux;

					/*TODO, conseguir el nombre del ambito*/
					sprintf(nombre, "main_%s", $1.lexema);
					if(buscarParaDeclararIdTablaSimbolosAmbitos(tabla_simbolos, nombre, &e, "main") == OK){
						fprintf(stderr, "Identificador %s duplicado. Linea %d columna %d\n", $1.lexema, row, col);
						return ERR;
					}

					printf("declarando variable %s", nombre);

					/*TODO llamada correcta funcion*/
					aux = insertarTablaSimbolosMain(tabla_simbolos, VARIABLE,
											  nombre,         clase_actual,
											  tipo_actual,	  0,                    
											  0,      		  0,
											  0,              tamanio_vector_actual,      
											  ACCESO_TODOS,        MIEMBRO_NO_UNICO, 
											  0,              0,
											  NULL);
					
					printf("RETORNO %d", aux);
					/*Insertamos en segmento .bss*/

					declarar_variable(fout, $1.lexema,  tipo_actual,  tamanio_vector_actual);

				}

funciones: funcion funciones {fprintf(compilador_log, ";R:\tfunciones: funcion funciones\n");}
		 | /*lambda*/ {fprintf(compilador_log, ";R:\tfunciones: \n");};


funcion: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{'
		 declaraciones_funcion sentencias '}' {fprintf(compilador_log, ";R:\tfuncion: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'\n");};


tipo_retorno: TOK_NONE {fprintf(compilador_log, ";R:\ttipo_retorno: TOK_NONE\n");}
			| tipo {fprintf(compilador_log, ";R:\ttipo_retorno: tipo\n");}
			| clase_objeto {fprintf(compilador_log, ";R:\ttipo_retorno: clase_objeto\n");};


parametros_funcion: parametro_funcion resto_parametros_funcion {fprintf(compilador_log, ";R:\tparametros_funcion: parametro_funcion resto_parametros_funcion\n");}
				  | /*lambda*/ {fprintf(compilador_log, ";R:\tparametros_funcion: \n");};


resto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion {fprintf(compilador_log, ";R:\tresto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion\n");}
						| /*lambda*/ {fprintf(compilador_log, ";R:\tresto_parametros_funcion: \n");};


parametro_funcion: tipo TOK_IDENTIFICADOR {fprintf(compilador_log, ";R:\tparametro_funcion: tipo TOK_IDENTIFICADOR\n");}
				 | clase_objeto TOK_IDENTIFICADOR {fprintf(compilador_log, ";R:\tparametro_funcion: clase_objeto TOK_IDENTIFICADOR\n");};


declaraciones_funcion: declaraciones {fprintf(compilador_log, ";R:\tdeclaraciones_funcion: declaraciones\n");}
					 | /*lambda*/ {fprintf(compilador_log, ";R:\tdeclaraciones_funcion: \n");};


sentencias: sentencia {fprintf(compilador_log, ";R:\tsentencias: sentencia\n");}
		  | sentencia sentencias {fprintf(compilador_log, ";R:\tsentencias: sentencia sentencias\n");};


sentencia: sentencia_simple ';' {fprintf(compilador_log, ";R:\tsentencia: sentencia_simple ';'\n");}
		 | bloque {fprintf(compilador_log, ";R:\tsentencia: bloque\n");};


sentencia_simple: asignacion {fprintf(compilador_log, ";R:\tsentencia_simple: asignacion\n");}
				| escritura {fprintf(compilador_log, ";R:\tsentencia_simple: escritura\n");}
				| lectura {fprintf(compilador_log, ";R:\tsentencia_simple: lectura\n");}
				| retorno_funcion {fprintf(compilador_log, ";R:\tsentencia_simple: retorno_funcion\n");}
				| identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')' {fprintf(compilador_log, ";R:\tsentencia_simple: identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
				| TOK_IDENTIFICADOR '(' lista_expresiones ')' {fprintf(compilador_log, ";R:\tsentencia_simple: TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
				| destruir_objeto {fprintf(compilador_log, ";R:\tsentencia_simple: destruir_objeto\n");};


destruir_objeto: TOK_DISCARD TOK_IDENTIFICADOR {fprintf(compilador_log, ";R:\tdestruir_objeto: TOK_DISCARD TOK_IDENTIFICADOR\n");};


bloque: condicional {fprintf(compilador_log, ";R:\tbloque: condicional\n");}
	  | bucle {fprintf(compilador_log, ";R:\tbloque: bucle\n");};


asignacion: TOK_IDENTIFICADOR '=' exp
			{fprintf(compilador_log, ";R:\tasignacion: TOK_IDENTIFICADOR '=' exp\n");
			 //TODO nombre ambito
			char nombre[100];
			char nombre_ambito_encontrado [100];
			HT_item* e;
			sprintf(nombre, "main_%s", $1.lexema);
			printf("buscando variabe %s", nombre);
			if(buscarIdNoCualificado(tabla_simbolos, 
                 					nombre, 
                 					"main",
                 					&e, 
  									nombre_ambito_encontrado) == ERR){
    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se encuentra simbolo en asignacion\n", row, col);}
    		else if (HT_itemGetCategory(e) == FUNCION){
    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se puede asignar una funcion\n", row, col);}
    		else if (HT_itemGetClass(e) == VECTOR){
    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. La clase del simboo es vector\n", row, col);
    		}
    		else if(HT_itemGetType(e) != $3.tipo){
    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. Asignacion de tipos incompatibles\n", row, col);
    		}

    		asignar(fout, $1.lexema, $3.direcciones);

			}
		  | elemento_vector '=' exp {fprintf(compilador_log, ";R:\tasignacion: elemento_vector '=' exp\n");}
		  | elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')' {fprintf(compilador_log, ";R:\tasignacion: elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
		  | TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')' {fprintf(compilador_log, ";R:\tasignacion: TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
		  | identificador_clase '.' TOK_IDENTIFICADOR '=' exp {fprintf(compilador_log, ";R:\tasignacion: identificador_clase '.' TOK_IDENTIFICADOR '=' exp\n");};


elemento_vector: TOK_IDENTIFICADOR '[' exp ']' {fprintf(compilador_log, ";R:\telemento_vector: TOK_IDENTIFICADOR '[' exp ']'\n");};


condicional: TOK_IF '(' exp ')' '{' sentencias '}' {fprintf(compilador_log, ";R:\tcondicional: TOK_IF '(' exp ')' '{' sentencias '}'\n");}
		   | TOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}' {fprintf(compilador_log, ";R:\tcondicional: TOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}'\n");};


bucle: TOK_WHILE '(' exp ')' '{' sentencias '}' {fprintf(compilador_log, ";R:\tdbucle: TOK_WHILE '(' exp ')' '{' sentencias '}'\n");};


lectura: TOK_SCANF TOK_IDENTIFICADOR {fprintf(compilador_log, ";R:\tlectura: TOK_SCANF TOK_IDENTIFICADOR\n");}
	   | TOK_SCANF elemento_vector {fprintf(compilador_log, ";R:\tlectura: TOK_SCANF elemento_vector\n");};


escritura: TOK_PRINTF exp 
			{fprintf(compilador_log, ";R:\tescritura: TOK_PRINTF exp\n");
			escribir(fout, $2.direcciones, $2.tipo);			
			};


retorno_funcion: TOK_RETURN exp {fprintf(compilador_log, ";R:\tretorno_funcion: TOK_RETURN exp\n");}
			   | TOK_RETURN TOK_NONE {fprintf(compilador_log, ";R:\tretorno_funcion: TOK_RETURN TOK_NONE\n");};


exp: exp '+' exp {fprintf(compilador_log, ";R:\texp: exp '+' exp\n");}
   | exp '-' exp {fprintf(compilador_log, ";R:\texp: exp '-' exp\n");}
   | exp '/' exp {fprintf(compilador_log, ";R:\texp: exp '/' exp\n");}
   | exp '*' exp {fprintf(compilador_log, ";R:\texp: exp '*' exp\n");}
   | '-'  exp %prec NEG_UNARIA {fprintf(compilador_log, ";R:\texp: '-' exp\n");}
   | exp TOK_AND exp {fprintf(compilador_log, ";R:\texp: exp TOK_AND exp\n");}
   | exp TOK_OR exp {fprintf(compilador_log, ";R:\texp: exp TOK_OR exp\n");}
   | '!' exp {fprintf(compilador_log, ";R:\texp: '!' exp\n");}
   | TOK_IDENTIFICADOR {fprintf(compilador_log, ";R:\texp: TOK_IDENTIFICADOR\n");
	//TODO conseguir nombre con ambit bien
			char nombre[100];
			char nombre_ambito_encontrado [100];
			HT_item* e = NULL;
			sprintf(nombre, "main_%s", $1.lexema);
			if(buscarIdNoCualificado(tabla_simbolos, 
                 					nombre, 
                 					"main",
                 					&e, 
  									nombre_ambito_encontrado) == ERR){
    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se encuentra simbolo.\n", row, col);}
    		else if (HT_itemGetCategory(e) == FUNCION){
    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. El simbolo en asignacion es una funcion\n", row, col);}
    		else if (HT_itemGetClass(e) == VECTOR){
    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. La clase del simboo es vector\n", row, col);
    		}
    		$$.tipo = HT_itemGetType(e);
    		$$.direcciones = 1;
    		escribir_operando(fout, $1.lexema, 1);
    	}
   | constante 
   		{fprintf(compilador_log, ";R:\texp: constante\n");
   		 $$.tipo = $1.tipo;
   		 $$.direcciones = $1.direcciones; }
						
   | '(' exp ')' {fprintf(compilador_log, ";R:\texp: '(' exp ')'\n");}
   | '(' comparacion ')' {fprintf(compilador_log, ";R:\texp: '(' comparacion ')'\n");}
   | elemento_vector {fprintf(compilador_log, ";R:\texp: elemento_vector\n");}
   | TOK_IDENTIFICADOR '(' lista_expresiones ')' {fprintf(compilador_log, ";R:\texp: TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
   | identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')' {fprintf(compilador_log, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
   | identificador_clase '.' TOK_IDENTIFICADOR {fprintf(compilador_log, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR\n");};


identificador_clase: TOK_IDENTIFICADOR {fprintf(compilador_log, ";R:\tidentificador_clase: TOK_IDENTIFICADOR\n");}
				   | TOK_ITSELF {fprintf(compilador_log, ";R:\tidentificador_clase: TOK_ITSELF\n");};


lista_expresiones: exp resto_lista_expresiones {fprintf(compilador_log, ";R:\tlista_expresiones: exp resto_lista_expresiones\n");}
				 | /*lambda*/ {fprintf(compilador_log, ";R:\tlista_expresiones: \n");};


resto_lista_expresiones: ',' exp resto_lista_expresiones {fprintf(compilador_log, ";R:\tresto_lista_expresiones: ',' exp resto_lista_expresiones\n");}
					   | /*lambda*/ {fprintf(compilador_log, ";R:\tresto_lista_expresiones: \n");};


comparacion: exp TOK_IGUAL exp {fprintf(compilador_log, ";R:\tcomparacion: exp TOK_IGUAL exp\n");}
		   | exp TOK_DISTINTO exp {fprintf(compilador_log, ";R:\tcomparacion: exp TOK_DISTINTO exp\n");}
		   | exp TOK_MENORIGUAL exp {fprintf(compilador_log, ";R:\tcomparacion: exp TOK_MENORIGUAL exp\n");}
		   | exp TOK_MAYORIGUAL exp {fprintf(compilador_log, ";R:\tcomparacion: exp TOK_MAYORIGUAL exp\n");}
		   | exp '<' exp {fprintf(compilador_log, ";R:\tcomparacion: exp '<' exp\n");}
		   | exp '>' exp {fprintf(compilador_log, ";R:\tcomparacion: exp '>' exp\n");};


constante: constante_logica {fprintf(compilador_log, ";R:\tconstante: constante_logica\n");}
			{}
		 | constante_entera 
		 {
		 	fprintf(compilador_log, ";R:\tconstante: constante_entera\n");
		 	$$.tipo = $1.tipo;
		 	$$.direcciones = $1.direcciones;
		 };


constante_logica: TOK_TRUE {fprintf(compilador_log, ";R:\tconstante_logica: TOK_TRUE\n");}
					{}

				| TOK_FALSE {fprintf(compilador_log, ";R:\tconstante_logica: TOK_FALSE\n");}
					{};


constante_entera: TOK_CONSTANTE_ENTERA 
					{fprintf(compilador_log, ";R:\tconstante_entera: TOK_CONSTANTE_ENTERA\n");
					 $$.tipo=INT;
					 $$.direcciones = 0 ;
					 $$.valor_entero = $1.valor_entero;
					 char aux[10];
					 sprintf(aux, "%d", $1.valor_entero);
					 escribir_operando(fout, aux, 0);
					};

escritura_cabeceras_datos: {
	escribir_subseccion_data(fout);
	escribir_cabecera_bss(fout);

};


escritura_main:{
  escribir_segmento_codigo(fout);
	escribir_inicio_main(fout);
};

escritura_fin:{
	escribir_fin(fout);
};


%%


int yyerror (const char *s)
{
	if(error_flag == 0){
    	fprintf(stderr, "****Error sintactico en [lin %d, col %d]\n", row, col);
    }
    return 0;
}
