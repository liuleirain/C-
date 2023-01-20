/*像小孩子一样说出现在的时间*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t now;
  struct tm* tm;
  int hour;
  int minute;

  /*获得当前的小时和分钟*/
  now = time(NULL);
  tm = localtime(&now);
  hour = tm->tm_hour;
  minute = tm->tm_min;

  /*四舍五入并规范化小时，转换分钟，然后打印它们*/
  if (minute >= 30)
    hour += 1;
  hour %= 12;
  if (hour == 0)
    hour = 12;
  minute += 2;
  minute /= 5;
  if (minute == 0)
    minute = 12;

  printf("The big gand is on the %d, and the little hand is on the %d.\n", minute, hour);

  return EXIT_SUCCESS;
}