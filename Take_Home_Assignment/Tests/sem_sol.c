#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h> // this should be included

#define THREADC 12
int thread_ids[THREADC] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

int tickets_left = 10;
void *thread_function(int *id);
sem_t semaphore; // decalre semaphore

int main()
{
    int sempahore_value = 1;
    sem_init(&semaphore, 0, sempahore_value); // init semaphore with a value, must be before creating threads

    pthread_t threads[THREADC];

    for (int i = 0; i < THREADC; i++)
        pthread_create(&threads[i], NULL, (void *)thread_function, &thread_ids[i]);

    for (int i = 0; i < THREADC; i++)
        pthread_join(threads[i], NULL);

    sem_destroy(&semaphore); // destroy semaphore, must be after joining threads

    return 0;
}

void *thread_function(int *id)
{
    // printf("Entered in thread: %d\n", *id);
    // for (int i = 0; i < 100000; i++)
    // {
    //     sem_wait(&semaphore); // wait
    //     count++;
    //     sem_post(&semaphore); // signal
    // }
    if (tickets_left > 0)
    {
        printf("Person %d is purchasing\n", *id);
        sem_wait(&semaphore);
        printf("Tickets left: %d\n", tickets_left);
        tickets_left--;
        printf("Person: %d, Purchase Done\n", *id);
        sem_post(&semaphore);
    }
    else
    {
        printf("Person: %d can not purchase\n", *id);
        printf("Tickets left: %d\n", tickets_left);
        printf("Person: %d, Purchase failed\n", *id);
    }
}