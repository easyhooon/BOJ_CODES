# a, b, c = map(int, input().split())
#
# print(pow(a, b) % c)

# a=nc+r이라고 생각햇을때
# a^2=(nc)^2+2(nc)r+r^2
# a^2를 c로 나눈것의 나머지는 r^2%c

# n -> log n 으로 줄이는 방법!

def squared(a, b):
    if b == 0:
        return 1
    elif b == 1:
        return a
    elif b % 2 == 1:
        return squared(a, b - 1) * a
    half = squared(a, b // 2)
    half %= c
    return half ** 2 % c


N, r, c = map(int, input().split())
# print(squared(a, b) % c)

# ex)
#
# 2^4 %3
#
# 2^4 % 3 == (2^2%3)(2^2%3)%3 과 같음 위에 설명 참조
# (2^2%3)(2^2%3)%3 == (((2%3)(2%3)%3)((2%3)(2%3)%3))%3
# -> 1 * 1 % 3
# 따라서 재귀로 해결