CC = gcc
CCFLAGS = -Wall -g

all: lex.yy.c lex.yy.o pruebaMorfo

lex.yy.c: omicron.l
	flex $<

lex.yy.o: lex.yy.c
	$(CC) $(CCFLAGS) -c $< -o $@

pruebaMorfo: pruebaMorfo.c
	$(CC) $(CCFLAGS) -o $@ $<

clean:
	rm -f lex.yy.o pruebaMorfo lex.yy.c