import sys

n = str(sys.stdin.readline().rstrip())

n_list = list(n)

temp_sum = 0
for i in n_list:
    temp_sum += int(i)

if temp_sum % 3 == 0 and '0' in n_list:
    n_list.sort(reverse = True)
    for i in n_list:
        print(i, end='')

else:
    print('-1')

