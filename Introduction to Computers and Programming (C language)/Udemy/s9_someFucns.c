#include <stdio.h>
#include <stdlib.h>

int gcd(int u, int v);
float absoluteValue(float x);
float squareRoot(float x);

int main()
{
    int result = 0;

    float f1 = -15.5;
    int i1 = -716;
    float absvalue = 0.0;

    result = gcd(150, 35);
    printf("The gcd of 150 and 35 is %d\n", result);

    absvalue = absoluteValue(f1);
    printf("absvalue = %.2f\n", absvalue);
    absvalue = absoluteValue(i1);
    printf("absvalue = %.2f\n", absvalue);
    printf("%.2f\n", absoluteValue (-6.0) / 4);

    printf("%.2f\n", squareRoot(-3.0));
    printf("%.2f\n", squareRoot(16.0));
    printf("%.2f\n", squareRoot(165.0));

    return 0;
}

int gcd(int u, int v)
{
    int temp;

    while (v!=0)
    {
        temp = u % v;
        u = v;
        v = temp;
    }

    return u;
}

float squareRoot(float x)
{
    const float epsilon = .0001;
    float guess = 1.0;
    
    if (x < 0)
    {
        printf("Negative argument to squareRoot.\n");
        return -1.0;
    }

    while (absoluteValue (guess * guess - x) >= epsilon)
    {
        guess = (x / guess + guess) / 2.0;
    }
    
    return guess;
}

float absoluteValue(float x)
{
    if (x < 0)
    {
        x = -x;
    }
    
    return x;
}
