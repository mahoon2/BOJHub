#include <bits/stdc++.h>

#define INF 987654321
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#define sz(v) ((int)v.size())

#define MAX_N 20001

#define rep(i, n) for(int i=0; i<(n); i++)
#define rrep(i, n) for(int i=1; i<=(n); i++)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using ld = long double;

using namespace std;

int n, m;
vector<pii> adj[MAX_N];

char buf[1 << 17];

char read() {
    static int idx = 1 << 17;
    if (idx == 1 << 17) {
        fread(buf, 1, 1 << 17, stdin);
        idx = 0;
    }
    return buf[idx++];
}

int readInt() {
    int t, r = read() & 15;
    while ((t = read()) & 16) r = r * 10 + (t & 15);
    return r;
}

class BucketHeap{
    int size;
    int MOD;
    vector<vector<int>> arr; // 버킷을 원소로 갖는 힙 배열, 버킷의 첫 원소를 Key로 간주
    vector<int> KeyIdx; // key -> arr에서 bucket 번호로 Mapping
    vector<int> ValueIdx; // value -> 대응되는 arr의 bucket안에서의 idx로 Mapping

    public:
    void init(int v, int w)
    {
        size = 0;
        MOD = w+1;
        arr = vector<vector<int>> (w+1, vector<int>());
        KeyIdx = vector<int> (w+1, -1);
        ValueIdx = vector<int> (v+1, -1);
    }

    void percolateUp(int here)
    {
        if(here >= size) return;
        int parent;

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
            if(lchild >= size) break;
            
            if(rchild < size && arr[rchild][0] < arr[lchild][0])
            {
                lchild = rchild;
            }
            if(arr[lchild][0] >= arr[here][0]) break;

            swap(KeyIdx[arr[lchild][0] % MOD], KeyIdx[arr[here][0] % MOD]);
            swap(arr[lchild], arr[here]);
            here = lchild;
        }
    }
    
    void push_key(int key)
    {
        // 힙의 맨 끝에 추가 후, 수선(스며오르기)
        arr[size].push_back(key);
        KeyIdx[key % MOD] = size++;

        percolateUp(size-1);
    }

    void push(int key, int value)
    {
        // Key에 대응되는 버킷이 없다면 새로 추가
        if(KeyIdx[key % MOD] == -1) push_key(key);
        int bucket = KeyIdx[key % MOD];
        arr[bucket].push_back(value);
        ValueIdx[value] = arr[bucket].end() - arr[bucket].begin()-1;
    }

    void pop_key(int key)
    {
        // 힙의 마지막 원소와 swap한 후, 수선(스며내리기 or 스며올리기)
        if(size <= 0) return;
        int last_key = arr[size-1][0];
        
        swap(arr[KeyIdx[last_key % MOD]], arr[KeyIdx[key % MOD]]);
        swap(KeyIdx[last_key % MOD], KeyIdx[key % MOD]);

        // 버킷을 비우고, 힙의 크기를 1 줄인다
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

        // 이 연산으로 인해 옛 버킷이 비워지면 pop한다
        if(sz(arr[bucket]) <= 1) pop_key(oldKey);
        push(newKey, value);
    }

    int popMin()
    {
        auto iter = arr[0].end();
        iter--;
        
        // 힙의 맨 위 버킷에 있는 마지막 원소에 접근하여 pop
        int ret = *iter;
        arr[0].erase(iter);
        ValueIdx[ret] = -1;
        
        // 버킷이 텅 비면 버킷을 pop
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

void dijkstra(int start)
{
    vector<int> dist(n+1, INF);
    vector<bool> visited(n+1, false);
    BucketHeap bh;
    // 정점의 개수, 가중치의 상한으로 BucketHeap 초기화
    bh.init(n, 10);

    dist[start] = 0;
    bh.push(dist[start], start);

    while(!bh.empty())
    {
        int here = bh.popMin();
        if(visited[here]) continue;
        visited[here] = true;

        for(auto [cost, there]: adj[here])
        {
            if(dist[there] > dist[here] + cost)
            {
                int newKey = dist[here] + cost;
                if(dist[there] != INF)
                {
                    // 이전에 dist[there]이 갱신되어 bh에 {dist[there], there}이 삽입되어있다면
                    bh.modify(dist[there], newKey, there);
                }
                else
                {
                    // bh에 {dist[there], there}을 삽입하지 않았었다면
                    bh.push(newKey, there);
                }
                dist[there] = newKey;
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    n = readInt(); m = readInt();
    int from, to, cost, start;
    start = readInt();
    while(m--)
    {
        from = readInt();
        to = readInt();
        cost = readInt();
        adj[from].eb(cost, to);
    }

    dijkstra(start);
    
    return 0;
}