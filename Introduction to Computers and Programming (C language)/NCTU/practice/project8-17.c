#include <stdio.h>

int main(void) {

    int count, n, x, y, x_last, y_last;
    
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &n);

    int square[n][n];
    
    for (x = 0; x < n; x++) {
        for (y = 0; y < n; y++) {
            square[x][y] = 0;
        }
    }

    x = n / 2; 
    y = 0;
    square[x][y] = 1;

    count = 2;
    while (count <= n * n) {
        x_last = x;
        x = (x + 1) % n;
        y = (y - 1 < 0 ? n - 1 : y - 1);
        
        if (square[x][y] == 0) {
            square[x][y] = count++;
        } else {
            x = x_last;
            y = (y + 2) % n;
            square[x][y] = count++;
        }
    }

    for (y = 0; y < n; y++) {
        for (x = 0; x < n; x++) {
            printf("%4d", square[x][y]);
        }
        printf("\n");
    }
    
    return 0;
}
