#include <stdio.h>
#include <pthread.h>

#define NTHREADS 10

int counter = 0;
 
void* func1(void* data)
{
    int *x = (int *) data;
   
    counter++;
    printf("message is %d, thread id = %d modified the counter to %d\n", *x, (int) pthread_self(), counter);
    printf("message is %d, thread id = %d read the counter %d\n", *x, (int) pthread_self(), counter);
    return NULL;
}

int main(void)
{
    pthread_t thread_id[NTHREADS];
    int values[NTHREADS];

    for(int i = 0; i < NTHREADS; i++) 
    {
        values[i] = i;
        pthread_create(&thread_id[i], NULL, func1, &values[i]);
    }

    for(int j = 0; j < NTHREADS; j++) 
    {
        pthread_join(thread_id[j], NULL); 
        pthread_exit(&thread_id[j]);
    }

    return 0;
}
