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
int dp[101][100001];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> k;
    int temp1, temp2;
    for(int i=0; i<n; i++)
	{
		cin >> temp1 >> temp2;
		things.push_back(make_pair(temp1, temp2));
	}
	
	for(int i=0; i<things[0].first; i++)
		dp[0][i] = 0;
	for(int i=things[0].first; i<=k; i++)
		dp[0][i] = things[0].second;
    
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<things[i].first; j++)
        {
            dp[i][j] = dp[i-1][j];
        }
        for(int j=things[i].first; j<=k; j++)
        {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-things[i].first] + things[i].second);
        }
    }

    cout << dp[n-1][k] << '\n';
    
    return 0;
}