################################################################################
# Makefile con auto-deteccion de dependencias: nunca querras usar otro
# (de tipo .h; las de linkado hay que enumerarlas)
# Ver http://www.cs.washington.edu/orgs/acm/tutorials/dev-in-unix/makefiles.html
################################################################################

# banderas de compilacion (PUEDE SER UTIL CAMBIARLAS)
CC = gcc
#ifdef ENTREGA
CFLAGS = -Wall -g -I .
LDLIBS = -lm 
#else
CFLAGS = -Wall -g -I .
#-DENTREGA
LDLIBS = -lm
#endif

# fuentes a considerar (si no se cambia, todos los '.c' del directorio actual)
SOURCES = $(shell ls -1 *.c* | xargs)

# busca los ejecutables (todos los .c con metodo tipo 'int main')
EXEC_SOURCES = $(shell grep -l "^int main" $(SOURCES) | xargs)

# fich. de dependencia (.d) y nombres de ejecutables (los anteriores, sin '.c')
EXECS = $(shell echo $(EXEC_SOURCES) | sed -e 's:\.c[p]*::g')
DEPS = $(shell echo $(SOURCES) | sed -e 's:\.c[p]*:\.d:g')

all:	graph-test hash-test declararMiembroClase_test declararMiembroInstancia_test usoIdentificadorCualificado_test buscarIdNoCualificado_test buscarParaDeclararIdTablaSimbolosAmbitos_test

graph-test: graph-test.o graph.o node.o hash_table.o

hash-test: hash-test.o hash_table.o

#buscarIdNoCualificado_test declararMiembroClase_test declararMiembroInstancia_test usoIdentificadorCualificado_test

buscarIdNoCualificado_test: buscarIdNoCualificado_test.o graph.o node.o hash_table.o

declararMiembroClase_test: declararMiembroClase_test.o graph.o node.o hash_table.o

declararMiembroInstancia_test: declararMiembroInstancia_test.o graph.o node.o hash_table.o

usoIdentificadorCualificado_test: usoIdentificadorCualificado_test.o graph.o node.o hash_table.o

buscarParaDeclararIdTablaSimbolosAmbitos_test: buscarParaDeclararIdTablaSimbolosAmbitos_test.o graph.o node.o hash_table.o

# receta para hacer un .d (dependencias automaticas de tipo .h para tus .o)
%.d : %.c
	@set -e; $(CC) -MM $(CFLAGS) $< \
	| sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' > $@; \
	[ -s $@ ] || rm -f $@

#incluye las dependencias generadas
-include $(DEPS)

# receta para hacer un .o
%.o :	%.c
	@echo -n compilando objeto \'$<\'...
	@$(CC) $(CFLAGS) $< -c
	@echo [OK]

# receta para hacer un ejecutable (suponiendo resto de dependencias OK)
% :	%.o
	@echo -n compilando ejecutable \'$@\'...
	@$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)
	@echo [OK]

# limpieza
clean:	
	@rm -f $(wildcard *.o *.d core* *.P) $(EXECS)

# ayuda (nunca viene mal)
help:
	@echo "Use: make <target> ..."
	@echo "Valid targets:"
	@$(MAKE) --print-data-base --question | sed -e "s:makefile::g" |\
	awk '/^[^.%][-A-Za-z0-9_]*:/	\
		{ print "   " substr($$1, 1, length($$1)-1) }'
