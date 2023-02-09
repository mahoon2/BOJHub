#include <iostream>
#include <vector>
#include <string>

using namespace std;

string a, b;
vector<vector<int>> dp;
vector<vector<int>> lcs_picked;

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
	{
		ret = solve(aIndex+1, bIndex);
		int temp = solve(aIndex+1, next_bIndex+1)+1;
		if(ret < temp)
		{
			lcs_picked[aIndex][bIndex] = next_bIndex+1;
			ret = temp;
		}
		return ret;
	}
	else
		return ret = solve(aIndex+1, bIndex);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> a >> b;
	
	dp = vector<vector<int>> (a.size(), vector<int>(b.size(), -1));
	lcs_picked = vector<vector<int>>(a.size(), vector<int>(b.size(), -1));
	cout << solve(0, 0) << '\n';
	if(solve(0, 0) != 0)
	{
		int bIndex = 0;
		string lcs;
		for(int i=0; i<a.size(); i++)
			if(bIndex < b.size() && lcs_picked[i][bIndex] != -1)
			{
				lcs.push_back(a[i]);
				bIndex = lcs_picked[i][bIndex];
			}
		
		cout << lcs << '\n';
	}
	return 0;
}