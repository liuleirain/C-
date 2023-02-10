#include "tree.h"
#include "queue.h"
#include <stdio.h>
#include <assert.h>

#define TREE_SIZE 100 /*Max # of values in the trees*/
#define ARRAY_SIZE (TREE_SIZE + 1)

/*用于存储树的所有结点的数组*/
static TREE_TYPE tree[ARRAY_SIZE];

/*
**left_child
**计算一个节点左孩子的下标
*/
static int left_child(int current) {
  return current * 2;
}

/*
** right_child
**计算一个节点右孩子的下标
*/
static int right_child(int current) {
  return current * 2 + 1;
}

/*
**print
**打印节点中的值
*/
void print(TREE_TYPE value) {
  printf("%d ", value);
}

/*
** insert
*/
void insert(TREE_TYPE value) {
  int current;
  /*确保值为非零，因为零用于提示一个未使用的节点*/
  assert(value != 0);

  /*从根节点开始*/
  current = 1;

  /*从合适的子树开始，直到到一个叶节点*/
  while (tree[current] != 0) {
    /*根据情况，进入叶节点或右子树（确信未出现重复的值）*/
    if (value < tree[current]) {
      current = left_child(current);
    }
    else {
      assert(value != tree[current]);
      current = right_child(current);
    }
    assert(current < ARRAY_SIZE);
  }
  tree[current] = value;
}

/*find*/
TREE_TYPE* find(TREE_TYPE value) {
  int current;
  /*从根节点开始。直到找到那个值，进入合适的子树。*/
  current = 1;
  while (current < ARRAY_SIZE && tree[current] != value) {
    /*根据情况，进入左子树或右子树。*/
    if (value < tree[current]) {
      current = left_child(current);
    }
    else {
      current = right_child(current);
    }
  }
  if (current < ARRAY_SIZE) {
    return tree + current;
  }
  else {
    return NULL;
  }
}

/*
**breadth_first_traversal
**对一个数组形式的二叉搜索执行层次遍历。
*/
void breadth_first_traversal(void(*callback)(TREE_TYPE value)) {
  int current;
  int child;

  /*把根节点插入到队列中。*/
  queue_insert(1);

  /*当队列还没有空时*/
  while (!is_queue_empty()) {
    /*从队列中取出第1个值并对它进行处理。*/
    current = queue_first();
    queue_delete();
    callback(tree[current]);

    /*将该节点的所有孩子添加到队列中。*/
    child = left_child(current);
    if (child < ARRAY_SIZE && tree[child] != 0) {
      queue_insert(child);
    }
    child = right_child(current);
    if (child < ARRAY_SIZE && tree[child] != 0) {
      queue_insert(child);
    }
  }
  destroy_queue();
}

/*
**do_pre_order_traverse
**执行一层前序遍历，这个帮助函数用于保存当前正在处理的节点的信息。
**它并不是用户接口的一部分。
*/
static void do_pre_order_traverse(int current, void(*callback)(TREE_TYPE value)) {
  if (current < ARRAY_SIZE && tree[current] != 0) {
    callback(tree[current]);
    do_pre_order_traverse(left_child(current), callback);
    do_pre_order_traverse(right_child(current), callback);
  }
}

/*pre_order_traverse*/
void pre_order_traverse(void(*callback)(TREE_TYPE value)) {
  do_pre_order_traverse(1, callback);
}