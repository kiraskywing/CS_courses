#include <stdio.h>

int main()
{
    unsigned long long sum = 0LL;
    unsigned int count = 0;

    printf("Enter the number of integers you want to sum: ");
    scanf(" %u", &count);

    for (int i = 1; i <= count; ++i)
    {
        sum += i;
    }
    
    printf("Total of the first %u numbers is %llu\n", count, sum);
    return 0;
}