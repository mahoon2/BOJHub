#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>

#define MAX_N 100002

using namespace std;
typedef long long ll;

ll n;
ll inp[MAX_N];
ll tree[MAX_N] = {0, };
vector<array<ll,2>> firstQuery; // i v
vector<array<ll,4>> secondQuery; // k idx i j
vector<pair<ll,ll>> out; // idx ret

ll sum(ll i)
{
    ll ret = 0;

    while(i >= 1)
    {
        ret += tree[i];
        i -= (i & -i);
    }
    return ret;
}

void update(ll i, ll x)
{
    while(i <= n)
    {
        tree[i] += x;
        i += (i & -i);
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    /*ifstream fin;
    fin.open("1.inp");*/
    cin >> n;
    for(ll i=1; i<=n; i++)
    {
        cin >> inp[i];
        update(i, inp[i]);
    }

    ll m;
    ll q;
    ll a, b, c;
    ll secondQueryCnt = 0;
    cin >> m;
    while(m--)
    {
        cin >> q;
        if(q == 1)
        {
            cin >> a >> b;
            // inp[a] = b 로 변경
            firstQuery.push_back({a, b});
        }
        else if(q == 2)
        {
            cin >> a >> b >> c;
            a--; // a == -1일 경우 아무런 쿼리도 적용하지 않음
            secondQuery.push_back({a, secondQueryCnt++, b, c});
        }
    }
    sort(secondQuery.begin(), secondQuery.end());

    ll last_k = -1;
    for(auto[k, idx, i, j]: secondQuery)
    {
        if(last_k != k)
        {
            for(int f=last_k+1; f<=k; f++)
            {
                auto[a, b] = firstQuery[f];
                update(a, (ll)(b)-inp[a]);
                inp[a] = b;
            }
        }

        ll ret = sum(j) - sum(i-1);
        out.push_back(make_pair(idx, ret));
        last_k = k;
    }

    sort(out.begin(), out.end());
    for(auto o: out)
    {
        cout << o.second << '\n';
    }

    return 0;
}