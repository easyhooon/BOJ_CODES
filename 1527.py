# m, n = map(int, input().split())
# l = []
# for i in range(m, n+1):
#     if i % 10 == 4 or i % 10 == 7:
#         l.append(i)
# count = 0
#
# for i in l:
#     while True:
#         temp = i % 10
#         i = i // 10
#         if temp == 4 or temp == 7:
#             if i == 0:
#                 count = count + 1
#                 break
#             else:
#                 continue
#         else:
#             break
#
# print(count)
# #좀 비효율 적이긴해?
# #하나 만약에 검사 되면 건너뛰기 할 건수가잇지?

from collections import deque

# def test(num):
#     for i in str(num):
#         if i == '4' or i == '7':
#             continue
#         else:
#             return -1
#     return 0
#
# def bfs(number):
#     count = 0
#     q = deque([[number, count]])
#     while q:
#         l = q.popleft()
#         num = l[0]
#         count = l[1]
#         if not visited[num]:
#             visited[num] = True
#             if num == k:
#                 return count
#
#             if test(num) == 0:
#                 count += 1
#                 q.append([num+1, count])
#             else:
#                 q.append([num+1, count])
#
#     return count
count = 0

def gms(num):
    if (num > k):
        return
    if (n <= num and num <= k):
        global count
        count += 1
    gms(num * 10 + 4)
    gms(num * 10 + 7)

n, k = map(int, input().split())

gms(4)
gms(7)
print(count)
