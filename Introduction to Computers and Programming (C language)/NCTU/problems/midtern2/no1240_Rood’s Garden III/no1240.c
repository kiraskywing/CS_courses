#include <stdio.h>

int main(void)
{
    int m, n, times, shift, x, y;
    scanf("%d %d %d", &m, &n, &times);
    int arr[m][n], s[m][n][3];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            arr[i][j] = s[i][j][0] = s[i][j][1] = s[i][j][2] = 0;
    }

    while (times--)
    {
        scanf("%d %d %d", &shift, &x, &y);
        if (shift > s[x][y][0])
        {
            s[x][y][2] = s[x][y][1];
            s[x][y][1] = s[x][y][0];
            s[x][y][0] = shift;
        }
        else if (shift > s[x][y][1])
        {
            s[x][y][2] = s[x][y][1];
            s[x][y][1] = shift;
        }
        else if (shift > s[x][y][2])
            s[x][y][2] = shift;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (s[i][j][k])
                {
                    int d = s[i][j][k] / 2;
                    int x_min = i - d >= 0 ? i - d : 0;
                    int y_min = j - d >= 0 ? j - d : 0;
                    int x_max = i + d < m ? i + d : m - 1;
                    int y_max = j + d < n ? j + d : n - 1;
                    for (int x = x_min; x <= x_max; x++)
                    {
                        for (int y = y_min; y <= y_max; y++)
                            arr[x][y]++;
                    }
                }
            }
        }
    }

    int res = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            res += arr[i][j] >= 1 && arr[i][j] <= 2;
    }

    printf("%d", res);
    
    return 0;
}

