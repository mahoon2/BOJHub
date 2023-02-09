#include <iostream>
#include <vector>
#include <string>

using namespace std;

string a, b;
vector<vector<int>> dp;

int solve(int aIndex, int bIndex)
{
	if(aIndex >= a.size() || bIndex >= b.size()) return 0;
	int &ret = dp[aIndex][bIndex];
	if(ret != -1) return ret;
	
	int next_bIndex = -1;
	for(int i=bIndex; i<b.size(); i++)
		if(a[aIndex] == b[i])
		{
			next_bIndex = i;
			break;
		}
	
	if(next_bIndex != -1)
		return ret = max(solve(aIndex+1, next_bIndex+1)+1, solve(aIndex+1, bIndex));
	else
		return ret = solve(aIndex+1, bIndex);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> a >> b;
	
	dp = vector<vector<int>> (a.size(), vector<int>(b.size(), -1));
	cout << solve(0, 0) << '\n';
	return 0;
}