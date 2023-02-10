#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  TREE_TYPE values[] = { 54, 36, 72, 22, 41, 61, 80, 16, 25, 40, 51, 73 };
  int len;
  int i;

  len = sizeof(values) / sizeof(*values);
  for (i = 0; i < len; ++i) {
    insert(values[i]);
  }

  printf("The sequence of preorder traversal:\n");
  pre_order_traverse(print);
  printf("\n");

  TREE_TYPE value = 54;
  delete(value);
  printf("The sequence of preorder traversal:\n");
  pre_order_traverse(print);
  printf("\n");
  value = 73;
  delete(value);
  printf("The sequence of preorder traversal:\n");
  pre_order_traverse(print);
  printf("\n");
  value = 80;
  delete(value);
  printf("The sequence of preorder traversal:\n");
  pre_order_traverse(print);
  printf("\n");
  value = 72;
  delete(value);
  printf("The sequence of preorder traversal:\n");
  pre_order_traverse(print);
  printf("\n");

  return EXIT_SUCCESS;
}