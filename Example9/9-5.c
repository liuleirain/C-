#include <stdio.h>
#include <string.h>
#define SIZE 20

char *my_strncat(char *dst, char const *src, int size);

int main()
{
  char str1[SIZE] = "abcdefghij";
  char str2[SIZE] = "klmnopqrstuvwxyz";
  my_strncat(str1, str2, 15);
  printf("%s\n",str1);
  return 0;
}

char *my_strncat(char *dst, char const *src, int size)
{
  int dst_len = strlen(dst);
  int length;
  length = size - dst_len;
  if(length > 0)
  {
    int j = 0;
    int i;
    for(i = dst_len; i < size; i++)
    {
      *(dst + i) = *(src + j);
      j++;
    }
    *(dst + i - 1) = '\0';
  }
  return dst;
}