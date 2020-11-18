#include <stdio.h>

void helper(int arr[], int start, int end);

int main(void)
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
    
    helper(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

void helper(int arr[], int start, int end)
{
    if (start >= end)
        return;
    
    int n = (end - start + 1) / 2, temp, i1 = start, i2 = i1 + n;
    while (n--)
    {
        temp = arr[i1];
        arr[i1] = arr[i2];
        arr[i2] = temp;
        i1++;
        i2++;
    }

    helper(arr, start, i1 - 1);
    helper(arr, i1, i2 - 1);
}