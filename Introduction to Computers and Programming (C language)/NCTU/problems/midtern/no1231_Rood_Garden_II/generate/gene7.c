#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int R = 100, C = 100, N = 300000, max_d = 95;
    
    // printf("Generating garden...\n");
    printf("%d %d %d\n", R, C, N);
    srand(time(NULL));
    int di, ri, ci, type;
    while(N--){
	type = rand() % 1000;
	di = rand() % 25;
	if(type){
	    di += 70;
	}
	di = (di / 2) * 2 + 1;
	
	type = rand() % 4;
	if(type % 2){
            ri = (type / 2) ? 0 : (R - 1);
            ci = rand() % C;
	}
	else{
            ri = rand() % R;
            ci = (type / 2) ? 0 : (C - 1);
	}
        printf("%d %d %d\n", di, ri, ci);
    }
    
    return 0;
}
