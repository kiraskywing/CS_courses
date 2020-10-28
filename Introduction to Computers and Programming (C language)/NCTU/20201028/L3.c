#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d\n", &m, &n);
    int arr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            arr[i][j] = 1;
    }

    int times, x, y, x_min, x_max, y_min, y_max;
    scanf("%d\n", &times);
    for (int t = 0; t < times; t++)
    {
        scanf("%d %d\n", &x, &y);
        x_min = x - 1 > 0 ? x - 1 : 0;
        x_max = x + 1 < m ? x + 1 : m - 1;
        y_min = y - 1 > 0 ? y - 1 : 0;
        y_max = y + 1 < n ? y + 1 : n - 1;
        for (int i = x_min; i <= x_max; i++)
        {
            for (int j = y_min; j <= y_max; j++)
                arr[i][j] = 0;
        }
    }
    
    int total = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            total += arr[i][j];
    }

    printf("%d", total);
    return 0;
}