%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "omicron.h"
	#include "generacion.h"
	#include "graph.h"

	/* Del main*/
	extern FILE* yyin;

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

	/*Etiqueta para comprobar que la función tiene retorno*/
	int hay_retorno_funcion_actual;

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
	int num_parametros_llamada_actual;

	int tipo_retorno_actual;

	int en_explist;

	/*Array para almacenar tipos de parametros función*/
	int array_tipo_parametros[255];
	/* Array para almacenar nombres de parametros función*/
	char array_nombre_parametros[255][MAX_LONG_ID+1];

	char nombre_ambito_actual[255];

	/*Variables auxiliares para codigo*/
	int i; /*Bucles*/
	char nombre_parametro[MAX_LONG_ID + 3];
	char nombre_funcion[255];
	int param_or_variable = 0;


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
%type <atributos> idf_llamada_funcion
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
%type <atributos> escritura_segmento_texto

%left '+' '-' TOK_OR
%left '*' '/' TOK_AND
%right NEG_UNARIA '!'

/*Axioma*/
%start programa


%% /*Seccion de reglas*/

programa: inicioTabla TOK_MAIN '{' escritura_cabeceras_datos  declaraciones escritura_segmento_texto  funciones escritura_main sentencias '}' escritura_fin { }
		| inicioTabla TOK_MAIN '{' escritura_cabeceras_datos escritura_segmento_texto funciones escritura_main sentencias '}' { } ;

inicioTabla:
	{
		iniciarTablaSimbolosClases(&tabla_simbolos, "Tablasimbolos");
		strcpy(nombre_ambito_actual, "main");
	}

declaraciones:  declaracion {}
			 |  declaracion declaraciones {};


declaracion: modificadores_acceso clase identificadores ';'
			{}
 		   | modificadores_acceso declaracion_clase ';'  {};

modificadores_acceso: TOK_HIDDEN TOK_UNIQUE {}
					| TOK_SECRET TOK_UNIQUE {}
					| TOK_EXPOSED TOK_UNIQUE {}
					| TOK_HIDDEN {}
					| TOK_SECRET {}
					| TOK_EXPOSED {}
					| TOK_UNIQUE {}
					| /*lambda*/{};

clase: clase_escalar
		{
		  clase_actual=ESCALAR;	}
	 | clase_vector
	 	{
	 	  clase_actual = VECTOR; }
	 | clase_objeto
	 	{
	   	  clase_actual = OBJETO; };


declaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR TOK_INHERITS identificadores '{' declaraciones funciones '}' {}
				 | modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}' {};


modificadores_clase: /*lambda*/ {};


clase_escalar: tipo
				{
				  tamanio_vector_actual = 1;};


tipo: TOK_INT
		{

			$$.tipo = INT;
			tipo_actual = INT;
	    }
	| TOK_BOOLEAN
		{

			$$.tipo = BOOLEAN;
			tipo_actual = BOOLEAN;
		};


clase_objeto: '{' TOK_IDENTIFICADOR '}' {};


clase_vector: TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']'
				{
					tamanio_vector_actual = $4.valor_entero;
					if ((tamanio_vector_actual < 1) || (tamanio_vector_actual > MAX_TAMANIO_VECTOR)){
						fprintf(stderr, "Error, tamaño de vector no válido. Linea %d columna %d", row, col);
						return ERR;
					}

				};


identificadores: identificador {}
			   | identificador ',' identificadores {};


identificador: TOK_IDENTIFICADOR
				{
					HT_item *e;
					char nombre [100];
					int aux;
					if (strcmp(nombre_ambito_actual, "main") == 0){

						sprintf(nombre, "main_%s", $1.lexema);
						if(buscarParaDeclararIdTablaSimbolosAmbitos(tabla_simbolos, nombre, &e, "main") == OK){
							fprintf(stderr, "Identificador %s duplicado. Linea %d columna %d\n", $1.lexema, row, col);
							return ERR;
						}

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
					/* Estamos dentro de una función*/
					else{
						sprintf(nombre, "%s_%s",nombre_ambito_actual, $1.lexema);
						/*num_variable local empieza en 1*/
						num_variable_local_actual++;

						if(buscarParaDeclararIdTablaSimbolosAmbitos(tabla_simbolos, nombre, &e, "main") == OK){
							fprintf(stderr, "Identificador %s duplicado. Linea %d columna %d\n", $1.lexema, row, col);
							return ERR;
						}
						aux = insertarTablaSimbolosMain(tabla_simbolos, VARIABLE,
							nombre,         clase_actual,
							tipo_actual,	  0,
							0,      		  num_variable_local_actual,
							0,              tamanio_vector_actual,
							ACCESO_TODOS,        MIEMBRO_NO_UNICO,
							0,              0,
							NULL);
					}
				}

funciones: funcion funciones {}
		 | /*lambda*/ {};


funcion: fn_declaration sentencias '}'
				{
					/*Cerramos ámbito*/
					tablaSimbolosClasesCerrarAmbitoEnMain(tabla_simbolos);
					strcpy(nombre_ambito_actual,"main");
					if (hay_retorno_funcion_actual == 0){
						fprintf(stderr, "**** Error semantico en [lin %d, col %d]. La funcion no tiene sentencia de retorno.\n", row, col);
						return ERR;
					}
					hay_retorno_funcion_actual = 0;
				};


fn_declaration: fn_complete_name '{' declaraciones_funcion
								{
									declararFuncion(fout, $1.lexema, num_parametro_actual);
								};


fn_complete_name: fn_name '(' parametros_funcion ')'
									{
										char auxNombreFuncion[100];
										HT_item *e;
										int i;
										sprintf(nombre_funcion, "main_%s", $1.lexema);
										/*Añadimos los parametros al nombre de la funcion*/
										for (i = 0 ; i < num_parametro_actual ; i++ ){
											sprintf(auxNombreFuncion, "@%d", array_tipo_parametros[i]);
											strcat(nombre_funcion, auxNombreFuncion);
										}
										/*El nombre del lexema será el completo*/
										strcpy($$.lexema,nombre_funcion);
										/*Guardamos el ámbito*/
										sprintf(nombre_ambito_actual, "%s", strtok(nombre_funcion, "main_"));
										if(buscarParaDeclararIdTablaSimbolosAmbitos(tabla_simbolos, nombre_funcion, &e, "main") == ERR){
											tablaSimbolosClasesAbrirAmbitoEnMain(tabla_simbolos,
																											nombre_funcion,
																											FUNCION,
																											NINGUNO,
																											tipo_retorno_actual,
																											0,
																											0,
																											num_parametro_actual,
																											array_tipo_parametros);

											/*Ahora declaramos todos los parametros*/
											for(i = 0 ; i < num_parametro_actual ; i++){
												sprintf(nombre_funcion, "%s_%s", nombre_ambito_actual,array_nombre_parametros[i]);
												if(buscarParaDeclararIdTablaSimbolosAmbitos(tabla_simbolos, nombre_funcion, &e, "main") == ERR){
													insertarTablaSimbolosMain(tabla_simbolos, VARIABLE,
																				nombre_funcion,         ESCALAR,
																				array_tipo_parametros[i],	  0,
																				num_parametro_actual,      		  0,
																				i,              tamanio_vector_actual,
																				ACCESO_TODOS,        MIEMBRO_NO_UNICO,
																				0,              0,
																				NULL);
												}
												else{
													fprintf(stderr, "Parámetro de la función no válido. Linea %d columna %d\n", row, col);
													return ERR;
												}

											}
										}
										else{
											fprintf(stderr, "Ya existe esta función. Linea %d columna %d\n", row, col);
											return ERR;
										}


										//tablaSimbolosClasesAbrirAmbitoEnMain(tabla_clases, nombre_ambito, FUNCION, NINGUNO, tipo_basico, 0, 0, 0, NULL);

									};

fn_name: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR
				{
					hay_retorno_funcion_actual = 0;
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
								}
			| tipo
							{	$$.tipo = $1.tipo;
								}
			| clase_objeto
							{};


parametros_funcion: parametro_funcion resto_parametros_funcion {}
				  | /*lambda*/ {};


resto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion {}
						| /*lambda*/ {};


parametro_funcion: tipo idpf
									{

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

									}
				 /* Creo que esta regla ya no hace falta*/
				 | clase_objeto idpf {};

idpf: TOK_IDENTIFICADOR
			{
				strcpy($$.lexema,$1.lexema);
			};


declaraciones_funcion: declaraciones {}
					 | /*lambda*/ {};


sentencias: sentencia {}
		  | sentencia sentencias {};


sentencia: sentencia_simple ';' {}
		 | bloque {};


sentencia_simple: asignacion {}
				| escritura {}
				| lectura {}
				| retorno_funcion
				| identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')' {}
				| TOK_IDENTIFICADOR '(' lista_expresiones ')' {}
				| destruir_objeto {};


destruir_objeto: TOK_DISCARD TOK_IDENTIFICADOR {};


bloque: condicional {}
	  | bucle {};


asignacion: TOK_IDENTIFICADOR '=' exp
			{
				char nombre[100];
				char nombre_ambito_encontrado [100];
				HT_item* e;
				sprintf(nombre, "%s", $1.lexema);

				if(buscarIdNoCualificado(tabla_simbolos, nombre, "main", &e, nombre_ambito_encontrado) == ERR){
	    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se encuentra simbolo en asignacion\n", row, col);
					return ERR;
				}
	    		else if (HT_itemGetCategory(e) == FUNCION){
	    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se puede asignar una funcion\n", row, col);
					return ERR;
				}
	    		else if (HT_itemGetClass(e) == VECTOR){
	    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. La clase del simbolo es vector\n", row, col);
					return ERR;
	    		}
	    		else if(HT_itemGetType(e) != $3.tipo){
	    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. Asignacion de tipos incompatibles\n", row, col);
					return ERR;
	    		}

	    		if (strcmp(nombre_ambito_encontrado, "main") == 0)
	    			asignar(fout, $1.lexema, $3.direcciones);
	    		else {

						escribirVariableLocal(fout, HT_itemGetPosicionVariableLocal(e));
						asignarDestinoEnPila(fout, $3.direcciones);
	    		}

			}
		  | elemento_vector '=' exp
		    {
		    	if ($1.tipo != $3.tipo){
					fprintf(stderr, "****Error semantico en [lin %d, col %d]. Asignacion de tipos incompatibles\n", row, col);
					return ERR;
				}

				asignar_a_elemento_vector(fout, $3.direcciones);

		    }
		  | elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')' {}
		  | TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')' {}
		  | identificador_clase '.' TOK_IDENTIFICADOR '=' exp {};


elemento_vector: TOK_IDENTIFICADOR '[' exp ']'
		{


			char nombre[100];
			char nombre_ambito_encontrado [100];
			HT_item* e;
			sprintf(nombre, "%s", $1.lexema);
			if(buscarIdNoCualificado(tabla_simbolos, nombre, "main", &e, nombre_ambito_encontrado) == ERR){
    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. Vector no declarado\n", row, col);
				return ERR;}
    		else if (HT_itemGetCategory(e) == FUNCION){
    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. Indexacion vectorial sobre funcion\n", row, col);
				return ERR;
			}
    		else if (HT_itemGetClass(e) == ESCALAR){
    			fprintf(stderr, "****Error semantico en [lin %d, col %d]. Indexacion vectorial sobre escalar\n", row, col);
				return ERR;
    		}
    		else if (HT_itemGetClass(e) != VECTOR){
				fprintf(stderr, "****Error semantico en [lin %d, col %d]. Indexacion vectorial sobre algo que no es un vector\n", row, col);
				return ERR;
    		}

			if($3.tipo != INT){
				fprintf(stderr, "****Error semantico en [lin %d, col %d]. Para indexar un vector se debe usar un INT \n", row, col);
				return ERR;
			}

			$$.tipo = HT_itemGetType(e);
			$$.direcciones = 1;

			escribir_elemento_vector(fout, $1.lexema, HT_itemGetTamanio(e), $3.direcciones);

		};


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
	   | TOK_SCANF elemento_vector
	   {
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
			else if(HT_itemGetClass(e) != VECTOR){
				fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se puede aplicar scanf a una variable no escalar.\n", row, col);
				return ERR;
			}
			leer(fout, $2.lexema, HT_itemGetType(e));

	   };


escritura: TOK_PRINTF exp
		{
			escribir(fout, $2.direcciones, $2.tipo);
		};


retorno_funcion: TOK_RETURN exp
								{
									hay_retorno_funcion_actual = 1;
									retornarFuncion(fout, $2.direcciones);
								}
			   | TOK_RETURN TOK_NONE {};


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
    		fprintf(stderr, "****Error semantico en [lin %d, col %d]. La clase del simbolo es vector\n", row, col);
				return ERR;
    	}

  		$$.tipo = HT_itemGetType(e);
  		$$.direcciones = 1;
			param_or_variable = 1;
			for (i = 0; i < num_parametro_actual ; i++){
				if (strcmp(array_nombre_parametros[i], $1.lexema) == 0){
					escribirParametro(fout, i, num_parametro_actual);
					param_or_variable = 0;
				}
			}

			if(param_or_variable == 1){
				/*Caso en el que asignamos una variable local*/
				if (strcmp(nombre_ambito_encontrado, "main") == 0)
					escribir_operando(fout, $1.lexema, 1);
				else {
					/* Variable de funcion*/
					escribirVariableLocal(fout, HT_itemGetPosicionVariableLocal(e));
				}
			}

			param_or_variable = 0;

			/*Caso cuando estamos reduciendo en la llamada de función*/
			if (en_explist == 1){
				operandoEnPilaAArgumento(fout, 1);
			}
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
   | elemento_vector
   		{
				$$.tipo = $1.tipo;
				$$.direcciones = $1.direcciones;
   		}
   | idf_llamada_funcion '(' lista_expresiones ')'
	 		{
				en_explist = 0;
				HT_item* e;
				char auxNombreFuncion[100];
				char nombre_ambito_encontrado [100];
				sprintf(nombre_funcion, "%s", $1.lexema);
				/*Añadimos los parametros al nombre de la funcion*/
				for (i = 0 ; i < num_parametros_llamada_actual ; i++ ){
					sprintf(auxNombreFuncion, "@%d", array_tipo_parametros[i]);
					strcat(nombre_funcion, auxNombreFuncion);
				}
				if(buscarIdNoCualificado(tabla_simbolos, nombre_funcion, "main", &e, nombre_ambito_encontrado) == ERR){
	    		fprintf(stderr, "****Error semantico en [lin %d, col %d]. No se encuentra la función.\n", row, col);
					return ERR;
				}

				/*Comprobamos que sea función*/
				if (HT_itemGetCategory(e) != FUNCION){
					fprintf(stderr, "****Error semantico en [lin %d, col %d]. No es un nombre de función.\n", row, col);
					return ERR;
				}

				$$.tipo = HT_itemGetType(e);
				/*Cogemos un valor, no una dirección*/
				sprintf(auxNombreFuncion, "main_%s", nombre_funcion);
				/*Generamos el código NASM */
				llamarFuncion(fout, auxNombreFuncion, num_parametros_llamada_actual);

			}
   | identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')' {}
   | identificador_clase '.' TOK_IDENTIFICADOR {};

idf_llamada_funcion : TOK_IDENTIFICADOR
											{
												if (en_explist ==  1){
													fprintf(stderr, "Error en [lin %d, col %d]. No se permite llamadas a funciones dentro de los parámetros.\n", row, col);
													return ERR;
												}
												en_explist = 1;
												num_parametros_llamada_actual = 0;
												strcpy($$.lexema, $1.lexema);
											};

identificador_clase: TOK_IDENTIFICADOR {}
				   | TOK_ITSELF {};


lista_expresiones: exp resto_lista_expresiones
									{
										array_tipo_parametros[num_parametros_llamada_actual] = $1.tipo;

										num_parametros_llamada_actual++;

										}
				 | /*lambda*/ {};


resto_lista_expresiones: ',' exp resto_lista_expresiones
												{
													array_tipo_parametros[num_parametros_llamada_actual] = $2.tipo;
													num_parametros_llamada_actual++;
												}
					   | /*lambda*/ {};


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
		escribir_inicio_main(fout);
	};

escritura_segmento_texto: /*lambda*/
	{
		escribir_segmento_codigo(fout);
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
