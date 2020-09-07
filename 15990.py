# #단, 같은 수를 두 번 이상 연속해서 사용하면 안 된다.
import sys
n = int(sys.stdin.readline().rstrip())

#dp[i][j] -> i번째 수가 덧셈의 마지막 수가 j일때의 경우의 수 , 첫번째 수라 해도 되고
# ex) 첫번째 수 라했을때 숫자가 n일 경우
# 1 + n-1 -> 맨앞자리가 2 or 3 이어야 됨 1+2+n-3 과 1+3+n-4 로 분할
#
# 2 + n-2 -> 맨앞자리가 1 or 3 이어야 됨 2+1+n-3 과 1+3+n-4
#
# 3 + n-3 -> 맨앞자리가 1 or 2 이어야됨 3+1+n-4 과 3+2+n-5

dp = [[0 for i in range(4)] for j in range(100001)]
dp[1][1] = 1
dp[2][2] = 1
dp[3][1] = 1
dp[3][2] = 1
dp[3][3] = 1

for j in range(4, 100001):
    dp[j][1] = (dp[j - 1][2] + dp[j - 1][3])%1000000009
    dp[j][2] = (dp[j - 2][1] + dp[j - 2][3])%1000000009
    dp[j][3] = (dp[j - 3][1] + dp[j - 3][2])%1000000009

for i in range(0, n):
    k = int(sys.stdin.readline().rstrip())
    ans = dp[k][1] + dp[k][2] + dp[k][3]
    print(ans % 1000000009)

#마지막 자리가 3 이면 그 앞에는 1 or 2
#마지막 자리가 2이면 그 앞에는 1 or 3
#마지막 자리가 1이면 그 앞에는 2 or 3



#
# 1 -> 1
# 2 -> 2
# 3 -> 1+2, 2+1, 3 (n-2 + 2) (n-1 + 1) (n)
# 4 -> 1+2+1 1+3 3+1 (n-3)+3 (n-2+2) (n-1)+1
# 5 -> 1+3+1 2+1+2 2+3 3+2
# 6 -> 1+2+3 1+3+2 2+1+3 2+3+1 3+2+1 1+2+1+2 2+1+2+1
# 7 -> 1+2+1+3 1+2+3+1 1+3+1+2 1+3+2+1 2+1+3+1 1+2+1+2+1 2+3+2 1+3+3 3+1+3
#


# (n-k + k)

# t = int(input())
# d = []
# d.append(0)
# d.append(1)
# d.append(2)
# d.append([[1,2],[2,1],[3]])
# for _ in range(t):
#     n = int(input())
#     for x in range(4, n+1):
#         for s in range(1, 4):
#             for l in range(len(d[x-1])):
#                 if d[x-s][l][0] != s:
#                     temp = [s]
#                     d.append([])
#                     d[x].append(temp+d[x-s][l])
# print(len(d[n])%1000000009)



# d = []
# d.append([0])
# d.append([1])
# d.append([2])
# d.append([[1,2],[2,1],[3]])
# print(d[3][0][0])

# d = [1,2,3,4,5,6,7,8,9,10,11]
# for i in range(10):
#     for j in range(10):
#         if d[j] == i:
#             print('hi')
#
# age = [1,2,3,4]
#
# x = [1,2,3,4]
# print(x[age])



# d = [0,1,2,[[1,2],[2,1],[3]]]
# print(d[3][0][0])

# d = []
# d.append(0)
# print(d)