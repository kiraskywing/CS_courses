#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int array1[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int array2[] = {38, 27, 87, 63, 59, 223, 132, 1, 19, 7};


int add(int a, int b) {return a + b;}
int sub(int a, int b) {return a - b;}
int mult(int a, int b){return a * b;}
int divi(int a, int b) {return a / b;}

/// Array of pointers to functions
int (*fpArr[])(int, int) = {add, sub, mult, divi};

// performs the given operation on elements of the arrays
int* performOp(int *a, int *b, int size, int (*f)(int, int));

// displays the elements of an array
void display(int *x, int size);

// main method
int main(void)
{
    int choice = 0;

    // size of the array                      
    int size = 0;		
    int *result = NULL;

    // set size to minimum size of the two arrays
    size = sizeof(array1) / sizeof(int);			
  
    if (sizeof(array2) / sizeof(int) < size)
	size = sizeof(array2) / sizeof(int);

    while(choice != 5)
    {
        printf("Which operation do you want to perform? \n");
        printf("1. Add \n");
        printf("2. Subtract \n");
        printf("3. Multiply \n");
        printf("4. Divide \n");
        printf("5. None ... \n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 5) break;
        if (choice < 1 || choice > 5) continue;

        int j = choice - 1;

        result = performOp(array1, array2, size, fpArr[j]);		
        display(result, size);
        
        if (result)  
            free(result);
    }
    
    return 0;
}



// performs the given operation on all elements of the arrays A and B 
int* performOp(int *a, int *b, int size, int (*f)(int, int))
{
    int *c = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
        c[i] = f(a[i], b[i]);

    return c;
}


// function for displaying the results stored in array x
void display(int *x, int size)
{
    if(!x)
        return;
    
    printf("\nThe results are ...\n");
    for (int i = 0; i < size; i++) 
        printf("%d ", x[i]);

    puts("");
}