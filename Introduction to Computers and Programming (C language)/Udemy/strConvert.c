#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char text[30] = "hello world";
    
    printf("Before: %s\n", text);
    for (int i = 0; (text[i] = toupper(text[i])) != '\0'; i++);
    printf("After: %s\n", text);

    return 0;
}