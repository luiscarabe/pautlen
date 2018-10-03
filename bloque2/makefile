ejemplos_gen = ejemplo1 ejemplo2 ejemplo3 ejemplo4
CC = gcc
CCFLAGS = -pedantic -Wall -g

#Generator
ejemplos: $(ejemplos_gen)

%: ejemplos_gen/%_generacion.c generacion.c 
	$(CC) $(CCFLAGS) $^ -o $@_asm
	./$@_asm $@.asm
	nasm -g -o $@.o -f elf32 $@.asm
	gcc $(CCFLAGS) -m32 olib $@.o -o $@
	rm -f $@.o $@.asm $@_asm

