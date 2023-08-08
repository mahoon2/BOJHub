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

deque<pii> dq;

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    
    int n, l;
    cin >> n >> l;
    int temp;
    FOR(i, n)
    {
        cin >> temp;
        while(!dq.empty() && dq.back().fi >= temp) dq.pop_back();
        dq.push_back({temp, i});
        if(i >= l)
        {
            while(!dq.empty() && dq.front().se <= i-l) dq.pop_front();
        }
        cout << dq.front().fi << " ";
    }
    cout << '\n';

    return 0;
}