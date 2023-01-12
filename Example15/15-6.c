#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int palindrome(char* string) {
  int s_len = strlen(string);
  int res = 1;
  for (int i = 0; i < s_len / 2; i++) {
    if (string[i] != string[s_len - i - 1]) return 0;
  }
  return res;
}

int numeric_palindrome(int value) {
  char string[50];
  sprintf(string, "%d", value);
  return palindrome(string);
}

int main() {
  int n;
  printf("输入一个正整数：\n");
  scanf("%d", &n);
  if (numeric_palindrome(n)) printf("是回文数！\n");
  else printf("不是回文数!\n");
  return EXIT_SUCCESS;
}