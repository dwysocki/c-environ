#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

Node *
makenode(char *key, char *contents)
{
  Node *node = (Node *) malloc(sizeof(Node));

  node->key = key; node->contents = contents;

  return node;
}

void
addnode(Node *root, Node *node)
{
  ;
}

void
display(Node *node)
{
  printf("%s -> %s\n", node->key, node->contents);
}

void
displayall(Node *root)
{
  Node *node;
  for(node = root; node != NULL; node = node->next)
    display(node);
}

void
query(Node *root, char *key)
{
  ;
}
