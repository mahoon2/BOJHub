while True:
    line = input().split()
    a, b = int(line[0]), int(line[1])
    if a == 0 and b == 0:
        break
    print(a+b)