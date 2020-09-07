# import sys
# n = int(sys.stdin.readline().rstrip())
# #맨 오른쪽에 개행 문자가 있다고 생각
# scores = list(map(int, input().split()))
# scores.sort()
# print(scores[n-1]-scores[0])
from numpy import zeros, array, arange
import matplotlib.pyplot as plt

n = 4
m = 4
y = zeros([n, m])


print(y)
print(' ')

y[1,2] = 4
print(y[1])
print(' ')

print(y[1, 2])


