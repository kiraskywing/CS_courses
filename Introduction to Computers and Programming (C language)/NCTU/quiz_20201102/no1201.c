#include <stdio.h>

int main(void)
{
    int row, col;
    scanf("%d %d", &row, &col);
    int mat[row][col], pos_x[row * col], pos_y[row * col], count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] == 1)
            {
                pos_x[count] = i;
                pos_y[count] = j;
                count++;
            }
        }
    }

    int x_low, y_low, x_high, y_high;
    for (int i = 0; i < count; i++)
    {
        x_low = (pos_x[i] - 1 >= 0 ? pos_x[i] - 1 : 0);
        y_low = (pos_y[i] - 1 >= 0 ? pos_y[i] - 1 : 0);
        x_high = (pos_x[i] + 1 <= row - 1 ? pos_x[i] + 1 : row - 1);
        y_high = (pos_y[i] + 1 <= col - 1 ? pos_y[i] + 1 : col - 1);

        for (int x = x_low; x <= x_high; x++)
        {
            for (int y = y_low; y <= y_high; y++)
                mat[x][y]++;
        }
    }

    for (int i = 0; i < count; i++)
        mat[pos_x[i]][pos_y[i]] = -1;
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }

    return 0;
}