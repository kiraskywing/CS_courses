#include <stdio.h>

int power(int n);
int map[1024][1024];
void helper(int i1, int j1, int i2, int j2, int target);
int x, y, count = 1;

int main(void)
{
    int n, target;
    scanf("%d %d", &n, &target);
    int w = power(n);
    helper(0, 0, w - 1, w - 1, target);
    
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < w; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
    printf("%d %d", x, y);

    return 0;
}

int power(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 2;
    
    int res = power(n / 2) * power(n / 2);
    if (n % 2 != 0)
        res *= 2;

    return res;
}

void helper(int i1, int j1, int i2, int j2, int target)
{
    if (i1 == i2 && j1 == j2)
    {
        map[i1][j1] = count;
        if (count == target)
        {
            x = i1 + 1;
            y = j1 + 1;
        }
        count++;
        return;
    }
    
    int i_mid = (i1 + i2) / 2, j_mid = (j1 + j2) / 2;
    helper(i1, j1, i_mid, j_mid, target);
    helper(i1, j_mid + 1, i_mid, j2, target);
    helper(i_mid + 1, j1, i2, j_mid, target);
    helper(i_mid + 1, j_mid + 1, i2, j2, target);
}