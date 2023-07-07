#include <iostream>
#include <cstring>
#include <vector>
#define MAX_N 1001

using namespace std;

int n, m, k;
int parent[MAX_N];
bool indegree[MAX_N], visited[MAX_N];
vector<int> adj[MAX_N];

void dfs(int here)
{
    visited[here] = true;

    if(adj[here].size() > m)
    {
        for(int i=m; i<adj[here].size(); i++)
        {
            adj[adj[here][i-m]].push_back(adj[here][i]);
        }

        adj[here].erase(adj[here].begin()+m, adj[here].end());
    }

    for(int there: adj[here])
    {
        if(!visited[there])
        {
            dfs(there);
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    memset(indegree, false, sizeof(indegree));
    memset(visited, false, sizeof(visited));

    int temp, next;
    for(int i=1; i<=n; i++)
    {
        cin >> temp;
        for(int j=0; j<temp; j++)
        {
            cin >> next;
            indegree[next] = true;
            adj[i].push_back(next);
        }
    }

    int root;
    for(int i=1; i<=n; i++)
    {
        if(!indegree[i])
        {
            root = i;
            break;
        }
    }

    dfs(root);

    cout << "1\n0\n";
    for(int i=1; i<=n; i++)
    {
        cout << adj[i].size() << " ";
        for(int there: adj[i])
        {
            cout << there << " ";
        }
        cout << "\n";
    }

    return 0;
}