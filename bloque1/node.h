// Definition of a node

typedef struct _Node Node;

// Node *newNode(char *name, void *content);
Node *newNode(char *name);
int nameCompare(Node *node, char *name);
// void *getContent(Node *node);
void deleteNode(Node *node);
void printNode(Node *node);
char *getName(Node *node);
char **getAttributes(Node *node);
// char **getFunctions(Node *node);
int getNumAttributes(Node *node);
// int getNumFunctions(Node *node);