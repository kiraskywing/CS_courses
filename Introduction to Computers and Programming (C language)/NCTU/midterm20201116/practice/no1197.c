#include <stdio.h>

int main(void)
{
    int n, x = 0, y = 0, z = 0;
    while (scanf("%d", &n) != EOF)
    {
        x++;
        y += n;
        if (n > z)
            z = n;
    }
    printf("%d %d %d", x, y, z);

    return 0;
}