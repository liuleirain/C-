/*通过返回一个范围为1~6的值，模拟掷一个六边的骰子*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*计算将产生骰子值的随机数生成函数所返回的最大数*/
#define MAX_OK_RAND\
  (int)((((long)RAND_MAX+1)/6)*6 - 1)

int throw_die(void) {
  static int is_seeded = 0;
  int value;

  if (!is_seeded) {
    is_seeded = 1;
    srand((unsigned int)time(NULL));
  }

  do {
    value = rand();
  } while (value > MAX_OK_RAND);
  return value % 6 + 1;
}

int main() {
  int res = 0;
  for (int i = 0; i < 1000; i++) {
    res = throw_die();
    printf("%d ", res);
    if ((i + 1) % 20 == 0) putchar('\n');
  }
  return 0;
}