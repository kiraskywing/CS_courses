#include <stdio.h>

int main(void)
{
    FILE *fp;

    //
    int ch;
    fp = fopen("file.txt", "w+");
    for (ch = 33; ch <= 100; ch++)
        fputc(ch, fp);
    fclose(fp);

    //
    fp = fopen("file.txt", "w+");
    fputs("This is Charles Lin's messege.", fp);
    fputs("I'm happy to be here.", fp);
    fclose(fp);

    //
    fp = fopen("file.txt", "w+");
    if (fp)
        fprintf(fp, "%s %s %s %s\n %d", "Hello", "my", "number", "is", 555);
    fclose(fp);

    return 0;
}