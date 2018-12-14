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

	/* variable para la generacion de etiquetas */
	int etiqueta = 0;
	int cuantos_no = 0;

	Graph* tabla_simbolos;

	/*Variables globales necesarias para la inserción de identificadores en la tabla de símbolos*/
	//int categoria;
	int tipo_actual;
	int clase_actual;

	int tamanio_vector_actual;
	int num_variable_local_actual;
	int pos_variable_local_actual;
	int num_parametro_actual;
	int pos_parametro_actual;
	int tipo_retorno_actual;

	/*Array para almacenar tipos de parametros función*/
	int array_tipo_parametros[255];
	/* Array para almacenar nombres de parametros función*/
	char array_nombre_parametros[255][MAX_LONG_ID+1];


	/*Variables auxiliares para codigo*/
	int i; /*Bucles*/
	char nombre_parametro[MAX_LONG_ID + 3];
	char nombre_funcion[255];



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
%type <atributos> fn_declaration
%type <atributos> fn_complete_name
%type <atributos> fn_name
%type <atributos> tipo_retorno
%type <atributos> idpf
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
%type <atributos> if_exp
%type <atributos> if_exp_sentencias
%type <atributos> bucle
%type <atributos> while_exp
%type <atributos> while_ini
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

inicioTabla:
	{
		iniciarTablaSimbolosClases(&tabla_simbolos, "Tablasimbolos");
	}

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
		{
			fprintf(compilador_log, ";R:\ttipo: TOK_INT\n");
			$$.tipo = INT;
			tipo_actual = INT;
	    }
	| TOK_BOOLEAN
		{
			fprintf(compilador_log, ";R:\ttipo: TOK_BOOLEAN\n");
			$$.tipo = BOOLEAN;
			tipo_actual = BOOLEAN;
		};


clase_objeto: '{' TOK_IDENTIFICADOR '}' {fprintf(compilador_log, ";R:\tclase_objeto: '{' TOK_IDENTIFICADOR '}'\n");};


clase_vector: TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']'
				{
					tamanio_vector_actual = $4.valor_entero;
					if ((tamanio_vector_actual < 1) || (tamanio_vector_actual > MAX_TAMANIO_VECTOR)){
						fprintf(stderr, "Error, tamaño de vector no válido. Linea %d columna %d", row, col);
						return ERR;
					}
				};


identificadores: identificador {fprintf(compilador_log, ";R:\tidentificadores: TOK_IDENTIFICADOR\n");}
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


					/*TODO llamada correcta funcion*/
					aux = insertarTablaSimbolosMain(tabla_simbolos, VARIABLE,
											  nombre,         clase_actual,
											  tipo_actual,	  0,
											  0,      		  0,
											  0,              tamanio_vector_actual,
											  ACCESO_TODOS,        MIEMBRO_NO_UNICO,
											  0,              0,
											  NULL);

					/*Insertamos en segmento .bss*/

					declarar_variable(fout, $1.lexema,  tipo_actual,  tamanio_vector_actual);

				}

funciones: funcion funciones {fprintf(compilador_log, ";R:\tfunciones: funcion funciones\n");}
		 | /*lambda*/ {fprintf(compilador_log, ";R:\tfunciones: \n");};


funcion: fn_declaration sentencias '}'
				{
					//void retornarFuncion(FILE * fd_s, int es_variable);
					fprintf(compilador_log, ";R:\tfuncion: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'\n");
					// Cerrar ambito
				};


fn_declaration: fn_complete_name '{' declaraciones_funcion
								{
									//declararFuncion(FILE * fd_s, char * nombre_funcion, int num_var_loc);
								};


fn_complete_name: fn_name '(' parametros_funcion ')'
									{
										
										//tablaSimbolosClasesAbrirAmbitoEnMain(tabla_clases, nombre_ambito, FUNCION, NINGUNO, tipo_basico, 0, 0, 0, NULL);

									};

fn_name: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR
				{
					num_parametro_actual = 0;
					pos_parametro_actual = 0;
					num_variable_local_actual = 0;
					pos_variable_local_actual = 0;
					strcpy($$.lexema,$4.lexema);
					tipo_retorno_actual = $3.tipo;
				};


tipo_retorno: TOK_NONE
							{
								$$.tipo = 0;
								fprintf(compilador_log, ";R:\ttipo_retorno: TOK_NONE\n");}
			| tipo
							{	$$.tipo = $1.tipo;
								fprintf(compilador_log, ";R:\ttipo_retorno: tipo\n");}
			| clase_objeto
							{	/* TODO propagar TIPO*/
								fprintf(compilador_log, ";R:\ttipo_retorno: clase_objeto\n");};


parametros_funcion: parametro_funcion resto_parametros_funcion {fprintf(compilador_log, ";R:\tparametros_funcion: parametro_funcion resto_parametros_funcion\n");}
				  | /*lambda*/ {fprintf(compilador_log, ";R:\tparametros_funcion: \n");};


resto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion {fprintf(compilador_log, ";R:\tresto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion\n");}
						| /*lambda*/ {fprintf(compilador_log, ";R:\tresto_parametros_funcion: \n");};


parametro_funcion: tipo idpf
									{
										/*Comprobamos que el identificador no existe ya
										if(){
											VAMOS A VER, COMO COMPRUEBO QUE NO EXISTE YA SI AUN NO HE
											ABIERTO EL AMBITO?? LO MIRO EN EL ARRAY??
										}*/

										for(i=0; i < num_parametro_actual; i++){

											if(strcmp($2.lexema, array_nombre_parametros[i]) == 0){
	    										fprintf(stderr, "**** Error semantico en [lin %d, col %d]. La funcion tiene dos parametros con el mismo nombre\n", row, col);
												return ERR;
											}
										}

										array_tipo_parametros[pos_parametro_actual] = $1.tipo;
										strcpy(array_nombre_parametros[pos_parametro_actual],$2.lexema);
										num_parametro_actual++;
										pos_parametro_actual++;
										fprintf(compilador_log, ";R:\tparametro_funcion: tipo TOK_IDENTIFICADOR\n");
									}
				 /* Creo que esta regla ya no hace falta*/
				 | clase_objeto idpf {fprintf(compilador_log, ";R:\tparametro_funcion: clase_objeto TOK_IDENTIFICADOR\n");};

idpf: TOK_IDENTIFICADOR
			{
				strcpy($$.lexema,$1.lexema);
			};


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
			{
				//TODO nombre ambito
				char nombre[100];
				char nombre_ambito_encontrado [100];
				HT_item* e;
				sprintf(nombre, "%s", $1.lexema);
				if(buscarIdNoCualificado(tabla_simbolos, nombre, "main", &e, nombre_ambito_encontrado) == ERR){
	    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se encuentra simbolo en asignacion\n", row, col);
						return ERR;}
	    		else if (HT_itemGetCategory(e) == FUNCION){
	    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se puede asignar una funcion\n", row, col);
						return ERR;
					}
	    		else if (HT_itemGetClass(e) == VECTOR){
	    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. La clase del simboo es vector\n", row, col);
						return ERR;
	    		}
	    		else if(HT_itemGetType(e) != $3.tipo){
	    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. Asignacion de tipos incompatibles\n", row, col);
						return ERR;
	    		}

	    		asignar(fout, $1.lexema, $3.direcciones);

			}
		  | elemento_vector '=' exp {fprintf(compilador_log, ";R:\tasignacion: elemento_vector '=' exp\n");}
		  | elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')' {fprintf(compilador_log, ";R:\tasignacion: elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
		  | TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')' {fprintf(compilador_log, ";R:\tasignacion: TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
		  | identificador_clase '.' TOK_IDENTIFICADOR '=' exp {fprintf(compilador_log, ";R:\tasignacion: identificador_clase '.' TOK_IDENTIFICADOR '=' exp\n");};


elemento_vector: TOK_IDENTIFICADOR '[' exp ']' {fprintf(compilador_log, ";R:\telemento_vector: TOK_IDENTIFICADOR '[' exp ']'\n");};


condicional: if_exp sentencias '}' 
			{

				$$.etiqueta = $1.etiqueta;
			 	ifthen_fin(fout, $$.etiqueta);

			}
		   | if_exp_sentencias TOK_ELSE '{' sentencias '}'
		    {

				/* Sólo se escribe la etiqueta del final de la estructura, no uses la variable global etiqueta que ya puede haber sido modificada
				   por sentencias, utiliza la propagada del primer símbolo $1.etiqueta , por ej. */

		    	$$.etiqueta = $1.etiqueta;
			 	ifthenelse_fin(fout, $$.etiqueta);

			};


if_exp_sentencias: if_exp sentencias '}'
				{
					/* Propagamos el valor de la etiqueta reservado por if_exp para que pueda usarlo la regla más externa*/
					$$.etiqueta = $1.etiqueta;

					/* Cuando esta regla se resuelve ya se han acabado las sentencias del if. Ponemos un salto al final del bloque condicional.
					Tambien es necesario escribir la etiqueta de fin de la rama then para saltar si la condición del if no se cumple. */
					ifthenelse_fin_then(fout, $$.etiqueta);
				};

if_exp: TOK_IF '(' exp ')' '{'
				{
					/* Si el tipo de la expresión $3.tipo no es BOOLEAN  salir con Error */
					if($3.tipo != BOOLEAN){
						fprintf(stderr, "****Error semantico en [lin %d, col %d]. Condición no booleana.\n", row, col);
						return ERR;
					}

					/* En este momento, en el que vamos a comenzar a escribir etiquetas para los saltos debemos reservar la nuestra (etiqueta++)
					y propagar su valor para que al reducir el conjunto de las 3 reglas del if-then-else siempre tengamos el valor de la etiqueta
					vinculada con esta estructura como atributo de alguno de los no terminales  */

					$$.etiqueta = etiqueta++;

					/* Da igual llamar a ifthenelse inicio o iftheninicio. hacne lo mismo */
					ifthenelse_inicio(fout, $3.direcciones, $$.etiqueta);
				};



bucle: while_exp '{' sentencias '}' {

		$$.etiqueta = $1.etiqueta;

		while_fin(fout, $$.etiqueta);

	};


while_exp:  while_ini '(' exp ')' {

				/* Si el tipo de la expresión $3.tipo no es BOOLEAN  salir con Error */
				if($3.tipo != BOOLEAN){
					fprintf(stderr, "****Error semantico en [lin %d, col %d]. Condición de bucle no booleana.\n", row, col);
					return ERR;
				}

				$$.etiqueta = $1.etiqueta;

				while_exp_pila(fout, $3.direcciones, $$.etiqueta);
}

while_ini: TOK_WHILE {

	$$.etiqueta = etiqueta++;

	/* Da igual llamar a ifthenelse inicio o iftheninicio. hance lo mismo */
	while_inicio(fout, $$.etiqueta);
}

lectura: TOK_SCANF TOK_IDENTIFICADOR
		{
			fprintf(compilador_log, ";R:\tlectura: TOK_SCANF TOK_IDENTIFICADOR\n");
			//TODO nombre ambito
			char nombre[100];
			char nombre_ambito_encontrado [100];
			HT_item* e;
			sprintf(nombre, "%s", $2.lexema);
			if(buscarIdNoCualificado(tabla_simbolos, nombre,"main", &e, nombre_ambito_encontrado) == ERR){
					 fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se encuentra simbolo para scanf.\n", row, col);
				 	 return ERR;
			}
			else if(HT_itemGetCategory(e) != VARIABLE){
				fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se puede aplicar scanf a algo que no sea una variable.\n", row, col);
				return ERR;
			}
			else if(HT_itemGetClass(e) != ESCALAR){
				fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se puede aplicar scanf a una variable no escalar.\n", row, col);
				return ERR;
			}
			leer(fout, $2.lexema, HT_itemGetType(e));
		}
	   | TOK_SCANF elemento_vector {fprintf(compilador_log, ";R:\tlectura: TOK_SCANF elemento_vector\n");};


escritura: TOK_PRINTF exp
		{
			fprintf(compilador_log, ";R:\tescritura: TOK_PRINTF exp\n");
			escribir(fout, $2.direcciones, $2.tipo);
		};


retorno_funcion: TOK_RETURN exp {fprintf(compilador_log, ";R:\tretorno_funcion: TOK_RETURN exp\n");}
			   | TOK_RETURN TOK_NONE {fprintf(compilador_log, ";R:\tretorno_funcion: TOK_RETURN TOK_NONE\n");};


exp: exp '+' exp
		{
			if (($1.tipo == BOOLEAN) || ($3.tipo == BOOLEAN)){
				fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se pueden sumar booleanos.\n", row, col);
				return ERR;
			}
			/*Sólo se puede generar código si se intenta sumar dos subexpresiones enteras*/
			if (($1.tipo == INT) && ($3.tipo == INT)){
				sumar(fout, $1.direcciones, $3.direcciones);
			    /* Propaga los atributos*/
			    $$.tipo = INT;
				$$.direcciones = 0;
			}
		}
   | exp '-' exp
   		{
			if (($1.tipo == BOOLEAN) || ($3.tipo == BOOLEAN)){
				fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se pueden restar booleanos.\n", row, col);
				return ERR;
			}
			if (($1.tipo == INT) && ($3.tipo == INT)){
				restar(fout, $1.direcciones, $3.direcciones);
			    /* Propaga los atributos*/
			    $$.tipo = INT;
				$$.direcciones = 0;
			}
		}
   | exp '/' exp
   		{
			if (($1.tipo == BOOLEAN) || ($3.tipo == BOOLEAN)){
				fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se pueden dividir booleanos.\n", row, col);
				return ERR;
			}
			if (($1.tipo == INT) && ($3.tipo == INT)){
				dividir(fout, $1.direcciones, $3.direcciones);
			    /* Propaga los atributos*/
			    $$.tipo = INT;
				$$.direcciones = 0;
			}
		}
   | exp '*' exp
   		{
			if (($1.tipo == BOOLEAN) || ($3.tipo == BOOLEAN)){
				fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se pueden multiplicar booleanos.\n", row, col);
				return ERR;
			}
			if (($1.tipo == INT) && ($3.tipo == INT)){
				multiplicar(fout, $1.direcciones, $3.direcciones);
			    /* Propaga los atributos*/
			    $$.tipo = INT;
				$$.direcciones = 0;
			}
		}
   | '-'  exp %prec NEG_UNARIA
   		{
			if (($2.tipo == BOOLEAN)){
				fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se puede negar aritmeticamente un booleano.\n", row, col);
				return ERR;
			}
			/*Sólo se puede generar código si se intenta sumar dos subexpresiones enteras*/
			if (($2.tipo == INT)){
				cambiar_signo(fout, $2.direcciones);
			    /* Propaga los atributos*/
			    $$.tipo = INT;
				$$.direcciones = 0;
			}
		}
   | exp TOK_AND exp
   		{
			if (($1.tipo == INT) || ($3.tipo == INT)){
				fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se puede hacer un AND sobre enteros.\n", row, col);
				return ERR;
			}
			if (($1.tipo == BOOLEAN) && ($3.tipo == BOOLEAN)){
				y(fout, $1.direcciones, $3.direcciones);
			    /* Propaga los atributos*/
			    $$.tipo = BOOLEAN;
				$$.direcciones = 0;
			}
		}
   | exp TOK_OR exp
   		{
			if (($1.tipo == INT) || ($3.tipo == INT)){
				fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se puede hacer un OR sobre enteros.\n", row, col);
				return ERR;
			}
			if (($1.tipo == BOOLEAN) && ($3.tipo == BOOLEAN)){
				o(fout, $1.direcciones, $3.direcciones);
			    /* Propaga los atributos*/
			    $$.tipo = BOOLEAN;
				$$.direcciones = 0;
			}
		}

   | '!' exp
   		{
			if (($2.tipo == INT)){
				fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se puede negar logicamente un entero.\n", row, col);
				return ERR;
			}
			/*Sólo se puede generar código si se intenta sumar dos subexpresiones enteras*/
			if (($2.tipo == BOOLEAN)){
				cuantos_no++;
				no(fout, $2.direcciones, cuantos_no);
			    /* Propaga los atributos*/
			    $$.tipo = BOOLEAN;
				$$.direcciones = 0;
			}
		}
   | TOK_IDENTIFICADOR
   		{
			//TODO conseguir nombre con ambito bien
			char nombre[100];
			char nombre_ambito_encontrado[100];
			HT_item* e = NULL;
			sprintf(nombre, "%s", $1.lexema);
			if(buscarIdNoCualificado(tabla_simbolos, nombre, "main", &e, nombre_ambito_encontrado) == ERR){
    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se encuentra simbolo.\n", row, col);
				return ERR;
			}
    		else if (HT_itemGetCategory(e) == FUNCION){
    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. El simbolo en asignacion es una funcion\n", row, col);
				return ERR;
			}
    		else if (HT_itemGetClass(e) == VECTOR){
    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. La clase del simboo es vector\n", row, col);
				return ERR;
    		}

    		$$.tipo = HT_itemGetType(e);
    		$$.direcciones = 1;
    		escribir_operando(fout, $1.lexema, 1);
    	}
   | constante
   		{
	   		$$.tipo = $1.tipo;
	   		$$.direcciones = $1.direcciones;
	   	}
   | '(' exp ')'
   		{
   			$$.tipo = $2.tipo;
	   		$$.direcciones = $2.direcciones;
   		}
   | '(' comparacion ')'
	 	{
			$$.tipo = $2.tipo;
			$$.direcciones = $2.direcciones;
		}
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


comparacion: exp TOK_IGUAL exp
				{
					/* Si alguna de las expresiones es booleana, salir con Error */
					if (($1.tipo == BOOLEAN) || ($3.tipo == BOOLEAN)){
						fprintf(stderr, "****Error sintactico en [lin %d, col %d]. No se pueden igualar booleanos.\n", row, col);
						return ERR;
					}

					/* Sólo hay que realizar acciones si ambas expresiones son enteras */
					if (($1.tipo == INT) && ($3.tipo == INT)){

						/*Incrementa el valor de etiqueta para reservarla*/
						etiqueta++;

						/* Genera código para la comparación */
						igual(fout, $1.direcciones, $3.direcciones, etiqueta);

						/* Ajusta la semántica
						   Propaga tipo y es dirección*/
						$$.tipo = BOOLEAN;
						$$.direcciones = 0;
					}
				}
		   | exp TOK_DISTINTO exp
		   		{
					/* Si alguna de las expresiones es booleana, salir con Error */
					if (($1.tipo == BOOLEAN) || ($3.tipo == BOOLEAN)){
						fprintf(stderr, "****Error sintactico en [lin %d, col %d]. No se pueden desigualar booleanos.\n", row, col);
						return ERR;
					}

					/* Sólo hay que realizar acciones si ambas expresiones son enteras */
					if (($1.tipo == INT) && ($3.tipo == INT)){

						/*Incrementa el valor de etiqueta para reservarla*/
						etiqueta++;

						/* Genera código para la comparación */
						distinto(fout, $1.direcciones, $3.direcciones, etiqueta);

						/* Ajusta la semántica
						   Propaga tipo y es dirección*/
						$$.tipo = BOOLEAN;
						$$.direcciones = 0;
					}
		   		}
		   | exp TOK_MENORIGUAL exp
		   		{
					/* Si alguna de las expresiones es booleana, salir con Error */
					if (($1.tipo == BOOLEAN) || ($3.tipo == BOOLEAN)){
						fprintf(stderr, "****Error sintactico en [lin %d, col %d]. No se puede <= booleanos.\n", row, col);
						return ERR;
					}

					/* Sólo hay que realizar acciones si ambas expresiones son enteras */
					if (($1.tipo == INT) && ($3.tipo == INT)){

						/*Incrementa el valor de etiqueta para reservarla*/
						etiqueta++;

						/* Genera código para la comparación */
						menor_igual(fout, $1.direcciones, $3.direcciones, etiqueta);

						/* Ajusta la semántica
						   Propaga tipo y es dirección*/
						$$.tipo = BOOLEAN;
						$$.direcciones = 0;
					}
		   		}
		   | exp TOK_MAYORIGUAL exp
		   		{
					/* Si alguna de las expresiones es booleana, salir con Error */
					if (($1.tipo == BOOLEAN) || ($3.tipo == BOOLEAN)){
						fprintf(stderr, "****Error sintactico en [lin %d, col %d]. No se pueden >= booleanos.\n", row, col);
						return ERR;
					}

					/* Sólo hay que realizar acciones si ambas expresiones son enteras */
					if (($1.tipo == INT) && ($3.tipo == INT)){

						/*Incrementa el valor de etiqueta para reservarla*/
						etiqueta++;

						/* Genera código para la comparación */
						mayor_igual(fout, $1.direcciones, $3.direcciones, etiqueta);

						/* Ajusta la semántica
						   Propaga tipo y es dirección*/
						$$.tipo = BOOLEAN;
						$$.direcciones = 0;
					}
		   		}
		   | exp '<' exp
		   		{
					/* Si alguna de las expresiones es booleana, salir con Error */
					if (($1.tipo == BOOLEAN) || ($3.tipo == BOOLEAN)){
						fprintf(stderr, "****Error sintactico en [lin %d, col %d]. No se puede < booleanos.\n", row, col);
						return ERR;
					}

					/* Sólo hay que realizar acciones si ambas expresiones son enteras */
					if (($1.tipo == INT) && ($3.tipo == INT)){

						/*Incrementa el valor de etiqueta para reservarla*/
						etiqueta++;

						/* Genera código para la comparación */
						menor(fout, $1.direcciones, $3.direcciones, etiqueta);

						/* Ajusta la semántica
						   Propaga tipo y es dirección*/
						$$.tipo = BOOLEAN;
						$$.direcciones = 0;
					}
		   		}
		   | exp '>' exp {
					/* Si alguna de las expresiones es booleana, salir con Error */
					if (($1.tipo == BOOLEAN) || ($3.tipo == BOOLEAN)){
						fprintf(stderr, "****Error sintactico en [lin %d, col %d]. No se puede > booleanos.\n", row, col);
						return ERR;
					}

					/* Sólo hay que realizar acciones si ambas expresiones son enteras */
					if (($1.tipo == INT) && ($3.tipo == INT)){

						/*Incrementa el valor de etiqueta para reservarla*/
						etiqueta++;

						/* Genera código para la comparación */
						mayor(fout, $1.direcciones, $3.direcciones, etiqueta);

						/* Ajusta la semántica
						   Propaga tipo y es dirección*/
						$$.tipo = BOOLEAN;
						$$.direcciones = 0;
					}
		   		};


constante: constante_logica
			{
				$$.tipo = $1.tipo;
		 		$$.direcciones = $1.direcciones;
			}
		 | constante_entera
		 	{
		 		$$.tipo = $1.tipo;
		 		$$.direcciones = $1.direcciones;
		 	};


constante_logica: TOK_TRUE
					{
						$$.tipo = BOOLEAN;
						$$.direcciones = 0 ;
						$$.valor_entero = 1;
						char aux[10];
						sprintf(aux, "%d", $$.valor_entero);
						escribir_operando(fout, aux, 0);
					}

				| TOK_FALSE
					{
						$$.tipo = BOOLEAN;
						$$.direcciones = 0 ;
						$$.valor_entero = 0;
						char aux[10];
						sprintf(aux, "%d", $$.valor_entero);
						escribir_operando(fout, aux, 0);
					};


constante_entera: TOK_CONSTANTE_ENTERA
				{
					$$.tipo=INT;
					$$.direcciones = 0 ;
					$$.valor_entero = $1.valor_entero;
					char aux[10];
					sprintf(aux, "%d", $1.valor_entero);
					escribir_operando(fout, aux, 0);
				};

escritura_cabeceras_datos: /*lambda*/
	{
		escribir_subseccion_data(fout);
		escribir_cabecera_bss(fout);
	};


escritura_main: /*lambda*/
	{
  		escribir_segmento_codigo(fout);
		escribir_inicio_main(fout);
	};

escritura_fin: /*lambda*/
	{
		escribir_fin(fout);
	};


%%


int yyerror (const char *s)
{
	if(error_flag == 0){
    	fprintf(stderr, "****Error sintactico en [lin %d, col %d]\n", row, col);
    }
    error_flag = 0;
    return 0;
}
