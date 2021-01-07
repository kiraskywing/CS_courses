#include <stdio.h>
#include <string.h>

int mod = 10000;

void sum(void);
void sub(void);
void power(void);
long long fast_pow(long long base, long long n);

int main(void)
{
    int times;
    scanf("%d", &times);
    while (times--)
    {
        char op[4];
        scanf("%s", op);

        if (strcmp(op, "sum") == 0)
            sum();
        if (strcmp(op, "sub") == 0)
            sub();
        if (strcmp(op, "pow") == 0)
            power();
    }

    return 0;
}

void sum(void)
{
    long long res = 0;
    char c;

    while ((c = getchar()) == ' ');
    while (c != '\n')
    {
        if (c == ' ')
            while ((c = getchar()) == ' ');
        long long cur = 0;

        while (c != ' ' && c != '\n')
        {
            cur = cur * 10 + c - '0';
            c = getchar();
        }

        res += cur;
        res %= mod;
        if (res < 0)
            res += mod;
    }

    printf("%lld\n", res);
}

void sub(void)
{
    long long res = 0;
    char c;
    while ((c = getchar()) == ' ');

    while (c != ' ')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }

    while ((c = getchar()) == ' ');

    while (c != '\n')
    {
        if (c == ' ')
            while ((c = getchar()) == ' ');
        long long cur = 0;
        while (c != ' ' && c != '\n')
        {
            cur = cur * 10 + c - '0';
            c = getchar();
        }

        res -= cur;
        res %= mod;
        if (res < 0)
            res += mod;
    }

    printf("%lld\n", res);
}

void power(void)
{
    long long res = 0, power = 0;
    char c;
    while ((c = getchar()) == ' ');

    while (c != ' ')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }

    c = getchar();
    while (c != ' ')
    {
        power = power * 10 + c - '0';
        c = getchar();
    }

    c = getchar();
    while (c != '\n')
    {
        if (c == ' ')
            while ((c = getchar()) == ' ');
        long long cur = 0;
        while (c != ' ' && c != '\n')
        {
            printf("%c\n", c);
            cur = cur * 10 + c - '0';
            c = getchar();
        }
        power *= cur;
    }

    printf("%lld %lld\n", res, power);
    res = fast_pow(res, power);
    if (res < 0)
        res += mod;

    printf("%lld\n", res);

    return;
}

long long fast_pow(long long base, long long n)
{
    long long ans = 1;
    while (n)
    {
        if(n & 1)
        {
            ans *= base;
            ans %= mod;
        }

        base *= base;
        base %= mod;
        n >>= 1;
    }

    return ans;
}
