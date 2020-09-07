op = [0, 0]
w_op = [0, 0]
f = [0, 0]
w_f = [0, 0]
cc = [0, 0]
w_cc = [0, 0]
cdr = [0, 0]
w_cdr = [0, 0]
asi = [0, 0]
w_asi = [0, 0]

op[0], f[0], cc[0], cdr[0], asi[0] = map(int, input().split())
op[1], f[1], cc[1], cdr[1], asi[1] = map(int, input().split())
w_op[0], w_f[0], w_cc[0], w_cdr[0], w_asi[0] = map(int, input().split())
w_op[1], w_f[1], w_cc[1], w_cdr[1], w_asi[1] = map(int, input().split())


def measure_cp(op, f, cc, cdr, asi):
    cp = op * (100 + f)*(100*(100 - min(cc, 100)) + min(cc, 100) * cdr) * (100 + asi)

    return cp
# 곱하기 100을 덧붙혀야 하는 이유를 모르겠음

k_c_cp = measure_cp(op[0], f[0], cc[0], cdr[0], asi[0])

k_n_cp = measure_cp(op[0]-w_op[0]+w_op[1], f[0]-w_f[0]+w_f[1], cc[0]-w_cc[0]+w_cc[1], cdr[0]-w_cdr[0]+w_cdr[1], asi[0]-w_asi[0]+w_asi[1])

p_c_cp = measure_cp(op[1], f[1], cc[1], cdr[1], asi[1])

p_n_cp = measure_cp(op[1]-w_op[1]+w_op[0], f[1]-w_f[1]+w_f[0], cc[1]-w_cc[1]+w_cc[0], cdr[1]-w_cdr[1]+w_cdr[0], asi[1]-w_asi[1]+w_asi[0])

if k_n_cp > k_c_cp:
    print('+')
elif k_n_cp == k_c_cp:
    print('0')
else:
    print('-')

if p_n_cp > p_c_cp:
    print('+')
elif p_n_cp == p_c_cp:
    print('0')
else:
    print('-')

