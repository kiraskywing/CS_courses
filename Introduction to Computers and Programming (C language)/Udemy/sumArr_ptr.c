#include <stdio.h>

int arrSum(int arr[], const int n);

int main(void)
{
    int values[10] = {3, 7 -9, 3, 6, -1, 7, 9, 1, -5};
    printf("The sum is %d\n", arrSum(values, 10));
    return 0;
}

int arrSum(int arr[], const int n)
{
    int sum = 0, *ptr;
    int *const arrEnd = arr + n;

    // for (ptr = &arr[0]; ptr < arrEnd; ptr++)
    for (ptr = arr; ptr < arrEnd; ptr++)
        sum += *ptr;
    
    return sum;
}