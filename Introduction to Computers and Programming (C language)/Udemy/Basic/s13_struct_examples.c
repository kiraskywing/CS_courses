#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct date
{
    int month;
    int day;
    int year;
};

struct intPtrs
{
    int *p1;
    int *p2;
};

struct names
{
    char first[20];    //using array to store string
    char last[20];
};

struct namect
{
    char *fname;    // pointer points to the string litarel, dynamically allocates memory
    char *lname;
    int letters;
};

void getinfo (struct namect *pst);

int main(void)
{
    struct date today, *datePtr;
    datePtr = &today;

    datePtr -> month = 9;
    datePtr -> day = 25;
    datePtr -> year = 2020;

    printf("Today's date is %d/%d/%d.\n", datePtr -> month, datePtr -> day, datePtr -> year);
    /////////////    

    struct intPtrs pointers, *pPtr;
    pPtr = &pointers;
    int i1 = 100, i2;

    pointers.p1 = &i1;
    pointers.p2 = &i2;
    *pointers.p2 = -97;

    printf("i1 = %d, *pointers.p1 = %d\n", i1, *pointers.p1);
    printf("i2 = %d, *pointers.p2 = %d\n", i1, *pointers.p2);

    int i3 = 200, i4;
    pPtr -> p1 = &i3;
    pPtr -> p2 = &i4;
    *(pPtr -> p2) = -300;
    printf("i3 = %d, *(pPtr -> p1) = %d\n", i3, *(pPtr -> p1));
    printf("i4 = %d, *(pPtr -> p2) = %d\n", i4, *(pPtr -> p2));
    /////////////    

    struct namect full_name, *nPtr;
    nPtr = &full_name;
    getinfo(nPtr);
    printf("First name: %s, Last name: %s\n", nPtr -> fname, nPtr -> lname);
                                           // (*nPtr).fname, (*nPtr).lname);
    free(nPtr -> fname);
    free(nPtr -> lname);

    return 0;
}

void getinfo (struct namect *pst)
{
    char temp[100];
    int n;
    
    printf("Please enter your first name:\n");
    fgets(temp, 100, stdin);
    n = strlen(temp);
    if (temp[n - 1] == '\n')
        temp[n - 1] = '\0';
    
    pst -> fname = (char *) malloc((n + 1) * sizeof(char));    // allocate memory to hold name
    strcpy(pst -> fname, temp);    // copy name to allocated memory
    

    printf("Please enter your last name.\n");
    fgets(temp, 100, stdin);
    n = strlen(temp);
    if (temp[n - 1] == '\n')
        temp[n - 1] = '\0';
    
    pst -> lname = (char *) malloc((n + 1) * sizeof(char));    // allocate memory to hold name
    strcpy(pst -> lname, temp);    // copy name to allocated memory
}