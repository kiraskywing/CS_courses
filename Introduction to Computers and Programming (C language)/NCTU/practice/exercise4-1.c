#include <stdio.h>

int main()
{
    int i = 7, j = 8, k = 9;
    printf("%d\n", (i + 10) % k / j);
    printf("%d\n", (i + 10) % (k / j));
    printf("%d\n", ((i + 10) % k) / j);
    return 0;
}