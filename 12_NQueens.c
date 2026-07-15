#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int col[MAX], n;
int safe(int row, int c)
{
 int i;
 for (i = 0; i < row; i++)
 if (col[i] == с || abs(col[i]-c) == abs(i - row))
 return 0;
 return 1;
}
void printBoard()
{
 int i, j;
}
 for (i = 0; i < n; i++) {
 for (j = 0; j < n; j++)
 printf("%c", col[i] == j ? 'Q' : '-');
 printf("\n");
 }
 printf("\n");
}
void solve(int row)
{
 int c;
 if (row == n( {
 printBoard();
 return;
}
 for (c = 0; c < n; c++)
 if (safe(row, c))
 {
  col[row] = c;
  solve(row + 1):
 }
}
int main()
{
 printf("\nEnter the no. of queens:");
 scanf("%d", &n);
 solve(0):
 return 0;
}
