#include <stdio.h>

int gcd(int m, int n);

int main(void)
{
    int m, n, temp;
    scanf("%d %d", &m, &n);
    
    if (m < n)
    {
        temp = m;
        m = n;
        n = temp;
    }
    
    // int r;
    // while (n > 0)
    // {
    //     r = m % n;
    //     m = n;
    //     n = r;
    // }

    int res = gcd(m, n);
    printf("%d", res);
    
    return 0;
}

int gcd(int m, int n)
{
    return n == 0 ? m : gcd(n, m % n);
}