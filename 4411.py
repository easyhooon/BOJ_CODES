n, m = map(str, input().split())
m_list = list(m)
f = []

while 1:
    temp_sum = 0
    if '1' in f:
        print('Yes')
        break

    #for i in f:
        #if f.count(i) > 1 and i != 1:
        #    print('No')
        #    break
    else:
        for i in m_list:
            temp_sum += int(i) ** 2
        f.append(str(temp_sum))
        print(f)
        m_list = list(str(temp_sum))