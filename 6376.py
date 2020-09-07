import math
print('n e')
print('- -----------')
for i in range(0, 10):
    result = 0
    for j in range(0, i+1):
        divisor = math.factorial(j)
        result += 1/divisor
    if result <= 2:
        print('%d %d' %(i, result))
    elif result == 2.5:
        print('{0} {1}'.format(i, result))
    else:
        print('%d %0.9f' %(i, result))

