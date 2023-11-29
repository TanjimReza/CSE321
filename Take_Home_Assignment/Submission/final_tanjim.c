#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define THREADC 12
int thread_ids[THREADC] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

int tickets_left = 10;
void *thread_function(int *id);

sem_t SEMAPHORE_ONE;
sem_t SEMAPHORE_TWO;

int main()
{
    int LIMIT_PURCHASE = 1;
    int LIMIT_PEOPLE = 2;

    sem_init(&SEMAPHORE_ONE, 0, LIMIT_PURCHASE);
    sem_init(&SEMAPHORE_TWO, 0, LIMIT_PEOPLE);

    pthread_t threads[THREADC];

    for (int i = 0; i < THREADC; i++)
    {
        pthread_create(&threads[i], NULL, (void *)thread_function, &thread_ids[i]);
        // printf("Thread %d created\n", i);
    }

    //! Joining Threads two by two at a time
    for (int i = 0; i < THREADC; i += 2)
    {
        //* Person-1
        pthread_join(threads[i], NULL);
        //* Person-2
        pthread_join(threads[i + 1], NULL);
    }
    sem_destroy(&SEMAPHORE_ONE);
    sem_destroy(&SEMAPHORE_TWO);
    return 0;
}

void *thread_function(int *id)
{

    sem_wait(&SEMAPHORE_TWO);
    // printf(":::Thread %d created\n", *id);
    sleep(1);
    sem_wait(&SEMAPHORE_ONE);
    if (tickets_left > 0)
    {
        printf("Person %d is purchasing\n", *id);
        printf("Tickets left: %d\n", tickets_left);
        sleep(1);
        tickets_left--;
        printf("Person: %d, Purchase Done\n", *id);
    }
    else
    {
        printf("Person %d can not purchase\n", *id);
        printf("Tickets left: %d\n", tickets_left);
        printf("Person: %d, Purchase failed\n", *id);
    }
    sem_post(&SEMAPHORE_ONE);
    sem_post(&SEMAPHORE_TWO);
    pthread_exit(NULL);
}