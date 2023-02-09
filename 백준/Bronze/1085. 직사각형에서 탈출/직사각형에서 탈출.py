line = list(map(int, input().split()))
print(min(line[0], line[2]-line[0], line[1], line[3]-line[1]))