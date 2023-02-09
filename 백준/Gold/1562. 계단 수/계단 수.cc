#include <iostream>
#include <cstring>

#define MOD 1000000000

using namespace std;

int dp[101][10][1<<10];

int main()
{
	int n;
	cin >> n;
	memset(dp, 0, sizeof(dp));
	long long ret = 0;
	
	for(int i=1; i<=9; i++)
		dp[1][i][1<<i] = 1;
	for(int i=2; i<=n; i++)
	{
		for(int j=0; j<=9; j++)
		{
			for(int visited=0; visited<=1023; visited++)
			{
				if(j==0) dp[i][j][visited | (1<<j)] += dp[i-1][1][visited];
				else if(j==9) dp[i][j][visited | (1<<j)] += dp[i-1][8][visited];
				else
				{
					dp[i][j][visited | (1<<j)] += dp[i-1][j-1][visited];
					dp[i][j][visited | (1<<j)] %= MOD;
					dp[i][j][visited | (1<<j)] += dp[i-1][j+1][visited];
				}
				dp[i][j][visited | (1<<j)] %= MOD;
			}
		}
	}
	
	for(int i=0; i<=9; i++)
	{
		ret = (ret + dp[n][i][1023]) % MOD; 
	}
	cout << ret << '\n';
	return 0;
}