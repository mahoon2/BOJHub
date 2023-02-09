def fact(n):
    temp = 1
    for i in range(2, n+1):
        temp *= i
    return temp

def case_count(i):
    x, y = i[0], i[1]

    if x == 0 or y == 0:
        return 1
    else:
        return fact(x+y)//(fact(x)*fact(y))

def seed(n):
    pair = []
    x, y = 0, n

    while True:
        if y >= 0:
            pair.append((x, y))
            x += 1
            y = n - 2*x
        else:
            break
    
    return sum(case_count(i) for i in pair)

n = int(input())
output = []

for _ in range(n):
    t = int(input())
    a, b = 0, 0

    if t == 0:
        a, b = 1, 0
    elif t == 1:
        a, b = 0, 1
    elif t == 2:
        a, b = 1, 1
    else:
        a = seed(t-2)
        b = seed(t-1)

    output.append((a, b))

for o in output:
    a, b = o[0], o[1]
    print(a, b)