# l, m, n = map(int, input().split())
#
# # 항상 n이 제일 크다는 조건은 없는데..
#
# d = []
# d.append(n)
#
# if n - m >= 0:
#     d.append(n-m)
#     d.append(m)
#
# if n - l >= 0:
#     d.append(n-l)
#     d.append(l)
#
# d = list(set(d))
# d.sort()
# print(d)

from collections import deque

def pour(x, y):
    if not check[x][y]:
        check[x][y] = True
        q.append((x, y))

def bfs():
    q.append((0, 0))
    check[0][0] = True
    while q:
        x, y = q.popleft()
        z = c-x-y
        if not x:
            v.append(z)
        #x->y
        water = min(x, b-y)
        pour(x-water, y+water)
        #x->z
        water = min(x, c-z)
        pour(x-water, y)
        #y->x
        water = min(y, a-x)
        pour(x+water, y-water)
        #y->z
        water = min(y, c-z)
        pour(x, y-water)
        #z->x
        water = min(z, a-x)
        pour(x+water, y)
        #z->y
        water = min(z, b-y)
        pour(x, y+water)

q = deque()
v = []
a, b, c = map(int, input().split())
check = [[False]*(b+1) for _ in range(a+1)]
bfs()
print(' '.join(map(str, sorted(v))))
