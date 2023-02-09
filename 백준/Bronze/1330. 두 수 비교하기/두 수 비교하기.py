line = input().split()
a, b = int(line[0]), int(line[1])

if a>b:
    print('>')
elif a<b:
    print('<')
else:
    print('==')