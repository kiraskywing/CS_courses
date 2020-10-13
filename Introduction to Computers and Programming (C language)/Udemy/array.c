#include <stdio.h>

int main()
{
    int count;
    printf("How many grades are going to enter? ");
    scanf("%d", &count);

    int grades[count];
    long sum = 0;
    float average = 0.0f;

    printf("Enter the %u grades: \n", count);

    int i;
    for(i = 0; i < count; ++i)
    {
        printf("%2u> ", i + 1);
        scanf("%d", &grades[i]);
        sum += grades[i];
    }

    average = (float)sum/count;
    printf("\nAverage of the ten grades entered is: %.2f\n", average);
    return 0;
}