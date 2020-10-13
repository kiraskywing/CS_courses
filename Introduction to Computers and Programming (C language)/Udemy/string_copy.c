#include <stdio.h>
#include <string.h>

int main()
{
    char myString[] = "My name is YCLin";  // 16 + 1 characters
    char temp[10];

    strncpy(temp, myString, sizeof(temp) - 1);
    printf("The length of myString is %lu\n", strlen(myString));
    printf("The temp string is: %s\n", temp);

    return 0;
}