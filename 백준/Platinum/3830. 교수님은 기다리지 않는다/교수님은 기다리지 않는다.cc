#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<pair<int,int>>> adj;
vector<int> dist;
vector<bool> visited;
vector<int> parent;

int find_parent(int here)
{
    if(parent[here] == here) return here;
    else return parent[here] = find_parent(parent[here]);
}

void merge(int x, int y)
{
    int px = find_parent(x);
    int py = find_parent(y);

    if(px == py) return;
    parent[py] = px;
}

void bfs(int start)
{
    queue<pair<int,int>> q;
    q.push(make_pair(0, start));

    while(!q.empty())
    {
        auto& temp = q.front();
        int here_dist = temp.first; int here = temp.second;
        q.pop();

        if(visited[here]) continue;
        visited[here] = true;
        dist[here] = here_dist;

        for(auto& p: adj[here])
        {
            int next_dist = p.first + here_dist; int next = p.second;
            if(!visited[next]) q.push(make_pair(next_dist, next));
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    while(true)
    {
        int m;
        cin >> n >> m;
        if(n == 0 && m == 0) return 0;

        adj = vector<vector<pair<int,int>>> (n+1);
        dist = parent = vector<int> (n+1);
        visited = vector<bool> (n+1, false);
        queue<pair<bool,pair<int,int>>> is_query_possible;
        for(int i=1; i<=n; i++)
        {
            parent[i] = i;
        }

        char c;
        int a, b, w;
        for(int i=0; i<m; i++)
        {
            cin >> c;
            if(c == '!')
            {
                cin >> a >> b >> w;
                adj[a].push_back(make_pair(w, b));
                adj[b].push_back(make_pair(-w, a));
                merge(a, b);
            }
            else if(c == '?')
            {
                cin >> a >> b;
                if(find_parent(a) == find_parent(b))
                    is_query_possible.push(make_pair(true, make_pair(a, b)));
                else
                    is_query_possible.push(make_pair(false, make_pair(0, 0)));
            }
        }

        for(int i=1; i<=n; i++)
        {
            if(!visited[i])
            {
                bfs(i);
            }
        }

        while(!is_query_possible.empty())
        {
            auto t = is_query_possible.front();
            is_query_possible.pop();

            if(!t.first)
                cout << "UNKNOWN\n";
            else
            {
                cout << dist[t.second.second] - dist[t.second.first] << '\n';
            }
        }
    }

    return 0;
}