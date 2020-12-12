#include <stdio.h>
#include <ctype.h>

void judge_v4(void);
void judge_v6(void);
void clear(void);

int main(void)
{
    int times, type;
    scanf("%d", &times);

    while (times--)
    {
        scanf("%d", &type);
        getchar();
        if (type == 4)
            judge_v4();
        if (type == 6)
            judge_v6();
    }
    
    return 0;
}

void judge_v4(void)
{
    char c;
    int num = 0, digit_len = 3, punct_len = 3;
    while ((c = getchar()) != '\n')
    {
        if (ispunct(c))
        {
            if (c != '.' || digit_len == 3 || punct_len == 0)
            {
                printf("QAQ\n");
                clear();
                return;
            }
            punct_len--;
            digit_len = 3;
            num = 0;
        }
        else if (isdigit(c))
        {
            if (digit_len < 3 && num == 0)
            {
                printf("QAQ\n");
                clear();
                return;
            }
            num = num * 10 + c - '0';
            digit_len--;
            if (num > 255)
            {
                printf("QAQ\n");
                clear();
                return;
            }
        }
        else
        {
            printf("QAQ\n");
            clear();
            return;
        }
    }
    
    printf("Valid IP\n");
}

void judge_v6(void)
{
    char c;
    int digit_len = 4, punct_len = 7;
    while ((c = getchar()) != '\n')
    {
        if (ispunct(c))
        {
            if (c != ':' || digit_len == 4 || punct_len == 0)
            {
                printf("QAQ\n");
                clear();
                return;
            }
            punct_len--;
            digit_len = 4;
        }
        else if (isalnum(c))
        {
            if (isalpha(c) && ((tolower(c) - 'a') > 'f' - 'a'))
            {
                printf("QAQ\n");
                clear();
                return;
            }
            digit_len--;
            if (digit_len < 0)
            {
                printf("QAQ\n");
                clear();
                return;
            }
        }
        else
        {
            printf("QAQ\n");
            clear();
            return;
        }
    }
    
    printf("Valid IP\n");
}

void clear(void)
{
    while (getchar() != '\n');
}