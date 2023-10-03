#include <bits/stdc++.h>

#define INF 2087654321
#define fi first
#define se second
#define pii pair<int,int>

#define FOR(i, n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using ld = long double;

using namespace std;

int n;
pii inp[501];
int dp[501][501];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n;

    for(int i=1; i<=n; i++)
    {
        cin >> inp[i].fi >> inp[i].se;
        dp[i][i] = 0;
    }

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=n-i; j++)
        {
            // [j, j+i] 구간의 답을 구한다
            dp[j][j+i] = INF;
            for(int k=0; k<i; k++)
            {
                // [j, j+k] + [j+k+1, j+i]
                dp[j][j+i] = min(dp[j][j+i], dp[j][j+k] + dp[j+k+1][j+i] +
                inp[j].fi*inp[j+k].se*inp[j+i].se);
            }
        }
    }

    cout << dp[1][n] << '\n';
    
    return 0;
}