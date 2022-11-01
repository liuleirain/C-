#include <stdio.h>

int my_strlen(const char *str);

int main()
{
  char chs[100] = "How are you!";
  int n = my_strlen(chs);
  printf("%d\n", n);
  return 0;
}

int my_strlen(const char *str)
{
  int res = 0;
  for(int i = 0; *(str + i) != '\0'; i++)
  {
    res += 1;
  }
  return res;
} 