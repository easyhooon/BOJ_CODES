N, K = map(int, input().split())

prime_ox = [True for _ in range(N + 1)]
num = 1

for i in range(2, N + 1):
    if prime_ox[i] == True:
        for j in range(i, N + 1, i):
            if prime_ox[j] == False:
                continue

            if num == K:
                print(j)

            prime_ox[j] = False
            num += 1
