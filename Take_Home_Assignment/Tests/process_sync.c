/*
Assignment Based Quiz
Duration: 24 Hours
There is a high voltage match between Manchester City and Tottenham Hotspurs on December 2.
Fans of both teams are very excited about the match and they are keen to watch the match live in the stadium.
Tickets for the match have almost been sold out.
There are only 10 tickets left. Fans have to maintain a queue according to the first come first serve manner while purchasing tickets.
In order to maintain the rule a serial number has been assigned to each who is in the queue.
Serials have been assigned in 1, 2 , 3, ……………, n according to the first come first serve order.
The current scenario is, there are 10 tickets available and 12 persons in the queue. And there are 2 booths for purchasing tickets.
Tickets gets sold in the following order, first two persons (1 and 2 in this case) gets called to two booths together but after the purchase gets completed of person 1
then person 2 starts the procedure of his purchase then after the completion of his purchase both of them left booths then next two persons from the queue gets called to booths for purchasing (3 and 4 in this case).
If tickets get finished, booths get closed.
Then nobody from the queue can purchase tickets anymore. That is how the entire ticket selling procedure works.
According to the current scenario, there are 10 tickets left and 12 persons in the queue for purchasing tickets.
Design a proper solution to the scenario that how the entire procedure of selling tickets can be synchronized based on the procedure described above.
You have to design a solution and explain it briefly in order to provide the solution.
Consider the number of remaining tickets as the shared variable and order of persons in the queue 1,2,3,..........,12.
Consider 12 persons as 12 threads here.
The outcome of the solution should look like the following:
Person 1 is purchasing
Tickets left: 10
Person: 1, Purchase Done
Person 2 is purchasing
Tickets left: 9
Person: 2, Purchase Done
Person 3 is purchasing
Tickets left: 8
Person: 3, Purchase Done
Person 4 is purchasing
Tickets left: 7
Person: 4, Purchase Done
Person 5 is purchasing
Tickets left: 6
Person: 5, Purchase Done
Person 6 is purchasing
Tickets left: 5
Person: 6, Purchase Done
Person 7 is purchasing
Tickets left: 4
Person: 7, Purchase Done
Person 8 is purchasing
Tickets left: 3
Person: 8, Purchase Done
Person 9 is purchasing
Tickets left: 2
Person: 9, Purchase Done
Person 10 is purchasing
Tickets left: 1
Person: 10, Purchase Done
Person 11 can not purchase
Tickets left: 0
Person: 11, Purchase failed
Person 12 can not purchase
Tickets left: 0
Person: 12, Purchase
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define TOTAL_CUSTOMERS 12
int customer_ids[TOTAL_CUSTOMERS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int tickets_left = 10;

void *thread_function(int *id);
pthread_mutex_t mutex;

int main()
{

    pthread_mutex_init(&mutex, NULL);
    pthread_t threads[TOTAL_CUSTOMERS];

    int ready_thread_count = 0;
    // Create all the threads
    for (int i = 0; i < TOTAL_CUSTOMERS; i++){
        sleep(1);
        pthread_create(&threads[i], NULL, (void *)thread_function, &customer_ids[i]);
    }
    // Join two threads in two booths together
    for (int i = 0; i < TOTAL_CUSTOMERS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}

void *thread_function(int *id)
{

    // if mutex is set then run else wait

    if (tickets_left > 0)
    {
        printf("Person %d is purchasing\n", *id);
        pthread_mutex_lock(&mutex);
        printf("Tickets left: %d\n", tickets_left);
        tickets_left--;
        printf("Person: %d, Purchase Done\n", *id);
        pthread_mutex_unlock(&mutex);
    }
    else
    {
        printf("Person: %d can not purchase\n", *id);
        printf("Tickets left: %d\n", tickets_left);
        printf("Person: %d, Purchase failed\n", *id);
    }
    return NULL;
}