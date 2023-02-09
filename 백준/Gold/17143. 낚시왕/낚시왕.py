class Shark():
    def __init__(self, y, x, speed, direction, size):
        self.size = size
        self.y = y
        self.x = x
        self.direction = direction
        self.speed = speed

    def get_pos(self):
        return (self.y, self.x)

    def get_size(self):
        return self.size

    def isBiggerThan(self, another_shark):
        if self.size > another_shark.get_size():
            return True
        else:
            return False

    def move(self):
        global r, c
        if (self.direction == 1):
            left = self.y - 1
            if self.speed <= left:
                self.y -= self.speed
                if self.speed == left:
                    self.direction = 2
                return
            div = (self.speed - left) // (r - 1)
            rem = (self.speed - left) % (r - 1)
            if div % 2 == 1:
                self.y = r - rem
            else:
                self.direction = 2
                self.y = rem + 1
        elif self.direction == 2:
            left = r - self.y
            if self.speed <= left:
                self.y += self.speed
                if self.speed == left:
                    self.direction = 1
                return
            div = (self.speed - left) // (r - 1)
            rem = (self.speed - left) % (r - 1)
            if div % 2 == 1:
                self.y = rem + 1
            else:
                self.direction = 1
                self.y = r - rem
        elif self.direction == 3:
            left = c - self.x
            if self.speed <= left:
                self.x += self.speed
                if self.speed == left:
                    self.direction = 4
                return
            div = (self.speed - left) // (c - 1)
            rem = (self.speed - left) % (c - 1)
            if div % 2 == 1:
                self.x = rem + 1
            else:
                self.direction = 4
                self.x = c - rem
        elif self.direction == 4:
            left = self.x - 1
            if self.speed <= left:
                self.x -= self.speed
                if self.speed == left:
                    self.direction = 3
                return
            div = (self.speed - left) // (c - 1)
            rem = (self.speed - left) % (c - 1)
            if div % 2 == 1:
                self.x = c - rem
            else:
                self.direction = 3
                self.x = rem + 1


def main():
    import sys
    global r, c
    input = sys.stdin.readline
    r, c, m = map(int, input().split())
    
    sharks = []
    sharks_pos = []
    for _ in range(m):
        y, x, speed, direction, size = map(int, input().split())
        sharks.append(Shark(y, x, speed, direction, size))
        sharks_pos.append((y, x))
    
    naksi = 1
    ret = 0
    while naksi <= c:
        closest_shark = -1
        for idx, pos in enumerate(sharks_pos):
            if pos[1] == naksi and (closest_shark == -1 or pos[0] < sharks_pos[closest_shark][0]):
                closest_shark = idx
        if closest_shark != -1:
            ret += sharks[closest_shark].get_size()
            del sharks[closest_shark]
            del sharks_pos[closest_shark]
        for idx, s in enumerate(sharks):
            s.move()
            sharks_pos[idx] = s.get_pos()
            
        del_set = set()
        board = [[0 for _ in range(c+1)] for _ in range(r+1)]
        for i in range(len(sharks)):
            p = sharks_pos[i]
            if board[p[0]][p[1]] != 0:
                if board[p[0]][p[1]][0] > sharks[i].get_size():
                    del_set.add(i)
                else:
                    del_set.add(board[p[0]][p[1]][1])
                    board[p[0]][p[1]] = (sharks[i].get_size(), i)
            else:
                board[p[0]][p[1]] = (sharks[i].get_size(), i)
        
        del_cnt = 0
        for i in sorted(del_set):
            del sharks[i-del_cnt]
            del sharks_pos[i-del_cnt]
            del_cnt += 1
        naksi += 1
    
    print(ret)
    
r = c = 0
main()