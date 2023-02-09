#include <iostream>
#include <vector>

using namespace std;
vector<int> cost, dp;
vector<vector<int>> graph;

int solve(int here)
{
	int& ret = dp[here];
	if(ret != -1) return ret;
	
	ret = 0;
	for(int there: graph[here])
	{
		ret = max(ret, solve(there));
	}
	return ret += cost[here];
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		cost = vector<int> (n+1);
		dp = vector<int> (n+1, -1);
		graph = vector<vector<int>> (n+1);
		
		for(int i=1; i<=n; i++)
			cin >> cost[i];
		
		int from, to, end;
		while(k--)
		{
			cin >> from >> to;
			graph[to].push_back(from); // 일부러 반대로 저장
		}
		cin >> end;
		solve(end);
		cout << dp[end] << '\n';
	}
	return 0;
}