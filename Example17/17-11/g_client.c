/*一个使用泛型堆栈模块创建两个容纳不同类型数据的堆栈的用户程序*/
#include <stdlib.h>
#include <stdio.h>
#include "g_stack.h"

/*创建两个堆栈，一个用于容纳整数，一个用于容纳浮点数。*/
// GENERIC_STACK(int, _int, 10)
// GENERIC_STACK(float, _float, 5)
GENERIC_STACK_DATA(int, _int, 10)
GENERIC_STACK_DATA(float, _float, 10)
GENERIC_STACK_INTERFACE(int, _int)
GENERIC_STACK_INTERFACE(float, _float)

GENERIC_STACK_ACHIEVEMENT(int, _int, 10)
GENERIC_STACK_ACHIEVEMENT(float, _float, 10)

int main() {
  /*往每个堆栈压入几个值*/
  push_int(5);
  push_int(22);
  push_int(15);
  push_float(25.3);
  push_float(-40.5);

  /*清空整数堆栈并打印这些值*/
  while (!is_empty_int()) {
    printf("Poping %d\n", top_int());
    pop_int();
  }

  /*清空浮点数堆栈并打印这些值*/
  while (!is_empty_float()) {
    printf("Poping %f\n", top_float());
    pop_float();
  }

  return EXIT_SUCCESS;
}
