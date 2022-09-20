#include <stdio.h>

int ascii_to_integer(char *string);

int main(void){
  char num[50] = "151501";
  printf("Integer is : %d\n",ascii_to_integer(num));
  return 0;
}

int ascii_to_integer(char * string){
  int res = 0;
  char *temp = string;
  while(*temp){
    if(*temp < '0' || *temp > '9') return   0;
    res = res * 10 + (*temp - '0');
    temp++;
  }
  return res;
}