#include <stdio.h>

long long fast_power(long long a, long long b, long long c);

int main(void)
{
    long long a, b, c, res;
    while (scanf("%lld %lld %lld", &a, &b, &c) != EOF)
    {
        res = fast_power(a, b, c);
        printf("%lld\n", res);
    }
    
    return 0;
}

long long fast_power(long long a, long long b, long long c)
{
    if (b == 0)
        return (1 % c);
    if (b == 1)
        return (a % c);
    
    long long res = (fast_power(a, b / 2, c) * fast_power(a, b / 2, c)) % c;
    if (b % 2 != 0)
        res = (res * a) % c;
    
    return res;
}