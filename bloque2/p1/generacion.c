/*
Asignatura: PAUTLEN
Bloque: Procedural
Modulo: generacion.c

Grupo 5: Alejandro Cabana, Pablo Alejo Polanía, Luis Cárabe, Emilio Cuesta, Blanca Martín

*/

#include "generacion.h"

/*
   Código para el principio de la sección .bss.
   Con seguridad sabes que deberás reservar una variable entera para guardar el puntero de pila extendido (esp). Se te sugiere el nombre __esp para esta variable.
*/
void escribir_cabecera_bss(FILE* fpasm){
   fprintf(fpasm, "segment .bss\n");
   fprintf(fpasm, "\t__esp resd 1\n"); /*Variable para guardar la pila*/
   return;
}

/*
   Declaración (con directiva db) de las variables que contienen el texto de los mensajes para la identificación de errores en tiempo de ejecución.
   En este punto, al menos, debes ser capaz de detectar la división por 0.
*/
void escribir_subseccion_data(FILE* fpasm){
   fprintf(fpasm, "segment .data\n");
   fprintf(fpasm, "\tmsg_error_indice_vector\tdb \"Indice de vector fuera de rango\", 0\n");
   fprintf(fpasm, "\tmsg_error_div_zero\tdb \"ERROR: Division por 0\", 0\n"); /*Mensaje de error (división por 0)*/
   return;
}


/*
   Para ser invocada en la sección .bss cada vez que se quiera declarar una variable:
   El argumento nombre es el de la variable.
   tipo puede ser ENTERO o BOOLEANO (observa la declaración de las constantes del principio del fichero).
   Esta misma función se invocará cuando en el compilador se declaren vectores, por eso se adjunta un argumento final (tamano) que para esta primera práctica siempre recibirá el valor 1.
*/

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
   /*Funciones declaradas en olib.o*/
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

   fprintf(fpasm, "\tjmp fin\n"); /*Saltamos el error de divisor 0*/

   fprintf(fpasm, "\tdivisor_zero:\n");
   /*Imprimimos el mensaje de error por división por cero*/
   fprintf(fpasm, "\tpush dword msg_error_div_zero\n"); 
   fprintf(fpasm, "\tcall print_string\n");
   fprintf(fpasm, "\tadd esp, 4\n"); /*Equilibramos la pila*/
   fprintf(fpasm, "\tcall print_endofline\n");/*Imprimimos salto de línea*/

   fprintf(fpasm, "fin:\n");
   fprintf(fpasm, "\tmov dword esp, [__esp]\n"); /*Restauramos puntero de la pila*/
   fprintf(fpasm, "\tret\n");
   return; 
}

/*
   Función que debe ser invocada cuando se sabe un operando de una operación aritmético-lógica y se necesita introducirlo en la pila.
nombre es la cadena de caracteres del operando tal y como debería aparecer en el fuente NASM
es_variable indica si este operando es una variable (como por ejemplo b1) con un 1 u otra cosa (como por ejemplo 34) con un 0. Recuerda que en el primer caso internamente se representará como _b1 y, sin embargo, en el segundo se representará tal y como esté en el argumento (34).
*/
void escribir_operando(FILE* fpasm, char* nombre, int es_variable){
   if (es_variable) /* En caso de ser variable, sabemos que esta almacenada con "_" antes del nombre*/
      fprintf(fpasm, "\tpush dword _%s\n", nombre);
   else /* En caso de no ser variable, insertamos directamente*/
      fprintf(fpasm, "\tpush dword %s\n", nombre);
   return;
}

/*
Genera el código para asignar valor a la variable de nombre nombre. 
Se toma el valor de la cima de la pila.
El último argumento es el que indica si lo que hay en la cima de la pila es una referencia (1) o ya un valor explícito (0).
*/
void asignar(FILE* fpasm, char* nombre, int es_variable){
   if(es_variable){ /* En caso de ser una referencia...*/
      fprintf(fpasm, "\tpop dword ecx\n"); /*... extraemos la direccion en ecx*/ 
      fprintf(fpasm, "\tmov dword eax, [ecx]\n"); /* Guardamos lo que contiene esa posición de memoria en eax*/
      fprintf(fpasm, "\tmov dword [_%s], eax\n", nombre); /* Por último, guardamos el dato en su correspondiente posición de memoria*/
   }
   else
      fprintf(fpasm, "\tpop dword [_%s]\n", nombre); /*En caso de ser valor explícito, al extraer de pila, lo podemos hacer directamente en su correspondiente posición de memoria*/ 
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
      fprintf(fpasm, "\tpop dword edx\n"); /*Extraemos la dirección de la pila*/
      fprintf(fpasm, "\tmov dword %s, [edx]\n", registro); /*Guardamos el contenido de esa dirección de memoria en el registro correspondiente*/
   }
   else{
      fprintf(fpasm,"\tpop dword %s\n", registro); /*Si es un valor explícito, guardamos directamente en el registro*/
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

   /*Cargamos los operandos en los registros eax y ebx*/

   cargarDePila(fpasm, es_variable_2, "ebx");
   cargarDePila(fpasm, es_variable_1, "eax");
   
   fprintf(fpasm,"\tadd eax, ebx\n"); /*Operamos*/
   fprintf(fpasm, "\tpush dword eax\n");/*Guardamos el resultado*/

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

   /*Cargamos los operandos en los registros eax y ebx*/

   cargarDePila(fpasm, es_variable_2, "ebx");
   cargarDePila(fpasm, es_variable_1, "eax");
   
   fprintf(fpasm,"\tsub eax, ebx\n");/*Operamos*/
   fprintf(fpasm, "\tpush dword eax\n");/*Guardamos el resultado*/

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

   /*Cargamos los operandos en los registros eax y ecx*/

   cargarDePila(fpasm, es_variable_2, "ecx");
   cargarDePila(fpasm, es_variable_1, "eax");

   fprintf(fpasm,"\timul ecx\n");/*Operamos (imul toma como segundo operando eax)*/
   fprintf(fpasm, "\tpush dword eax\n");/*Guardamos el resultado*/

   return;
}

void dividir(FILE* fpasm, int es_variable_1, int es_variable_2){
/* A la hora de llamar a cualquiera de estas funciones los argumentos se 
escriben en la pila de izquierda a derecha. Esto es, si por ejemplo
la operacion es x + y, primero se inserta x en la pila y luego y.
De esta manera, es necesario extraer y primero. Consecuentemente:
es_variable_2: Se corresponde con el elemento que esta mas alto en la pila, 
               el segundo operando (y).
es_variable_1: Se corresponde con el elemento que esta por debajo en la pila, 
               el primer operando (x) */

   /*Cargamos los operandos en los registros eax y ecx*/

   cargarDePila(fpasm, es_variable_2, "ecx");
   cargarDePila(fpasm, es_variable_1, "eax");

   /*Comprobamos que el divisor sea distinto de 0*/
   fprintf(fpasm, "\tcmp ecx, 0\n");
   fprintf(fpasm, "\tje near divisor_zero\n"); /*Saltamos a la parte del codigo que se encarga de avisar de divisor 0 y terminar el programa (estará al final)*/

   /*El código de divisor_zero se encuentra al final del programa para evitar colisiones*/

   fprintf(fpasm, "\tcdq\n"); /*Extension de eax a edx:eax*/

   fprintf(fpasm,"\tidiv ecx\n"); /*idiv toma como dividendo eax, como argumento le pasamos el divisor*/
   fprintf(fpasm, "\tpush dword eax\n");/*Guardamos el resultado*/
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

   /*Cargamos los operandos en los registros eax y ebx*/

   cargarDePila(fpasm, es_variable_2, "ebx");
   cargarDePila(fpasm, es_variable_1, "eax");

   fprintf(fpasm,"\tor eax, ebx\n"); /*Operamos*/
   fprintf(fpasm, "\tpush dword eax\n");/*Guardamos el resultado*/

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

   /*Cargamos los operandos en los registros eax y ebx*/

   cargarDePila(fpasm, es_variable_2, "ebx");
   cargarDePila(fpasm, es_variable_1, "eax");

   fprintf(fpasm,"\tand eax, ebx\n"); /*Operamos*/
   fprintf(fpasm, "\tpush dword eax\n");/*Guardamos el resultado*/

   return;
}

/*
   Función aritmética de cambio de signo. 
   Es análoga a las binarias, excepto que sólo requiere de un acceso a la pila ya que sólo usa un operando.
*/
void cambiar_signo(FILE* fpasm, int es_variable){

   /*Cargamos el operando en el registro eax*/

   cargarDePila(fpasm, es_variable, "eax");

   fprintf(fpasm,"\tneg eax\n"); /*Operamos*/
   fprintf(fpasm, "\tpush dword eax\n");/*Guardamos el resultado*/

   return;
}

/*
   Función monádica lógica de negación. No hay un código de operación de la ALU que realice esta operación por lo que se debe codificar un algoritmo que,
    si encuentra en la cima de la pila un 0 deja en la cima un 1 y al contrario.
   El último argumento es el valor de etiqueta que corresponde (sin lugar a dudas, la implementación del algoritmo requerirá etiquetas). 
   Véase en los ejemplos de programa principal como puede gestionarse el número de etiquetas cuantos_no.
*/
void no(FILE* fpasm, int es_variable, int cuantos_no){

   /*Cargamos el operando en el registro eax*/

   cargarDePila(fpasm, es_variable, "eax");

   /*Comprobamos si hay un 0, en ese caso saltamos a la etiqueta zero_to_oneN, siendo N el identificador de la etiqueta correspondiente*/

   fprintf(fpasm,"\tmov dword edx, 0\n");
   fprintf(fpasm, "\tcmp ebx, eax\n");
   fprintf(fpasm,"\tje near zero_to_one%d\n",cuantos_no);

   /*Pasamos de uno a cero*/
   fprintf(fpasm, "\tmov dword eax, 0\n");
   fprintf(fpasm, "\tjmp near after_not%d\n", cuantos_no); /*Saltamos la operación de pasar de 0 a 1*/

   /*Pasamos de cero a uno*/
   fprintf(fpasm, "zero_to_one%d:\n", cuantos_no);
   fprintf(fpasm, "\tmov dword eax, 1\n");

   fprintf(fpasm,"after_not%d:\n", cuantos_no);
   fprintf(fpasm, "\tpush dword eax\n");/*Guardamos el resultado*/

   return;

}

/* FUNCIONES COMPARATIVAS */
/* 
   Todas estas funciones reciben como argumento si los elementos a comparar son o no variables. 
   El resultado de las operaciones, que siempre será un booleano (“1” si se cumple la comparación
   y “0” si no se cumple), se deja en la pila como en el resto de operaciones. Se deben usar 
   etiquetas para poder gestionar los saltos necesarios para implementar las comparaciones.
*/

/*Función que generaliza el comportamiento que deben tener todos los tipos de salto*/

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

   /*Cargamos los registros a comparar en eax y ebx*/
      
   cargarDePila(fpasm, es_variable_2, "ebx");
   cargarDePila(fpasm, es_variable_1, "eax");

   /* Realizamos la comparacion*/
   fprintf(fpasm, "\tcmp eax, ebx\n");

   logicadeSalto(fpasm, "je", etiqueta);

   return;
}

void distinto(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){

   /*Cargamos los registros a comparar en eax y ebx*/
   
   cargarDePila(fpasm, es_variable_2, "ebx");
   cargarDePila(fpasm, es_variable_1, "eax");

   /* Realizamos la comparacion*/
   fprintf(fpasm, "\tcmp eax, ebx\n");

   logicadeSalto(fpasm, "jne", etiqueta);

   return;
}
void menor_igual(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){

   /*Cargamos los registros a comparar en eax y ebx*/
   
   cargarDePila(fpasm, es_variable_2, "ebx");
   cargarDePila(fpasm, es_variable_1, "eax");

   /* Realizamos la comparacion*/
   fprintf(fpasm, "\tcmp eax, ebx\n");

   logicadeSalto(fpasm, "jle", etiqueta);

   return;
}
void mayor_igual(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){

   /*Cargamos los registros a comparar en eax y ebx*/
   
   cargarDePila(fpasm, es_variable_2, "ebx");
   cargarDePila(fpasm, es_variable_1, "eax");

   /* Realizamos la comparacion*/
   fprintf(fpasm, "\tcmp eax, ebx\n");

   logicadeSalto(fpasm, "jge", etiqueta);

   return;
}

void menor(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){

   /*Cargamos los registros a comparar en eax y ebx*/
      
   cargarDePila(fpasm, es_variable_2, "ebx");
   cargarDePila(fpasm, es_variable_1, "eax");

   /* Realizamos la comparacion*/
   fprintf(fpasm, "\tcmp eax, ebx\n");

   logicadeSalto(fpasm, "jl", etiqueta);

   return;
}
void mayor(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){

   /*Cargamos los registros a comparar en eax y ebx*/
   
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
   fprintf(fpasm, "\tpush dword _%s\n", nombre); /*Guardamos la dirección de memoria donde queremos guardar lo que leamos en la pila*/
   if( tipo == BOOLEANO ){ /*Leemos un booleano*/
      fprintf(fpasm, "\tcall scan_boolean\n");
   } else if( tipo == ENTERO){ /*Leemos un entero*/
      fprintf(fpasm, "\tcall scan_int\n"); 
   }

   fprintf(fpasm, "\tadd esp, 4\n"); /* Equilibramos el puntero de la pila*/
   return;
}

void escribir(FILE* fpasm, int es_variable, int tipo){
   if(es_variable){
      fprintf(fpasm, "\tpop dword ecx\n"); /*Sacamos la dirección que hemos metido previamente en la pila*/
      fprintf(fpasm, "\tpush dword [ecx]\n"); /*Guardamos el contenido de la dirección en la pila*/
   } /*Si no es variable, ya tenemos guardada en la pila lo que queremos imprimir*/

   if( tipo == BOOLEANO ){ /*Imprimimos booleano*/
      fprintf(fpasm, "\tcall print_boolean\n");
   } else if( tipo == ENTERO){ /*Imprimimos entero*/
      fprintf(fpasm, "\tcall print_int\n");
   }
   
   fprintf(fpasm, "\tadd esp, 4\n"); /* Equilibramos el puntero de la pila*/
   fprintf(fpasm, "\tcall print_endofline\n"); /*Imprimimos un salto de línea*/
   return;
}



