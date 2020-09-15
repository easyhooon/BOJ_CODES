x,y = map(int,input().split()) 
arr = []
arr2 = set() 
for i in range(x):
    row = list(map(int,input().split())) #각 row를 한번에 받고 리스트 형으로 저장
    arr2.add(max(row)) #set 자료형에 각 row 최대값을 추가한다.
    arr.append(row) 
for j in range(y):
    arr2.add(max(arr[i][j] for i in range(x))) #각 column에 최대값을 추가한다.

print(sum(map(sum,arr)) - sum(arr2))  

# print(sum(map(sum,arr)))

# print(map(sum,arr))

# print(sum(arr))