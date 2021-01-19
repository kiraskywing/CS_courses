#include <stdio.h>

int ch_to_int(char ch);

int main(void)
{
    int times;
    scanf("%d", &times);
    getchar();    // abandon '\n'
    
    while (times--)
    {
        char ch;
        int pre_int = 0, cur_int = 0, res = 0;
        while ((ch = getchar()) != '\n')
        {
            cur_int = ch_to_int(ch);
            
            if (pre_int >= cur_int)
                res += pre_int;
            else
                res -= pre_int;
            
            pre_int = cur_int;
        }
        res += pre_int;
        
        printf("%d\n", res);
    }

    return 0;
}

int ch_to_int(char ch)
{
    if (ch == 'I')
        return 1;
    if (ch == 'V')
        return 5;
    if (ch == 'X')
        return 10;
    if (ch == 'L')
        return 50;
    if (ch == 'C')
        return 100;
    if (ch == 'D')
        return 500;
    if (ch == 'M')
        return 1000;
    return 0;
}