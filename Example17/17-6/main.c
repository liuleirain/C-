#include "tree.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  TREE_TYPE values[] = { 54,36,72,22,41,61,80,16,25,40,51,73 };
  int len;
  int i;

  len = sizeof(values) / sizeof(*values);
  for (i = 0; i < len; ++i) {
    insert(values[i]);
  }

  printf("the sequence of preorder traversal:\n");
  pre_order_traverse(print);
  printf("\n");
  printf("the sequence of level traversal:\n");
  breadth_first_traversal(print);
  printf("\n");

  return EXIT_SUCCESS;
}