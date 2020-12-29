#include <stdio.h>

int main(void)
{
    int r, c, n;
    scanf("%d %d %d", &r, &c, &n);

    int record[100][100] = {0}, bias, x, y;
    
    while (n--)
    {
        scanf("%d %d %d", &bias, &x, &y);
        if (bias > record[x][y])
            record[x][y] = bias;
    }

    int map[100][100] = {0}, x_low, x_high, y_low, y_high, d;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (record[i][j] > 0)
            {
                d = record[i][j] / 2;
                x_low = (i - d >= 0 ? i - d : 0);
                y_low = (j - d >= 0 ? j - d : 0);
                x_high = (i + d < r ? i + d : r - 1);
                y_high = (j + d < c ? j + d : c - 1);

                for (int x = x_low; x <= x_high; x++)
                {
                    for (int y = y_low; y <= y_high; y++)
                        map[x][y] = 1;
                }
            }
        }
    }

    int res = r * c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            res -= map[i][j];
    }
    printf("%d", res);
    
    return 0;
}