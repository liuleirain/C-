#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void) {
  TREE_TYPE values[] = { 54, 36, 72, 22, 41, 61, 80, 16, 25, 40, 51, 73 };
  int len;
  int i;

  len = sizeof(values) / sizeof(*values);
  for (i = 0; i < len;++i) {
    insert(values[i]);
  }

  printf("The sequence of preorder traversal:\n");
  pre_order_traverse(print);
  printf("\n");

  int number;
  number = counter_all_nodes_number(find);
  printf("number = %d\n", number);
  post_order_traverse(destroy_tree);

  return EXIT_SUCCESS;
}