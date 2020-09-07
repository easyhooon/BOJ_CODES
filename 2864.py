#s[0] = 'k'  # 얘는 오류가 난다. 튜플처럼 고정된 값이라고 생각하면 쉬울 듯하다.
a, b = map(str, input().split())

change_a = '1234'
change_b = '1234'
if '5' in a:
    change_a = a.replace('5', '6')
else:
    change_a = a
if '5' in b:
    change_b = b.replace('5', '6')
else:
    change_b = b

max_sum = int(change_a) + int(change_b)

change_a = a
change_b = b
if '6' in a:
    change_a = a.replace('6', '5')
else:
    change_a = a
if '6' in b:
    change_b = b.replace('6', '5')
else:
    change_b = b

min_sum = int(change_a) + int(change_b)

print('{0} {1}'.format(min_sum, max_sum))

