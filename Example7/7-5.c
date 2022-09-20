#include <stdio.h>
#include <stdarg.h>

void myprintf(char *string, ...);
void print_integer(int);
void print_float(float);

int main(void){
  myprintf("I am Lily, %d3 years old, I have %f3");
  return 0;
}

void print_integer(int n){
  printf("%d", n);
}

void print_float(float f){
  printf("%f", f);
}

void myprintf(char *string, ...){
  char *p = string;
  va_list var_list; 
  va_start(var_list,string);
  char *q = NULL;

  while(*p != '\0'){
    if(*p == '%'){
      switch(*++p){
        case 'd':
        print_integer(va_arg(var_list,int));
        break;
        case 'f':
        print_float(va_arg(var_list,float));
        break;
        case 'c':
        putchar(va_arg(var_list,int));
        case 's':
        *q = va_arg(var_list, char *);
        while(*q != '\0') putchar(*q++);
        break;
        default:
        break;
      }
    }else{
      putchar(*p);
    }
    p++;
  }
  va_end(var_list);
}