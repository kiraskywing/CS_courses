#include <stdio.h>

void fill_map(int map[100][100], int d, int x, int y, int row, int col);

int main(void)
{
    int row, col, n;
    scanf("%d %d %d", &row, &col, &n);

    int map[100][100] = {0}, record[100][100] = {0}, once[100][100] = {0}, twice[100][100] = {0}, thrice[100][100] = {0};
    int d, x, y;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &d, &x, &y);
        record[x][y] = 1;
        if (d > once[x][y])
        {
            thrice[x][y] = twice[x][y];
            twice[x][y] = once[x][y];
            once[x][y] = d;
        }
        else if (d > twice[x][y])
        {
            thrice[x][y] = twice[x][y];
            twice[x][y] = d;
        }
        else if (d > thrice[x][y])
            thrice[x][y] = d;
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (record[i][j] == 1)
            {
                d = once[i][j];
                fill_map(map, d, i, j, row, col);
                d = twice[i][j];
                fill_map(map, d, i, j, row, col);
                d = thrice[i][j];
                fill_map(map, d, i, j, row, col);
            }
        }
    }
    
    int res = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (map[i][j] >= 1 && map[i][j] <= 2)
                res += 1;
        }
    }

    printf("%d\n", res);
    
    return 0;
}

void fill_map(int map[100][100], int d, int x, int y, int row, int col)
{
    if (d == 0)
        return;
    
    int x_low = (x - d / 2 >= 0 ? x - d / 2 : 0);
    int y_low = (y - d / 2 >= 0 ? y - d / 2 : 0);
    int x_high = (x + d / 2 <= row - 1 ? x + d / 2 : row - 1);
    int y_high = (y + d / 2 <= col - 1 ? y + d / 2 : col - 1);
    for (int i = x_low; i <= x_high; i++)
    {
        for (int j = y_low; j <= y_high; j++)
            map[i][j] += 1;
    }
}