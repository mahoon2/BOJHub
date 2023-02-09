n = int(input())

for _ in range(n):
    line = input()
    check = 0
    score = 0
    for result in line:
        if result == 'O':
            check += 1
            score += check
        else:
            check = 0
    print(score)