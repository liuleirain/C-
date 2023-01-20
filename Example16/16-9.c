/*求一个30人班级中两个人生日相同的概率*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

#define TRIALS 10000

int main(int ac, char** av) {
  int n_students = 30;
  int* birthdays;
  int test;
  int match;
  int total_matches = 0;

  /*查看班级中有多少学生(默认为30人)*/
  if (ac > 1) {
    n_students = atoi(av[1]);
    assert(n_students > 0);
  }

  /*为随机数生成器提供种子*/
  srand((unsigned int)time(0));

  /*为学生生日分配一个数组*/
  birthdays = (int*)malloc(n_students * sizeof(int));
  assert(birthdays != NULL);

  /*多次进行测试*/
  for (test = 0; test < TRIALS; test++) {
    int i;

    /*生成生日并检查是否匹配*/
    match = FALSE;
    for (i = 0; i < n_students && !match; i++) {
      /*生成下一个生日*/
      birthdays[i] = rand() % 365;

      /*看看是否和现有的匹配;一找到匹配的就退出*/
      for (int j = 0; !match && j < i; j++) {
        if (birthdays[i] == birthdays[j]) {
          match = TRUE;
          break;
        }
      }
    }
    /*计算结果*/
    if (match)
      total_matches += 1;
  }
  printf("The odds of any two people in a group of %d\n"
    "having the same birthday are %g\n", n_students,
    (double)total_matches / TRIALS);
  free(birthdays);
}