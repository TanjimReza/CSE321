#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h> // this should be included

#define THREADC 12
int thread_ids[THREADC] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

int tickets_left = 10;

void *thread_function(int *id);
// void *booth_function(int *id);

sem_t semaphore; // decalre semaphore
sem_t boothSemaphore;    // counting semaphore
int main()
{
    int sempahore_value = 1;
    int semaphore_for_booth = 2;
    sem_init(&semaphore, 0, sempahore_value); // init semaphore with a value, must be before creating threads
    sem_init(&boothSemaphore, 0, semaphore_for_booth);
    pthread_t threads[THREADC];

    for (int i = 0; i < THREADC; i += 2)
    {
        pthread_create(&threads[i], NULL, (void *)thread_function, &thread_ids[i]);
        pthread_create(&threads[i + 1], NULL, (void *)thread_function, &thread_ids[i + 1]);
        // printf("Thread %d created\n", i);
        // printf("Thread %d created\n", i + 1);
    }

    for (int i = 0; i < THREADC; i += 2)
    {
        pthread_join(threads[i], NULL);
        pthread_join(threads[i + 1], NULL);
    }
    sem_destroy(&semaphore);
    sem_destroy(&boothSemaphore);
    return 0;
}

void *thread_function(int *id)
{

    sem_wait(&boothSemaphore);
    printf(":::Thread %d created\n", *id);
    sleep(1);
    sem_wait(&semaphore);
    if (tickets_left > 0)
    {
        printf("Person %d is purchasing\n", *id);
        printf("Tickets left: %d\n", tickets_left);
        // sleep(1);
        tickets_left--;
        printf("Person: %d, Purchase Done\n", *id);
    }
    else
    {
        printf("Person %d can not purchase\n", *id);
        printf("Tickets left: %d\n", tickets_left);
        printf("Person: %d, Purchase failed\n", *id);
    }
    sem_post(&semaphore);
    sem_post(&boothSemaphore);
    pthread_exit(NULL);
}