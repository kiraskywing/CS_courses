#include <stdio.h>
#include <string.h>

#define LEN 201

int order_judge(char order[]);
void add(char s1[], char s2[]);
void sub(char s1[], char s2[]);
void eq(char s1[], char s2[]);

int main(void)
{
    int n;
    scanf("%d", &n);
    char strings[n][LEN], order[LEN];

    for (int i = 0; i < n; i++)
        scanf("%s", strings[i]);
    
    int a, b;
    while (scanf("%s %d %d", order, &a, &b) != EOF)
    {
        int order_number = order_judge(order);
        if (order_number == 1)
            add(strings[a], strings[b]);
        else if (order_number == 2)
            sub(strings[a], strings[b]);
        else if (order_number == 3)
            eq(strings[a], strings[b]);
        else
            printf("Oops\n");
    }
    
    return 0;
}

int order_judge(char order[])
{
    if (strcmp(order, "add") == 0)
        return 1;
    else if (strcmp(order, "sub") == 0)
        return 2;
    else if (strcmp(order, "eq") == 0)
        return 3;
    return 0;
}

void add(char s1[], char s2[])
{
    strcat(s1, s2);
    puts(s1);
}

void sub(char s1[], char s2[])
{
    char temp[LEN] = "", c = s2[0], *p;
    int i = 0;
    p = s1;
    while (*p != '\0')
    {
        if (*p != c)
            temp[i++] = *p;
        p++;
    }
    temp[i] = '\0';

    strcpy(s1, temp);
    puts(s1);
}

void eq(char s1[], char s2[])
{
    printf("%s\n", strcmp(s1, s2) == 0 ? "same" : "different");
}