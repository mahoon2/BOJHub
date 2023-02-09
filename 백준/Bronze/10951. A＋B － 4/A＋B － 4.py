while True:
    try:
        line = input()
    except:
        break
    line = line.split()
    a, b = int(line[0]), int(line[1])
    print(a+b)