#include <iostream>
#include <vector>
#include <cmath>

#define MAX_N 40001

using namespace std;

int n;
int max_depth = 0;
int depth[MAX_N];
pair<int,int> par[17][MAX_N];
vector<pair<int,int>> adj[MAX_N];

void dfs(int prev, int here)
{
    depth[here] = depth[prev] + 1;

    for(auto p: adj[here])
    {
        if(p.second == prev)
        {
            par[0][here] = make_pair(p.first, prev);
        }
        else
        {
            dfs(here, p.second);
        }
    }

    max_depth = max(max_depth, depth[here]);
}

void set_par()
{
    max_depth = (int)(log2(max_depth));
    for(int level=1; level<=max_depth; level++)
    {
        for(int i=1; i<=n; i++)
        {
            auto p = par[level-1][par[level-1][i].second];
            par[level][i] = make_pair(par[level-1][i].first+p.first, p.second);
        }
    }
}

int query(int x, int y)
{
    if(depth[x] > depth[y])
    {
        int temp = x;
        x = y;
        y = temp;
    }

    // ShiftExponent error
    int dh = depth[y] - depth[x];
    int ret = 0;
    for(int level=max_depth; level>=0; level--)
    {
        if((1<<level) & dh)
        {
            ret += par[level][y].first;
            y = par[level][y].second;
        }
    }

    if(x == y) return ret;

    for(int level=max_depth; level>=0; level--)
    {
        if(par[level][x].second != par[level][y].second)
        {
            ret += par[level][x].first + par[level][y].first;
            x = par[level][x].second;
            y = par[level][y].second;
        }
    }

    ret += par[0][x].first + par[0][y].first;
    return ret;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;

    int from, to, cost;
    for(int i=0; i<n-1; i++)
    {
        cin >> from >> to >> cost;
        adj[from].push_back(make_pair(cost, to));
        adj[to].push_back(make_pair(cost, from));
    }

    depth[0] = 0;
    dfs(0, 1);
    set_par();

    int m;
    cin >> m;
    while(m--)
    {
        cin >> from >> to;
        cout << query(from, to) << '\n';
    }

    return 0;
}