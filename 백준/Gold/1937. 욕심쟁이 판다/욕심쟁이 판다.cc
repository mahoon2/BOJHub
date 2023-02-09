#include <iostream>
#include <cstring>

using namespace std;

int n;
int board[501][501];
int dp[501][501];
int dy[] = {-1, 1, 0, 0};
int dx[]= {0, 0, -1, 1};

int solve(int y, int x)
{
	int& ret = dp[y][x];
	if(ret != -1) return ret;
	
	ret = 0;
	for(int i=0; i<4; i++)
	{
		int ny = y+dy[i]; int nx = x+dx[i];
		if(ny >= 0 && ny < n && nx >= 0 && nx < n && board[y][x] < board[ny][nx])
			ret = max(ret, solve(ny, nx)+1);
	}
	
	return ret;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> board[i][j];
	
	int max_ret = 0;
	memset(dp, -1, sizeof(dp));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			max_ret = max(max_ret, solve(i, j));
	cout << max_ret+1 << '\n';
	
	return 0;
}