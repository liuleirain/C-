#include <stdio.h>
#include <ctype.h>


int main(void) {
  int ch;
  while ((ch = getchar()) != EOF) {
    if (islower(ch)) {
      if ((ch + 13) > 'z') {
        putchar((ch + 13) - 26);
      }
      else
        putchar(ch + 13);
    }
    if (isupper(ch)) {
      if ((ch + 13) > 'Z') {
        putchar((ch + 13) - 26);
      }
      else
        putchar(ch + 13);
    }
  }
  return 0;
}