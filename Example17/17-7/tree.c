/*一个使用动态分配的链式结构实现的二叉搜索树*/
#include "tree.h"
#include <assert.h>
#include <stdio.h>
#include <malloc.h>
#include <limits.h>

/*指向树根节点的指针*/
static TreeNode* tree;

/*
**print
**打印数组中的某个值
*/
void print(TREE_TYPE value) {
  printf("%d ", value);
}

/*insert*/
void insert(TREE_TYPE value) {
  TreeNode* current;
  TreeNode** link;

  /*从根节点开始*/
  link = &tree;

  /*持续查找值，进入格式的子树*/
  while ((current = *link) != NULL) {
    /*根据情况，进入左子树或右子树（确认没有出现重复的值）*/
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

  while (current != NULL && current->value) {
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
**查找一个特定值，这个值作为第1个传递给函数
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
**compare_tree_type
**判断值的大小
*/
int compare_tree_type(TREE_TYPE value, TREE_TYPE value2) {
  return value - value2;
}

/*
**judge_binary_search_node(改进方案)
**
*/
int judge_binary_search_node(TreeNode* current, int(*compare)(TREE_TYPE value, TREE_TYPE value2)) {
  TREE_TYPE left_value;
  TREE_TYPE right_value;
  TREE_TYPE value;
  int sum = 0;

  if (current) {
    value = current->value;
    TreeNode* left_next = current->left;
    TreeNode* right_next = current->right;
    if (left_next && right_next) {
      left_value = left_next->value;
      right_value = right_next->value;
      if (compare(value, left_value) > 0 && compare(value, right_value) > 0) {
        sum += judge_binary_search_node(left_next, compare);
        sum += judge_binary_search_node(right_next, compare);
      }
      else {
        ++sum;
      }
    }
    else if (left_next) {
      left_value = left_next->value;
      if (compare(value, left_value) <= 0) {
        ++sum;
      }
      else {
        sum += judge_binary_search_node(left_next, compare);
      }
    }
    else if (right_next) {
      right_value = right_next->value;
      if (compare(right_value, value) <= 0) {
        ++sum;
      }
      else {
        sum += judge_binary_search_node(right_next, compare);
      }
    }
  }
  return sum;
}

/*
**judge_binary_search_tree
**判断该树是否二叉搜索树
*/
int judge_binary_search_tree(int(*compare)(TREE_TYPE value, TREE_TYPE value2)) {
  return judge_binary_search_node(tree, compare);
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
/*改进的方法请看上一节问题20的解答*/

/*
**do_pre_order_traverse
**执行一层前序遍历。这个帮助函数用于保存当前正在处理的节点的信息。
*/
static void do_pre_order_traverse(TreeNode* current, void(*callback)(TREE_TYPE value)) {
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
**pre_order_traverse
**执行一层前序遍历。这个帮助函数用于保存当前正在处理的节点的信息。
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

/*
** 检查一个链接二叉搜索树的有效性
** 这个助手函数使用从调用方传入的最小值和最大值来检查一个节点的有效性
*/
int check_bst_subtree(TreeNode* node, int min, int max) {
  /*空树总是有效的*/
  if (node == NULL)
    return TRUE;

  /*检查该节点的有效性。*/
  if (node->value < min || node->value > max)
    return FALSE;
  /*检查subtress的有效性。*/
  if (!check_bst_subtree(node->left, min, node->value - 1) ||
    !check_bst_subtree(node->right, node->value + 1, max))
    return FALSE;
  return TRUE;
}

/*检查二叉搜索树的有效性。*/
int check_bst_tree() {
  return check_bst_subtree(tree, INT_MIN, INT_MAX);
}