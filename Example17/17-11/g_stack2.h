/*带有静态数组的堆栈的通用实现。数组大小在堆栈实例化时作为参数之一给出。*/
#include <assert.h>

/*
**interface
**这个宏声明了一个特定类型的堆栈所需的原型和数据类型。对于源文件中使用的每种不同的堆栈类型，它应该被调用一次(每个源文件)。后缀被附加到每个函数名之后;**它必须由用户选择，以便为所使用的每个不同类型提供唯一的名称。
*/
#define GENERIC_STACK_INTERFACE(STACK_TYPE, SUFFIX) \
  typedef struct { \
    STACK_TYPE* stack; \
    int top_element; \
    int stack_size; \
  }STACK##SUFFIX; \
  void push##SUFFIX(STACK##SUFFIX* stack, STACK_TYPE value); \
  void pop##SUFFIX(STACK##SUFFIX* stack); \
  STACK_TYPE top##SUFFIX(STACK##SUFFIX* stack); \
  int is_empty##SUFFIX(STACK##SUFFIX* stack); \
  int is_full##SUFFIX(STACK##SUFFIX* stack); 

/*
**Implementation
**此宏定义了操作特定类型堆栈的函数。对于程序中使用的每种不同堆栈类型，它应该被调用一次(每个整个程序)。后缀必须与接口声明中使用的后缀相同。
*/
#define GENERIC_STACK_IMPLEMENTATION(STACK_TYPE, SUFFIX) \
        \
    void \
    push##SUFFIX(STACK##SUFFIX* stack, STACK_TYPE value) \
    { \
      assert(!is_full##SUFFIX(stack)); \
      stack->top_element += 1; \
      stack->stack[stack->top_element] = value; \
    } \
        \
    void \
    pop##SUFFIX(STACK##SUFFIX* stack) \
    { \
      assert(!is_empty##SUFFIX(stack)); \
      stack->top_element -= 1; \
    } \
      \
    STACK_TYPE top##SUFFIX(STACK##SUFFIX* stack) \
    { \
      assert(!is_empty##SUFFIX(stack)); \
      return stack->stack[stack->top_element]; \
    } \
      \
    int is_empty##SUFFIX(STACK##SUFFIX* stack) \
    { \
      return stack->top_element == -1; \
    } \
      \
    int \
    is_full##SUFFIX(STACK##SUFFIX* stack) \
    { \
      return stack->top_element == stack->stack_size - 1; \
    }

/*
**Stacks
**这个宏创建单个堆栈所需的数据。每个堆栈调用一次。NAME是在后续函数调用中引用堆栈的名称，STACK_SIZE是您希望堆栈的大小。STACK_TYPE是存储在堆栈上的
**数据类型，SUFFIX必须是该STACK_TYPE的接口声明中给出的名称
*/
#define GENERIC_STACK(NAME, STACK_SIZE, STACK_TYPE, SUFFIX) \
    static STACK_TYPE NAME##stack[STACK_SIZE]; \
    STACK##SUFFIX NAME = {NAME##stack, -1, STACK_SIZE};
