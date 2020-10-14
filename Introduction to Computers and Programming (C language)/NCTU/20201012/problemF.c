#include <stdio.h>

int main()
{
    int times = 0, n, i;
    scanf("%d", &times);

    while (times > 0)
    {
        n = 0, i = 2;
        scanf("%d", &n);
        times -= 1;

        if (n == 1)
        {
            printf("NO\n");
            continue;
        }

        while (i < n)
        {
            if (n % i != 0)
                i += 1;
            else
            {
                printf("NO\n");
                break;
            }
        }

        if (i == n) printf("YES\n");
    }

    return 0;
}
