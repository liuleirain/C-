#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void) {
  TREE_TYPE values[] = { 54,26, 72,22,41,61,80, 16,25,40, 51, 73 };
  int len;
  int i;

  len = sizeof(values) / sizeof(*values);
  for (i = 0; i < len; ++i) {
    insert(values[i]);
  }

  printf("the sequence of preorder traversal:\n");
  pre_order_traverse(print);
  printf("\n");

  printf("the sequence of inorder traversal:\n");
  in_order_traverse(print);
  printf("\n");

  printf("the sequence of postorder traversal:\n");
  post_order_traverse(print);
  printf("\n");

  destroy_tree_2();

  return EXIT_SUCCESS;
}