/*做一个插入排序来排序数组中的元素*/
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

int (*compare)(void const* a, void const* b);

int sort_int(int a, int b) {
  return a - b;
}

int sort(void const* x, void const* y) {
  char* a = (char*)x;
  char* b = (char*)y;
  while (*a != *b) {
    a++;
    b++;
  }
  return *a - *b;
}

void insertion_sort(void* base, size_t n_elements, size_t el_size, int (*compare)(void const* a, void const* b)) {
  char* array = base;
  //存放灵石需要位于的元素
  char* temp = malloc(el_size);
  //已排序的元素下标,从0开始，拿第二个元素和第一个对比
  int sortIdx = 1;
  //元素游标和已排序元素游标
  int idx, idy;
  //位移元素下标
  int mov;
  //从第二位开始，依次拿出元素和之前的已排序元素比较
  for (idx = 1; idx < n_elements; idx++) {
    for (idy = 0; idy < sortIdx; idy++) {
      if (compare(array + idy * el_size, array + idx * el_size) > 0) {
        /*将元素和已排序元素依次比较，当遇到已排序元素，比当前元素大时，当前元素应插入到该已排序
        元素位置，已排序元素应该后移一位位移会覆盖后面的值，所以需要先保存需要插入的值*/
        memcpy(temp, array + idx * el_size, el_size);
        // memmove(array + idy * el_size, array + idx * el_size, idx * el_size);
        for (mov = sortIdx; mov > idy; mov--)
          memmove(array + mov * el_size, array + (mov - 1) * el_size, el_size);
        memcpy(array + idy * el_size, temp, el_size);
      }
    }
    sortIdx++;
  }
  free(temp);
}


int main(int argc, char** argv) {
  int array[] = { 5,3,6,71,3,2,5 };
  int len = sizeof(array) / sizeof(int);
  printf("Source:");
  for (int i = 0; i < len; i++) {
    printf("%d ", array[i]);
  }
  putchar('\n');
  insertion_sort(array, len, sizeof(int), sort);
  printf("Sort:");
  for (int i = 0; i < len; i++) {
    printf("%d ", array[i]);
  }
  putchar('\n');
  return 0;
}