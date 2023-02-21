import sys
input = sys.stdin.readline

def main():
    [N, M, K] = list(map(int, input().rstrip().split()))
    data = list()

    for i in range(N):
        line = input().rstrip().split()
        x = int(line[0])
        y = int(line[1])

        d = y/x
        data.append(d)

        for k in range(1, K):
            if k%2 == 1:
                d = y/(((k-1)//2+1)*2*M-x)
            else:
                d = y/(((k-1)//2+1)*2*M+x)
            data.append(d)
    
    data.sort()
    
    cnt = 1
    max_cnt = 0
    for i in range(1, len(data)):
        if data[i-1] != data[i]:
            max_cnt = max((max_cnt, cnt))
            cnt = 1
        else:
            cnt += 1
    print(max_cnt)

main()