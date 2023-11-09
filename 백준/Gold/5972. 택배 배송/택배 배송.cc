#include <bits/stdc++.h>

#define INF 987654321
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#define sz(v) ((int)v.size())
#define MAX_N 50001

#define rep(i, n) for(int i=0; i<(n); i++)
#define rrep(i, n) for(int i=1; i<=(n); i++)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using ld = long double;

using namespace std;

int n, m;
vector<pii> adj[MAX_N];

class BucketHeap{
    int size;
    int MOD;
    vector<int> arr[100001];
    vector<int> KeyIdx;
    vector<int> ValueIdx;

    public:
    void init(int v, int w)
    {
        size = 0;
        MOD = w+1;
        KeyIdx = vector<int> (w+1, -1);
        ValueIdx = vector<int> (v+1, -1);
    }

    void percolateUp(int here)
    {
        int parent;
        if(here >= size) return;

        while(here > 0)
        {
            parent = (here-1)/2;

            if(arr[parent][0] < arr[here][0]) break;
            swap(KeyIdx[arr[parent][0] % MOD], KeyIdx[arr[here][0] % MOD]);
            swap(arr[parent], arr[here]);

            here = parent;
        }
    }

    void percolateDown(int here)
    {
        int lchild, rchild;
        if(here < 0) return;

        while(here < size)
        {
            lchild = 2*here+1, rchild = 2*here+2;
            if(lchild < size)
            {
                if(rchild < size && arr[rchild][0] < arr[lchild][0])
                {
                    lchild = rchild;
                }
                if(arr[lchild][0] < arr[here][0])
                {
                    swap(KeyIdx[arr[lchild][0] % MOD], KeyIdx[arr[here][0] % MOD]);
                    swap(arr[lchild], arr[here]);
                    here = lchild;
                }
                else break;
            }
            else break;
        }
    }
    
    void push_key(int key)
    {
        arr[size].push_back(key);
        KeyIdx[key % MOD] = size++;

        percolateUp(size-1);
    }

    void push(int key, int value)
    {
        if(KeyIdx[key % MOD] == -1) push_key(key);
        int bucket = KeyIdx[key % MOD];
        arr[bucket].push_back(value);
        ValueIdx[value] = arr[bucket].end() - arr[bucket].begin()-1;
    }

    void pop_key(int key)
    {
        if(size <= 0) return;
        if(key == 3932)
        {
            //cout << "debug\n";
        }
        int last_key = arr[size-1][0];
        swap(arr[KeyIdx[last_key % MOD]], arr[KeyIdx[key % MOD]]);
        swap(KeyIdx[last_key % MOD], KeyIdx[key % MOD]);
        arr[KeyIdx[key % MOD]].clear();
        KeyIdx[key % MOD] = -1;
        size--;
        percolateUp(KeyIdx[last_key % MOD]);
        percolateDown(KeyIdx[last_key % MOD]);
    }

    void modify(int oldKey, int newKey, int value)
    {
        int bucket = KeyIdx[oldKey % MOD];
        int temp_value = arr[bucket][sz(arr[bucket])-1];
        swap(arr[bucket][sz(arr[bucket])-1], arr[bucket][ValueIdx[value]]);
        swap(ValueIdx[temp_value], ValueIdx[value]);
        arr[bucket].erase(--arr[bucket].end());
        if(oldKey == 3932)
        {
            //cout << "debug\n";
        }
        if(sz(arr[bucket]) <= 1) pop_key(oldKey);
        push(newKey, value);
    }

    int popMin()
    {
        auto iter = arr[0].end();
        iter--;
        int ret = *iter;
        arr[0].erase(iter);
        ValueIdx[ret] = -1;
        if(sz(arr[0]) <= 1)
        {
            pop_key(arr[0][0]);
        }
        return ret;
    }

    bool empty()
    {
        return (size <= 0);
    }
};

int dijkstra(int start, int finish)
{
    vector<int> dist(n+1, INF);
    vector<bool> visited(n+1, false);
    BucketHeap bh;
    bh.init(n, 1000);

    dist[start] = 0;
    bh.push(dist[start], start);

    while(!bh.empty())
    {
        int here = bh.popMin();
        if(visited[here]) continue;
        if(here == finish) return dist[here];
        visited[here] = true;

        for(auto [cost, there]: adj[here])
        {
            if(dist[there] > dist[here] + cost)
            {
                int newKey = dist[here] + cost;
                if(newKey > 1000)
                {
                    //cout << here << '\n';
                }
                if(dist[there] != INF)
                {
                    bh.modify(dist[there], newKey, there);
                }
                else
                {
                    bh.push(newKey, there);
                }
                dist[there] = newKey;
            }
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> m;
    int from, to, cost;
    while(m--)
    {
        cin >> from >> to >> cost;
        adj[from].eb(cost, to);
        adj[to].eb(cost, from);
    }

    //cin >> from >> to;
    cout << dijkstra(1, n) << '\n';
    
    return 0;
}