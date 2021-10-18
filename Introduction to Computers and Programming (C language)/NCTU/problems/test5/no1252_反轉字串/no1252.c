#include <stdio.h>

int main(void)
{
    int times;
    scanf("%d", &times);

    while (times--)
    {
        int n;
        scanf("%d", &n);
        int m = 100 / n + 2;
        char strings[n][m];

        for (int i = 0; i < n; i++)
            scanf("%s", strings[i]);

        for (int i = n - 1; i >= 0; i--)
            printf("%s ", strings[i]);
        
        puts("");
    }

    return 0;
}

