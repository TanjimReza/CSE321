#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
struct Process
{
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    int response_time;
    int priority;
};
int main()
{

    FILE *fp = fopen("ps_input.txt", "r");
    int process_count = 0;
    fscanf(fp, "%d", &process_count);
    printf("Process Count: %d\n", process_count);

    struct Process processes[process_count + 1];
    //! Reading Arrival Times
    for (int i = 0; i < process_count; i++)
    {
        int temp;
        fscanf(fp, "%d", &temp);
        processes[i].arrival_time = temp;
        processes[i].process_id = i;
        processes[i].completion_time = 0;
        processes[i].turn_around_time = 0;
        processes[i].waiting_time = 0;

        printf("Arrival Time: %d\n", processes[i].arrival_time);
    }
    printf("Read Arrival Times \n");
    //! Reading Burst Times
    for (int i = 0; i < process_count; i++)
    {
        int temp;
        fscanf(fp, "%d", &temp);
        processes[i].burst_time = temp;
        processes[i].remaining_burst_time = temp;
        // printf("Burst Time: %d\n", processes[i].burst_time);
    }
    for (int i = 0; i < process_count; i++)
    {
        int temp;
        fscanf(fp, "%d", &temp);
        processes[i].priority = temp;
        // processes[i].remaining_burst_time = temp;
        // printf("Burst Time: %d\n", processes[i].burst_time);
    }
    printf("Read Burst Times \n");

    //! Sorting the processes according to arrival time
    for (int i = 0; i < process_count; i++)
    {
        for (int j = i + 1; j < process_count; j++)
        {
            if (processes[i].arrival_time > processes[j].arrival_time)
            {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    fclose(fp);

    int pid_highest_priority = processes[0].process_id;
    int highest_priority = processes[0].priority;
    printf("PID with highest priority: %d\n", pid_highest_priority);
    printf("Highest Priority: %d\n", highest_priority);
    for (int i = 0; i < process_count; i++)
    {
        // printf("Priority of %d is %d\n", processes[i].process_id, processes[i].priority);

        if (processes[i].priority < highest_priority)
        {
            // printf("New Priority of %d is %d\n", processes[i].process_id, processes[i].priority);
            pid_highest_priority = processes[i].process_id;
            highest_priority = processes[i].priority;
        }
    }

    int completed = 0;
    int time = 0;
    printf("Going inside loop \n");
    while (completed < process_count)
    {
        for (int i = 0; i < process_count; i++)
        {
            // printf("Priority of %d is %d\n", processes[i].process_id, processes[i].priority);

            if (processes[i].priority < highest_priority && processes[i].priority >= 0)
            {
                // printf("New Priority of %d is %d\n", processes[i].process_id, processes[i].priority);
                pid_highest_priority = processes[i].process_id;
                highest_priority = processes[i].priority;
            }
        }
        printf("PID with highest priority: %d\n", pid_highest_priority);
        printf("Highest Priority: %d\n", highest_priority);

        int s_p = pid_highest_priority;

        for (int i = 0; i < process_count; i++)
        {
            if (processes[i].process_id == pid_highest_priority)
            {

                printf("Process %d is highest with %d priority \n", processes[i].process_id, processes[i].priority);
                if (processes[i].arrival_time <= time && processes[i].remaining_burst_time > 0)
                {
                    processes[i].remaining_burst_time--;

                    if (processes[i].remaining_burst_time == 0)
                    {
                        completed++;
                        processes[i].completion_time = time + 1;
                        processes[i].turn_around_time = processes[i].completion_time - processes[i].arrival_time;
                        processes[i].waiting_time = processes[i].turn_around_time - processes[i].burst_time;
                        break;
                    }
                }
            }
        }
        time++;
        printf("Time: %d\n", time);
    }

    // printf("PID with highest priority: %d\n", pid_highest_priority);
    // printf("Highest Priority: %d\n", highest_priority);

    printf("PID\tArrival Time\tBurst Time\tPrioroty\tCompletion Time\tTurn Around Time\tWaiting Time\n");
    for (int i = 0; i < process_count; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",
               processes[i].process_id,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].priority,
               processes[i].completion_time,
               processes[i].turn_around_time,
               processes[i].waiting_time);
    }
}