# from pprint import pprint
# v = []
# #﻿볼륨의 리스트
# v.append(0)
#
# d = [[0 for col in range(1001)] for row in range(101)]
# #d[i][j] i번째 노래에서(행) 볼륨 j(열) 가능하면 1, 불가능하면 0
#
# n, s, m = map(int, input().split())
# # ﻿#n: 곡의 개수, s: 시작 볼륨, m: 볼륨의 최대 값
#
# l = list(map(int, input().split()))
#
# for i in l:
#     v.append(i)
#
# d[0][s] = 1  ﻿
# ## 시작 볼륨 0 <= s <= m﻿
#
# for i in range(0, n):
#     for j in range(0, m+1):
#         if d[i][j] == 0:
#             continue
#
#         ﻿# d[i][j]가 1일때 j는 가능한 현재 볼륨의 값 그 값과 다음 볼륨의 +-가 0과 m사이 이면 true로 전환
#         if j-v[i+1] >= 0:
#             d[i+1][j-v[i+1]] = 1
#         if j+v[i+1] <= m:
#             d[i+1][j+v[i+1]] = 1
#
# ans = -1
# ﻿#마지막 곡을 연주할 수 없는 경우로 일단 초기화
#
# for i in range(0, m+1):
#     if d[n][i] == 1:
#         ans = i ﻿
#         #가능한 최대 볼륨으로 계속해서 ans를 갱신, 결국 가장 큰 i가 ans에 들어감
#
# print(ans)
# pprint(d)


v = [] #﻿볼륨의 리스트
v.append(0)

d = [[0 for col in range(1001)] for row in range(101)]
#d[i][j] i번째 노래에서(행) 볼륨 j(열) 가능하면 1, 불가능하면 0

n, s, m = map(int, input().split())
#n: 곡의 개수, s: 시작 볼륨, m: 볼륨의 최대 값

l = list(map(int, input().split()))
for i in l:
    v.append(i)

d[0][s] = 1
# 시작 볼륨 0 <= s <= m﻿

for i in range(0, n):
    for j in range(0, m+1):
        if d[i][j] == 0:
            continue

            # d[i][j]가 1일때 j는 가능한 현재 볼륨의 값 그 값과 다음 볼륨의 +-가 0과 m사이 이면 true로 전환
        if j-v[i+1] >= 0:
            d[i+1][j-v[i+1]] = 1
        if j+v[i+1] <= m:
            d[i+1][j+v[i+1]] = 1

ans = -1
#마지막 곡을 연주할 수 없는 경우로 일단 초기화

for i in range(0, m+1):
    if d[n][i] == 1:
        ans = i
        # 가능한 최대 볼륨으로 계속해서 ans를 갱신, 결국 가장 큰 i가 ans에 들어감

print(ans)

