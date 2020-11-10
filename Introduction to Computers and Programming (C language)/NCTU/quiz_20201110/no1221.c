#include <stdio.h>

int mod = 10000007;
void power(long long mat[2][2], int n);
void copy(long long a[2][2], long long b[2][2]);
void mul(long long res[2][2], long long a[2][2], long long b[2][2]);

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, a0 = 0, a1 = 1;
        scanf("%d", &n);
        
        if (n == 1)
            printf("%d\n", 1);

        if (n >= 2)
        {
            long long mat[2][2] = {{1, 1}, {1, 0}};
            power(mat, n);
            long long res = (mat[1][0] * a1 + mat[1][1] * a0) % mod;
            printf("%lld\n", res);
        }
    }
    
    return 0;
}

void power(long long mat[2][2], int n)
{
    if (n <= 1)
        return;

    power(mat, n / 2);
    long long temp[2][2];
    copy(temp, mat);
    mul(mat, temp, temp);
    
    if (n % 2 != 0)
    {
        long long trans[2][2] = {{1, 1}, {1, 0}};
        copy(temp, mat);
        mul(mat, temp, trans);
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