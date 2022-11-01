#include <stdio.h>
#include <string.h>
#define SIZE 20

char *my_strcat(char *dst, char const *src);

int main()
{
  char str1[SIZE] = "abcdefghij";
  char str2[SIZE] = "klmnopqrstuvwxyz";
  my_strcat(str1, str2);
  printf("%s\n",str1);
  return 0;
}

char *my_strcat(char *dst, char const *src)
{
  int dst_len = strlen(dst);
  if(dst_len < SIZE)
  {
    int j = 0;
    int i;
    for(i = dst_len; i < SIZE; i++)
    {
      *(dst + i) = *(src + j);
      j++;
    }
    *(dst + SIZE - 1) = '\0';
  }
  return dst;
}