#include <stdio.h>

int main()
{
    int count = 0, cur = 0, total = 0, max = 0;
    while (scanf("%d", &cur) != EOF)
    {
        count += 1;
        total += cur;
        if (cur > max) max = cur;
    }
    printf("%d %d %d", count, total, max);

    return 0;
}