#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    
    //
    int c;
    fp = fopen("file.txt", "r");
    if (!fp)
    {
        perror("Error in opening file");
        return -1;
    }
    while ((c = fgetc(fp)) != EOF)
        printf("%c", c);
    
    fclose(fp);
    fp = NULL;

    //
    char str[61];
    fp = fopen("file.txt", "r");
    if (!fp)
    {
        perror("Error in opening file");
        return -1;
    }
    if (fgets(str, 10, fp))
        printf("%s", str);
    
    fclose(fp);
    fp = NULL;

    //
    char str1[10], str2[10], str3[10];
    int year;
    fp = fopen("file.txt", "w+");
    if (fp)
        fputs("Hello how are you", fp);
    
    rewind(fp);
    fscanf(fp, "%s %s %s %d", str1, str2, str3, &year);
    printf("Str1: %s\n", str1);
    printf("Str2: %s\n", str2);
    printf("Str3: %s\n", str3);
    printf("year: %d\n", year);

    fclose(fp);
    
    return 0;
}