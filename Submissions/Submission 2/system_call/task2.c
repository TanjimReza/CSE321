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

    // child process
    int pid = fork();
    if (pid == 0)
    {

        int pid2 = fork();
        if (pid2 == 0)
        {
            printf("I am grandchild\n");
        }
        else if (pid2 < 0)
        {
            printf("Error in Fork\n");
        }
        else
        {
            wait(NULL);
            printf("I am child\n");
        }
    }
    else if (pid < 0)
    {
        printf("Error in Fork\n");
    }
    else
    {
        wait(NULL);
        printf("I am parent\n");
    }
}
