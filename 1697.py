
from collections import deque

# def bfs(number):
#     count = 0
#     q = deque([[number, count]])
#     while q:
#         l = q.popleft()
#         num = l[0]
#         count = l[1]
#         if not visited[num]:
#             visited[num] = True
#
#             if num == k:
#                 return count
#             count += 1
#             if (num * 2) <= 100000:
#                 q.append([num * 2, count])
#             if (num + 1) <= 100000:
#                 q.append([num + 1, count])
#             if (num- 1) >= 0:
#                 q.append([num - 1, count])
#     return count
# 
# 
# n, k = map(int, input().split())
# visited = [False] * 100001
# print(bfs(n))
# 
# from collections import deque
from collections import deque

from collections import deque


def bfs(num):
    count = 0
    q = deque([[num, count]])
    while q:
        d = q.popleft()
        num = d[0]
        count = d[1]
        if not visited[num]:
            visited[num] = True
            if num == k:
                return count
            count += 1
            if (num * 2) <= 100000:
                q.append([num * 2, count])
            if (num + 1) <= 100000:
                q.append([num + 1, count])
            if (num - 1) >= 0:
                q.append([num - 1, count])
    return count


n, k = map(int, input().split())
visited = [False] * 100001
print(bfs(n))