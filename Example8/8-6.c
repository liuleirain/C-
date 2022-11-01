/*
** 从一组下标个维度信息中计算阵列偏移量.
*/
#include <stdio.h>
#include <stdarg.h>

#define reg register

int array_offset(int *arrayinfo, ...);

int main(void)
{

  int array[] = { 3, 4, 6, 1, 5, -3, 3};
  printf("%d\n", array_offset(array,4,1,-3));
  printf("%d\n", array_offset(array,4,1,3));
  printf("%d\n", array_offset(array,5,1,-3));
  printf("%d\n", array_offset(array,4,1,-2));
  printf("%d\n", array_offset(array,4,2,-3));
  printf("%d\n", array_offset(array,6,3,1));
  return 0;
}

int array_offset (int *arrayinfo, ...)
{
  reg int ndim;
  reg int offset;
  reg int hi, lo;
  reg int i;
  int s[10];
  va_list subscripts;

  /*
  ** 检查维度的数量
  */
  ndim = *arrayinfo++;
  if(ndim >= 1 && ndim <= 10)
  {
    /*
    ** 将下标复制到数组
    */
    va_start(subscripts, arrayinfo);
    for(i = 0; i < ndim; i += 1)
    {
      s[i] = va_arg(subscripts, int);
    }
    va_end(subscripts);

    /*
    ** 每次计算一个维度的偏移量
    */
    offset = 0;
    for(i = 0; ndim; ndim--, i++)
    {
      /*
      ** 获取下一个下标的限制
      */
      lo = *arrayinfo++;
      hi = *arrayinfo++;
      /*
      ** 请注意，没有必要测试hi < lo，因为如果这是真的，
      ** 那么下面的至少一个测试将失败。
      */
      if(s[i] < lo || s[i] > hi)
      {
        return -1;
      }
      /*
      ** 计算偏移量
      */
      offset *= hi - lo + 1;
      offset += s[i] - lo;

    }
    return offset;
  }
  return -1;
}
