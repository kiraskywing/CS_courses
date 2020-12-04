#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Variables of type char occupy %lu bytes.\n", (unsigned long) sizeof(char));
    printf("char range: %d to %d\n\n", CHAR_MIN, CHAR_MAX);
    // -(2 ^ 7) to 2 ^ 7 - 1

    printf("Variables of type short occupy %lu bytes.\n", (unsigned long) sizeof(short));
    printf("short range: %d to %d\n\n", SHRT_MIN, SHRT_MAX);
    // -(2 ^ 15) to 2 ^ 15 - 1
    printf("Variables of type unsigned short int occupy %lu bytes.\n", (unsigned long) sizeof(unsigned short));
    printf("unsigned short range: %d to %d\n\n", 0, USHRT_MAX);
    // 0 to 2 ^ 16 - 1 => 0 to 65,535

    printf("Variables of type int occupy %lu bytes.\n", (unsigned long) sizeof(int));
    printf("int range: %d to %d\n\n", INT_MIN, INT_MAX);
    // -(2 ^ 31) to 2 ^ 31 - 1 => -2,147,483,648 to 2,147,483,647
    printf("Variables of type unsigned int occupy %lu bytes.\n", (unsigned long) sizeof(unsigned int));
    printf("unsigned int range: %d to %d\n\n", 0, UINT_MAX);
    // 0 to 2 ^ 32 - 1 => 0 to 4,294,967,295
    
    printf("Variables of type long int occupy %lu bytes.\n", (unsigned long) sizeof(long));
    printf("long range: %ld to %ld\n\n", (long) LONG_MIN, (long) LONG_MAX);
    // -(2 ^ 63) to 2 ^ 63 - 1 => -9223372036854775808 to 9223372036854775807
    printf("Variables of type unsigned long int occupy %lu bytes.\n", (unsigned long) sizeof(unsigned long int));
    printf("unsigned long range: %d to %lu\n\n", 0, (unsigned long) ULONG_MAX);
    // 0 to 2 ^ 64 -1 => 0 to 18446744073709551615
    printf("Variables of type long long int occupy %lu bytes.\n\n", (unsigned long) sizeof(long long int));
    printf("long long range: %ld to %ld\n\n", (long) LLONG_MIN, (long) LLONG_MAX);

    printf("Variables of type float occupy %lu bytes.\n", (unsigned long) sizeof(float));
    printf("Variables of type double occupy %lu bytes.\n", (unsigned long) sizeof(double));
    printf("Variables of type long double occupy %lu bytes.\n", (unsigned long) sizeof(long double));

    return 0;
}