import sys
input = sys.stdin.readline

line = input().split()
n = int(line[0])
m = int(line[1])
dogam_list = [0 for _ in range(n+1)]
dogam_dict = dict()
for i in range(n):
    pocketmon = input().strip()
    dogam_list[i+1] = pocketmon
    dogam_dict[pocketmon] = i+1
for _ in range(m):
    inp = input().strip()
    if inp.isdigit():
        print(dogam_list[int(inp)])
    else:
        print(dogam_dict[inp])