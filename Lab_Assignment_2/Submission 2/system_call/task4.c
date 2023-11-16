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
    // I had to add the NULL at the end of the array to make it work in cygwin
    // But in native POSIX Machine it is not needed

    char *arr[] = {"", "5", "7", "1", "6", "8", NULL};

    // create a child process
    int pid = fork();

    if (pid == 0)
    {
        printf("Child Process\n");
        printf("Going to Child");
        execv("./sort", arr);
        
    }
    else
    {
        wait(NULL);
        printf("Parent Process\n");
        printf("Going to Child");
        execv("./oddeven", arr);
    }
}