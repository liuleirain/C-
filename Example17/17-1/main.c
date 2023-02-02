#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  STACK_TYPE values[100];
  size_t i;
  size_t size;
  size_t len;

  printf("Please enter the something:\n");
  scanf("%s", values);
  len = strlen(values);
  create_stack(len);
  for (i = 0; i < len; ++i) {
    push(values[i]);
  }
  printf("Please enter the someting again:\n");
  scanf("%s", values);
  len += strlen(values);
  resize_stack(len);
  for (i = 0; i < strlen(values); i++) {
    push(values[i]);
  }
  printf("print elements in the stack:\n");
  for (i = 0; i < len; ++i) {
    printf("%c ", top());
    pop();
  }
  destroy_stack();
  return EXIT_SUCCESS;
}