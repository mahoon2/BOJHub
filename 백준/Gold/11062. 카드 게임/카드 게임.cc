#include <iostream>
#include <cstring>

using namespace std;

int n;
int card[1001];
int dp[1001][1001];

int solve(int start, int end, int Gturn)
{
	// Gturn : 0이면 근우의 턴, 1이면 명우의 턴
	if(start > end) return 0;
	
	int& ret = dp[start][end];
	if(ret != -1) return ret;
	if(Gturn == 0)
	{
		ret = max(card[start] + solve(start+1, end, 1),
				 card[end] + solve(start, end-1, 1));
	}
	else
	{
		ret = min(solve(start+1, end, 0),
				 solve(start, end-1, 0));
	}
	
	return ret;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i=0; i<n; i++)
		{
			cin >> card[i];
		}
		memset(dp, -1, sizeof(dp));
		cout << solve(0, n-1, 0) << '\n';
	}
	
	return 0;
}