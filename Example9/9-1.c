#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int n_cntrl = 0;
int n_space = 0;
int n_digit = 0;
int n_lower = 0;
int n_upper = 0;
int n_punct = 0;
int n_nprint = 0;
int total = 0;

int main()
{
  int ch;

  /*
  ** 读入和处理字符
  */
  while ((ch = getchar()) != EOF)
  {
    total += 1;
    /*
    ** 测试每一个字符，如果为true，则增加关联的计数器
    */
    if (iscntrl(ch)) n_cntrl += 1;
    if (isspace(ch)) n_space += 1;
    if (isdigit(ch)) n_digit += 1;
    if (islower(ch)) n_lower += 1;
    if (isupper(ch)) n_upper += 1;
    if (ispunct(ch)) n_punct += 1;
    if (!isprint(ch)) n_nprint += 1;
  }

  /*
  ** 打印结果
  */
  if (total == 0) printf("No characters in the input!\n");
  else
  {
    printf("%3.0f%% control characters\n", n_cntrl * 100.0 / total);
    printf("%3.0f%% whitespace characters\n", n_cntrl * 100.0 / total);
    printf("%3.0f%% digit characters\n", n_digit * 100.0 / total);
    printf("%3.0f%% lower case characters\n", n_lower * 100.0 / total);
    printf("%3.0f%% upper case characters\n", n_upper * 100.0 / total);
    printf("%3.0f%% puctuation caharacters\n", n_punct * 100.0 / total);
    printf("%3.0f%% non-printable characters\n", n_nprint * 100.0 / total);
  }

  return EXIT_SUCCESS;
}

