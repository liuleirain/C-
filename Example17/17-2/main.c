#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void) {
  QUEUE_TYPE values[] = { 1,2,3,4,5 };
  size_t len = sizeof(values) / sizeof(*values);
  size_t i;
  size_t number;
  create_queue(len + 1);
  for (i = 0; i < len; ++i) {
    insert(values[i]);
  }
  len += 2;
  resize_queue(len + 1);
  for (i = 0; i < 2; i++) {
    while (scanf("%ld", &number) != 1);
    insert(number);
  }
  printf("print elements in the queue:\n");
  for (i = 0; i < len; ++i) {
    printf("%d\n", first());
    delete();
  }
  printf("\n");

  return EXIT_SUCCESS;
}