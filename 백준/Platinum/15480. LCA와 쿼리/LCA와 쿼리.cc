#include <bits/stdc++.h>

#define MAX_N 100010

#define INF 987654321
#define fi first
#define se second
#define pii pair<int,int>

#define FOR(i, n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(), (v).end()
#define pb(v) push_back((v))
#define eb(v) emplace_back((v))

using ll = long long;
using ld = long double;

using namespace std;

int n;
vector<int> adj[MAX_N];
int depth[MAX_N];
int par[18][MAX_N];
int max_depth = -1;

void dfs(int prev, int here)
{
    depth[here] = depth[prev]+1;
    par[0][here] = prev;

    for(int there: adj[here])
    {
        if(there == prev) continue;
        dfs(here, there);
    }

    max_depth = max(max_depth, depth[here]);
}

void init()
{
    for(int lvl=1; lvl<=max_depth; lvl++)
    {
        for(int i=1; i<=n; i++)
        {
            par[lvl][i] = par[lvl-1][par[lvl-1][i]];
        }
    }
}

int lca(int a, int b)
{
    if(depth[a] > depth[b]) swap(a, b);
    
    int dh = depth[b] - depth[a];
    for(int lvl=max_depth; lvl>=0; lvl--)
    {
        if(dh & (1<<lvl)) b = par[lvl][b];
    }

    if(a == b) return a;

    for(int lvl=max_depth; lvl>=0; lvl--)
    {
        if(par[lvl][a] != par[lvl][b])
        {
            a = par[lvl][a];
            b = par[lvl][b];
        }
    }

    return par[0][a];
}

int solve(int r, int a, int b)
{
    int x = lca(r, a);
    int y = lca(r, b);
    int z = lca(a, b);

    if(depth[x] >= depth[y]) swap(x, y);
    if(depth[y] >= depth[z]) swap(y, z);
    return z;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    
    cin >> n;
    int from, to;
    FOR(i, n-1)
    {
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    depth[0] = 0;
    dfs(0, 1);
    max_depth = (int)log2(max_depth);
    init();

    int m, root;
    cin >> m;
    while(m--)
    {
        cin >> root >> from >> to;
        cout << solve(root, from, to) << '\n';
    }

    return 0;
}