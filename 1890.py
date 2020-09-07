import sys

n = int(sys.stdin.readline().rstrip())
data = []
for i in range(n):
    temp = list(map(int, sys.stdin.readline().split()))
    data.append(temp)

dp = []

#이중포문을 이용한 matrix 생성법도 기억해둘 것
#d[i][j] : (i, j)번 칸에서 가장 오른쪽 아래 칸으로 이동하는 경우의 수
for i in range(n):
    dp.append([])
    for j in range(n):
        dp[i].append(0)

#초기값 1 중요
dp[0][0] = 1

for i in range(n):
    for j in range(n):
        #도착 지점에 도착하면 반복문 종료
        if i == n - 1 and j == n - 1:
            break
        value = data[i][j]
        down = i + value
        right = j + value

        if down < n:
            #아래로 값을 갱신
            dp[down][j] += dp[i][j]
        if right < n:
            #오른쪽으로 값을 갱신
            dp[i][right] += dp[i][j]

print(dp[n - 1][n - 1])





