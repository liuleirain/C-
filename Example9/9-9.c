#include <stdio.h>
#include <string.h>

int count_chars(char const* str, char const* chars);

int main()
{
  char chs1[50] = "abcdcfgdswefdaewecfgdfweqtrtdsa";
  char chs2[50] = "cfg";
  int res = count_chars(chs1, chs2);
  printf("res: %d\n", res);
  return 0;
}

int count_chars(char const* str, char const* chars)
{
  int count = 0;
  while ((str = strpbrk(str, chars)) != NULL)
  {
    count += 1;
    str++;
  }
  return count;
}