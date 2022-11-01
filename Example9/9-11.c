#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char const whilespace[] = "\n\r\f\t\v";

int main()
{
  char buffer[101];
  int count;

  count = 0;
  /*
  ** 读入文本行，知道发现EOF
  */
  while(gets(buffer))
  {
    char *word;
    /*
    ** 从缓冲去逐个提取单词，直到缓冲区内不再有单词
    */
    for(word = strtok(buffer, whitespace); word != NULL; word = strtok(NULL, whitespace))
    {
      if(strcmp(word, "the") == 0)
        count += 1;
    }
  }
  printf("%d\n", count);
  return EXIT_SUCCESS;
}