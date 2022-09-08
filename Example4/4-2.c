#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int is_prime = 1;
  int i, j;
  for (i = 2; i <= 100; i++) {
    is_prime = 1;
    for (j = 2; j < i; j++) {
      if (i % j == 0) {
        is_prime = 0;
        break;
      }
    }
    if (is_prime) {
      printf("%d\n", i);
    }
  }
  return 0;
}