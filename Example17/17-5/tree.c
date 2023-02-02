#include "tree.h"
#include <assert.h>
#include <stdio.h>
#include <malloc.h>

static TreeNode* tree;

void print(TREE_TYPE value) {
  printf("%d ", value);
}

void insert(TREE_TYPE value) {
  TreeNode* current;
  TreeNode** link;

  link = &tree;

  while ((current = *link) != NULL) {
    if (value < current->value) {
      link = &current->left;
    }
    else {
      assert(value != current->value);
      link = &current->right;
    }
  }
  current = (TreeNode*)malloc(sizeof(TreeNode));
  assert(current != NULL);
  current->value = value;
  current->left = NULL;
  current->right = NULL;
  *link = current;
}

TREE_TYPE* find(TREE_TYPE value) {
  TreeNode* current;

  current = tree;

  while (current != NULL && current->value != value) {
    if (value < current->value) {
      current = current->left;
    }
    else {
      current = current->right;
    }
  }
  if (current != NULL) {
    return &current->value;
  }
  else {
    return NULL;
  }
}

TreeNode* find_2(TREE_TYPE value) {
  TreeNode* current;

  current = tree;

  while (current != NULL && current->value != value) {
    if (value < current->value) {
      current = current->left;
    }
    else {
      current = current->right;
    }
  }
  return current;
}

void destory_tree(TREE_TYPE value) {
  TreeNode* p = find_2(value);
  if (p) {
    printf("%d ", p->value);
  }
  free(p);
}

static int pre_order_counter_node_number(TreeNode* current, TREE_TYPE* (*callback)(TREE_TYPE value)) {
  int sum = 0;
  if (current) {
    ++sum;
    sum += pre_order_counter_node_number(current->left, callback);
    sum += pre_order_counter_node_number(current->right, callback);
  }
  else {
    return 0;
  }
  return sum;
}

int counter_all_nodes_number(TREE_TYPE* (*callback)(TREE_TYPE value)) {
  return pre_order_counter_node_number(tree, callback);
}

static void do_pre_order_traverse(TreeNode* current, void(*callback)(TREE_TYPE value)) {
  if (current != NULL) {
    callback(current->value);
    do_pre_order_traverse(current->left, callback);
    do_pre_order_traverse(current->right, callback);
  }
}

void pre_order_traverse(void(*callback)(TREE_TYPE value)) {
  do_pre_order_traverse(tree, callback);
}

static void do_in_order_traverse(TreeNode* current, void(*callback)(TREE_TYPE value)) {
  if (current != NULL) {
    do_in_order_traverse(current->left, callback);
    callback(current->value);
    do_in_order_traverse(current->right, callback);
  }
}

void in_order_traverse(void(*callback)(TREE_TYPE value)) {
  do_in_order_traverse(tree, callback);
}

static void do_post_order_traverse(TreeNode* current, void(*callback)(TREE_TYPE value)) {
  if (current != NULL) {
    do_post_order_traverse(current->left, callback);
    do_post_order_traverse(current->right, callback);
    callback(current->value);
  }
}

void post_order_traverse(void(*callback)(TREE_TYPE value)) {
  do_post_order_traverse(tree, callback);
}
