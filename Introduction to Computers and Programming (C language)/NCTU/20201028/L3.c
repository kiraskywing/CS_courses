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

    int times, x, y;
    scanf("%d\n", &times);
    for (int t = 0; t < times; t++)
    {
        scanf("%d %d\n", &x, &y);
        for (int i = (x - 1 > 0 ? x - 1 : 0); i <= (x + 1 < m ? x + 1 : m - 1); i++)
        {
            for (int j = (y - 1 > 0 ? y - 1 : 0); j <= (y + 1 < n ? y + 1 : n - 1); j++)
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