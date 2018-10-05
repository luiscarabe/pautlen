/*
Asignatura: PAUTLEN
Bloque: Procedural
Modulo: generacion.c
*/

#include "generacion.h"
#include <stdlib.h>

/*
   Código para el principio de la sección .bss.
   Con seguridad sabes que deberás reservar una variable entera para guardar el puntero de pila extendido (esp). Se te sugiere el nombre __esp para esta variable.
*/
void escribir_cabecera_bss(FILE* fpasm){
   fprintf(fpasm, "segment .bss\n");
   fprintf(fpasm, "\t__esp resd 1\n");
   return;
}

/*
   Declaración (con directiva db) de las variables que contienen el texto de los mensajes para la identificación de errores en tiempo de ejecución.
   En este punto, al menos, debes ser capaz de detectar la división por 0.
*/
void escribir_subseccion_data(FILE* fpasm){
   fprintf(fpasm, "segment .data\n");
   fprintf(fpasm, "\tmsg_error_indice_vector\tdb \"Indice de vector fuera de rango\", 0\n");
   fprintf(fpasm, "\tmsg_error_div_zero\tdb \"ERROR: Division por 0\", 0\n");
   return;
}


/*
   Para ser invocada en la sección .bss cada vez que se quiera declarar una variable:
   El argumento nombre es el de la variable.
   tipo puede ser ENTERO o BOOLEANO (observa la declaración de las constantes del principio del fichero).
   Esta misma función se invocará cuando en el compilador se declaren vectores, por eso se adjunta un argumento final (tamano) que para esta primera práctica siempre recibirá el valor 1.
*/

/* TODO: Por que pasamos el tipo aqui??*/
void declarar_variable(FILE* fpasm, char * nombre,  int tipo,  int tamano){
   fprintf(fpasm, "\t_%s resd %d\n", nombre, tamano);
   return;
}


/*
   Para escribir el comienzo del segmento .text, básicamente se indica que se exporta la etiqueta main y que se usarán las funciones declaradas en la librería olib.o
*/
void escribir_segmento_codigo(FILE* fpasm){
   fprintf(fpasm, "segment .txt\n");
   fprintf(fpasm, "\tglobal main\n");
   fprintf(fpasm, "\textern scan_int, print_int, scan_boolean, print_boolean\n");
   fprintf(fpasm, "\textern print_endofline, print_blank, print_string\n");
   return;
}

/* 
   En este punto se debe escribir, al menos, la etiqueta main y la sentencia que guarda el puntero de pila en su variable (se recomienda usar __esp).
*/
void escribir_inicio_main(FILE* fpasm){
   fprintf(fpasm, "main:\n");
   fprintf(fpasm, "\tmov dword [__esp], esp\n");
   return;   
}

/*
   Al final del programa se escribe:
El código NASM para salir de manera controlada cuando se detecta un error en tiempo de ejecución (cada error saltará a una etiqueta situada en esta zona en la que se imprimirá el correspondiente mensaje y se saltará a la zona de finalización del programa).
En el final del programa se debe:
         ·Restaurar el valor del puntero de pila (a partir de su variable __esp)
         ·Salir del programa (ret).
*/
void escribir_fin(FILE* fpasm){
   /* TODO: */
   fprintf(fpasm, "fin:\n");
   fprintf(fpasm, "\tmov dword esp, [__esp]\n");
   fprintf(fpasm, "\tret\n");
   return; 
}

/*
   Función que debe ser invocada cuando se sabe un operando de una operación aritmético-lógica y se necesita introducirlo en la pila.
nombre es la cadena de caracteres del operando tal y como debería aparecer en el fuente NASM
es_variable indica si este operando es una variable (como por ejemplo b1) con un 1 u otra cosa (como por ejemplo 34) con un 0. Recuerda que en el primer caso internamente se representará como _b1 y, sin embargo, en el segundo se representará tal y como esté en el argumento (34).
*/
void escribir_operando(FILE* fpasm, char* nombre, int es_variable){
   if (es_variable)
      fprintf(fpasm, "\tpush dword _%s\n", nombre);
   else
      fprintf(fpasm, "\tpush dword %s\n", nombre);
   return;
}

/*
Genera el código para asignar valor a la variable de nombre nombre. 
Se toma el valor de la cima de la pila.
El último argumento es el que indica si lo que hay en la cima de la pila es una referencia (1) o ya un valor explícito (0).
*/
void asignar(FILE* fpasm, char* nombre, int es_variable){
   if(es_variable){
      fprintf(fpasm, "\tpop dword ecx\n");      
      fprintf(fpasm, "\tmov dword eax, [ecx]\n");
      fprintf(fpasm, "\tmov dword [_%s], eax\n", nombre);
   }
   else
      fprintf(fpasm, "\tpop dword [_%s]\n", nombre);      
   return;
}

/* FUNCIONES ARITMÉTICO-LÓGICAS BINARIAS */
/*
   En todas ellas se realiza la operación como se ha resumido anteriormente:
   Se extrae de la pila los operandos
   Se realiza la operación
   Se guarda el resultado en la pila
   Los dos últimos argumentos indican respectivamente si lo que hay en la pila es una referencia a un valor o un valor explícito.
   Deben tenerse en cuenta las peculiaridades de cada operación. En este sentido sí hay que mencionar explícitamente que, en el caso de la división, 
   se debe controlar si el divisor es “0” y en ese caso se debe saltar a la rutina de error controlado (restaurando el puntero de pila en ese caso y 
   comprobando en el retorno que no se produce “Segmentation Fault”)
*/


/* Funcion auxiliar que se encarga de escribir las instrucciones que:
   Asignan a un registro (pasado como argumento) el contenido del nivel mas alto de la pila.
   Si es una variable (se indica como argumento) se carga directamente el valor de la misma en el
   registro (NO su direccion!).  Si no se trata de una variable,  se toma el valor del elemento 
   directamente. Se utiliza edx como registro auxiliar.*/

void cargarDePila(FILE* fpasm, int es_variable, char* registro){
   
   if(es_variable){
      fprintf(fpasm, "\tpop dword edx\n");
      fprintf(fpasm, "\tmov dword %s, [edx]\n", registro);
   }
   else{
      fprintf(fpasm,"\tpop dword %s\n", registro);
   }

   return;  
}

void sumar(FILE* fpasm, int es_variable_1, int es_variable_2){
/* A la hora de llamar a cualquiera de estas funciones los argumentos se 
   escriben en la pila de izquierda a derecha. Esto es, si por ejemplo
   la operacion es x + y, primero se inserta x en la pila y luego y.
   De esta manera, es necesario extraer y primero. Consecuentemente:
   es_variable_2: Se corresponde con el elemento que esta mas alto en la pila, 
                  el segundo operando (y).
   es_variable_1: Se corresponde con el elemento que esta por debajo en la pila, 
                  el primer operando (x) */

   cargarDePila(fpasm, es_variable_2, "ebx");
   cargarDePila(fpasm, es_variable_1, "eax");
   
   fprintf(fpasm,"\tadd eax, ebx\n");
   fprintf(fpasm, "\tpush dword eax\n");

   return;
}

void restar(FILE* fpasm, int es_variable_1, int es_variable_2){
/* A la hora de llamar a cualquiera de estas funciones los argumentos se 
escriben en la pila de izquierda a derecha. Esto es, si por ejemplo
la operacion es x + y, primero se inserta x en la pila y luego y.
De esta manera, es necesario extraer y primero. Consecuentemente:
es_variable_2: Se corresponde con el elemento que esta mas alto en la pila, 
               el segundo operando (y).
es_variable_1: Se corresponde con el elemento que esta por debajo en la pila, 
               el primer operando (x) */

   cargarDePila(fpasm, es_variable_2, "ebx");
   cargarDePila(fpasm, es_variable_1, "eax");
   
   fprintf(fpasm,"\tsub eax, ebx\n");
   fprintf(fpasm, "\tpush dword eax\n");

   return;
}

void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2){
/* A la hora de llamar a cualquiera de estas funciones los argumentos se 
escriben en la pila de izquierda a derecha. Esto es, si por ejemplo
la operacion es x + y, primero se inserta x en la pila y luego y.
De esta manera, es necesario extraer y primero. Consecuentemente:
es_variable_2: Se corresponde con el elemento que esta mas alto en la pila, 
               el segundo operando (y).
es_variable_1: Se corresponde con el elemento que esta por debajo en la pila, 
               el primer operando (x) */

   cargarDePila(fpasm, es_variable_2, "ecx");
   cargarDePila(fpasm, es_variable_1, "eax");

   fprintf(fpasm,"\timul ecx\n");
   fprintf(fpasm, "\tpush dword eax\n");

   return;
}

/*   Deben tenerse en cuenta las peculiaridades de cada operación. En este sentido sí hay que mencionar explícitamente que,
 en el caso de la división, se debe controlar si el divisor es “0” y en ese caso se debe saltar a la rutina de error 
 controlado (restaurando el puntero de pila en ese caso y comprobando en el retorno que no se produce “Segmentation Fault”)
*/

void dividir(FILE* fpasm, int es_variable_1, int es_variable_2){
/* A la hora de llamar a cualquiera de estas funciones los argumentos se 
escriben en la pila de izquierda a derecha. Esto es, si por ejemplo
la operacion es x + y, primero se inserta x en la pila y luego y.
De esta manera, es necesario extraer y primero. Consecuentemente:
es_variable_2: Se corresponde con el elemento que esta mas alto en la pila, 
               el segundo operando (y).
es_variable_1: Se corresponde con el elemento que esta por debajo en la pila, 
               el primer operando (x) */

   cargarDePila(fpasm, es_variable_2, "ecx");
   cargarDePila(fpasm, es_variable_1, "eax");
   
   /*idiv o div? TODO (supongo idiv de momento)*/

   /*Comprobamos que el divisor sea distinto de 0*/
   fprintf(fpasm, "\tcmp ecx, 0\n");
   fprintf(fpasm, "\tjne near divisor_no_zero\n");

   fprintf(fpasm, "\tpush dword msg_error_div_zero\n");
   fprintf(fpasm, "\tcall print_string\n");
   fprintf(fpasm, "\tadd esp, 4\n");
   fprintf(fpasm, "\tcall print_endofline\n");

   fprintf(fpasm, "\tjmp near fin\n");


   fprintf(fpasm, "\tdivisor_no_zero:\n");
   fprintf(fpasm, "\tcdq\n"); /*Extension de eax a edx:eax*/

   /*Guardamos resto y resultado?? resultado en eax, resto en edx TODO*/

   fprintf(fpasm,"\tidiv ecx\n");
   fprintf(fpasm, "\tpush dword eax\n");
   return;
}

void o(FILE* fpasm, int es_variable_1, int es_variable_2){
/* A la hora de llamar a cualquiera de estas funciones los argumentos se 
escriben en la pila de izquierda a derecha. Esto es, si por ejemplo
la operacion es x + y, primero se inserta x en la pila y luego y.
De esta manera, es necesario extraer y primero. Consecuentemente:
es_variable_2: Se corresponde con el elemento que esta mas alto en la pila, 
               el segundo operando (y).
es_variable_1: Se corresponde con el elemento que esta por debajo en la pila, 
               el primer operando (x) */

   cargarDePila(fpasm, es_variable_2, "ebx");
   cargarDePila(fpasm, es_variable_1, "eax");

   fprintf(fpasm,"\tor eax, ebx\n");
   fprintf(fpasm, "\tpush dword eax\n");

   return;
}

void y(FILE* fpasm, int es_variable_1, int es_variable_2){
/* A la hora de llamar a cualquiera de estas funciones los argumentos se 
escriben en la pila de izquierda a derecha. Esto es, si por ejemplo
la operacion es x + y, primero se inserta x en la pila y luego y.
De esta manera, es necesario extraer y primero. Consecuentemente:
es_variable_2: Se corresponde con el elemento que esta mas alto en la pila, 
               el segundo operando (y).
es_variable_1: Se corresponde con el elemento que esta por debajo en la pila, 
               el primer operando (x) */

   cargarDePila(fpasm, es_variable_2, "ebx");
   cargarDePila(fpasm, es_variable_1, "eax");

   fprintf(fpasm,"\tand eax, ebx\n");
   fprintf(fpasm, "\tpush dword eax\n");

   return;
}

/*
   Función aritmética de cambio de signo. 
   Es análoga a las binarias, excepto que sólo requiere de un acceso a la pila ya que sólo usa un operando.
*/
void cambiar_signo(FILE* fpasm, int es_variable){

   cargarDePila(fpasm, es_variable, "eax");

   fprintf(fpasm,"\tneg eax\n");
   fprintf(fpasm, "\tpush dword eax\n");

   return;
}

/*
   Función monádica lógica de negación. No hay un código de operación de la ALU que realice esta operación por lo que se debe codificar un algoritmo que,
    si encuentra en la cima de la pila un 0 deja en la cima un 1 y al contrario.
   El último argumento es el valor de etiqueta que corresponde (sin lugar a dudas, la implementación del algoritmo requerirá etiquetas). 
   Véase en los ejemplos de programa principal como puede gestionarse el número de etiquetas cuantos_no.
*/
void no(FILE* fpasm, int es_variable, int cuantos_no){

   /*En los ejemplos se usa solo con booleanos, voy a suponer que esto es estrictamente para eso, pero quien sabe TODO*/

   /*No se como hacer bien lo de las etiquetas TODO*/

   cargarDePila(fpasm, es_variable, "eax");

   fprintf(fpasm,"\tmov dword edx, 0\n");
   fprintf(fpasm, "\tcmp ebx, eax\n");

   fprintf(fpasm,"\tje near zero_to_one%d\n",cuantos_no);

   /*Pasamos de uno a cero*/
   fprintf(fpasm, "\tmov dword eax, 0\n");
   fprintf(fpasm, "\tjmp near after_not%d\n", cuantos_no); /*LEgal?? TODO*/

   /*Etiqueta zero_to_one*/
   fprintf(fpasm, "zero_to_one%d:\n", cuantos_no);
   fprintf(fpasm, "\tmov dword eax, 1\n");

   fprintf(fpasm,"after_not%d:\n", cuantos_no);
   fprintf(fpasm, "\tpush dword eax\n");

   return;

}

/* FUNCIONES COMPARATIVAS */
/* 
   Todas estas funciones reciben como argumento si los elementos a comparar son o no variables. 
   El resultado de las operaciones, que siempre será un booleano (“1” si se cumple la comparación
   y “0” si no se cumple), se deja en la pila como en el resto de operaciones. Se deben usar 
   etiquetas para poder gestionar los saltos necesarios para implementar las comparaciones.
*/

void logicadeSalto(FILE* fpasm, char* tipo_salto, int etiqueta){
   /* Salto en caso de comparacion efectiva*/
   fprintf(fpasm,"\t%s near branch_%d\n", tipo_salto, etiqueta);

   /* El resultado de la comparacion es falso*/
   fprintf(fpasm, "\tmov dword eax, 0\n");
   fprintf(fpasm, "\tjmp near branchend_%d\n", etiqueta); 

   /* El resultado de la comparacion es true*/
   fprintf(fpasm,"branch_%d:\n",etiqueta);
   fprintf(fpasm, "\tmov dword eax, 1\n");
   
   /* Escribimos el resultado en la pila*/
   fprintf(fpasm, "branchend_%d:\n", etiqueta);
   fprintf(fpasm, "\tpush dword eax\n");

   return;
}


void igual(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){
   
   cargarDePila(fpasm, es_variable_2, "ebx");
   cargarDePila(fpasm, es_variable_1, "eax");

   /* Realizamos la comparacion*/
   fprintf(fpasm, "\tcmp eax, ebx\n");

   logicadeSalto(fpasm, "je", etiqueta);

   return;
}

void distinto(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){
   
   cargarDePila(fpasm, es_variable_2, "ebx");
   cargarDePila(fpasm, es_variable_1, "eax");

   /* Realizamos la comparacion*/
   fprintf(fpasm, "\tcmp eax, ebx\n");

   logicadeSalto(fpasm, "jne", etiqueta);

   return;
}
void menor_igual(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){
   
   cargarDePila(fpasm, es_variable_2, "ebx");
   cargarDePila(fpasm, es_variable_1, "eax");

   /* Realizamos la comparacion*/
   fprintf(fpasm, "\tcmp eax, ebx\n");

   logicadeSalto(fpasm, "jle", etiqueta);

   return;
}
void mayor_igual(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){
   
   cargarDePila(fpasm, es_variable_2, "ebx");
   cargarDePila(fpasm, es_variable_1, "eax");

   /* Realizamos la comparacion*/
   fprintf(fpasm, "\tcmp eax, ebx\n");

   logicadeSalto(fpasm, "jge", etiqueta);

   return;
}

void menor(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){
      
   cargarDePila(fpasm, es_variable_2, "ebx");
   cargarDePila(fpasm, es_variable_1, "eax");

   /* Realizamos la comparacion*/
   fprintf(fpasm, "\tcmp eax, ebx\n");

   logicadeSalto(fpasm, "jl", etiqueta);

   return;
}
void mayor(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){
   
   cargarDePila(fpasm, es_variable_2, "ebx");
   cargarDePila(fpasm, es_variable_1, "eax");

   /* Realizamos la comparacion*/
   fprintf(fpasm, "\tcmp eax, ebx\n");

   logicadeSalto(fpasm, "jg", etiqueta);

   return;
}

/* FUNCIONES DE ESCRITURA Y LECTURA */
/*
   Se necesita saber el tipo de datos que se va a procesar (ENTERO o BOOLEANO) ya que hay diferentes funciones de librería para la lectura (idem. escritura) de cada tipo.
   Se deben insertar en la pila los argumentos necesarios, realizar la llamada (call) a la función de librería correspondiente y limpiar la pila.
*/
void leer(FILE* fpasm, char* nombre, int tipo){
   fprintf(fpasm, "\tpush dword _%s\n", nombre);
   if( tipo == BOOLEANO ){
      fprintf(fpasm, "\tcall scan_boolean\n");
   } else if( tipo == ENTERO){
      fprintf(fpasm, "\tcall scan_int\n");
   }

   fprintf(fpasm, "\tadd esp, 4\n");
   return;
}

void escribir(FILE* fpasm, int es_variable, int tipo){
   if(es_variable){
      fprintf(fpasm, "\tpop dword ecx\n");
      fprintf(fpasm, "\tpush dword [ecx]\n");
   }

   if( tipo == BOOLEANO ){
      fprintf(fpasm, "\tcall print_boolean\n");
   } else if( tipo == ENTERO){
      fprintf(fpasm, "\tcall print_int\n");
   }
   
   fprintf(fpasm, "\tadd esp, 4\n");
   fprintf(fpasm, "\tcall print_endofline\n");
   return;
}



