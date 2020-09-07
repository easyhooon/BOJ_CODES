#사전 순으로 출력한다.
#출력은 6개만...
import sys
import random
import operator as op
from functools import reduce

# d = []
# tmp = []
#
# while 1:
#     n = list(map(int, input().split()))
#     if n[0] == 0:
#         break
#     else:
#         for i in range(1, n[0]+1):
#             for j in range(1, n[0] + 1):
#                 if j == i:
#                     pass
#                 else:
#                     tmp.append(n[j])
#
#             d.append(tmp)
#             tmp = []
#
#         d.sort()
#         for i in d:
#             print(i)
#         d = []
#
#
# n = int(sys.stdin.readline().rstrip())

# n = [8, 1, 2, 3, 5, 8, 13, 21, 34]


# def nCr(n, k):
#     numerator = 1
#     denominator = 1
#     k = min(n-k, k) #조합의 대칭성을 이용하여 더 적은 수의 연산을 하기 위해서입니다.
#     for i in range(1, k+1):
#         denominator *= i
#         numerator *= n+1-i
#     return numerator//denominator
#
# list = []
# ran_num = 0
#
# for i in range(0, nCr(n[0], 6)):
#     ran_num = 0
#     while ran_num not in n:
#         ran_num = random.randint(1, 50)
#     if ran_num != n[0]:
#         if ran_num not in list:
#             list.append(ran_num)
# list.sort()
# print(list)

def dfs(start, depth):
    if depth == 6:
        for i in range(6):
            print("{0} ".format(ans[i]), end='')
        print('')
        return

    else:
        for i in range(start, k):
            ans[depth] = d[i]
            # print(ans[depth])
            dfs(i + 1, depth + 1)

while True:
    d = list((map(int, input().split())))
    k = d[0] #한 줄에 숫자

    ans = [0 for _ in range(k)]  # _ 자리엔 자료형의 제약받지않고 아무거나 들어올 수 있다. 인덱스의 의미가 없을때에도 사용\
    # k만큼의 0으로 채워진 리스트를 생성해라

    if k == 0:
        break
    d = d[1:] #첫번째 원소 제외할때 쓰이는 스킬
    dfs(0, 0)
    print('') # 각 경우 사이의 한칸의 공백


# import sys
# from itertools import combinations
# input = sys.stdin.readline
#
# flag = True
#
# while flag:
#     d = list(map(int, input().split()))
#     n = int(d[0])
#     if n == 0:
#         flag == False
#         break
#
#     for case in combinations(d[1:], 6):
#         print(' '.join(map(str, case)))
#     print('')