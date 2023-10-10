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
vector<pii> things;
int dp[2][100001];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> k;
    int temp1, temp2;
    things = vector<pii>(n);
    for(auto& p: things)
    {
        cin >> p.fi >> p.se;
    }
    int weight, cost;
    cost = things[0].second;
    
	for(int i=0; i<things[0].first; i++)
		dp[0][i] = 0;
	for(int i=things[0].first; i<=k; i++)
		dp[0][i] = cost;
    
    for(int i=1; i<n; i++)
    {
        temp1 = i%2; temp2 = (i-1)%2;
        weight = things[i].first;
        cost = things[i].second;

        for(int j=0; j<weight; j++)
        {
            dp[temp1][j] = dp[temp2][j];
        }
        for(int j=weight; j<=k; j++)
        {
            dp[temp1][j] = max(dp[temp2][j], dp[temp2][j-weight] + cost);
        }
    }

    cout << dp[(n-1)%2][k] << '\n';
    
    return 0;
}