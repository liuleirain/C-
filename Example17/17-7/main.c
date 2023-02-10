#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
  printf("The sequence of postorder traversal:\n");
  post_order_traverse(print);
  printf("\n");

  // int result = judge_binary_search_tree(compare_tree_type);
  int result = check_bst_tree();
  printf("result = %d\n", result);
  if (!result) {
    printf("It is a binary search tree.\n");
  }
  else {
    printf("It is not a binary search tree.\n");
  }

  /*free memory*/
  post_order_traverse(destroy_tree);
  printf("\n");

  TreeNode* tree;
  TreeNode* left_tree;
  TreeNode* right_tree;
  TreeNode* ll_tree;
  TreeNode* lr_tree;
  TreeNode* lll_tree;
  TreeNode* llr_tree;

  tree = (TreeNode*)malloc(sizeof(TreeNode));
  left_tree = (TreeNode*)malloc(sizeof(TreeNode));
  right_tree = (TreeNode*)malloc(sizeof(TreeNode));
  ll_tree = (TreeNode*)malloc(sizeof(TreeNode));
  lr_tree = (TreeNode*)malloc(sizeof(TreeNode));
  lll_tree = (TreeNode*)malloc(sizeof(TreeNode));
  llr_tree = (TreeNode*)malloc(sizeof(TreeNode));

  tree->value = 7;
  left_tree->value = 5;
  right_tree->value = 10;
  ll_tree->value = 120;
  lr_tree->value = 6;
  lll_tree->value = 100;
  llr_tree->value = 4;
  tree->left = left_tree;
  tree->right = right_tree;
  ll_tree->left = ll_tree;
  ll_tree->right = lr_tree;
  right_tree->left = NULL;
  right_tree->right = NULL;
  lll_tree->left = NULL;
  lll_tree->right = NULL;
  llr_tree->left = NULL;
  llr_tree->right = NULL;
  lr_tree->left = NULL;
  lr_tree->right = NULL;
  // result = judge_binary_search_node(tree, compare_tree_type);
  result = check_bst_subtree(tree, INT_MIN, INT_MAX);
  printf("result = %d\n", result);
  if (!result) {
    printf("It is a binary search tree.\n");
  }
  else {
    printf("It is not a binary search tree.\n");
  }
  free(tree);
  free(left_tree);
  free(right_tree);
  free(ll_tree);
  free(lr_tree);
  free(lll_tree);
  free(llr_tree);

  return EXIT_SUCCESS;
}