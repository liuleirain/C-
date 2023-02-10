#include <stdio.h>
#ifndef ARRAYBINARYTREE_H
#define ARRAYBINARYTREE_H
#define TREE_SIZE 100
#define ARRAY_SIZE (TREE_SIZE + 1)
typedef int TREE_TYPE;
static TREE_TYPE tree[ARRAY_SIZE] = { 0 };

void print(TREE_TYPE value);
unsigned long leftChild(unsigned long current);
unsigned long rightChild(unsigned long current);
void insert(TREE_TYPE value);
TREE_TYPE* find(TREE_TYPE value);
void do_pre_order_traverse(unsigned long current);
TREE_TYPE* findMax(unsigned long current);
TREE_TYPE* findMin(unsigned long current);
void delete(TREE_TYPE value);

/*从数组二叉搜索树中删除一个节点*/
void delete_2(TREE_TYPE value);
#endif //ARRAYBINARYTREE_H
