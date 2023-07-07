#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <algorithm>

#define MAX_N 100002

typedef long long ll;

using namespace std;

typedef struct Node{
    int parent;
    map<int,int> company_map;
}Node;

int n, k, m;
int company[MAX_N];
vector<array<int,3>> edges; // cost, from, to

vector<ll> ret(MAX_N, 0);
Node tree[MAX_N];

bool comp(array<int,3>& a, array<int,3>& b)
{
    // b가 나중에 가면 true

    if(a[0] > b[0]) return true;
    else return false;
}

int find_parent(int here)
{
    if(tree[here].parent == here) return here;
    else return tree[here].parent = find_parent(tree[here].parent);
}

void merge(int x, int y, int cost)
{
    int px = find_parent(x);
    int py = find_parent(y);

    if(px == py) return;

    if(tree[px].company_map.size() > tree[py].company_map.size())
    {
        swap(px, py);
    }

    tree[px].parent = py;
    auto& mapx = tree[px].company_map;
    auto& mapy = tree[py].company_map;

    for(auto [key, value]: mapx)
    {
        ret[key] += (ll)value * mapy[key] * cost;
        mapy[key] += value;
    }
}

void kruskal()
{
    sort(edges.begin(), edges.end(), comp);

    for(array<int,3>& here: edges)
    {
        int cost = here[0]; 
        int from = here[1];
        int to = here[2];

        merge(from, to, cost);
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> k >> m;

    for(int i=1; i<=n; i++)
    {
        cin >> company[i];
        tree[i].parent = i;
        tree[i].company_map.insert({company[i], 1});
    }

    int from, to, cost;
    for(int i=0; i<m; i++)
    {
        cin >> from >> to >> cost;
        edges.push_back({cost, from, to});
    }

    kruskal();
    for(int i=1; i<=k; i++)
    {
        cout << ret[i] << '\n';
    }

    return 0;
}