#include <stdio.h>

void copyString(char *from, char *to);
int stringLength(const char *string);

int main(void)
{
    char string1[] = "This is a string to be copied.";
    char string2[50];

    copyString(string1, string2);
    printf("Str1: %s\n", string1);
    printf("Str2: %s\n", string2);

    printf("%d \n", stringLength("stringLength test"));
    printf("%d \n", stringLength(""));
    printf("%d \n", stringLength("jason"));

    return 0;
}

void copyString(char *from, char *to)
{
    while (*from)
        *to++ = *from++;
    
    *to = '\0';
}

int stringLength(const char *string)
{
    const char *lastAddress = string;

    while (*lastAddress)
        ++lastAddress;

    return lastAddress - string;
}
