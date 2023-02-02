#include "10stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int values[10][5] = {
    {1,1,1,1,1},
    {2,2,2,2},
    {3,3,3,},
    {4,4,4,4,4},
    {5,5,5},
    {6,6,6,6},
    {7,7,7,7,7},
    {8,8,8,8,8},
    {9,9,9,9,9},
    {10,10,10,10},
  };
  size_t i, j;
  for (i = 0; i < 10; i++) {
    create_stack(i, 5);
  }
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 5; j++) {
      push(i, values[i][j]);
    }
  }
  printf("Show stacks:\n");
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 5; j++) {
      if (top(i) != 0) {
        printf("%d ", top(i));
      }
      pop(i);
    }
    putchar('\n');
  }
  for (i = 0; i < 10; i++) {
    destroy_stack(i);
  }
  return EXIT_SUCCESS;
}