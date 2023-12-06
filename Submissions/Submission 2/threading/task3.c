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
void *name_to_ascii_sum(void *name);

void *t_ret_1;
void *t_ret_2;
void *t_ret_3;
int sum;

int main()
{

    char name_1[100];
    char name_2[100];
    char name_3[100];

    printf("Enter Name-1: ");
    fgets(name_1, 100, stdin);
    printf("Enter Name-2: ");
    fgets(name_2, 100, stdin);
    printf("Enter Name-3: ");
    fgets(name_3, 100, stdin);

    int sum_1 = 0;
    int sum_2 = 0;
    int sum_3 = 0;
    pthread_t thread_1, thread_2, thread_3;
    pthread_create(&thread_1, NULL, (void *)name_to_ascii_sum, (void *)name_1);
    pthread_join(thread_1, &t_ret_1);
    sum_1 = *(int *)t_ret_1;
    printf("Sum of ASCII values of %s is %d\n", name_1, *(int *)t_ret_1);

    pthread_create(&thread_2, NULL, (void *)name_to_ascii_sum, (void *)name_2);
    pthread_join(thread_2, &t_ret_2);
    sum_2 = *(int *)t_ret_2;
    printf("Sum of ASCII values of %s is %d\n", name_2, *(int *)t_ret_2);

    pthread_create(&thread_3, NULL, (void *)name_to_ascii_sum, (void *)name_3);
    pthread_join(thread_3, &t_ret_3);
    sum_3 = *(int *)t_ret_3;
    printf("Sum of ASCII values of %s is %d\n", name_3, *(int *)t_ret_3);

    if (sum_1 == sum_2 && sum_2 == sum_3)
    {
        printf("Youreka"); // Shobai milse
    }

    else if (sum_1 != sum_2 && sum_1 != sum_3 && sum_2 != sum_3)
    {
        printf("Hasta la vista"); //Keu Mile nai
    }
    else {
        printf("Miracle"); // 2ta milse
    }

    return 0;
}

void *funcThread(int *n)
{
    printf("thread-%d running\n", *n);
}

void *name_to_ascii_sum(void *name)
{
    char *new_name = name;
    sum = 0;
    for (int i = 0; i < strlen(new_name); i++)
    {
        sum += new_name[i];
        // printf("name[%d] = %c, sum = %d\n", i, new_name[i], sum);
    }
    // printf("Sum of ASCII values of %s is %d\n", new_name, sum);
    pthread_exit(&sum);
}