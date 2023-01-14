/*
**这个程序为每个指定的输入文件计算校验和。结果要么打印到标准输出，要么打印到文件。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

/*
** 输出选项标志
*/
char file_output = FALSE;

/*
** 函数原型
*/
char** do_args(char**);
unsigned short process(FILE*);
void print(unsigned short, char*);

/*
** 主要功能。解析参数并处理指定的每个文件。
*/
int main(int argc, char** argv) {
  FILE* f; /* 读取的流 */
  unsigned short sum; /* 校验和值 */
  /*
  **处理选项参数。do_args返回一个指向参数列表中第一个文件名的指针。
  */
  argv = do_args(argv);
  /*
  **处理输入文件
  */
  if (*argv == NULL) {
    /*
    **没有给出文件，所以读取标准输入
    */
    if (file_output) {
      fprintf(stderr, "-f illegal with standard input\n");
      exit(EXIT_FAILURE);
    }
    sum = process(stdin);
    print(sum, NULL);
  }
  else {
    /*
    **对于给定的每个文件:打开它，处理其内容，并打印答案
    */
    for (;*argv != NULL; ++argv) {
      f = fopen(*argv, "r");
      if (f == NULL) {
        perror(*argv);
      }
      else {
        sum = process(f);
        if (fclose(f) != 0) {
          perror(*argv);
          exit(EXIT_FAILURE);
        }
        print(sum, *argv);
      }
    }
    return EXIT_SUCCESS;
  }
}

/*
通过逐字读取文件内容并调用适当的求和函数来处理文件。
*/
unsigned short process(FILE* f) {
  unsigned short sum; /* 当前校验和值 */
  int ch; /* 文件中的当前字符 */

  sum = 0;
  while ((ch = getc(f)) != EOF) {
    sum += ch;
  }
  return sum;
}

/*
打印校验和。它要么转到标准输出，要么转到由输入文件名派生的文件名。
*/
void print(unsigned short sum, char* in_name) {
  char* out_name; /* 输出文件名 */
  FILE* f; /* 用于打开输出文件的流 */

  if (!file_output)
    printf("%u\n", sum);
  else {
    /*
    分配空间保存输出文件名。它需要比输入名称长5个字节来保持”。和终止的NUL字节
    */
    out_name = malloc(strlen(in_name) + 5);
    if (out_name == NULL) {
      fprintf(stderr, "malloc: out of memory\n");
      exit(EXIT_FAILURE);
    }
    strcpy(out_name, in_name);
    strcat(out_name, ".cks");

    f = fopen(out_name, "w");
    if (f == NULL)
      perror(out_name);
    else {
      fprintf(f, "%u\n", sum);
      fclose(f);
    }
    free(out_name);
  }
}

/*
处理选项参数。返回指向第一个非选项参数的指针，它是文件名列表的开始
*/
char** do_args(char** argv) {
  /*
  逐个查看每个命令行参数
  */
  while (*++argv != NULL && **argv == '-') {
    /*
    逐个查看每个参数的每个字符
    */
    while (*++ * argv != '\0') {
      /*
      记录下每个给出的选项
      */
      switch (**argv) {
      case 'f':
        file_output = TRUE;
        break;
      default:
        fprintf(stderr, "Illegal option: %c\n", **argv);
        break;
      }
    }
  }
  /*
  返回的值是指向参数列表中选项结束后的位置的指针
  */
  return argv;
}