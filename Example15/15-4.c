#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 256

FILE* openfile(char* prompt, char* mode) {
  char buf[BUFSIZE];
  FILE* file;

  printf("%s filename? ", prompt);
  if (gets(buf) == NULL) {
    fprintf(stderr, "Missing %s file name.\n", prompt);
    exit(EXIT_FAILURE);
  }
  if ((file = fopen(buf, mode)) == NULL) {
    perror(buf);
    exit(EXIT_FAILURE);
  }

  return file;
}

int main() {
  FILE* sfp;
  FILE* tfp;

  sfp = openfile("source", "r");
  tfp = openfile("target", "w");

  char str[BUFSIZE];
  while (fgets(str, BUFSIZE, sfp) != NULL)
  {
    fputs(str, tfp);
  }

  if (fclose(sfp) != 0) {
    perror("source close error.");
    exit(EXIT_FAILURE);
  }
  if (fclose(tfp) != 0) {
    perror("target close error.");
    exit(EXIT_FAILURE);
  };

  return EXIT_SUCCESS;
}