// Definition of a node

typedef struct _Node Node;

// Node *newNode(char *name, void *content);
Node *newNode(char *name);
Node *newNodeTam(char *name, int tamanio);

int nameCompare(Node *node, char *name);
// void *getContent(Node *node);
void deleteNode(Node *node);
void printNode(Node *node);
char *getName(Node *node);
char **getAttributes(Node *node);
// char **getFunctions(Node *node);
int getNumAttributes(Node *node);
// int getNumFunctions(Node *node);
int abrirAmbitoFunc(Node *node, char * id_clase,
                                char* id_ambito, 
                                int categoria_ambito, 
                                int acceso_metodo, 
                                int tipo_metodo, 
                                int posicion_metodo_sobre, 
                                int tamanio);
int cerrarAmbitoFunc(Node *node);

int insertarTablaSimbolos(Node *node,
		const char* key,            int categoria,  
		int tipo,                   int clase, 
		int direcciones,            int numero_parametros, 
		int posicion_parametro,     int numero_variables_locales, 
		int posicion_variable_local,
		int tamanio,                int numero_atributos_clase, 
		int numero_atributos_instancia, 
		int numero_metodos_sobreescribibles, 
		int numero_metodos_no_sobreescribibles, 
		int tipo_acceso,            int tipo_miembro, 
		int posicion_atributo_instancia, 
		int posicion_metodo_sobreescribible, 
		int num_acumulado_atributos_instancia, 
		int num_acumulado_metodos_sobreescritura, 
		int * tipo_args);

