/*
** 计算从标准输入的几类字符的百分比
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
** 定义一个函数，判断一个字符是否为打印字符。这可以消除下面代码中这种类型的特殊情况。
*/
int is_not_print(int ch) {
  return !isprint(ch);
}

/*
**用于区别每种类型的分类函数的跳转表
*/
static int(*test_func[])(int) = {
    iscntrl,
    isspace,
    isdigit,
    islower,
    isupper,
    ispunct,
    is_not_print
};
#define N_CATEGORIES\
  (sizeof(test_func) / sizeof(test_func[0]))

/*
** 每种字符类型的名字。
*/
char* label[] = {
  "control",
  "whitespace",
  "digit",
  "lower case",
  "upper case",
  "punctuation",
  "non-printable"
};

/*
**目前见到的每种类型的字符数以及字符的总量。
*/
int count[N_CATEGORIES];
int total;
int main() {
  int ch;
  int category;

  /*
  ** 读取和处理每个字符。
  */
  while ((ch = getchar()) != EOF) {
    total += 1;
    /*
    ** 为这个字符调用每个测试函数。如果为真，增加对应计数器的值。
    */
    for (category = 0; category < N_CATEGORIES; category++) {
      if (test_func[category](ch))
        count[category]++;
    }
  }

  /*
  ** 打印结果。
  */
  if (total == 0) {
    printf("No characters in the input!\n");
  }
  else {
    for (category = 0; category < N_CATEGORIES; category++) {
      printf("%3.0f%% %s characters\n", count[category] * 100.0 / total, label[category]);
    }
  }
  return EXIT_SUCCESS;
}