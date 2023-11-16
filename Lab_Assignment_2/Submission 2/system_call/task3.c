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
    pid_t a = fork();
    pid_t b = fork();
    pid_t c = fork();
    int process_count = 0;

    if (a == 0)
    {
        int a_pid = getpid();
        if (a_pid % 2 != 0)
        {
            pid_t d = fork();
            process_count++;
            exit(0);
        }
        exit(0);
    }

    else if (a > 0)
    {
        process_count++;
    }

    if (b == 0)
    {
        int b_pid = getpid();
        if (b_pid % 2 != 0)
        {
            pid_t e = fork();
            process_count++;
            exit(0);
        }
        exit(0);
    }
    else if (b > 0)
    {
        process_count++;
    }
    if (c == 0)
    {
        int c_pid = getpid();
        if (c_pid % 2 != 0)
        {
            pid_t f = fork();
            process_count++;
            exit(0);
        }
        exit(0);
    }
    else if (c > 0)
    {
        process_count++;
    }
    printf("Process Count: %d\n", process_count);
    printf("END");
    return 0;
}