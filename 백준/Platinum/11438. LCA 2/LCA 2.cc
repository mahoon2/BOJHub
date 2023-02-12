#include <iostream>
#include <vector>
#include <cmath>

#define MAX_N 100001

using namespace std;

int n;
vector<int> adj[MAX_N];
int par[18][MAX_N]; // 2^17 > 100000
int depth[MAX_N];
int max_depth = 0;

void dfs(int prev, int here)
{
    depth[here] = depth[prev] + 1;
    par[0][here] = prev;

    for(int next: adj[here])
    {
        if(next != prev)
        {
            dfs(here, next);
        }
    }

    max_depth = max(depth[here], max_depth);
}

void set_par()
{
    for(int lvl=1; lvl<=max_depth; lvl++)
    {
        for(int i=1; i<=n; i++)
        {
            par[lvl][i] = par[lvl-1][par[lvl-1][i]];
            // cout << lvl << " " << i << " " << par[lvl][i] << '\n';
        }
    }
}

int solve(int a, int b)
{
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
            b = par[lvl][b];
        }
    }

    //cout << a << " " << b << '\n';

    if(a == b) return a;

    for(int lvl=max_depth; lvl>=0; lvl--)
    {
        if(par[lvl][a] != par[lvl][b])
        {
            a = par[lvl][a];
            b = par[lvl][b];
        }
    }

    //cout << a << " " << b << "\n";

    return par[0][a];
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;

    int from, to;
    for(int i=0; i<n-1; i++)
    {
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    int root = 1;
    depth[0] = 0;
    dfs(0, root);
    max_depth = (int)log2(max_depth);
    set_par();

    int m;
    cin >> m;
    while(m--)
    {
        cin >> from >> to;
        cout << solve(from, to) << "\n";
    }

    return 0;
}