/*
**在指定的文件中， 查找并打印所有包含指定字符串的文本行
**
**  用法：
**       fgrep string file [file...]
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

void search(char* filename, FILE* stream, char* string) {
  char buffer[BUFFER_SIZE];
  while (fgets(buffer, BUFFER_SIZE, stream) != NULL) {
    if (strstr(buffer, string) != NULL) {
      if (filename != NULL)
        printf("%s:", filename);
      fputs(buffer, stdout);
    }
  }
}

int main(int argc, char** argv) {
  char* string;
  if (argc < 2) {
    fprintf(stderr, "Usage: fgrep string file ...\n");
    exit(EXIT_FAILURE);
  }
  /*
  ** 得到字符串
  */
  string = *++argv;

  /*
  ** 处理文件
  */
  if (argc < 3) {
    search(NULL, stdin, string);
  }
  else {
    while (*++argv != NULL) {
      FILE* stream;
      stream = fopen(*argv, "r");
      if (stream == NULL)
        perror(*argv);
      else {
        search(*argv, stream, string);
        if (fclose(stream) != 0) {
          perror(*argv);
          exit(EXIT_FAILURE);
        }
      }
    }
  }
  return EXIT_SUCCESS;
}