#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int format(char* format_string, char const* digit_string);

int main()
{
  char format_s[50] = "##,###.##";
  char digit[50] = "123";
  if (format(format_s, digit))
  {
    printf("%s\n", format_s);
  }
  return 0;
}

int format(char* format_string, char const* digit_string)
{
  char* format_stringp, * digit_stringp;
  /*
  ** 检查NULL参数
  */
  if (format_string == NULL || digit_string == NULL) return FALSE;
  /*
  ** 查找两个字符串的末尾，看看数字字符串是否为空
  */
  format_stringp = format_string + strlen(format_string) - 1;
  digit_stringp = digit_string + strlen(digit_string) - 1;
  if (digit_stringp < digit_string) return FALSE;

  /*
  ** 继续下去,直到最近模式或数字
  */
  while (format_stringp >= format_string && digit_stringp >= digit_string)
  {
    if (*format_stringp == '#')
    {
      *format_stringp-- = *digit_stringp--;
      continue;
    }
    format_stringp--;
  }
  /*
  ** 如果模式中有更多字符，则用空格替换它们
  */
  while (format_stringp >= format_string)
  {
    if (*format_stringp == '.')
    {
      /*
      ** 把0延伸到点的右边
      */
      char* p0;
      for (p0 = format_stringp + 1; *p0 == ' '; *p0++ = '0');
      /*
      ** 在点的左边加个0
      */
      *--format_stringp = '0';
      --format_stringp;
      continue;
    }
    *format_stringp-- = ' ';
  }
  /*
  ** 如果有数字剩余，这是一个错误
  */
  return digit_stringp < digit_string;
}