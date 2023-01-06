/*
** 对任意固定长度元素的数组进行排序。调用者将一个指针传递给一个比较两个元素的函数。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
** 相互交换两个元素。
*/
void swap(char* a, char* b, int recsize) {
  char temp;
  while (recsize-- > 0) {
    temp = *a;
    *a++ = *b;
    *b++ = temp;
  }
}

int comp_func(void* a, void* b) {
  char* num1 = (char*)a;
  char* num2 = (char*)b;
  assert(num1 != NULL && num2 != NULL);
  while (*num1 != '\0' && *num2 != '\0') {
    if (*num1 == *num2) {
      num1++;
      num2++;
      continue;
    }
    break;
  }
  return *num1 - *num2;
}

int comp_double(void* a, void* b) {
  double* num1 = (double*)a;
  double* num2 = (double*)b;
  if (*num1 > *num2) {
    return 1;
  }
  else if (*num1 < *num2) {
    return -1;
  }
  else {
    return 0;
  }
}

void sort(void* base, int element_len, int element_size, int (*comp)(void*, void*)) {
  char* pc = (char*)base;
  for (int i = 0; i < element_len - 1; i++) {
    for (int j = i + 1; j < element_len; j++) {
      if (comp((pc + (i * element_size)), (pc + (j * element_size))) > 0) {
        // void* p = malloc(element_size);
        // memcpy(p, pc + (i * element_size), element_size);
        // memcpy(pc + (i * element_size), pc + (j * element_size), element_size);
        // memcpy(pc + (j * element_size), p, element_size);
        // free(p);
        swap((pc + (i * element_size)), (pc + (j * element_size)), element_size);
      }
    }
  }
}

int main() {
  int array[] = { 9, 20, 7, 17 ,2,3,5,32 };
  int array_size = sizeof(array);
  int array_len = array_size / sizeof(*array);
  int array_elem_size = array_size / array_len;
  char str[] = "Hello, World";
  int str_size = sizeof(str);
  int str_len = str_size / sizeof(*str);
  int str_elem_size = str_size / str_len;
  double d_array[] = { 12.1, 22.4, 11.2, 3.4, 5.3 };
  int d_array_size = sizeof(d_array);
  int d_array_len = d_array_size / sizeof(*d_array);
  int d_array_elem_size = d_array_size / d_array_len;

  int (*comp)(void*, void*) = comp_func;

  printf("The original array:\n");
  for (int i = 0; i < array_len; i++) {
    printf("%d ", array[i]);
  }
  putchar('\n');
  sort(array, array_len, array_elem_size, comp);
  printf("After ordering:\n");
  for (int i = 0; i < array_len; i++) {
    printf("%d ", array[i]);
  }
  putchar('\n');

  printf("The original str:\n");
  for (int i = 0; i < str_len; i++) {
    printf("%c ", str[i]);
  }
  putchar('\n');
  sort(str, str_len, str_elem_size, comp);
  printf("After ordering:\n");
  for (int i = 0; i < str_len; i++) {
    printf("%c ", str[i]);
  }
  putchar('\n');

  comp = comp_double;
  printf("The original d_array:\n");
  for (int i = 0; i < d_array_len; i++) {
    printf("%.1f ", d_array[i]);
  }
  putchar('\n');
  sort(d_array, d_array_len, d_array_elem_size, comp);
  printf("After ordering:\n");
  for (int i = 0; i < d_array_len; i++) {
    printf("%.1f ", d_array[i]);
  }
  putchar('\n');




  return 0;
}