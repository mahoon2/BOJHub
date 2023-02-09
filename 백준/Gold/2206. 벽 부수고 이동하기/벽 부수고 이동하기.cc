#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
 
int n, m;
int map[1001][1001];
int visited[1001][1001][2];
 
int xMove[4] = { 0,0,-1,1 };
int yMove[4] = { 1,-1,0,0 };

typedef struct pos
{
    int y;
    int x;
    int breakingWall;
} pos;
 
int bfs(void)
{
    queue<pos> Q;
    visited[1][1][0] = 1;
    Q.push({ 1,1,0 });
 
    while (!Q.empty())
    {
        pos cur = Q.front();
        Q.pop();
 
        if (cur.y == n && cur.x == m) return visited[cur.y][cur.x][cur.breakingWall];
 
        for (int i = 0; i < 4; i++)
        {
            pos next;
            next.y = cur.y + yMove[i];
            next.x = cur.x + xMove[i];
            next.breakingWall = cur.breakingWall;
           
            if (next.y <= 0 || next.y > n || next.x <= 0 || next.x > m) continue;
            if (visited[next.y][next.x][cur.breakingWall]) continue;
            
            if (map[next.y][next.x] == 0)
            {
                visited[next.y][next.x][next.breakingWall] = visited[cur.y][cur.x][cur.breakingWall] + 1;
                Q.push({ next.y,next.x,cur.breakingWall });
            }
            if (map[next.y][next.x] == 1 && next.breakingWall == 0)
            {
                visited[next.y][next.x][1] = visited[cur.y][cur.x][cur.breakingWall] + 1;
                next.breakingWall = 1;
                Q.push(next);
            }
       
        }
    }
 
    return -1;
}
 
int main(void)
{
    cin >> n >> m;
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
 
    cout << bfs();
}
