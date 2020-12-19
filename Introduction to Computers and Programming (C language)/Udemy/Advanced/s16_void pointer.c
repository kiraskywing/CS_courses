#include <stdio.h>

int main(void)
{
    int i = 10;
    float f = 2.34;
    char c = 'k';

    void *ptr = NULL;

    printf("Size of void pointer = %lu\n", sizeof(ptr));
    
    ptr = &i;
    printf("Value of i = %d\n", *(int *)ptr);

    ptr = &f;
    printf("Value of f = %.2f\n", *(float *)ptr);

    ptr = &c;
    printf("Value of c = %c\n", *(char *)ptr);
    
    int datas[] = {100, 200, 300};
    ptr = &datas[1];
    ptr += sizeof(int);
    printf("%d\n", *(int *)ptr);

    return 0;
}