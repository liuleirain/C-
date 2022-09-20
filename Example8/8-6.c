/*
** 从一组下标个维度信息中计算阵列偏移量.
*/
#include <stdio.h>
#include <stdarg.h>

#define reg register

int array_offset(reg int *arrayinfo, ...);

int main(void){
  int res;
  if((res = array_offset([3,4,6,1,5,-3,3], )) != -1)
  printf("Offset: %d\n",res);
  return 0;
}

int array_offset (reg int *arrayinfo, ...){
  reg int ndim;
  reg int offset;
  reg int hi, lo;
  reg int i;
  int s[10];
  va_list subscripts;

  /*
  ** 检查尺寸的数量.
  */
  ndim = *arrayinfo++;
  if(ndim >= 1 && ndim <= 10){
    /*
    ** 将下标值复制到数组.
    */
    va_start(subscripts, arrayinfo);
    for(i = 0; i < ndim; i ++){
      s[i] =va_arg(subscripts, int);
    }
    va_end(subscripts);

    /*
    ** 一次计算偏移一维.
    */
    offset = 0;
    for( i= 0; ndim; ndim--, i++){
      /*
      ** 获得下一个下标的限制.
      */
      lo = *arrayinfo++;
      hi = *arrayinfo++;
      /*
      ** 请注意，没有必要测试hi < lo, 因为如果这是真的， 那么下面的至少一个人物将失败
      */
      if(s[i] < lo || s[i] > hi)
        return -1;
      /*
      ** 计算偏移.
      */
      offset *= hi - lo + 1;
      offset += s[i] - lo;
    }
    return offset;
  }
  return -1;
}
