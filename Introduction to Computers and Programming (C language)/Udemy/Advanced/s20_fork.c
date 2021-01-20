#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h>
  
int main(void) 
{ 
    // Creating first child 
    pid_t n1 = fork(); 
  
    // Creating second child. First child also executes this line and creates grandchild. 
    pid_t n2 = fork(); 
  
    if (n1 > 0 && n2 > 0) 
    { 
        printf("parent\n"); 
        printf("%d %d \n", n1, n2); 
        printf("   my id is %d \n", getpid()); 
        printf("   my parentid is %d \n", getppid()); 
    } 
    else if (n1 == 0 && n2 > 0) 
    { 
        printf("\nFirst child\n"); 
        printf("%d %d \n", n1, n2); 
        printf("   my id is %d  \n", getpid()); 
        printf("   my parentid is %d \n", getppid()); 
    } 
    else if (n1 > 0 && n2 == 0) 
    { 
        printf("\nsecond child\n"); 
        printf("%d %d \n", n1, n2); 
        printf("   my id is %d  \n", getpid()); 
        printf("   my parentid is %d \n", getppid()); 
    } 
    else 
    { 
        printf("\nthird child\n"); 
        printf("%d %d \n", n1, n2); 
        printf("   my id is %d \n", getpid()); 
        printf("   my parentid is %d \n", getppid()); 
    } 
  
    return 0; 
} 




