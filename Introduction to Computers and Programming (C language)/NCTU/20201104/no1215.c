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
    if (start == end)
        return;
    
    int num = (end - start + 1) / 2, left = start, right = start + num, temp;
    while (num--)
    {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left += 1;
        right += 1;
    }

    helper(arr, start, left - 1);
    helper(arr, left, right - 1);
}