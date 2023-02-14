#include <stdio.h>
int sum(int a, int b, int c) {
  return a + b + c;
}

int main(void) {
  int a = 1, b = 2, c = 3;
  printf("%d, %d, %d\n", a, b, c);
  return 0;
}