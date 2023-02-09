line = input()
line = list(map(int, input().split()))
data = line.copy()

line = list(set(line))
line.sort()

data_index = dict()
for i in range(len(line)):
    data_index[line[i]] = i
for i in data:
    print(data_index[i], end=' ')
print()