#include <stdio.h>

void swap(int *x, int *y);

int main(void)
{
    int a = 100, b = 200;

    printf("Before swap, (a, b) = (%d, %d)\n", a, b);
    swap(&a, &b);
    printf("After swap, (a, b) = (%d, %d)\n", a, b);

    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}