/*
** 从一组下标和维度信息计算数组偏移量
*/
#include <stdio.h>
#include <stdarg.h>

int array_offset2(int *arrayinfo, ...)
{
  va_list var_arg;
  int n = arrayinfo[0] * 2;
  int loc = 0;
  int temp_index[10], index = 0;

  va_start(var_arg, arrayinfo);

  while(index < arrayinfo[0])
  {
    temp_index[index++] = va_arg(var_arg, int);
  }

  for(; n > 0; n -= 2)
  {
    // 进行下标检测
    if(temp_index[--index] >= arrayinfo[n - 1] && temp_index[index] <= arrayinfo[n])
    {
      loc *= arrayinfo[n] - arrayinfo[n - 1] + 1;
      loc += temp_index[index] - arrayinfo[n - 1];
    }
    else
    {
      return -1;
    }
  }

  va_end(var_arg);
  return loc;
}

int main(void)
{
  int arrayinfo[] = {3, 4, 6, 1, 5, -3, 3};
  printf("%d\n", array_offset2(arrayinfo,4,1,-3));
  printf("%d\n", array_offset2(arrayinfo,5,1,-3));
  printf("%d\n", array_offset2(arrayinfo,6,1,-3));
  printf("%d\n", array_offset2(arrayinfo,4,2,-3));
  printf("%d\n", array_offset2(arrayinfo,4,3,-3));
  printf("%d\n", array_offset2(arrayinfo,4,1,-2));
  printf("%d\n", array_offset2(arrayinfo,4,1,-1));
  printf("%d\n", array_offset2(arrayinfo,5,3,-1));
  printf("%d\n", array_offset2(arrayinfo,6,5,3));

  return 0;
}