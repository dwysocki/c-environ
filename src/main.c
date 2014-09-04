#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int
main(int argc, char* argv[])
{
  Node *root = NULL;
  root = addnew(root, "a", "Some description of a.");
  root = addnew(root, "A", "Some description of A.");
  root = addnew(root, "B", "Some description of B.");
  root = addnew(root, "D", "Some description of D.");
  root = addnew(root, "C", "Some description of C.");
  root = addnew(root, "b", "Some description of b.");
  root = addnew(root, "b", "New description of b.");
  //  Node *root = makenode("root", "contents");
  //  Node *child = makenode("child", "moar contents");
  //  addnode(root, child);
  //  displayall(root);
  query(root, "b");
}
