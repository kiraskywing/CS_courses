#include <stdio.h>

int main(void)
{
    int n, q, cur, practice[100] = {0};
    scanf("%d %d", &n, &q);

    while (n--)
    {
        scanf("%d", &cur);
        practice[cur] = 1;
    }

    while (q--)
    {
        scanf("%d", &cur);
        if (practice[cur] == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    return 0;
}