import sys

a = str(sys.stdin.readline().rstrip())
a_list = list(a)
count = 0

for i in range(0, len(a_list)//2):
    if a_list[i] == a_list[len(a_list)-1-i]:
        count += 1

print(count)



