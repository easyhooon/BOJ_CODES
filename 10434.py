import sys

n = int(sys.stdin.readline().rstrip())
f = []

def is_prime(n: int) -> bool:
    if n < 2:
        return False
    if n in (2, 3):
        return True
    if n % 2 is 0 or n % 3 is 0:
        return False
    if n < 9:
        return True
    k, l = 5, n**0.5
    while k <= l:
        if n % k is 0 or n % (k+2) is 0:
            return False
        k += 6
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
            d_list = list(str(temp_sum))

for i in range(0, n):
    l, m = map(str, input().split())
    m_list = list(m)
    if is_prime(int(m)):
        if happy(m_list, f):
            print('{0} {1} YES'.format(l, m))
        else:
            print('{0} {1} NO'.format(l, m))
    else:
        print('{0} {1} NO'.format(l, m))
