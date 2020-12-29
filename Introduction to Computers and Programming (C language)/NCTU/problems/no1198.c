#include <stdio.h>

int main(void)
{
    int t1 = 0, t2 = 0, n;
    int last_t1 = 0;
    while (scanf("%d", &n) != EOF)
    {
        last_t1 = 0;
        if (t1 < t2)
        {
            t1 += n;
            last_t1 = 1;
        }
        else
            t2 += n;
    }

    int ans;
    if (last_t1)
        ans = t1;
    else
        ans = t2;

    printf("%dm%ds", ans / 60, ans % 60);

    return 0;
}