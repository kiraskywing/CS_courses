#include <stdio.h>

int mod = 10000007;
int n;
long long temp[2][2];
long long unit[2][2] = {{1, 0}, {0, 1}};
long long res[2][2];

void copy(long long a[2][2], long long b[2][2]);
void multi(long long a[2][2], long long b[2][2], long long c[2][2]);
void power(long long trans[2][2], int n);

int main(void)
{
    int times;
    scanf("%d", &times);
    while (times--)
    {
        int a0 = 0, a1 = 1;
        scanf("%d", &n);
        long long trans[2][2] = {{1, 1}, {1, 0}};
        copy(res, unit);
        power(trans, n);
        long long ans = (res[1][0] * a1) % mod;
        printf("%lld\n", ans);
    }

    return 0;
}

void copy(long long a[2][2], long long b[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            a[i][j] = b[i][j];
    }
}

void multi(long long a[2][2], long long b[2][2], long long c[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            a[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                a[i][j] += b[i][k] * c[k][j];
                a[i][j] %= mod;
            }
        }
    }
}

void power(long long trans[2][2], int n)
{
    while (n)
    {
        if (n % 2 != 0)
        {
            copy(temp, res);
            multi(res, temp, trans);
        }

        copy(temp, trans);
        multi(trans, temp, temp);
        n /= 2;
    }
}