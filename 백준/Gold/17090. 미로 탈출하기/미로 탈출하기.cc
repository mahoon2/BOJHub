#include <iostream>
#include <vector>
#include <cstring>
#include <string>

#define MAX_N 501

using namespace std;

int n, m;
int isCycle[MAX_N][MAX_N]; // -1 for unvisited, 0 for visiting, 1 for impossible, 2 for possible
int adj[MAX_N][MAX_N];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int dfs(int y, int x)
{
    if(isCycle[y][x] == 0)
    {
        return isCycle[y][x] = 1;
    }

    isCycle[y][x] = 0;

    int& idx = adj[y][x];
    int next_y = y + dy[idx];
    int next_x = x + dx[idx];

    if(next_y < 0 || next_y >= n || next_x < 0 || next_x >= m) return isCycle[y][x] = 2;
    if(isCycle[next_y][next_x] == 1 || isCycle[next_y][next_x] == 2) return isCycle[y][x] = isCycle[next_y][next_x];
    return isCycle[y][x] = dfs(next_y, next_x);
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    memset(isCycle, -1, sizeof(isCycle));

    cin >> n >> m;

    string inp;
    for(int i=0; i<n; i++)
    {
        cin >> inp;
        for(int j=0; j<m; j++)
        {
            if(inp[j] == 'U')
            {
                adj[i][j] = 0;
            }
            else if(inp[j] == 'D')
            {
                adj[i][j] = 1;
            }
            else if(inp[j] == 'L')
            {
                adj[i][j] = 2;
            }
            else if(inp[j] == 'R')
            {
                adj[i][j] = 3;
            }
            else
            {
                cout << "Something went wrong...\n";
            }
        }
    }

    int ret = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(isCycle[i][j] == -1)
            {
                dfs(i, j);
            }

            if(isCycle[i][j] == 2)
            {
                ret++;
            }
        }
    }

    cout << ret << '\n';

    return 0;
}