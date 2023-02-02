#include "tree.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

// #define TREE_SIZE 100
// #define ARRAY_SIZE (TREE_SIZE + 1)

static TreeNode* tree;

// static TREE_TYPE tree[ARRAY_SIZE];

// static int left_child(int current) {
//   return current * 2;
// }

// static int right_child(int current) {
//   return current * 2 + 1;
// }

void print(TREE_TYPE value) {
  printf("%d ", value);
}

void insert(TREE_TYPE value) {
  // int current;

  // assert(value != 0);

  // current = 1;

  // while (tree[current] != 0) {
  //   if (value < tree[current]) {
  //     current = left_child(current);
  //   }
  //   else {
  //     assert(value != tree[current]);
  //     current = right_child(current);
  //   }
  //   assert(current < ARRAY_SIZE);
  // }
  // tree[current] = value;
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

void destroy_tree(TREE_TYPE value) {
  TreeNode* p = find_2(value);
  if (p) {
    printf("%d ", p->value);
  }
  free(p);
}

// static void do_pre_order_traverse(int current, void(*callback)(TREE_TYPE value)) {
//   if (current < ARRAY_SIZE && tree[current] != 0) {
//     callback(tree[current]);
//     do_pre_order_traverse(left_child(current), callback);
//     do_pre_order_traverse(right_child(current), callback);
//   }
// }

static void do_pre_order_traverse(TreeNode* current, void(*callback)(TREE_TYPE value)) {
  if (current != NULL) {
    callback(current->value);
    do_pre_order_traverse(current->left, callback);
    do_pre_order_traverse(current->right, callback);
  }
}

void pre_order_traverse(void(*callback)(TREE_TYPE value)) {
  // do_pre_order_traverse(1, callback);
  do_pre_order_traverse(tree, callback);
}

// static void do_in_order_traverse(int current, void(*callback)(TREE_TYPE value)) {
//   if (current < ARRAY_SIZE && tree[current] != 0) {
//     do_in_order_traverse(left_child(current), callback);
//     callback(tree[current]);
//     do_in_order_traverse(right_child(current), callback);
//   }
// }
static void do_in_order_traverse(TreeNode* current, void(*callback)(TREE_TYPE value)) {
  if (current != NULL) {
    do_in_order_traverse(current->left, callback);
    callback(current->value);
    do_in_order_traverse(current->right, callback);
  }
}

void in_order_traverse(void(*callback)(TREE_TYPE value)) {
  // do_in_order_traverse(1, callback);
  do_in_order_traverse(tree, callback);
}

// static void do_post_order_traverse(int current, void (*callback)(TREE_TYPE value)) {
//   if (current < ARRAY_SIZE && tree[current] != 0) {
//     do_post_order_traverse(left_child(current), callback);
//     do_post_order_traverse(right_child(current), callback);
//     callback(tree[current]);
//   }
// }
static void do_post_order_traverse(TreeNode* current, void(*callback)(TREE_TYPE value)) {
  if (current != NULL) {
    do_post_order_traverse(current->left, callback);
    do_post_order_traverse(current->right, callback);
    callback(current->value);
  }
}

void post_order_traverse(void(*callback)(TREE_TYPE value)) {
  // do_post_order_traverse(1, callback);
  do_post_order_traverse(tree, callback);
}

static void destroy_node(TreeNode* node) {
  TreeNode* left_node;
  TreeNode* right_node;
  TREE_TYPE value;

  if (node) {
    left_node = node->left;
    right_node = node->right;
    if (left_node) {
      destroy_node(left_node);
    }
    if (right_node) {
      destroy_node(right_node);
    }
    value = node->value;
    printf("%d ", value);
    free(node);
  }
}

void destroy_tree_2(void) {
  destroy_node(tree);
}