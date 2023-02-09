n = int(input())

for _ in range(n):
    line = input().split()
    r = int(line[0])
    
    for data in line[1]:
        print(data*r, end='')
    print()