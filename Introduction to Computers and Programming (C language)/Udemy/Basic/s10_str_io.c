#include <stdio.h>

int main(void)
{
    // Write (output)
    printf("\"printf\" ends when encounters a null character.\n");
    puts("\"puts\" always writes an additional new-line character");    // both put char pointer
    
    char string1[] = "This is a test of \"putchar()\".\n";
    char *p = string1;
    while (*p)
        putchar(*p++);    // put character
    
    // Read (input)
    char string2[100] = "";
    printf("\"scanf()\" test:\n");
    scanf("%s", string2);    // put pointer; when encounter space, tab, new-line character stops reading.
    puts(string2);

    while (getchar() != '\n')    // clean characters stored in buffer
        ;

    char string3[100];
    printf("\"gets()\" test:\n");
    gets(string3);    // reads until it finds a new-line character, discard new-line character
    puts(string3);

    char string4[10];
    printf("\"fgets()\" test:\n");
    fgets(string4, sizeof(string4), stdin);   // if space is enough, it also stores space character.
    printf("%s", string4);
    
    while (getchar() != '\n')    // clean characters stored in buffer
        ;

    int i = 0, n = 10;
    char string5[n];
    printf("\"getchar()\" test:\n");
    while ((string5[i] = getchar()) != '\n' && i < n - 1)
        i++;
    string5[i] = '\0';
    puts(string5);

    return 0;
}