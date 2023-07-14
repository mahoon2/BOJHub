import sys
from functools import cmp_to_key

input = sys.stdin.readline

def comp(d1, d2):
    s1, e1 = d1[0]
    s2, e2 = d2[0]

    if s1 == s2:
        if e1 == e2:
            if d1[1] == d2[1]:
                return 0
            elif d1[1] < d2[1]:
                return -1
        elif e1 < e2:
            return -1
    elif s1 < s2:
        return -1

    return 1

n = int(input().rstrip())
data = list()

for _ in range(n):
    line = input().rstrip().split()

    start = line[0].split('-')
    end = line[1].split('-')

    data.append([start, 0])
    data.append([end, 1])

data.sort(key=cmp_to_key(comp))

cnt = 0
ret = 0
print_ret = None

for d in data:
    if d[1] == 0: cnt += 1
    else: cnt -= 1
    
    if ret < cnt:
        ret = cnt
        print_ret = d[0]

print(str(print_ret[0])+'-'+str(print_ret[1]))