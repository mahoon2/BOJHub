#include <iostream>
#include <string>

using namespace std;
int n, m;
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
int board[1001][1001];
bool visited[1001][1001] = {false, };
int parent[10001001];
bool parent_visited[10001001] = {false, };

int find_parent(int y, int x)
{
    int index = y*10000 + x;
    if(parent[index] == index)
        return index;
    else
        return parent[index] = find_parent(parent[index]/10000, parent[index]%10000);
}

void dfs(int y, int x)
{
    visited[y][x] = true;

    int index = board[y][x];
    int next_y = y + dy[index], next_x = x + dx[index];
    parent[y*10000+x] = find_parent(next_y, next_x);

    if(!visited[next_y][next_x])
        dfs(next_y, next_x);
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for(int i=0; i<10001001; i++)
        parent[i] = i;

    string inp;
    for(int i=0; i<n; i++)
    {
        cin >> inp;
        for(int j=0; j<m; j++)
        {
            if(inp[j] == 'U')
                board[i][j] = 0;
            else if(inp[j] == 'D')
                board[i][j] = 1;
            else if(inp[j] == 'L')
                board[i][j] = 2;
            else
                board[i][j] = 3;
        }
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(!visited[i][j])
                dfs(i, j);

    int cnt = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            int parent_index = find_parent(i, j);
            if(!parent_visited[parent_index])
            {
                parent_visited[parent_index] = true;
                cnt++;
            }
        }

    cout << cnt << '\n';
    return 0;
}