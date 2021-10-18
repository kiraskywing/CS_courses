#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int R = 100, C = 100, N = 1000000, max_d = 25;
    
    // printf("Generating garden...\n");
    printf("%d %d %d\n", R, C, N);
    srand(time(NULL));
    int di, ri, ci, type;
    while(N--){
        di = rand();
        ri = rand() % 25;
        ci = rand() % 25;
        type = rand() % 4;
	switch(type){
	    case 0: {
		di %= 11;
		break;
	    }
	    case 1: {
		di %= 13;
		ri = (R - 1 - ri);
		break;
	    }
	    case 2: {
		di %= 19;
		ci = (C - 1 - ci);
		break;
	    }
	    case 3: {
		di %= 11;
		ri = (R - 1 - ri);
		ci = (C - 1 - ci);
		break;
	    }
	}
	di = (di / 2) * 2 + 1;
        printf("%d %d %d\n", di, ri, ci);
    }
    
    return 0;
}
