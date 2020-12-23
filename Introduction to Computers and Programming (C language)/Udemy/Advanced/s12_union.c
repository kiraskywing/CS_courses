#include <stdio.h>
#include <string.h>

struct owner
{
    char socsecurity[12];
};
struct leasecompany
{
    char name[40];
    char headquarters[40];
};
struct car_data
{
    char make[15];
    int status;    // 0: owned, 1: leased
    union
    {
        struct owner owncar;
        struct leasecompany leasecar;
    };
};

union student  
{
    char letterGrade;
    int roundedGrade;
    float exactGrade;
};

int main(void)
{
    union student record1;
    union student record2;

    // assigning values to record1 union variable
    record1.letterGrade = 'B';
    record1.roundedGrade = 87;
    record1.exactGrade = 86.50;

    printf("Union record1 values example\n");
    printf(" Letter Grade: %c \n", record1.letterGrade);
    printf(" Rounded Grade: %d \n", record1.roundedGrade);
    printf(" Exact Grade: %.2f \n\n", record1.exactGrade);

    // assigning values to record2 union variable
    printf("Union record2 values example\n");
    record2.letterGrade = 'A';
    printf(" Letter Grade: %c \n", record2.letterGrade);

    record2.roundedGrade = 100;
    printf(" Rounded Grade: %d \n", record2.roundedGrade);

    record2.exactGrade = 99.50;
    printf(" Exact Grade: %.2f \n", record2.exactGrade);
    
    return 0;
}