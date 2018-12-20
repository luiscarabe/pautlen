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
   fprintf(fpasm, "\tmsg_error_indice_vector\tdb \"ERROR: Indice de vector fuera de rango\", 0\n");
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
   fprintf(fpasm, "\textern print_endofline, print_blank, print_string, malloc, free\n");
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

   fprintf(fpasm, "\tjmp near fin\n"); /*Saltamos el error de divisor 0*/

   fprintf(fpasm, "index_error:\n");
   /*Imprimimos el mensaje de error por división por cero*/
   fprintf(fpasm, "\tpush dword msg_error_indice_vector\n");
   fprintf(fpasm, "\tcall print_string\n");
   fprintf(fpasm, "\tadd esp, 4\n"); /*Equilibramos la pila*/
   fprintf(fpasm, "\tcall print_endofline\n");/*Imprimimos salto de línea*/
   fprintf(fpasm, "\tjmp near fin\n");

   fprintf(fpasm, "divisor_zero:\n");
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
la operacion es x - y, primero se inserta x en la pila y luego y.
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



/* Generación de código para el inicio de una estructura if-then
exp_es_variable
Es 1 si la expresión de la condición es algo asimilable a una variable (identificador, acceso a atributo de instancia o clase, elemento de vector
Es 0 en caso contrario (constante u otro tipo de expresión) */

void ifthen_inicio(FILE * fpasm, int exp_es_variable, int etiqueta){
   /* Realizaremos la comprobación del if-then-else
   Sacamos su valor de la pila, ej. pop eax
   Si es dirección ($3.es_direccion == 1) ... mov eax, [eax] */
   // Recuerdo: cargarDePila ya hace la distincion si es variable o no.
   cargarDePila(fpasm, exp_es_variable, "eax");

   /*Comparamos con 0,  cmp eax, 0
   Hacemos el salto al final de la rama then en este caso,
   je near fin_then%numetiqueta%>

   Si el resultado que había en la pila es un 0 es que no se cumple la condición.
   Saltamos directamente al final de la rama if-then. (No hay else)
   */
   fprintf(fpasm, "\tcmp eax, 0\n");
   fprintf(fpasm, "\tje near fin_then%d\n", etiqueta);
   return;
}


/* Generación de código para el fin de una estructura if-then */
void ifthen_fin(FILE * fpasm, int etiqueta){

   /* Escribes la etiqueta para poder saltar el bloque */
   fprintf(fpasm, "fin_then%d:\n", etiqueta);
   return;
}


void ifthenelse_inicio(FILE * fpasm, int exp_es_variable, int etiqueta){


   /* El comienzo es el mismo tanto para if-then como para if-then-else
      En caso de que no se cumpla la condición se salta al final del bloque then*/
   ifthen_inicio(fpasm, exp_es_variable, etiqueta);
   return;
}


/* Generación de código para el fin de la rama then de una estructura if-then-else */
void ifthenelse_fin_then( FILE * fpasm, int etiqueta){

   /* Si vienes ejecutando las instrucciones del bloque if, saltas al final
   (no quieres ejecutar else)*/
   fprintf(fpasm, "\tjmp near fin_else%d\n", etiqueta);

   /* Escribes la etiqueta para poder saltar el bloque */
   fprintf(fpasm, "fin_then%d:\n", etiqueta);
   return;

}


/* Generación de código para el fin de una estructura if-then-else */
void ifthenelse_fin( FILE * fpasm, int etiqueta){

   /* Escritura del fin del else, (se salta aqui desde el final del bloque if) */
   fprintf(fpasm, "fin_else%d:\n", etiqueta);
   return;
}


void while_inicio(FILE * fpasm, int etiqueta){
   /*1. Escribimos la etiqueta */

   fprintf(fpasm, "inicio_while%d:\n", etiqueta);

   return;
}

void while_exp_pila (FILE * fpasm, int exp_es_variable, int etiqueta){

   cargarDePila(fpasm, exp_es_variable, "eax");
   fprintf(fpasm, "\tcmp eax, 0\n");
   fprintf(fpasm, "\tje near fin_while%d\n", etiqueta);

   return;
}

void while_fin( FILE * fpasm, int etiqueta){

   fprintf(fpasm, "\tjmp near inicio_while%d\n", etiqueta);
   fprintf(fpasm, "fin_while%d:\n", etiqueta);
   return;
}


/* COMENTARIO MUY IMPORTANTE */
/* Escribe LA DIRECCION de un elemento vectorial en la cima de la pila*/
void escribir_elemento_vector(FILE * fpasm,char * nombre_vector, int tam_max, int exp_es_direccion){

   /* PASO 1: Codigo para comprobar si el indice esta fuera de rango. En ese caso se imprime error y se finaliza el programa"*/

   /* Cargamos el valor del indice */
   cargarDePila(fpasm, exp_es_direccion, "eax");
   fprintf(fpasm, "\tcmp eax, 0\n");
   fprintf(fpasm, "\tjl near index_error\n");
   fprintf(fpasm, "\tcmp eax, %d\n", tam_max-1);
   fprintf(fpasm, "\tjg near index_error\n");

   /* En este punto el indice es correcto */

   /* PASO 2: Gestion de la asignacion propiamente dicha. Hay que dejar en la cima de la pila la direccion del elem. indexado */

   fprintf(fpasm, "\tmov dword edx, _%s\n", nombre_vector);
   fprintf(fpasm, "\tlea eax, [edx + eax*4]\n");
   fprintf(fpasm, "\tpush dword eax\n");

   return;
}

/* Vale para general el codigo de expresiones de la forma:
   v[i] = exp */
/* Asume que exp esta en la cima de la pila, y que la direccion del elemento del vector está en segunda posicion de la pila*/
void asignar_a_elemento_vector(FILE * fpasm, int exp_es_direccion){


   /* Cargar en eax la parte derecha de la asignación */
   cargarDePila(fpasm, exp_es_direccion, "eax");
   /* Cargar en edx la parte izquierda de la asignación */
   /* Estamos asumiendo que en pila esta justo el valor que queremos (no es necesario acceder a otra posicion de memoria),
      entonces, asignamos manualmente el valor 0 a es_direccion */
   cargarDePila(fpasm, 0, "edx");

   /* Hacer la asignación efectiva */
   fprintf(fpasm, "\tmov dword [edx] , eax\n");
   return;
}

/*Generación de código para iniciar la declaración de una función.*/

void declararFuncion(FILE * fd_s, char * nombre_funcion, int num_var_loc){
  fprintf(fd_s, "_%s:\n", nombre_funcion);
  fprintf(fd_s, "\tmov ebp, esp\n");
  fprintf(fd_s, "\tsub esp, %d\n", 4 * num_var_loc);
}

/*Generación de código para el retorno de una función.*/

void retornarFuncion(FILE * fd_s, int es_variable){
  /* El retorno se hará mediante eax*/
  fprintf(fd_s, "\tpop dword eax\n");
  if(es_variable){ /*Si es una dirección, sacamos su valor*/
    fprintf(fd_s, "\tmov eax, [eax]\n");
  }
  fprintf(fd_s, "\tmov dword esp, ebp\n");
  fprintf(fd_s, "\tpop dword ebp\n");
  fprintf(fd_s, "\tret\n");

}

void escribirParametro(FILE* fpasm, int pos_parametro, int num_total_parametros){
  /* Cogemos la dirección donde está nuestro parámetro*/
  fprintf(fpasm, "\tlea eax, [ebp+%d]\n", 4+4*(num_total_parametros-pos_parametro));
  /*Guardamos en la pila*/
  fprintf(fpasm, "\tpush eax\n");

}

void escribirVariableLocal(FILE* fpasm, int posicion_variable_local){
  /*[ebp -
<4*posición de la variable en declaración>
]*/
  /* Cogemos la dirección donde está nuestra variable local*/
  fprintf(fpasm, "\tlea eax, [ebp-%d]\n", 4*(posicion_variable_local));
  /*Guardamos en la pila*/
  fprintf(fpasm, "\tpush eax\n");
}

/*Realiza la tarea de dado un operando escrito en la pila y sabiendo si es variable o no se deja en la pila el valor correspondiente*/
void operandoEnPilaAArgumento(FILE* fd_asm, int es_variable){
  cargarDePila(fd_asm, es_variable, "eax");
  fprintf(fd_asm, "\tpush eax\n");
}

/*Genera código para llamar a la función nombre_funcion asumiendo que los argumentos están en la pila en el orden fijado en el material de la asignatura*/
void llamarFuncion(FILE * fd_asm, char * nombre_funcion, int num_argumentos){
  fprintf(fd_asm, "\tcall _%s\n", nombre_funcion);
  limpiarPila(fd_asm, num_argumentos);
  /*Guardamos el resultado de la función en la pila*/
  fprintf(fd_asm, "\tpush dword eax\n");
}


/******************* NUEVAS OO *********************************************/
char * claseATabla(char * nombre_fuente_clase);

void instance_of (FILE * fd_asm, char * nombre_fuente_clase, int numero_atributos_instancia){

   fprintf(fd_asm, "\tpush dword %d\n", (numero_atributos_instancia+1)*4);
   fprintf(fd_asm, "\tcall malloc\n");
   fprintf(fd_asm, "\tadd esp, 4\n");
   // Si falla quitar ms (fantasma)
   fprintf(fd_asm, "\tmov dword [eax], _ms%s\n", nombre_fuente_clase);
   fprintf(fd_asm, "\tpush eax\n");
}

void discardPila (FILE * fd_asm){

   fprintf(fd_asm, "\tcall free\n");
   fprintf(fd_asm, "\tadd esp, 4\n");
}

void limpiarPila(FILE * fd_asm, int num_argumentos){
  /*Restauramos la pila*/
  fprintf(fd_asm, "\tadd esp, %d\n", 4*num_argumentos);
}

void llamarMetodoSobreescribibleCualificadoInstanciaPila(FILE * fd_asm, char * nombre_metodo){

	fprintf(fd_asm, "\tpop ebx\n");
   fprintf(fd_asm, "\tmov dword ebx, [ebx]\n");
   fprintf(fd_asm, "\tmov dword ecx, [_offset_%s]\n", nombre_metodo);
   fprintf(fd_asm, "\tlea ecx, [ebx + ecx]\n");
   fprintf(fd_asm, "\tmov dword ecx, [ecx]\n");
   fprintf(fd_asm, "\tcall ecx\n");

}

void accederAtributoInstanciaDePila(FILE * fd_asm, char * nombre_atributo){

   fprintf(fd_asm, "\tpop ebx\n");
   fprintf(fd_asm, "\tmov dword ebx, [ebx]\n");
   fprintf(fd_asm, "\tmov dword ecx, [_offset_%s]\n", nombre_atributo);
   fprintf(fd_asm, "\tlea ecx, [ebx+ecx]\n");
   fprintf(fd_asm, "\tpush ecx\n");

}


// ESTA FUNCIÓN ES LA QUE SE USA DESPUÉS DE
// - escribir_operando (para una variable global)
// - escribirParametro
// - escribirVariableLocal
void asignarDestinoEnPila(FILE* fd_asm, int es_variable){
	// Primero la direccion
	fprintf(fd_asm, "\tpop dword eax\n");
	// Valor que hay que escribir
	fprintf(fd_asm, "\tpop dword ebx\n");

	if (es_variable)
		fprintf(fd_asm, "\tmov ebx, [ebx]\n");
	fprintf(fd_asm, "\tmov [eax], ebx\n");
}
