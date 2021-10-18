#include<stdio.h>
int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    //printf("%d %d %d\n", a, b, c);
    
    // let a be the longest segment
    int tmpt;
    if(a<b){
        if(b<c){    // c is longest
            tmpt = a;
            a = c;
            c = tmpt;
        }
        else{       // b is longest
            tmpt = a;
            a = b;
            b = tmpt;
        }
    }
    else{
        if(a<c){    // c is longest
            tmpt = a;
            a = c;
            c = tmpt;
        }
    }
    
    // determine if a, b, c can form triangle by triangle inequality
    if(b+c>a){  // is a triangle, then determine the type of the triangle
        if(b*b + c*c == a*a){
            printf("right triangle\n");
        }
        else if(b*b + c*c < a*a){
            printf("obtuse triangle\n");
        }
        else{
            printf("acute triangle\n");
        }
    }
    else{       // is NOT a triangle
        printf("OOPS\n");
    }
    return 0;
}
