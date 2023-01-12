#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 256

int main() {
  int value, total = 0;
  char buf[BUFSIZE];
  FILE* input = fopen("source.txt", "r");
  FILE* output = fopen("target.txt", "w");
  while (fgets(buf, BUFSIZE, input) != NULL) {
    if (sscanf(buf, "%d", &value) == 1) {
      total += value;
    }
  }

  fprintf(output, "%d\n", total);
}