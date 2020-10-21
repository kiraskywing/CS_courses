#include <stdio.h>

int main()
{
    int m, n, r = 1;
    scanf("%d %d", &m, &n);

    while (r != 0)
    {
        r = m % n;
        m = n;
        n = r;
    }
    printf("%d\n", m);

    return 0;
}