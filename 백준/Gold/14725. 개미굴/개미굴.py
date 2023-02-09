def print_keys(curr, depth):
    for key in sorted(curr.keys()):
        print("--"*depth, end="")
        print(key)
        
        if len(curr[key]) >= 1:
            print_keys(curr[key], depth+1)

def main():
    n = int(input())
    head = dict()
    
    for _ in range(n):
        line = input().split()
        curr = head
        for data in line[1:]:
            if data in curr:
                curr = curr[data]
            else:
                curr[data] = dict()
                curr = curr[data]
    print_keys(head, 0)

import sys
input = sys.stdin.readline
main()