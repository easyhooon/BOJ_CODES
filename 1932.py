import sys
from pprint import pprint
n = int(sys.stdin.readline().rstrip())

board = [[0 for i in range(n+2)] for j in range(n+2)]
dp = [[0 for i in range(n+2)] for j in range(n+2)]

for i in range(1, n+1):
    k = list(map(int, input().split()))
    k.insert(0, 0)
    for j in range(1, i+1):
        board[i][j] = k[j]

for i in range(1, n+1):
    dp[n][i] = board[n][i]

for i in range(n-1, 0, -1):
    for j in range(1, n+1):
        dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + board[i][j]

pprint(dp)
print(dp[1][1])

# dp[i][j]
#
# ans(i,j) = max(ans(i+1, j), ans(i+1,j+1)) + 지금까지의 합
# ans(i,j) = arr[i][j] if i == n