#include <stdio.h>

void helper(int arr[], int n, int target);

int main(void)
{
    int n, times, target;
    scanf("%d %d", &n, &times);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    while (times--)
    {
        scanf("%d", &target);
        helper(arr, n, target);
    }

    return 0;
}

void helper(int arr[], int n, int target)
{
    int left = 0, right = n - 1, mid;
    while (left + 1 < right)
    {
        mid = (left + right) / 2;
        if (arr[mid] > target)
            right = mid;
        else
            left = mid;
    }

    if (arr[left] == target)
        printf("%d\n", left);
    else
        printf("%d\n", right);
}