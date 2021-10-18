#include <stdio.h>

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    int arr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;
    }

    int times, x, y;
    scanf("%d", &times);
    while (times--)
    {
        scanf("%d %d", &x, &y);
        int i_min = x - 1 >= 0 ? x - 1 : 0;
        int j_min = y - 1 >= 0 ? y - 1 : 0;
        int i_max = x + 1 <= m - 1 ? x + 1 : m - 1;
        int j_max = y + 1 <= n - 1 ? y + 1 : n - 1;
        for (int i = i_min; i <= i_max; i++)
        {
            for (int j = j_min; j <= j_max; j++)
                arr[i][j] = 1;
        }
    }

    int res = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            res += arr[i][j] == 0;
    }
    printf("%d", res);
    
    return 0;
}