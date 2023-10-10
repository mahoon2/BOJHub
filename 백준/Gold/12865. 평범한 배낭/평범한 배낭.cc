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

int n, k;
int dp[2][100001];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> k;
    int temp1, temp2;
    cin >> temp1 >> temp2;
    for(int i=0; i<temp1; i++)
		dp[0][i] = 0;
	for(int i=temp1; i<=k; i++)
		dp[0][i] = temp2;

    int here, prev;
    for(int i=1; i<n; i++)
    {
        cin >> temp1 >> temp2;
        here = i%2; prev = (i-1)%2;

        for(int j=0; j<temp1; j++)
        {
            dp[here][j] = dp[prev][j];
        }
        for(int j=temp1; j<=k; j++)
        {
            dp[here][j] = max(dp[prev][j], dp[prev][j-temp1] + temp2);
        }
    }

    cout << dp[(n-1)%2][k] << '\n';
    
    return 0;
}