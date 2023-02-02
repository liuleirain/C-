/*用动态分配的数组实现的堆栈。数组的大小是在调用create时给出的，这必须在尝试任何其他堆栈操作之前发生。*/
#include "10stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

/*模块处理的最大堆栈数。这只能通过重新编译模块来改变*/
#define N_STACKS 11

/*该结构保存了一个堆栈的所有信息:存储值的数组、数组大小和指向最上面值的指针。*/
typedef struct {
  STACK_TYPE* stack;
  size_t size;
  int top_element;
}StackInfo;

/*这是实际的堆栈。*/
StackInfo stacks[N_STACKS];

/*创建堆栈*/
void create_stack(size_t stack, size_t size) {
  assert(stack < N_STACKS);
  assert(stacks[stack].size == 0);
  stacks[stack].size = size;
  stacks[stack].stack = (STACK_TYPE*)malloc(size * sizeof(STACK_TYPE));
  assert(stacks[stack].stack != NULL);
  stacks[stack].top_element = -1;
}

/*销毁堆栈*/
void destroy_stack(size_t stack) {
  assert(stack < N_STACKS);
  assert(stacks[stack].size > 0);
  stacks[stack].size = 0;
  free(stacks[stack].stack);
  stacks[stack].stack = NULL;
}

/*压栈*/
void push(size_t stack, STACK_TYPE value) {
  assert(!is_full(stack));
  stacks[stack].top_element += 1;
  stacks[stack].stack[stacks[stack].top_element] = value;
}

/*出栈*/
void pop(size_t stack) {
  assert(!is_empty(stack));
  stacks[stack].top_element -= 1;
}

/*栈顶*/
STACK_TYPE top(size_t stack) {
  assert(!is_empty(stack));
  return stacks[stack].stack[stacks[stack].top_element];
}

/*是否为空*/
int is_empty(size_t stack) {
  assert(stack < N_STACKS);
  assert(stacks[stack].size > 0);
  return stacks[stack].top_element == -1;
}

/*是否满*/
int is_full(size_t stack) {
  assert(stack < N_STACKS);
  assert(stacks[stack].size > 0);
  return stacks[stack].top_element == stacks[stack].size - 1;
}