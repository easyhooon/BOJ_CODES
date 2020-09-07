#그냥 제일 큰거 더하는게 아니라 연속적인 날에서 판단하는거임
n, k = map(int, input().split())

d = list(map(int, input().split()))
l = []


for i in range(0, n-k+1):
    temp = 0
    for j in range(i, i+k):
        temp += d[j]

    l.append(temp)

l.sort()

print(l[n-k])


