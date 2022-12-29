/*
** 读取一个字符串并在动态分配的内存中返回其副本。没有限制（可动态内存的数量除外）
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define DELTA 256

char* readstring() {
  static char* buffer = NULL;
  static int buffer_size = 0;
  int ch;
  int len;
  char* bp;

  bp = buffer;
  len = 0;
  /*
  ** 每次获取一个字符，直到读取换行符或到达EOF
  */
  do {
    ch = getchar();
    if (ch == '\n' || ch == EOF)
      ch = '\0';
    /*
    ** 如果缓冲区已满，则增大缓冲区
    */
    if (len >= buffer_size) {
      buffer_size += DELTA;
      buffer = realloc(buffer, buffer_size);
      assert(buffer != NULL);
      bp = buffer + len;
    }
    *bp++ = ch;
    len += 1;
  } while (ch != '\0');
  /*
  ** 复制要返回的字符串
  */
  bp = malloc(len);
  assert(bp != 0);
  strcpy(bp, buffer);
  return bp;
}

int main() {
  char* str = readstring();
  printf("%s\n", str);
  free(str);
  return 0;
}