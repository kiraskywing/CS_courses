#include <stdio.h>

int count = 1, target, target_x, target_y;
int arr[1024][1024];

void helper(int i_start, int j_start, int i_end, int j_end);

int main(void)
{
    int n;
    scanf("%d %d", &n, &target);
    int len = 1;
    while (n--)
        len *= 2;
    
    helper(0, 0, len - 1, len - 1);
    
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("%d %d\n", target_x, target_y);

    return 0;
}

void helper(int i_start, int j_start, int i_end, int j_end)
{
    if (i_start == i_end && j_start == j_end)
    {
        arr[i_start][j_start] = count;
        if (count == target)
        {
            target_x = i_start + 1;
            target_y = j_start + 1;
        }
        count++;
        return;
    }

    int i_mid = (i_start + i_end) / 2, j_mid = (j_start + j_end) / 2;
    helper(i_start, j_start, i_mid, j_mid);
    helper(i_start, j_mid + 1, i_mid, j_end);
    helper(i_mid + 1, j_start, i_end, j_mid);
    helper(i_mid + 1, j_mid + 1, i_end, j_end);
}