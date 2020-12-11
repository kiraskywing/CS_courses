#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    // Upper and Lower
    char text[30] = "hello world";
    
    printf("Before: %s\n", text);
    for (int i = 0; (text[i] = toupper(text[i])) != '\0'; i++);
    printf("After to upper: %s\n", text);
    for (int i = 0; (text[i] = tolower(text[i])) != '\0'; i++);
    printf("After to lower: %s\n", text);

    // Convert string to double
    double value = 0;
    char str[] = "3.5 2.5 1.26";
    char *pstr = str;
    char *ptr = NULL;

    while (1)
    {
        value = strtod(pstr, &ptr);
        if (pstr == ptr)
            break;
        else
        {
            printf(" %.3f", value);
            pstr = ptr;
        }
    }
    printf("\n");

    return 0;
}