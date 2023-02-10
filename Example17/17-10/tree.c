#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
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

/*insert*/
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

  /*从根节点开始，直到找到这个值，计入合适的子树*/
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
**find_3
**查找一个特定值的双亲节点，参数值为儿子节点当前的值作为第1个参数传递给函数。
*/
TreeNode* find_3(TREE_TYPE value) {
  TreeNode* current;
  TreeNode* previous;

  /*从根节点开始，直到找到这个值，进入合适的子树*/
  previous = NULL;
  current = tree;

  while (current != NULL && current->value != value) {
    /*根据情况，进入左子树或右子树*/
    previous = current;
    if (value < current->value) {
      current = current->left;
    }
    else {
      current = current->right;
    }
  }
  return previous;
}

/*
**do_pre_order_traverse
**执行一层前序遍历，这个帮助函数用于保存当前正在处理的节点的信息。
**这个函数并不是用户节后的一部分。
*/
static void do_pre_order_traverse(TreeNode* current, void(*callback)(TREE_TYPE value)) {
  if (current != NULL) {
    callback(current->value);
    do_pre_order_traverse(current->left, callback);
    do_pre_order_traverse(current->right, callback);
  }
}

/*pre_order_traverse*/
void pre_order_traverse(void (*callback)(TREE_TYPE value)) {
  do_pre_order_traverse(tree, callback);
}

/*
**delete_value
**从树中删除一个值，如果需要删除的值并未在树中找到，函数可以终止程序。
*/
void delete_value(TREE_TYPE value) {
  TreeNode* p = find_2(value);
  TreeNode* pre_p = find_3(value);
  TreeNode* left_p;
  TreeNode* right_p;

  if (p) {
    printf("1\n");
    left_p = p->left;
    right_p = p->right;
    if (left_p == NULL && right_p == NULL) {
      if (pre_p->left == p) {
        free(p);
        p = NULL;
        pre_p->left = NULL;
      }
      else {
        free(p);
        p = NULL;
        pre_p->right = NULL;
      }
    }
    else if (left_p == NULL) {
      *p = *right_p;
    }
    else if (right_p == NULL) {
      *p = *left_p;
    }
    else {
      printf("1.2\n");
      TreeNode* left_max_prev;
      TreeNode* left_max;
      TreeNode* left_max_2;
      TreeNode* left_max_left;

      left_max = left_p;
      left_max_prev = left_max;
      left_max_2 = left_max->right;

      while (left_max_2) {
        left_max_prev = left_max;
        left_max_2 = left_max_2->right;
        left_max = left_max->right;
      }
      TREE_TYPE left_max_value;
      left_max_value = left_max->value;
      p->value = left_max_value;
      printf("p->value = %d\n", p->value);
      left_max_left = left_max->left;
      if (left_max_left) {
        *left_max = *left_max_left;
      }
      else {
        if (left_max_prev == left_max) {
          *p = *left_max;
        }
        else {
          free(left_max);
          left_max = NULL;
          left_max_prev->right = left_max;
        }
      }
    }
  }
  else {
    printf("2\n");
    exit(EXIT_SUCCESS);
  }
}

/*从链接二叉搜索树中删除一个节点*/
void delete(TREE_TYPE value) {
  TreeNode* current;
  TreeNode** link;

  /*首先，定位值。它必须存在于树中，否则这个例程将中止程序*/
  link = &tree;

  while ((current = *link) != NULL && value != current->value) {
    if (value < current->value)
      link = &current->left;
    else
      link = &current->right;
  }
  assert(current != NULL);

  /*我们已经找到了价值。看看它有多少个孩子。*/
  if (current->left == NULL && current->right == NULL) {
    /*它是一片叶子;不用担心孩子!*/
    *link = NULL;
    free(current);
  }
  else if (current->left == NULL || current->right == NULL) {
    /*节点只有一个子节点，所以父节点将继承它。*/
    if (current->left != NULL)
      *link = current->left;
    else
      *link = current->right;
    free(current);
  }
  else {
    /*节点有两个子节点!将其值替换为其左子树中最大的值，然后删除该节点。*/
    TreeNode* this_child;
    TreeNode* next_child;

    this_child = current->left;
    next_child = this_child->right;
    while (next_child != NULL) {
      this_child = next_child;
      next_child = this_child->right;
    }
    /*删除子对象并将当前值替换为this_child的值*/
    value = this_child->value;
    delete(value);
    current->value = value;
  }
}