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

        // printf("Arrival Time: %d\n", processes[i].arrival_time);
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
    printf("Sorted \n");

    // int count = 0;
    // int t = 0;
    // priority scheduling
    // while (count < process_count)
    // {
    //     int min = process_count;
    //     for (int i = 0; i < process_count; i++)
    //     {
    //         if (processes[i].arrival_time <= t && processes[i].priority < processes[min].priority && processes[i].completion_time == 0)
    //         {
    //             min = i;
    //         }
    //     }
    //     if (min == process_count)
    //     {
    //         t++;
    //         continue;
    //     }
    //     processes[min].remaining_burst_time--;
    //     if (processes[min].remaining_burst_time == 0)
    //     {
    //         processes[min].completion_time = t + 1;
    //         processes[min].turn_around_time = processes[min].completion_time - processes[min].arrival_time;
    //         processes[min].waiting_time = processes[min].turn_around_time - processes[min].burst_time;

    //         count++;
    //     }
    //     t++;
    // }
    int max_priority_process = 0;
    for (int i = 0; i < process_count; i++)
    {
        if (processes[i].priority < processes[max_priority_process].priority)
        {
            max_priority_process = i;
        }
    }
    printf("max_priority_process: %d\n", max_priority_process);
    int count = 0;
    int t = 0;
    sleep(1);

    while (count < process_count)
    {
        int max_priority_process = -1;
        for (int i = 0; i < process_count; i++)
        {
            if (processes[i].arrival_time <= t && processes[i].remaining_burst_time > 0 && processes[i].priority < processes[max_priority_process].priority)
            {
                max_priority_process = i;
            }
        }
        processes[max_priority_process].remaining_burst_time--;

        if (processes[max_priority_process].remaining_burst_time == 0)
        {
            count++;
            processes[max_priority_process].completion_time = t + 1;
            processes[max_priority_process].turn_around_time = processes[max_priority_process].completion_time - processes[max_priority_process].arrival_time;
            processes[max_priority_process].waiting_time = processes[max_priority_process].turn_around_time - processes[max_priority_process].burst_time;
        }

        t++;
    }
    printf("PID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurn Around Time\tWaiting Time\n");
    for (int i = 0; i < process_count; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",
               processes[i].process_id,
               processes[i].arrival_time,
               processes[i].burst_time,
               //    processes[i].remaining_burst_time,
               processes[i].priority,
               processes[i].completion_time,
               processes[i].turn_around_time,
               processes[i].waiting_time);
    }
}
