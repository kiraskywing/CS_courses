#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
        printf("%d", 366);
    else
        printf("%d", 365);

    return 0;
}