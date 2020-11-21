#include <stdio.h>

long long mat[10][10];
long long mod = 100000007;
int n;

long long solve(int A[], int B[], int n);

int main(void)
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                scanf("%lld", &mat[i][j]);
        }

        int A[n], B[n];  // A: record row index, B: record col index
        for (int i = 0; i < n; i++)
            A[i] = B[i] = i;
        
        long long ans = solve(A, B, n);
        if (ans < 0)
            ans += mod;
        printf("%lld\n", ans);
    }

    return 0;
}

long long solve(int A[], int B[], int n)
{
    if (n == 1)
        return mat[A[0]][B[0]];
    
    long long res = 0;
    int sub_A[n - 1], sub_B[n - 1];

    for (int i = 0; i < n - 1; i++) // record sub col index
        sub_B[i] = B[i + 1];
    
    for (int i = 0; i < n; i++) // scan current row index
    {
        for (int j = 0; j < n; j++) // record sub row index (pass i == j)
        {
            if (i > j)
                sub_A[j] = A[j];
            else if (i < j)
                sub_A[j - 1] = A[j];
        }

        long long sub_res = solve(sub_A, sub_B, n - 1);
        if (i % 2 != 0)
            sub_res = -sub_res;
        res += sub_res * mat[A[i]][B[0]];
        res %= mod;
    }

    return res;
}