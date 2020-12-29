#include <stdio.h>

int mod = 100000007;
long long helper(int mat[10][10], int cur_rows[], int row_visited[], int n, int col_index);

int main(void)
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int mat[10][10];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                scanf("%d", &mat[i][j]);
        }

        int cur_rows[n], row_visited[n];
        for (int i = 0; i < n; i++)
        {
            cur_rows[i] = i;
            row_visited[i] = 0;
        }

        long long res = helper(mat, cur_rows, row_visited, n, 0);
        if (res < 0)
            res += mod;
        printf("%lld\n", res);
    }

    return 0;
}

long long helper(int mat[10][10], int cur_rows[], int row_visited[], int n, int col_index)
{
    if (col_index == n - 1)
        return mat[cur_rows[0]][col_index];

    long long res = 0;
    for (int i = 0; i < n - col_index; i++)    // get current rows
    {
        int row = cur_rows[i];
        row_visited[row] = 1;                  // record currently used row

        int next_rows[n], len = 0;
        for (int j = 0; j < n; j++)            // pass not used rows
        {
            if (row_visited[j] == 0)
                next_rows[len++] = j;
        }

        long long sub_res = helper(mat, next_rows, row_visited, n, col_index + 1);
        if (i % 2 != 0)
            sub_res = -sub_res;

        res += mat[row][col_index] * sub_res;
        res %= mod;
        
        row_visited[row] = 0;
    }

    return res;
}
