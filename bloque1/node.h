// Definition of a node

typedef struct _Node Node;

Node *newNode(char *name, void *content);
int nameCompare(Node *node, char *name);
void *getContent(Node *node);
void deleteNode(Node *node);
void printNode(Node *node);
char *getName(Node *node);