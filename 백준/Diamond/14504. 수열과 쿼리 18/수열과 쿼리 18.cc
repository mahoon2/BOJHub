#include <bits/stdc++.h>

#define INF 987654321
#define fi first
#define se second
#define pii pair<int,int>

#define FOR(i, n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using ld = long double;

using namespace std;
int n;
int rootn;
int inp[100010];
vector<int> sorted[400];

int query(int start, int end, int k)
{
    int ret = 0;
    while(start % rootn != 0 && start <= end)
    {
        if(inp[start++] > k) ret++;
    }
    while(end % rootn != rootn-1 && start <= end)
    {
        if(inp[end--] > k) ret++;
    }

    if(start > end) return ret;

    int idxStart = start/rootn;
    int idxEnd = end/rootn;

    while(idxStart <= idxEnd)
    {
        ret += sorted[idxStart].end() - upper_bound(all(sorted[idxStart]), k);
        idxStart++;
    }

    return ret;
}

void update(int updateIdx, int k)
{
    int idx = updateIdx / rootn;
    int& backup = inp[updateIdx];

    sorted[idx].erase(lower_bound(all(sorted[idx]), backup));
    sorted[idx].insert(lower_bound(all(sorted[idx]), k), k);

    backup = k;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    
    cin >> n;
    rootn = (int)sqrt(n);
    vector<int> temp;
    FOR(i, n)
    {
        int idx = i/rootn;
        cin >> inp[i];
        if(i % rootn == 0 && i != 0)
        {
            sort(all(sorted[idx-1]));
        }
        sorted[idx].push_back(inp[i]);
    }

    sort(all(sorted[(n-1)/rootn]));

    int m;
    cin >> m;
    int op, a, b, c;
    while(m--)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> a >> b >> c;
            a--; b--;
            cout << query(a, b, c) << '\n';
        }
        else
        {
            cin >> a >> b;
            a--;
            update(a, b);
        }
    }

    return 0;
}