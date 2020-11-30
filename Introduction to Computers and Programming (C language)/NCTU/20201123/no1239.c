#include <stdio.h>
#include <stdbool.h>

void helper(int cur_row, int len, int res[]);
bool is_valid(int cur_col, int cur_row, int res[]);

int main(void)
{
    int times;
    scanf("%d", &times);

    while (times--)
    {
        int len;
        scanf("%d", &len);
        int res[len];
        helper(0, len, res);
    }
    
    return 0;
}

void helper(int cur_row, int len, int res[])
{
    if (cur_row == len)
    {
        for (int i = 0; i < len; i++)
            printf("%d ", res[i] + 1);
        printf("\n");
        return;
    }

    for (int cur_col = 0; cur_col < len; cur_col++)
    {
        if (is_valid(cur_col, cur_row, res))
        {
            res[cur_row] = cur_col;
            helper(cur_row + 1, len, res);
        }
    }
}

bool is_valid(int cur_col, int cur_row, int res[])
{
    int pre_col;
    for (int pre_row = 0; pre_row < cur_row; pre_row++)
    {
        pre_col = res[pre_row];
        if (cur_col == pre_col || (cur_col - pre_col) == (cur_row - pre_row) || (cur_col - pre_col) == (pre_row - cur_row))
            return false;
    }
    return true;
}