#include <stdio.h>
#include <string.h>

char *my_strcpy(char *dst, char const *src, int size);

int main()
{
  char chs[100] = "I am student.";
  char res[100];
  my_strcpy(res, chs, strlen(chs) + 1);
  printf("%s\n",res);
  return 0;
}

char *my_strcpy(char *dst, char const *src, int size)
{
  for(int i = 0; i < size; i++)
  {
    *(dst + i) = *(src + i);
  }
  dst[size - 1] = '\0';
  return dst;
}