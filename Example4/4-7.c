#include <stdio.h>
#include <stdlib.h>
#define LEN 100

void deblank(char string[]);

int main(void) {
  char st[LEN] = "This  string   is too more    blank.";

  printf("src: %s\n", st);
  deblank(st);
  printf("new: %s\n", st);

  return 0;
}

void deblank(char string[]) {
  int is_blank = 0;
  int i, j;
  for (i = 0; string[i] != '\0'; i++) {
    while (string[i] == ' ' && is_blank == 1) {
      for (j = i; string[j] != '\0'; j++) {
        string[j] = string[j + 1];
      }
      string[j] = '\0';
    }

    if (string[i] == ' ') {
      is_blank = 1;
    }
    else {
      is_blank = 0;
    }
  }
}