#include <stdio.h>

int main()
{
    char str1[] = "To be or not to be";
    char str2[] = ", that is the question";
    int count = 0;

    while (str1[count] != '\0')
        count += 1;
    
    printf("The length of the string1 \"%s\" is %d characters.\n", str1, count);
    printf("The length of str1 array is %lu.\n", sizeof(str1) / sizeof(str1[0]));

    count = 0;
    while (str2[count] != '\0')
        count += 1;
    
    printf("The length of the string2 \"%s\" is %d characters.\n", str2, count);
    printf("The length of str2 array is %lu.\n", sizeof(str2) / sizeof(str2[0]));

    return 0;
}