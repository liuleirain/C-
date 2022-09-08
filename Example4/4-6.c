#include <stdio.h>
#include <stdlib.h>
#define LEN 100

int substr(char dst[], char src[], int start, int len);

int main(void) {
  char dst[LEN];
  char src[LEN] = "\"C and Polying\" Chapter 4 Programming Exercise Answer";

  substr(dst, src, 3, 30);

  printf("Src: %s\n", src);
  printf("Dst: %s\n", dst);

  return 0;
}

int substr(char dst[], char src[], int start, int len) {
  int count = 0;
  int i;
  if (start < 0 || len < 0) {


    dst[count] = '\0';
    return 0;
  }
  for (i = start; i < len; i++) {
    if (src[i]) {

      dst[count++] = src[i];
    }
    else
      dst[count++] = '\0';
  }
  dst[count] = '\0';

  return count;
}