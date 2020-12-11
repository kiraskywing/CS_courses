#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char buff[100];
    int nLetters = 0, nDigits = 0, nPuncts = 0;

    printf("Enter a string of less than %d characters: \n", 100);
    scanf("%s", buff);

    int i = 0;
    while (buff[i])
    {
        if (isalpha(buff[i]))
            nLetters++;
        if (isdigit(buff[i]))
            nDigits++;
        if (ispunct(buff[i]))
            nPuncts++;
        i++;
    }

    printf("%d digits, %d letters, %d punctuations\n", nDigits, nLetters, nPuncts);

    return 0;
}