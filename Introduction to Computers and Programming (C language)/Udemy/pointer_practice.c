#include <stdio.h>
#include <stddef.h>

int main(void)
{
    int count = 10;
    int *pInt = NULL;

    pInt = &count;
    
    printf("count = %d\n", count);
    printf("The address of count: %p\n", &count);
    printf("The address of pInt pointing to: %p\n", pInt);
    printf("The address of pInt itself: %p\n", (void*)&pInt);
    printf("pInt's size: %zd bytes\n", sizeof(pInt));
    printf("The value pInt pointing to: %d\n", *pInt);

    int value = 0;
    int *pVal = &value;

    printf("Input an integer: ");
    scanf("%d", pVal);
    printf("You entered: %d\n", value);

    return 0;
}