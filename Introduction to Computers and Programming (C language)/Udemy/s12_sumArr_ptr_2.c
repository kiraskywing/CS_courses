#include <stdio.h>

int arrSum(int *ptr, const int n);

int main(void)
{
    int values[10] = {3, 7 -9, 3, 6, -1, 7, 9, 1, -5};
    printf("The sum is %d\n", arrSum(values, 10));
    return 0;
}

int arrSum(int *ptr, const int n)
{
    int sum = 0;
    int *const arrEnd = ptr + n;

    for (; ptr < arrEnd; ptr++)
        sum += *ptr;
    
    return sum;
}