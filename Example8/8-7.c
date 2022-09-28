/*
** 从一组下标和维度信息计算数组偏移量
*/
#include <stdio.h>
#include <stdarg.h>
#define reg register

int array_offset2(reg int *arrayinfo, ...)
{
  reg int ndim;
  reg int hi;
  reg int offset;
  reg int lo;
  reg int *sp;
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
    for(offset = 0; offset < ndim; offset += 1)
    {
      s[offset] = va_arg(subscripts, int);
    }
    va_end(subscripts);

    /*
    ** 计算偏移量，从最后一个下标开始，一直后退到第一个下标
    */
    offset = 0;
    arrayinfo += ndim * 2;
    sp = s + ndim;
    while(ndim-- >= 1)
    {
      /*
      ** 得到下一个下标的限制
      */
      hi = *--arrayinfo;
      lo = *--arrayinfo;

      /*
      ** 请注意，没有必要测试hi < lo，因为如果这是真的，
      ** 那么下面的至少一个测试将失败。
      */
      if(*--sp > hi || *sp < lo)
      {
        return -1;
      }

      /*
      ** 计算偏移量
      */
      offset *= hi - lo + 1;
      offset += *sp - lo;
    }
    return offset;
  }
  return -1;
}
