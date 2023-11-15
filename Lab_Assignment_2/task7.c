#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t child = fork();
    pid_t status;
    if (child == 0)
    {
        printf("2. Child Process ID: %d \n", getpid());
        pid_t grand_child_1 = fork();
        if (grand_child_1 == 0)
        {
            printf("3. Grand Child Process ID: %d \n", getpid());
            exit(0);
        }

        pid_t grand_child_2 = fork();
        if (grand_child_2 == 0)
        {
            printf("4. Grand Child Process ID: %d \n", getpid());
            exit(0);
        }
        pid_t grand_child_3 = fork();
        if (grand_child_3 == 0)
        {
            printf("5. Grand Child Process ID: %d \n", getpid());
            exit(0);
        }
    }
    else if (child > 0)
    {
        printf("1. Parent process ID: 0 \n");
        wait(&status);
    }
    else
    {
        printf("Error in Fork\n");
    }
}