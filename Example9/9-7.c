#include <stdio.h>
#include <string.h>

char * my_strrchr(char const *str, int ch);

int main()
{
  char chs[20] = "abcdefg";
  printf("chs: %p\n", chs);
  char *res = my_strrchr(chs, 'f');
  printf("res: %p\n", res);
  return 0;
}

char * my_strrchr(char const *str, int ch)
{
  char *prev_answer = NULL;
  for(;(str = strchr(str, ch)) != NULL; str += 1) prev_answer = str;
  return prev_answer;
}