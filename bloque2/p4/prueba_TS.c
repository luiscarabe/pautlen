// INCLUDES

...


// OPERACIONES

#define TOK_OP_INICIA_TSA_MAIN        "inicia_tsa_main"
#define TOK_OP_ABRIR_AMBITO_PPAL_MAIN    "abrir_ambito_ppal_main"
#define TOK_OP_BUSCAR            "buscar"
#define TOK_OP_INSERTAR_TSA_MAIN     "insertar_tsa_main"
#define TOK_OP_ABRIR_AMBITO_TSA_MAIN    "abrir_ambito_tsa_main"
#define TOK_OP_CERRAR_AMBITO_TSA_MAIN    "cerrar_ambito_tsa_main"
#define TOK_OP_INICIA_TSC         "inicia_tsc"
#define TOK_OP_DECLARAR_MAIN  "declarar_main"


#define TOK_OP_CERRAR_CLASE        "cerrar_clase"
#define TOK_OP_CERRAR_TSA_MAIN        "cerrar_tsa_main"
#define TOK_OP_CERRAR_TSC        "cerrar_tsc"

// PARAMETROS
#define TOK_DECLARAR_MAIN        "declarar_main"
#define TOK_DECLARAR_MIEMBRO_CLASE    "declarar_miembro_clase"
#define TOK_DECLARAR_MIEMBRO_INSTANCIA    "declarar_miembro_instancia"
···
#define TOK_ID_CUALIFICADO_INSTANCIA    "id_cualificado_instancia"
#define TOK_ID_CUALIFICADO_CLASE    "id_cualificado_clase"

// Definicion de cosas, punto 5 del enunciado



FILE* yyin; 
FILE* fout;


// MAIN
int main(int argv, char** argc){

	if (argc != 3){
		fprintf(stderr, "Por favor, inserta por argumento el fichero de entrada y de salida.\n");
		return 1;
	}

	yyin = fopen(argv[1], "r");
	if (!yyin){
		fprintf(stderr, "Fichero de entrada inválido.\n");
		return 1;
	}

	fout = fopen(argv[2], "w");
	if (!fout){
		fprintf(stderr, "Fichero de salida inválido.\n");
		fclose(yyin);
		return 1;
	}


	while( fgets(linea,100,fd_in) != NULL){

        token=strtok(linea," \n\t");

        switch(token){

        case 1... : 
    	
        	...
    	case TOKn...:
    		token=strtok(NULL," \n\t");
    		ambito =(char*)malloc(sizeof(char)*(1+strlen(token)));
    		strcpy(ambito,token);
    		categoria= atoi(strtok(NULL," \n\t"));
        

    	}
    }

}

