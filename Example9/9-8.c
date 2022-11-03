#include <stdio.h>
#include <string.h>

char* my_strnchr(char const* str, int ch, int which);

int main(int argc, char* argv[])
{
  char chs[50] = "abcdefgabcdefgabcdefgabcdefg";
  printf("chs: %p\n", chs);
  char* res = my_strnchr(chs, 'c', 3);
  printf("res: %p\n", res);
  return 0;
}

char* my_strnchr(char const* str, int ch, int which)
{
  char* answer = NULL;
  while (--which >= 0 && (answer = strchr(str, ch)) != NULL)
    str = answer + 1;
  return answer;
}