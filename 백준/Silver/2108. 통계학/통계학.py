import sys
input = sys.stdin.readline

n = int(input())
data = list()
cnt = list()

for i in range(8002):
    cnt.append(0)

for _ in range(n):
    data.append(int(input()))

data.sort()
print(round(sum(data)/n))
print(data[int(n/2)])

for d in data:
    cnt[d+4000] += 1
max_cnt = max(cnt)

max_cnt_index = max_cnt_index_cnt = 0
for i in range(len(cnt)):
    if cnt[i] == max_cnt:
        max_cnt_index_cnt += 1
        max_cnt_index = i
        if max_cnt_index_cnt == 2:
            break
print(max_cnt_index-4000)
print(data[n-1]-data[0])