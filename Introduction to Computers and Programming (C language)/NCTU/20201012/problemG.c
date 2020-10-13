#include <stdio.h>

int main()
{
    int count = 0, money = 100, n = 0;
    while (scanf("%d", &n) != EOF)
    {
        if (money >= n)
        {
            count += 1;
            money -= n;
        }
        else break;
    }
    printf("%d", count);
    return 0;
}
