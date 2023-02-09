n = int(input())
dungchi = []
for i in range(n):
    temp = input().split()
    dungchi.append([int(temp[0]), int(temp[1])])

for i in range(n):
    int_larger_than_me = 0
    for j in range(n):
        if i==j : continue
        if dungchi[i][0] < dungchi[j][0] and dungchi[i][1] < dungchi[j][1]:
            int_larger_than_me += 1
    print(int_larger_than_me+1, end=' ')