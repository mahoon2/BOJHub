#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 101
#define INF 987654321

using namespace std;

int n;
int dist[MAX_N][MAX_N];
bool visited[MAX_N] = {false, };
vector<vector<int>> adj;

void dfs(int here, vector<int>& temp)
{
    visited[here] = true;
    temp.push_back(here);

    for(int there=1; there<=n; there++)
    {
        if(dist[here][there] == 1 && !visited[there])
        {
            dfs(there, temp);
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int m;
    cin >> n >> m;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dist[i][j] = INF;
        }
    }

    int from, to;
    while(m--)
    {
        cin >> from >> to;
        dist[from][to] = 1;
        dist[to][from] = 1;
    }

    int comp = 0;
    for(int i=1; i<=n; i++)
    {
        dist[i][i] = 0;
        if(!visited[i])
        {
            adj.push_back(vector<int>());
            dfs(i, adj[comp++]);
        }
    }
    
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            if(dist[i][k] == INF) continue;
            for(int j=1; j<=n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    cout << comp << '\n';
    vector<int> ret;
    for(vector<int>&temp: adj)
    {
        int representative = temp[0];
        int min_ret = INF;

        for(int i=0; i<temp.size(); i++)
        {
            int ret = -1;
            for(int j=0; j<temp.size(); j++)
            {
                if(temp[i]==temp[j]) continue;
                ret = max(ret, dist[temp[i]][temp[j]]);
            }
            if(min_ret > ret)
            {
                min_ret = ret;
                representative = temp[i];
            }
        }
        ret.push_back(representative);
    }
    sort(ret.begin(), ret.end());
    for(int i: ret)
    {
        cout << i << '\n';
    }

    return 0;
}