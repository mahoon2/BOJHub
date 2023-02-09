#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

int n, k;
vector<pair<int, int>> things;
bool ispicked[100] = {false};
int dp[100][100001];

int solve(int pick, int weight)
{
	if(pick < 0) return 0;
	int& ret = dp[pick][weight];
	if(ret != -1) return ret;
	
	if(things[pick].first > weight)
		return ret = solve(pick-1, weight);
	return ret = max(solve(pick-1, weight-things[pick].first) + things[pick].second, solve(pick-1, weight));
}

int main()
{
	memset(dp, -1, sizeof(dp));
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
	
	cout << solve(n-1, k) << '\n';
	return 0;
}