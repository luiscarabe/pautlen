%{

%}
%union
{
  int numero;
  // Yo creo que todos esto no es necesario porque nuestros tokens son todos del tipo int.
}

%token SI
%token ENTONCES
%token SINO

/* PALABRAS RESERVADAS */
%token TOK_NONE 200
%token TOK_CLASS 201
%token TOK_INHERITS 202
%token TOK_INSTANCE_OF 203
%token TOK_DISCARD 204
%token TOK_ITSELF 205
%token TOK_FLECHA 206
%token TOK_HIDDEN 207
%token TOK_SECRET 208
%token TOK_EXPOSED 209
%token TOK_UNIQUE 210
%token TOK_FUNCTION 211
%token TOK_RETURN 212
%token TOK_MAIN 213
%token TOK_INT 214
%token TOK_BOOLEAN 215
%token TOK_ARRAY 216	
%token TOK_IF 217
%token TOK_ELSE 218
%token TOK_WHILE 219
%token TOK_SCANF 220
%token TOK_PRINTF 221

/* IDENTIFICADOR */
%token TOK_IDENTIFICADOR 222

/* OPERADORES */
%token TOK_IGUAL 223
%token TOK_DISTINTO 224
%token TOK_MENORIGUAL 225
%token TOK_MAYORIGUAL 226
%token TOK_OR 227
%token TOK_AND 228

/* CONSTANTES */
%token TOK_CONSTANTE_ENTERA 229
%token TOK_FALSE 230 
%token TOK_TRUE 231

/* ERRORES */
%token TOK_ERROR -1

%left '+', '-'
%left '*', '/'
%right NEG_UNARIA '!'

/*Axioma*/
%start main

%%

main : TOK_MAIN '{' programa '}'

programa: declaraciones sentencias

declaraciones: 




%%


