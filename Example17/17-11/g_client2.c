#include <stdio.h>
#include <stdlib.h>
#include "g_stack2.h"

GENERIC_STACK_INTERFACE(int, _int)
GENERIC_STACK_INTERFACE(float, _float)
GENERIC_STACK_IMPLEMENTATION(int, _int)
GENERIC_STACK_IMPLEMENTATION(float, _float)
GENERIC_STACK(test1, 10, int, _int)
GENERIC_STACK(test2, 10, float, _float)

int main(void) {
  push_int(&test1, 5);
  push_int(&test1, 22);
  push_int(&test1, 25);
  push_float(&test2, 25.3);
  push_float(&test2, -40.3);

  while (!is_empty_int(&test1)) {
    printf("%d\n", top_int(&test1));
    pop_int(&test1);
  }

  while (!is_empty_float(&test2)) {
    printf("%f\n", top_float(&test2));
    pop_float(&test2);
  }

  return EXIT_SUCCESS;
}