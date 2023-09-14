#include <iostream>
#include <queue>
#include <cstring>
#include <array>

using namespace std;

int n, m;
int board[1001][1001];
int dist[1001][1001];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(int y, int x)
{
  queue<array<int,2>> q;
  q.push({y, x});
  dist[y][x] = 0;

  while(!q.empty())
  {
    auto [hereY, hereX] = q.front();
    q.pop();
    int nextY, nextX;

    for(int i=0; i<4; i++)
    {
      nextY = hereY + dy[i];
      nextX = hereX + dx[i];

      if(nextY < 0 || nextY >= n || nextX < 0 || nextX >= m || dist[nextY][nextX] != -1) continue;
      dist[nextY][nextX] = dist[hereY][hereX]+1;
      q.push({nextY, nextX});
    }
  }
}

int main()
{
  cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
  cin >> n >> m;
  int starti, startj;
  memset(dist, -1, sizeof(dist));
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      cin >> board[i][j];
      if(board[i][j] == 2)
      {
        starti = i;
        startj = j;
      }
      else if(board[i][j] == 0)
      {
        dist[i][j] = 0;
      }
    }
  }

  bfs(starti, startj);
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      cout << dist[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}