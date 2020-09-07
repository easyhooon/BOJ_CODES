from collections import deque

graph = {}
temp = []

def BFS_for_problem(graph, root):
    visited = []
    queue = deque([root])

    while queue:
        n = queue.popleft()
        if n not in visited:
            visited.append(n)
            if n in graph:
                temp = list(set(graph[n]) - set(visited))
                temp.sort()
                queue += temp

    return visited

def recursive(l, count):
    visited = BFS_for_problem(graph, l[0])
    l = list(set(l) - set(visited))
    l.sort()
    if l:
        count = count+1
        recursive(l, count)
    else:
        return
    return count

node, edge = map(int, input().split())

for i in range(edge):
    n1, n2 = map(int, input().split())
    temp.append(n1)
    temp.append(n2)
    if n1 not in graph:
        graph[n1] = [n2]
    elif n2 not in graph[n1]:
        graph[n1].append(n2)

    if n2 not in graph:
        graph[n2] = [n1]
    elif n1 not in graph[n2]:
        graph[n2].append(n1)

temp = list(set(temp))

answer = recursive(temp, 1)
print(answer)
#전체리스트 - visited가 [] 가 되지 않으면 빼고 난 다음에 bfs를 한번더 수행 count++ 해주면서






