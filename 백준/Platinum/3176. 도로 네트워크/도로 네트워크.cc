#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#define MAX_N 100002

using namespace std;

int n, max_depth;
vector<pair<int,int>> adj[MAX_N];
int depth[MAX_N];
int parent[18][MAX_N]; // 2^17 > 100,000
int route[MAX_N];
int minimum[18][MAX_N];
int maximum[18][MAX_N];

void dfs(int here)
{
    max_depth = max(max_depth, depth[here]);

    for(auto& p: adj[here])
    {
        int dist = p.first; int next = p.second;
        if(depth[next] == -1)
        {
            depth[next] = depth[here]+1;
            parent[0][next] = here;
            route[next] = dist;
            dfs(next);
        }
    }
}

void set_lca()
{
    for(int i=0; i<=max_depth; i++)
    {
        for(int j=0; j<=n; j++)
        {
            minimum[i][j] = 987654321;
            maximum[i][j] = -1;
        }
    }

    for(int i=1; i<=n; i++)
    {
        minimum[0][i] = maximum[0][i] = route[i];
    }

    for(int lvl=1; lvl<=max_depth; lvl++)
    {
//        cout << lvl << '\n';
        for(int i=1; i<=n; i++)
        {
            parent[lvl][i] = parent[lvl-1][parent[lvl-1][i]];
            minimum[lvl][i] = min(minimum[lvl-1][i], minimum[lvl-1][parent[lvl-1][i]]);
            maximum[lvl][i] = max(maximum[lvl-1][i], maximum[lvl-1][parent[lvl-1][i]]);

//            cout << i << " " << parent[lvl][i] << " " << minimum[lvl][i] << " " << maximum[lvl][i] << '\n';
        }
    }
}

pair<int,int> query(int a, int b)
{
    pair<int,int> ret = make_pair(987654321, -1);

    if(depth[a] > depth[b])
    {
        int temp = a;
        a = b;
        b = temp;
    }

    int dh = depth[b] - depth[a];
    for(int lvl=max_depth; lvl>=0; lvl--)
    {
        if((1<<lvl) & dh)
        {
            ret.first = min(ret.first, minimum[lvl][b]);
            ret.second = max(ret.second, maximum[lvl][b]);
            b = parent[lvl][b];
        }
    }

    if(a == b)
    {
        return ret;
    }

    for(int lvl=max_depth; lvl>=0; lvl--)
    {
        if(parent[lvl][a] != parent[lvl][b])
        {
            ret.first = min(ret.first, min(minimum[lvl][a], minimum[lvl][b]));
            ret.second = max(ret.second, max(maximum[lvl][a], maximum[lvl][b]));
            a = parent[lvl][a];
            b = parent[lvl][b];
        }
    }

    ret.first = min(ret.first, min(minimum[0][a], minimum[0][b]));
    ret.second = max(ret.second, max(maximum[0][a], maximum[0][b]));
    return ret;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;

    int a, b, c;
    for(int i=0; i<n-1; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(c, b));
        adj[b].push_back(make_pair(c, a));
    }

    max_depth = -1;
    memset(depth, -1, sizeof(depth));
    depth[1] = 0;
    parent[0][1] = 1;
    dfs(1);
    max_depth = (int)log2(max_depth);
    set_lca();

    int m;
    cin >> m;
    while(m--)
    {
        cin >> a >> b;
        pair<int,int> ret = query(a, b);
        cout << ret.first << " " << ret.second << '\n';
    }

    return 0;
}