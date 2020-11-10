#include <stdio.h>

long long power(long long a, long long b, long long c) 
{
    long long re = 1;
    while(b) 
    {
        printf("%lld\n", b);
        if (b & 1) 
        {
            printf("%lld\n", b);
            re = re * a % c;
        }
        b >>= 1;
        a = a * a % c;
    }
    return re;
}

int main(void) 
{
    long long a, b, c;
    while(scanf("%lld %lld %lld", &a, &b, &c) != EOF) 
    {
        printf("%lld\n", power(a, b, c));
    }
}