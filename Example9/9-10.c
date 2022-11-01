#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int palindrome(char *string);

int main()
{
  char chs[30] = "Madam, I'm Adam";
  if(palindrome(chs)) printf("Yes.\n");
  else printf("No.\n");

  return 0;
}

int palindrome(char *string)
{
  char *string_end; 
  string_end = string + strlen(string) - 1;
  while(TRUE)
  {
    /*
    ** 前进开始指针以跳过任何非字母
    ** 同样后退结束指针
    */
    while(!isalpha(*string)) string++;
    while(!isalpha(*string_end)) string_end--;

    /*
    ** 如果指针已经互相传递，我们就完成了，它是一个回文
    */
    if(string_end <= string) return TRUE;

    /*
    ** 否则，比较字符，看看它们是否匹配。
    ** 在比较之前将它们都转换为小写将使其不区分大小写
    */
    if(tolower(*string) != tolower(*string_end))
      return FALSE;

    /*
    ** 这些字符完成，继续下一个
    */
    string++;
    string_end--;
  }
}
