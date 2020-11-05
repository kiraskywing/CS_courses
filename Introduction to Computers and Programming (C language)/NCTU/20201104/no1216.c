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
    
    int res = gcd(m, n);
    printf("%d", res);
    
    return 0;
}

int gcd(int m, int n)
{
    int r = m % n;
    if (r == 0)
        return n;
    
    return gcd(n, r);
}