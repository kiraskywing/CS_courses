#include <stdio.h>

void qsort(int arr[], int start, int end);

int main(void)
{
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    
    qsort(arr, 0, N - 1);
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}

void qsort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    
    int left = start, right = end;
    int pivot = arr[(left + right) / 2];

    while (left <= right)
    {
        while (left <= right && arr[left] < pivot)
            left++;
        while (left <= right && arr[right] > pivot)
            right--;
        if (left <= right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }

    qsort(arr, start, right);
    qsort(arr, left, end);
}