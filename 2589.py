def divide(l, n):
    for i in range(0, len(l), n):
        yield l[i:i+n]

d = '111111111111111111'
divide_list = list(divide(d, 6))
print(divide_list)