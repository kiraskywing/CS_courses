#include <stdio.h>
#include <stdbool.h>

void helper(int map[], int row, int n);
bool pos_valid(int map[], int row, int col);

int main(void)
{
    int times;
    scanf("%d", &times);

    while (times--)
    {
        int n;
        scanf("%d", &n);
        int map[n];
        for (int i = 0; i < n; i++)
            map[i] = 0;
        
        helper(map, 0, n);
    }

    return 0;
}

void helper(int map[], int row, int n)
{
    if (row == n)
    {
        for (int i = 0; i < row; i++)
            printf("%d ", map[i] + 1);
        printf("\n");
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (pos_valid(map, row, j))
        {
            map[row] = j;
            helper(map, row + 1, n);
        }
    }
}

bool pos_valid(int map[], int row, int col)
{
    if (row == 0)
        return true;
    else
    {
        for (int i = 0; i < row; i++)
        {
            int x = i, y = map[i];
            if (col == y || (col - y) == (row - x) || (col - y) == (x - row))
                return false;
        }
    }
    return true;
}