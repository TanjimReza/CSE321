#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define TOTAL_TICKETS 10
#define TOTAL_PERSONS 12

int tickets = TOTAL_TICKETS;
pthread_mutex_t ticketMutex;

void *purchaseTicket(void *arg)
{
    long person = (long)arg;

    pthread_mutex_lock(&ticketMutex);

    if (tickets > 0)
    {
        printf("Person %ld is purchasing\n", person);
        printf("Tickets left: %d\n", tickets);
        // Simulate ticket purchase time
        sleep(1);
        tickets--;
        printf("Person: %ld, Purchase Done\n", person);
    }
    else
    {
        printf("Person %ld can not purchase\n", person);
        printf("Tickets left: %d\n", tickets);
        printf("Person: %ld, Purchase failed\n", person);
    }

    pthread_mutex_unlock(&ticketMutex);
    return NULL;
}

int main()
{
    pthread_t persons[TOTAL_PERSONS];
    pthread_mutex_init(&ticketMutex, NULL);

    for (long i = 1; i <= TOTAL_PERSONS; i++)
    {
        pthread_create(&persons[i - 1], NULL, purchaseTicket, (void *)i);
        // Ensuring ordering: Wait for the first person in the pair to finish before starting the second
        if (i % 2 == 1)
        {
            pthread_join(persons[i - 1], NULL);
        }
    }

    // Joining the remaining threads
    for (int i = 0; i < TOTAL_PERSONS; i++)
    {
        if (i % 2 == 0)
        {
            pthread_join(persons[i], NULL);
        }
    }

    pthread_mutex_destroy(&ticketMutex);
    return 0;
}