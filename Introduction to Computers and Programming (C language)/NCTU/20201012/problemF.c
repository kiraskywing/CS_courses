#include <stdio.h>

int main()
{
    int times, n, i;
    scanf("%d", &times);

    for (int j = 0; j < times; j++)
    {
        scanf("%d", &n);
        
        if (n == 1) 
        {
            printf("NO\n"); 
            continue;
        }
        
        for (i = 2; i * i <= n; i += 1)
        {
            if (n % i == 0)
            {
                printf("NO\n");
                break;
            }
        }
        if (i * i > n) printf("YES\n");
    }

    return 0;
}
