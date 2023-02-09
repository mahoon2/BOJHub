#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int memory[101];
int cost[101];
long long dp[2][10001];

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	
	int cost_sum = 0;
	for(int i=0; i<n; i++)
		cin >> memory[i];
	for(int i=0; i<n; i++)
	{
		cin >> cost[i];
		cost_sum += cost[i];
	}
	
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	dp[0][cost[0]] = memory[0];
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<=cost_sum; j++)
		{
			if(dp[(i-1)%2][j] == -1) continue;
			if(j <= cost_sum - cost[i])
				dp[i%2][j+cost[i]] = dp[(i-1)%2][j]+memory[i];
			dp[i%2][j] = max(dp[i%2][j], dp[(i-1)%2][j]);
		}
	}
	
	for(int j=0; j<=cost_sum; j++)
		if(dp[(n-1)%2][j] >= m)
		{
			cout << j << '\n';
			break;
		}
	
	return 0;
}