#include <bits/stdc++.h>

#define INF 987654321
#define fi first
#define se second
#define pii pair<int,int>

#define FOR(i, n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(), (v).end()

#define MOD 9999991

using ll = long long;
using ld = long double;

using namespace std;

int dp[21][21];

int comb(int a, int b)
{
    int& ret = dp[a][b];
    if(ret != -1) return ret;
    if(b == 0 || b == a) return ret = 1;
    if(b == 1 || b == a-1) return ret = a;

    return ret = comb(a-1, b) + comb(a-1, b-1);
}

int solve(vector<int>& inp)
{
    int n = inp.size();
    if(n <= 1) return 1;

    int l=0, r=0;
    vector<int> left, right;
    for(int i=1; i<n; i++)
    {
        if(inp[i] < inp[0])
        {
            l++;
            left.push_back(inp[i]);
        }
        else
        {
            r++;
            right.push_back(inp[i]);
        }
    }

    return ((ll)comb(l+r,r)*solve(left)*solve(right)) % MOD;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    memset(dp, -1, sizeof(dp));
    comb(20, 20);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> inp(n);
        FOR(i, n)
        {
            cin >> inp[i];
        }

        cout << solve(inp) << '\n';
    }
    
    return 0;
}