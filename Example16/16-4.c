/*从命令行读取月、日和年，并确定该日期的星期几。*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* month[] = { "January", "February", "March", "April", "May" ,"June","July","August", "September", "October", "November","December" };

char* day[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

int main(int argc, char** argv) {
  struct tm tm;
  if (argc != 4) {
    fputs("Usage: day_of_seek month day year\n", stderr);
    exit(EXIT_FAILURE);
  }

  /*将参数存储在struct tm变量中*/
  tm.tm_sec = 0;
  tm.tm_min = 0;
  tm.tm_hour = 12;
  tm.tm_mday = atoi(argv[2]);
  tm.tm_mon = atoi(argv[1]) - 1;
  tm.tm_year = atoi(argv[3]) - 1900;
  tm.tm_isdst = 0;

  /*规范化它，然后打印答案*/
  mktime(&tm);
  printf("%s %d, %d is a %s\n", month[tm.tm_mon], tm.tm_mday, tm.tm_year + 1900, day[tm.tm_wday]);
  return EXIT_SUCCESS;
}