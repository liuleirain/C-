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
  while (*a == *b) {
    a++;
    b++;
  }
  return *a - *b;
}

void print_array(int* ar, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", ar[i]);
  }
  putchar('\n');
}

void insertion_sort2(void* base, size_t n_elements, size_t el_size, int (*compare)(void const* a, void const* b)) {
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
    print_array(base, n_elements);
  }
  free(temp);
}

void insertion_sort(void* base, size_t n_elements, size_t el_size, int(*compare)(void const* x, void const* y)) {
  char* array;
  char* temp;
  int i;
  int next_element;

  /*将基址复制到char*中，这样我们就可以做指针算术了。然后获取一个足以容纳单个元素的临时数组。*/
  array = base;
  temp = malloc(el_size);
  assert(temp != NULL);

  /*数组中的第一个元素已经排序。把剩下的一个一个插入*/
  for (next_element = 1; next_element < n_elements; next_element += 1) {
    char* i_ptr = array;
    char* next_ptr = array + next_element * el_size;

    /*找到插入下一个元素的正确位置*/
    for (i = 0; i < next_element; i++, i_ptr += el_size)
      if (compare(next_ptr, i_ptr) < 0) break;

    /*如果我们一直走到数组排序部分的末尾，那么下一个元素应该在那些已经排序的元素之后。这就是现在的情况，所以我们结束了。*/
    if (i == next_element) continue;

    /*否则，我们必须在I所指向的元素之前插入下一个元素。首先，将下一个元素复制到临时数组中*/
    memcpy(temp, next_ptr, el_size);

    /*现在将元素从I复制到数组排序部分的末尾*/
    memmove(i_ptr + el_size, i_ptr, (next_element - i) * el_size);

    /*最后，插入下一个元素*/
    memcpy(i_ptr, temp, el_size);
    print_array(base, n_elements);
  }
  free(temp);
}

int main(int argc, char** argv) {
  int array[] = { 25,13,6,71,3,2,5,8 };
  int len = sizeof(array) / sizeof(int);
  printf("Source:\t");
  print_array(array, len);
  insertion_sort(array, len, sizeof(int), sort);
  printf("Sort:\t");
  print_array(array, len);
  return 0;
}