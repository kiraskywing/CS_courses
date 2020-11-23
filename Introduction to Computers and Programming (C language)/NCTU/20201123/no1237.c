#include <stdio.h>
#define LEN 10

int dic[LEN] = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};
int visited[LEN];
long long res;

void helper(int hour, int minute, int start, int n);

int main(void)
{
    int T, n;
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d", &n);
        
        for (int i = 0; i < LEN; i++)
            visited[i] = 0;
        res = 0;
        
        helper(0, 0, 0, n);
        printf("%lld\n", res);
    }
    
    return 0;
}

void helper(int hour, int minute, int start, int n)
{
    if (hour >= 12 || minute >= 60)
        return;
    else if (n == 0)
    {
        // printf("%d:%d\n", hour, minute);
        res += 60 * hour + minute;
    }
    else if (start == LEN)
        return;
    
    for (int i = start; i < LEN; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            if (i < 4)
                helper(hour + dic[i], minute, i + 1, n - 1);
            else
                helper(hour, minute + dic[i], i + 1, n - 1);
            visited[i] = 0;
        }
    }
}