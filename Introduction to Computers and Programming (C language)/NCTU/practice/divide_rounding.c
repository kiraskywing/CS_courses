#include <stdio.h>

int main()
{
    printf("The value of 4/3 is %d\n", 4/3);
    printf("The value of 4.0/3.0 is %.3f\n", 4.0/3.0);

    int r = 0;

    printf("Enter radius: ");
    scanf("%d", &r);

    printf("\nSphere volume: %.2f cubic meters\n",
           4.0/3.0 * 3.14 * r * r * r);

    return 0;
}