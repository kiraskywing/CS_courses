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
                count++;
            }
        }
    }

    int x_low, y_low, x_high, y_high;
    for (int k = 0; k < count; k++)
    {
        x_low = (pos[0][k] - 1 >= 0 ? pos[0][k] - 1 : 0);
        y_low = (pos[1][k] - 1 >= 0 ? pos[1][k] - 1 : 0);
        x_high = (pos[0][k] + 1 < m ? pos[0][k] + 1 : m - 1);
        y_high = (pos[1][k] + 1 < n ? pos[1][k] + 1 : n - 1);

        for (int i = x_low; i <= x_high; i++)
        {
            for (int j = y_low; j <= y_high; j++)
                arr[i][j] += 1;
        }
    }

    for (int k = 0; k < count; k++)
        arr[pos[0][k]][pos[1][k]] = -1;
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    return 0;
}