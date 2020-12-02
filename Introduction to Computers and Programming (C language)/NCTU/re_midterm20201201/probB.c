#include <stdio.h>

int mod = 10000007;

void helper(long long res[2][2], long long base[2][2], int n);
void copy(long long copied[2][2], long long origin[2][2]);
void multiply(long long c[2][2], long long a[2][2], long long b[2][2]);

int main(void)
{
    int times, a0, a1, x, y, n;
    scanf("%d", &times);

    while (times--)
    {
        scanf("%d %d %d %d %d", &a0, &a1, &x, &y, &n);
        long long base[2][2] = {{x, y}, {1, 0}};
        long long res[2][2] = {{1, 0}, {0, 1}};
        helper(res, base, n);
        long long ans = (res[1][0] * a1 + res[1][1] * a0) % mod;
        printf("%lld\n", ans);
    }

    return 0;
}

void helper(long long res[2][2], long long base[2][2], int n)
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
    for (int i = 0; i < 2; i++)
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

// |x y| |a1| |a2| = a1 * x + a0 * y
// |1 0| |a0| |a1|
