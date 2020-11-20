#include <stdio.h>

int n;
long long mod = 100000007;
long long mat[10][10];
long long dp[1 << 11];
int used[1 << 11];

void init(void);
long long solve(int r_idx, int len);

int main(void)
{
    while (scanf("%d", &n) != EOF)
    {
        init();
        long long ans = solve((1 << n) - 1, n);
        if (ans < 0)
            ans += mod;
        printf("%lld\n", ans);
    }
    
    return 0;
}

void init(void)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%lld", &mat[i][j]);
    }

    for (int i = 0; i < (1 << n); i++)
        used[i] = 0;
    
    for (int i = 0; i < n; i++)
    {
        dp[1 << i] = mat[i][n - 1];
        used[1 << i] = 1;
    }
}

long long solve(int r_idx, int len)
{
    if (used[r_idx])
        return dp[r_idx];
    
    int sub_row[len], count = 0;    // generate bit-mask
    for (int i = 0; i < 10; i++)
    {
        if (r_idx & (1 << i))
            sub_row[count++] = i;
    }

    long long res = 0;
    int sub_r_idx;
    for (int i = 0; i < len; i++)
    {
        sub_r_idx = r_idx ^ (1 << sub_row[i]);    // mask the index of chosen row, generate new sub_index sequence
        long long sub_res = solve(sub_r_idx, len - 1);
        if (i % 2 != 0)
            sub_res = -sub_res;
        res += mat[sub_row[i]][n - len] * sub_res;
        res %= mod;
    }

    used[r_idx] = 1;
    dp[r_idx] = res;
    return res;
}