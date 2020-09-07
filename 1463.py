import sys
n = int(sys.stdin.readline().rstrip())
#﻿3번째 항 정도까지의 결과를 미리 배열에 저장, 0일때는 포함이 되진 않지만 순서의 헷갈림을 방지하기 위해 넣어둠

l = [0, 0, 1, 1]

for i in range(4, n+1):
    if i % 3 == 0:
        l.append(min(l[i//3], l[i-1])+1)

    elif i % 2 == 0:
        l.append(min(l[i//2], l[i-1])+1)

    else:
        l.append(l[i-1]+1)

print(l[n])


