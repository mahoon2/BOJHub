#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int dp[10001][2];
bool isPicked[10001] = {false, };
vector<int> rec_vec;

int weight[10001];
vector<int> connect[10001];

int solve(int prev, int here, bool pickOk)
{
	int& ret = dp[here][pickOk];
	if(ret != -1) return ret;
	
	int ret1 = 0;
	if(pickOk) ret1 = weight[here];
	int ret2 = 0;
	for(int there: connect[here])
	{
		if(there == prev) continue;
		if(pickOk)
			ret1 += solve(here, there, false);
		ret2 += solve(here, there, true);
	}
	
	if(ret1 > ret2)
	{
		ret = ret1;
		isPicked[here] = true;
	}
	else
	{
		ret = ret2;
	}
	
	return ret;
}

void reconstruct(int prev, int here, bool pickOk)
{
	if(pickOk && isPicked[here])
	{
		rec_vec.push_back(here);
		for(int there: connect[here])
		{	
			if(prev == there) continue;
			reconstruct(here, there, false);
		}
	}
	else
	{
		for(int there: connect[here])
		{
			if(prev == there) continue;
			reconstruct(here, there, true);
		}
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> weight[i];
	
	int from, to;
	while(cin >> from >> to)
	{
		connect[from].push_back(to);
		connect[to].push_back(from);
	}
	
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 1, true) << '\n';
	reconstruct(0, 1, true);
	sort(rec_vec.begin(), rec_vec.end());
	for(int i: rec_vec)
		cout << i << " ";
	cout << '\n';
	
	return 0;
}