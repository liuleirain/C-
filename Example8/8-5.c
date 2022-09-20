#include <stdio.h>

/*
** 将两个矩阵相乘
*/
void matrix_mutiply(int *m1, int *m2, register int *r, int x, int y, int z);

int main(void){
  return 0;
}

void matrix_mutiply(int *m1, int *m2, register int *r, int x, int y, int z){
  register int *m1p;
  register int *m2p;
  register int k;
  int row;
  int column;


  /*
  ** 外层的两个循环逐个产生结果矩阵的元素，由于这是按照存在顺序进行的，
  ** 因此可以通过对r进行间接访问来访问这些元素。
  */
  for(row = 0; row < x; row += 1){
    for(column = 0; column < z; column += 1){
      /*
      ** 计算结果的一个值。 这是通过获得指向m1和m2的合适元素的指针，
      ** 在进行循环时， 使它们前进来实现的。
      */
      m1p = m1 + row * y;
      m2p = m2 + column;
      *r = 0;

      for( k = 0; k < y; k += 1){
        *r += *m1p * *m2p;
        m1p += 1;
        m2p += z;
      }

      /*
      ** r前进一步，指向下一个元素。
      */
      r++;
    }
  }
}