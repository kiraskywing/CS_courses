#include <stdio.h>

void helper(int arr[], int start, int end, int target);

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
        helper(arr, 0, n - 1, target);
    }

    return 0;
}

void helper(int arr[], int start, int end, int target)
{
    int left = start, right = end, mid;
    while (left + 1 < right)
    {
        mid = (left + right) / 2;
        if (arr[mid] > target)
            left = mid;
        else
            right = mid;
    }

    if (arr[right] == target)
        printf("%d\n", right);
    else
        printf("%d\n", left);
}
