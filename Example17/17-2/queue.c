/*用动态分配的数组实现的队列。数组大小是在调用create时给出的，这必须在尝试任何其他队列操作之前发生。*/
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*数组，保存队列上的值、队列大小以及指向队列前面和后面的指针。*/
static QUEUE_TYPE* queue;
static size_t queue_size;
static size_t front = 1;
static size_t rear = 0;

/*创建队列*/
void create_queue(size_t size) {
  assert(queue_size == 0);
  queue_size = size;
  queue = (QUEUE_TYPE*)malloc(queue_size * sizeof(QUEUE_TYPE));
  assert(queue != NULL);
}

/*摧毁队列*/
void destroy_queue(void) {
  assert(queue_size > 0);
  queue_size = 0;
  free(queue);
  queue = NULL;
}

/*调整队列*/
void resize_queue(size_t new_size) {
  QUEUE_TYPE* old_queue;
  int i;
  int rear_plus_one;

  /*确保新大小足以容纳队列上已经存在的数据。然后保存指向旧数组的指针，并创建一个大小合适的新数组。*/
  if (front <= rear)
    i = rear - front + 1;
  else
    i = queue_size - front + rear + 1;
  i %= queue_size;
  assert(new_size >= i);
  old_queue = queue;
  queue = (QUEUE_TYPE*)malloc(new_size * sizeof(QUEUE_TYPE));
  assert(queue != NULL);
  queue_size = new_size;

  /*将值从旧数组复制到新数组，然后释放旧内存*/
  i = 0;
  rear_plus_one = (rear + 1) % queue_size;
  while (front != rear_plus_one) {
    queue[i] = old_queue[front];
    front = (front + 1) % queue_size;
    i += 1;
  }
  front = 0;
  rear = (i + queue_size - 1) % queue_size;

  free(old_queue);
}

/*插入*/
void insert(QUEUE_TYPE value) {
  assert(!is_full());
  rear = (rear + 1) % queue_size;
  queue[rear] = value;
}

/*删除*/
void delete(void) {
  assert(!is_empty());
  front = (front + 1) % queue_size;
}

/*第一个*/
QUEUE_TYPE first(void) {
  assert(!is_empty());
  return queue[front];
}

/*是否是空*/
int is_empty(void) {
  assert(queue_size > 0);
  return (rear + 1) % queue_size == front;
}

/*是否满*/
int is_full(void) {
  assert(queue_size > 0);
  return (rear + 2) % queue_size == front;
}