class Trie:
    def __init__(self, c):
        self.char = c
        self.end = False
        self.child = [None for _ in range(10)]
    
    def trieEnds(self):
        self.end = True

def solve():
    n = int(input().rstrip())
    head = Trie('')
    answer = "YES"

    for _ in range(n):
        line = input().rstrip()
        here = head
        
        if answer == "NO":
            continue
        
        for i, c in enumerate(line):

            if here.child[int(c)] is None:
                here.child[int(c)] = Trie(c)
            here = here.child[int(c)]

            if here.end is True:
                answer = "NO"
                break
                
            if i == len(line)-1:
                here.trieEnds()

                if any(here.child):
                    answer = "NO"
                    break
                    
    print(answer)

def main():
    t = int(input())
    for _ in range(t):
        solve()

import sys
input = sys.stdin.readline
main()