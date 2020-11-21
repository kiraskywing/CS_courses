#include <stdio.h>

int main(void)
{
    int r, c;
    scanf("%d %d", &r, &c);
    
    int arr[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            arr[i][j] = 1;
    }

    int n, x, y, x_low, y_low, x_high, y_high;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d", &x, &y);
        x_low = (x - 1 >= 0 ? x - 1 : 0);
        y_low = (y - 1 >= 0 ? y - 1 : 0);
        x_high = (x + 1 < r ? x + 1 : r - 1);
        y_high = (y + 1 < c ? y + 1 : c - 1);
        
        for (int i = x_low; i <= x_high; i++)
        {
            for (int j = y_low; j <= y_high; j++)
                arr[i][j] = 0;
        }
    }

    int res = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            res += arr[i][j];
    }

    printf("%d", res);

    return 0;
}