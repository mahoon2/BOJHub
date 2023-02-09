n = int(input())
line = list(map(int, input().split()))
cnt = 0
for l in line:
    if l == n:
        cnt += 1
print(cnt)