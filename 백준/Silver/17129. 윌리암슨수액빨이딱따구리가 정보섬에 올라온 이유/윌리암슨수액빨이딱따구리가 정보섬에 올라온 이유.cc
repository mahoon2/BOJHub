#include <iostream>
#include <queue>
#include <string>

#define INF 987654321

using namespace std;

int n, m;
int board[3001][3001];
int dist[3001][3001];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int bfs(pair<int,int> start)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            dist[i][j] = INF;
        }
    }

    queue<pair<int,int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;

    while(!q.empty())
    {
        auto p = q.front();
        q.pop();

        int& board_here = board[p.first][p.second];
        if(board_here == 3 || board_here == 4 || board_here == 5)
        {
            return dist[p.first][p.second];
        }

        for(int i=0; i<4; i++)
        {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(board[ny][nx] == 1 || dist[ny][nx] != INF) continue;

            dist[ny][nx] = dist[p.first][p.second] + 1;
            q.push(make_pair(ny, nx));
        }
    }

    return -1;
}

int ctoi(char c)
{
    if(c == '0') return 0;
    if(c == '1') return 1;
    if(c == '2') return 2;
    if(c == '3') return 3;
    if(c == '4') return 4;
    if(c == '5') return 5;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    cin >> n >> m;

    pair<int,int> start;
    string temp;

    for(int i=0; i<n; i++)
    {
        cin >> temp;
        for(int j=0; j<m; j++)
        {
            board[i][j] = ctoi(temp[j]);
            if(board[i][j] == 2)
            {
                start = make_pair(i, j);
            }
        }
    }

    int ret = bfs(start);
    if(ret == -1)
    {
        cout << "NIE\n";
    }
    else
    {
        cout << "TAK\n";
        cout << ret << '\n';
    }

    return 0;
}