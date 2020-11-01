#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "The quick brown fox";
    char ch = 'q';
    char *pGot_char = NULL;
    pGot_char = strchr(str, ch);
    printf("%s\n", pGot_char);

    char text[] = "Every dog has his day";
    char word[] = "dog";
    char *pFound = NULL;
    pFound = strstr(text, word);
    printf("%s\n", pFound);

    return 0;
}