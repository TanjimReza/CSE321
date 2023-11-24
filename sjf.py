class Process:
    def __init__(self, process_id, arrival_time, burst_time):
        self.process_id = process_id
        self.arrival_time = arrival_time
        self.burst_time = burst_time
        self.remaining_burst_time = burst_time
        self.completion_time = 0
        self.turnaround_time = 0
        self.waiting_time = 0


"""
5 
0 2 3 4 5
5 2 7 4 5
"""
process_list = []
process_0 = Process(0, 0, 5)
process_1 = Process(1, 2, 2)
process_2 = Process(2, 3, 7)
process_3 = Process(3, 4, 4)
process_4 = Process(4, 5, 5)
process_5 = Process(5, 999, 999)
process_list.append(process_0)
process_list.append(process_1)
process_list.append(process_2)
process_list.append(process_3)
process_list.append(process_4)
process_list.append(process_5)


# sort by arrival time
max_burst_time = 0
for i in range(len(process_list)):
    for j in range(i + 1, len(process_list)):
        if process_list[i].arrival_time > process_list[j].arrival_time:
            process_list[i], process_list[j] = process_list[j], process_list[i]
        if process_list[i].burst_time > max_burst_time:
            max_burst_time = process_list[i].burst_time



max_iteration = 30
t = 0
count_ = 0


while count_ < 5 and max_iteration > 0:
    max_iteration -= 1
    min_ = 5

    for i in range(5):
        process = process_list[i]
        if process.arrival_time <= t and process.remaining_burst_time < process_list[min_].remaining_burst_time and process.remaining_burst_time > 0:
            min_ = process.process_id

    print(f"P{min_} - Remains: {process_list[min_].remaining_burst_time}")
    process_list[min_].remaining_burst_time -= 1
    print(f"P{min_} - U-Remains: {process_list[min_].remaining_burst_time}")

    if process_list[min_].remaining_burst_time == 0:
        count_ += 1
        print(f"P{min_} - Completed.")
        process_list[min_].completion_time = t + 1
        process_list[min_].turnaround_time = process_list[min_].completion_time - \
            process_list[min_].arrival_time
        process_list[min_].waiting_time = process_list[min_].turnaround_time - \
            process_list[min_].burst_time

    t += 1
    print(t)
# # print all the processes with arrival time and completion time
for i in range(len(process_list)-1):
    print(f"Process: {process_list[i].process_id} - AT: {process_list[i].arrival_time} - CT: {process_list[i].completion_time} - TAT: {process_list[i].turnaround_time} - WT: {process_list[i].waiting_time}")
