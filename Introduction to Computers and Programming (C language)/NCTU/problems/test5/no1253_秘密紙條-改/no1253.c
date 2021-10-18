#include <stdio.h>
#include <string.h>

#define S_LEN 11

void convert(int a, int b, char judge[]);
void shift(char *p, int n);

int main(void)
{
    int times;
    scanf("%d", &times);

    while (times--)
    {
        int a = 0, b = 0;
        char judge[S_LEN] = "";
        scanf("%d %d %s", &a, &b, judge);
        convert(a, b, judge);
    }

    return 0;
}

void convert(int a, int b, char judge[])
{
    char string[S_LEN] = "";
    scanf("%s", string);

    while (strcmp(string, "end") != 0)
    {
        int type = strcmp(judge, string);
        if (type > 0)
            shift(string, a);
        else if (type < 0)
            shift(string, -b);
        
        printf("%s ", string);
        scanf("%s", string);
    }
    puts("");
}

void shift(char *p, int n)
{
    while (*p != '\0')
    {
        *p += n;
        if (*p > 'z' || *p < 0)    // range of char: -128 ~ 127, 132 will become -124
            *p -= 26;
        if (*p < 'a')
            *p += 26;
        p++;
    }    
}