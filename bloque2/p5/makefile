CC = gcc
CCFLAGS = -Wall -g

all: generacion.o y.tab.c lex.yy.c y.tab.o lex.yy.o omicron

generacion.o: generacion.c
	$(CC) $(CCFLAGS) -c $< -o $@

y.tab.c: omicron.y
	bison -dyv $<

lex.yy.c: omicron.l
	flex $<

y.tab.o: y.tab.c
	$(CC) $(CCFLAGS) -o $@ -c $<

lex.yy.o: lex.yy.c
	$(CC) $(CCFLAGS) -o $@ -c $<

omicron: omicron.c
	$(CC) $(CCFLAGS) -o $@ $< lex.yy.c y.tab.c generacion.c

clean:
	rm -f  generacion.o y.tab.c y.tab.h y.output lex.yy.c y.tab.o lex.yy.o omicron
