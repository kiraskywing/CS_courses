#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[80] = "Hello how are you - my name is - Charles";
    char s[] = "aer";  
    char res[80] = "";
    char *token = NULL;

    token = strtok(str, s);    // 當str出現任一字元符合s中的字元，就分割

    while (token != NULL)
    {
        strncat(res, token, sizeof(res) - strlen(res) - 1);
        printf("%s\n", res);
        token = strtok(NULL, s);
    }
    
    char str2[80] = "Hello how are you - my name is - Charles";
    char str3[80] = "Hello how are you - my name is - Charles";
    char r1[80] = "", r2[80] = "", s1[] = " ", s2[] = "al";
    char *p1, *p2, *t1, *t2;
    t1 = strtok_r(str2, s1, &p1);
    t2 = strtok_r(str3, s2, &p2);
    
    while (t1 != NULL)
    {
        strncat(r1, t1, sizeof(r1) - strlen(r1) - 1);
        t1 = strtok_r(p1, s1, &p1);
        printf("r1: %s\n", r1);
    }
    while (t2 != NULL)
    {
        strncat(r2, t2, sizeof(r2) - strlen(r2) - 1);
        t2 = strtok_r(p2, s2, &p2);
        printf("r2: %s\n", r2);
    }
    
    return 0;
}