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
void addnode(Node *root, Node *node);
void display(Node *node);
void displayall(Node *root);
void query(Node *root, char *key);

#endif /* LINKEDLIST_H */
