#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*定义一个结构用于保存一个值，link字段将指向队列中的下一个节点*/
typedef struct QUEUE_NODE {
  QUEUE_TYPE value;
  struct QUEUE_NODE* next;
}QueueNode;

/*指向队列的第1个和最后一个节点的指针*/
static QueueNode* front;
static QueueNode* rear;

/*destroy_queue*/
void destroy_queue(void) {
  while (!is_queue_empty) {
    queue_delete();
  }
}

/*queue_insert*/
void queue_insert(QUEUE_TYPE value) {
  QueueNode* new_node;
  /*分配一个新节点，并填充它的各个字段*/
  new_node = (QueueNode*)malloc(sizeof(QueueNode));
  assert(new_node != NULL);
  new_node->value = value;
  new_node->next = NULL;
  /*把它插入到队列的尾部*/
  if (rear == NULL) {
    front = new_node;
  }
  else {
    rear->next = new_node;
  }
  rear = new_node;
}

/*queue_delete*/
void queue_delete(void) {
  QueueNode* next_node;
  /*将队列的头部删除一个节点，如果它是最后1个节点
  将rear也设置为NULL
  */
  assert(!is_queue_empty());
  next_node = front->next;
  free(front);
  front = next_node;
  if (front == NULL) {
    rear = NULL;
  }
}

/*queue_first*/
QUEUE_TYPE queue_first(void) {
  assert(!is_queue_empty());
  return front->value;
}

/*is_queue_empty*/
int is_queue_empty(void) {
  return front == NULL;
}

/*is_queue_full*/
int is_queue_full(void) {
  return 0;
}