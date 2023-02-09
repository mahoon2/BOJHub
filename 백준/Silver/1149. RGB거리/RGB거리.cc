#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

int n, dp[1000][3];
vector<vector<int>> rgb;

int solve(int home, int color)
{
	int &ret = dp[home][color];
	if(ret != INF) return ret;
	for(int i=0; i<3; i++)
	{
		if(i==color) continue;
		ret = min(solve(home-1, i) + rgb[home][color], ret);
	}
	
	return ret;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	int r, g, b;
	for(int i=0; i<n; i++)
	{
		cin >> r >> g >> b;
		rgb.push_back(vector<int>{r, g, b});
	}
	
	for(int i=0; i<3; i++)
		dp[0][i] = rgb[0][i];
	for(int i=1; i<n; i++)
		for(int j=0; j<3; j++)
			dp[i][j] = INF;
	
	int ret = INF;
	for(int i=0; i<3; i++)
		ret = min(ret, solve(n-1, i));
	cout << ret << '\n';
	
	return 0;
} 