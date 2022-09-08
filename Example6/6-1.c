#include  <stdio.h>
#define LEN 50
char* find_char(char const* source, char const* chars);

int main(void) {
  char src[LEN] = "ABCDEF";
  char chars[LEN] = "DXY";

  if (find_char(src, chars)) {
    puts("Yes.");
  }
  else
    puts("No.");
  return 0;
}

char* find_char(char const* source, char const* chars) {
  const char* src_temp = source;
  const char* chars_temp = chars;
  if (source == NULL || chars == NULL) return NULL;
  while (*src_temp != '\0') {
    chars_temp = chars;
    while (*chars_temp != '\0') {
      if (*chars_temp == *src_temp) {
        printf("0x%p\n", src_temp);
        return (char*)src_temp;
      }
      chars_temp++;
    }
    src_temp++;
  }
  return NULL;

}