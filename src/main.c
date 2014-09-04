#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int
main(int argc, char* argv[])
{
  Node *root = makenode("root", "contents");
  Node *child = makenode("child", "moar contents");
  root->next = child;
  displayall(root);
}
