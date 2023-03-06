#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <array>

using namespace std;

int n, m;
int board[11][11];
int cnt = 1;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
vector<pair<int,int>> adj[7];
int parent[7];

void label_bfs()
{
    // Labeling
    bool visited[11][11];
    memset(visited, false, sizeof(visited));

    queue<pair<int,int>> q;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(board[i][j] != 0 && !visited[i][j])
            {
                q.push(make_pair(i, j));
                visited[i][j] = true;
                board[i][j] = cnt;

                while(!q.empty())
                {
                    auto [y, x] = q.front();
                    q.pop();

                    for(int d=0; d<4; d++)
                    {
                        int ny = y + dy[d]; int nx = x + dx[d];
                        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || board[ny][nx] == 0)
                        {
                            continue;
                        }
                        visited[ny][nx] = true;
                        board[ny][nx] = cnt;
                        q.push(make_pair(ny, nx));
                    }
                }
                cnt++;
            }
        }
    }
}

void count_horizon()
{
    // 가로 방향 다리 세기

    int dist, last_j;
    for(int i=0; i<n; i++)
    {
        last_j = -1;
        for(int j=0; j<m; j++)
        {
            if(last_j != -1 && board[i][j] != 0 && board[i][last_j] != board[i][j])
            {
                dist = j-last_j-1;
                if(dist >= 2)
                {
                    int from = board[i][last_j];
                    int to = board[i][j];
                    adj[from].push_back(make_pair(dist, to));
                    adj[to].push_back(make_pair(dist, from));
                }
            }
            if(board[i][j] != 0)
            {
                last_j = j;
            }
        }
    }
}

void count_vertical()
{
    // 세로 방향 다리 세기

    int dist, last_i;
    for(int j=0; j<m; j++)
    {
        last_i = -1;
        for(int i=0; i<n; i++)
        {
            if(last_i != -1 && board[i][j] != 0 && board[last_i][j] != board[i][j])
            {
                dist = i-last_i-1;
                if(dist >= 2)
                {
                    int from = board[last_i][j];
                    int to = board[i][j];
                    adj[from].push_back(make_pair(dist, to));
                    adj[to].push_back(make_pair(dist, from));
                }
            }
            if(board[i][j] != 0)
            {
                last_i = i;
            }
        }
    }
}

int find_parent(int x)
{
    if(parent[x] == x) return x;
    else return parent[x] = find_parent(parent[x]);
}

void merge(int x, int y)
{
    int px = find_parent(x);
    int py = find_parent(y);

    if(px == py) return;

    parent[py] = px;
}

int kruskal()
{
    vector<array<int,3>> weighted;
    for(int here=1; here<cnt; here++)
    {
        parent[here] = here;
        for(auto [dist, there]: adj[here])
        {
            weighted.push_back({dist, here, there});
        }
    }

    sort(weighted.begin(), weighted.end());

    int ret = 0;
    for(auto [dist, here, there]: weighted)
    {
        if(find_parent(here) == find_parent(there)) continue;
        ret += dist;
        merge(here, there);
    }

    int p = find_parent(1);
    for(int here=2; here<cnt; here++)
    {
        if(find_parent(here) != p) return -1;
    }
    return ret;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> board[i][j];
        }
    }

    label_bfs();
    count_horizon();
    count_vertical();
    
    /*cout << '\n';
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }*/

    cout << kruskal() << '\n';

    return 0;
}