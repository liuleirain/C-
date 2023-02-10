#include "tree.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

/*指向树根节点的指针*/
static TreeNode* tree;

/*
**print
**打印数组中的某个值
*/
void print(TREE_TYPE value) {
  printf("%d ", value);
}

/*
**insert
*/
void insert(TREE_TYPE value) {
  TreeNode* current;
  TreeNode** link;

  /*从根节点开始*/
  link = &tree;
  /*持续查找值，进入合适的子树*/
  while ((current = *link) != NULL) {
    /*根据情况，进入左子树或右子树*/
    if (value < current->value) {
      link = &current->left;
    }
    else {
      assert(value != current->value);
      link = &current->right;
    }
  }

  /*分配一个新节点，使适当节点的link字段指向它*/
  current = (TreeNode*)malloc(sizeof(TreeNode));
  assert(current != NULL);
  current->value = value;
  current->left = NULL;
  current->right = NULL;
  *link = current;
}

/*find*/
TREE_TYPE* find(TREE_TYPE value) {
  TreeNode* current;
  /*从根节点开始，直到找到这个值，进入合适的子树*/
  current = tree;

  while (current != NULL && current->value != value) {
    /*根据情况，进入左子树或右子树*/
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

/*
**find_2
**查找一个特定值，这个值作为第1个参数传递给函数
*/
TreeNode* find_2(TREE_TYPE value) {
  TreeNode* current;

  /*从根节点开始，直到找到这个值，进入合适的子树*/
  current = tree;

  while (current != NULL && current->value != value) {
    /*根据情况，进入左子树或右子树*/
    if (value < current->value) {
      current = current->left;
    }
    else {
      current = current->right;
    }
  }
  return current;
}

/*
**destroy_tree
**删除树中单个的节点
*/
void destroy_tree(TREE_TYPE value) {
  TreeNode* p = find_2(value);
  if (p) {
    printf("%d ", p->value);
  }
  free(p);
}

/*
**do_pre_order_traverse
**执行一层前序遍历。这个帮助函数用于保存当前梳理的节点的信息。
**这个函数并不是用户接口的一部分
*/
static void do_pre_order_traverse(TreeNode* current, void (*callback)(TREE_TYPE value)) {
  if (current != NULL) {
    callback(current->value);
    do_pre_order_traverse(current->left, callback);
    do_pre_order_traverse(current->right, callback);
  }
}

/*pre_order_traverse*/
void pre_order_traverse(void(*callback)(TREE_TYPE value)) {
  do_pre_order_traverse(tree, callback);
}

/*
**do_in_order_traverse
**执行一层中序遍历。这个帮助函数用于保存当前梳理的节点的信息。
**这个函数并不是用户接口的一部分
*/
static void do_in_order_traverse(TreeNode* current, void(*callback)(TREE_TYPE value)) {
  if (current != NULL) {
    do_in_order_traverse(current->left, callback);
    callback(current->value);
    do_in_order_traverse(current->right, callback);
  }
}

/*in_order_traverse*/
void in_order_traverse(void(*callback)(TREE_TYPE value)) {
  do_in_order_traverse(tree, callback);
}

/*
**do_post_order_traverse
**执行一层后序遍历。这个帮助函数用于保存当前梳理的节点的信息。
**这个函数并不是用户接口的一部分
*/
static void do_post_order_traverse(TreeNode* current, void(*callback)(TREE_TYPE value)) {
  if (current != NULL) {
    do_post_order_traverse(current->left, callback);
    do_post_order_traverse(current->right, callback);
    callback(current->value);
  }
}

/*post_order_traverse*/
void post_order_traverse(void(*callback)(TREE_TYPE value)) {
  do_post_order_traverse(tree, callback);
}

/*做一层后序遍历摧毁树。这个helper函数用于保存当前正在处理的节点的信息;这不是客户端接口的一部分。*/
static void do_destroy_tree(TreeNode* current) {
  if (current != NULL) {
    do_destroy_tree(current->left);
    do_destroy_tree(current->right);
    free(current);
  }
}

/*销毁整个树*/
void destroy_tree_2() {
  do_destroy_tree(tree);
}