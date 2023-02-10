#include "ArrayBinaryTree.h"
#include <assert.h>
#include <stdio.h>

void print(TREE_TYPE value) {
  printf("%d ", value);
}

unsigned long leftChild(unsigned long current) {
  return 2 * current;
}

unsigned long rightChild(unsigned long current) {
  return 2 * current + 1;
}

void insert(TREE_TYPE value) {
  int current = 1;
  while (tree[current] != 0 && current <= TREE_SIZE) {
    if (tree[current] < value) {
      current = 2 * current + 1;
    }
    else if (tree[current] > value) {
      current = 2 * current;
    }
    else {
      return;
    }
  }
  assert(current <= TREE_SIZE);
  tree[current] = value;
}

TREE_TYPE* find(TREE_TYPE value) {
  int current = 1;
  while (tree[current] != 0 && current <= TREE_SIZE) {
    if (tree[current] < value) {
      current = 2 * current + 1;
    }
    else if (tree[current] > value) {
      current = 2 * current;
    }
    else {
      break;
    }
  }
  assert(current <= TREE_SIZE);
  return (tree + current);
}

//前序遍历
void do_pre_order_traverse(unsigned long current) {
  if (tree[current] != 0) {
    printf("%d ", tree[current]);
    do_pre_order_traverse(leftChild(current));
    do_pre_order_traverse(rightChild(current));
  }
}

//需按照current树下面的最大值的树,返回指向该地址的指针
TREE_TYPE* findMax(unsigned long current) {
  assert(tree[current] != 0);
  while (tree[current] != 0) {
    current = rightChild(current);
  }
  return tree + (current / 2);
}

//寻找最小树
TREE_TYPE* findMin(unsigned long current) {
  assert(tree[current] != 0);
  while (tree[current] != 0) {
    current = leftChild(current);
  }
  return tree + (current / 2);
}

//查找左子树最大节点然后替换，然后删除最大节点
void delete(TREE_TYPE value) {
  TREE_TYPE* ptr = find(value);
  TREE_TYPE temp;
  //待删除节点的下标
  unsigned long current = ptr - tree;

  if (tree[leftChild(current)] != 0 && tree[rightChild(current)] != 0) {
    //如果有两个子树，用左子树最大值替换，然后删除最大值树
    TREE_TYPE* leftMax = findMax(leftChild(current));
    temp = *leftMax;
    //删除最大值然后替换
    delete(temp);
    tree[current] = temp;
  }
  else if (tree[leftChild(current)] == 0 && tree[rightChild(current)] == 0) {
    //如果没有子树
    tree[current] = 0;
  }
  else {
    if (tree[leftChild(current)] != 0) {
      //左子树，最大值树删除，替换
      TREE_TYPE* leftMax = findMax(leftChild(current));
      temp = *leftMax;
      //删除最大值然后替换
      delete(temp);
      tree[current] = temp;
    }
    else {
      //只有右子树，右子树最小值替换
      TREE_TYPE* rightMin = findMin(rightChild(current));
      temp = *rightMin;
      delete(temp);
      tree[current] = temp;
    }
  }
}

void delete_2(TREE_TYPE value) {
  int current;
  int left;
  int right;
  int left_subtree_empty;
  int right_subtree_empty;

  /*首先，定位值。它必须存在于树中，否则该例程将中止程序。*/
  current = 1;

  while (tree[current] != value) {
    if (value < tree[current])
      current = left_child(current);
    else
      current = right_child(current);
    assert(current < ARRAY_SIZE);
    assert(tree[current] != 0);
  }

  /*我们已经找到了值。如果它是一个叶子，只需将其设置为0。否则，如果它的左子树不为空，则将该节点的值替换为其左子树的最右(最大)子节点，然后删除该节点。否则，将该值替换为其右子树的最左(最小)子节点，并删除该节点。*/
  left = left_child(current);
  right = right_child(current);
  left_subtree_empty = left > ARRAY_SIZE || tree[left] == 0;
  right_subtree_empty = right > ARRAY_SIZE || tree[right] == 0;

  if (left_subtree_empty && right_subtree_empty)
    /*该值没有子代;简单地把它设为零*/
    tree[current] = 0;
  else {
    int this_child;
    int next_child;

    if (!left_subtree_empty) {
      /*左子树非空。找到它的最右子结点。*/
      this_child = left;
      next_child = right_child(this_child);

      while (next_child < ARRAY_SIZE
        && tree[next_child] != 0) {
        this_child = next_child;
        next_child = right_child(this_child);
      }
    }
    else {
      /*右子树非空。找出它最左边的子结点。*/
      this_child = right;
      next_child = left_child(this_child);

      while (next_child < ARRAY_SIZE
        && tree[next_child] != 0) {
        this_child = next_child;
        next_child = left_child[this_child];
      }
    }

    /*删除子对象并将当前值替换为this_child的值。*/
    value = tree[this_child];
    delete_2(value);
    tree[current] = value;
  }
}