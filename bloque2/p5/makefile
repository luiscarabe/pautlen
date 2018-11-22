CC = gcc
CCFLAGS = -Wall -g

all:  omicron


# OO


hash_table.o: hash_table.c hash_table.h
	$(CC) $(CCFLAGS) -c $<  -o $@ 


node.o: node.c node.h
	$(CC) $(CCFLAGS) -c $<  -o $@ 


graph.o: graph.c graph.h
	$(CC) $(CCFLAGS) -c $<  -o $@ 


# Procedural

generacion.o: generacion.c generacion.h
	$(CC) $(CCFLAGS) -c $< -o $@

y.tab.c: omicron.y
	bison -dyv $<

lex.yy.c: omicron.l
	flex $<

y.tab.o: y.tab.c y.tab.h
	$(CC) $(CCFLAGS) -o $@ -c $<

lex.yy.o: lex.yy.c 
	$(CC) $(CCFLAGS) -o $@ -c $<

omicron: omicron.c hash_table.o node.o graph.o generacion.o y.tab.c lex.yy.c y.tab.o lex.yy.o
	$(CC) $(CCFLAGS) -o $@  $< lex.yy.o y.tab.o generacion.o graph.o node.o hash_table.o -lm

clean:
	rm -f hash_table.o node.o graph.o
	rm -f  generacion.o y.tab.c y.tab.h y.output lex.yy.c y.tab.o lex.yy.o omicron