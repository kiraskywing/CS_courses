#include <stdio.h>
#include <string.h>

int main(void)
{
    // Getting the length of a string
    char myString[] = "my string";
    printf("The length of \"%s\" is %lu charaters.\n\n", myString, strlen(myString));
    
    // Copying strings
    char myString2[] = "My name is YCLin";    // 16 + 1 characters
    char temp[10];
    strncpy(temp, myString2, sizeof(temp) - 1);    //keep one space for '\0'
    printf("The length of myString is %lu\n", strlen(myString2));
    printf("The size of temp is %lu\n", sizeof(temp) / sizeof(temp[0]));
    printf("The temp string is: %s\n", temp);
    printf("The length of temp string is %lu\n\n", strlen(temp));

    // String concatenation
    char src[50], dest[50];
    strncpy(src, "This is source", sizeof(src) - 1);    //keep one space for '\0'
    strncpy(dest, "This is the destination", sizeof(dest) - 1);
    printf("src string: |%s|\n", src);
    printf("dest string: |%s|\n", dest);
    strncat(dest, src, 8);
    printf("dest string after concatenation: |%s|\n\n", dest);

    // String comparision
    printf("strcmp(\"A\", \"A\") is %d\n", strcmp("A", "A"));
    printf("strcmp(\"A\", \"B\") is %d\n", strcmp("A", "B"));
    printf("strcmp(\"B\", \"A\") is %d\n", strcmp("B", "A"));
    printf("strcmp(\"a\", \"A\") is %d\n", strcmp("a", "Z"));
    printf("strcmp(\"applesss\", \"apple\") is %d\n", strcmp("applesss", "apple"));
    printf("strncmp(\"applesss\", \"apple\") with n = 4 is %d\n\n", strncmp("applesss", "apple", 4));

    // Search character
    char str[] = "The quick brown fox";
    char ch = 'o';
    char *pGot_char = strchr(str, ch);
    printf("Origin str: %s\n", str);
    printf("String starting with character '%c': %s\n\n", ch, pGot_char);

    char text[] = "Every dog has his day";
    char w1[] = "dog";
    char w2[] = "hi";
    char *pGot_str = NULL;
    pGot_str = strstr(text, w1);
    printf("Origin str: %s\n", str);
    printf("String starting with string w1 \"%s\": %s\n", w1, pGot_str);
    pGot_str = strstr(text, w2);
    printf("String starting with string w2 \"%s\": %s\n", w2, pGot_str);
    
    return 0;
}