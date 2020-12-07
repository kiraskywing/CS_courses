#include <stdio.h>
#include <string.h>

#define LEN 202

int valid_check(char order[]);
void add(char strings[][LEN], int a, int b);
void sub(char strings[][LEN], int a, int b);
void eq(char strings[][LEN], int a, int b);

int main(void)
{
    int n;
    scanf("%d", &n);
    char strings[n][LEN];

    for (int i = 0; i < n; i++)
        scanf("%s", strings[i]);

    char order[LEN];
    int a, b;
    while ((scanf("%s %d %d", order, &a, &b) != EOF))
    {
        if (valid_check(order) == 0)
            printf("Oops\n");
        else if (valid_check(order) == 1)
            add(strings, a, b);
        else if (valid_check(order) == 2)
            sub(strings, a, b);
        else if (valid_check(order) == 3)
            eq(strings, a, b);
    }
    
    return 0;
}

int valid_check(char order[])
{
    if (strcmp(order, "add") == 0)
        return 1;
    if (strcmp(order, "sub") == 0)
        return 2;
    if (strcmp(order, "eq") == 0)
        return 3;
    return 0;
}

void add(char strings[][LEN], int a, int b)
{
    strcat(strings[a], strings[b]);
    printf("%s\n", strings[a]);
}

void sub(char strings[][LEN], int a, int b)
{
    char temp[LEN], ch = strings[b][0];
    int i = 0, j = 0;
    while (strings[a][i] != '\0')
    {
        if (strings[a][i] != ch)
            temp[j++] = strings[a][i];
        i++;
    }
    
    temp[j] = '\0';
    strcpy(strings[a], temp);
    printf("%s\n", strings[a]);
}

void eq(char strings[][LEN], int a, int b)
{
    printf("%s\n", strcmp(strings[a], strings[b]) == 0 ? "same" : "different");
}