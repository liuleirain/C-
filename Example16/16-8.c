/*计算家庭成员的平均年龄。每一行输入代表一个家族;它包含所有家庭成员的年龄。*/
#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[512];

  /*每次获取一行输入。*/
  while (fgets(buffer, 512, stdin) != NULL) {
    char* bp;
    int members;
    long sum;
    long age;

    /*一个接一个解码这些年代*/
    sum = 0;
    members = 0;

    bp = buffer;
    while ((age = strtol(bp, &bp, 10)) > 0) {
      members += 1;
      sum += age;
    }
    if (members == 0) continue;

    /*计算平均值并打印结果*/
    printf("%5.2f: %s", (double)sum / members, buffer);
  }

  return 0;
}