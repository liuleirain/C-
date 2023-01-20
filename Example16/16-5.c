/*计算风寒，给定温度(摄氏度)和风速(米/秒)*/
#include <stdio.h>
#include <math.h>

#define A 10.45
#define B 10.00
#define C -1.0
#define X 1.78816

double wind_chill(double temp, double velocity) {
  temp = 33 - temp;
  return 33 - ((A + B * sqrt(velocity) + C * velocity) * temp) /
    (A + B * sqrt(X) + C * X);
}

int main() {
  double windChill = 0;
  windChill = wind_chill(-5, 10);
  printf("Wind chill: %.1lf\n", windChill);
  return 0;
}