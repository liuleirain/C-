#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 81/* 80个数据字节加上NUL字节*/

int main() {
  char buf[BUFSIZE];
  while (gets(buf) != NULL)
    puts(buf);
  return EXIT_SUCCESS;
}