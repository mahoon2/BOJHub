n = int(input())
cnt, num = 0, 665
while True:
    if cnt == n:
        print(num)
        break
    num += 1
    num_str = str(num)

    if num_str.count('6') >= 3:
        if '666' in num_str:
            cnt += 1