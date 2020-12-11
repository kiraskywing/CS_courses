#include <stdio.h>
#include <string.h>

int main(void)
{
    char multiple[] = "a string";
    char *p = multiple;

    for (int i = 0; i < strlen(multiple); i++)
        printf("multiple[%d] = %c ; *(p+%d) = %c ; &multiple[%d] = %p ; p+%d = %p\n", i, multiple[i], i, *(p + i), i, &multiple[i], i, p + i);
    printf("Type char occupies: %d bytes\n", (int) sizeof(char));
    
    long arr[] = {15, 25, 35, 45};
    long *ptr = arr;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        printf("address p+%d (&arr[%d]): %p ; *(p+%d) value: %ld\n", i, i, ptr + i, i, *(ptr + i));
    printf("Type long occupies: %d bytes\n", (int) sizeof(long));
    
    return 0;
}