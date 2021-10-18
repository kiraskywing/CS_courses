#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int R = 100, C = 100, N = 500000, max_d = 45;
    
    // printf("Generating garden...\n");
    printf("%d %d %d\n", R, C, N);
    srand(time(NULL));
    int di, ri, ci, type;
    while(N--){
	type = rand() % 1000;
        di = rand() % 15;
	if(!type){
            ri = rand() % R;
            ci = rand() % C;
	}
	else{
            di = max_d - di;
            ri = rand() % 2 + 49;
            ci = rand() % 2 + 49;
	}
	di = (di / 2) * 2 + 1;
        printf("%d %d %d\n", di, ri, ci);
    }
    
    return 0;
}
