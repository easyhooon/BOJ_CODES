def find_multiple(d):
    count = 0
    for i in range(0, len(d)):
        if d[i]*2 in d:
            count += 1

    return count

while True:
    a = list(map(int, input().strip().split()))
    # 갯수의 상관없이(갯수가 주어지지 않았을 때,) 입력을 리스트로 한꺼번에 받는법
    if a[0] == -1:
        break
    else:
        a.remove(0)
        result = find_multiple(a)
    print(result)

