#include <stdio.h>

int main()
{
    // int a = 33;
    // int b = 15;
    
    // printf("a is %d\n", a);
    // printf("++a is %d\n", ++a);
    // printf("b is %d\n", b);
    // printf("--b is %d\n", --b);
    
    _Bool c = 1;
    _Bool d = 0;
    _Bool op_and;
    _Bool op_or;
    _Bool op_not;

    op_and = c && d;
    op_or = c || d;
    op_not = !c;
    printf("c, d is %d, %d\n", c, d);
    printf("c && d is %d (AND operator)\n", op_and);
    printf("c || d is %d (OR operator)\n", op_or);
    printf("!c is %d (NOT operator)\n", op_and);

    return 0;
}