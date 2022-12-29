/*
** 从标准输入读取一列由EOF结尾的整数并返回一个包含这些值的动态分配的数组。
** 数组的第1个元素是数组所包含的值的数量。
*/
#include <stdio.h>
#include <malloc.h>

#define DELTA 5

int* readints() {
  int* array;
  int size;
  int count;
  int value;

  /*
  ** 获得最初的数组，大小足以容纳DELTA个值。
  */
  size = DELTA;
  array = malloc((size + 1) * sizeof(int));
  if (array == NULL)
    return NULL;

  /*
  ** 从标准输入获得值
  */
  count = 0;
  while (scanf("%d", &value) != EOF) {
    /*
    ** 如果需要，使数组变大，然后存储这个值
    */
    if (-1 == value) break;
    count += 1;
    if (count > size) {
      size += DELTA;
      array = realloc(array, (size + 1) * sizeof(int));
      if (array == NULL) return NULL;
    }
    array[count] = value;
  }
  /*
  ** 改变数组的长度，使其刚刚正好，然后存储计数值并返回这个数组
  ** 这样做绝不会使数组更大，所以它绝不应该失败（但还是应该进行检查！）
  */
  if (count < size) {
    array = realloc(array, (count + 1) * sizeof(int));
    if (array == NULL) return NULL;
  }
  array[0] = count;
  for (int i = 0; i <= count; i++) {
    printf("%d ", array[i]);
    if (i != 0 && i % 10 == 0) putchar('\n');
  }
  return array;
}

int main(int argc, char* argv[]) {
  int* num;
  num = readints();
  free(num);
  return 0;
}