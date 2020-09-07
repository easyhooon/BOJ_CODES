import sys
n = int(sys.stdin.readline().rstrip())
op = input().split()
op.append('')
count_i = 0
count_d = 0
MAX = 9
MIN = 0
max_num = []
min_num = []

# 최대
for i in range(n+1):
    if len(max_num) == (n+1):
        break

    if op[i] == '<':
        count_i += 1
    else:
        x_num = MAX - count_i - 1 # count_i개 를 썼으니까 이제 가능한 가장 큰 숫자는 1 더 작은 수
        while True:
            max_num.append(MAX-count_i)
            if count_i == 0:
                MAX = x_num
                break
            count_i -= 1

# 최소
for i in range(n+1):
    if len(min_num) == (n+1):
        break
    if op[i] == '>':
        count_d += 1
    else:
        n_num = MIN + count_d + 1 # count_d개를 썼으니까 이제 가능한 가장 작은 숫자는 1 더 큰 수
        while True:
            min_num.append(MIN+count_d)
            if count_d == 0:
                MIN = n_num
                break
            count_d -= 1


for i in range(n+1):
    print(max_num[i], end='')

print()

for i in range(n+1):
    print(min_num[i], end='')