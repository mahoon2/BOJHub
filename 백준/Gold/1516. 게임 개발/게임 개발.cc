#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int cost[501];
int dp[501];
vector<int> graph[501];

int solve(int here)
{
	int& ret = dp[here];
	if(ret != -1) return ret;
	
	ret = 0;
	for(int there: graph[here])
		ret = max(ret, solve(there));
	return ret += cost[here];
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	
	for(int i=1; i<=n; i++)
	{
		int temp;
		cin >> cost[i];
		while(true)
		{
			cin >> temp;
			if(temp == -1) break;
			graph[i].push_back(temp);
		}
	}
	
	memset(dp, -1, sizeof(dp));
	for(int i=1; i<=n; i++)
		cout << solve(i) << '\n';
	return 0;
}