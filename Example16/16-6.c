/*根据贷款金额、实际利率及贷款期限，计算每月按揭供款*/
#include <stdio.h>
#include <math.h>

double payment(double amount, double interest, int periods) {
  interest /= 1200;
  periods *= 12;
  amount = amount * interest /
    (1 - pow(1 + interest, (double)(-periods)));
  return floor(amount * 100 + 0.5) / 100;
}

int main() {
  double pay_ment = 0;
  pay_ment = payment(100000, 8, 20);
  printf("月付金额：%.2lf\n", pay_ment);
  return 0;
}