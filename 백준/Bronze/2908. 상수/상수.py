line=input().split()
a=int(line[0][::-1])
b=int(line[1][::-1])
if a > b:
    print(a)
else:
    print(b)