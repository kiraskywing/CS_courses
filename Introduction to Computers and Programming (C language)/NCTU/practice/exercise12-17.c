#include <stdio.h>

#define LEN 10
int sum_two_dimensional_array(int a[][LEN], int n);

int main(void)
{
    int arr[3][LEN] = {{1, 1, 1, 1, 1, 1, 1}};
    int res = sum_two_dimensional_array(arr, 3);

    printf("%d\n", res);
    
    return 0;
}

int sum_two_dimensional_array(int a[][LEN], int n)
{

    int *p = *a;    
    int sum = 0, count = 0;

    while (p < *a + n * LEN)
    {
        sum += *p++;
        count++;
    }
    
    printf("count = %d\n", count);
    return sum;
}

// for one-dimension: int *p = &a[0] = &(*a) = a;
// for two-dimension: int *p = &a[0][0] = &(*a[0]) = a[0] = *a
// for three-dimension: int *p = &a[0][0][0] = &(*a[0][0]) = a[0][0] = *(a[0]) = *(*a) = **a