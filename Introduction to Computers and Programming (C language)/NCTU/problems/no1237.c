#include <stdio.h>
#define LEN 10

const int nums[LEN] = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};

void helper(int visited[], int start, int remain, int hours, int mins, long long *res);

int main(void)
{
    int times, n;
    scanf("%d", &times);
    while (times--)
    {
        int visited[10] = {0};
        scanf("%d", &n);
        long long res = 0;
        helper(visited, 0, n, 0, 0, &res);
        printf("%lld\n", res);
    }
    
    return 0;
}

void helper(int visited[], int start, int remain, int hours, int mins, long long *res)
{
    if (hours >= 12 || mins >= 60)
        return;
    
    if (remain == 0)
    {
        *res += 60 * hours + mins;
        return;
    }

    for (int i = start; i < LEN; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            if (i < 4)
                helper(visited, i + 1, remain - 1, hours + nums[i], mins, res);
            else
                helper(visited, i + 1, remain - 1, hours, mins + nums[i], res);
            visited[i] = 0;
        }
    }
}