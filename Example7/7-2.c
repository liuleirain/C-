#include <stdio.h>

int gcd(int m , int n);

int main(void){
  int m = 13;
  int n = 26;

  printf("最大公约数为：%d\n", gcd(m, n));

  return 0;
}

int gcd(int m, int n){
  if(m % n == 0) return n;
  else
    {
      if( m  % n > 0){
        return gcd(n, m % n);
      }
      else
        return gcd(m, n % m);
    }
}