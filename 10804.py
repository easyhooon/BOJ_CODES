def change(d, a, b):
    c = []

    for i in range(a - 1, b):
        c.append(d[i])

    c.reverse()
    #sort의 역순 정렬
    j = 0
    for i in range(a - 1, b):
        d[i] = c[j]
        j += 1
    return d

d = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]

for i in range(0, 10):
    a, b = map(int, input().split())
    d = change(d, a, b)

for i in range(len(d)):
    print(d[i], end =' ')