import itertools
import sys

def sol():
    while True:
        s = sys.stdin.readline()
        if s.strip() == "0":
            return
        l = list(map(int, s.split()))
        l = l[1:] #첫번째 원소 뺄 때 사용하는 기법
        l = list(map(str, l))
        combi = list(map(' '.join, list(itertools.combinations(l, 6))))
        # print(combi)

        for i in combi:
            print(i)
        print()

sol()

# first, *rest = [1, 2, 3, 4, 5]
# print(first) # 1
# print(rest) # [2, 3, 4, 5]