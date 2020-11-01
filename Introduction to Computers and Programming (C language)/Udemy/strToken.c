#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[80] = "Hello how are you - my name is - Charles";
    const char s[2] = "-";  // 為何要開2?
    char *token = NULL;

    token = strtok(str, s);

    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, s);
    }

    return 0;
}