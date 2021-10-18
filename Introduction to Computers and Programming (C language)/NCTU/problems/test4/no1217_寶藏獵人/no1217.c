#include <stdio.h>

void helper(int *arr, int i1, int j1, int i2, int j2, int n, int *cur, int *x, int *y, int target);

int main(void)
{
    int n, target, len = 1;
    scanf("%d %d", &n, &target);
    while (n--)
        len *= 2;
    
    int arr[len][len], cur = 1, x, y;
    helper(&arr[0][0], 0, 0, len - 1, len - 1, len, &cur, &x, &y, target);

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
            printf("%d ", arr[i][j]);
        puts("");
    }
    printf("%d %d\n", x, y);
    
    return 0;
}

void helper(int *arr, int i1, int j1, int i2, int j2, int n, int *cur, int *x, int *y, int target)
{
    if (i1 == i2 && j1 == j2)
    {
        if (*cur == target)
        {
            *x = i2 + 1;
            *y = j2 + 1;
        }
        *(arr + i2 * n + j2) = (*cur)++;
        return;
    }

    int i_mid = (i1 + i2) / 2, j_mid = (j1 + j2) / 2;
    helper(arr, i1, j1, i_mid, j_mid, n, cur, x, y, target);
    helper(arr, i1, j_mid + 1, i_mid, j2, n, cur, x, y, target);
    helper(arr, i_mid + 1, j1, i2, j_mid, n, cur, x, y, target);
    helper(arr, i_mid + 1, j_mid + 1, i2, j2, n, cur, x, y, target);
}