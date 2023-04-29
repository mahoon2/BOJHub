#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

#define MAX_N 10002

using namespace std;

int n, t;
int parent[MAX_N];
vector<array<int,3>> adj;

int find_parent(int here)
{
    if(here == parent[here]) return here;
    else return parent[here] = find_parent(parent[here]);
}

void merge(int x, int y)
{
    int px = find_parent(x);
    int py = find_parent(y);

    if(px == py) return;

    parent[py] = px;
}

int mst()
{
    int ret = 0;
    int plus_fee = 0;

    for(int i=1; i<=n; i++)
    {
        parent[i] = i;
    }
    sort(adj.begin(), adj.end());

    for(int i=0; i<adj.size(); i++)
    {
        auto& [cost, from, to] = adj[i];

        if(find_parent(from) != find_parent(to))
        {
            ret += cost + plus_fee;
            plus_fee += t;
            merge(from, to);
        }
    }

    return ret;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int m;
    cin >> n >> m >> t;

    int from, to, cost;
    while(m--)
    {
        cin >> from >> to >> cost;
        adj.push_back({cost, from, to});
    }

    int ret = mst();
    cout << ret << '\n';

    return 0;
}