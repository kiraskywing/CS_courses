#include<stdio.h>
int main(){
    // input N
    int N;
    float Bill=0;
    scanf("%d", &N);
    //printf("%d\n", N);

    // calculate the bill
    if(N<=120)
        Bill = N*1.63;
    else if(N>120 && N<=330)
        Bill = 120*1.63 + (N-120)*2.38;
    else if(N>330 && N<=500)
        Bill = 120*1.63 + (330-120)*2.38 + (N-330)*3.52;
    else if(N>500 && N<=700)
        Bill = 120*1.63 + (330-120)*2.38 + (500-330)*3.52 + (N-500)*4.8;
    else if(N>700 && N<=1000)
        Bill = 120*1.63 + (330-120)*2.38 + (500-330)*3.52 + (700-500)*4.8 + (N-700)*5.66;
    else
        Bill = 120*1.63 + (330-120)*2.38 + (500-330)*3.52 + (700-500)*4.8 + (1000-700)*5.66 + (N-1000)*6.41;
    
    // output Bill
    printf("%.0f\n", Bill);
}
