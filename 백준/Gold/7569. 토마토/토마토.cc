#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int m, n, h, cnt=0, ret=0;
int board[101][101][101];
int dz[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dx[] = {0, 0, 0, 0, -1, 1};

struct Tomato_pos
{
    int z, y, x, dist;
}typedef tomato_pos;

void bfs(vector<tomato_pos>& tomato_init)
{
    queue<tomato_pos> q;
    for(auto tomato: tomato_init)
        q.push(tomato);
    
    while(!q.empty())
    {
        auto here = q.front();
        q.pop();
        for(int i=0; i<6; i++)
        {
            int nz = here.z + dz[i];
            int ny = here.y + dy[i];
            int nx = here.x + dx[i];
            if(0 <= nz && nz < h && 0 <= ny && ny < n && 0 <= nx && nx < m && board[nz][ny][nx] == 0)
            {
                board[nz][ny][nx] = 1;
                tomato_pos next = {nz, ny, nx, here.dist+1};
                q.push(next);
                cnt--;
                ret = max(ret, next.dist);
            }
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> m >> n >> h;

    vector<tomato_pos> tomato_init;
    for(int i=0; i<h; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<m; k++)
            {
                cin >> board[i][j][k];
                if(board[i][j][k] == 1)
                {
                    tomato_pos temp = {i, j, k, 0};
                    tomato_init.push_back(temp);
                }
                else if(board[i][j][k] == 0)
                    cnt++;
            }
    
    bfs(tomato_init);
    if(cnt)
        cout << -1 << '\n';
    else
        cout << ret << '\n';

    return 0;
}