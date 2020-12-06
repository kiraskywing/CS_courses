#include <stdio.h>
#include <string.h>
#include <ctype.h>

void judge_v4(char string[]);
void judge_v6(char string[]);

int main(void)
{
    int times;
    scanf("%d", &times);

    while (times--)
    {
        int n;
        char string[1000];
        scanf("%d %s", &n, string);

        if (n == 4)
            judge_v4(string);
        if (n == 6)
            judge_v6(string);
    }
    
    return 0;
}

void judge_v4(char string[])
{
    int punct_n = 3, s_len = strlen(string);
    int num = 0, num_check = 0;

    for (int i = 0; i < s_len; i++)
    {
        if (ispunct(string[i]))
        {
            if (!num_check || (punct_n == 3 && num == 0) || punct_n == 0 || string[i] != '.')
            {
                printf("QAQ\n");
                return;
            }
            num = num_check = 0;
            punct_n--;
        }
        
        else
        {
            if (!isdigit(string[i]))
            {
                printf("QAQ\n");
                return;
            }
            num_check = 1;
            num = 10 * num + string[i] - '0';
            if (num > 255)
            {
                printf("QAQ\n");
                return;
            }
        }
    }

    printf("Valid IP\n");
}

void judge_v6(char string[])
{
    int punct_n = 7, s_len = strlen(string);
    int num_len = 4, num_check = 0;

    for (int i = 0; i < s_len; i++)
    {
        if (ispunct(string[i]))
        {
            if (!num_check || punct_n == 0 || string[i] != ':')
            {
                printf("QAQ\n");
                return;
            }
            
            num_len = 4;
            num_check = 0;
            punct_n--;
        }
        
        else
        {
            if (!isalnum(string[i]) || (isalpha(string[i]) && (tolower(string[i]) - 'a' > 'f' - 'a')))
            {
                printf("QAQ\n");
                return;
            }

            num_check = 1;
            num_len--;
            if (num_len < 0)
            {
                printf("QAQ\n");
                return;
            }
        }
    }

    printf("%s\n", punct_n == 0 ? "Valid IP" : "QAQ");
}