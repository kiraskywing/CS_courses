#include <stdio.h>

int count = 1;
int arr[1024][1024];
int target, target_x, target_y;

void helper(int i1, int j1, int i2, int j2);

int main(void)
{
    int n;
    scanf("%d %d", &n, &target);
    int p = 1;
    for (int i = 0; i < n; i++)
        p *= 2;
    
    helper(0, 0, p - 1, p - 1);

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < p; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    printf("%d %d\n", target_x, target_y);

    return 0;
}

void helper(int i1, int j1, int i2, int j2)
{
    if (i1 == i2 && j1 == j2)
    {
        arr[i1][j1] = count;
        if (count == target)
        {
            target_x = i1 + 1;
            target_y = j1 + 1;
        }
        count++;
        return;
    }

    int i_mid = (i1 + i2) / 2, j_mid = (j1 + j2) / 2;
    helper(i1, j1, i_mid, j_mid);
    helper(i1, j_mid + 1, i_mid, j2);
    helper(i_mid + 1, j1, i2, j_mid);
    helper(i_mid + 1, j_mid + 1, i2, j2);
}