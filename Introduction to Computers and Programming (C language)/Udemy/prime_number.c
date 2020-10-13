#include <stdio.h>
#include <stdbool.h>

int main()
{
    int p, i;
    int primes[50] = {0};
    int primeIndex = 2;
    _Bool isPrime;

    primes[0] = 2;
    primes[1] = 3;
    
    for (p = 5; p <= 100; p += 2)
    {
        isPrime = true;
        
        for (i = 1; isPrime && i < primeIndex ; ++i)
            if (p % primes[i] == 0)
                isPrime = false;
        
        if (isPrime == true)
        {
            primes[primeIndex] = p;
            primeIndex += 1;
        }
    }

    for (i = 0; i < primeIndex; i++)
    {
        printf("%i ", primes[i]);
    }
    
    return 0;
}