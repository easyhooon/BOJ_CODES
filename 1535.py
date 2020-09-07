import sys
n = int(sys.stdin.readline().rstrip())

L = list(map(int, input().split())) # 잃는 체력을 저장하는 리스트
L.insert(0, 0) # 순서의 헷갈림 방지를 위한 0번째 원소에 0 삽입
J = list(map(int, input().split())) # 얻는 기쁨을 저장하는 리스트
J.insert(0, 0)


K = [[0 for col in range(101)] for row in range(21)]


def knapsack(n, m, weight, price): #knapsack 알고리즘 함수
    for i in range(1, n+1):
        for j in range(1, m+1):
            if weight[i] > j:
                K[i][j] = K[i-1][j]
            else:
                K[i][j] = max(K[i-1][j-weight[i]] + price[i], K[i-1][j])
                #MAX(현재 보석의 가치+ 남은 가방 크기 만큼 나머지 보석을 넣을 때 최대 가치, 이전까지 구해둔 보석의 가치) 가 됩니다.

    return K[n][m]


print(knapsack(n, 99, L, J))






