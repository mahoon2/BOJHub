#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int value[101];
int dp[10001];

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int k;
	cin >> n >> k;
	for(int i=0; i<n; i++)
		cin >> value[i];
	
	sort(value, value+n);
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i=0; i<n; i++)
		for(int j=value[i]; j<=k; j++)
			dp[j] += dp[j-value[i]];
	cout << dp[k] << '\n';
	
	return 0;
}