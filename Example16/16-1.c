/*对于给定的输入年龄，计算2 - 36范围内年龄显示为小于或等于29的最小基数*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  int age;
  int radix;
  div_t result;

  if (argc != 2) {
    fputs("Usage: age_radix your-age\n", stderr);
    exit(EXIT_FAILURE);
  }

  /*得到年龄的论证*/
  age = atoi(argv[1]);

  /*找到最小的基数*/
  for (radix = 2; radix <= 36; radix++) {
    result = div(age, radix);
    if (result.quot <= 2 && result.rem <= 9)
      break;
  }

  /*打印这个结果*/
  if (radix <= 36) {
    printf("Use radix %d when telling your age; "
      "%d in base %d is %d%d\n",
      radix, age, radix, result.quot, result.rem);
    return EXIT_SUCCESS;
  }
  else {
    printf("Sorry, even in vase 36 your age "
      "is greater than 29!\n");
    return EXIT_FAILURE;
  }
}