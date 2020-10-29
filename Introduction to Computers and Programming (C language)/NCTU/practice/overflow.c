#include <stdio.h>

int main(void)
{
    int i, n;
    int fact = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for (i = n; i > 1; i--)
        fact *= i;

    printf("Factorial of %d: %d\n", n, fact);
    return 0;
}