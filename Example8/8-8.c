/*
** 解决八皇后问题
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/*
** 棋盘。如果一个元素为TRUE，那么该方块上有一个皇后;如果FALSE，就没有女王
*/
int board[8][8];

/*
** print_board
**
** 打印出有效的解决方案
*/
void print_board()
{
  int row;
  int column;
  static int n_solutions;

  n_solutions += 1;
  printf("Solution #%d:\n", n_solutions);

  for(row = 0; row < 8; row += 1)
  {
    for(column = 0; column < 8; column += 1)
    {
      if(board[row][column])
      {
        printf(" Q");
      }
      else
      {
        printf(" +");
      }
      putchar('\n');
    }
    putchar('\n');
  }
}

/*
** confilicts
**
** 检查棋盘是否与刚刚放置的皇后发生冲突。注意:因为q是按顺序排列的，
** 所以不需要查看当前行下面的行，因为那里没有q !
*/
int confilicts(int row, int column)
{
  int i;

  for(i = 1; i < 8; i += 1)
  {
    /*
    ** 向上，向左，向右。(不必核对;那几排还没有女王!)
    */
    if(row - i >= 0 && board[row - i][column])
      return TRUE;
    if(column - i >= 0 && board[row][column - i])
      return TRUE;
    if(column + i < 8 && board[row][column + i])
      return TRUE;

    /*
    ** 检查对角线:上和左，上和右。(不必检查;那里还没有女王呢!)
    */
    if(row - i >= 0&& column - i >= 0 && board[row -i][column - i])
      return TRUE;
    if(row - i >= 0 && column + i < 8 && board[row - i][column + i])
      return TRUE;
  }

  /*
  ** 如果我们走到这一步，就没有冲突了
  */
  return FALSE;
}

/*
** place_queen
**
** 尝试在给定行的每一列中放置一个皇后
*/
void place_queen(int row)
{
  int column;

  /*
  ** 逐个尝试每一列
  */
  for(column = 0; column < 8; column += 1)
  {
    board[row][column] = TRUE;

    /*
    ** 看看这个女王是否可以攻击其他任何一个女王(不需要检查第一个女王!)
    */
    if(row == 0 || !confilicts(row, column))
    {
      /*
      ** 没有冲突——如果我们还没有完成，递归地放置下一个皇后。
      ** 如果完成，打印解决方案!
      */
      if(row < 7)
      {
        place_queen(row + 1);
      }
      else
      {
        print_board();
      }

      /*
      ** 把皇后从这个位置移开
      */
      board[row][column] = FALSE;
    }
  }
}

int main()
{
  place_queen(0);
  return EXIT_SUCCESS;
}