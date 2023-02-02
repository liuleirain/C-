/*一个用链表形式实现的队列，它没有长度限制*/
#include "queue.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*定义一个结构用于保存一个值。link字段将指向队列中的下一个节点。*/
typedef struct QUEUE_NODE {
  QUEUE_TYPE value;
  struct QUEUE_NODE* next;
}QueueNode;

/*指向队列第1个和最后1个节点的指针*/
static QueueNode* front;
static QueueNode* rear;

/*销毁队列*/
void destroy_queue(void) {
  while (!is_empty())
    delete();
}

/*插入队列*/
void insert(QUEUE_TYPE value) {
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

/*删除*/
void delete(void) {
  QueueNode* next_node;
  /*从队列的头部删除一个节点，如果它是最后一个节点，将rear也设置为NULL*/
  assert(!is_empty());
  next_node = front->next;
  free(front);
  front = next_node;
  if (front == NULL)
    rear = NULL;

}

/*首个节点*/
QUEUE_TYPE first(void) {
  assert(!is_empty());
  return front->value;
}

/*是否为空*/
int is_empty(void) {
  return front == NULL;
}

/*是否满*/
int is_full(void) {
  return 0;
}