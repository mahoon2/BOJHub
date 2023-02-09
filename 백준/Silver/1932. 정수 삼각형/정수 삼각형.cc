#include <iostream>
#include <cstring>

using namespace std;

int n, tri[501][501], dp[501][501];

int main()
{
	int temp;
	cin >> n;
	memset(tri, -1, sizeof(tri));
	memset(dp, -1, sizeof(dp));
	
	for(int i=0; i<n; i++)
		for(int j=0; j<=i; j++)
		{
			cin >> temp;
			tri[i][j] = temp;
		}
	
	dp[0][0] = tri[0][0];
	for(int i=1; i<n; i++)
		for(int j=0; j<=i; j++)
		{
			if(j==0)
				dp[i][j] = dp[i-1][j] + tri[i][j];
			else if(j==i)
				dp[i][j] = dp[i-1][j-1] + tri[i][j];
			else
				dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j];
		}
	
	int max = -1;
	for(int i=0; i<n; i++)
		if(dp[n-1][i] > max)
			max = dp[n-1][i];
	
	cout << max << '\n';
	return 0;
}