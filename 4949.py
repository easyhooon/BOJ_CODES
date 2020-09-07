import sys

n = int(sys.stdin.readline().rstrip())
f = []
temp_sum = 0

def prime_number(number):
    if int(number) != 1:
        for i in range(2, number):
            if number % i == 0:
                return False
    else:
        return False

    return True

def ovl(f):
    for i in f:
        if f.count(i) > 1 and i != 1:
            return 1
    return 0

def happy(d_list, f):
    while 1:
        temp_sum = 0
        if '1' in f:
            return 1

        elif ovl(f) == 1:
            return 0

        else:
            for i in d_list:
                temp_sum += int(i) ** 2
            f.append(str(temp_sum))
            print(f)
            d_list = list(str(temp_sum))

for i in range(0, n):
    l, d = map(str, input().split())
    d_list = list(d)
    if prime_number(int(d)):

        if happy(d_list, f) == 1:
            print('Yes')
        else:
            print('No')
    else:
        print('No')















