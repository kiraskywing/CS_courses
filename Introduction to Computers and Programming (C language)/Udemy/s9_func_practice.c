#include <stdio.h>

int multiplyTwoNumbers(int x, int y)
{
    int result = x * y;
    return result;
}

int main()
{
    int result;
    result = multiplyTwoNumbers(10, 20);
    printf("result is %d\n", result);

    return 0;
}