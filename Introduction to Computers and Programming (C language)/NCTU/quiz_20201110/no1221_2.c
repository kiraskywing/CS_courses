#include <stdio.h>

long long mod = 10000007;
long long mat[2][2];
long long trans[2][2] = {{1, 1}, {1, 0}};
long long I[2][2] = {{1, 0}, {0, 1}};

void power(long long b, long long re[2][2]);
void copy(long long a[2][2], long long b[2][2]);
void mul(long long res[2][2], long long a[2][2], long long b[2][2]);

int main(void)
{
    int T;
    scanf("%d", &T);
    long long in;
    while (T--)
    {
        scanf("%lld", &in);
        power(in, mat);
        printf("%lld\n", mat[1][0]);
    }

    return 0;
}

void power(long long b, long long re[2][2])
{
    long long temp[2][2];
    long long a[2][2];
    copy(re, I);
    copy(a, trans);
    
    while (b)
    {
        if (b % 2 != 0)
        {
            copy(temp, re);
            mul(re, temp, a);
        }
        b /= 2;
        copy(temp, a);
        mul(a, temp, temp);
    }
}

void copy(long long a[2][2], long long b[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            a[i][j] = b[i][j];
    }
}

void mul(long long res[2][2], long long a[2][2], long long b[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
        }
    }
}