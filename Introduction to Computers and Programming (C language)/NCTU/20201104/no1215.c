#include <stdio.h>

void helper(int mat[], int start, int end);

int main(void)
{
    int n;
    scanf("%d", &n);
    int mat[n];
    for (int i = 0; i < n; i++)
        mat[i] = i + 1;
    
    helper(mat, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", mat[i]);

    return 0;
}

void helper(int mat[], int start, int end)
{
    if (start == end)
        return;
    
    int num = (end - start + 1) / 2, i = start, j = start + num;
    for (int k = 0; k < num; k++, i++, j++)
    {
        int temp = mat[i];
        mat[i] = mat[j];
        mat[j] = temp;
    }

    helper(mat, start, i - 1);
    helper(mat, i, j - 1);
}