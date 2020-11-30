#include <stdio.h>

int mod = 10000007;

void fast_power(long long res[2][2], long long base[2][2], int n);
void copy(long long copied[2][2], long long origin[2][2]);
void multiply(long long c[2][2], long long a[2][2], long long b[2][2]);

int main(void)
{
    int a0 = 0, a1 = 1, times, n;
    scanf("%d", &times);

    while (times--)
    {
        scanf("%d", &n);

        if (n == 0)
            printf("%d\n", a0);
        else
        {
            long long base[2][2] = {{1, 1}, {1, 0}}, res[2][2] = {{1, 0}, {0, 1}};
            fast_power(res, base, n);
            long long ans = (res[1][0] * a1 + res[1][1] * a0) % mod;
            printf("%lld\n", ans);
        }
    }
    
    return 0;
}

// |1 1| |a1| |a2| = a1 + a0
// |1 0| |a0| |a1|

void fast_power(long long res[2][2], long long base[2][2], int n)
{
    long long temp[2][2];
    while (n > 0)
    {
        if (n % 2 != 0)
        {
            copy(temp, res);
            multiply(res, temp, base);
        }

        copy(temp, base);
        multiply(base, temp, temp);
        n /= 2;
    }
}

void copy(long long copied[2][2], long long origin[2][2])
{
    for (int i = 0; i < 2; i ++)
    {
        for (int j = 0; j < 2; j++)
            copied[i][j] = origin[i][j];
    }
}

void multiply(long long c[2][2], long long a[2][2], long long b[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }
}