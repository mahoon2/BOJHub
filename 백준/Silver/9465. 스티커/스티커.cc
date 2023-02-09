#include <iostream>
#include <cstring>

using namespace std;

int score[2][100000], dp[2][100000];

int solve(int row, int column)
{
	int& ret = dp[row][column];
	if(ret != -1) return ret;
	int next_row = row? 0:1;
	return ret = max(solve(next_row, column-1) + score[row][column],
					 solve(row, column-1));
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		int n, temp;
		cin >> n;
		for(int i=0; i<2; i++)
			for(int j=0; j<n; j++)
			{
				cin >> temp;
				score[i][j] = temp;
			}
		
		memset(dp, -1, sizeof(dp));
		dp[0][0] = score[0][0];
		dp[1][0] = score[1][0];
		int ret = max(solve(0, n-1), solve(1, n-1));
		cout << ret << '\n';
	}
	return 0;
}