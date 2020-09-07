def cycle(d):
    temp1 = d[0][0]
    temp2 = d[0][1]
    temp3 = d[1][0]
    temp4 = d[1][1]
    d[0][0] = temp3
    d[0][1] = temp1
    d[1][0] = temp4
    d[1][1] = temp2
    return d

def cal(d):
    temp1 = d[0][0]
    temp2 = d[0][1]
    temp3 = d[1][0]
    temp4 = d[1][1]
    return temp1/temp3 + temp2/temp4

a, b = map(int, input().split())
c, d = map(int, input().split())
#a = [[1, 2], [3,4]]
f = []
f.append([a,b])
f.append([c,d])
cal_f= []
cal_f.append(cal(f))
cal_f.append(cal(cycle(f)))
cal_f.append(cal(cycle(f)))
cal_f.append(cal(cycle(f)))
cal_max = max(cal_f)
print(cal_f.index(cal_max))

