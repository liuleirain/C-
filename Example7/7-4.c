#include <stdio.h>
#include <stdarg.h>

int max_list(int first_arg, ...);

int main(void){
  printf("Max num is: %d\n", max_list(3,22,66,88,77,23,31,52,32,-1));
  return 0;
}

int max_list(int first_arg, ...){
  va_list  var_arg;
  int max = first_arg;

  va_start(var_arg, first_arg);

  int temp = va_arg(var_arg, int);
  do{
    if(temp > max) {
      max = temp;
    }
    temp = va_arg(var_arg,int);
  }while(temp >= 0);

  va_end(var_arg);
  return max;
}