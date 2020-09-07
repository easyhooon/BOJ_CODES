n, m = map(int, input().split())

board = [[0 for i in range(m+2)] for j in range(n+2)]
dp = [[0 for i in range(m+2)] for j in range(n+2)]

for i in range(1, n+1):
    k = list(map(int, input().split()))
    k.insert(0, 0)
    for j in range(1, m+1):
        board[i][j] = k[j]

dp[n][m] = board[n][m]


for i in range(n,0,-1):
    for j in range(m,0,-1):
        dp[i][j] = max(dp[i+1][j], dp[i][j+1]) + board[i][j]

print(dp[1][1])



# dp = [[0 for i in range(n+2)] for j in range(n+2)]

# dx = [1, -1, 0, 0]
# dy = [0, 0, -1, 1]
#
#
# def bfs(x, y):
#     queue = [[x, y]]
#     while queue:
#         a, b = queue[0][0], queue[0][1]
#         del queue[0]
#         for i in range(4):
#             q = a + dx[i]
#             w = b + dy[i]
#             if 0 <= q < n and 0 <= w < m and s[q][w] == 1:
#                 s[q][w] = 0
#                 queue.append([q, w])
#
#
# for i in range(t):
#     m, n, k = map(int, input().split())
#     s = [[0] * m for i in range(n)]
#     cnt = 0
#     for j in range(k):
#         a, b = map(int, input().split())
#         s[b][a] = 1
#     for q in range(n):
#         for w in range(m):
#             if s[q][w] == 1:
#                 bfs(q, w)
#                 s[q][w] = 0
#                 cnt += 1
#     print(cnt)