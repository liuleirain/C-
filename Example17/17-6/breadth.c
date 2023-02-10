#include "tree.h"
/*对一个数组形式的二叉数执行层次遍历*/
void breadth_first_traversal(void(*callback)(TREE_TYPE value)) {
  int current;
  int child;

  /*把根节点插入到队列中*/
  queue_insert(1);

  /*当队列还没有空时...*/
  while (!is_queue_empty()) {
    /*从队列中取出第1个值并对它进行处理*/
    current = queue_first();
    queue_delete();
    callback(tree[current]);

    /*将该节点的所有孩子添加到队列中*/
    child = left_child(current);
    if (child < ARRAY_SIZE && tree[child] != 0)
      queue_insert(child);
    child = left_child(current);
    if (child < ARRAY_SIZE && tree[child] != 0)
      queue_insert(child);
  }
}