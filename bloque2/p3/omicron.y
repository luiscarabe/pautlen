%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "lex.yy.c"

	/* En main*/
	extern FILE* fout;

	/* En fichero especificacion Flex*/
	extern int yylex(void);
	extern int row;
	extern int col;
	extern error_flag;

	int yyerror (const char *s);

%}

%union
{
  int numero;
  /*TODO: Memoria dinamica*/
  char cadena[1000];
}


/* PALABRAS RESERVADAS */
%token TOK_NONE
%token TOK_CLASS
%token TOK_INHERITS
%token TOK_INSTANCE_OF
%token TOK_DISCARD
%token TOK_ITSELF
%token TOK_FLECHA
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
/* ERRORES */
%token TOK_ERROR

%left '+' '-' TOK_OR
%left '*' '/' TOK_AND
%right NEG_UNARIA '!'

/*Axioma*/
%start programa


%% /*Seccion de reglas*/

programa: TOK_MAIN '{' declaraciones funciones sentencias '}' { fprintf(fout, ";R:\tprograma: TOK_MAIN '{' declaraciones funciones sentencias '}'\n");}
		| TOK_MAIN '{' funciones sentencias '}' { fprintf(fout, ";R:\tprograma: TOK_MAIN '{' funciones sentencias '}'\n");} ;


declaraciones: declaracion {fprintf(fout, ";R:\tdeclaraciones: declaracion\n");}
			 | declaracion declaraciones {fprintf(fout, ";R:\tdeclaraciones: declaracion declaraciones\n");};


declaracion: modificadores_acceso clase identificadores ';' {fprintf(fout, ";R:\tdeclaracion: modificadores_acceso clase identificadores ';'\n");}
 		   | modificadores_acceso declaracion_clase ';'  {fprintf(fout, ";R:\tdeclaracion: modificadores_acceso declaracion_clase ';'\n");};


modificadores_acceso: TOK_HIDDEN TOK_UNIQUE {fprintf(fout, ";R:\tmodificadores_acceso: TOK_HIDDEN TOK_UNIQUE\n");}
					| TOK_SECRET TOK_UNIQUE {fprintf(fout, ";R:\tmodificadores_acceso: TOK_SECRET TOK_UNIQUE\n");}
					| TOK_EXPOSED TOK_UNIQUE {fprintf(fout, ";R:\tmodificadores_acceso: TOK_EXPOSED TOK_UNIQUE\n");}
					| TOK_HIDDEN {fprintf(fout, ";R:\tmodificadores_acceso: TOK_HIDDEN\n");}
					| TOK_SECRET {fprintf(fout, ";R:\tmodificadores_acceso: TOK_SECRET\n");}
					| TOK_EXPOSED {fprintf(fout, ";R:\tmodificadores_acceso: TOK_EXPOSED\n");}
					| TOK_UNIQUE {fprintf(fout, ";R:\tmodificadores_acceso: TOK_UNIQUE\n");}
					| /*lambda*/{fprintf(fout, ";R:\tmodificadores_acceso: \n");};

clase: clase_escalar {fprintf(fout, ";R:\tclase: clase_escalar\n");}
	 | clase_vector {fprintf(fout, ";R:\tclase: clase_vector\n");}
	 | clase_objeto {fprintf(fout, ";R:\tclase: clase_objeto\n");};


declaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR TOK_INHERITS identificadores '{' declaraciones funciones '}' {fprintf(fout, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR TOK_INHERITS identificadores '{' declaraciones funciones '}'\n");}
				 | modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}' {fprintf(fout, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}'\n");};


modificadores_clase: /*lambda*/ {fprintf(fout, ";R:\tmodificadores_clase: \n");};


clase_escalar: tipo {fprintf(fout, ";R:\tclase_escalar: tipo\n");};


tipo: TOK_INT {fprintf(fout, ";R:\ttipo: TOK_INT\n");}
	| TOK_BOOLEAN {fprintf(fout, ";R:\ttipo: TOK_BOOLEAN\n");};


clase_objeto: '{' TOK_IDENTIFICADOR '}' {fprintf(fout, ";R:\tclase_objeto: '{' TOK_IDENTIFICADOR '}'\n");};


clase_vector: TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']' {fprintf(fout, ";R:\tclase_vector: TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']'\n");};


identificadores: TOK_IDENTIFICADOR {fprintf(fout, ";R:\tidentificadores: TOK_IDENTIFICADOR\n");}
			   | TOK_IDENTIFICADOR ',' identificadores {fprintf(fout, ";R:\tidentificadores: TOK_IDENTIFICADOR ',' identificadores\n");};


funciones: funcion funciones {fprintf(fout, ";R:\tfunciones: funcion funciones\n");}
		 | /*lambda*/ {fprintf(fout, ";R:\tfunciones: \n");};


funcion: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{'
		 declaraciones_funcion sentencias '}' {fprintf(fout, ";R:\tfuncion: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'\n");};


tipo_retorno: TOK_NONE {fprintf(fout, ";R:\ttipo_retorno: TOK_NONE\n");}
			| tipo {fprintf(fout, ";R:\ttipo_retorno: tipo\n");}
			| clase_objeto {fprintf(fout, ";R:\ttipo_retorno: clase_objeto\n");};


parametros_funcion: parametro_funcion resto_parametros_funcion {fprintf(fout, ";R:\tparametros_funcion: parametro_funcion resto_parametros_funcion\n");}
				  | /*lambda*/ {fprintf(fout, ";R:\tparametros_funcion: \n");};


resto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion {fprintf(fout, ";R:\tresto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion\n");}
						| /*lambda*/ {fprintf(fout, ";R:\tresto_parametros_funcion: \n");};


parametro_funcion: tipo TOK_IDENTIFICADOR {fprintf(fout, ";R:\tparametro_funcion: tipo TOK_IDENTIFICADOR\n");}
				 | clase_objeto TOK_IDENTIFICADOR {fprintf(fout, ";R:\tparametro_funcion: clase_objeto TOK_IDENTIFICADOR\n");};


declaraciones_funcion: declaraciones {fprintf(fout, ";R:\tdeclaraciones_funcion: declaraciones\n");}
					 | /*lambda*/ {fprintf(fout, ";R:\tdeclaraciones_funcion: \n");};


sentencias: sentencia {fprintf(fout, ";R:\tsentencias: sentencia\n");}
		  | sentencia sentencias {fprintf(fout, ";R:\tsentencias: sentencia sentencias\n");};


sentencia: sentencia_simple ';' {fprintf(fout, ";R:\tsentencia: sentencia_simple ';'\n");}
		 | bloque {fprintf(fout, ";R:\tsentencia: bloque\n");};


sentencia_simple: asignacion {fprintf(fout, ";R:\tsentencia_simple: asignacion\n");}
				| escritura {fprintf(fout, ";R:\tsentencia_simple: escritura\n");}
				| lectura {fprintf(fout, ";R:\tsentencia_simple: lectura\n");}
				| retorno_funcion {fprintf(fout, ";R:\tsentencia_simple: retorno_funcion\n");}
				| identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')' {fprintf(fout, ";R:\tsentencia_simple: identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
				| TOK_IDENTIFICADOR '(' lista_expresiones ')' {fprintf(fout, ";R:\tsentencia_simple: TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
				| destruir_objeto {fprintf(fout, ";R:\tsentencia_simple: destruir_objeto\n");};


destruir_objeto: TOK_DISCARD TOK_IDENTIFICADOR {fprintf(fout, ";R:\tdestruir_objeto: TOK_DISCARD TOK_IDENTIFICADOR\n");};


bloque: condicional {fprintf(fout, ";R:\tbloque: condicional\n");}
	  | bucle {fprintf(fout, ";R:\tbloque: bucle\n");};


asignacion: TOK_IDENTIFICADOR '=' exp {fprintf(fout, ";R:\tasignacion: TOK_IDENTIFICADOR '=' exp\n");}
		  | elemento_vector '=' exp {fprintf(fout, ";R:\tasignacion: elemento_vector '=' exp\n");}
		  | elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')' {fprintf(fout, ";R:\tasignacion: elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
		  | TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')' {fprintf(fout, ";R:\tasignacion: TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
		  | identificador_clase '.' TOK_IDENTIFICADOR '=' exp {fprintf(fout, ";R:\tasignacion: identificador_clase '.' TOK_IDENTIFICADOR '=' exp\n");};


elemento_vector: TOK_IDENTIFICADOR '[' exp ']' {fprintf(fout, ";R:\telemento_vector: TOK_IDENTIFICADOR '[' exp ']'\n");};


condicional: TOK_IF '(' exp ')' '{' sentencias '}' {fprintf(fout, ";R:\tcondicional: TOK_IF '(' exp ')' '{' sentencias '}'\n");}
		   | TOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}' {fprintf(fout, ";R:\tcondicional: TOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}'\n");};


bucle: TOK_WHILE '(' exp ')' '{' sentencias '}' {fprintf(fout, ";R:\tdbucle: TOK_WHILE '(' exp ')' '{' sentencias '}'\n");};


lectura: TOK_SCANF TOK_IDENTIFICADOR {fprintf(fout, ";R:\tlectura: TOK_SCANF TOK_IDENTIFICADOR\n");}
	   | TOK_SCANF elemento_vector {fprintf(fout, ";R:\tlectura: TOK_SCANF elemento_vector\n");};


escritura: TOK_PRINTF exp {fprintf(fout, ";R:\tescritura: TOK_PRINTF exp\n");};


retorno_funcion: TOK_RETURN exp {fprintf(fout, ";R:\tretorno_funcion: TOK_RETURN exp\n");}
			   | TOK_RETURN TOK_NONE {fprintf(fout, ";R:\tretorno_funcion: TOK_RETURN TOK_NONE\n");};


exp: exp '+' exp {fprintf(fout, ";R:\texp: exp '+' exp\n");}
   | exp '-' exp {fprintf(fout, ";R:\texp: exp '-' exp\n");}
   | exp '/' exp {fprintf(fout, ";R:\texp: exp '/' exp\n");}
   | exp '*' exp {fprintf(fout, ";R:\texp: exp '*' exp\n");}
   | '-'  exp %prec NEG_UNARIA {fprintf(fout, ";R:\texp: '-' exp\n");}
   | exp TOK_AND exp {fprintf(fout, ";R:\texp: exp TOK_AND exp\n");}
   | exp TOK_OR exp {fprintf(fout, ";R:\texp: exp TOK_OR exp\n");}
   | '!' exp {fprintf(fout, ";R:\texp: '!' exp\n");}
   | TOK_IDENTIFICADOR {fprintf(fout, ";R:\texp: TOK_IDENTIFICADOR\n");}
   | constante {fprintf(fout, ";R:\texp: constante\n");}
   | '(' exp ')' {fprintf(fout, ";R:\texp: '(' exp ')'\n");}
   | '(' comparacion ')' {fprintf(fout, ";R:\texp: '(' comparacion ')'\n");}
   | elemento_vector {fprintf(fout, ";R:\texp: elemento_vector\n");}
   | TOK_IDENTIFICADOR '(' lista_expresiones ')' {fprintf(fout, ";R:\texp: TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
   | identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')' {fprintf(fout, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
   | identificador_clase '.' TOK_IDENTIFICADOR {fprintf(fout, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR\n");};


identificador_clase: TOK_IDENTIFICADOR {fprintf(fout, ";R:\tidentificador_clase: TOK_IDENTIFICADOR\n");}
				   | TOK_ITSELF {fprintf(fout, ";R:\tidentificador_clase: TOK_ITSELF\n");};


lista_expresiones: exp resto_lista_expresiones {fprintf(fout, ";R:\tlista_expresiones: exp resto_lista_expresiones\n");}
				 | /*lambda*/ {fprintf(fout, ";R:\tlista_expresiones: \n");};


resto_lista_expresiones: ',' exp resto_lista_expresiones {fprintf(fout, ";R:\tresto_lista_expresiones: ',' exp resto_lista_expresiones\n");}
					   | /*lambda*/ {fprintf(fout, ";R:\tresto_lista_expresiones: \n");};


comparacion: exp TOK_IGUAL exp {fprintf(fout, ";R:\tcomparacion: exp TOK_IGUAL exp\n");}
		   | exp TOK_DISTINTO exp {fprintf(fout, ";R:\tcomparacion: exp TOK_DISTINTO exp\n");}
		   | exp TOK_MENORIGUAL exp {fprintf(fout, ";R:\tcomparacion: exp TOK_MENORIGUAL exp\n");}
		   | exp TOK_MAYORIGUAL exp {fprintf(fout, ";R:\tcomparacion: exp TOK_MAYORIGUAL exp\n");}
		   | exp '<' exp {fprintf(fout, ";R:\tcomparacion: exp '<' exp\n");}
		   | exp '>' exp {fprintf(fout, ";R:\tcomparacion: exp '>' exp\n");};


constante: constante_logica {fprintf(fout, ";R:\tconstante: constante_logica\n");}
		 | constante_entera {fprintf(fout, ";R:\tconstante: constante_entera\n");};


constante_logica: TOK_TRUE {fprintf(fout, ";R:\tconstante_logica: TOK_TRUE\n");}
				| TOK_FALSE {fprintf(fout, ";R:\tconstante_logica: TOK_FALSE\n");};


constante_entera: TOK_CONSTANTE_ENTERA {fprintf(fout, ";R:\tconstante_entera: TOK_CONSTANTE_ENTERA\n");};


//numero: TOK_CONSTANTE_ENTERA {fprintf(fout, ";R:\tdeclaraciones_funcion: \n");}
	  //| numero digito;



// Creo que esto esta mejor en el TOK IDENTIFICADOR (lo veo mas morfo)
/*identificador: letra
			 | letra cola_identificador;


cola_identificador: alfanumerico
				  | alfanumerico cola_identificador;*/


/*alfanumerico: letra
			| digito;


letra: [a-zA-z];

digito: [0-9];*/


%%


int yyerror (const char *s)
{
	if(error_flag == 0){
    	fprintf(stderr, "****Error sintactico en [lin %d, col %d]\n", row, col);
    }
    return 0;
}
