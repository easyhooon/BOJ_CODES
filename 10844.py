import sys
n = int(sys.stdin.readline().rstrip())

# 101행 10열을 0으로 초기화한다.
# 행은 N의 경우의 수의 모든 집합(1~100), 열은 가능한 끝나는 자릿수(0~9)
# 즉 길이가 N(i)일때 마지막 수가 (j)일 경우의 계단 수를 의미한다.
dp = [[0 for i in range(10)] for j in range(101)]

for i in range(1,10):
    dp[1][i] = 1

for i in range(2, n+1):
    for j in range(10):
        if j == 0:
            dp[i][j] = dp[i-1][1]

        elif j == 9:
            dp[i][j] = dp[i-1][8]
        else:
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]

print(sum(dp[n])%1000000000)