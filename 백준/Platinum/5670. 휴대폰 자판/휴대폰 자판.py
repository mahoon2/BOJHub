class Trie:
    def __init__(self, c):
        self.char = c
        self.child = [None for _ in range(26)]
        self.childNum = 0
        self.isEnd = False

def ctoi(c):
    return ord(c)-ord('a')

def main():
    while True:
        try:
            n = int(input().rstrip())
            head = Trie('')
            head.childNum = n

            data = []
            for _ in range(n):
                data.append(input().rstrip())
            data.sort()

            for d in data:
                here = head
                for i in range(len(d)):
                    idx = ctoi(d[i])
                    if here.child[idx] is None:
                        here.child[idx] = Trie(d[i])
                    here = here.child[idx]
                    here.childNum += 1
                
                here.isEnd = True

            ret = 0
            for d in data:
                here = head
                temp = 1
                for i in range(len(d)):
                    next = here.child[ctoi(d[i])]
                    if here.childNum != next.childNum and here != head:
                        temp += 1
                    here = next
                ret += temp
            print('{:.2f}\n'.format(ret/n))

        except:
            break

import sys
input = sys.stdin.readline
print = sys.stdout.write
main()