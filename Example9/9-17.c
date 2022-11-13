/*
** 通过将数字串中的数字复制到模式字符串中来处理模式字符串，例如IBM 360的“编辑”指令
*/
#include <stdio.h>


#define NUL '\0'

#define DIGIT_SELECTOR '#'
#define SIGNIFICANCE_START '!'

#define TRUE 1
#define FALSE 0

char* edit(char* pattern, char const* digits);

int main()
{
  char pattern[20] = "$#,##!.##";
  char digits[20] = "Hi there";
  char* result;
  result = edit(pattern, digits);
  printf("%s\n", result);
  return 0;
}

char* edit(char* pattern, char const* digits)
{
  int digit;
  int pat_char;
  int fill;
  int significance;
  char* first_digit;
  /*
  ** 检查缺失的数据，并获取填充字符
  */
  if (pattern == NULL || digits == NULL || (fill = *pattern) == '\0') return NULL;
  first_digit = NULL;
  significance = FALSE;
  /*
  ** 一个一个地处理模版字符串
  */
  while ((pat_char = *++pattern) != NUL)
  {
    /*
    ** 看看模式字符有什么含义
    */
    switch (pat_char)
    {
    case DIGIT_SELECTOR:
    case SIGNIFICANCE_START:
      if ((digit = *digits++) == NUL)
      {
        *pattern = NUL;
        return first_digit;
      }

      if (digit == ' ')
      {
        digit = '0';
      }

      if (digit != '0' || pat_char == SIGNIFICANCE_START)
      {
        if (!significance)
          first_digit = pattern;
        significance = TRUE;
      }

      break;
    default:
      digit = pat_char;
      break;
    }
    /*
    ** 在结果中存储适当的字符
    */
    *pattern = significance ? digit : fill;
  }
  return first_digit;
}