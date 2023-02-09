line=input().split()
n=int(line[0])
m=int(line[1])
d=set()
b=set()
for _ in range(n):
    d.add(input())
for _ in range(m):
    b.add(input())
db=list(d&b)
db.sort()
print(len(db))
for data in db:
    print(data)