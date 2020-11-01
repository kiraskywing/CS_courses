#include <stdio.h>

int arr_sum(int arr[], int len);

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = (int) sizeof(arr) / sizeof(arr[0]);
    int sum = arr_sum(arr, len);
    printf("%d", sum);

    return 0;
}

int arr_sum(int arr[], int len)
{
    int sum = 0;
    for (long int i = 0; i < len; i++)
        sum += arr[i];
    return sum;
}