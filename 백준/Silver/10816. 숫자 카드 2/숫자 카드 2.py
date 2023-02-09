import sys
input = sys.stdin.readline

number_dict = dict()
n = int(input().strip())
line = list(map(int, input().split()))
for data in line:
    if data not in number_dict.keys():
        number_dict[data] = 1
    else:
        number_dict[data] += 1

n = int(input().strip())
line = list(map(int, input().split()))
for data in line:
    if data not in number_dict.keys():
        print("0", end=" ")
    else:
        print(number_dict[data], end=" ")
print()