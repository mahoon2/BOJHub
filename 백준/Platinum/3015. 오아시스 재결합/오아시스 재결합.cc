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
stack<pii> st;

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    
    cin >> n;
    int inp;
    cin >> inp;
    st.push(make_pair(inp, 1));

    ll ret = 0;
    FOR(i, n-1)
    {
        cin >> inp;
        if(st.top().fi > inp)
        {
            ret++;
            st.push(make_pair(inp, 1));
        }
        else
        {
            pii temp;
            while(!st.empty() && st.top().fi <= inp)
            {
                temp = st.top();
                ret += (ll)temp.se;
                st.pop();
            }

            if(!st.empty()) ret++;

            if(temp.fi == inp)
            {
                st.push(make_pair(inp, temp.se+1));
            }
            else
            {
                st.push(make_pair(inp, 1));
            }
        }
    }

    cout << ret << '\n';

    return 0;
}