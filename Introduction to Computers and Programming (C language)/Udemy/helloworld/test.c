/*
This is a comment.
*/

#include <stdio.h>
int main()
{
    char str[100];
    int i;

    printf("Enter a value :");

    scanf("%d %s", &i, str);

    printf("\nYou entered: %d___%s\n", i, str);

    return 0;
}