d = []
for i in range(0, 3):
    tmp = list(map(int, input().split()))
    d.append(tmp)

max_a = d[0][0]
a = d[0][1]
max_b = d[1][0]
b = d[1][1]
max_c = d[2][0]
c = d[2][1]

d = [a, b, c]
max_d = [max_a, max_b, max_c]

for i in range(1, 101):
    if i % 3 == 1:
        if d[0] + d[1] <= max_d[1]:
            d[1] = d[0] + d[1]
            d[0] = 0

        else:
            d[0] = d[0] + d[1] - max_d[1]
            d[1] = max_d[1]

    if i % 3 == 2:
        if d[1] + d[2] <= max_d[2]:
            d[2] = d[1] + d[2]
            d[1] = 0

        else:
            d[1] = d[1] + d[2] - max_d[2]
            d[2] = max_d[2]

    if i % 3 == 0:
        if d[2] + d[0] <= max_d[0]:
            d[0] = d[2] + d[0]
            d[2] = 0

        else:
            d[2] = d[2] + d[0] - max_d[0]
            d[0] = max_d[0]

for i in range(0, 3):
    print(d[i])





