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
};
int main()
{

    FILE *fp = fopen("rr_input.txt", "r");
    int process_count = 0;
    fscanf(fp, "%d", &process_count);
    printf("Process Count: %d\n", process_count);

    int time_quantum = 0;
    fscanf(fp, "%d", &time_quantum);
    printf("Time Quantum: %d\n", time_quantum);

    struct Process processes[process_count + 1];
    //! Reading Arrival Times
    for (int i = 0; i < process_count; i++)
    {
        int temp;
        fscanf(fp, "%d", &temp);
        processes[i].burst_time = temp;
        processes[i].remaining_burst_time = temp;
        processes[i].arrival_time = 0;
        processes[i].completion_time = 0;
        processes[i].turn_around_time = 0;
        processes[i].waiting_time = 0;
        processes[i].process_id = i;
        // printf("Arrival Time: %d\n", processes[i].arrival_time);
    }
    printf("Read Arrival Times - 0 \n");
    //! Reading Burst Times
    // for (int i = 0; i < process_count; i++)
    // {
    //     int temp;
    //     fscanf(fp, "%d", &temp);
    //     processes[i].burst_time = temp;
    //     processes[i].remaining_burst_time = temp;
    //     // printf("Burst Time: %d\n", processes[i].burst_time);
    // }
    printf("Read Burst Times \n");

    // int time = 0;
    // int flag = 1;
    // while (flag)
    // {
    //     flag = 0;
    //     for (int i = 0; i < process_count; i++)
    //     {
    //         if (processes[i].remaining_burst_time > time_quantum)
    //         {
    //             printf("Process %d is running for %d seconds\n", processes[i].process_id, time_quantum);
    //             time = time + time_quantum;
    //             processes[i].remaining_burst_time = processes[i].remaining_burst_time - time_quantum;
    //             flag = 1;
    //         }
    //         else
    //         {
    //             time = time + processes[i].remaining_burst_time;
    //             processes[i].remaining_burst_time = 0;
    //             processes[i].completion_time = time;
    //             processes[i].turn_around_time = processes[i].completion_time - processes[i].arrival_time;
    //             processes[i].waiting_time = processes[i].turn_around_time - processes[i].burst_time;
    //             flag = 1;
    //         }
    //     }
    // }
    int time = 0;
    int completed = 0;
    while (process_count > completed)
    {

        for (int i = 0; i < process_count; i++)
        {
            if (processes[i].remaining_burst_time > time_quantum)
            {
                time += time_quantum;
                processes[i].remaining_burst_time -= time_quantum;
            }
            else if (processes[i].remaining_burst_time > 0)
            {
                time += processes[i].remaining_burst_time;
                processes[i].remaining_burst_time = 0;
                processes[i].completion_time = time;
                processes[i].turn_around_time = processes[i].completion_time - processes[i].arrival_time;
                processes[i].waiting_time = processes[i].turn_around_time - processes[i].burst_time;
                completed++;
            }
        }
    }
    printf("Process Id\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n");
    for (int i = 0; i < process_count; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turn_around_time, processes[i].waiting_time);
    }
}