#include <stdio.h>

int main()
{
    int minutes_input = 0;
    double years = 0.0;
    double days = 0.0;
    double minutesInYear = 0;

    printf("Please enter the number of minutes: ");
    scanf("%d", &minutes_input);

    minutesInYear = (60 * 24 * 365);
    
    years = minutes_input / minutesInYear;
    days = minutes_input / 60.0 / 24.0;

    printf("%d minutes is approximately %f years and %f days.\n", minutes_input, years, days);

    return 0;
}