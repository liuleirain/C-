#include <stdio.h>
#include <string.h>

char *my_strcpy_end(char *dst, char const *src);

int main()
{
  char dst[20] = "abcdefg";
  char src[20] = "hijklmn";
  char *end = my_strcpy_end(dst, src);
  printf("dst: %p\n",dst);
  printf("end: %p\n",end);
  return 0;
}

char *my_strcpy_end(char *dst, char const *src)
{
  while((*dst++ = *src++) != '\0');
  return dst - 1;
}