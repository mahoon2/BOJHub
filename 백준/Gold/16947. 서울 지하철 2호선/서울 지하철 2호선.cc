#include <bits/stdc++.h>

#define INF 987654321
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#define sz(v) ((int)v.size())

#define rep(i, n) for(int i=0; i<(n); i++)
#define rrep(i, n) for(int i=1; i<=(n); i++)
#define all(v) (v).begin(), (v).end()
#define MAX_N 3001

using ll = long long;
using ld = long double;

using namespace std;

int n;
vector<int> adj[MAX_N];
int visited[MAX_N];
vector<int> dist;

int cycleCheck(int prev, int here)
{
    int ret;

    visited[here] = 1;
    for(int there: adj[here])
    {
        if(there == prev) continue;
        if(visited[there])
        {
            dist[here] = 0;
            return there;
        }
        else if((ret = cycleCheck(here, there)) != -1)
        {
            dist[here] = 0;
            if(ret == here) return -1;
            else return ret;
        }
    }

    return -1;
}

int dfs(int prev, int here)
{
    if(dist[here] != INF) return dist[here];

    for(int there: adj[here])
    {
        if(there == prev) continue;
        dist[here] = min(dist[here], dfs(here, there) + 1);
    }

    return dist[here];
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n;
    int from, to;
    rep(i, n)
    {
        cin >> from >> to;
        adj[from].pb(to);
        adj[to].pb(from);
    }
    memset(visited, 0, sizeof(visited));
    dist = vector<int> (n+1, INF);
    cycleCheck(0, 1);

    rrep(i, n)
    {
        dfs(0, i);
    }

    rrep(i, n)
    {
        cout << dist[i] << " ";
    }
    cout << '\n';
    
    return 0;
}