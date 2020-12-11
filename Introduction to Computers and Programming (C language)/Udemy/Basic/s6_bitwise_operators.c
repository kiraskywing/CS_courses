#include <stdio.h>

int main()
{
    unsigned int a = 60; // 0011 1100
    unsigned int b = 13; // 0000 1101
    int res_and = 0;
    int res_or = 0;
    int res_shift = 0;

    res_and = a & b; // 0000 1100
    res_or = a | b; // 0011 1101
    res_shift = a << 2; //1111 0000;
    printf("a & b is %d\n", res_and);
    printf("a | b is %d\n", res_or);
    printf("a << 2 is %d\n", res_shift);

    return 0;
}