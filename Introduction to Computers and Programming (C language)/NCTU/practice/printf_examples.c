#include <stdio.h>

// reference: https://openhome.cc/Gossip/CGossip/PrintfScanf.html

/*******************************************************
%c：以字元方式輸出
%d：10 進位整數輸出
%o：以 8 進位整數方式輸出
%u：無號整數輸出
%x、%X：將整數以 16 進位方式輸出
%f：浮點數輸出
%e、%E：使用科學記號顯示浮點數
%g、%G：浮點數輸出，取 %f 或 %e（%f 或 %E），看哪個表示精簡
%%：顯示 %
%s：字串輸出
%lu：long unsigned 型態的整數
%p：指標型態
*********************************************************/

int main(void) 
{
    printf("顯示字元 %c \n", 'A');
    printf("顯示字元編碼 %d \n", 'A');
    printf("顯示字元編碼 %c \n", 65);    
    printf("顯示十進位整數 %d \n", 15);
    printf("顯示八進位整數 %o \n", 15);
    printf("顯示十六進位整數 %X \n", 15);
    printf("顯示十六進位整數 %x \n", 15);    
    printf("顯示科學記號 %E \n", 0.001234);    
    printf("顯示科學記號 %e \n\n", 0.001234);    
    
    printf("example:%.2f\n", 19.234);       // precision down to 0.01
    printf("example:%8.2f\n", 19.234);      // 8 char spaces, to right
    printf("example:%-8.2f\n", 19.234);     // 8 char spaces, to left

    return 0;
}