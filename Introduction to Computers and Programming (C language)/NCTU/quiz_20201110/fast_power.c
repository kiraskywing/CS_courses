#include <stdio.h>

int main(void)
{
    int a, n, re = 1;
    scanf("%d %d", &a, &n);

    while (n > 0)
    {
        printf("n = %d, a = %d\n", n, a);
        if (n % 2 != 0)
        {
            re *= a;
            printf("n = %d, re = %d\n", n, re);
        }
        
        a *= a;
        n /= 2;
    }
    
    return 0;
}