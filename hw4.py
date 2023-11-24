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
process_list.append(process_0)
process_list.append(process_1)
process_list.append(process_2)
process_list.append(process_3)
process_list.append(process_4)

# sort by arrival time
max_burst_time = 0
for i in range(len(process_list)):
    for j in range(i + 1, len(process_list)):
        if process_list[i].arrival_time > process_list[j].arrival_time:
            process_list[i], process_list[j] = process_list[j], process_list[i]
        if process_list[i].burst_time > max_burst_time:
            max_burst_time = process_list[i].burst_time


# SJF
t = 0
countt = 0
minn = len(process_list) + 1
burst_time_min = max_burst_time + 1
print(f"{t=} {countt=} {minn=} {burst_time_min=}")

# while not all process are done
while countt < len(process_list):
    print("ok")
	
   
  	countt += 1

# print("done")
