
#include <stdio.h>
#include <string.h>
#define LEN 128
int main(void) {
  char previou[LEN];
  char next[LEN];
  int flag = 0;

  gets(previou);
  while (gets(next) != EOF) {

    if (strcmp(previou, next) != 0 && flag == 1)
    {
      printf("%s", previou);
      flag = 0;
    }
    if (strcmp(previou, next) == 0)
      flag = 1;
    else
      flag = 0;
    strcpy(previou, next);
  }


  return 0;
}