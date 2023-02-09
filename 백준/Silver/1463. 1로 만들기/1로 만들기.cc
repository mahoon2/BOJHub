#include <iostream>
#include <cstring>

using namespace std;
short dp[1000001];

int sol(int n)
{
	if(n==1)
		return 0;
	if(dp[n] != 0)
		return dp[n];
	
	if(n%2 == 0 && n%3 == 0)
	{
		int temp = min(sol(n/2)+1, sol(n/3)+1);
		dp[n] = min(temp, sol(n-1)+1);
	}
	else if(n%2==0)
		dp[n] = min(sol(n/2)+1, sol(n-1)+1);
	else if(n%3==0)
		dp[n] = min(sol(n/3)+1, sol(n-1)+1);
	else
		dp[n] = sol(n-1)+1;
	
	return dp[n];
}

int main()
{
	int n;
	memset(dp, 0, sizeof(dp));
	dp[2] = 1;
	dp[3] = 1;
	cin >> n;
	cout << sol(n) << endl;
	return 0;
}