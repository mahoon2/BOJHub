import sys
cache = [[0 for _ in range(1516)] for _ in range(1516)]

def sol(a, b):
    if(b>a/2): b=a-b
    if(b==0 or b==a): return 1
    if(b==1 or b==a-1): return a
    if(cache[a][b]): return cache[a][b]
    cache[a][b] = sol(a-1, b-1) + sol(a-1, b)
    return cache[a][b]

def main():
    sys.setrecursionlimit(2000)
    n=int(input())
    can=[]
    for i in range(1, n+1):
        if((5*i+n-i)%3==0):
            can.append(i-1)
    sum=0
    for data in can:
        sum += sol(n-1, data)
    print(sum%1000000007)
main()