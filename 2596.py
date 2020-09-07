import sys
n = int(sys.stdin.readline().rstrip())

a = str(sys.stdin.readline().rstrip())

result = []

def divide(l, n):
    for i in range(0, len(l), n):
        yield l[i:i+n]

# 한개까지 오차를 봐줘야됨
def search_alphabet(d):
    for i in d:
        if i == '000000' or i == '100000' or i == '010000' or i == '001000' or i == '000100' or i == '000010' \
                or i == '000001':
            result.append('A')
        elif i == '001111' or i == '101111' or i == '011111' or i == '000111' or i == '001011' or i == '001101' \
                or i == '001110':
            result.append('B')
        elif i == '010011' or i == '110011' or i == '000011' or i == '011011' or i == '010111' or i == '010001' \
                or i == '010010':
            result.append('C')
        elif i == '011100' or i == '111100' or i == '001100' or i == '010100' or i == '011000' or i == '011110' \
                or i == '011101':
            result.append('D')
        elif i == '100110' or i == '000110' or i == '110110' or i == '101110' or i == '100010' or i == '100100' \
                or i == '100111':
            result.append('E')
        elif i == '101001' or i == '001001' or i == '111001' or i == '100001' or i == '101101' or i == '101011' \
                or i == '101000':
            result.append('F')
        elif i == '110101' or i == '010101' or i == '100101' or i == '111101' or i == '110001' or i == '110111' \
                or i == '110100':
            result.append('G')
        elif i == '111010' or i == '011010' or i == '101010' or i == '110010' or i == '111110' or i == '111000' \
                or i == '111011':
            result.append('H')
        else:
            #배열상의 위치가 아닌 실제 위치 d[8] => 9번째
            return d.index(i)+1
    return result

divide_list = list(divide(a,len(a)//n))
#print(divide_list)

if str(type(search_alphabet(divide_list))) == "<class 'int'>":
    print(search_alphabet(divide_list))
else:
    for i in range(0, len(result)):
        print(result[i], end='')

