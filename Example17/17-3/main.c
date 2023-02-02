#include "queue.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main(void) {
  QUEUE_TYPE values[] = { 1,2,3,4,5 };
  size_t len = sizeof(values) / sizeof(*values);
  size_t i;
  size_t number;

  number = 5;
  for (i = 0; i < number; ++i) {
    insert(values[i]);
  }
  printf("print elements in the queue:\n");
  for (i = 0; i < number; ++i) {
    printf("%d\n", first());
    delete();
  }
  printf("\n");

  destroy_queue();

  return EXIT_SUCCESS;
}