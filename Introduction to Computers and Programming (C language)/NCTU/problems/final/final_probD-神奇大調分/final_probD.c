#include <stdio.h>
#include <stdlib.h>
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
    getchar();

    while (times--)
    {
        char input[10000], *op;
        fgets(input, 10000, stdin);
        op = strtok(input, " ");

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
    char *token;

    token = strtok(NULL, " \n");
    while (token)
    {
        res += (long long) atoi(token);
        res %= mod;
        token = strtok(NULL, " \n");
    }

    printf("%lld\n", res);
}

void sub(void)
{
    long long res;
    char *token;
    token = strtok(NULL, " ");
    res = 2 * (long long) atoi(token);
    
    while (token)
    {
        res -= (long long) atoi(token);
        res %= mod;
        token = strtok(NULL, " \n");
    }
    if (res < 0)
        res += mod;

    printf("%lld\n", res);
}

void power(void)
{
    long long res, power;
    char *token;
    
    token = strtok(NULL, " ");
    res = (long long) atoi(token);
    token = strtok(NULL, " \n");

    while (token)
    {
        power = (long long) atoi(token);
        res = fast_pow(res, power);
        token = strtok(NULL, " \n");
    }
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
