import sys
input = sys.stdin.readline

n = int(input().rstrip())
data = dict()

while n:
    n -= 1

    line = input().rstrip().split()
    for name in line:
        if name == '-': continue
        if name not in data:
            data[name] = 4
        else:
            data[name] += 4
    
    line = input().rstrip().split()
    for name in line:
        if name == '-': continue
        if name not in data:
            data[name] = 6
        else:
            data[name] += 6
    
    line = input().rstrip().split()
    for name in line:
        if name == '-': continue
        if name not in data:
            data[name] = 4
        else:
            data[name] += 4
    
    line = input().rstrip().split()
    for name in line:
        if name == '-': continue
        if name not in data:
            data[name] = 10
        else:
            data[name] += 10

if(len(data.values()) == 0): print("Yes")
elif max(data.values()) - min(data.values()) <= 12: print("Yes")
else: print("No")