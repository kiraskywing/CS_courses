#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[80] = "Hello how are you - my name is - Charles";
    const char s[] = " ";  
    char res[80] = "";
    char *token = NULL;

    token = strtok(str, s);

    while (token != NULL)
    {
        strncat(res, token, sizeof(res) - strlen(res) - 1);
        printf("%s\n", res);
        token = strtok(NULL, s);
    }

    return 0;
}