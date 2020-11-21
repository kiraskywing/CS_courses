#include <stdio.h>

int main(void)
{
    int n, cur, a = 0, b = 0;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &cur);
        if (cur > a)
        {
            b = a;
            a = cur;
        }
        else if (cur > b)
            b = cur;
    }

    printf("%d", b);

    return 0;
}