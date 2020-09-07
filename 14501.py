# import sys
#
# n = int(sys.stdin.readline().rstrip())
# a = [0]
# b = [0]
# dp =
#
# for i in range(0, n):
#     m, k = map(int, input().split())
#     a.append(m)
#     b.append(k)
#
#
# L = list(map(int, input().split()))  # 잃는 체력을 저장하는 리스트
#
# L.insert(0, 0)  # 순서의 헷갈림 방지를 위한 0번째 원소에 0 삽입
#
# J = list(map(int, input().split()))  # 얻는 기쁨을 저장하는 리스트
#
# J.insert(0, 0)
#
# K = [[0 for col in range(101)] for row in range(21)]
#
#
# def knapsack(n, m, weight, price):  # knapsack 알고리즘 함수
#
#     for i in range(1, n + 1):
#         for j in range(1, m + 1):
#
#             if weight[i] > j:
#                 K[i][j] = K[i - 1][j]
#             else:
#                 K[i][j] = max(K[i - 1][j - weight[i]] + price[i], K[i - 1][j])
#                 # MAX(현재 보석들의 가치+ 남은 가방 크기 만큼 나머지 보석을 넣을 때 최대 가치, 이전까지 구해둔 보석들의 가치)
#                 # 처음의 경우엔 MAX(가방에 들어있던 보석(1)을 빼고, 보석(2)을 넣을때의 가치, 이전 보석(1)의 가치)
#
#     return K[n][m]
#
#
# print(knapsack(n, 99, L, J))


import sys

n = int(sys.stdin.readline().rstrip())
t = []
p = []
dp = []
for i in range(n):
    a, b = map(int, input().split())
    t.append(a)
    p.append(b)
    dp.append(b)

# print(t)
# print(p)
dp.append(0) # 핵심 기저를 어디로 설정할 것인가.
# print(dp)
for i in range(n - 1, -1, -1): # for문 거꾸로 가는 방법도 생각해야.
    if t[i] + i > n: #핵심
        dp[i] = dp[i + 1]
    else:
        # print(dp[i+1], end =' ')
        # print(dp[i+t[i]] + p[i])
        dp[i] = max(dp[i + 1], p[i] + dp[i + t[i]])
print(dp[0])