#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int m, n;
int board[501][501];
int count[501][501];
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};

int dp(pair<int,int> here)
{
	int here_y = here.first, here_x = here.second;
	//cout << "here: " << here_y << " " << here_x << '\n';
	
	int& ret = count[here_y][here_x];
	if(ret != -1) return ret;
	
	for(int i=0; i<4; i++)
	{
		int prev_y = here_y + dy[i];
		int prev_x = here_x + dx[i];
		//cout << "prev: " << prev_y << " " << prev_x << '\n';
		if(prev_y >= 0 && prev_y < m && prev_x >= 0 && prev_x < n && board[here_y][here_x] < board[prev_y][prev_x])
		{
			if(ret == -1) ret = dp(make_pair(prev_y, prev_x));
			else ret += dp(make_pair(prev_y, prev_x));
		}
	}
	
	if(ret == -1) ret = 0;
	return ret;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> m >> n;
	
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin >> board[i][j];
	
	memset(count, -1, sizeof(count));
	count[0][0] = 1;
	cout << dp(make_pair(m-1, n-1)) << '\n';
	
	/*for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			cout << count[i][j] << " ";
		cout << '\n';
	}*/
	return 0;
}