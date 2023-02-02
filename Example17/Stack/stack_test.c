#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  int ch;
  int counter;

  counter = 0;
  printf("input name you want:\n");
  while ((ch = getchar()) != EOF) {
    push(ch);
    counter++;
  }
  printf("print name you input:");
  while (--counter >= 0) {
    ch = top();
    putchar(ch);
    pop();
  }
  putchar('\n');
  return EXIT_SUCCESS;
}