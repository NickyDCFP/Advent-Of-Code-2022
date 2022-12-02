import time
start_time = time.time()
filename = "day1_input.txt"

f = open(filename, "r")
sum_cals = 0
mx = -1
for line in f:
    if line == "\n":
        mx = max(mx, sum_cals)
        sum_cals = 0
    else:
        sum_cals += int(line)
print(f"The elf with most calories carries {mx} calories.",
      f"Completed in {time.time() - start_time} seconds.")