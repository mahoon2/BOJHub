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

ll n;
ll l;
ll pos[100010];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n;
    ll left = 0;
    ll temp;
    FOR(i, n)
    {
        cin >> temp;
        pos[i] = left+temp;
        left += 2*temp;
    }

    cin >> l;
    int q;
    cin >> q;

    cout << fixed;
    cout.precision(2);
    while(q--)
    {
        cin >> temp;
        if(left <= 2*l) cout << "0.00\n";
        else
        {
            temp--;
            ll ret = pos[temp] - l;
            if(ret <= 0) cout << "0.00\n";
            else if(pos[temp]+l >= left) cout << left/2-(double)l << '\n';
            else cout << floor(ret*50)/100 << '\n';
        }
    }
    
    return 0;
}