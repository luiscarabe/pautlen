%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "lex.yy.c"

	extern int yylex(void);
	int yyerror (const char *s);
	FILE* fout;

%}

%union
{
  int numero;
  /*TODO: Memoria dinamica*/
  char* cadena;
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





%left '+' '-'
%left '*' '/'
%right NEG_UNARIA '!'

/*Axioma*/
%start programa


%% /*Seccion de reglas*/

programa: TOK_MAIN '{' funciones declaraciones funciones sentencias '}' { fprintf(fout, ";R: hola");}
		| TOK_MAIN '{' declaraciones funciones sentencias '}' { fprintf(fout, ";R: hola");}
		| TOK_MAIN '{' funciones sentencias '}'  ;


declaraciones: declaracion {fprintf(fout, ";R: hola3");}
			 | declaracion declaraciones {fprintf(fout, ";R: hola2");};


declaracion: modificadores_acceso clase identificadores ';' {fprintf(fout, ";R: holaladedeu");} 
 		   | modificadores_acceso declaracion_clase ';'  {fprintf(fout, ";R: hola8000");};


modificadores_acceso: TOK_HIDDEN TOK_UNIQUE 
					| TOK_SECRET TOK_UNIQUE
					| TOK_EXPOSED TOK_UNIQUE
					| TOK_HIDDEN
					| TOK_SECRET
					| TOK_EXPOSED
					| TOK_UNIQUE
					| /*lambda*/;

clase: clase_escalar
	 | clase_vector
	 | clase_objeto;


declaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR TOK_INHERITS identificadores '{' declaraciones funciones '}'
				 | modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}';


modificadores_clase: /*lambda*/;


clase_escalar: tipo;


tipo: TOK_INT
	| TOK_BOOLEAN;


clase_objeto: '{' TOK_IDENTIFICADOR '}';


clase_vector: TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']';


identificadores: TOK_IDENTIFICADOR ',' identificadores
			   | TOK_IDENTIFICADOR;


funciones: funcion funciones
		 | /*lambda*/;		 


funcion: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{'
		 declaraciones_funcion sentencias '}';


tipo_retorno: TOK_NONE
			| tipo
			| clase_objeto;


parametros_funcion: parametro_funcion resto_parametros_funcion
				  | /*lambda*/;


resto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion
						| /*lambda*/;


parametro_funcion: tipo TOK_IDENTIFICADOR
				 | clase_objeto TOK_IDENTIFICADOR;


declaraciones_funcion: declaraciones
					 | /*lambda*/;


sentencias: sentencia sentencias 
		  | sentencia;


sentencia: sentencia_simple ';'
		 | bloque;


sentencia_simple: asignacion
				| escritura 
				| lectura
				| retorno_funcion
				| identificador_clase'.'TOK_IDENTIFICADOR'('lista_expresiones')'
				| TOK_IDENTIFICADOR'('lista_expresiones')'
				| destruir_objeto;


destruir_objeto: TOK_DISCARD TOK_IDENTIFICADOR;


bloque: condicional
	  | bucle;


asignacion: TOK_IDENTIFICADOR '=' exp
		  | elemento_vector '=' exp
		  | elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR'(' lista_expresiones ')'
		  | TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR'(' lista_expresiones ')'
		  | identificador_clase'.'TOK_IDENTIFICADOR '=' exp;


elemento_vector: TOK_IDENTIFICADOR'['exp']';


condicional: TOK_IF'('exp')''{'sentencias'}'
		   | TOK_IF'('exp')''{'sentencias'}' TOK_ELSE '{'sentencias'}';


bucle: TOK_WHILE'('exp')''{'sentencias'}';


lectura: TOK_SCANF TOK_IDENTIFICADOR
	   | TOK_SCANF elemento_vector;


escritura: TOK_PRINTF exp;


retorno_funcion: TOK_RETURN exp
			   | TOK_RETURN TOK_NONE; 


exp: exp '+' exp
   | exp '-' exp
   | exp '/' exp
   | exp '*' exp
   | '-'exp
   | exp TOK_AND exp
   | exp TOK_OR exp
   | '!'exp
   | TOK_IDENTIFICADOR
   | constante
   | '('exp')'
   | '('comparacion')'
   | elemento_vector
   | TOK_IDENTIFICADOR'(' lista_expresiones ')'
   | identificador_clase'.'TOK_IDENTIFICADOR'('lista_expresiones ')'
   | identificador_clase'.'TOK_IDENTIFICADOR;


identificador_clase: TOK_IDENTIFICADOR
				   | TOK_ITSELF;


lista_expresiones: exp resto_lista_expresiones
				 | /*lambda*/;


resto_lista_expresiones: ',' exp resto_lista_expresiones
					   | /*lambda*/;


comparacion: exp TOK_IGUAL exp
		   | exp TOK_DISTINTO exp
		   | exp TOK_MENORIGUAL exp
		   | exp TOK_MAYORIGUAL exp
		   | exp '<' exp
		   | exp '>' exp;


constante: constante_logica
		 | constante_entera;


constante_logica: TOK_TRUE
				| TOK_FALSE;


constante_entera: numero;


numero: TOK_CONSTANTE_ENTERA
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
    printf("parser error %s \n ",s);
    return 0;
}