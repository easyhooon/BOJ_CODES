#부분점수
import sys
n = int(sys.stdin.readline().rstrip())

one_d = []
two_d = []
all_result = 0

def distance(d):
    result = 0
    for i in range(0, len(d)):
        min_num = 9999999
        for j in range(0, len(d)):
            if i == j:
                continue
            else:
                if abs(d[i] - d[j]) < min_num:
                    min_num = abs(d[i] - d[j])
        result += min_num
    return result

for i in range(0, n):
    a, b = map(int, input().split())
    if b == 1:
        one_d.append(a)
    else:
        two_d.append(a)

all_result += distance(one_d)
all_result += distance(two_d)


print(all_result)
