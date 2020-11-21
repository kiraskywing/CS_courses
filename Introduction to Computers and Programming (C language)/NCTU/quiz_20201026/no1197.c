#include <stdio.h>

int main(void)
{
    int cur, count = 0, total = 0, max = 0;
    while (scanf("%d", &cur) != EOF)
    {
        count++;
        total += cur;
        if (cur > max)
            max = cur;
    }
    printf("%d %d %d", count, total, max);

    return 0;
}