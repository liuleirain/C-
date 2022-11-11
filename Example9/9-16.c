#include <stdio.h>
#include <string.h>

char* format(char* format_string, char const* digit_string);

int main()
{

  return 0;
}

char* format(char* format_string, char const* digit_string)
{
  char* format_stringp, * digit_stringp;
  /*
  ** 检查NULL参数
  */
  if (*format_string == NULL || *digit_string == NULL) return;
  /*
  ** 查找两个字符串的末尾，看看数字字符串是否为空
  */
  format_stringp = format_string + strlen(format_string) - 1;
  digit_stringp = digit_string + strlen(digit_string) - 1;
  if (digit_stringp < digit_string) return;

  /*
  ** 继续下去,直到最近模式或数字
  */

}