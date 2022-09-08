#include <stdio.h>

int del_substr(char* str, char const* substr);

int main(void) {
  char str[20] = "ABCDEFGHIJKLMN";
  char substr[4] = "CDE";

  if (del_substr(str, substr)) {
    printf("%s\n", str);
  }
  else puts("No.");

  return 0;
}

int del_substr(char* str, char const* substr) {
  if (str == NULL || substr == NULL) return 0;

  char* str_temp = str;
  const char* substr_temp = substr;
  char* temp = NULL;
  char ch;

  while (*str_temp != '\0') {
    substr_temp = substr;
    temp = str_temp;
    while (*substr_temp++ == *temp++) {
      if (*substr_temp == '\0') {
        while (*temp != '\0') {
          *str_temp++ = *temp++;
        }
        *str_temp = '\0';
        return 1;
      }
    }
    str_temp++;
  }
  return 0;
}