#include <iostream>
#define DIV 10007

using namespace std;

int dp[1001] = {0};

int sol(int n)
{
	int &ret = dp[n];
	if(ret) return ret;
	for(int i=2; i>0; i--)
		ret += sol(n-i)%DIV;
	return ret%DIV;
}

int main()
{
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	cout << sol(n) << '\n';
	return 0;
}