#include <stdio.h>

int main(void)
{
    FILE *fp;

    //
    // int len;
    // fp = fopen("file.txt", "r");
    // if (!fp)
    // {
    //     perror("Error opening file");
    //     return -1;
    // }
    // fseek(fp, 0, SEEK_END);
    // len = ftell(fp);
    // fclose(fp);
    // printf("Total size of file.txt: %d bytes.\n", len);

    //
    // fp = fopen("file.txt", "w+");
    // fputs("This is Charles", fp);
    // fseek(fp, 7, SEEK_SET);
    // fputs("Hello how are you", fp);
    // fclose(fp);

    fpos_t position;
    fp = fopen("file.txt", "w+");
    fgetpos(fp, &position);
    fputs("Hello world!\n", fp);

    fsetpos(fp, &position);
    fputs("This is going to override previous content.\n", fp);
    fclose(fp);
    
    return 0;
}