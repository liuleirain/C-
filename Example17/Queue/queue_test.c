#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void) {
  QUEUE_TYPE values[] = { 1,2,3,4,5 };
  size_t len = sizeof(values) / sizeof(*values);
  size_t i;
  size_t number;

  number = 5;
  for (i = 0; i < number; ++i) {
    insert(values[i]);
  }
  printf("the number of elements in queue is %d\n", count_elem_num());
  printf("print elements in the queue:\n");
  for (i = 0; i < number; ++i) {
    printf("%d\n", first());
    delete();
    printf("remove a element each time, the rest number of elements in queue is %d\n", count_elem_num());
  }
  printf("\n");

  QUEUE_TYPE value;
  value = 5;
  insert(value);
  printf("%d", first());
  delete();

  return EXIT_SUCCESS;
}