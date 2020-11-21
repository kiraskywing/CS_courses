#include <stdio.h>

int main(void)
{
    int n, m = 100, count = 0;
    while (scanf("%d", &n) != EOF)
    {
        if ((m - n) >= 0)
        {
            count++;
            m -= n;
        }
        else
            break;
    }
    printf("%d", count);
    
    return 0;
}