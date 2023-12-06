#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void *funcThread(int *n);

void *t_ret;

int main()
{
    pthread_t t1[6];
    for (int i = 1; i <= 5; i++)
    {
        // pthread_t t1;
        pthread_create(&t1[i], NULL, (void *)funcThread, &i);
        pthread_join(t1[i], &t_ret);
        printf("thread-%d closed\n", i);
    }
    return 0;
}

void *funcThread(int *n)
{
    printf("thread-%d running\n", *n);
}