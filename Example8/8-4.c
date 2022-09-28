#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define SIZE 10

int identity_matrix(int *matrix, int size);

int main(void)
{
  int matrix[SIZE][SIZE] = 
  {
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  };
  if(identity_matrix(matrix, SIZE))
  {
    puts("Yes!!");
  }else
    puts("No!!");
  return 0;
}

int identity_matrix(int *matrix, int size)
{
  int row;
  int column;

  /*
  ** 通过矩阵的每个元素.
  */
  for(row = 0; row < size; row += 1)
  {
    for(column = 0; column < size; column += 1)
    {
      /*
      ** 如果行号等于列号，则值为1，否则为0
      */
      if(*(matrix++) != (row == column)) return FALSE;
    }
  }
  return TRUE;
}