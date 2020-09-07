import sys


n = int(sys.stdin.readline().rstrip())

#3번째 칸에 쓰여 있는 수가 3이면, 재환이는 4, 5, 6번 칸 중 하나로 점프할 수 있다.
#그 칸 만큼이 아닌 그 칸 '이하'는 다 이동 가능
#가장 오른쪽 끝 칸으로 갈 수 없으면 -1을 출력

a = [0 for _ in range(0, 1002)]
dp = [0 for _ in range(0, 1002)]

k = list(map(int, input().split()))
k.insert(0, 0)
for i in range(1, n+1):
    a[i] = k[i]

#dp 배열을 어떻게 세울것인가
#초기조건은 무엇으로 할 것인가.

# dp[i] : i번째 칸에서 가장 오른쪽 끝 칸으로 갈 수 있는 최소 점프 횟수
# dp[i] : i번째 칸까지 왔을때 최소 점프 횟수

for i in range(1, 1002):
    if i == 1:
        dp[1] = 0
    else:
        dp[i] = 87654321

    # for j in range(1, i+1):
    #     if a[j]+j >= i: #핵심
    #         dp[i] = min(dp[i], dp[j] + 1)

for j in range(1, i+1):
    if a[j] >= j:
        if i+j <= n:
            dp[i + j] = min(dp[i + j], dp[i] + 1) #이거 잘못 출력됨 

if dp[n] == 87654321:
    print(-1)
else:
    print(dp[n])






