// Definition of a node

typedef struct _Node Node;

Node *newNode(char *name);
Node *cloneNode(Node *node);
void deleteNode(Node *node);
void printNode(Node *node);