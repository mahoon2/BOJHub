#include <bits/stdc++.h>

#define INF 987654321
#define fi first
#define se second
#define pii pair<int,int>

#define FOR(i, n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(), (v).end()
#define MAX_N 100010

using ll = long long;
using ld = long double;

using namespace std;

typedef struct _Node{
    int start;
    int end;
    ll sum;
    ll lazy;
}Node;

int n;
vector<int> adj[MAX_N];
int Start[MAX_N], End[MAX_N];
Node tree[4*MAX_N];
int cnt = 0;

void lazy_update(int idx)
{
    Node& here = tree[idx];

    if(here.lazy)
    {
        if(here.start != here.end)
        {
            tree[2*idx].lazy += here.lazy;
            tree[2*idx+1].lazy += here.lazy;
        }
        here.sum += here.lazy*(here.end - here.start + 1);
        here.lazy = 0;
    }
}

ll update(int idx, int& left, int& right, int& k)
{
    Node& here = tree[idx];
    lazy_update(idx);

    if(right < here.start || here.end < left) return 0;
    else if(left <= here.start && here.end <= right)
    {
        here.lazy += k;
        lazy_update(idx);
    }
    else
    {
        here.sum = update(2*idx, left, right, k) +
                    update(2*idx+1, left, right, k);
    }

    return here.sum;
}

ll query(int idx, int& left, int& right)
{
    Node& here = tree[idx];
    lazy_update(idx);

    if(right < here.start || here.end < left) return 0;
    else if(left <= here.start && here.end <= right)
    {
        return here.sum;
    }
    else
    {
        return query(2*idx, left, right) +
                    query(2*idx+1, left, right);
    }
}

void dfs(int here)
{
    Start[here] = ++cnt;
    for(int there: adj[here])
    {
        dfs(there);
    }
    End[here] = cnt;
}

void init(int idx, int left, int right)
{
    if(left > right) return;

    Node& here = tree[idx];
    here.start = left;
    here.end = right;
    here.sum = here.lazy = 0;

    if(left != right)
    {
        int mid = (left + right)/2;
        init(2*idx, left, mid);
        init(2*idx+1, mid+1, right);
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int m;
    cin >> n >> m;

    int parent;
    for(int i=1; i<=n; i++)
    {
        cin >> parent;
        if(parent != -1)
        {
            adj[parent].push_back(i);
        }
    }

    dfs(1);
    init(1, 1, n);

    int a, b, c;
    while(m--)
    {
        cin >> a;
        if(a == 1)
        {
            cin >> b >> c;
            int left = Start[b];
            int right = End[b];
            update(1, left, right, c);
        }
        else
        {
            cin >> b;
            int left = Start[b];
            cout << query(1, left, left) << '\n';
        }
    }
    
    return 0;
}