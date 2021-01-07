#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void init(char s[], char res[][4]);
void get_res(char s[], char res[][4], int start, int used, int len, bool *sol_check);
bool valid(char s[], int start, int n);

int main(void)
{
    int times;
    scanf("%d", &times);
    while (times--)
    {
        char s[30], res[4][4];
        init(s, res);

        bool sol_check = false;
        scanf("%s", s);
        int len = strlen(s);
        get_res(s, res, 0, 0, len, &sol_check);
        printf("%s\n", sol_check ? "" : "QAQ");
    }

    return 0;
}

void init(char s[], char res[][4])
{
    memset(s, '\0', 30);
    for (int i = 0; i < 4; i++)
        memset(res[i], '\0', 4);
}

void get_res(char s[], char res[][4], int start, int used, int len, bool *sol_check)
{
    if (used == 4 && len == 0)
    {
        *sol_check = true;
        printf("%s.%s.%s.%s ", res[0], res[1], res[2], res[3]);
        return;
    }
    else if (used == 4 || len < 0)
        return;

    int upper = 3;
    if (len < 3)
        upper = len;

    for (int n = 1; n <= upper; n++)
    {
        if (valid(s, start, n))
        {
            int i;
            strncpy(res[used], &s[start], n);
            get_res(s, res, start + n, used + 1, len - n, sol_check);
            memset(res[used], '\0', 4);
        }
    }
}

bool valid(char s[], int start, int n)
{
    if (n > 1 && s[start] == '0')
        return false;

    int num = 0;
    for (int i = 0; i < n; i++)
        num = num * 10 + s[start + i] - '0';

    if (num > 255)
        return false;

    return true;
}
