/*
** 与库"calloc"功能相同的作业的函数
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void* calloc(size_t n_elements, size_t element_size) {
  char* new_memory;
  n_elements *= element_size;
  new_memory = malloc(n_elements);
  if (new_memory != NULL) {
    char* ptr;
    ptr = new_memory;
    while (--n_elements > 0)
      *ptr++ = '\0';
  }
  else {
    printf("未能创建动态内存！");
  }
  return new_memory;
}

int main() {
  int* array;
  array = calloc(4, sizeof(int));
  // array = (int*)malloc(4 * sizeof(int));
  if (array == NULL) return 0;
  srand((unsigned)time(NULL));
  for (int i = 0; i < 4;i++) {
    array[i] = rand();
  }
  for (int i = 0; i < 4; i++)
  {
    printf("%d\n", array[i]);
  }
  free(array);
  return 0;
}
