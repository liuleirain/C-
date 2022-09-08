#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a, b, c;

  printf("Enter the triangular three edages:\n ");
  scanf("%d %d %d", &a, &b, &c);
  if (a < 0 || b < 0 || c < 0) {
    printf("The edge length must be greater than 0\n");
    return EXIT_FAILURE;
  }
  int max;
  if (a > b) max = a;
  else max = b;
  if (c > max) {
    if (a + b < c) {

      printf("Can't set up triangles.\n");
      return EXIT_FAILURE;
    }
  }
  else {
    if (a == max) {
      if (b + c < a) {
        printf("Can't set up triangles.\n");
        return EXIT_FAILURE;
      }
    }
    else
      if (a + c < b) {
        printf("Can't set up triangles.\n");
        return EXIT_FAILURE;
      }
  }

  if (a == b || a == c || b == c) {
    printf("Wait for the edge triangle.\n");
  }
  else {
    printf("Don't wait for the edge triangle.\n");
  }

  return 0;
}