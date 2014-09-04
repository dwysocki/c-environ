#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

Node *
makenode(char *key, char *contents)
{
  Node *node = (Node *) malloc(sizeof(Node));

  node->key = key; node->contents = contents;

  return node;
}

void
insertbefore(Node *old, Node *new)
{
  /* store old at a new memory location */
  Node *newold = (Node *) malloc(sizeof(Node));
  memmove(newold, old, sizeof(Node));
  /* store the value of new at the memory location of old */
  memmove(old, new, sizeof(Node));
  /* make new point to the new memory location of old */
  old->next = newold;
}

void
insertafter(Node *old, Node *new)
{
  old->next = new;
}

void
replace(Node *old, Node *new)
{
  old = new;
}

Node *
addnode(Node *root, Node *node)
{
  Node *n;
  int c;
  if (root == NULL)
    return node;
  for(n = root; ; n = n->next) {
    c = strcmp(node->key, n->key);
    if (c < 0)
      insertbefore(n, node);
    else if (c == 0)
      replace(n, node);
    else if (n->next == NULL)
      insertafter(n, node);
    else
      continue;

    return root;
  }
}

Node *
addnew(Node *root, char *key, char *contents)
{
  Node *node = makenode(key, contents);
  return addnode(root, node);
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
  Node *node;
  for(node = root; node != NULL; node = node->next) {
    if (strcmp(node->key, key) == 0) {
      printf("%s\n", node->contents);
      return;
    }
  }
  printf("Key %s not found\n", key);
}
