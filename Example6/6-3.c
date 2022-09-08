#include <stdio.h>

void reverse_string(char* string);

int main(void) {
  char str[] = "ABCDEFGHIJKLMN";

  printf("Source: %s\n", str);

  reverse_string(str);

  printf("Reverse: %s\n", str);

  return 0;
}

void reverse_string(char* string) {
  char temp;
  char* str_temp = string;
  char* last_str = string;

  while (*last_str != '\0') last_str++;
  last_str--;


  while (last_str > str_temp) {
    temp = *str_temp;
    *str_temp = *last_str;
    *last_str = temp;
    str_temp++;
    last_str--;
  }

}