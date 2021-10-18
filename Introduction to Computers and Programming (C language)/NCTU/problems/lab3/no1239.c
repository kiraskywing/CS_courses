#include <stdio.h>
#include <stdbool.h>

void helper(int cols[], int row, int n);
bool valid_pos(int cols[], int row, int col);

int main(void)
{
    int times, n;
    scanf("%d", &times);
    while (times--)
    {
        scanf("%d", &n);
        int cols[n];
        helper(cols, 0, n);
    }
    
    return 0;
}

void helper(int cols[], int row, int n)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
            printf("%d ", cols[i] + 1);
        puts("");
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (valid_pos(cols, row, col))
        {
            cols[row] = col;
            helper(cols, row + 1, n);
        }
    }
}
bool valid_pos(int cols[], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (cols[i] == col || col - cols[i] == row - i || col - cols[i] == i - row)
            return false;
    }
    return true;
}