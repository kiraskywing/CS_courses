#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool judge_v4(void);
bool judge_v6(void);
void clear(void);

int main(void)
{
    int times, type;
    scanf("%d", &times);

    while (times--)
    {
        scanf("%d", &type);
        getchar();
        bool valid = (type == 4 ? judge_v4() : judge_v6());
        printf("%s\n", valid ? "Valid IP" : "QAQ");
    }
    
    return 0;
}

bool judge_v4(void)
{
    char c;
    int num = 0, digit_len = 3, punct_len = 3, n_num = 4;
    while ((c = getchar()) != '\n')
    {
        if (ispunct(c))
        {
            if (c != '.' || digit_len == 3 || punct_len == 0)
            {
                clear();
                return false;
            }
            punct_len--;
            digit_len = 3;
            num = 0;
        }
        else if (isdigit(c))
        {
            if (digit_len < 3 && num == 0)
            {
                clear();
                return false;
            }
            
            if (digit_len == 3)
                n_num--;
            
            num = num * 10 + c - '0';
            digit_len--;
            if (num > 255)
            {
                clear();
                return false;
            }
        }
        else
        {
            clear();
            return false;
        }
    }

    if (n_num != 0 || punct_len != 0)
    {
        clear();
        return false;
    }
    
    return true;
}

bool judge_v6(void)
{
    char c;
    int digit_len = 4, punct_len = 7, n_num = 8;
    while ((c = getchar()) != '\n')
    {
        if (ispunct(c))
        {
            if (c != ':' || digit_len == 4 || punct_len == 0)
            {
                clear();
                return false;
            }
            punct_len--;
            digit_len = 4;
        }
        else if (isalnum(c))
        {
            if (isalpha(c) && ((tolower(c) - 'a') > 'f' - 'a'))
            {
                clear();
                return false;
            }
            
            if (digit_len == 4)
                n_num--;

            digit_len--;
            if (digit_len < 0)
            {
                clear();
                return false;
            }
        }
        else
        {
            clear();
            return false;
        }
    }

    if (n_num != 0 || punct_len != 0)
    {
        clear();
        return false;
    }
    
    return true;
}

void clear(void)
{
    while (getchar() != '\n');
}