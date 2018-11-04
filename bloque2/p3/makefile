CC = gcc
CCFLAGS = -Wall -g

all: y.tab.c lex.yy.c lex.yy.o pruebaSintactico

y.tab.c: omicron.y
	bison -dyv *.y

lex.yy.c: omicron.l
	flex $<

y.tab.o: y.tab.c
	$(CC) $(CCFLAGS) -c $< -o $@

lex.yy.o: lex.yy.c
	$(CC) $(CCFLAGS) -c $< -o $@

pruebaSintactico: pruebaSintactico.c
	$(CC) $(CCFLAGS) -o $@ $<

clean:
	rm -f y.tab.o lex.yy.o pruebaSintactico y.tab.c lex.yy.c