data = []
for _ in range(9):
    data.append(int(input()))
n = max(data)
print(n)
print(data.index(n)+1)