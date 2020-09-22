#include <stdio.h>
#include <stdlib.h>

#define PAYRATE 12.00
#define TAXRATE_300 .15
#define TAXRATE_150 .20
#define TAXRATE_REST .25
#define OVERTIME 40

int main()
{
    int hours = 0;
    double gross_pay = 0.0;
    double taxes = 0.0;
    double net_pay = 0.0;

    printf("Please  enter the number of hours worked this week: ");
    scanf("%d", &hours);

    if (hours <= 40)
    {
        gross_pay = hours * PAYRATE;
    }
    else
    {
        gross_pay = 40 * PAYRATE;
        double overtime_pay = (hours - 40) * (PAYRATE * 1.5);
        gross_pay += overtime_pay;
    }

    if (gross_pay <= 300)
    {
        taxes = gross_pay * TAXRATE_300;
    }
    
    else if (gross_pay > 300 && gross_pay <= 450)
    {
        taxes = 300 * TAXRATE_300;
        taxes += (gross_pay - 300) * TAXRATE_150;
    }
    else if (gross_pay > 450)
    {
        taxes = 300 * TAXRATE_300;
        taxes += 150 * TAXRATE_150;
        taxes += (gross_pay - 450) * TAXRATE_REST;
    }

    net_pay = gross_pay - taxes;
    
    printf("Your gross pay this week is: %.2f\n", gross_pay);
    printf("Your taxes this week is: %.2f\n", taxes);
    printf("Your net pay this week is: %.2f\n", net_pay);
        
    return 0;
}