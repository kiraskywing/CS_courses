#include <stdio.h>

int main(void)
{
    long long a, b, c;
    while (scanf("%lld %lld %lld", &a, &b, &c) != EOF)
    {
        long long res = 1;
        while (b)
        {
            if (b & 1)
                res = (a * res) % c;

            a = (a * a) % c;
            b >>= 1;
        }
        
        printf("%lld\n", res);
    }
}