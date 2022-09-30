#include <stdio.h>
#include <stdbool.h>

int place[8] = {0};
bool flag[8] = {1,1,1,1,1,1,1,1};
bool d1[15] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
bool d2[15] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int number = 0;

void print();
void gernerate(int n);

int main()
{
  gernerate(0);
  return 0;
}

void gernerate(int n)
{
  int col;
  for(col = 0; col < 8; col++ )
  {
    if(flag[col] && d1[n - col + 7] && d2[n+col])
    {
      place[n] = col;
      flag[col] = false;
      d1[n - col + 7] = false;
      d2[n + col] = false;
      if(n < 7)
        gernerate(n + 1);
      else
        print();

      flag[col] = true;
      d1[n - col + 7] = true;
      d2[n + col] = true;
    }
  }
}

void print()
{
  int col, i, j;
  number++;
  printf("No. %d\n", number);

  int table[8][8] = {0};
  for(col = 0; col < 8; col++)
  {
    table[col][place[col]] = 1;
  }
  for(i = 0; i < 8; i++)
  {
    for(j = 0; j < 8; j++)
    {
      printf("%d ", table[i][j]);
    }
    putchar('\n');
  }
}