#include <stdio.h>

int mod = 10000007;
long long unit[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

void copy(long long copied[3][3], long long origin[3][3]);
void multi(long long c[3][3], long long a[3][3], long long b[3][3]);
void power(long long res[3][3], long long base[3][3], int n);

int main(void)
{
    int times;
    scanf("%d", &times);

    while (times--)
    {
        int a0, a1, a2, x, y, z, n;
        scanf("%d %d %d %d %d %d %d", &a0, &a1, &a2, &x, &y, &z, &n);
        long long trans[3][3] = {{x, y, z}, {1, 0, 0}, {0, 1, 0}};
        long long res[3][3];
        copy(res, unit);
        power(res, trans, n);
        long long ans = (res[2][0] * a2 + res[2][1] * a1 + res[2][2] * a0) % mod;
        printf("%lld\n", ans);
    }
    
    return 0;
}

void copy(long long copied[3][3], long long origin[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            copied[i][j] = origin[i][j];
    }
}

void multi(long long c[3][3], long long a[3][3], long long b[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }
}

void power(long long res[3][3], long long base[3][3], int n)
{
    long long temp[3][3];

    while (n)
    {
        if (n % 2 != 0)
        {
            copy(temp, res);
            multi(res, temp, base);
        }

        copy(temp, base);
        multi(base, temp, temp);
        n /= 2;
    }
}



// |x y z|   |a2|   |a3| = a2 * x + a1 * y + a0 * z
// |1 0 0| * |a1| = |a2|
// |0 1 0|   |a0|   |a1|