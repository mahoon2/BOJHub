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
vector<int> tempy;
vector<pii> inp;
int tree[75001];

int sum(int i)
{
    int ret = 0;
    while(i >= 1)
    {
        ret += tree[i];
        i -= (i & -i);
    }
    return ret;
}

void update(int i, int num)
{
    while(i <= n)
    {
        tree[i] += num;
        i += (i & -i);
    }
}

bool comp(pii& a, pii& b)
{
    if(a.fi == b.fi) return a.se > b.se;
    return a.fi < b.fi;
}

ll solve()
{
    cin >> n;
    tempy = vector<int>(n);
    inp = vector<pii> (n);
    memset(tree, 0, sizeof(tree));

    FOR(i, n)
    {
        auto& p = inp[i];
        cin >> p.fi >> p.se;
        tempy[i] = p.se;
    }
    if(n == 1) return 0;

    sort(all(tempy));
    tempy.erase(unique(all(tempy)), tempy.end());
    for(auto& p: inp)
    {
        p.se = lower_bound(all(tempy), p.se) - tempy.begin();
    }

    sort(all(inp), comp);
    ll ret = 0;
    for(auto& p: inp)
    {
        ret += sum(n) - sum(p.se);
        update(p.se+1, 1);
    }
    return ret;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    
    int t; cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}