#include <stdio.h>
#define LEN 20
void copy_n(char dst[], char src[], int n);

int main(void) {
  char src[LEN] = "How old are you!";
  char dst[LEN];

  copy_n(dst, src, 9);

  printf("src: %s\n", src);
  printf("dst: %s\n", dst);
  return 0;
}

void copy_n(char dst[], char src[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    if (src[i]) {
      dst[i] = src[i];
    }
    else
      dst[i] = '\0';
  }
  dst[i] = '\0';
}