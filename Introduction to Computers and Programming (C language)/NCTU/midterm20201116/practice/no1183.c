#include <stdio.h>

int main(void)
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        
        if (n == 1)
        {
            printf("NO\n");
            continue;
        }
        if (n == 2)
        {
            printf("YES\n");
            continue;
        }

        int i;
        for (i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                printf("NO\n");
                break;
            }
        }
        
        if (i * i > n)
            printf("YES\n");
    }

    return 0;
}