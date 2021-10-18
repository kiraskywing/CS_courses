#include <stdio.h>

int main(void)
{
    int m, n, temp;
    scanf("%d %d", &m, &n);
    if (n > m)
    {
        temp = m;
        m = n;
        n = temp;
    }

    while (n != 0)
    {
        temp = m % n;
        m = n;
        n = temp;
    }

    printf("%d", m);

    return 0;
}