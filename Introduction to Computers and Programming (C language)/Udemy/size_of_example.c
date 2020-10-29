#include <stdio.h>

int main()
{
    printf("Variables of type char occupy %lu bytes.\n\n", (unsigned long) sizeof(char));

    printf("Variables of type short occupy %lu bytes.\n", (unsigned long) sizeof(short));
    printf("Variables of type unsigned short int occupy %lu bytes.\n\n", (unsigned long) sizeof(unsigned short));

    printf("Variables of type int occupy %lu bytes.\n", (unsigned long) sizeof(int));
    printf("Variables of type unsigned int occupy %lu bytes.\n\n", (unsigned long) sizeof(unsigned int));
    
    printf("Variables of type long int occupy %lu bytes.\n", (unsigned long) sizeof(long int));
    printf("Variables of type unsigned long int occupy %lu bytes.\n", (unsigned long) sizeof(unsigned long int));
    printf("Variables of type long long int occupy %lu bytes.\n\n", (unsigned long) sizeof(long long int));

    printf("Variables of type float occupy %lu bytes.\n", (unsigned long) sizeof(float));
    printf("Variables of type double occupy %lu bytes.\n", (unsigned long) sizeof(double));
    printf("Variables of type long double occupy %lu bytes.\n", (unsigned long) sizeof(long double));

    return 0;
}