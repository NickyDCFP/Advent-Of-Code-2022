import time
import heapq
start_time = time.time()
filename = "day1_input.txt"
n = 3

f = open(filename, "r")
sum_cals = 0
lst = []
for line in f:
    if line == "\n":
        lst.append(sum_cals)
        sum_cals = 0
    else:
        sum_cals += int(line)
print(f"Max {n} elf snacks total {sum(heapq.nlargest(n, lst))} calories.",
      f"Completed in {time.time() - start_time} seconds.")