#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target);

int main(void)
{
    int n, times;
    scanf("%d %d", &n, &times);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while (times--)
    {
        int target;
        scanf("%d", &target);
        printf("%d\n", binarySearch(arr, 0, n - 1, target));
    }
    
    return 0;
}

int binarySearch(int arr[], int left, int right, int target)
{
    int mid;
    while (left + 1 < right)
    {
        mid = (left + right) / 2;
        if (arr[mid] < target)
            left = mid;
        else
            right = mid;
    }
    if (arr[left] == target)
        return left;
    return right;
}