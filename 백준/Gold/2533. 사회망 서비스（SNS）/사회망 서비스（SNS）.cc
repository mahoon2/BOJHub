#include <iostream>
#include <cstring>
#include <vector>

#define INF 987654321

using namespace std;

int n;
int dp[1000001][2];
vector<int> adj[1000001];

int solve(int prev, int here, bool must_early)
{
	int& ret = dp[here][must_early];
	if(ret != -1) return ret;
	
	if(must_early)
	{
		ret = 1;
		for(int there: adj[here])
		{
			if(prev == there) continue;
			ret += solve(here, there, false);
		}
	}
	else
	{
		int ret1 = 1; int ret2 = 0;
		for(int there: adj[here])
		{
			if(prev == there) continue;
			ret1 += solve(here, there, false);
			ret2 += solve(here, there, true);
		}
		ret = min(ret1, ret2);
	}
	
	return ret;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	int from, to;
	for(int i=0; i<n-1; i++)
	{
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 1, false) << '\n';
	return 0;
}