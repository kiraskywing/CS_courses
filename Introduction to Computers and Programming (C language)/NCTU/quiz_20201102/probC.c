#include <stdio.h>

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    int arr[m][n], pos[2][m * n], count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 1)
            {
                pos[0][count] = i;
                pos[1][count] = j;
                count += 1;
            }
        }
    }

    int x_low, x_high, y_low, y_high;
    for (int i = 0; i < count; i++)
    {
        x_low = (pos[0][i] - 1 >= 0 ? pos[0][i] - 1 : 0);
        x_high = (pos[0][i] + 1 <= m - 1 ? pos[0][i] + 1 : m - 1);
        y_low = (pos[1][i] - 1 >= 0 ? pos[1][i] - 1 : 0);
        y_high = (pos[1][i] + 1 <= n - 1 ? pos[1][i] + 1 : n - 1);
        
        for (int x = x_low; x <= x_high; x++)
        {
            for (int y = y_low; y <= y_high; y++)
                arr[x][y] += 1;
        }
    }
    for (int i = 0; i < count; i++)
        arr[pos[0][i]][pos[1][i]] = -1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    
    return 0;
}