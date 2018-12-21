 #gcc -Wall -g -o main_generacion_omicron *.c -lm
 #./main_generacion_omicron ej.asm
 nasm -felf32 -g ej.asm
 nasm -felf32 -g n.asm 
 gcc -o ej -m32 ej.o n.o olib.o
 valgrind --leak-check=yes ./ej
