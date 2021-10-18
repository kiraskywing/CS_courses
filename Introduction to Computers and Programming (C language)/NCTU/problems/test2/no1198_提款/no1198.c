#include <stdio.h>

int main(void)
{
    int a = 0, b = 0, last_a = 0, cur;
    while (scanf("%d", &cur) != EOF)
    {
        if (a <= b)
        {
            a += cur;
            last_a = 1;
        }
        else
        {
            b += cur;
            last_a = 0;
        }
    }

    int res = last_a ? a : b;
    printf("%dm%ds", res / 60, res % 60);
    
    return 0;
}