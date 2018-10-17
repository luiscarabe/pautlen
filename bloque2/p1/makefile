CC = gcc
CCFLAGS = -pedantic -Wall -g

all: generacion.o

generacion.o: generacion.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f generacion.o