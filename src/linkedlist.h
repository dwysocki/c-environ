#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct
node
{
    char *key;
    char *contents;
    struct node *next;
} Node;

Node * makenode(char *key, char *contents);
Node * addnode(Node *root, Node *node);
Node * addnew(Node *root, char *key, char *contents);
void display(Node *node);
void displayall(Node *root);
void query(Node *root, char *key);

static void insertbefore(Node *old, Node *new);
static void insertafter(Node *old, Node *new);
static void replace(Node *old, Node *new);

#endif /* LINKEDLIST_H */
