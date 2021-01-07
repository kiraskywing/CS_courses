#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool cmp(char *s1, char *s2);

int main(void)
{
    int times;
    scanf("%d", &times);
    getchar();

    while (times--)
    {
        char s1[101] = "", s2[101] = "";
        fgets(s1, sizeof(s1), stdin);
        fgets(s2, sizeof(s2), stdin);
        printf("%s\n", cmp(s1, s2) ? "Pass" : "Fail");
    }

    return 0;
}

bool cmp(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 != len2)
        return false;
    
    for (int i = 0; i < len1; i++)
    {
        if (tolower(s1[i]) != tolower(s2[i]))
            return false;
    }

    return true;
}
