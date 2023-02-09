def getRepaintNum(board):
    lines = ['BWBWBWBW', 'WBWBWBWB', 'BWBWBWBW', 'WBWBWBWB', 'BWBWBWBW', 'WBWBWBWB', 'BWBWBWBW', 'WBWBWBWB']

    num1 = 0
    for i in range(8):
        for j in range(8):
            if board[i][j] != lines[i][j]:
                num1 += 1

    return min(num1, 64-num1)

if __name__ == '__main__':
    line = input().split()
    n, m = int(line[0]), int(line[1])
    num = 100000000
    data = []

    for _ in range(n):
        data.append(input())

    board = ['', '', '', '', '', '', '', '']
    for i in range(n-7):
        for j in range(m-7):
            for k in range(8):
                board[k] = data[i+k][j:j+8]

            #print(board)
            temp = getRepaintNum(board)
            #print(temp)
            if temp < num:
                num = temp
        
    print(num)